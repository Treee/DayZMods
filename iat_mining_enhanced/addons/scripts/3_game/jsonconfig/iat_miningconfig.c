class IAT_MiningConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "MiningConfig.json";

	protected int m_MiningDepthMin = 200; // top of the mining area (since we are up in the air this is larger than max)
	protected int m_MiningDepthMax = 100; // bottom of the mining area

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
			iat_MIConfig.SetMiningSegments(new array<ref IAT_MiningSegmentConfig>());
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
	void SaveConfig()
	{
		string errorMessage;
		// non serialized values are empty here because a loaded config isnt a 'new config'
		string rootFilePath = string.Format("%1\\%2\\%3", m_DayZFolder, m_RootConfigFolder, m_JsonFile);
		if (!JsonFileLoader<IAT_MiningConfig>.SaveFile(rootFilePath, this, errorMessage))
			ErrorEx(errorMessage);
		PrintFormat("[IAT_Enhanced_Mining] Config Saved: %1", rootFilePath);
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
	string CreateSegmentEntranceNode(vector segmentPosition, vector teleportPosition)
	{
		bool isEntrance = true; // no magic numbers
		// unique id for this object
		int uuid[4];
		UUIDApi.Generate(uuid);
		string id = UUIDApi.FormatString(uuid);

		InsertMiningSegment(new IAT_MiningSegmentConfig(id, isEntrance, !isEntrance, segmentPosition, teleportPosition));
		return id;
	}
	string CreateSegmentJunctionNode(vector segmentPosition, vector teleportPosition, bool isExit = false)
	{
		bool isEntrance = false; // no magic numbers
		// unique id for this object
		int uuid[4];
		UUIDApi.Generate(uuid);
		string id = UUIDApi.FormatString(uuid);
		IAT_MiningSegmentConfig junctionConfig = new IAT_MiningSegmentConfig(id, isEntrance, isExit, segmentPosition, teleportPosition);
		// defaults (find a better way?)

		junctionConfig.SetMineableComponentOreChances({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});

		InsertMiningSegment(junctionConfig);
		return id;
	}

	vector GetSegmentTeleportDestination(string id)
	{
		IAT_MiningSegmentConfig segmentConfig;
		if (Class.CastTo(segmentConfig, GetMiningSegmentById(id)))
		{
			return segmentConfig.GetSegmentTeleportDestination();
		}
		return vector.Zero;
	}
	vector GetExitJunctionSpawnPosition(vector surfacePosition)
	{
		string junctionTargetPosition = string.Format("0 %1 0", m_MiningDepthMin);
		vector newPosition = surfacePosition + junctionTargetPosition.ToVector();

		// check if anything occupys this space already
		foreach(IAT_MiningSegmentConfig miningSegment : m_IAT_MiningSegmentConfigs)
		{
			if(vector.Distance(miningSegment.GetSegmentPosition(), newPosition) <= 1)
			{
				Print("an existing junction is here. dont make a new one")
				return vector.Zero;
			}
		}
		PrintFormat("new position: %1", newPosition);
		return newPosition;
	}

	bool IsExistingSegmentPresent(vector position)
	{
		// TODO
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
	void SetMiningSegments(array<ref IAT_MiningSegmentConfig> segments)
	{
		m_IAT_MiningSegmentConfigs = segments;
	}


	void PrettyPrint()
	{
		Print("--[IAT MINING CONFIG BEGIN]");

		Print("--[END]");
	}
};