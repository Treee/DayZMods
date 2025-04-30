modded class DayZGame
{
	protected ref IAT_PoweredRadioTowerConfig m_iatPoweredRadioTowerConfig;

	void SetIATPoweredRadioTowerConfig(IAT_PoweredRadioTowerConfig config)
	{
		Print("IAT_PoweredRadioTowerConfig Settings Initialized");
		config.PrettyPrint();
		m_iatPoweredRadioTowerConfig = config;
	}

	IAT_PoweredRadioTowerConfig GetIATPoweredRadioTowerConfig()
	{
		if (!m_iatPoweredRadioTowerConfig)
		{
			IAT_PoweredRadioTowerConfig tempConfig = new IAT_PoweredRadioTowerConfig();
			m_iatPoweredRadioTowerConfig = tempConfig.TryGetPoweredRadioTowerConfig();
		}
		return m_iatPoweredRadioTowerConfig;
	}
};