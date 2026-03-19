let build_version_file = HEMTT_VFS.join("release_version.hpp").open_file().read();

let minorPrefix = "#define MINOR ";
let currentMinor = HEMTT.project().version().minor();

let patchPrefix = "#define PATCH ";
let currentPatch = HEMTT.project().version().patch();

let buildPrefix = "#define BUILD ";
let currentBuild = HEMTT.project().version().build();

if HEMTT.is_release() { // Minor Bump
	let nextMinor = currentMinor + 1;
	build_version_file.replace(minorPrefix + currentMinor.to_string(), minorPrefix + nextMinor.to_string());
} else if HEMTT.is_build() { // Patch Bump
	let nextPatch = currentPatch + 1;
	build_version_file.replace(patchPrefix + currentPatch.to_string(), patchPrefix + nextPatch.to_string());
} else if HEMTT.is_dev() { // Build Bump
	let nextBuild = currentBuild + 1;
	build_version_file.replace(buildPrefix + currentBuild.to_string(), buildPrefix + nextBuild.to_string());
}

HEMTT_RFS.join("release_version.hpp").create_file().write(build_version_file);
