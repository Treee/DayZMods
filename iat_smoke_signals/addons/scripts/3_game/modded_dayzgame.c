modded class DayZGame
{
	protected ref IAT_SmokeSignalsConfig m_iatSmokeSignalsConfig;

	void SetIATSmokeSignalsConfig(IAT_SmokeSignalsConfig config)
	{
		Print("IAT_SmokeSignals Settings Initialized On Server");
		config.PrettyPrint();
		m_iatSmokeSignalsConfig = config;
	}

	IAT_SmokeSignalsConfig GetIATSmokeSignalsConfig()
	{
		// server side check so we do not create a config on the client
		if (GetGame().IsDedicatedServer())
		{
			if (!m_iatSmokeSignalsConfig)
			{
				IAT_SmokeSignalsConfig tempConfig = new IAT_SmokeSignalsConfig();
				m_iatSmokeSignalsConfig = tempConfig.TryGetSmokeSignalsConfig();
			}
		}
		return m_iatSmokeSignalsConfig;
	}
};