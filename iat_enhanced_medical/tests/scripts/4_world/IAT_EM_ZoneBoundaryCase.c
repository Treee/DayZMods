// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_ZoneBoundaryCase : IAT_EM_PlayerCase
{
	string m_Zone;
	float m_Fraction;
	bool m_Dressing;
	bool m_Bullet;
	bool m_Expected;
	void IAT_EM_ZoneBoundaryCase(string zone, float fraction, bool dressing, bool bullet, bool expected)
	{
		m_Suite = "RegenerationEligibility";
		m_Name = "Regen_" + zone + "_" + fraction.ToString() + "_dressing_" + dressing.ToString() + "_bullet_" + bullet.ToString();
		m_Zone = zone; m_Fraction = fraction; m_Dressing = dressing; m_Bullet = bullet; m_Expected = expected;
	}
	override bool Execute()
	{
		if (!m_Ready) return true;
		Blood(m_Zone, m_Fraction);
		if (m_Dressing && !Dress(m_Zone)) return true;
		if (m_Bullet) m_Medical.RecordBullet(m_Player, m_Medical.IAT_GetFirstBoneForZone(m_Zone));
		bool severe = m_Medical.IsSevere(m_Player, m_Zone);
		Check(severe == (m_Fraction < 0.5), "Strict below-half severity boundary", (m_Fraction < 0.5).ToString(), severe.ToString());
		bool actual = m_Medical.CanRegenerateZone(m_Player, m_Zone);
		Check(actual == m_Expected, "Zone regeneration eligibility", m_Expected.ToString(), actual.ToString());
		bool needs = m_Medical.NeedsZoneRegen(m_Player);
		bool expectedNeeds = m_Expected && m_Fraction < 1;
		Check(needs == expectedNeeds, "Only eligible incomplete zones request regeneration", expectedNeeds.ToString(), needs.ToString());
		bool healed = m_Medical.IsZoneHealed(m_Player, m_Zone);
		bool expectedHealed = m_Fraction == 1 && !m_Bullet;
		Check(healed == expectedHealed, "Full zone with bullet is not healed", expectedHealed.ToString(), healed.ToString());
		return true;
	}
}
#endif
#endif
