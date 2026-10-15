// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Presence publication across retained locations, dressing, and final extraction.
#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_EM_BulletPresenceCase : IAT_EM_PlayerCase
{
	void IAT_EM_BulletPresenceCase()
	{
		m_Suite = "Extraction";
		m_Name = "BulletPresenceTracksRemainingLocationsAndIgnoresDressing";
	}

	override bool Execute()
	{
		if (!m_Ready) return true;
		Check(!m_Player.IAT_EM_TestBulletPresence(), "Empty player publishes absent bullet", "false", "checked");
		EntityAI dressing = Dress("LeftArm");
		if (!dressing) return true;
		Check(!m_Player.IAT_HasRetainedBullet() && !m_Player.IAT_EM_TestBulletPresence(), "Dressing alone does not indicate bullet", "false/false", "checked");
		m_Medical.RecordBullet(m_Player, "leftarm");
		Check(m_Player.IAT_EM_TestBulletPresence(), "First retained bullet publishes presence through dressing", "true", "checked");
		m_Medical.RecordBullet(m_Player, "leftarm");
		m_Medical.RecordBullet(m_Player, "leftforearm");
		m_Medical.RecordBullet(m_Player, "rightleg");
		string zone;
		m_Medical.ExtractBullet(m_Player, zone);
		Check(m_Player.IAT_EM_TestBulletPresence(), "Presence remains with second location in same zone", "true", "checked");
		m_Medical.ExtractBullet(m_Player, zone);
		Check(m_Player.IAT_EM_TestBulletPresence(), "Presence remains with bullet in another zone", "true", "checked");
		m_Medical.ExtractBullet(m_Player, zone);
		Check(!m_Player.IAT_HasRetainedBullet() && !m_Player.IAT_EM_TestBulletPresence(), "Final extraction publishes absent bullet", "false/false", "checked");
		m_Medical.RecordBullet(m_Player, "rightleg");
		Check(m_Player.IAT_EM_TestBulletPresence(), "New retained hit republishes presence", "true", "checked");
		return true;
	}
}
#endif
#endif
