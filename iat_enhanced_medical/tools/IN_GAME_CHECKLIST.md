# Enhanced Medical: in-game verification

Run with WesternZ and Enhanced Medical loaded on both server and clients. Use a second client for visibility and treating another player. Check client/server script logs during testing. This checklist has not been executed in DayZ.

## Setup and observations

Use a living test character with food and water sufficient for blood regeneration. Have rags, bandage dressings, pliers, and the six existing WesternZ bandages available. Keep the patient alive between observations; god mode may prevent bleeding creation.

For precise checks, use your server-side debug console with a valid PlayerBase variable named `player`:

```c
Print(player.GetHealth("LeftArm", "Blood"));
Print(player.GetHealth("LeftHand", "Blood"));
Print(player.GetHealth("", "Blood"));
Print(player.IAT_GetMedicalState().Wounds);
Print(player.IAT_GetMedicalState().Bullets);
Print(player.IAT_GetMedicalState().DressedWounds);
```

The three masks are server-only. A client console cannot read them. To create a controlled wound without firing a weapon:

```c
player.SetHealth("LeftArm", "Blood", 25);
player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftArm");
```

## Checks

- [x] **Startup:** Pack/load without a missing `bandages.hpp` error, unknown WesternZ class error, or script compilation error.
- [x] **Self-bandaging:** Create a left-arm bleed and apply a rag. One rag is consumed, the existing `WZ_Bandage_LArm` attaches in `WZBandageLArm`, and bleeding stops. Repeat with a bandage dressing. Wait at least two bleeding-manager ticks (about 6 seconds): bleeding must stay stopped.
- [x] **Other player:** Repeat bandaging another player. The attachment and stopped bleeding belong to the patient, and supplies are consumed from the treating player.
- [x] **Six regions:** Check head, chest, left/right arm, and left/right leg dressings. Both clients see the appropriate worn model. No duplicate dressing appears in cargo or at the patient's feet.
- [x] **Shared coverage:** Create left-arm and left-hand bleeds together (hand selection: `LeftForeArmRoll`). One left-arm dressing closes both. Repeat leg/foot coverage. A wound on the opposite side must remain bleeding.
- [ ] **Unhealed removal:** Remove a dressing while its covered zone is below maximum Blood. Bleeding returns immediately or within the next approximately 3-second reconciliation tick. Other dressed regions remain closed.
- [ ] **Reattachment:** Reattach that WesternZ dressing manually. Covered bleeding stops and stays stopped. This exercises the normal attachment callback separately from applying a rag.
- [ ] **Automatic healed removal:** With no retained bullets or active bleeding, let every zone covered by a dressing reach maximum Blood. The next blood-regeneration cleanup tick deletes the dressing (it is not dropped), logs `BANDAGE_HEALED_REMOVAL`, and does not reopen bleeding. Repeat while global Blood is already full.
- [ ] **Partial regional healing:** Fully heal an arm while its hand remains injured, then reverse the test. The shared dressing must stay until both are healed. Repeat for a leg and foot. A retained bullet or active bleeding in either covered zone must also prevent automatic removal.
- [ ] **Ruined dressing:** Ruin a worn dressing over an unhealed wound. Bleeding returns within approximately 3 seconds. Trying to bandage over the ruined attachment must not consume supplies or close bleeding; remove it and retry successfully.
- [ ] **Fresh injury under a dressing:** Injure an already dressed region again. The existing dressing must not automatically prevent every new bleed. Applying another treatment closes the new bleed without adding a second attachment.
- [ ] **Minor expiry:** Create a wound with the zone well above 50% Blood (for example 90%). Keep it above 50% throughout observation. Bleeding should expire after roughly 45 seconds plus server tick scheduling.
- [ ] **Severe expiry:** Create a wound below 50% zone Blood. While it remains below 50%, it must continue bleeding past 45 seconds. Applying a dressing stops it. Severity currently follows the current zone Blood value; it is not permanently latched after crossing the threshold.
- [ ] **Bullet regeneration block:** Shoot a survivable limb with ordinary ammunition and confirm a retained-bullet bit exists. Bandage the bleeding. That zone's Blood remains unchanged across several regeneration ticks; a different depleted, bullet-free zone and depleted global Blood can regenerate.
- [ ] **Pliers on self:** Complete extraction. A success message names the treated zone, a bullet bit clears, and that zone resumes regenerating once no bullets remain there. Extraction must not instantly refill Blood or remove the dressing.
- [ ] **Pliers on another player:** Repeat on another living patient, including an unconscious patient if possible. The patient's bullet state changes, not the treating player's.
- [ ] **Cancelled extraction:** Interrupt the action before completion. The retained bullet remains and regeneration stays blocked.
- [ ] **No bullet:** Use pliers on a character without retained bullets. The completed action reports that none was found and changes no medical state. The action being visible in this case is intentional: there is no custom medical-state synchronization.
- [ ] **Multiple locations:** Retain bullets on two distinct bones. Each extraction clears one bit. A zone remains blocked if another retained bullet is still in that same zone. Hits on the exact same bone currently share one presence bit, rather than a bullet count.
- [ ] **Ammunition exclusions:** Using a clean test character for each case, confirm bolts, flares, 40 mm rounds, rubber slugs, and beanbags create no retained-bullet state. Ordinary bullets, solid slugs, and buckshot do. Damage and bleeding from excluded projectiles still follow the game's normal behavior.
- [ ] **Reconnect:** Save/reconnect with one dressed unhealed wound and a retained bullet. Dressing remains visible, covered bleeding stays stopped, and the bullet still blocks zone regeneration. Removing the dressing after reconnect reopens the wound.
- [ ] **Server restart:** Repeat with a normal server save/shutdown/restart. Also retain a separate active severe bleed and confirm it restores and stays active below the threshold.
- [ ] **Saved treatment:** Extract the bullet, save/restart again, and confirm it does not return. Test a fully healed wound similarly: its dressing should already have been deleted, or be removed by the first eligible regeneration cleanup tick after loading, without reopening bleeding.
- [ ] **Missing attachment on restore:** If your admin tools allow it, remove an unhealed saved dressing while preserving the patient's medical record. The server should reopen the dressed wound after loading rather than leave it permanently closed.

If something fails, record the zone/selection, ammunition class, treatment item, whether it was self/target treatment, whether reconnect/restart was involved, the three medical masks, and the relevant client/server script errors.

## Diagnostic logs

Logging is enabled by default in `scripts/4_world/classes/wounds/iat_medicallog.c` (`IAT_MedicalLog.Enabled`). Search the server script log for `[IAT MEDICAL]`. Each line has an `event`, the player's four-part persistent entity ID (`pid`), and a runtime `entity` reference. Use `pid` to compare sessions; an ID may be zero before the engine assigns it. Runtime entity references alone are not stable across restarts.

Save/load snapshots include the three numeric medical masks, decoded bone lists, all six attachment slots (including ruined status), and current/max Blood for all ten zones. `activeBleeds` uses the vanilla bleeding bit layout; do not directly compare its numeric value with the medical wound mask.

### Persistence walkthrough

1. Injure and dress a player, leaving a retained bullet. From your **server-side** console, take a baseline with `IAT_MedicalLog.Snapshot(player, "MANUAL_BEFORE_RESTART");`.
2. Save normally. Find `SAVE_SERIALIZED` for that player and keep its following `BONES`, `ATTACHMENTS`, and `BLOOD_POOLS` lines. This records the save-hook state; it is not proof that the server committed the save to disk.
3. Reconnect or restart. Expect `LOAD_RESULT success=1 loaded_version=1` (boolean formatting may vary), followed by `LOAD_READ`. Compare the wound, bullet, and dressed masks to the last save for that player. Version 1 is the initial format; prototype formats are not migrated.
4. Check `AFTER_STORE_LOAD`, then `LOAD_RECONCILED` on the first medical reconciliation tick. Inventory can still be incomplete in `LOAD_READ`; use the later snapshot to assess attachments. Fully healed dressings may then be automatically deleted by the blood-regeneration modifier; `BANDAGE_HEALED_REMOVAL` explains that expected removal. Reconciliation may legitimately clear healed wounds or reopen wounds whose dressings are missing/ruined. Corresponding events explain those changes.
5. Confirm `REGEN_BLOCKED` for the bullet's zone. After extraction, expect `BULLET_EXTRACTED` and eventually `REGEN_ALLOWED` once that zone has no remaining bullets. The regeneration log includes actual before/after Blood for that tick. `REGEN_ALLOWED` means the bullet gate allows healing; full Blood or inadequate nutrition may still mean no increase.
6. Take `IAT_MedicalLog.Snapshot(player, "MANUAL_AFTER_TREATMENT");`, save/restart again, and confirm the removed bullet stays absent.

`LOAD_RESULT ... no_record_or_unreadable_header` means the first medical field could not be read. This can be expected for a player saved before the mod was installed, but should be investigated if that player previously had a successful medical save. `unsupported_version`, `incomplete_record`, and `LOAD_FAILED` identify failed loads. The diagnostic field is not serialized, and logging does not change the existing storage version or record layout.

### Treatment events

- `WOUND_RECORDED` / `BULLET_RECORDED`: a source or retained-bullet location was recorded. Repeated hits on the same bone still share one bit.
- `BANDAGE_APPLIED`: rag/dressing treatment completed after properties were transferred. `BANDAGE_FAILED` identifies an occupied/ruined slot or attachment creation failure.
- `BANDAGE_ATTACHED` / `BANDAGE_DETACHED`: normal manual attachment/removal callbacks. The attach callback is deliberately suppressed during application and loading.
- `WOUND_DRESSED`: a particular bone's bleeding source was closed by treatment.
- `WOUND_REOPENED`: missing or ruined dressing caused successful bleeding-source creation.
- `WOUND_HEALED`: the healed wound record was cleared.
- `BANDAGE_HEALED_REMOVAL`: all zones covered by this dressing are healed, bullet-free, and not actively bleeding; the modifier requested deletion of the worn item.
- `BULLET_EXTRACTED` / `EXTRACTION_EMPTY`: completed extraction result.
- `REGEN_BLOCKED` / `REGEN_ALLOWED`: first observed state for each zone, then only changes to that state. These do not print every tick.

Disable diagnostic output from a server-side console with `IAT_MedicalLog.Enabled = false;`, or change the default to `false` and rebuild. Re-enable with `IAT_MedicalLog.Enabled = true;`. No client RPCs or custom replicated variables are added.

## Proportional regeneration check

- [ ] With no active bleeding or retained bullets, set global Blood to 4500/5000 and LeftArm Blood to 90/100. Both are 90% full. Under unchanged food/water conditions, their percentage recovery should track together. At globalRate=0.3, expect about +18 global Blood and +0.36 LeftArm Blood over 60 seconds (allow for tick timing).
- [ ] Compare manual snapshots a minute apart. At this rate, LeftArm should be near 90.36, not 100. The dressing should remain until all its covered zones reach maximum Blood.
- [ ] Set global Blood to maximum while leaving LeftArm below maximum. LeftArm must continue recovering at its scaled rate.
- [ ] With a retained bullet in LeftArm, its Blood must not regenerate; other depleted bullet-free zones and global Blood can regenerate. After extraction, the scaled recovery resumes.
- [ ] Near maximum zone Blood, confirm regeneration caps at maximum and automatic dressing removal still occurs after the arm and hand both finish healing.

Regeneration transition logs now distinguish `globalRate` from `zoneRate` and include global Blood before/after that tick. They remain transition-only; use `IAT_MedicalLog.Snapshot(player, "REGEN_SAMPLE");` from the server console to compare ongoing recovery. Different initial deficits and the separate zone bleeding-damage scale can still give different completion times.


## Consolidation regression

- [ ] Pack and start both client and server. Check for unresolved static members, missing classes, and script compile errors. Extraction duration now references the plugin's static constant on both sides.
- [ ] Load a character saved with the current version 1 format with a retained bullet and dressed wound. Compare masks and attachments with its previous save; all mappings and bit assignments should match.
- [ ] Apply/remove/reattach a WesternZ dressing. Confirm application suppression still prevents premature closure, and unhealed removal reopens bleeding.
- [ ] Fully heal both zones of a shared dressing; confirm `BANDAGE_HEALED_REMOVAL` and safe deletion, including when global Blood is full.
- [ ] Extract with pliers and confirm blocked zone regeneration resumes at the same proportional rate. Save/restart and verify the extracted bullet stays absent.

These are refactor regressions; use the current tuning in PlayerConstants (-13 blood-loss constant and 25-second normal source duration) when assessing timing. Older examples mentioning 45 seconds predate that tuning.

After resetting the unreleased storage format to version 1, use a fresh test character or reset the old test character persistence before running the save/restart checks. Previous version 2 records are rejected; the older prototype version 1 used a different third field and should not be reused.


## Extraction tool damage

- [ ] Pliers still offers self/target extraction. Ordinary items do not. Pliers currently inherits 0 damage.
- [ ] Opt another tool into extraction with IAT_CanExtractBullet and a positive IAT_BulletExtractionHpDmg value. Both extraction actions appear.
- [ ] Successfully extract one bullet from yourself: global Health decreases once by that tool's configured amount. Check EXTRACTION_HP_DAMAGE before/after values.
- [ ] Extract from another player: only the patient's Health decreases, not the treating player's or the tool's durability.
- [ ] Cancel extraction or finish with no retained bullet: no Health damage occurs.
- [ ] Try a negative configured damage value: it is clamped to zero and cannot heal the patient.


## Map lookup regression

- [ ] Compile/load on client and server, including using an extraction action before any medical treatment to exercise lazy definitions.
- [ ] Confirm a left-hand bullet blocks LeftHand regeneration, not LeftArm or RightHand; the left-arm dressing still covers both left zones. Repeat foot/leg coverage.
- [ ] Remove a dressing over multiple unhealed bones in its region. All those treated wounds reopen, and other regions stay dressed.
- [ ] Load a previously saved version 1 character and compare decoded bones, masks, and attachments; assignments must match the pre-refactor save.
- [ ] With multiple retained bullets, extraction still chooses the same first registered bone. Ordinary bandaging, healed removal, and per-tool extraction damage remain unchanged.
