class IAT_ItemBlacklistConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "ItemBlacklistConfig.json";

	protected ref TStringArray m_BlacklistedItems;

	IAT_ItemBlacklistConfig TryGetItemBlacklistConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_ItemBlacklistConfig iat_BIConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_BIConfig = new IAT_ItemBlacklistConfig();
			// set some default values
			iat_BIConfig.m_BlacklistedItems = {};

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_ItemBlacklistConfig>.SaveFile(jsonConfig, iat_BIConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_ItemBlacklistConfig>.LoadFile(jsonConfig, iat_BIConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_BIConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	bool IsItemBlacklisted(string itemClassName)
	{
		// foreach blacklisted item
		foreach(string s1 : m_BlacklistedItems)
		{
			if (s1 == itemClassName)
			{
				return true;
			}
		}
		return false;
	}
	// ================================================================================== HELPERS
	void PrettyPrint()
	{
		Print("--[IAT_ItemBlacklistConfig BEGIN]");
		foreach(string s1 : m_BlacklistedItems)
		{
			PrintFormat("---- Blacklisted Item: %1", s1);
		}
		Print("--[IAT_ItemBlacklistConfig END]");
	}
};