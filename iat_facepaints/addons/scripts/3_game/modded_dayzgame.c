modded class DayZGame
{
	protected ref IAT_FacePaintsConfig m_iatFacePaintConfig;

	void SetIATFacePaintConfig(IAT_FacePaintsConfig config)
	{
		Print("IAT_FacePaintsConfig Settings Received From Server");
		m_iatFacePaintConfig = config;
	}

	IAT_FacePaintsConfig GetIATFacePaintConfig()
	{
		if (!m_iatFacePaintConfig)
		{
			IAT_FacePaintsConfig tempConfig = new IAT_FacePaintsConfig();
			m_iatFacePaintConfig = tempConfig.TryGetFacePaintConfig();
		}
		return m_iatFacePaintConfig;
	}
};
