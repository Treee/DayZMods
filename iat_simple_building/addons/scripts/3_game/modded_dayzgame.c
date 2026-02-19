modded class DayZGame
{
	protected ref IAT_SimpleBuildingConfig m_iatSimpleBuildingConfig;

	void SetIATSimpleBuildingConfig(IAT_SimpleBuildingConfig config)
	{
		Print("IAT_SimpleBuilding Settings Initialized On Server");
		config.PrettyPrint();
		m_iatSimpleBuildingConfig = config;
	}

	IAT_SimpleBuildingConfig GetIATSimpleBuildingConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_iatSimpleBuildingConfig)
			{
				IAT_SimpleBuildingConfig tempConfig = new IAT_SimpleBuildingConfig();
				m_iatSimpleBuildingConfig = tempConfig.TryGetSimpleBuildingConfig();
			}
		}
		return m_iatSimpleBuildingConfig;
	}
};