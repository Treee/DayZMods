modded class DayZGame
{
	protected ref IAT_DynamicTrapsConfig m_iatDynamicTrapsConfig;

	void SetIATDynamicTrapsConfig(IAT_DynamicTrapsConfig config)
	{
		Print("IAT_DynamicTrapsConfig Settings Initialized On Server");
		config.PrettyPrint();
		m_iatDynamicTrapsConfig = config;
	}

	IAT_DynamicTrapsConfig GetIATDynamicTrapsConfig()
	{
		if (!m_iatDynamicTrapsConfig)
		{
			IAT_DynamicTrapsConfig tempConfig = new IAT_DynamicTrapsConfig();
			m_iatDynamicTrapsConfig = tempConfig.TryGetDynamicTrapsConfig();
		}
		return m_iatDynamicTrapsConfig;
	}
};