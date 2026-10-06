// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Diagnostic-only medical scenario or fixture.
// Integration: optional harness; restores fixture state; preserves engine access.
// Documentation: iat_enhanced_medical/tests/README.md

#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_ExtractionToolTest : IAT_ScenarioCase
{
	Pliers m_Pliers;
	ItemBase m_Bandage;

	void IAT_EM_ExtractionToolTest()
	{
		m_Mod = "IAT_Enhanced_Medical";
		m_Suite = "ExtractionTools";
		m_Name = "PliersOptIntoBulletExtraction";
	}
	override bool Prepare()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (!player)
			return false;
		m_Pliers = Pliers.Cast(g_Game.CreateObjectEx("Pliers", player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Bandage = ItemBase.Cast(g_Game.CreateObjectEx("BandageDressing", player.GetPosition(), ECE_PLACE_ON_SURFACE));
		bool pliersCreated = m_Pliers != null;
		Check(pliersCreated, "Pliers fixture created", "true", pliersCreated.ToString());
		bool bandageCreated = m_Bandage != null;
		Check(bandageCreated, "Bandage fixture created", "true", bandageCreated.ToString());
		return true;
	}
	override bool Execute()
	{
		if (!m_Pliers || !m_Bandage)
			return true;
		Check(m_Pliers.IAT_CanExtractBullet(), "Pliers opts into extraction", "true", m_Pliers.IAT_CanExtractBullet().ToString());
		Check(m_Pliers.IAT_BulletExtractionHpDmg() == 10, "Pliers configures 10 patient Health damage", "10", m_Pliers.IAT_BulletExtractionHpDmg().ToString());
		Check(!m_Bandage.IAT_CanExtractBullet(), "Ordinary item does not opt into extraction", "false", m_Bandage.IAT_CanExtractBullet().ToString());
		Check(m_Bandage.IAT_BulletExtractionHpDmg() == 0, "Ordinary item configures no extraction damage", "0", m_Bandage.IAT_BulletExtractionHpDmg().ToString());
		return true;
	}
	override bool Cleanup()
	{
		if (m_Pliers)
			g_Game.ObjectDelete(m_Pliers);
		if (m_Bandage)
			g_Game.ObjectDelete(m_Bandage);
		m_Pliers = null;
		m_Bandage = null;
		return true;
	}
}
#endif
#endif
