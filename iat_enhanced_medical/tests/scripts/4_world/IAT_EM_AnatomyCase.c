// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_AnatomyCase : IAT_EM_PlayerCase
{
	string m_Bone;
	string m_Zone;
	int m_Index;
	string m_Slot;
	void IAT_EM_AnatomyCase(string bone, string zone, int index, string slot)
	{
		m_Suite = "Definitions";
		m_Name = "Anatomy_" + bone;
		m_Bone = bone;
		m_Zone = zone;
		m_Index = index;
		m_Slot = slot;
	}
	override bool Execute()
	{
		if (!m_Ready) return true;
		int expectedBit = 1 << m_Index;
		EqualInt(m_Medical.IAT_GetBulletBoneBit(m_Bone), expectedBit, "Stable vanilla selection bit");
		Check(m_Medical.IAT_MapBoneNameToDamageZone(m_Bone) == m_Zone, "Selection resolves to anatomy", m_Zone, m_Medical.IAT_MapBoneNameToDamageZone(m_Bone));
		Check(m_Medical.IAT_EM_TestResolve(m_Player, m_Bone) == m_Zone, "Anatomy resolver", m_Zone, m_Medical.IAT_EM_TestResolve(m_Player, m_Bone));
		Check(m_Medical.IAT_GetBandageSlot(m_Zone) == m_Slot, "Regional dressing slot", m_Slot, m_Medical.IAT_GetBandageSlot(m_Zone));
		Check((m_Medical.IAT_GetZoneBoneMask(m_Zone) & expectedBit) != 0, "Zone mask contains bone", "true", (m_Medical.IAT_GetZoneBoneMask(m_Zone) & expectedBit).ToString());
		Check(m_Medical.IAT_GetBandageBones(m_Slot).Find(m_Bone) >= 0, "Dressing covers bone", "true", m_Medical.IAT_GetBandageBones(m_Slot).Find(m_Bone).ToString());
		int count = m_Medical.IAT_GetBones().Count();
		m_Medical.IAT_RegisterBleedingSelection(m_Player, m_Bone, expectedBit);
		EqualInt(m_Medical.IAT_GetBones().Count(), count, "Additional player registration deduplicated");
		// A hit in this bone blocks only its zone; repeat hits do not accumulate.
		m_Medical.RecordBullet(m_Player, m_Bone);
		m_Medical.RecordBullet(m_Player, m_Bone);
		EqualInt(m_State.m_Bullets, expectedBit, "Repeated hit retains one bit per bone");
		map<string, ref IAT_MedicalZoneDefinition> zones = m_Medical.IAT_GetDamageZones();
		foreach (string zone, IAT_MedicalZoneDefinition definition : zones)
		{
			bool expected = zone == m_Zone;
			bool actual = m_Medical.HasBulletInZone(m_Player, zone);
			Check(actual == expected, "Bullet locality " + zone, expected.ToString(), actual.ToString());
		}
		return true;
	}
}
#endif
#endif
