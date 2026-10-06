# Verification evidence

Verified on 2026-10-04 with the configured DayZ 1.29 diagnostic harness. Test source
was staged in the workspace and packed separately as `@IAT_EM_Coverage` to validate
the complete addon before writing through the external production-source junction.

| Check | Run / result |
| --- | --- |
| Original baseline | `923973f885f14368b730e20b1954082e`: PASS, two cases |
| Expanded suite | `7f551872e101401a8dc8f2b832a1fdcf`: PASS, 184 cases / 1,942 assertions |
| Deliberately wrong staged severity boundary | `0f2299012f7e4af2ac2eea4fddc17b59`: expected TEST_FAILURE, one selected case; cleanup and termination verified |
| Final restored suite with artifact hashes | `8fd44502cbb2499789b20665c0f6e40d`: PASS, 184 cases; cleanup and termination verified |
| Installed suite, normal mod source/output, artifact hashes | `0a1ecf438a5a49cb99186b732c87b7a1`: PASS, 184 cases / 1,942 assertions; cleanup and termination verified |

The mutation changed only a workspace staging copy of `IsSevere`: `< 50%` became
`<= 50%`. `Regen_Head_0.5_dressing_false_bullet_false` then failed the exact-half
severity, regeneration eligibility and pending-recovery assertions. This was a
valid behavioral failure, not a script/build/discovery error. The staging source
was restored byte-for-byte before final verification; the external mod's gameplay
source was never mutated. This is regression-detection evidence, not a claim that
production implementation followed a red-green development cycle.

All twelve production scripts/config/prefix files match the captured baseline
SHA-256 hashes in both the external source and the restored stage. Existing user
changes in the source repository are preserved. Only the tests addon is installed.

The diagnostic executable's successful `RequestExit(0)` returns -1 on this machine;
the maintained verifier accepted complete matching reports, cleanup and RPT
termination. The single recognized vanilla PluginItemDiagnostic lookup diagnostic
remains listed in result.json. No additional diagnostic/crash exceptions were added.

Run artifacts are in `dayz-test-harness/runs/<run-id>/`: `result.json`,
`test-report.json`, `junit.xml`, packed-addon provenance in `run.json`, and engine
profile/discovery/logs. The final run used `-HashArtifacts`.

The final snapshot also emitted `EM_TEST_SNAPSHOT`, the expected ordered bone
names, attachment and Blood-pool events; disabled/null events were absent.

Remaining verification limits are explicit in [COVERAGE.md](COVERAGE.md), including
dedicated roles/persistence, native read failures and animation/rendering paths.

## Knife removal feature, 2026-10-05

The unchanged baseline passed 184 cases in run `e96969f29050440f9feea0b10462725a`.
The new `BelowHalfReopensEveryCoveredWound` case failed against the removal
scaffold in `add6fe82ebe2493a83c5478a526f74d9`: the dressing remained attached
and the expected three-source mask was zero. Cleanup and termination verified.
Two earlier build attempts exposed a fixture constructor mismatch and an invalid
animation constant; both were corrected and are not behavioral red evidence.

Final run `351d1ccf185246e88bee013ea2f4a318` passed all 194 registered cases,
including ten ManualRemoval cases, with cleanup and termination verified.
Invocation: `powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod P:\iat_enhanced_medical -HashArtifacts`.
Loaded artifact hashes are recorded in that run's `run.json`.

The new cases exercise self/target completion, eight knife types and their action
registration, missing dressings and invalid tools, one-dressing removal, all
covered unhealed sources reopening together, full healing, retained bullets,
and Blood at 25%, 50%, and 75%. Existing expiry cases verify the unchanged 50%
natural-expiry rule. Safe healing still requires full zone Blood and no bullet.

These are engine-backed authoritative component checks. Dedicated multiplayer
visibility, input, reach, animation, cancellation, and attachment rendering
remain manual checks in `tools/IN_GAME_CHECKLIST.md`.
## Explicit knife capabilities and protected callbacks, 2026-10-05

Run `de3b75e1882f4f4693d62a728026f5dd` passed all 194 cases with cleanup and
termination verified; loaded addon hashes were recorded with `-HashArtifacts`.
ItemBase now defaults a protected capability boolean to false. Each of the eight
supported knife classes enables it and explicitly registers both removal actions.
The removal tests invoke our `IAT_Remove` directly with the actor or patient.
Protected DayZ `OnFinishProgressServer` callbacks are unchanged and not exposed
or invoked by these tests. Their dispatch and patient routing remain manual checks.