class IAT_SimpleBuildingConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "SimpleBuildingConfig.json";

	// map of all the building stages
	protected ref map<string, ref IAT_BuildingRequirements> m_BuildingStages;

	IAT_SimpleBuildingConfig TryGetSimpleBuildingConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_SimpleBuildingConfig iat_SBConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_SBConfig = new IAT_SimpleBuildingConfig();
			// set some default values
			iat_SBConfig.m_BuildingStages = new map<string, ref IAT_BuildingRequirements>;

			IAT_BuildingRequirements requirements = new IAT_BuildingRequirements();
			TStringArray allowedTools = { "Hammer", "Screwdriver", "Pliers" };
			requirements.SetAllowedTools(allowedTools);
			requirements.SetLastStage(false);
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenStick", 2));
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenLog", 2));
			iat_SBConfig.m_BuildingStages.Set("IAT_BuildingStage_ExampleShack_0", requirements);

			requirements = new IAT_BuildingRequirements();
			requirements.SetAllowedTools(allowedTools);
			requirements.SetLastStage(false);
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenStick", 3));
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenLog", 3));
			iat_SBConfig.m_BuildingStages.Set("IAT_BuildingStage_ExampleShack_1", requirements);

			requirements = new IAT_BuildingRequirements();
			requirements.SetAllowedTools(allowedTools);
			requirements.SetLastStage(false);
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenStick", 4));
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenLog", 4));
			iat_SBConfig.m_BuildingStages.Set("IAT_BuildingStage_ExampleShack_2", requirements);

			requirements = new IAT_BuildingRequirements();
			requirements.SetAllowedTools(allowedTools);
			requirements.SetLastStage(false);
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenStick", 5));
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenLog", 5));
			iat_SBConfig.m_BuildingStages.Set("IAT_BuildingStage_ExampleShack_3", requirements);

			requirements = new IAT_BuildingRequirements();
			requirements.SetAllowedTools(allowedTools);
			requirements.SetLastStage(false);
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenStick", 6));
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenLog", 6));
			iat_SBConfig.m_BuildingStages.Set("IAT_BuildingStage_ExampleShack_4", requirements);

			requirements = new IAT_BuildingRequirements();
			requirements.SetAllowedTools(allowedTools);
			requirements.SetLastStage(true);
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenStick", 7));
			requirements.AddRequiredItem(new IAT_BuildingRequiredItems("WoodenLog", 7));
			iat_SBConfig.m_BuildingStages.Set("IAT_BuildingStage_ExampleShack_5", requirements);

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_SimpleBuildingConfig>.SaveFile(jsonConfig, iat_SBConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_SimpleBuildingConfig>.LoadFile(jsonConfig, iat_SBConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_SBConfig;
	}

	// ================================================================================== HELPERS
	bool HasBuildingRequirements(string className)
	{
		if (m_BuildingStages)
		{
			if (m_BuildingStages.Contains(className))
			{
				return true;
			}
		}
		return false;
	}
	IAT_BuildingRequirements GetBuildingRequirements(string className)
	{
		if (m_BuildingStages)
		{
			if (m_BuildingStages.Contains(className))
			{
				return m_BuildingStages.Get(className);
			}
		}
		return null;
	}

	void PrettyPrint()
	{
		Print("--[IAT_SimpleBuildingConfig BEGIN]");
		IAT_BuildingRequirements buildingRequirement;
		TStringArray buildingKeys = m_BuildingStages.GetKeyArray();
		foreach(string buildingKey : buildingKeys)
		{
			PrintFormat("----Building Stage: %1", buildingKey);
			buildingRequirement = m_BuildingStages.Get(buildingKey);
			buildingRequirement.PrettyPrint();
		}
		Print("--[IAT_SimpleBuildingConfig END]");
	}
};