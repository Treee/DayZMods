modded class DayZGame
{
	protected ref IAT_DynamicRadioConfig m_iatDynamicRadioConfig;

	void SetIATDynamicRadioConfig(IAT_DynamicRadioConfig config)
	{
		Print("IAT_DynamicRadioConfig Settings Initialized On Server");
		config.PrettyPrint();
		m_iatDynamicRadioConfig = config;
	}

	IAT_DynamicRadioConfig GetIATDynamicRadioConfig()
	{
		if (!m_iatDynamicRadioConfig)
		{
			IAT_DynamicRadioConfig tempConfig = new IAT_DynamicRadioConfig();
			m_iatDynamicRadioConfig = tempConfig.TryGetDynamicRadioConfig();
		}
		return m_iatDynamicRadioConfig;
	}
};