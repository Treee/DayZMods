modded class DayZGame
{
	protected ref IAT_FacePaintsConfig m_iatFacePaintConfig;

	void SetIATFacePaintConfig(IAT_FacePaintsConfig config)
	{
		Print("IAT_FacePaintsConfig Settings Initialized");
		// client side only because options are non serialzied so rpc's ignore
		if (!g_Game.IsDedicatedServer())
		{
			// these are dynamically generated and update at will
			IAT_FacePaintOptions fpOptions = new IAT_FacePaintOptions();
			config.SetFacePaintOptions(fpOptions);
		}
		config.PrettyPrint();
		m_iatFacePaintConfig = config;
	}

	IAT_FacePaintsConfig GetIATFacePaintConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_iatFacePaintConfig)
			{
				IAT_FacePaintsConfig tempConfig = new IAT_FacePaintsConfig();
				m_iatFacePaintConfig = tempConfig.TryGetFacePaintConfig();
			}
		}
		return m_iatFacePaintConfig;
	}
};


#ifdef CF_MODSTORAGE
class IAT_FacePaints_Scripts extends ModStructure{};
#endif