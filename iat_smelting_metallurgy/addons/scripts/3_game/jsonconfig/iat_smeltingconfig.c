class IAT_SmeltingConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "SmeltingConfig.json";

	protected ref array<ref IAT_SmeltingRecipe> m_IAT_Recipes;
	protected ref array<ref IAT_SmeltingScore> m_IAT_Scores;

	IAT_SmeltingConfig TryGetSmeltingConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		// new object so the non serialzied values are created
		IAT_SmeltingConfig iat_SMConfig = new IAT_SmeltingConfig();
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// DEFAULT ALLOY BARS
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_BlackPowder", "saltpeter", "sulfur", -1, 1, 1300));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Lead", "lead", "lead", -1, 1, 1330));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Solder", "lead", "tin", -1, 1, 1360));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Glass", "quartz", "quartz", -1, 1, 1390));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_AluminiumTin", "aluminium", "tin", -1, 1, 1430));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_AluminiumZinc", "aluminium", "zinc", -1, 1, 1470));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Scrap", "scrap", "scrap", -1, 1, 1500));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_SilverSterling", "silver", "tin", -1, 1, 1540));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Silver", "silver", "silver", -1, 1, 1570));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_ElectrumNatural", "gold", "silver", -1, 1, 1600));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_AluminiumBronze", "aluminium", "copper", -1, 1, 1640));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Copper", "copper", "copper", -1, 1, 1680));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Gold", "gold", "gold", -1, 1, 1720));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Bronze", "copper", "tin", -1, 1, 1760));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Brass", "copper", "zinc", -1, 1, 1800));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Nickel", "copper", "silver", -1, 1, 1860));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_PigIron", "iron", "iron", -1, 1, 1900));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_ElectrumIron", "iron", "silver", -1, 1, 1950));
			iat_SMConfig.IAT_InsertNewRecipe(new IAT_SmeltingRecipe("IAT_SmeltingIngot_Steel", "iron", "coke", -1, 1, 2000));

			// DEFAULT PLAYER SCORES
			iat_SMConfig.IAT_InsertNewScore(new IAT_SmeltingScore("TestPlayer", "76561197985160398"));

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_SmeltingConfig>.SaveFile(jsonConfig, iat_SMConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_SmeltingConfig>.LoadFile(jsonConfig, iat_SMConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_SMConfig;
	}

	void SaveConfig()
	{
		string errorMessage;
		// non serialized values are empty here because a loaded config isnt a 'new config'
		string rootFilePath = string.Format("%1\\%2\\%3", m_DayZFolder, m_RootConfigFolder, m_JsonFile);
		if (!JsonFileLoader<IAT_SmeltingConfig>.SaveFile(rootFilePath, this, errorMessage))
			ErrorEx(errorMessage);
		PrintFormat("[IAT_SmeltingConfig] Config Saved: %1", rootFilePath);
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================

	// ================================================================================== HELPERS
	void IAT_InsertNewRecipe(IAT_SmeltingRecipe recipe)
	{
		if (!m_IAT_Recipes)
		{
			m_IAT_Recipes = new array<ref IAT_SmeltingRecipe>();
		}
		m_IAT_Recipes.Insert(recipe);
	}
	void IAT_InsertNewScore(IAT_SmeltingScore score)
	{
		if (!m_IAT_Scores)
		{
			m_IAT_Scores = new array<ref IAT_SmeltingScore>();
		}
		m_IAT_Scores.Insert(score);
	}

	IAT_SmeltingRecipe IAT_GetSmeltingRecipe(string ore1, string ore2, int temperature)
	{
		foreach(IAT_SmeltingRecipe recipe : m_IAT_Recipes)
		{
			if (recipe.CanCraft(ore1, ore2, temperature))
			{
				return recipe;
			}
		}
		return null;
	}

	IAT_SmeltingScore IAT_GetSmeltingScore(string playerName, string playerId)
	{
		foreach(IAT_SmeltingScore score : m_IAT_Scores)
		{
			if (score.IsPlayerScore(playerId))
			{
				score.TryUpdateName(playerName);
				return score;
			}
		}
		// at this point the user does not exist so lets add an entry for them and send it back
		IAT_SmeltingScore newScore = new IAT_SmeltingScore(playerName, playerId);
		IAT_InsertNewScore(newScore);

		return newScore;
	}

	void IncrementPlayerWins(string playerId, int win, int streak)
	{
		foreach(IAT_SmeltingScore score : m_IAT_Scores)
		{
			if (score.IsPlayerScore(playerId))
			{
				score.IncrementWins(win, streak);
			}
		}
	}
	void IncrementPlayerLoss(string playerId, int loss)
	{
		foreach(IAT_SmeltingScore score : m_IAT_Scores)
		{
			if (score.IsPlayerScore(playerId))
			{
				score.IncrementLoss(loss);
			}
		}
	}

	void PrettyPrint()
	{
		Print("--[IAT_SmeltingConfig BEGIN]");
		Print("----[IAT_SmeltingRecipe BEGIN]");
		foreach(IAT_SmeltingRecipe recipe : m_IAT_Recipes)
		{
			recipe.PrettyPrint();
		}
		Print("----[IAT_SmeltingRecipe END]");
		Print("----[IAT_SmeltingScore BEGIN]");
		foreach(IAT_SmeltingScore score : m_IAT_Scores)
		{
			score.PrettyPrint();
		}
		Print("----[IAT_SmeltingScore END]");
		Print("--[IAT_SmeltingConfig END]");
	}
};