# Digital lock verification

Run from the workspace:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\dayz-test-harness\run.ps1 -Mod P:\iat_more_doors
```

Four registered cases cover single and double construction doors, each with
the battery inserted before or after attachment:

- SingleDoorBatteryAfterAttachment
- SingleDoorBatteryBeforeAttachment
- DoubleDoorBatteryAfterAttachment
- DoubleDoorBatteryBeforeAttachment

The cases check parent recognition, power, explicit registration of the two
IAT door actions, Set Code/Enter Code/Reset Code availability on a door target,
and retention of the door as the target during setup. They also check that
vanilla actions still reject door targets and accept direct lock targets,
that the IAT actions do not duplicate a direct lock prompt, and that missing
or unpowered locks and disallowed physical sides reject the custom actions.

Public `AnimatedActionBase.OnAnimationEvent` dispatch exercises locking and
rear-side release in the authoritative offline fixture, including rejecting
release after the player moves to the keypad side. This manually supplies an
animation event; it does not establish engine animation timing or multiplayer
message delivery. Tests do not invoke protected callbacks directly or widen
production visibility. PIN menus are not opened by these component checks.

Fixtures release setup reservations, restore player position and delete their
lock and door. Harness references remain guarded by both DIAG_DEVELOPER and
IAT_TestHarness.

## Latest evidence: 2026-10-18

Run `dayz-test-harness/runs/3a479c96027d408f931be12f20586253` built the selected
addons and compiled the World and Mission modules on DayZDiag 1.30.164078.
It then stopped with RUN_ERROR at vanilla PluginItemDiagnostic initialization
because PluginConfigDebugProfile was not registered. The timestamped stack
still does not match the harness's preexisting exact known-diagnostic filter.
No harness exception or gameplay behavior was changed to bypass that failure.

No case completed and fixture cleanup was not exercised. These are compiled
component tests awaiting a valid runtime run, not passing behavioral evidence.
The separate-actions change removes the earlier vanilla-action `Can` and
`SetupAction` overrides and the target-translation helper.

## In-game checks still required

1. With the rebuilt scripts.pbo on both client and server, aim at a door panel
   or frame, rather than the lock proxy. Check Set Code with a charged battery.
2. Configure a PIN and verify Enter Code, Lock, unlocked Reset Code, and the
   rear-side physical release. Confirm both leaves obey a locked digital lock.
3. Check an empty slot, depleted or removed battery, direct lock targeting,
   cancellation, and movement between sides while the action is running.
4. Replace/detach the lock during an action and verify that the operation does
   not apply to the replacement lock.
5. Repeat with land doors, desired model variants, reconnect/server restart,
   and the server's normal mod list. Multiplayer, persistence, menu interaction
   and actual animation scheduling remain outside this compilation evidence.