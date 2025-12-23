class IAT_SmokeSignalsConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "SmokeSignalsConfig.json";

	IAT_SmokeSignalsConfig TryGetSmokeSignalsConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_SmokeSignalsConfig iat_RTConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_RTConfig = new IAT_SmokeSignalsConfig();
			// set some default values


			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_SmokeSignalsConfig>.SaveFile(jsonConfig, iat_RTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_SmokeSignalsConfig>.LoadFile(jsonConfig, iat_RTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_RTConfig;
	}

	// ================================================================================== HELPERS
	void PrettyPrint()
	{
		Print("--[IAT_SmokeSignalsConfig BEGIN]");

		Print("--[IAT_SmokeSignalsConfig END]");
	}
};