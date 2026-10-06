// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! R-004: retained areas lose Blood even through a dressing.
// Integration: diagnostic engine fixture; restores player state.
// Documentation: iat_enhanced_medical/tests/VERIFICATION.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_RetainedBleedingCase : IAT_EM_PlayerCase
{
	protected int m_Mode;

	void IAT_EM_RetainedBleedingCase(string caseName, int mode)
	{
		m_Suite = "RetainedBleeding";
		m_Name = caseName;
		m_Mode = mode;
	}

	override bool Execute()
	{
		if (!m_Ready) return true;
		if (!Dress("LeftArm")) return true;
		Blood("LeftArm", 0.8);
		Blood("RightLeg", 0.8);
		m_Player.SetHealth("", "Blood", 5000);
		m_State.m_DressedWounds = m_Medical.IAT_GetBulletBoneBit("leftarm");
		if (m_Mode != 0) m_Medical.RecordBullet(m_Player, "leftarm");
		if (m_Mode == 2) m_Medical.RecordBullet(m_Player, "leftforearm");
		if (m_Mode == 3) m_Medical.RecordBullet(m_Player, "rightleg");

		m_Manager.OnTick(9.9);
		Near(m_Player.GetHealth("", "Blood"), 5000, "No retained loss before ten-second interval");
		m_Manager.OnTick(0.1);
		float expectedBlood = 4990;
		float expectedArm = 79.5;
		float expectedLeg = 80;
		if (m_Mode == 0) { expectedBlood = 5000; expectedArm = 80; }
		if (m_Mode == 3) { expectedBlood = 4980; expectedLeg = 79.5; }
		Near(m_Player.GetHealth("", "Blood"), expectedBlood, "Ten mL per retained zone, independent of bone count", 0.01);
		Near(m_Player.GetHealth("LeftArm", "Blood"), expectedArm, "Retained region loses proportionate Blood through bandage");
		Near(m_Player.GetHealth("RightLeg", "Blood"), expectedLeg, "Other regions lose Blood only when retaining a bullet");
		EqualInt(m_Player.GetBleedingBits(), 0, "Slow loss does not reopen bandaged sources");

		if (m_Mode == 4)
		{
			m_Manager.OnTick(25);
			Near(m_Player.GetHealth("", "Blood"), 4970, "Delayed tick applies two complete intervals", 0.01);
			m_Manager.OnTick(5);
			Near(m_Player.GetHealth("", "Blood"), 4960, "Interval remainder is preserved", 0.01);
			string zone;
			Check(m_Medical.ExtractBullet(m_Player, zone), "Extract retained bullet", "true", "checked");
			// Isolate retained loss from the separately tested new extraction bleed.
			m_Manager.RemoveAllSources();
			m_Manager.OnTick(10);
			Near(m_Player.GetHealth("", "Blood"), 4960, "Extraction ends retained-bullet loss", 0.01);
		}
		return true;
	}
}
#endif
#endif
