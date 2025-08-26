class IAT_MiningConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "MiningConfig.json";

	protected int m_SkySurfaceY = 2500; // the highest the mining system can be. simulates the surface level
	protected int m_MaxDepth = 500; // the depth of the mining area in meters (default junctions are 4m cubed so 1 level is 4m)
	protected int m_EdgeBuffer = 20; // the buffer around the edge of the map
	protected int m_MinimumDistanceBetweenEntrances = 100; // the minimum distance between entrances so they are not spammed.
	protected int m_MaxWallSupportCount = 10; // the number of wooden logs needed to fortify a junction
	protected float m_MinimumOreYieldChance = 0.03; // out of 100%, what is the lowest chance for ANY spawn by default
	protected ref IAT_OreYieldManager m_IAT_OreYieldManager;
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
			iat_MIConfig.SetDefaultOreManager();
			// iat_MIConfig.SetDebugOreManager();
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

		// TODO defaults (find a better way?) maybe randomize door states? supports start "opened"

		// if this is an exit junction, spawn the supports on
		if (isExit)
		{
			// exit junctions have their supports already set for convenience
			junctionConfig.SetMineableComponentDoorStates({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1});
		}
		else
		{
			junctionConfig.SetMineableComponentDoorStates({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
		}

		TFloatArray oreChances = m_IAT_OreYieldManager.GetJunctionOreChancesByPosition(segmentPosition, m_MinimumOreYieldChance);

		junctionConfig.SetMineableComponentOreChances(oreChances);

		InsertMiningSegment(junctionConfig);
		return id;
	}

	void UpdateJunctionDoorState(string id, int doorIndex, int doorState = 0)
	{
		IAT_MiningSegmentConfig junctionToUpdate;
		if (Class.CastTo(junctionToUpdate, GetMiningSegmentById(id)))
		{
			junctionToUpdate.UpdateDoorState(doorIndex, doorState);
		}
	}
	void UpdateJunctionToExit(string id, vector teleportPosition)
	{
		IAT_MiningSegmentConfig junctionToUpdate;
		if (Class.CastTo(junctionToUpdate, GetMiningSegmentById(id)))
		{
			junctionToUpdate.SetIsExit(true);
			junctionToUpdate.SetSegmentTeleportDestination(teleportPosition);
		}
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
	// format the vector using sky surface
	vector GetExitJunctionSpawnPosition(vector surfacePosition)
	{
		vector newPosition = string.Format("%1 %2 %3", surfacePosition[0], m_SkySurfaceY, surfacePosition[2]).ToVector();
		return newPosition;
	}
	// format the entrance vector so it is predictable
	vector GetEntranceSpawnPosition(vector cursorPosition)
	{
		vector newPosition = string.Format("%1 %2 %3", Math.Round(cursorPosition[0]), cursorPosition[1], Math.Round(cursorPosition[2])).ToVector();
		return newPosition;
	}
	// check to see if there is an existing junction present at the supplied vector
	IAT_MiningSegmentConfig IsExistingJunctionPresent(vector potentialJunctionPosition)
	{
		// check if anything occupys this space already
		foreach(IAT_MiningSegmentConfig miningSegment : m_IAT_MiningSegmentConfigs)
		{
			if(vector.Distance(miningSegment.GetSegmentPosition(), potentialJunctionPosition) <= 4)
			{
				PrintFormat("IsExistingJunctionPresent::An existing entrance is here. Do not make a new one. %1", potentialJunctionPosition);
				// TODO: link the existing junction to the entrance
				return miningSegment;
			}
		}
		return null;
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
					PrintFormat("CanPlaceEntrance::There is an existing entrance with %1 of %2", m_MinimumDistanceBetweenEntrances, position);
					return false;
				}
			}
		}
		return true;
	}

	void SetDefaultOreManager()
	{
		if (!m_IAT_OreYieldManager)
			m_IAT_OreYieldManager = new IAT_OreYieldManager();

		/*
		* Mineable depth represents how much height can be used to distribute ore and its radius
		*/
		int mineableDepth = GetSkySurfaceY() - GetMaxDepth();

		// Metal ores (top to bottom, more plentiful at top)
		AddNewOreRecord("iron", 2400, 2500, 250, 750, 10, 1.5); // surface, large radius, high intensity
		AddNewOreRecord("copper", 2200, 2500, 250, 750, 10, 1.2); // upper 60%
		AddNewOreRecord("tin", 2200, 2500, 250, 750, 10, 1.1);
		AddNewOreRecord("lead", 2200, 2500, 250, 750, 10, 1.0);
		AddNewOreRecord("zinc", 2200, 2500, 250, 750, 10, 1.0);
		AddNewOreRecord("aluminium", 2200, 2500, 250, 750, 10, 0.9);

		// Precious metals (below 50% mineable depth)
		AddNewOreRecord("silver", 2000, 2250, 150, 500, 10, 0.8);
		AddNewOreRecord("gold", 2000, 2250, 150, 500, 10, 0.7);

		// Earth minerals
		AddNewOreRecord("clay", 2250, 2500, 500, 1500, 10, 1.3); // above 50%
		AddNewOreRecord("coal", 2250, 2500, 500, 1500, 10, 1.2);
		AddNewOreRecord("saltcrystals", 2250, 2500, 500, 1500, 10, 1.1);
		AddNewOreRecord("saltpeter", 2000, 2250, 300, 750, 10, 0.9); // below 50%
		AddNewOreRecord("sulfur", 2000, 2250, 300, 750, 10, 0.8);

		// Gemstones (tiered by depth)
		AddNewOreRecord("quartz", 2420, 2500, 400, 2000, 10, 1.0); // top 0-0.16
		AddNewOreRecord("amethyst", 2340, 2420, 400, 2000, 10, 0.9); // 0.16-0.32
		AddNewOreRecord("topaz", 2260, 2340, 400, 2000, 10, 0.8); // 0.32-0.48
		AddNewOreRecord("sapphire", 2180, 2260, 400, 2000, 10, 0.7); // 0.48-0.64
		AddNewOreRecord("ruby", 2100, 2180, 400, 2000, 10, 0.6); // 0.64-0.80
		AddNewOreRecord("diamond", 2000, 2100, 400, 2000, 10, 0.5); // bottom only
	}

	void SetDebugOreManager()
	{
		if (!m_IAT_OreYieldManager)
			m_IAT_OreYieldManager = new IAT_OreYieldManager();

		AddDebugOreRecords("iron");
		AddDebugOreRecords("copper");
		AddDebugOreRecords("tin");
		AddDebugOreRecords("lead");
		AddDebugOreRecords("zinc");
		AddDebugOreRecords("aluminium");
		AddDebugOreRecords("silver");
		AddDebugOreRecords("gold");
		AddDebugOreRecords("clay");
		AddDebugOreRecords("coal");
		AddDebugOreRecords("saltcrystals");
		AddDebugOreRecords("saltpeter");
		AddDebugOreRecords("sulfur");
		AddDebugOreRecords("quartz");
		AddDebugOreRecords("amethyst");
		AddDebugOreRecords("topaz");
		AddDebugOreRecords("sapphire");
		AddDebugOreRecords("ruby");
		AddDebugOreRecords("diamond");
	}

	void AddNewOreRecord(string oreType, int minHeight, int maxHeight, int minRadius, int maxRadius, int numPoints = 10, float intensity = 1.0, int mapSize = 11500)
	{
		m_IAT_OreYieldManager.InsertOreType(oreType);
		IAT_OreYieldAreaList oreArea = new IAT_OreYieldAreaList(oreType);
		float circleBuffer = maxRadius - minRadius;
		float mapBuffer = mapSize - circleBuffer;
		float x;
		float y;
		float z;
		float radius;
		vector circleCenter = vector.Zero;
		for (int i = 0; i < numPoints; i++)
		{
			// get random circle center that accounts for radius so it never goes outside the map
			x = Math.RandomFloat(circleBuffer, mapBuffer);
			z = Math.RandomFloat(circleBuffer, mapBuffer);
			// adjust the height within the range we want
			y = Math.RandomFloat(minHeight, maxHeight);
			circleCenter = string.Format("%1 %2 %3", x, y, z).ToVector();
			radius = Math.RandomFloat(minRadius, maxRadius);
			oreArea.AddOreYieldPoint(circleCenter, radius, intensity);
		}
		m_IAT_OreYieldManager.InsertOreYieldList(oreArea);

	}

	void AddDebugOreRecords(string oreType)
	{
		m_IAT_OreYieldManager.InsertOreType(oreType);
		IAT_OreYieldAreaList oreArea = new IAT_OreYieldAreaList(oreType);
		vector mapCenter = string.Format("%1 %2 %3", 6000, 2500, 6000).ToVector();
		oreArea.AddOreYieldPoint(mapCenter, 10000, 100);
		m_IAT_OreYieldManager.InsertOreYieldList(oreArea);
	}

	TFloatArray GetMiningSegmentOreChances(string id)
	{
		IAT_MiningSegmentConfig junctionSegments;
		if (Class.CastTo(junctionSegments, GetMiningSegmentById(id)))
		{
			return junctionSegments.GetMineableComponentOreChances();
		}
		return null;
	}

	// from the chance array, given an index, which oretype is associated?
	string GetOreTypeByChanceIndex(int index)
	{
		return m_IAT_OreYieldManager.GetOreTypeByIndex(index);
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
	int GetMaxWallSupportCount()
	{
		return m_MaxWallSupportCount;
	}
	void PrettyPrint()
	{
		Print("--[IAT MINING CONFIG BEGIN]");
		PrintFormat("----m_SkySurfaceY: %1", GetSkySurfaceY());
		PrintFormat("----m_MaxDepth: %1", GetMaxDepth());
		PrintFormat("----m_EdgeBuffer: %1", GetMapEdgeBuffer());
		PrintFormat("----m_MinimumDistanceBetweenEntrances: %1", GetMinDistanceBetweenEntrances());
		PrintFormat("----m_MaxWallSupportCount: %1", GetMaxWallSupportCount());
		m_IAT_OreYieldManager.PrettyPrint();
		Print("--[END]");
	}
};


	protected ref IAT_OreYieldManager m_IAT_OreYieldManager;