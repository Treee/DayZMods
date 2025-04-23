modded class DayZGame
{
	protected ref IAT_PoweredRadioTowerConfig m_iatDynamicRadioConfig;

	void SetIATPoweredRadioTowerConfig(IAT_PoweredRadioTowerConfig config)
	{
		Print("IAT_PoweredRadioTowerConfig Settings Initialized");
		config.PrettyPrint();
		m_iatDynamicRadioConfig = config;
	}

	IAT_PoweredRadioTowerConfig GetIATPoweredRadioTowerConfig()
	{
		if (!m_iatDynamicRadioConfig)
		{
			IAT_PoweredRadioTowerConfig tempConfig = new IAT_PoweredRadioTowerConfig();
			m_iatDynamicRadioConfig = tempConfig.TryGetPoweredRadioTowerConfig();
		}
		return m_iatDynamicRadioConfig;
	}
};