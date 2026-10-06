# Enhanced Medical

# How do I make this mod useful?

# Localizaiton

- https://github.com/WoozyMasta/dayz-stringtable

# Attribution

## Current medical implementation

`IAT_PluginMedical` handles server-side medical rules. `IAT_MedicalState` stores retained bullets and dressed wounds on each player through `OnStoreSave` / `OnStoreLoad`. Bandages use the existing WesternZ classes and slots with normal inventory replication; this mod does not define replacement bandage classes or synchronize custom medical masks.

Each vanilla bandaging cycle treats one bleeding source and consumes one use. The regional dressing is created once and reused by subsequent treatments; each treated bone is recorded separately. Manually attaching a dressing does not close active bleeds. Arms cover hands; legs cover feet. Removing or ruining a dressing reopens covered wounds until their zone Blood has fully recovered. The blood-regeneration modifier automatically deletes a dressing once all covered zones are fully healed, with no retained bullets or active bleeding, like an applied splint. Shared arm/hand and leg/foot dressings wait for both zones. Below 50% zone Blood, natural bleed expiry is blocked and zone regeneration requires a usable covering dressing. At 50% or above, vanilla natural bleed expiry is allowed. Retained bullets prevent regeneration only in their zone; pliers extract one retained-bullet location per completed action, allowing regeneration once that zone has no remaining bullets.

Each positive eligible bullet hit has a 45% chance to retain a bullet at its resolved bone, independent of power or previous hits. Bullet presence is one bit per bone, so repeated hits cannot add a second bullet at that bone. A failed retention roll never clears an existing bullet. Bolts, flares, 40 mm rounds, rubber slugs, and beanbags are excluded; ordinary bullets, solid slugs, and buckshot are eligible.

Each zone with at least one retained bullet loses 10 mL of global Blood every 10 seconds, even through a usable dressing. Its regional Blood loses the proportionate amount using the existing zone scale (0.5 points per interval for a 100-point zone). Multiple retained bones in one zone share that zone's loss; separate affected zones each contribute. This exceeds normal well-fed global regeneration of 0.3 mL/second for even one retained zone. The loss does not create an active bleeding-source icon or reopen a bandaged source. Extraction stops this additional loss once the zone's last retained bullet is removed. The interval is maintained by the server bleeding manager, respects disabled blood loss and invulnerability, and restarts after load; bullet state remains in the existing version-1 save record.

Extraction takes 10 seconds and is offered without a client-side bullet check; an empty treatment reports no retained bullet. A successful extraction opens a bleeding source at the extracted bone, even with a dressing attached. Normal bandaging closes it again and records the new dressed wound. Automatic dressing cleanup waits for full recovery of all covered zones with no bullets or active bleeds. Manual cutting remains allowed before recovery and reopens the treated wound. Empty and cancelled attempts open no extraction wound. Extraction adds no fixed percentage of regional Blood damage; the new bleeding source causes normal regional/global loss on its ticks.

## Illness treatment window

The tuning goal for untreated cholera, salmonella, and wound infection is approximately 45-60 minutes under comparable starting conditions. This is not a fixed death timer: initial Health, nutrition, immunity, stomach contents, other injuries, and random vomiting affect survival.

- Cholera and salmonella vomiting now drain 135 Water and 93 Energy instead of 450 and 310.
- Cholera's continuous Water drain is 0.15/second at maximum agent load instead of 0.5.
- Salmonella invasibility is 0.225 instead of 0.75; immunity, maximum agent count, and medicine resistance retain vanilla behavior.
- Parameterized vomiting while cholera or salmonella is active loses 30% of the requested stomach percentage: vanilla cholera's 65% becomes 19.5%, salmonella's 50% becomes 15%. Ordinary vomiting and contamination vomiting keep their original stomach loss. The shared symptom parameter is not modified.
- Stage-two wound infection's net damage is 0.033333333 Health/second, projecting to 50 minutes from 100 Health. Vanilla still compensates for natural Health regeneration and suppresses infection damage during antibiotics.

Engine-backed tests verify these component effects. Full cholera/salmonella survival windows require the timed gameplay benchmark in the in-game checklist; they have not been established by the component tests.

See [the in-game verification checklist](tools/IN_GAME_CHECKLIST.md) for setup, expected behavior, and persistence checks. Source-level checks have passed; DayZ compilation, attachment rendering, and runtime persistence still require in-game verification.

Server diagnostic logging is enabled by default with the `[IAT MEDICAL]` prefix. See the [diagnostic logging walkthrough](tools/IN_GAME_CHECKLIST.md#diagnostic-logs) for comparing save/load snapshots and confirming regeneration behavior.

Zone loss and regeneration use `zone maximum Blood / (global maximum Blood - (fatal Blood threshold + 500))`. With 100-point zones, 5,000 maximum Blood, and a 2,500 fatal threshold, the scale is 0.05: a global regeneration rate of 0.3 gives each eligible zone 0.015 points/second. The comparison range is 3,000?5,000 Blood; 4,000 corresponds to 50% zone recovery. Loss has an additional severity multiplier of 1.0. This does not change vanilla death, global Blood regeneration, or low-pressure bleeding rules. Zones can still recover when global Blood is full, subject to the bullet and dressing rules. Nonpositive recovery ranges disable this scaling to avoid division by zero.


## Code organization

- `scripts/3_game/constants/modded_playerconstants.c`: only overrides of vanilla bleeding constants. Current blood-loss and duration values are -13 and 25 seconds.
- `scripts/4_world/plugins/iat_pluginmedical.c`: medical tuning, bone, zone, and bandage definitions, bandage coverage, instance mapping helpers, diagnostic logging, and server treatment/healing rules. Constants remain available to client action callbacks; the plugin instance is registered server-side.
- `IAT_MedicalState`: per-player records and versioned serialization. Bone ordering and bit assignments are part of the save format and must remain stable.
- `PlayerBase`: owns medical state, attachment notifications, and save/load hooks. Attachment callbacks forward medical decisions to the plugin.
- `BloodRegenMdfr`: retains vanilla rate calculation and bridges modifier scheduling to the plugin. `IAT_PluginMedical` owns regional regeneration, the medical-tick decision, and healed-dressing cleanup. Its activation/deactivation checks retain a cleanup tick even when global Blood is full.
- Bleeding and action overrides connect vanilla events to medical behavior. WesternZ supplies the actual bandage classes and assets.

The unreleased storage format starts at version 1 and stores the version, retained-bullet mask, and dressed-wound mask. Pre-release formats are not migrated. Log event names, tuning values, and attachment timing remain unchanged. No custom medical-state replication or plugin-owned player registry is introduced.


## Extraction tools

ItemBase provides `IAT_CanExtractBullet()` (default false) and `IAT_BulletExtractionHpDmg()` (default 0). Pliers overrides the capability and damage methods, causes 10 Health damage per successful extraction, and explicitly registers both actions in Pliers.SetActions. Other eligible tool classes must override the capability and explicitly register their actions. The capability should be constant per item class because DayZ caches action lists per type, and custom SetActions overrides must call super.

A successful extraction subtracts the tool's nonnegative damage value from the patient's global Health. Cancelled actions and attempts with no retained bullet do no damage. Negative values cannot heal the patient. `EXTRACTION_HP_DAMAGE` logs the tool, configured damage, and patient Health before/after.

For example, to make pliers cause 5 Health damage, add this method inside its existing modded class:

```c
override float IAT_BulletExtractionHpDmg()
{
    return 5;
}
```


## Medical lookup definitions

The plugin initializes WesternZ bandage regions and damage-zone coverage in its constructor. A `BleedingSourcesManagerBase.RegisterBleedingZoneEx` override observes successful vanilla registrations and derives selection names, bit IDs, and registration order. An explicit anatomy resolver maps known bleeding selections to medical damage zones; skeleton names are not reliably present in DamageZones.componentNames. Unknown modded selections fall back to the player config component lookup and report an error if unresolved. Repeated registrations from additional players are deduplicated. Three maps hold the resulting definitions, and one ordered selection array controls extraction priority. Internally, existing bone-named getters now refer to bleeding selections, which may differ from particle bones.

Bone-to-zone, bone-to-bit, zone-to-slot, and slot-to-item lookups use maps. Each zone has a precomputed bone mask, so checking retained bullets uses one mask intersection. Bandage removal/reopening checks visit only the bones and zones assigned to that region. Remaining loops process multiple wounds, zones, or log entries rather than searching the full lists for a mapping. Definition maps and coverage arrays are shared read-only views by convention; callers must not modify them. The three small definition classes live in the plugin file.

Version 1 still stores the version and two masks. Mask IDs now follow vanilla bleeding registration; use fresh saves after this change or any registration reorder. New selections are discovered automatically; names without a known anatomy mapping or a matching config component require a resolver entry. New damage zones require a bandage coverage entry; missing mappings and conflicting bits report explicit errors. The engine bleeding-source bit limit still applies.

## Zone-based injury and dressed-wound history

There is no general wound mask. Zone Blood below 50% requires a usable covering bandage for zone regeneration; at exactly 50% or above, no bandage is required. Retained bullets always block their zone. Vanilla global Blood regeneration is unchanged. `DressedWounds` retains the original treated bone locations for reopening when a dressing is missing or ruined, and clears as zones fully heal.

The unreleased version-1 record contains only the version, bullets, and dressed wounds. Both masks are validated against the supported bone mask independently. Use fresh player saves when testing this layout.


## Manual bandage removal

Hold a non-ruined knife and complete **Cut off bandage** on yourself (crouched),
or **Cut off person's bandage** on another living player within normal action
reach. Both actions take five seconds and require an attached WesternZ dressing.
Each completion destroys one dressing, including dirty or ruined dressings,
in this order: head, chest, left arm, right arm, left leg, right leg.
Cancellation does not remove anything. Supported vanilla knife classes and their
subclasses are HuntingKnife, CombatKnife, KitchenKnife, SteakKnife, StoneKnife,
BoneKnife, FangeKnife and KukriKnife. WesternZ knives inheriting WZ_Melee_Knife_Base also opt in and register both actions through that base.

Manual removal is allowed before healing finishes. Every recorded dressed wound
covered by the removed dressing reopens together unless its zone has full Blood
and no retained bullet. Other regional dressings remain attached. Above or at
50% zone Blood, reopened bleeding follows the existing natural-expiry rule;
below 50%, natural expiry is blocked. Safe healing remains full zone Blood with
no retained bullet; manual removal does not change automatic healed cleanup.
Cutting adds no direct patient Health damage or new infection mechanic.

## Source organization

Runtime script files match their primary class name; closely related callback classes stay in the owning action file, while widely reused callbacks can be separate. Small medical lookup definitions live under classes/wounds; item opt-ins are separate files under entities/itembase. Engine completion callbacks remain protected; diagnostic cases test IAT_Extract and IAT_Remove directly. Source changes follow the workspace AGENTS.md and repository .github/dayz.instructions.md, with DayZ semantics taking precedence over illustrative Reforger syntax.
