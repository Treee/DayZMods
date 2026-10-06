// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_DefinitionsCase : IAT_EM_PlayerCase
{
	void IAT_EM_DefinitionsCase() { m_Suite = "Definitions"; m_Name = "DefinitionDefaultsMasksAndUnknownLookups"; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		IAT_MedicalBoneDefinition bone = new IAT_MedicalBoneDefinition(8, "Torso");
		EqualInt(bone.GetBit(), 8, "Bone definition bit");
		Check(bone.GetZone() == "Torso", "Bone definition zone", "Torso", bone.GetZone());
		IAT_MedicalZoneDefinition zone = new IAT_MedicalZoneDefinition(4, "testSlot");
		EqualInt(zone.GetBoneMask(), 0, "Empty zone mask");
		Check(zone.GetFirstBone() == "", "Empty zone first bone", "", zone.GetFirstBone());
		zone.AddBone("first", 8); zone.AddBone("second", 32); zone.AddBone("first", 8);
		EqualInt(zone.GetBoneMask(), 40, "Zone mask union is idempotent");
		EqualInt(zone.GetBit(), 4, "Zone bit independent of bone mask");
		Check(zone.GetFirstBone() == "first", "First registered bone stays stable", "first", zone.GetFirstBone());
		Check(zone.GetSlot() == "testSlot", "Zone slot", "testSlot", zone.GetSlot());
		IAT_MedicalBandageDefinition dressing = new IAT_MedicalBandageDefinition("testItem");
		dressing.AddZone("LeftArm"); dressing.AddZone("LeftHand"); dressing.AddBone("leftarm");
		Check(dressing.GetItemClass() == "testItem", "Bandage item", "testItem", dressing.GetItemClass());
		EqualInt(dressing.GetZones().Count(), 2, "Shared bandage zones");
		Check(dressing.GetZones()[1] == "LeftHand" && dressing.GetBones()[0] == "leftarm", "Definition insertion order", "LeftHand/leftarm", dressing.GetZones()[1] + "/" + dressing.GetBones()[0]);
		EqualInt(m_Medical.IAT_GetBones().Count(), 29, "All vanilla selections discovered");
		EqualInt(m_Medical.IAT_GetRegisteredBoneMask(), 536870911, "All 29 supported bits");
		EqualInt(m_Medical.IAT_GetDamageZones().Count(), 10, "Ten damage zones");
		EqualInt(m_Medical.IAT_GetBandageSlots().Count(), 6, "Six regional dressings");
		EqualInt(m_Medical.IAT_GetBulletBoneBit("LEFTARM"), 256, "Bone lookup normalizes case");
		EqualInt(m_Medical.IAT_GetBulletBoneBit("not_a_bone"), 0, "Unknown bullet bone");
		EqualInt(m_Medical.IAT_GetDamageZoneBit("not_a_zone"), 0, "Unknown zone bit");
		EqualInt(m_Medical.IAT_GetZoneBoneMask("not_a_zone"), 0, "Unknown zone mask");
		Check(m_Medical.IAT_GetFirstBoneForZone("not_a_zone") == "", "Unknown first bone", "", m_Medical.IAT_GetFirstBoneForZone("not_a_zone"));
		Check(m_Medical.IAT_GetBandageSlot("not_a_zone") == "" && m_Medical.IAT_GetBandageClass("not_a_zone") == "", "Unknown zone has no dressing", "empty", m_Medical.IAT_GetBandageClass("not_a_zone"));
		Check(!m_Medical.IAT_GetBandageZones("not_a_slot") && !m_Medical.IAT_GetBandageBones("not_a_slot"), "Unknown slot returns null coverage", "null", "checked");
		Check(m_Medical.IAT_EM_TestLogBones(0) == "[]", "Empty diagnostic mask", "[]", m_Medical.IAT_EM_TestLogBones(0));
		Check(m_Medical.IAT_EM_TestLogBones(5) == "[head,pelvis]", "Diagnostic names in registration order", "[head,pelvis]", m_Medical.IAT_EM_TestLogBones(5));
		Near(PlayerConstants.BLEEDING_SOURCE_BLOODLOSS_PER_SEC, -13, "Configured global blood loss");
		EqualInt(PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, 25, "Configured bleed duration");
		Near(PlayerConstants.BLEEDING_SOURCE_CLOSE_INFECTION_CHANCE, 0.01, "Configured closure infection chance");
		Near(PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM, 0.47, "Configured medium flow");
		Near(IAT_PluginMedical.IAT_BULLET_EXTRACTION_SECONDS, 10, "Extraction duration");
		return true;
	}
}
#endif
#endif
