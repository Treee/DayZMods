modded class DayZGame
{
	protected ref IAT_ItemBlacklistConfig m_iatItemBlacklistConfig;

	void SetIATItemBlacklistConfig(IAT_ItemBlacklistConfig config)
	{
		Print("IAT_ItemBlacklist Settings Initialized On Server");
		config.PrettyPrint();
		m_iatItemBlacklistConfig = config;
	}

	IAT_ItemBlacklistConfig GetIATItemBlacklistConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_iatItemBlacklistConfig)
			{
				IAT_ItemBlacklistConfig tempConfig = new IAT_ItemBlacklistConfig();
				m_iatItemBlacklistConfig = tempConfig.TryGetItemBlacklistConfig();
			}
		}
		return m_iatItemBlacklistConfig;
	}
};