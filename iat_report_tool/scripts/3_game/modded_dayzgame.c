modded class DayZGame
{
	protected ref IAT_ReportToolConfig m_IAT_ReportToolConfig;

	void SetIATReportToolConfig(IAT_ReportToolConfig config)
	{
		Print("IAT_ReportToolConfig Settings Initialized");
		// config.PrettyPrint();
		m_IAT_ReportToolConfig = config;
	}

	IAT_ReportToolConfig GetIATReportToolConfig()
	{
		if (!m_IAT_ReportToolConfig)
		{
			IAT_ReportToolConfig tempConfig = new IAT_ReportToolConfig();
			m_IAT_ReportToolConfig = tempConfig.TryGetReportToolConfig();
		}
		return m_IAT_ReportToolConfig;
	}
};