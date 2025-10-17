modded class DayZGame
{
	protected ref IAT_RollTableConfig m_iatRollTableConfig;

	void SetIATRollTableConfig(IAT_RollTableConfig config)
	{
		Print("IAT_RollTable Settings Initialized On Server");
		config.PrettyPrint();
		m_iatRollTableConfig = config;
	}

	IAT_RollTableConfig GetIATRollTableConfig()
	{
		// server side check so we do not create a config on the client
		if (GetGame().IsDedicatedServer())
		{
			if (!m_iatRollTableConfig)
			{
				IAT_RollTableConfig tempConfig = new IAT_RollTableConfig();
				m_iatRollTableConfig = tempConfig.TryGetRollTableConfig();
			}
		}
		return m_iatRollTableConfig;
	}
};