class IAT_RollTableConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "RollTableConfig.json";

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

			IAT_RollTable rollTable = new IAT_RollTable("Small1", 20);
			rollTable.RegisterProbability(new IAT_RollTableProbability(1, 5, {"Nail", "Battery9v"}));
			rollTable.RegisterProbability(new IAT_RollTableProbability(6, 10, {"SewingKit", "Paper", "DuctTape"}));
			rollTable.RegisterProbability(new IAT_RollTableProbability(11, 15, {"GiftWrapPaper"}));
			rollTable.RegisterProbability(new IAT_RollTableProbability(16, 20, {"Matchbox", "PunchedCard"}));
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
	TStringArray GetResultsForItem(string tableName)
	{
		IAT_RollTable rollTable;
		// if the tableName is pointing to an actual roll table
		if (Class.CastTo(rollTable, GetRollTable(tableName)))
		{
			// get the next result
			return rollTable.GetResults();
		}
		return {};
	}
	bool RollTableExists(string tableName)
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
	IAT_RollTable GetRollTable(string tableName)
	{
		if (RollTableExists(tableName))
		{
			return m_RollTableMap.Get(tableName);
		}
		return null;
	}
	void RegisterRollTable(IAT_RollTable newRollTable)
	{
		// if the map doesnt exist
		if (!m_RollTableMap)
		{
			// create it
			m_RollTableMap = new map<string, ref IAT_RollTable>();
		}
		// if the map doesnt have this table
		if (!m_RollTableMap.Contains(newRollTable.GetTableName()))
		{
			// insert it
			m_RollTableMap.Insert(newRollTable.GetTableName(), newRollTable);
		}
	}
	void PrettyPrint()
	{
		Print("--[IAT_RollTableConfig BEGIN]");
		IAT_RollTable rollTable;

		TStringArray rollTableKeys = m_RollTableMap.GetKeyArray();
		foreach (string key : rollTableKeys)
		{
			if (Class.CastTo(rollTable, m_RollTableMap.Get(key)))
			{
				rollTable.PrettyPrint();
			}
		}
		Print("--[IAT_RollTableConfig END]");
	}
};