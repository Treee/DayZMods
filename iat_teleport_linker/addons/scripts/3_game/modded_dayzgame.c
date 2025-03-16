modded class DayZGame
{
	protected ref IAT_TeleportLinkConfig m_iatTeleportLinkConfig;

	void SetIATTeleportLinkConfig(IAT_TeleportLinkConfig config)
	{
		m_iatTeleportLinkConfig = config;
	}

	IAT_TeleportLinkConfig GetIATTeleportLinkConfig()
	{
		if (!m_iatTeleportLinkConfig)
		{
			Print("[IAT_Teleport_Linker] No config exist. Create New.");
			IAT_TeleportLinkConfig tempConfig = new IAT_TeleportLinkConfig();
			m_iatTeleportLinkConfig = tempConfig.TryGetTeleportLinkConfig();
		}
		return m_iatTeleportLinkConfig;
	}
};