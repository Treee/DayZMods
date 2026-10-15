modded class DayZGame
{
	protected ref IAT_CodelockConfig m_iatCodelockConfig;

	void SetIATCodelockConfig(IAT_CodelockConfig config)
	{
		Print("IAT_Codelock Settings Initialized On Server");
		config.PrettyPrint();
		m_iatCodelockConfig = config;
	}

	IAT_CodelockConfig GetIATCodelockConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_iatCodelockConfig)
			{
				IAT_CodelockConfig tempConfig = new IAT_CodelockConfig();
				m_iatCodelockConfig = tempConfig.TryGetCodelockConfig();
			}
		}
		return m_iatCodelockConfig;
	}
};