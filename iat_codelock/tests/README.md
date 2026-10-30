The `NasdaraBuildings` suite uses the installed Nasdara house models and rebuilding components.

- `DoorTargetingAndAccess` places locks on two separate doors. It checks door and direct-lock targeting, absence of house-body prompts, cursor-distance conditions, debug-lock passcode availability without admin tools, and building-door access enforcement.
- `KeypadPreventsCombinationLock` and `CombinationLockPreventsKeypad` check both attachment orders, occupied-slot visibility, and locked/unlocked detachment.

Run from the configured DayZ workspace with:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod P:\iat_codelock -HashArtifacts
```

The offline mission has no Steam identity. The debug lock exercises denied access, and a test-only lock subclass supplies granted access. These cases do not establish Steam identity replication, the multiplayer whitelist/RPC lifecycle, UI menu callbacks, or COT's forced attachment behavior. Manually check those paths on a server with two independently locked doors and admin tools disabled.

The test addon also registers the vanilla `PluginConfigDebugProfile` dependency required by `PluginItemDiagnostic` in diagnostic builds where `IsDebug()` is false. It uses the isolated run's profile and leaves the harness's error verification unchanged.

On 2026-10-30, DayZDiag 1.30.164200 completed all three cases, all 44 assertions, and all fixture cleanup checks. The public runner rejected the run as `RUN_ERROR` because shutdown reported `Leaked 'BunkerBroadcastManager' script instance (1x)!`. This is not a verified pipeline pass. Evidence is in harness run `2a9ebeb639df44619a986667ac99ca02`, including `profile/iat-result.json`, the script log, and `result.json`.
