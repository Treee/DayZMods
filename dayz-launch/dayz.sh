#!/usr/bin/env bash
set -euo pipefail

# Git Bash invoked from a Windows terminal may not have its own utilities on PATH.
export PATH="/usr/bin:/bin:$PATH"

fail() { printf 'Error: %s\n' "$*" >&2; exit 1; }
usage() {
    printf 'Usage: %s {server|client} PROFILE_DIRECTORY [--] [DAYZ_ARGUMENTS...]\n       %s clear-logs PROFILE_DIRECTORY\n' "${0##*/}" "${0##*/}" >&2
    exit 2
}

[[ $# -ge 2 ]] || usage
action=$1
case "$action" in server|client|clear-logs) ;; *) usage ;; esac
[[ $action != clear-logs || $# == 2 ]] || usage

resolve_path() {
    local value=${1//\\//} base=$2
    [[ -n $value ]] || fail 'A required filesystem path is empty'
    if command -v cygpath >/dev/null 2>&1; then
        value=$(cygpath -u -- "$value") || fail "Cannot translate path: $1"
    fi
    [[ $value == /* ]] || value="$base/$value"
    realpath -m -- "$value"
}

native_path() {
    if command -v cygpath >/dev/null 2>&1; then
        cygpath -w -- "$1"
    else
        printf '%s\n' "$1"
    fi
}

profile_dir=$(resolve_path "$2" "$PWD")
shift 2
if [[ ${1-} == -- ]]; then shift; fi
extra_arguments=("$@")
profile_conf="$profile_dir/profile.conf"
[[ -d $profile_dir && -f $profile_conf ]] || fail "Expected configuration: $profile_conf"

# Reset the settings so a calling shell cannot supply stale values accidentally.
GAME_DIR='' WORKSHOP_DIR='' SERVER_CONFIG='' SERVER_PROFILE='' CLIENT_PROFILE=''
SERVER_IP='127.0.0.1' PORT=2302 CLIENT_NAME='Survivor'
WORKSHOP_MODS=() LOCAL_MODS=()
SERVER_ARGS=() CLIENT_ARGS=()
# Configuration is deliberately trusted Bash, with comments and ordered arrays.
source "$profile_conf"

server_profile=$(resolve_path "$SERVER_PROFILE" "$profile_dir")
client_profile=$(resolve_path "$CLIENT_PROFILE" "$profile_dir")
profile_root_check=$profile_dir
server_check=$server_profile
client_check=$client_profile
if [[ $OSTYPE == msys* ]]; then
    profile_root_check=${profile_root_check,,}
    server_check=${server_check,,}
    client_check=${client_check,,}
fi
for target in "$server_check" "$client_check"; do
    [[ $target == "$profile_root_check/"* ]] || fail 'Runtime profile directories must be inside the selected profile directory'
done
[[ $server_check != "$client_check" && $server_check != "$client_check/"* && $client_check != "$server_check/"* ]] \
    || fail 'Server and client profiles must be distinct and must not overlap'

clean_logs() {
    local directory=$1
    [[ -e $directory ]] || return 0
    [[ -d $directory ]] || fail "Cleanup target is not a directory: $directory"
    printf 'Clearing root-level logs: %s\n' "$directory"
    find "$directory" -maxdepth 1 -type f \
        \( -iname '*.log' -o -iname '*.rpt' -o -iname '*.mdmp' -o -iname '*.adm' \) \
        -delete || fail "Could not clean logs in: $directory"
}

printf 'Action: %s\nConfiguration: %s\nServer profile: %s\nClient profile: %s\n' \
    "$action" "$profile_conf" "$server_profile" "$client_profile"
if [[ $action == clear-logs ]]; then
    clean_logs "$server_profile"
    clean_logs "$client_profile"
    exit 0
fi

[[ $PORT =~ ^[0-9]+$ && ${#PORT} -le 5 ]] || fail 'PORT must be an integer from 1 to 65535'
(( 10#$PORT >= 1 && 10#$PORT <= 65535 )) || fail 'PORT must be an integer from 1 to 65535'
[[ -n $SERVER_IP && -n $CLIENT_NAME ]] || fail 'SERVER_IP and CLIENT_NAME must not be empty'

game_dir=$(resolve_path "$GAME_DIR" "$profile_dir")
executable="$game_dir/DayZDiag_x64.exe"
[[ -d $game_dir && -f $executable && -x $executable ]] || fail "Diagnostic executable not found or executable: $executable"
for array_name in WORKSHOP_MODS LOCAL_MODS; do
    [[ $(declare -p "$array_name") == 'declare -a '* ]] || fail "$array_name must be a Bash array"
done
argument_setting=${action^^}_ARGS
[[ $(declare -p "$argument_setting") == 'declare -a '* ]] || fail "$argument_setting must be a Bash array"

mod_paths=()
if (( ${#WORKSHOP_MODS[@]} )); then
    workshop_dir=$(resolve_path "$WORKSHOP_DIR" "$profile_dir")
    for mod in "${WORKSHOP_MODS[@]}"; do
        [[ -n $mod && $mod != */* && $mod != *\\* ]] || fail "Workshop entry must be a folder name: $mod"
        mod_path=$(resolve_path "$workshop_dir/$mod" "$profile_dir")
        [[ -d $mod_path ]] || fail "Workshop mod directory not found: $mod_path"
        mod_paths+=("$(native_path "$mod_path")")
    done
fi
for mod in "${LOCAL_MODS[@]}"; do
    mod_path=$(resolve_path "$mod" "$profile_dir")
    [[ -d $mod_path ]] || fail "Local mod directory not found: $mod_path"
    mod_paths+=("$(native_path "$mod_path")")
done
for mod in "${mod_paths[@]}"; do
    [[ $mod != *';'* ]] || fail "A mod path cannot contain a semicolon: $mod"
done
mod_argument=$(IFS=';'; printf '%s' "${mod_paths[*]}")

if [[ $action == server ]]; then
    server_config=$(resolve_path "$SERVER_CONFIG" "$profile_dir")
    [[ -f $server_config ]] || fail "Server configuration not found: $server_config"
    mission_arguments=()
    # The server otherwise prefixes template with mpmissions\, even for an
    # absolute path. Keep the mission setting in the cfg and pin external paths.
    template_pattern='^[[:space:]]*template[[:space:]]*=[[:space:]]*"([^"]+)"'
    while IFS= read -r line || [[ -n $line ]]; do
        if [[ $line =~ $template_pattern ]]; then
            mission_template=${BASH_REMATCH[1]//\\//}
            if [[ $mission_template == /* || $mission_template == [[:alpha:]]:/* ]]; then
                mission_dir=$(resolve_path "$mission_template" "$profile_dir")
                [[ -f $mission_dir/init.c ]] || fail "Mission init.c not found: $mission_dir/init.c"
                mission_arguments=("-mission=$(native_path "$mission_dir")")
            fi
            break
        fi
    done < "$server_config"
    launch_profile=$server_profile
    arguments=("-config=$(native_path "$server_config")" "${mission_arguments[@]}" "-port=$PORT"
        "-profiles=$(native_path "$launch_profile")" "-mod=$mod_argument"
        "${SERVER_ARGS[@]}")
else
    launch_profile=$client_profile
    arguments=("-name=$CLIENT_NAME" "-connect=$SERVER_IP" "-port=$PORT"
        "-profiles=$(native_path "$launch_profile")" "-mod=$mod_argument"
        "${CLIENT_ARGS[@]}")
fi
arguments+=("${extra_arguments[@]}")

mkdir -p -- "$launch_profile"
clean_logs "$launch_profile"
printf 'Command:'; printf ' %q' "$executable" "${arguments[@]}"; printf '\n'
cd -- "$game_dir"
# Arguments are already native paths; prevent MSYS from rewriting the mod list.
MSYS2_ARG_CONV_EXCL='*' nohup "$executable" "${arguments[@]}" \
    >"$launch_profile/launcher.log" 2>&1 </dev/null &
printf 'Started process %s. Check the game and profile logs for runtime errors.\n' "$!"
