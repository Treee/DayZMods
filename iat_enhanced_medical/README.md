# Enhanced Medical

# How do I make this mod useful?

# Localizaiton

- https://github.com/WoozyMasta/dayz-stringtable

# Attribution

## Current medical implementation

`PluginIATMedical` handles server-side medical rules. `IAT_MedicalState` stores wounds, retained bullets, and dressed wounds on each player through `OnStoreSave` / `OnStoreLoad`. Bandages use the existing WesternZ classes and slots with normal inventory replication; this mod does not define replacement bandage classes or synchronize custom medical masks.

Rags and bandage dressings treat all active bleeding sources covered by the selected region. Arms cover hands; legs cover feet. Removing or ruining a dressing reopens covered wounds until their zone Blood has fully recovered. The blood-regeneration modifier automatically deletes a dressing once all covered zones are fully healed, with no retained bullets or active bleeding, like an applied splint. Shared arm/hand and leg/foot dressings wait for both zones. Active bleeding below 50% zone Blood cannot expire naturally. Retained bullets prevent regeneration only in their zone; pliers extract one retained-bullet location per completed action, allowing regeneration once that zone has no remaining bullets.

Bullet presence is one bit per bone, not a count of repeated hits on the same bone. Extraction takes 10 seconds and is offered without a client-side bullet check; an empty treatment reports no retained bullet. Bolts, flares, 40 mm rounds, rubber slugs, and beanbags are excluded from bullet retention. Ordinary bullets, solid slugs, and buckshot are included.

See [the in-game verification checklist](tools/IN_GAME_CHECKLIST.md) for setup, expected behavior, and persistence checks. Source-level checks have passed; DayZ compilation, attachment rendering, and runtime persistence still require in-game verification.

Server diagnostic logging is enabled by default with the `[IAT MEDICAL]` prefix. See the [diagnostic logging walkthrough](tools/IN_GAME_CHECKLIST.md#diagnostic-logs) for comparing save/load snapshots and confirming regeneration behavior.

Zone regeneration scales the vanilla global regeneration rate by `zone maximum Blood / global maximum Blood`. With 100-point zones and 5,000 global Blood, the multiplier is 0.02: a global rate of 0.3 gives each eligible zone 0.006 points/second. This matches percentage recovery rates, not absolute levels or completion times. Zone damage still uses its separate bleeding multiplier, and zone healing continues when global Blood is full. Retained bullets still block their zone.


## Code organization

- `scripts/3_game/constants/modded_playerconstants.c`: only overrides of vanilla bleeding constants. Current blood-loss and duration values are -13 and 25 seconds.
- `scripts/4_world/plugins/pluginiatmedical.c`: medical tuning, ordered bone/zone definitions, bandage coverage, static mapping helpers, and server treatment/healing rules. Static members can be used by client action callbacks without obtaining a plugin instance; the plugin instance is registered server-side.
- `IAT_MedicalState`: per-player records and versioned serialization. Bone ordering and bit assignments are part of the save format and must remain stable.
- `IAT_MedicalLog`: diagnostic output and manual snapshots.
- `PlayerBase`: owns medical state, save/load hooks, and protected loading/application flags. Attachment callbacks forward medical decisions to the plugin.
- `BloodRegenMdfr`: schedules proportional regeneration and calls the plugin for healed-dressing cleanup. Its activation/deactivation checks retain a cleanup tick even when global Blood is full.
- Bleeding and action overrides connect vanilla events to medical behavior. WesternZ supplies the actual bandage classes and assets.

The unreleased storage format starts at version 1 and stores wound, bullet, and dressed-wound bone masks. Pre-release formats are not migrated. Log event names, tuning values, and attachment timing remain unchanged. No custom medical-state replication or plugin-owned player registry is introduced.


## Extraction tools

ItemBase provides `IAT_CanExtractBullet()` (default false) and `IAT_BulletExtractionHpDmg()` (default 0). Pliers opts into extraction and currently inherits zero patient damage. Other tool classes can override both methods; self/target extraction actions are registered automatically through ItemBase.SetActions. The capability should be constant per item class because DayZ caches action lists per type, and custom SetActions overrides must call super.

A successful extraction subtracts the tool's nonnegative damage value from the patient's global Health. Cancelled actions and attempts with no retained bullet do no damage. Negative values cannot heal the patient. `EXTRACTION_HP_DAMAGE` logs the tool, configured damage, and patient Health before/after.

For example, to make pliers cause 5 Health damage, add this method inside its existing modded class:

```c
override float IAT_BulletExtractionHpDmg()
{
    return 5;
}
```


## Medical lookup definitions

The plugin registers each bandage region, damage zone, and bone once in `IAT_InitDefinitions`. Maps and ordered processing arrays are derived lazily from those registrations, including on clients without a plugin instance. Bone/zone bit indices are explicit save-format IDs; keep them stable. Registration order also preserves the existing extraction order and default bone chosen for a zone.

Bone-to-zone, bone-to-bit, zone-to-slot, and slot-to-item lookups use maps. Each zone has a precomputed bone mask, so checking retained bullets uses one mask intersection. Bandage removal/reopening checks visit only the bones and zones assigned to that region. Remaining loops process multiple wounds, zones, or log entries rather than searching the full lists for a mapping. Getter arrays are shared read-only views by convention; callers must not modify them.

Version 1 storage and gameplay tuning are unchanged. Source-level validation compared every bone/zone assignment and bandage class with the previous definitions and checked the zone masks against the old scan logic.
