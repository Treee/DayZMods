modded class DayZGame
{
	protected ref IAT_TentManager m_IAT_TentManager;

	void IAT_SetTentManager(IAT_TentManager config)
	{
		m_IAT_TentManager = config;
	}

	IAT_TentManager IAT_GetTentManager()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_IAT_TentManager)
			{
				m_IAT_TentManager = new IAT_TentManager();
			}
		}
		return m_IAT_TentManager;
	}
};