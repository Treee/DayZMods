// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_AmmoClassificationTest : IAT_ScenarioCase
{
	ref IAT_PluginMedical m_Medical;
	void IAT_EM_AmmoClassificationTest()
	{
		m_Mod = "IAT_Enhanced_Medical";
		m_Suite = "Ammunition";
		m_Name = "OnlyFirearmRoundsAreRetained";
	}
	override bool Prepare()
	{
		m_Medical = new IAT_PluginMedical();
		return true;
	}
	void CheckAmmo(string ammo, bool expected)
	{
		bool actual = m_Medical.IsBulletAmmo(ammo);
		Check(actual == expected, "Retained ammunition: " + ammo, expected.ToString(), actual.ToString());
	}
	override bool Execute()
	{
		CheckAmmo("Bullet_Base", true);
		CheckAmmo("Bullet_556x45", true);
		CheckAmmo("IAT_EM_DeepRoundLevel3", true);
		CheckAmmo("Shotgun_Base", true);
		CheckAmmo("Bolt_Base", false);
		CheckAmmo("Bullet_Flare", false);
		CheckAmmo("Bullet_40mm_Base", false);
		CheckAmmo("Bullet_12GaugeRubberSlug", false);
		CheckAmmo("Bullet_12GaugeBeanbag", false);
		CheckAmmo("", false);
		return true;
	}
	override bool Cleanup()
	{
		m_Medical = null;
		return true;
	}
}
#endif
#endif
