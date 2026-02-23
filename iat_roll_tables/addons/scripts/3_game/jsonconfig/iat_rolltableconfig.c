class IAT_RollTableConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "RollTableConfig.json";

	protected bool m_IsDebugPrintEnabled;
	protected ref map<string, ref IAT_RollTable> m_RollTableMap;

	IAT_RollTableConfig TryGetRollTableConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_RollTableConfig iat_RTConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_RTConfig = new IAT_RollTableConfig();
			// set some default values
			iat_RTConfig.m_IsDebugPrintEnabled = false;

			IAT_RollTable rollTable = new IAT_RollTable("lootbox_small_1", 20);
			rollTable.RegisterProbability(new IAT_RollTableResult(1, 5, {"Nail", "Battery9v"}));
			rollTable.RegisterProbability(new IAT_RollTableResult(6, 10, {"SewingKit", "Paper", "DuctTape"}));
			rollTable.RegisterProbability(new IAT_RollTableResult(11, 15, {"GiftWrapPaper"}));
			rollTable.RegisterProbability(new IAT_RollTableResult(16, 20, {"Matchbox", "PunchedCard"}));
			iat_RTConfig.RegisterRollTable(rollTable);

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_RollTableConfig>.SaveFile(jsonConfig, iat_RTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_RollTableConfig>.LoadFile(jsonConfig, iat_RTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_RTConfig;
	}

	// ================================================================================== HELPERS
	/*
	* Handle the case where a loot table result can reference another loot table
	* returns a string representing a single item reward
	*/
	string GetRollTableResult(string tableName, int diceRoll = 0)
	{
		string potentialResult = "";
		// server only
		if (!g_Game.IsDedicatedServer())
		{
			return potentialResult;
		}

		IAT_RollTable rollTable;
		// if the tableName is pointing to an actual roll table
		if (Class.CastTo(rollTable, GetRollTable(tableName)))
		{
			// get the result(s) from the dice roll. this is a list of potential
			// things that this roll can yield. can be items, can be other roll tables
			// can be both
			TStringArray firstRollTableResults = rollTable.GetResults(diceRoll);
			// this keeps track of the inner roll tables of this parant while
			// we traverse the graph
			TStringArray otherTollTableResaults = {};
			// pick the first potential result
			potentialResult = firstRollTableResults.GetRandomElement();
			// keep checking for a loot table until
			// we find a result that is not a loot table
			while (Class.CastTo(rollTable, GetRollTable(potentialResult)))
			{
				// get this roll tables results (random result)
				otherTollTableResaults = rollTable.GetResults();
				// pick the next potential result
				potentialResult = otherTollTableResaults.GetRandomElement();
				// PrintFormat("result was a roll table, new result is: %1", potentialResult);
			}
		}
		PrintDebugLog(string.Format("[IAT_RollTableConfig]--GetRollTableResult: %1 from RollTable: %2 DiceRoll: %3", potentialResult, tableName, diceRoll));
		return potentialResult;
	}

	void PrintDebugLog(string s)
	{
		if (m_IsDebugPrintEnabled)
		{
			PrintFormat("%1",s);
		}
	}

	/*
	*
	* Spawns a result for a given roll table
	* className - string classname of the object to spawn
	* position - position to spawn this object
	* quantityModifier - 0-1 range to reduce quantity. 0 is no reduction, 1 is full reduction
	*/
	EntityAI SpawnRollTableResult(string className, vector position, float quantityModifier = 0.0)
	{
		// server only
		if (!g_Game.IsDedicatedServer())
		{
			return null;
		}
		// flags such that the item works but doesnt persist between restarts unless players interact
		int iFlags = ECE_SETUP|ECE_PLACE_ON_SURFACE|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY;

		EntityAI entityResult;
		// handle the case for AI
		bool isAi = g_Game.IsKindOf(className, "DZ_LightAI") || g_Game.IsKindOf(className, "SurvivorBase");
		if (isAi)
		{
			iFlags |= ECE_INITAI|ECE_CREATEPHYSICS;
		}
		// PrintFormat("===================attempt to create: %1", className);
		// at this point we know we have a result that is just an item or AI
		if (Class.CastTo(entityResult, g_Game.CreateObjectEx(className, position, iFlags)))
		{
			// PrintFormat("================================================ CREATED: %1", className);
			// get the max quantity
			int maxQuantity = entityResult.GetQuantityMax();
			// reduce it by the modifier
			int spawnQuantity = maxQuantity - (maxQuantity * quantityModifier);
			// treat ammo special

			if (entityResult.HasQuantity())
			{
				entityResult.SetQuantity(spawnQuantity);
			}
		}
		return entityResult;
	}

	// Gets the immediate roll table results as a list. items can potential be another roll table
	protected TStringArray GetRollTableResults(string tableName)
	{
		IAT_RollTable rollTable;
		// if the tableName is pointing to an actual roll table
		if (Class.CastTo(rollTable, GetRollTable(tableName)))
		{
			PrintDebugLog(string.Format("[IAT_RollTableConfig]--GetRollTableResults %1 exists", tableName));
			// get the next result
			return rollTable.GetResults();
		}
		PrintDebugLog(string.Format("[IAT_RollTableConfig]--GetRollTableResults %1 does not exist", tableName));
		return {};
	}

	// gets a roll table given a name. null if doesnt exist
	protected IAT_RollTable GetRollTable(string tableName)
	{
		if (RollTableExists(tableName))
		{
			PrintDebugLog(string.Format("[IAT_RollTableConfig]--GetRollTable contains %1", tableName));
			return m_RollTableMap.Get(tableName);
		}
		return null;
	}

	// checks to see if a given roll table exists
	protected bool RollTableExists(string tableName)
	{
		// if the map doesnt exist
		if (!m_RollTableMap)
		{
			return false; // short circuit
		}
		// if the map has the tablename
		if (m_RollTableMap.Contains(tableName))
		{
			return true;
		}
		return false;
	}


	// programatic way to register a new roll table
	void RegisterRollTable(IAT_RollTable newRollTable)
	{
		// if the map doesnt exist
		if (!m_RollTableMap)
		{
			PrintDebugLog("[IAT_RollTableConfig]--RollTableMap does not exist, creating it");
			// create it
			m_RollTableMap = new map<string, ref IAT_RollTable>();
		}
		// if the map doesnt have this table
		if (!m_RollTableMap.Contains(newRollTable.GetTableName()))
		{
			// insert it
			m_RollTableMap.Insert(newRollTable.GetTableName(), newRollTable);
			PrintDebugLog(string.Format("[IAT_RollTableConfig]--Adding roll table %1", newRollTable.GetTableName()));
		}
		else
		{
			PrintDebugLog(string.Format("[IAT_RollTableConfig]--RollTableMap contains %1 already, ignoring duplicate", newRollTable.GetTableName()));
		}
	}

	// print the contents of the roll tables
	void PrettyPrint()
	{
		PrintDebugLog("--[IAT_RollTableConfig BEGIN]");
		IAT_RollTable rollTable;

		TStringArray rollTableKeys = m_RollTableMap.GetKeyArray();
		foreach (string key : rollTableKeys)
		{
			if (Class.CastTo(rollTable, m_RollTableMap.Get(key)))
			{
				PrintDebugLog(rollTable.ToPrettyString());
			}
		}
		PrintDebugLog("--[IAT_RollTableConfig END]");
	}
};