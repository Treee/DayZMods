// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_RegenerationCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_RegenerationCase(string caseName, int mode) { m_Suite = "Regeneration"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		BloodRegenMdfr modifier = BloodRegenMdfr.Cast(m_Player.GetModifiersManager().GetModifier(eModifiers.MDF_BLOOD_REGEN));
		Check(modifier != null, "Existing blood regeneration modifier", "true", (modifier != null).ToString());
		if (!modifier) return true;
		Near(m_Medical.IAT_GetZoneBloodScale(m_Player, 100), 0.05, "Default proportional scale");
		Near(m_Medical.IAT_GetZoneBloodScale(m_Player, 200), 0.1, "Scale follows zone maximum");
		Near(m_Medical.IAT_GetZoneBloodScale(m_Player, 0), 0, "Zero zone maximum disables scaling");
		Near(m_Medical.IAT_GetZoneBloodScale(m_Player, -1), 0, "Negative zone maximum disables scaling");
		Blood("Head", 0.75); Blood("LeftArm", 0.25); Blood("RightArm", 0.75);
		m_Medical.RecordBullet(m_Player, "rightarm");
		float before = m_Player.GetHealth("Head", "Blood");
		if (m_Mode == 0)
		{
			m_Medical.IAT_RegenerateZones(m_Player, 2, 0.3);
			Near(m_Player.GetHealth("Head", "Blood"), before + 0.03, "Eligible zone gains 0.015 points per second");
		}
		if (m_Mode == 1)
		{
			m_Player.SetHealth("Head", "Blood", 99.99);
			m_Medical.IAT_RegenerateZones(m_Player, 10, 0.3);
			Near(m_Player.GetHealth("Head", "Blood"), 100, "Regeneration caps at zone maximum");
		}
		if (m_Mode == 2)
		{
			m_Player.SetHealth("", "Blood", 5000);
			Check(modifier.ActivateCondition(m_Player) && !modifier.DeactivateCondition(m_Player), "Full global blood keeps zone recovery tick", "active/not deactivated", "checked");
			m_Medical.IAT_RegenerateZones(m_Player, 2, 0.3);
			Near(m_Player.GetHealth("Head", "Blood"), before + 0.03, "Zones recover with full global blood");
		}
		if (m_Mode == 3)
		{
			m_Player.GetStatWater().Set(5000); m_Player.GetStatEnergy().Set(5000);
			m_Player.SetHealth("", "Blood", 4500);
			float rate = modifier.IAT_EM_TestRate(m_Player);
			Near(rate, 0.3, "Well-fed conscious regeneration rate");
			modifier.OnTick(m_Player, 2);
			Near(m_Player.GetHealth("", "Blood"), 4500.6, "Vanilla global regeneration retained", 0.01);
			Near(m_Player.GetHealth("Head", "Blood"), before + 0.03, "OnTick connects proportional zone recovery");
		}
		Near(m_Player.GetHealth("LeftArm", "Blood"), 25, "Uncovered severe zone cannot regenerate");
		Near(m_Player.GetHealth("RightArm", "Blood"), 75, "Retained bullet zone cannot regenerate");
		return true;
	}
}
#endif
#endif
