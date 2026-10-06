// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Register all medical diagnostic scenarios.
// Integration: optional harness and case discovery.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
modded class IAT_ScenarioRegistry
{
	void IAT_ScenarioRegistry()
	{
		m_Cases.Insert(new IAT_EM_DefinitionsCase);
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("BelowHalfReopensEveryCoveredWound", 0));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("AtHalfReopensEveryCoveredWound", 1));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("AboveHalfReopensEveryCoveredWound", 2));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("FullyHealedRemovalDoesNotReopen", 3));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("FullBloodRetainedBulletReopensZoneWounds", 4));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("RuinedKnifeCannotRemove", 5));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("NonKnifeCannotRemove", 6));
		m_Cases.Insert(new IAT_EM_ManualRemovalCase("RuinedDressingCanBeCutOff", 7));
		m_Cases.Insert(new IAT_EM_RemovalConditionsCase);
		m_Cases.Insert(new IAT_EM_TargetRemovalCase("KnifeRemovalAffectsPatientAndAllCoveredWounds", 0));
		m_Cases.Insert(new IAT_EM_CoverageCase("Head", 1, 1, "WZBandageHead", "WZ_Bandage_Head", "head"));
		m_Cases.Insert(new IAT_EM_CoverageCase("Torso", 2, 126, "WZBandageChest", "WZ_Bandage_Chest", "neck"));
		m_Cases.Insert(new IAT_EM_CoverageCase("LeftArm", 4, 1920, "WZBandageLArm", "WZ_Bandage_LArm", "leftshoulder"));
		m_Cases.Insert(new IAT_EM_CoverageCase("RightArm", 8, 30720, "WZBandageRArm", "WZ_Bandage_RArm", "rightshoulder"));
		m_Cases.Insert(new IAT_EM_CoverageCase("RightHand", 16, 65536, "WZBandageRArm", "WZ_Bandage_RArm", "rightforearmroll"));
		m_Cases.Insert(new IAT_EM_CoverageCase("LeftHand", 32, 32768, "WZBandageLArm", "WZ_Bandage_LArm", "leftforearmroll"));
		m_Cases.Insert(new IAT_EM_CoverageCase("LeftLeg", 64, 1966080, "WZBandageLLeg", "WZ_Bandage_LLeg", "leftleg"));
		m_Cases.Insert(new IAT_EM_CoverageCase("RightLeg", 128, 31457280, "WZBandageRLeg", "WZ_Bandage_RLeg", "rightleg"));
		m_Cases.Insert(new IAT_EM_CoverageCase("LeftFoot", 256, 100663296, "WZBandageLLeg", "WZ_Bandage_LLeg", "leftfoot"));
		m_Cases.Insert(new IAT_EM_CoverageCase("RightFoot", 512, 402653184, "WZBandageRLeg", "WZ_Bandage_RLeg", "rightfoot"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("head", "Head", 0, "WZBandageHead"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("neck", "Torso", 1, "WZBandageChest"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("pelvis", "Torso", 2, "WZBandageChest"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("spine", "Torso", 3, "WZBandageChest"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("spine1", "Torso", 4, "WZBandageChest"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("spine2", "Torso", 5, "WZBandageChest"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("spine3", "Torso", 6, "WZBandageChest"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftshoulder", "LeftArm", 7, "WZBandageLArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftarm", "LeftArm", 8, "WZBandageLArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftarmroll", "LeftArm", 9, "WZBandageLArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftforearm", "LeftArm", 10, "WZBandageLArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightshoulder", "RightArm", 11, "WZBandageRArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightarm", "RightArm", 12, "WZBandageRArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightarmroll", "RightArm", 13, "WZBandageRArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightforearm", "RightArm", 14, "WZBandageRArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftforearmroll", "LeftHand", 15, "WZBandageLArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightforearmroll", "RightHand", 16, "WZBandageRArm"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftleg", "LeftLeg", 17, "WZBandageLLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftlegroll", "LeftLeg", 18, "WZBandageLLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftupleg", "LeftLeg", 19, "WZBandageLLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftuplegroll", "LeftLeg", 20, "WZBandageLLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightleg", "RightLeg", 21, "WZBandageRLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightlegroll", "RightLeg", 22, "WZBandageRLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightupleg", "RightLeg", 23, "WZBandageRLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightuplegroll", "RightLeg", 24, "WZBandageRLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("leftfoot", "LeftFoot", 25, "WZBandageLLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("lefttoebase", "LeftFoot", 26, "WZBandageLLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("rightfoot", "RightFoot", 27, "WZBandageRLeg"));
		m_Cases.Insert(new IAT_EM_AnatomyCase("righttoebase", "RightFoot", 28, "WZBandageRLeg"));
		m_Cases.Insert(new IAT_EM_AmmoCase("Bullet_12GaugeSlug", true));
		m_Cases.Insert(new IAT_EM_AmmoCase("Bullet_12GaugePellets", true));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_RenamedRound", true));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_RenamedRubber", false));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_RenamedGrenade", false));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_RenamedBolt", false));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_RenamedFlare", false));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_RenamedBeanbag", false));
		m_Cases.Insert(new IAT_EM_AmmoCase("IAT_EM_UnknownAmmo", false));
		m_Cases.Insert(new IAT_EM_StorageCase("MedicalStateRoundtripAndWireLayout", 0));
		m_Cases.Insert(new IAT_EM_StorageCase("UnsupportedMedicalStorageVersionRejected", 2));
		m_Cases.Insert(new IAT_EM_StorageCase("MasksValidatedIndependently", 5));
		m_Cases.Insert(new IAT_EM_StorageCase("UnsupportedBulletBitsStrippedOnRoundtrip", 6));
		m_Cases.Insert(new IAT_EM_StorageCase("EmptyMedicalStateRoundtrip", 7));
		// Every zone tests both sides and the exact severity boundary.
		TStringArray zones = {"Head", "Torso", "LeftArm", "RightArm", "RightHand", "LeftHand", "LeftLeg", "RightLeg", "LeftFoot", "RightFoot"};
		foreach (string zone : zones)
		{
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 0.499, false, false, false));
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 0.5, false, false, true));
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 0.501, false, false, true));
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 0.25, true, false, true));
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 0.25, true, true, false));
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 1, false, false, true));
			m_Cases.Insert(new IAT_EM_ZoneBoundaryCase(zone, 1, true, true, false));
		}
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("ManualDressingDoesNotCloseBleeding", 0));
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("MissingDressingReopensOriginalCoveredBones", 1));
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("RuinedDressingReopensOriginalCoveredBones", 2));
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("UsableDressingPreservesTreatedHistory", 3));
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("SharedDressingWaitsForArmAndHand", 4));
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("FullBloodWithRetainedBulletKeepsDressing", 5));
		m_Cases.Insert(new IAT_EM_DressingLifecycleCase("FreshBleedKeepsHealedDressing", 6));
		m_Cases.Insert(new IAT_EM_HealedRemovalCase);
		m_Cases.Insert(new IAT_EM_RegenerationCase("ProportionalZoneRegeneration", 0));
		m_Cases.Insert(new IAT_EM_RegenerationCase("ZoneRegenerationCapsAtMaximum", 1));
		m_Cases.Insert(new IAT_EM_RegenerationCase("ZonesRecoverWhenGlobalBloodIsFull", 2));
		m_Cases.Insert(new IAT_EM_RegenerationCase("BloodModifierPreservesVanillaGlobalRegeneration", 3));
		m_Cases.Insert(new IAT_EM_BandagingCase("NoBleedCannotPrepareDressing", 0));
		m_Cases.Insert(new IAT_EM_BandagingCase("EachBandagingCycleTreatsOneSourceAndOneUse", 1));
		m_Cases.Insert(new IAT_EM_BandagingCase("RuinedOccupiedDressingBlocksTreatment", 2));
		m_Cases.Insert(new IAT_EM_BandagingCase("InvalidTreatmentMaterialRejected", 3));
		m_Cases.Insert(new IAT_EM_BandagingCase("DressingPreparationTransfersCleannessWithoutTreatment", 4));
		m_Cases.Insert(new IAT_EM_BandagingCase("ClosureHistoryRequiresTreatmentAndCoveringDressing", 5));
		m_Cases.Insert(new IAT_EM_BleedingCase("RegionalBleedingPreservesGlobalLoss", 0));
		m_Cases.Insert(new IAT_EM_BleedingCase("DisabledBloodLossSuppressesGlobalAndZoneLoss", 1));
		m_Cases.Insert(new IAT_EM_BleedingCase("ContaminatedSourceUsesBurnFlow", 2));
		m_Cases.Insert(new IAT_EM_BleedingCase("BelowHalfBloodBlocksNaturalExpiry", 3));
		m_Cases.Insert(new IAT_EM_BleedingCase("ExactlyHalfBloodAllowsNaturalExpiry", 4));
		m_Cases.Insert(new IAT_EM_BleedingCase("SevereExpiryRetriesAfterRecovery", 5));
		m_Cases.Insert(new IAT_EM_BleedingCase("TreatmentCancelsStaleQueuedExpiry", 6));
		m_Cases.Insert(new IAT_EM_BleedingCase("HealingReconciliationUsesBleedingTickInterval", 7));
		m_Cases.Insert(new IAT_EM_ExtractionCase("ExtractionClearsOneLocationInRegistrationOrder", 0));
		m_Cases.Insert(new IAT_EM_ExtractionCase("SuccessfulPliersExtractionCostsTenHealth", 1));
		m_Cases.Insert(new IAT_EM_ExtractionCase("EmptyExtractionCausesNoDamage", 2));
		m_Cases.Insert(new IAT_EM_ExtractionCase("NegativeToolDamageCannotHealPatient", 3));
		m_Cases.Insert(new IAT_EM_ExtractionCase("ZeroDamageExtractionStillRemovesBullet", 4));
		m_Cases.Insert(new IAT_EM_ExtractionCase("RuinedToolCompletionDoesNothing", 5));
		m_Cases.Insert(new IAT_EM_ExtractionCase("IncapableToolCompletionDoesNothing", 6));
		m_Cases.Insert(new IAT_EM_ExtractionCase("MissingToolCompletionDoesNothing", 7));
		m_Cases.Insert(new IAT_EM_ActionConditionsCase);
		m_Cases.Insert(new IAT_EM_VomitCase);
		m_Cases.Insert(new IAT_EM_EdgeCase("HealedAndIncompleteMissingDressingHistory", 0));
		m_Cases.Insert(new IAT_EM_EdgeCase("ActiveBleedPreservesFullBloodDressedHistory", 1));
		m_Cases.Insert(new IAT_EM_EdgeCase("FailedReopeningPreservesDressedBit", 2));
		m_Cases.Insert(new IAT_EM_EdgeCase("UnknownDressingSlotHasNoSideEffects", 3));
		m_Cases.Insert(new IAT_EM_EdgeCase("IncompatibleAttachmentBlocksDressing", 4));
		m_Cases.Insert(new IAT_EM_EdgeCase("RuinedDressingCannotSupportRegeneration", 5));
		m_Cases.Insert(new IAT_EM_EdgeCase("MedicalDetachNotificationReopensWound", 6));
		m_Cases.Insert(new IAT_EM_EdgeCase("UnrelatedAttachmentEventsPreserveWounds", 7));
		m_Cases.Insert(new IAT_EM_EdgeCase("StorageRequiresRegisteredBleedingDefinitions", 8));
		m_Cases.Insert(new IAT_EM_EdgeCase("ModifierKeepsHealedDressingCleanupTick", 9));
		m_Cases.Insert(new IAT_EM_EdgeCase("AnatomyAliasesAndConfigFallback", 10));
		m_Cases.Insert(new IAT_EM_HitCase("ZeroDamageDoesNotRetainBullet", 0));
		m_Cases.Insert(new IAT_EM_HitCase("NegativeDamageDoesNotRetainBullet", 1));
		m_Cases.Insert(new IAT_EM_HitCase("RubberHitDoesNotRetainBullet", 2));
		m_Cases.Insert(new IAT_EM_HitCase("HitWithoutBleedingComponentUsesZoneFallback", 3));
		m_Cases.Insert(new IAT_EM_HitCase("HitUsesRegisteredSelectionInsteadOfZoneFallback", 4));
		m_Cases.Insert(new IAT_EM_HitCase("HitWithoutResolvableAnatomyDoesNotRetainBullet", 5));
		m_Cases.Insert(new IAT_EM_LoggingCase);
		m_Cases.Insert(new IAT_EM_PatientCase("TargetExtractionAffectsPatientOnly", 0));
		m_Cases.Insert(new IAT_EM_PatientCase("DeadPatientAndActorRejected", 1));
		m_Cases.Insert(new IAT_EM_PatientCase("PlayerMedicalPersistenceHooksRoundtrip", 2));
		m_Cases.Insert(new IAT_EM_PatientCase("PlayerMedicalHooksRemainDedicatedOnly", 3));
		m_Cases.Insert(new IAT_EM_ExtractionToolTest());
		m_Cases.Insert(new IAT_EM_AmmoClassificationTest());
	}
}
#endif
#endif
