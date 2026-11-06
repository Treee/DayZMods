# Annotation checks

Run through the existing configured DayZ test harness:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File 'C:\Users\Tree\Documents\DayZ Projects\dayz-test-harness\run.ps1' -Mod 'Z:\DayZ\Modding\iat_map_annotations'
```

`dayz-tests.json` builds the production scripts and the optional tests addon.
The addon references the production CfgPatches identity and guards harness types
with both `DIAG_DEVELOPER` and `IAT_TestHarness`. Normal gameplay needs only the
production `scripts.pbo`.

The six registered cases cover:

- Packing positions across signed integer boundaries, simplification preserving
  endpoints and closed corners, and viewport clipping.
- Isolation of two documents, owned stroke data, stale/duplicate revision
  rejection, terrain mismatch, undo, and clear.
- Independent map stroke and point capacity limits.
- Storage round trips, exact record consumption, empty/pre-mod records, and
  oversized/truncated point packets.
- Real map items in an offline player fixture: holder checks, request/reply
  serialization, accepted strokes, item save/load hooks, and reading the restored
  item's data after moving it to hands. Cleanup deletes the created maps.
- Loading the packed toolbar/canvas layouts and checking projection alignment.

These are component checks. They cannot establish dedicated-server identity
authentication, real network delivery, actual mouse interaction, handoff between
clients, economy persistence, or compatibility with another map mod. Those checks
are listed in the mod README.

Latest engine evidence on November 5, 2026: the production World and Mission
modules and all six registered cases compile on DayZDiag 1.30.164.289. The harness then rejects the timestamped vanilla
PluginItemDiagnostic stack for missing PluginConfigDebugProfile and terminates
before cases complete. No harness filter or vanilla plugin behavior was changed
to bypass it. No passing runtime result is claimed.

The final run directory is
`C:\Users\Tree\Documents\DayZ Projects\dayz-test-harness\runs\c82dd49b63e94cc592363d68b21750f6`.
`result.json` reports `RUN_ERROR`, zero completed tests, and termination during
the run stage. Fixture cleanup was not exercised. Build output is
`P:\mods\@IAT_MapAnnotations`; inspection of `scripts.pbo` confirms that the
production script files and both UI layouts are present. This run used the
command above with no case filter.
