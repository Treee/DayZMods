modded class DayZGame
{
	protected ref IAT_TreasureHuntConfig m_IAT_TreasureHuntConfig;

	void SetIATTreasureHuntConfig(IAT_TreasureHuntConfig config)
	{
		Print("IAT_TreasureHunt Settings Initialized On Server");
		config.PrettyPrint();
		m_IAT_TreasureHuntConfig = config;
	}

	IAT_TreasureHuntConfig GetIATTreasureHuntConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_IAT_TreasureHuntConfig)
			{
				IAT_TreasureHuntConfig tempConfig = new IAT_TreasureHuntConfig();
				m_IAT_TreasureHuntConfig = tempConfig.TryGetTreasureHuntConfig();
			}
		}
		return m_IAT_TreasureHuntConfig;
	}
};