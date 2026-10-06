// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_AmmoCase : IAT_ScenarioCase
{
	string m_Ammo;
	bool m_Expected;
	void IAT_EM_AmmoCase(string ammo, bool expected)
	{
		m_Mod = "IAT_Enhanced_Medical"; m_Suite = "Ammunition"; m_Name = "Ammo_" + ammo;
		m_Ammo = ammo; m_Expected = expected;
	}
	override bool Execute()
	{
		IAT_PluginMedical medical = new IAT_PluginMedical;
		bool actual = medical.IsBulletAmmo(m_Ammo);
		Check(actual == m_Expected, "Retention follows CfgAmmo ancestry: " + m_Ammo, m_Expected.ToString(), actual.ToString());
		return true;
	}
}
#endif
#endif
