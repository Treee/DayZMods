modded class UndergroundHandlerClient
{
	// used by the mining system to force underground state without breadcrumbs
	void IAT_EnterUndergroundMines()
	{
		OnUndergroundPresenceUpdate(EUndergroundPresence.FULL, EUndergroundPresence.NONE);
		m_Player.SetUnderground(EUndergroundPresence.FULL);
	}

	void IAT_ExitUndergroundMines()
	{
		OnUndergroundPresenceUpdate(EUndergroundPresence.NONE, EUndergroundPresence.FULL);
		m_Player.SetUnderground(EUndergroundPresence.NONE);
	}
};