modded class DayZGame
{
	protected ref IAT_SmeltingConfig m_iatSmeltingConfig;

	void SetIATSmeltingConfig(IAT_SmeltingConfig config)
	{
		Print("IAT_Smelting Settings Initialized On Server");
		config.PrettyPrint();
		m_iatSmeltingConfig = config;
	}

	IAT_SmeltingConfig GetIATSmeltingConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_iatSmeltingConfig)
			{
				IAT_SmeltingConfig tempConfig = new IAT_SmeltingConfig();
				m_iatSmeltingConfig = tempConfig.TryGetSmeltingConfig();
			}
		}
		return m_iatSmeltingConfig;
	}
};