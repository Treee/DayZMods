class IAT_TeleportLinkConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "TeleportLinkerConfig.json";

	protected ref array<ref IAT_TeleportLinkData> m_TeleportLinks;

	IAT_TeleportLinkConfig TryGetTeleportLinkConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			PrintFormat("[IAT_Teleport_Linker] Create new directory: %1", rootFilePath);
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		// new config object
		IAT_TeleportLinkConfig iat_TLConfig = new IAT_TeleportLinkConfig();

		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			PrintFormat("[IAT_Teleport_Linker] Create new json file: %1", jsonConfig);
			// set some default values
			m_TeleportLinks = new array<ref IAT_TeleportLinkData>;
			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_TeleportLinkConfig>.SaveFile(jsonConfig, iat_TLConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			PrintFormat("[IAT_Teleport_Linker] Load config from: %1", jsonConfig);
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_TeleportLinkConfig>.LoadFile(jsonConfig, iat_TLConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_TLConfig;
	}

	bool AddNewTeleportAnchor(string teleportClassName, vector teleportPosition)
	{
		foreach(IAT_TeleportLinkData teleportLink : m_TeleportLinks)
		{
			if (teleportLink.TeleportExists(teleportClassName, teleportPosition))
			{
				// found an existing record here, cannot add duplicates
				PrintFormat("[IAT_Teleport_Linker] Unable to Add New Teleport Anchor since it already exists: %1 %2", teleportClassName, teleportPosition);
				return false;
			}
		}
		// we have checked all prior teleports, none exist with this object at this position
		m_TeleportLinks.Insert(new IAT_TeleportLinkData(teleportClassName, teleportPosition));
		PrintFormat("[IAT_Teleport_Linker] Add New Teleport Anchor: %1 %2", teleportClassName, teleportPosition);
		return true;
	}

	bool AddNewTeleportDestination(string teleportClassName, vector teleportPosition, vector teleportDestination)
	{
		foreach(IAT_TeleportLinkData teleportLink : m_TeleportLinks)
		{
			if (teleportLink.TeleportExists(teleportClassName, teleportPosition))
			{
				// found an existing record here, add to the array
				teleportLink.AddDestination(teleportDestination);
				PrintFormat("[IAT_Teleport_Linker] Add New Teleport Destination: %1 From: %2 To: %3", teleportClassName, teleportPosition, teleportDestination);
				return true;
			}
		}
		// we have checked all prior teleports, none exist with this object at this position
		// cant add a destination to a teleporter that doesnt exist
		PrintFormat("[IAT_Teleport_Linker] Unable to Add New Teleport Destination: %1 From: %2 To: %3 since this record does not exists", teleportClassName, teleportPosition, teleportDestination);
		return false;
	}

	bool ClearTeleporterDestinations(string teleportClassName, vector teleportPosition)
	{
		foreach(IAT_TeleportLinkData teleportLink : m_TeleportLinks)
		{
			if (teleportLink.TeleportExists(teleportClassName, teleportPosition))
			{
				// found an existing record here, add to the array
				teleportLink.ClearDestinations();
				PrintFormat("[IAT_Teleport_Linker] Clear Teleport Destinations: %1 %2", teleportClassName, teleportPosition);
				return true;
			}
		}
		// we have checked all prior teleports, none exist with this object at this position
		// cant add a destination to a teleporter that doesnt exist
		PrintFormat("[IAT_Teleport_Linker] Unable to Clear Teleport Destinations: %1 %2 since this record does not exist.", teleportClassName, teleportPosition);
		return false;
	}

	IAT_TeleportLinkData IsValidTeleporter(string teleportClassName, vector teleportPosition)
	{
		foreach(IAT_TeleportLinkData teleportLink : m_TeleportLinks)
		{
			if (teleportLink.TeleportExists(teleportClassName, teleportPosition))
			{
				return teleportLink;
			}
		}
		return null;
	}

	void SaveConfig()
	{
		string errorMessage;
		// non serialized values are empty here because a loaded config isnt a 'new config'
		string rootFilePath = string.Format("%1\\%2\\%3", m_DayZFolder, m_RootConfigFolder, m_JsonFile);
		if (!JsonFileLoader<IAT_TeleportLinkConfig>.SaveFile(rootFilePath, this, errorMessage))
			ErrorEx(errorMessage);
		PrintFormat("[IAT_Teleport_Linker] Config Saved: %1", rootFilePath);
	}


	// ==================================================================================
	// Getters & Setters
	// ==================================================================================

	array<ref IAT_TeleportLinkData> GetTeleportLinkData()
	{
		return m_TeleportLinks;
	}
};