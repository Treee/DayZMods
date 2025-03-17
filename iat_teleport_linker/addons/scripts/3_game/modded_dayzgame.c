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

	void IAT_AddNewTeleportAnchor(string objectName, vector objectPosition)
	{
		m_iatTeleportLinkConfig.AddNewTeleportAnchor(objectName, objectPosition);
	}

	void IAT_AddNewTeleportDestination(string objectName, vector objectPosition, vector objectDestination)
	{
		m_iatTeleportLinkConfig.AddNewTeleportDestination(objectName, objectPosition, objectDestination);
	}

	void IAT_ClearTeleporterDestinations(string objectName, vector objectPosition)
	{
		m_iatTeleportLinkConfig.ClearTeleporterDestinations(objectName, objectPosition);
	}

	IAT_TeleportLinkData IAT_IsValidTeleporter(string objectName, vector objectPosition)
	{
		return m_iatTeleportLinkConfig.IsValidTeleporter(objectName, objectPosition);
	}
};