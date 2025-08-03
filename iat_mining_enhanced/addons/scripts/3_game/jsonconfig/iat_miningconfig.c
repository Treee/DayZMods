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
	void CreateSegmentEntranceNode(string id, vector segmentPosition, vector teleportPosition, int maxNumHits = -1)
	{
		bool isEntrance = true; // no magic numbers
		InsertMinintSegment(new IAT_MiningSegmentConfig(id, isEntrance, !isEntrance, maxNumHits, segmentPosition, teleportPosition));
	}
	void CreateSegmentJunctionNode(string id, vector segmentPosition, vector teleportPosition, int maxNumHits = -1, bool isExit = false)
	{
		bool isEntrance = false; // no magic numbers
		InsertMinintSegment(new IAT_MiningSegmentConfig(id, isEntrance, isExit, maxNumHits, segmentPosition, teleportPosition));
	}
	void IncrementSegmentComponentHitCounter(string id, string componentName)
	{
		// enforce lowercase
		componentName.ToLower();

		IAT_MiningSegmentConfig segmentConfig;
		if (Class.CastTo(segmentConfig, GetMiningSegmentById(id)))
		{
			segmentConfig.IncrementSegmentComponentHitCounter(componentName);
		}
	}
	void GetSegmentTeleportDestination(string id)
	{
		IAT_MiningSegmentConfig segmentConfig;
		if (Class.CastTo(segmentConfig, GetMiningSegmentById(id)))
		{
			segmentConfig.GetSegmentTeleportDestination();
		}
	}

	bool CanMineSegmentComponent(string id, string componentName)
	{
		// enforce lowercase
		componentName.ToLower();

		IAT_MiningSegmentConfig segmentConfig;
		if (Class.CastTo(segmentConfig, GetMiningSegmentById(id)))
		{
			if (segmentConfig.CanMineSegmentComponent(componentName))
			{
				return true;
			}
		}
		// if none of the components can be mined or the config doesnt exist. return false
		return false;
	}
	bool IsSegmentEntrance(string id)
	{
		IAT_MiningSegmentConfig segmentConfig;
		if (Class.CastTo(segmentConfig, GetMiningSegmentById(id)))
		{
			return segmentConfig.IsEntrance();
		}
		return false;
	}
	bool IsSegmentExit(string id)
	{
		IAT_MiningSegmentConfig segmentConfig;
		if (Class.CastTo(segmentConfig, GetMiningSegmentById(id)))
		{
			return segmentConfig.IsExit();
		}
		return false;
	}




	void InsertMiningSegment(IAT_MiningSegmentConfig segment)
	{
		// initialize the array if it doesnt exist. this should only really happen when no entrances exist
		if (!m_IAT_MiningSegmentConfigs)
			m_IAT_MiningSegmentConfigs = new array<ref IAT_MiningSegmentConfig>();

		m_IAT_MiningSegmentConfigs.Insert(segment);
	}
	bool RemoveMiningSegment(IAT_MiningSegmentConfig segment)
	{
		return true;
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