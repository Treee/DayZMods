class IAT_CraftingPlusConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "CraftingPlusConfig.json";

	protected ref array<ref IAT_RecipeManager> m_IAT_RecipeManagers;

	IAT_CraftingPlusConfig TryGetCraftingPlusConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_CraftingPlusConfig iat_CPConfig = new IAT_CraftingPlusConfig();
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// set some default values
			iat_CPConfig.m_IAT_RecipeManagers = new array<ref IAT_RecipeManager>;

			IAT_RecipeManager testManager = new IAT_RecipeManager("TestManager");

			IAT_CraftingRecipe recipe1 = new IAT_CraftingRecipe("Single Item Result", "Hammer", 2);
			// default parameters technical dont need to be added but for verbosity here they are
			recipe1.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_WoodenLogs", "", 1));
			recipe1.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_L1_WoodenPlanks", "", 1));
			recipe1.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_MetalSheets"));
			recipe1.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_Shelter_Fabric"));
			recipe1.InsertCraftingRequirement(new IAT_CraftingItemRequirement("MetalWire"));
			recipe1.InsertCraftingResult(new IAT_CraftingResult("SewingKit", 50, 75));
			testManager.InsertCraftingRecipe(recipe1);


			IAT_CraftingRecipe recipe2 = new IAT_CraftingRecipe("Single Item Result Different Tool", "Pliers", 2);
			// default parameters technical dont need to be added but for verbosity here they are
			recipe2.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_WoodenLogs", "", 1));
			recipe2.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_L1_WoodenPlanks", "", 1));
			recipe2.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_MetalSheets", "", 4));
			recipe2.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_Shelter_Fabric", "", 2));
			recipe2.InsertCraftingRequirement(new IAT_CraftingItemRequirement("MetalWire"));
			recipe2.InsertCraftingResult(new IAT_CraftingResult("LeatherSewingKit", 50, 75));
			testManager.InsertCraftingRecipe(recipe2);

			IAT_CraftingRecipe recipe3 = new IAT_CraftingRecipe("Multi Item Result", "Hammer", 2);
			// default parameters technical dont need to be added but for verbosity here they are
			recipe3.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Material_WoodenLogs", "", 2));
			recipe3.InsertCraftingResult(new IAT_CraftingResult("Apple", 50, 75));
			recipe3.InsertCraftingResult(new IAT_CraftingResult("Plum", 50, 75));
			testManager.InsertCraftingRecipe(recipe3);

			IAT_CraftingRecipe recipe4 = new IAT_CraftingRecipe("Color Required Recipe Multi Result", "", 25);
			// default parameters technical dont need to be added but for verbosity here they are
			recipe4.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Chemlight", "Blue", 20));
			recipe4.InsertCraftingResult(new IAT_CraftingResult("Chemlight_White"));
			recipe4.InsertCraftingResult(new IAT_CraftingResult("Chemlight_Green"));
			testManager.InsertCraftingRecipe(recipe4);

			IAT_CraftingRecipe recipe5 = new IAT_CraftingRecipe("Protected Ingredient Recipe", "EpoxyPutty", 0, 25);
			// default parameters technical dont need to be added but for verbosity here they are
			recipe5.InsertCraftingRequirement(new IAT_CraftingItemRequirement("Chemlight", "Green", 20, false, true));
			recipe5.InsertCraftingResult(new IAT_CraftingResult("Chemlight_White"));
			recipe5.InsertCraftingResult(new IAT_CraftingResult("Chemlight_Blue"));
			testManager.InsertCraftingRecipe(recipe5);

			iat_CPConfig.m_IAT_RecipeManagers.Insert(testManager);

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_CraftingPlusConfig>.SaveFile(jsonConfig, iat_CPConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_CraftingPlusConfig>.LoadFile(jsonConfig, iat_CPConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_CPConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	IAT_RecipeManager GetRecipeManagerByName(string recipeManagerName)
	{
		foreach(IAT_RecipeManager recipeManager : m_IAT_RecipeManagers)
		{
			if (recipeManager.GetRecipeManagerName() == recipeManagerName)
			{
				return recipeManager;
			}
		}
		return null;
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	void PrettyPrint()
	{
		Print("--[CRAFTING PLUS CONFIG BEGIN]");
		foreach (IAT_RecipeManager recipeManager : m_IAT_RecipeManagers)
		{
			PrintFormat("Registering Recipe Manager: %1", recipeManager.GetRecipeManagerName());
			recipeManager.PrintRecipes();
		}
		Print("--[END]");
	}
};