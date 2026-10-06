// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_BleedingCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_BleedingCase(string caseName, int mode) { m_Suite = "Bleeding"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		int bit = m_Medical.IAT_GetBulletBoneBit("leftarm");
		m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
		BleedingSource source = m_Manager.m_BleedingSources.Get(bit);
		Check(source != null, "Real bleeding source created", "true", (source != null).ToString());
		if (!source) return true;
		Check(m_Manager.IAT_GetDamageZoneFromMostSignificantSource() == "LeftArm", "Most significant source zone", "LeftArm", m_Manager.IAT_GetDamageZoneFromMostSignificantSource());
		Check(m_Manager.IAT_GetDamageZoneFromSourceBit(0) == "", "Absent source bit has no zone", "", m_Manager.IAT_GetDamageZoneFromSourceBit(0));
		if (m_Mode <= 2)
		{
			Blood("LeftArm", 0.75); m_Player.SetHealth("", "Blood", 4500);
			if (m_Mode == 2) source.SetType(eBleedingSourceType.CONTAMINATED);
			float zoneBefore = m_Player.GetHealth("LeftArm", "Blood");
			source.OnUpdateServer(2, 0.5, m_Mode == 1);
			float expectedZone = zoneBefore - 0.3055;
			float expectedGlobal = 4500 - 6.11;
			if (m_Mode == 1) { expectedZone = zoneBefore; expectedGlobal = 4500; }
			if (m_Mode == 2)
			{
				expectedZone = zoneBefore - 0.3055 * PlayerConstants.BLEEDING_SOURCE_BURN_MODIFIER;
				expectedGlobal = 4500 - 6.11 * PlayerConstants.BLEEDING_SOURCE_BURN_MODIFIER;
			}
			Near(m_Player.GetHealth("LeftArm", "Blood"), expectedZone, "Proportional zone loss respects pressure, time, flow, and type");
			Near(m_Player.GetHealth("", "Blood"), expectedGlobal, "Vanilla global blood loss preserved", 0.01);
			return true;
		}
		if (m_Mode == 3 || m_Mode == 4)
		{
			float fraction = 0.499;
			if (m_Mode == 4) fraction = 0.5;
			Blood("LeftArm", fraction);
			m_Manager.RequestDeletion(bit);
			int expectedCount = 0;
			if (m_Mode == 4) expectedCount = 1;
			EqualInt(m_Manager.m_DeleteList.Count(), expectedCount, "Natural expiry strict half-blood boundary");
			return true;
		}
		if (m_Mode == 5)
		{
			Blood("LeftArm", 0.25);
			source.OnUpdateServer(26, 1, true);
			Check(!source.m_DeleteRequested, "Rejected severe expiry resets deletion flag for retry", "false", source.m_DeleteRequested.ToString());
			EqualInt(m_Manager.m_DeleteList.Count(), 0, "Severe source not queued");
			Blood("LeftArm", 0.5);
			source.OnUpdateServer(1, 1, true);
			Check(source.m_DeleteRequested, "Recovered source retries natural expiry", "true", source.m_DeleteRequested.ToString());
			EqualInt(m_Manager.m_DeleteList.Count(), 1, "Recovered source queued");
			m_Manager.OnTick(0);
			EqualInt(m_Player.GetBleedingBits(), 0, "Natural expiry removes source");
			EqualInt(m_State.m_DressedWounds, 0, "Natural expiry does not create treated history");
			return true;
		}
		if (m_Mode == 6)
		{
			ItemBase material = Item("BandageDressing");
			if (!material || !Dress("LeftArm")) return true;
			Blood("LeftArm", 0.75);
			m_Manager.RequestDeletion(bit);
			m_Manager.RemoveMostSignificantBleedingSourceEx(material);
			EqualInt(m_Manager.m_DeleteList.Count(), 0, "Treatment cancels queued natural expiry");
			m_Manager.AttemptAddBleedingSourceBySelection("leftarm");
			m_Manager.OnTick(0);
			Check((m_Player.GetBleedingBits() & bit) != 0, "Old expiry cannot remove reopened source", "nonzero arm bit", m_Player.GetBleedingBits().ToString());
			return true;
		}
		if (m_Mode == 7)
		{
			m_Manager.RemoveAllSources();
			Blood("LeftArm", 0.75);
			m_State.m_DressedWounds = bit;
			m_Manager.IAT_EM_TestResetClock();
			m_Manager.OnTick(2.9);
			EqualInt(m_Player.GetBleedingBits(), 0, "Healing reconciliation waits for tick interval");
			m_Manager.OnTick(0.1);
			Check((m_Player.GetBleedingBits() & bit) != 0, "Tick reopens missing dressing without preexisting bleed", "nonzero arm bit", m_Player.GetBleedingBits().ToString());
		}
		return true;
	}
}
#endif
#endif
