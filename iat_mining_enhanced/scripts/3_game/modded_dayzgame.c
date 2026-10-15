modded class DayZGame
{
	protected ref IAT_MiningConfig m_IAT_MiningConfig;

	void SetIATMiningConfig(IAT_MiningConfig config)
	{
		Print("IAT_MiningConfig Settings Initialized");
		config.PrettyPrint();
		m_IAT_MiningConfig = config;
	}

	IAT_MiningConfig GetIATMiningConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_IAT_MiningConfig)
			{
				IAT_MiningConfig tempConfig = new IAT_MiningConfig();
				m_IAT_MiningConfig = tempConfig.TryGetMiningConfig();
			}
		}
		return m_IAT_MiningConfig;
	}
};