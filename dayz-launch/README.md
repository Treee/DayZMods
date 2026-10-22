# DayZ diagnostic launcher

One Bash script starts the diagnostic server or client for a selected profile.
Use **Git Bash on Windows**, with Steam running. These commands do not use
PowerShell, build mods, or start the automated test harness.

From this folder:

```bash
./dayz.sh server profiles/treemods
# Wait for the server to finish starting, then:
./dayz.sh client profiles/treemods
```

Select `profiles/westernz` or `profiles/vanilla` the same way. If your shell needs
an explicit interpreter, use `bash ./dayz.sh ...`. Close the client and server
yourself before starting another setup; all three default to port 2302.

Each startup clears only that role's old root-level logs immediately before
launching. Starting a client leaves server logs intact. For optional manual
cleanup, stop both processes and run:

```bash
./dayz.sh clear-logs profiles/treemods
```

The script clears `.log`, `.rpt`, `.mdmp`, and `.adm` files, case-insensitively,
directly inside the selected role's profile folder. It retains nested files,
settings, permissions, mission saves, and other profiles. A cleanup failure
prevents startup. Check `server/launcher.log` or `client/launcher.log` for native
launch output, and the same directory's script/RPT files for engine output.
The printed process number is a Bash process identifier; Windows can report a
different PID. A successful launcher command means the process was started, not
that scripts compiled or a client connected.

## Settings

Every profile directory contains exactly one maintained `profile.conf`:

```text
profiles/treemods/
  profile.conf
  server/        # generated/private server settings and logs
  client/        # generated/private client settings and logs
```

Edit this file to change the player name, port, server address, paths, and mods.
It is trusted Bash configuration: use `#` for comments and arrays for mod lists
and launch arguments.

```bash
GAME_DIR='/y/SteamLibrary/steamapps/common/DayZ'
WORKSHOP_DIR="$GAME_DIR/!Workshop"
SERVER_CONFIG='../../configs/treemods.cfg'
SERVER_PROFILE='server'
CLIENT_PROFILE='client'
SERVER_IP='127.0.0.1'
PORT=2302
CLIENT_NAME='RandomSurvivor'

SERVER_ARGS=(
  -server
  -limitfps=120
  -noPause
  -forcedebugger
  -scriptDebug=true
  -dologs
  -adminlogs
  -newErrorsAreWarnings=1
  -scrAllowFileWrite
)
CLIENT_ARGS=(
  -window
  -x=1280
  -y=720
  -forcedebugger
  -scriptDebug=true
  -dologs
  -newErrorsAreWarnings=1
)

WORKSHOP_MODS=(
  '@CF'
  # "@Lad's Lighting Overhaul"
)
LOCAL_MODS=(
  'Z:/DayZ/Modding_Packed/@IAT_MoreDoors'
)
```

`SERVER_ARGS` and `CLIENT_ARGS` control the flags for their respective launches.
Remove or change entries freely; keep `-server` in `SERVER_ARGS` to run a
dedicated server. Empty or omitted arrays add no flags. Each array entry is one
argument; quote entries containing spaces. The supplied clients request a
1280×720 window. For 1024×768 instead, edit the entries to `-x=1024` and `-y=768`.

You can also pass additional arguments for a single launch:

```bash
./dayz.sh server profiles/treemods -- -freezecheck
./dayz.sh client profiles/treemods -- -noPause
```

The `--` separator is optional. Arguments go to DayZ after the selected profile's
array, preserving their order and quoting. The launcher does not interpret or
merge duplicate flags; use the profile to change an existing flag rather than
depending on which duplicate the engine honors. Use the named profile settings
for paths, mods, port, address, and player name so the launch summary and log
cleanup match the engine's directories. `clear-logs` accepts no extra arguments.

- Relative paths in settings resolve beside `profile.conf`, independently of
  your terminal's working directory. The directory supplied on the command line
  resolves from your terminal's working directory.
- Git Bash paths (`/y/...`) and absolute Windows paths (`Y:/...` or `Y:\...`)
  are accepted. The script passes absolute native paths to DayZ and runs it from
  its installation directory.
- Runtime server/client directories must be separate, non-overlapping children
  of the selected profile directory. This confines log deletion to that setup.
- Workshop entries are folder names under `WORKSHOP_DIR`. Local entries name
  existing packed directories. Workshop mods load first, followed by local
  mods; each array preserves its order. Empty arrays load no mods.
- The WesternZ local list retains its existing `P:/Mods/@IAT_EnhancedMedical`
  mapping. Run in your normal Windows user context with P: mounted.
- `SERVER_CONFIG` points to DayZ's own server `.cfg`, which selects the mission.
  Each supplied `.cfg` uses a separate full mission path under `missions/`.
  The script reads the absolute `template="..."` assignment and also supplies
  `-mission` to the server: the installed engine otherwise prefixes the path
  with `mpmissions\` and does not run the external mission's `init.c`.
  Keep that assignment on its own line. Update these paths if you relocate this
  checkout. Windows engine paths use backslashes in launch arguments.

Missing configuration or invalid launch settings fail before old logs are
cleared. `clear-logs` only needs valid profile paths; it works even if Steam,
the game executable, or packed mods are unavailable.

## Migrated setups

TreeMods and WesternZ retain their original active/commented mod selections,
copied server settings, permissions, and mission saves. Their clients have
independent copies of your existing client mod settings and controls. Originals
in Steam and Documents are unchanged. Old and new copies do not synchronize.

One stale TreeMods path was corrected: `Modding_Packed/@IAT_FacePaints` does not
exist, so its entry uses the already-packed local
`iat_facepaints/.hemttout/dev` output. That mod stays in the same load position;
no mod was rebuilt. The correction is commented in `profile.conf`.

Vanilla loads no mods and starts with fresh profiles. Its mission contains the
installed vanilla server `init.c`; default Chernarus economy data comes from the
game's `worlds_chernarusplus_ce.pbo`, without the custom TreeMods economy files.

Actual `configs/*.cfg`, generated server/client directories, mission storage,
and the copied private ReportTool configuration are ignored by Git. Sanitized
`configs/*.cfg.example` files are tracked. On a fresh checkout, copy each example
to the corresponding `.cfg`, set any private passwords, and update mission paths.

## Verification

Run the disposable filesystem/substitute-executable checks with Python 3:

```bash
python -m unittest discover -s dayz-launch/tests -v
```

Run that command from the repository root. Python is used only for development
tests; the launcher itself needs Bash and the utilities bundled with Git Bash.
If necessary, set `DAYZ_BASH` to the real Git Bash executable for tests. No JSON
parser or third-party Python packages are required.

All three server/client pairs connected in the engine. The WesternZ server
crashed during manual shutdown on two verification attempts, including one
after player logout completed; its shutdown is not verified clean. Vanilla
and TreeMods terminated successfully. The launcher itself does not stop games.
