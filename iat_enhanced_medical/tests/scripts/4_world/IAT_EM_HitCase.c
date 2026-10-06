// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_HitCase : IAT_EM_PlayerCase
{
	int m_Mode;
	void IAT_EM_HitCase(string caseName, int mode) { m_Suite = "Hits"; m_Name = caseName; m_Mode = mode; }
	override bool Execute()
	{
		if (!m_Ready) return true;
		int component = -1;
		int expected = m_Medical.IAT_GetBulletBoneBit("leftshoulder");
		string ammo = "Bullet_556x45";
		float damage = 1;
		string zone = "LeftArm";
		if (m_Mode == 0) damage = 0;
		if (m_Mode == 1) damage = -1;
		if (m_Mode == 2) ammo = "Bullet_12GaugeRubberSlug";
		if (m_Mode == 4)
		{
			// Use model-provided fire components rather than faking the lookup.
			TIntArray components = {};
			m_Player.GetActionComponentsForSelectionName(m_Player.GetFireGeometryLevel(), "leftarm", components);
			Check(components.Count() > 0, "Model exposes registered left-arm fire component", "nonempty", components.Count().ToString());
			if (components.Count() == 0) return true;
			component = components[0];
			expected = m_Medical.IAT_GetBulletBoneBit("leftarm");
		}
		if (m_Mode == 5) { zone = ""; expected = 0; }
		if (m_Mode <= 2) expected = 0;
		m_Manager.ProcessHit(damage, null, component, zone, ammo, "0 0 0");
		EqualInt(m_State.m_Bullets, expected, "Only positive qualifying hits retain a bullet in resolved anatomy");
		if (m_Mode == 3 || m_Mode == 4)
		{
			m_Manager.ProcessHit(damage, null, component, zone, ammo, "0 0 0");
			EqualInt(m_State.m_Bullets, expected, "Repeated qualifying hit keeps one location bit");
		}
		// No assertion on vanilla's random bleeding roll: retention is independent.
		return true;
	}
}
#endif
#endif
