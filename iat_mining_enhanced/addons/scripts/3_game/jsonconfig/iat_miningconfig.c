class IAT_MiningConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "MiningConfig.json";


	protected int m_MiningDepthMin;
	protected int m_MiningDepthMax;

	protected ref array<ref IAT_MiningSegmentConfig> m_IAT_MiningSegmentConfigs;

	IAT_MiningConfig TryGetMiningConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_MiningConfig iat_MIConfig = new IAT_MiningConfig();
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// set some default values
			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_MiningConfig>.SaveFile(jsonConfig, iat_MIConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_MiningConfig>.LoadFile(jsonConfig, iat_MIConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_MIConfig;
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	IAT_MiningSegmentConfig GetMiningSegmentById(string id)
	{
		foreach(IAT_MiningSegmentConfig miningSegment : m_IAT_MiningSegmentConfigs)
		{
			if (miningSegment.IsIDMatch(id))
			{
				return miningSegment;
			}
		}
		return null;
	}
	void InsertMiningSegment(IAT_MiningSegmentConfig segment)
	{

	}
	bool RemoveMiningSegment(IAT_MiningSegmentConfig segment)
	{
		return true;
	}
	void UpdateMiningSegment(IAT_MiningSegmentConfig segment)
	{

	}
	array<ref IAT_MiningSegmentConfig> GetMiningSegments()
	{
		return m_IAT_MiningSegmentConfigs;
	}

	void PrettyPrint()
	{
		Print("--[IAT MINING CONFIG BEGIN]");

		Print("--[END]");
	}
};