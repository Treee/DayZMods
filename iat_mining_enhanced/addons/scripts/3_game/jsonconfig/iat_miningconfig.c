class IAT_MiningConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "MiningConfig.json";

	protected int m_SkySurfaceY = 2500; // the highest the mining system can be. simulates the surface level
	protected int m_MaxDepth = 100; // the depth of the mining area in meters (default junctions are 4m cubed so 1 level is 4m)
	protected int m_EdgeBuffer = 20; // the buffer around the edge of the map
	protected int m_MinimumDistanceBetweenEntrances = 100; // the minimum distance between entrances so they are not spammed.

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
		vector newPosition = string.Format("%1 %2 %3", surfacePosition[0], m_SkySurfaceY, surfacePosition[2]).ToVector();

		// check if anything occupys this space already
		foreach(IAT_MiningSegmentConfig miningSegment : m_IAT_MiningSegmentConfigs)
		{
			if(vector.Distance(miningSegment.GetSegmentPosition(), newPosition) <= 4)
			{
				PrintFormat("GetExitJunctionSpawnPosition::An existing entrance is here. Do not make a new one. %1", newPosition);
				// TODO: link the existing junction to the entrance
				return vector.Zero;
			}
		}
		return newPosition;
	}

	vector GetNextJunctionSpawnPosition(vector currentJunctionPosition, int doorIndex, int bufferSize = 8)
	{
		vector newPosition = GetOffsetJunctionPosition(currentJunctionPosition, doorIndex, bufferSize);

		foreach(IAT_MiningSegmentConfig miningSegment : m_IAT_MiningSegmentConfigs)
		{
			if(vector.Distance(miningSegment.GetSegmentPosition(), newPosition) <= 1)
			{
				PrintFormat("GetNextJunctionSpawnPosition::An existing entrance is here. Do not make a new one. %1", newPosition);
				return vector.Zero;
			}
		}
		return newPosition;
	}

	// this is used for when inner walls are destroyed by a mining action so the next junction is created
	// segments are 4m cubed so all we need to do is add 4 to each sides
	// up 1 - Component36
	// down 2 - Component34
	// left (west) 3 - Component32
	// right (east) 4 - Component28
	// forward (south) 5 - Component26
	// back (north) 6 - Component30
	vector GetOffsetJunctionPosition(vector currentJunctionPosition, int doorIndex, int bufferSize = 8)
	{
		vector newSegmentPosition = vector.Zero;

		vector up = string.Format("0 %1 0", bufferSize).ToVector();
		vector right = string.Format("%1 0 0", bufferSize).ToVector();
		vector forward = string.Format("0 0 %1", bufferSize).ToVector();

		if (doorIndex == 0) // up
		{
			newSegmentPosition = currentJunctionPosition + up;
		}
		else if (doorIndex == 1) // down
		{
			newSegmentPosition = currentJunctionPosition - up;
		}
		else if (doorIndex == 2) // left
		{
			newSegmentPosition = currentJunctionPosition - right;
		}
		else if (doorIndex == 3) // right
		{
			newSegmentPosition = currentJunctionPosition + right;
		}
		else if (doorIndex == 4) // forward
		{
			newSegmentPosition = currentJunctionPosition - forward;
		}
		else if (doorIndex == 5) // back
		{
			newSegmentPosition = currentJunctionPosition + forward;
		}
		// PrintFormat("=======================================Current Junction: %1 New Junction: %2", currentJunctionPosition, newSegmentPosition);
		return newSegmentPosition;
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
		// TODO
		return false;
	}
	bool CanPlaceEntrance(vector position)
	{
		// check if anything occupys this space already
		foreach(IAT_MiningSegmentConfig miningSegment : m_IAT_MiningSegmentConfigs)
		{
			if (miningSegment.IsEntrance())
			{
				if(vector.Distance(miningSegment.GetSegmentPosition(), position) <= m_MinimumDistanceBetweenEntrances)
				{
					PrintFormat("CanPlaceEntrance::There is an existing entrance with 100m of %1", position);
					return false;
				}
			}
		}
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

	int GetSkySurfaceY()
	{
		return m_SkySurfaceY;
	}
	int GetMaxDepth()
	{
		return m_MaxDepth;
	}
	int GetMinDistanceBetweenEntrances()
	{
		return m_MinimumDistanceBetweenEntrances;
	}
	int GetMapEdgeBuffer()
	{
		return m_EdgeBuffer;
	}

	void PrettyPrint()
	{
		Print("--[IAT MINING CONFIG BEGIN]");

		Print("--[END]");
	}
};