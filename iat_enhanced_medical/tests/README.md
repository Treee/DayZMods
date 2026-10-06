# Enhanced Medical tests

194 registered DayZDiag component cases exercise this mod's own code. Vanilla
systems are assumed functional and serve as fixtures for Enhanced Medical's rules
and overrides; this suite does not attempt to retest the vanilla game.

Run from the workspace:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod P:\iat_enhanced_medical
powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod P:\iat_enhanced_medical -Test EachBandagingCycleTreatsOneSourceAndOneUse
```

Use the source mod root after edits. Use `-SkipBuild` only for a previously packed
copy. `dayz-tests.json` selects scripts, languagecore and tests with local WesternZ
and configured Workshop dependencies. The harness owns packing paths, the isolated
mission, discovery, cleanup verification and process lifetime.

All harness references and test-only script overrides require both
`DIAG_DEVELOPER` and `IAT_TestHarness`. The addon remains optional in ordinary
play. Its requiredAddon is the production scripts addon, not the harness.

The contract preserves current code, confirmed on 2026-10-04: pliers cause
**10 Health damage** per successful extraction and register both extraction actions
in `Pliers.SetActions`. Default ItemBase capability/damage are false/zero. The root
README describes the same explicit capability and registration contract.

Tests cover all 29 selections, ten zones, six regional dressings, every zone's
severity boundaries, bullets and extraction order, ammo ancestry, save layout and
mask validation, dressing/history lifecycle, proportional loss/recovery, expiry,
hit processing, action conditions, patient damage, diagnostics and player hooks.

Fixtures borrow the existing mission player, plugin, bleeding manager, blood
modifier and symptom manager. A second real player is used only for target/corpse
and persistence cases; CreatePlayer initializes its systems. Cleanup restores
touched state, removes fixture bleeds/items and releases borrowed systems.

The harness is offline authoritative, not dedicated. An opt-in test getter supplies
medical-state availability otherwise restricted to dedicated servers. No medical
algorithm is replaced. Vanilla bleeding HUD/particle effects are suppressed only
for opted-in fixtures: the real rendering lifecycle reproduced an offline engine
shutdown crash, while the same component case without rendering passed including
shutdown. Attachment rendering remains outside this suite's scope.

See [COVERAGE.md](COVERAGE.md) for the requirement/function map and precise gaps,
and [VERIFICATION.md](VERIFICATION.md) for executed evidence. This harness has no
line/branch instrumentation, so test counts do not imply a measured percentage.
