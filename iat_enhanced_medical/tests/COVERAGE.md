# Contract and coverage map

Scope: current Enhanced Medical code, with vanilla systems assumed functional.
These tests characterize existing behavior. Expectations use explicit anatomy,
save fields, masks, boundaries and independently calculated numeric examples.

## Requirement map

| Contract | Evidence |
| --- | --- |
| R01: stable bleeding bits, anatomy, order and deduplication | 29 `Anatomy_*` cases, `DefinitionDefaultsMasksAndUnknownLookups`, ten `Coverage_*` cases, `AnatomyAliasesAndConfigFallback` |
| R02: six dressings cover ten zones, including hands/feet; unknown lookups return defaults | `Coverage_*`, definition defaults, `UnknownDressingSlotHasNoSideEffects` |
| R03: retain bullets/slugs/buckshot; exclude launcher/nonpenetrating rounds, including renamed descendants | Ten `Ammunition` cases |
| R04: version 1 contains only version/bullets/dressed masks; validate masks independently | Five `Storage` cases, `StorageRequiresRegisteredBleedingDefinitions` |
| R05: one source/use per bandaging cycle, reused regional dressing; rejected preparation consumes nothing | Six `Bandaging` cases, `IncompatibleAttachmentBlocksDressing` |
| R06: attachment alone does not treat; treatment records individual bones; fresh sources clear only their history | `ManualDressingDoesNotCloseBleeding`, closure-history and cycle cases |
| R07: missing/ruined dressing reopens only incomplete original covered bones; failed creation preserves history | Missing/ruined dressing cases, `HealedAndIncompleteMissingDressingHistory`, `FailedReopeningPreservesDressedBit`, `ActiveBleedPreservesFullBloodDressedHistory` |
| R08: delete dressing only after all covered zones fully heal without bullets/bleeds | Eight `Dressings` cases, `ModifierKeepsHealedDressingCleanupTick` |
| R09: strict below-50% covering requirement; exactly 50% needs none; bullets always block their own zone | 70 all-zone `Regen_*` cases, ruined-covering case, 29 anatomy bullet-locality checks |
| R10: scale 0.05 for a 100-point zone; honor time/rate/pressure/flow/type; cap recovery and allow full-global recovery | Four `Regeneration` cases and loss/type cases in `Bleeding` |
| R11: severe natural-expiry guard, recovery retry, stale-queue cancellation, three-second healing reconciliation | Five expiry/timing cases in `Bleeding` |
| R12: repeated hits retain one bone bit; positive qualifying hits use selection or zone fallback independently of vanilla random bleeding | Six `Hits` cases and `Anatomy_*` |
| R13: extraction clears one location; preserve others/history; damage only after success, never heal from negative damage | Eight `Extraction` cases and target/dead patient cases |
| R14: pliers opt in and register both actions; default items opt out; availability/completion validate tool/patient | Tool/registration, availability and patient cases |
| R15: player hooks append/read masks and preserve state after load; original nondedicated guards remain | `PlayerMedicalPersistenceHooksRoundtrip`, `PlayerMedicalHooksRemainDedicatedOnly` |
| R16: diagnostics name bits in registration order without mutating medical state | Definition defaults, `MedicalSnapshotsDoNotMutateState` and actual emitted snapshot logs |
| R17: current vomit override accepts its additional crouch-mask command and rejects unrelated commands | `VomitActivationCommands` using the existing symptom |

## Function map

Component evidence means the production function runs in DayZDiag and has
behavioral assertions. Constructor/registration evidence is indirect through the
resulting definitions, action lists and real plugin availability. Partial rows
explicitly identify remaining native/dedicated/animation paths.

| Production functions | Evidence and limitations |
| --- | --- |
| `IAT_MedicalBoneDefinition`: constructor, `GetBit`, `GetZone` | Definition defaults and anatomy cases |
| `IAT_MedicalZoneDefinition`: constructor, `AddBone`, `GetBit`, `GetBoneMask`, `GetFirstBone`, `GetSlot` | Empty defaults, first-bone stability, idempotent union, coverage |
| `IAT_MedicalBandageDefinition`: constructor, `AddZone`, `AddBone`, `GetItemClass`, `GetZones`, `GetBones` | Ordered contents, shared coverage and defaults |
| `PluginManager.Init`; plugin constructor; `IAT_InitBandageCoverageWZ`, `IAT_RegisterBandage`, `IAT_RegisterZone` | Real plugin initialization and exact resulting maps; repeated-init short circuit source-reviewed |
| `IAT_RegisterBleedingSelection`, `IAT_ResolveBleedingSelectionZone` | 29 selections, deduplication, brain alias, case normalization and config fallback; intentional `Error` branches excluded below |
| `IAT_GetRegisteredBoneMask`, `IAT_GetBones`, `IAT_GetDamageZones`, `IAT_GetBandageSlots` | Exact counts/masks/order and resulting behavior |
| `IAT_GetBandageZones`, `IAT_GetBandageBones` | All regional coverage and unknown-slot null defaults |
| `IAT_GetBulletBoneBit`, `IAT_GetDamageZoneBit`, `IAT_GetZoneBoneMask`, `IAT_GetFirstBoneForZone` | Explicit bits/masks/order and unknown defaults |
| `IAT_GetBandageSlot`, `IAT_GetBandageClass`, `IAT_MapBoneNameToDamageZone` | All registered mappings and unknown slot/class defaults; unknown bone's `Error` path excluded |
| `OnBleedingSourceAdded`, `OnBleedingSourceClosed`, `RecordBullet` | Selective history, treatment/natural distinction, repeat-hit preservation |
| `PrepareDressing` | No source, null/ruined material, new/reused attachment, ruined/incompatible slot, cleanness and no premature treatment; native creation failure unforced |
| `ExtractBullet` | One-bit extraction/order, same-zone remaining bullet, empty/null/dead patient and output reset; multiplayer-client guard requires separate process |
| `OnBandageAttached`, `OnBandageDetached` | Manual/unrelated/null events and medical detach reopening |
| `UpdateHealing`, `ReopenDressedWounds` | Covered/missing/ruined, healed/incomplete/active/dead, selective history, region isolation, failed add |
| `RemoveHealedBandages`, `CanRemoveBandage`, `HasHealedBandage` | Shared regions, retained bullet/fresh bleed, absent/nonmedical/dead state and deferred deletion |
| `IsWearingBandage`, `CanRegenerateZone`, `NeedsZoneRegen`, `HasBulletInZone`, `IsZoneHealed`, `IsSevere` | Every zone at 49.9/50/50.1%, covered severe/bullet, full with/without bullet; ruined/incompatible and unknown covering |
| `IAT_GetZoneBloodScale` | Independently computed 0.05/0.1, zero/negative zone maximum; nonpositive global recovery range needs differently configured player maxima |
| `LogBones`, `LogEvent`, `LogSnapshot` | Exact mask names/order, disabled/null guards, state invariance and emitted snapshot; no exhaustive log-text contract |
| `IAT_MedicalState.Save`, `Load` | Raw version/field order, diagnostic exclusion, empty/mixed/full masks, unsupported version/bits, missing registered definitions; unavailable plugin and native read-failure branches unverified |
| `PlayerBase.IAT_GetMedicalState` | Partial: original nondedicated null guard; dedicated allocation/caching supplied by fixture, needs dedicated-process verification |
| `PlayerBase.EEItemAttached`, `EEItemDetached` | Partial: original nondedicated guards; dedicated forwarding/replication/rendering needs server verification; plugin boundaries tested |
| `PlayerBase.OnStoreSave`, `OnStoreLoad`, `AfterStoreLoad` | Complete player record, appended masks, exact stream position and after-load invariance; not database restart or base-load failure proof |
| `BloodRegenMdfr.ActivateCondition`, `DeactivateCondition`, `OnTick`, `IAT_GetBloodRegenRate`; `IAT_PluginMedical.IAT_RegenerateZones`, `IAT_NeedsMedicalTick` | Existing modifier: eligibility, scale/time/rate/cap, global preservation, full-global recovery/cleanup scheduling, conscious well-fed rate; unconscious branch source-reviewed |
| `BleedingSourcesManagerBase.RegisterBleedingZoneEx` | Real registrations feed exact anatomy and repeat-player deduplication |
| `BleedingSource.OnUpdateServer` | Loss/pressure/time/flow/type, no-loss flag and expiry retry; vanilla rendering suppressed |
| `BleedingSourcesManagerServer.IAT_GetDamageZoneFromMostSignificantSource`, `IAT_GetDamageZoneFromSourceBit` | Selected source and absent bit |
| `BleedingSourcesManagerServer.AddBleedingSource`, `RemoveBleedingSource`, `RequestDeletion` | Real source creation/treatment/expiry, one-source closure, queue cancellation, half-blood guard; already-absent removal source-reviewed |
| `BleedingSourcesManagerServer.ProcessHit`, `OnTick` | Positive/zero/negative/excluded hits, real model selection and fallback, duplicate hits, reconciliation interval |
| `ItemBase.IAT_CanExtractBullet`, `IAT_BulletExtractionHpDmg`; `Pliers.SetActions`, `IAT_CanExtractBullet`, `IAT_BulletExtractionHpDmg` | False/zero defaults, true/10 pliers and actual cached action map; negative/zero tool variants |
| `IAT_ActionExtractBulletSelf`: constructor, `CreateConditionComponents`, `HasTarget`, `ActionCondition`, `IAT_Extract` | Identity, condition construction, live/dead/null/incapable/ruined tool, completion/masks/Health; vehicle and native condition-component execution unverified |
| `IAT_ActionExtractBulletTarget`: constructor, `CreateConditionComponents`, `HasTarget`, `ActionCondition`, `IAT_Extract` | Identity/construction, absent/nonplayer/self/dead/live target, patient-only damage; vehicle/jump/swim/ladder guards unverified |
| `ActionConstructor.RegisterActions` | Both actions reachable through real Pliers action map |
| `IAT_ActionExtractBulletCB.CreateActionComponent` | Not executed: native animation-owned callback. Ten-second constant asserted; wiring source-reviewed; actual timing needs in-game verification |
| `ActionBandageBase.ApplyBandage` | Preparation rejection, exactly one source/use and attachment reuse |
| `VomitSymptom.CanActivate` | Existing symptom command inputs; animation outside scope |
| `PlayerConstants` overrides | -13/25/0.01/0.47 constants and loss/expiry integration |

## Limits and fixture evidence

There is no line/branch instrumentation in the current harness. Case counts and
this map are behavioral evidence, not a claimed 100% measurement.

Offline DayZDiag is authoritative but nondedicated. The opt-in test getter supplies
only medical-state availability. Tests reuse the production plugin, existing
managers/modifier/symptom, bleeding simulation and health/inventory systems. Player
save/load tests prove script integration under that seam, not a dedicated restart.

FileSerializer and ScriptReadWriteContext probes zero-filled exhausted primitive
reads and returned success. A write-only context returned failure but raised a VM
exception, correctly invalidating the run. These cannot safely establish the
intended absent-header/incomplete-record `Read`-failure branches. No passing EOF
expectation replaces those requirements. Real truncated-save safety is unproven.

Intentional `Error(...)` branches for conflicting/duplicate bits, unsupported zone
coverage and unknown anatomy produce engine error evidence, rejected by the
verifier. Automated testing of them needs separate expected-diagnostic support;
this suite does not weaken verification or change production error handling.

An isolated real bleeding-source case reproduced a shutdown access violation after
assertions/cleanup. Suppressing vanilla bleeding HUD/particle effects for the
opted-in fixture let the same medical case pass including termination. This is
fixture evidence, not proof of a vanilla-game defect. Borrowed systems and native
serializers are released during cleanup before shutdown.

Dedicated/client roles, replication, attachment appearance, full action animation,
cancellation/vehicles, unconscious bonus, custom player maxima, unavailable-plugin
and native failure paths, and database restart remain separate verification gaps.
The existing in-game checklist remains useful for those integration checks.

## Executed evidence

The original two-case baseline passed in `923973f885f14368b730e20b1954082e` on
2026-10-04. The expanded staged suite passed in
`7f551872e101401a8dc8f2b832a1fdcf`: 184 cases, 1,942 assertions, completed cleanup
and harness-verified termination. Invalid earlier fixture probes are not counted.

Final verification and a deliberate staged boundary-defect experiment are recorded
in [VERIFICATION.md](VERIFICATION.md). No deliberately wrong code is shipped.

## Manual removal requirements

- R18 (self removal): a non-ruined knife and attached dressing offer a self action without a target; completion destroys one dressing. Evidence: `KnifeRemovalAvailabilityAndRegistration` and eight removal boundary/tool cases.
- R19 (other-player removal): the target's dressing is required independently of the actor's dressings; completion removes the patient's dressing and reopens the patient's wounds. Evidence: `KnifeRemovalAffectsPatientAndAllCoveredWounds`.
- R20 (wound reconciliation): all recorded unhealed sources covered by the removed dressing reopen together; other dressings remain attached. Full Blood without a retained bullet does not reopen; full Blood with a bullet reopens the affected zone's recorded wounds. Evidence: below/at/above-half, full-healing, and retained-bullet removal cases. Existing natural-expiry cases cover the unchanged threshold rule.

Each action removes one dressing in fixed head/chest/left-arm/right-arm/left-leg/right-leg order. ItemBase defaults the removal capability to false. Each supported knife class overrides the capability method to return true and registers both removal actions in its own SetActions override; subclasses inherit that capability. Interactive and multiplayer validation remains in the manual checklist.

Manual-removal component tests invoke our IAT_Remove method directly. They do not invoke or expose protected DayZ OnFinishProgressServer callbacks. Patient selection by the callback, action timing, cancellation and engine dispatch remain in-game checks.

Extraction component tests now invoke IAT_Extract directly. Both extraction completion overrides retain protected engine access. Callback dispatch and target routing remain manual checks; no wrapper or visibility expansion is added.

Manual-removal fixtures process the vanilla inventory deletion queue before checking attachment absence, then invoke custom UpdateHealing reconciliation. DeleteSafe is deferred; all removal and wound-mask assertions remain. Dedicated detach dispatch and inventory junctures remain manual integration checks.

Ammo classification uses DayZ IsKindOf for bullet/shotgun families and excluded projectile descendants. OnlyFirearmRoundsAreRetained also checks a six-class inheritance chain to cover removal of the old four-level limit.
