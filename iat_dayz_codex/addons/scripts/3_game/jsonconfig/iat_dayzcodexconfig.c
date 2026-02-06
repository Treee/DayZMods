class IAT_DayZCodexConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "DayZCodexConfig.json";

	protected ref IAT_CodexDictionary m_Codex;

	IAT_DayZCodexConfig TryGetDayZCodexConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_DayZCodexConfig iat_DzCConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_DzCConfig = new IAT_DayZCodexConfig();
			// set some default values
			iat_DzCConfig.m_Codex = new IAT_CodexDictionary();
			iat_DzCConfig.m_Codex.SetIsDebugMode(true);

			TStringArray defaultIgnoredClassNames = {"TestObject", "DoorTestCamera", "PowerGeneratorStatic", "IAT_Admin_Thermometer", "RabbitPreview_Mourek"};
			iat_DzCConfig.m_Codex.SetIgnoredClasses(defaultIgnoredClassNames);
			TStringArray defaultIgnoredClassKinds = {"HouseNoDestruct", "EffectArea", "CarDoor"};
			iat_DzCConfig.m_Codex.SetIgnoredClassKinds(defaultIgnoredClassKinds);
			TStringArray defaultIgnoredClassContains = {"_Test", "Placing", "UndergroundStash", "GardenPlot"};
			iat_DzCConfig.m_Codex.SetIgnoredClassContains(defaultIgnoredClassContains);

			IAT_CodexCategory rootCategory = new IAT_CodexCategory("All", "", -1, false, false);

			IAT_CodexCategory srpCategory = new IAT_CodexCategory("Collectibles", "", -1, false, false);
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Teddy Bears", "IAT_Bear_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Vinyl Cover", "IAT_VinylCover_ColorBase", -1, false, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Vinyl Art", "IAT_VinylRecordArt_ColorBase", -1, false, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Playable Vinyl", "IAT_PlayableVinylCover_ColorBase", -1, false, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Pumpkins", "IAT_Pumpkin_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Frame Landscape", "IAT_PictureFrame_Landscape_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Frame Portrait", "IAT_PictureFrame_Portrait_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Frame Square", "IAT_PictureFrame_Square_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Carved Pumpkins", "IAT_PumpkinCarved_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Playing Cards", "IAT_CollectibleCard_ColorBase", -1, false, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Booster Packs", "IAT_BoosterPack_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Carved Letters", "IAT_CarvedSymbol_ColorBase", -1, false, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ADM AK Barrels", "ADM_CW_AK_Barrel_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ADM AR Barrels", "ADM_CW_AR_Barrel_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ADM AK Uppers", "ADM_CW_AK_Upper_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ADM AR Uppers", "ADM_CW_AR_Upper_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ALV Patches", "ALV_Patch_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ALV Herbs", "ALV_Herb_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ALV Plants", "ALV_Plant_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ALV Kits", "ALV_Kit_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("ALV Deployed", "ALV_Deployable_Base", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Display Kits", "IAT_DisplayCaseKit_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Display Case", "IAT_DisplayCase_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Ingots", "IAT_SmeltingIngot_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Ores", "IAT_MiningOre_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Gems", "IAT_MiningGem_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Furnace Kits", "IAT_FurnaceKit_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Furnace", "IAT_SmeltingFurnace_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Picture Frame1", "SRP_Investor_PictureFrame_Colorbase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Picture Frame2", "SRP_Investor_PictureFrame_2_Colorbase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Picture Frame3", "SRP_Investor_PictureFrame_2Small_Colorbase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Sign Landscape", "SRP_Investor_CollectableSignHorizontal_Colorbase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Sign Portrait", "SRP_Investor_CollectableSignVertical_Colorbase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Croc Skins", "CrocodileSkin_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Croc Hands", "CrocodileSkinHands_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Croc Parts", "CrocodileSkinParts_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Croc Teeth", "CrocodileLeatherStrapTeeth_ColorBase", -1, true, false));
			srpCategory.InsertNewSubCategory(new IAT_CodexCategory("Croc Strap", "CrocodileLeatherStrap_ColorBase", -1, true, false));

			IAT_CodexCategory aiCategory = new IAT_CodexCategory("AI", "", -1, false, false);
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Animals", "AnimalBase", -1, true, false));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Survivors", "SurvivorBase", -1, true, false));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Zombie(F)", "ZombieFemaleBase", -1, true, false));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Zombie(M)", "ZombieMaleBase", -1, true, false));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Zombies", "ZombieBase", -1, true, false));

			IAT_CodexCategory clothingCategory = new IAT_CodexCategory("Clothing", "", -1, false, false);
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Backpacks", "Backpack_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Headgear", "HeadGear_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Eyewear", "Glasses_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Masks", "Mask_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Tops", "Top_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Armbands", "Armband_ColorBase", -1, true, false));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Vests", "Vest_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Gloves", "Gloves_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Belts", "Belt_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Pants", "Pants_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Shoes", "Shoes_Base", -1, true, true));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Other Clothing", "Clothing", -1, true, false));

			IAT_CodexCategory containersCategory = new IAT_CodexCategory("Containers", "", -1, false, false);
			containersCategory.InsertNewSubCategory(new IAT_CodexCategory("Boxes", "Box_Base", -1, true, false));
			containersCategory.InsertNewSubCategory(new IAT_CodexCategory("Tents", "TentBase", -1, true, false));
			containersCategory.InsertNewSubCategory(new IAT_CodexCategory("Storage", "Container_Base", -1, true, false));

			IAT_CodexCategory gearCategory = new IAT_CodexCategory("Gear", "", -1, false, false);
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Bottles", "Bottle_Base", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Edibles", "Edible_Base", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Tools", "ToolBase", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Books", "ItemBook", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Flags", "Flag_Base", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Pelts", "Pelt_Base", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Traps", "Trap_Base", -1, true, false));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Other Traps", "TrapBase", -1, true, false));

			IAT_CodexCategory weaponGearCategory = new IAT_CodexCategory("Weapon Gear", "", -1, false, false);
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Ghillies", "GhillieAtt_ColorBase", -1, true, false));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Buttstocks", "ButtstockBase", -1, true, false));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Handguards", "AK_RailHndgrd", -1, true, false));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Suppressors", "ItemSuppressor", -1, true, false));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Optics", "ItemOptics", -1, true, false));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Grenades", "Grenade_Base", -1, true, false));

			IAT_CodexCategory vehiclesCategory = new IAT_CodexCategory("Vehicles", "", -1, false, false);
			vehiclesCategory.InsertNewSubCategory(new IAT_CodexCategory("Cars", "CarScript", -1, true, false));
			vehiclesCategory.InsertNewSubCategory(new IAT_CodexCategory("Boats", "BoatScript", -1, true, false));

			IAT_CodexCategory weaponsCategory = new IAT_CodexCategory("Weapons", "", -1, false, false);
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Guns", "Weapon_Base", -1, true, false));
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Melee", "NoMatch", -1, true, false));
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Ammunition", "Ammunition_Base", -1, true, false));
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Magazines", "Magazine_Base", -1, true, false));

			IAT_CodexCategory baseBuildingCategory = new IAT_CodexCategory("Base Building", "", -1, false, false);
			baseBuildingCategory.InsertNewSubCategory(new IAT_CodexCategory("Buildings", "BaseBuildingBase", -1, true, false));
			baseBuildingCategory.InsertNewSubCategory(new IAT_CodexCategory("Kits", "KitBase", -1, true, false));

			IAT_CodexCategory miscCategory = new IAT_CodexCategory("Misc", "", -1, false, false);
			miscCategory.InsertNewSubCategory(new IAT_CodexCategory("Other Items", "Inventory_Base", -1, true, false));
			miscCategory.InsertNewSubCategory(new IAT_CodexCategory("Other Items1", "ItemBase", -1, true, false));

			rootCategory.InsertNewSubCategory(srpCategory);
			rootCategory.InsertNewSubCategory(aiCategory);
			rootCategory.InsertNewSubCategory(clothingCategory);
			rootCategory.InsertNewSubCategory(gearCategory);
			rootCategory.InsertNewSubCategory(weaponGearCategory);
			rootCategory.InsertNewSubCategory(containersCategory);
			rootCategory.InsertNewSubCategory(vehiclesCategory);
			rootCategory.InsertNewSubCategory(weaponsCategory);
			rootCategory.InsertNewSubCategory(baseBuildingCategory);
			rootCategory.InsertNewSubCategory(miscCategory);

			iat_DzCConfig.m_Codex.SetCategories(rootCategory);
			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_DayZCodexConfig>.SaveFile(jsonConfig, iat_DzCConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_DayZCodexConfig>.LoadFile(jsonConfig, iat_DzCConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_DzCConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================


	// ================================================================================== HELPERS
	void IAT_Codex_ParseCfgItems(string cfg_path)
	{
		// PrintFormat("Config Path: %1", cfg_path);
		if (g_Game.ConfigIsExisting(cfg_path))
		{
			string className;
			string classPathScope;
			int numRootChildren = g_Game.ConfigGetChildrenCount(cfg_path);
			for(int rootIndex = 0; rootIndex < numRootChildren; rootIndex++)
			{
				g_Game.ConfigGetChildName(cfg_path, rootIndex, className);
				classPathScope = string.Format("%1 %2 scope", cfg_path, className);
				// only scope 2 objects pass this check
				if (g_Game.ConfigGetInt(classPathScope) == 2)
				{
					m_Codex.TryAddType(cfg_path, className);
				}
			}
		}
	}

	void PrettyPrint()
	{
		Print("--[IAT_DayZCodexConfig BEGIN]");
		m_Codex.PrettyPrint();
		Print("--[IAT_DayZCodexConfig END]");
	}
};