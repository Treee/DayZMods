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

## Illness and gunshot rework, 2026-10-06

The original source passed all 194 cases in `023ecd8bea08454c8cab7bdc88bcb78a`.
Changes were developed and tested in the ordinary workspace directory
`medical-change-work`, using the mod's existing addon identities, dependencies,
and packed output. Production files were then copied only after hash validation;
the existing version-1 bullet/dressed-wound save format remains unchanged.

| Requirement | Component evidence | Remaining checks |
| --- | --- | --- |
| R-001: illness treatment window | `IAT_EM_IllnessCase`: measured stage-two net damage projects to 50 minutes from 100 Health; actual cholera Water drain, registered salmonella growth, illness vomiting resource/stomach effects, ordinary/default/contamination preservation | Full 45-60-minute cholera/salmonella survival measurement with recorded nutrition, immunity, stomach contents, and repeated random vomiting |
| R-002: 45% independent retention | `IAT_EM_HitCase`: controlled rolls immediately below, at, and above 0.45 through real `ProcessHit`, with existing eligibility/anatomy cases | Actual projectile dispatch and multiplayer role/replication checks |
| R-003: one retained bullet per bone | Existing repeated-hit, multi-bone extraction, independent-zone, and storage roundtrip cases remain green | Dedicated persistence/reconnect lifecycle |
| R-004: slow loss only in retained areas | `IAT_EM_RetainedBleedingCase`: bandaged/no-bullet control, interval boundary, one pulse per zone with several bones, multiple affected zones, delayed interval remainder, stopping after extraction | Natural wall-clock scheduling, UI feedback, and dedicated multiplayer |
| R-005: extraction bleed, full-healing cleanup, manual reopening | `IAT_EM_ExtractionBleedCase`: active wound under dressing, actual regional damage, rebandaging and history, delayed cleanup, manual cutting/reopening, fully healed eligibility, empty extraction | Protected completion dispatch, animation, cancellation and dedicated detach callbacks |

Observed red evidence:

- `c4886baab82640c1966801c40fd92312`: retention roll at 0.45 incorrectly retained
  a bullet (`expected=0`, `actual=128`). The boundary test passed after the roll
  gate in `433ab6f64609465d8314e8f5f96b4d1d`.
- `6e715ee8b75344b5951b0bc574877297`: a bandaged retained-bullet zone lost no
  global or regional Blood after the interval.
- `e4975336c611446e92c5769f7f6b3d38`: extraction opened no bleeding source and
  the full zone still qualified for healed dressing cleanup.
- `e8c1321609db46b587b5bd3e0609ce81`: five illness cases failed against vanilla
  tuning, including a 2,499.99-second stage-two projection, Water loss of 5
  instead of 1.5 per ten seconds, salmonella growth 0.75 instead of 0.225,
  and unreduced vomiting effects. The other 208 cases passed.

Run `619cc1596f6a4069ad5c70fe58f93a9a` was rejected as RUN_ERROR: the engine's
boolean bleeding-source query preserved the source bit (256) in an assertion
result. Test-author correction normalized the actual bleeding mask comparison;
the harness/verifier was not changed. This run is not red/green evidence.

Run `4f83e17d2d6e4b04819541d23fec24e6` passed 213 cases / 2,249 assertions.
Final staged run `113f12a0d1b742478a3f128bf315d28f` passed all 214 cases / 2,255 assertions after
adding contamination preservation and completing fixture restoration.
Both used `-HashArtifacts`; cleanup, termination, and loaded addon identity were
verified. Final invocation:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod .\medical-change-work -HashArtifacts
```

Random retention rolls are controlled only by the guarded diagnostic addon;
normal gameplay uses `Math.RandomFloat(0, 1)`. Illness tests invoke public
`ModifierBase.Tick` and symptom effects without widening production callbacks.
The vomit event seed is replayed immediately before the public tick, and fixture
stomach/agent/symptom systems, disease flags, toxicity, exhaustion effects and
player Blood/Health/resources are restored. These are component observations,
not full elapsed gameplay or multiplayer survival trials.
