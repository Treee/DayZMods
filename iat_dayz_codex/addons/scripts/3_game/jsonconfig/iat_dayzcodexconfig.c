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
			m_Codex = new IAT_CodexDictionary();

			IAT_CodexCategory rootCategory = new IAT_CodexCategory("All", "", -1);

			IAT_CodexCategory aiCategory = new IAT_CodexCategory("AI", "", -1);
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Animals", "AnimalBase", -1));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Survivors", "SurvivorBase", -1));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Zombie(F)", "ZombieFemaleBase", -1));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Zombie(M)", "ZombieMaleBase", -1));
			aiCategory.InsertNewSubCategory(new IAT_CodexCategory("Zombies", "ZombieBase", -1));

			IAT_CodexCategory clothingCategory = new IAT_CodexCategory("Clothing", "", -1);
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Backpacks", "Backpack_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Headgear", "HeadGear_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Eyewear", "Glasses_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Masks", "Mask_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Tops", "Top_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Armbands", "Armband_ColorBase", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Vests", "Vest_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Gloves", "Gloves_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Belts", "Belt_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Pants", "Pants_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Shoes", "Shoes_Base", -1));
			clothingCategory.InsertNewSubCategory(new IAT_CodexCategory("Other Clothing", "Clothing", -1));

			IAT_CodexCategory gearCategory = new IAT_CodexCategory("Gear", "", -1);
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Bottles", "Bottle_Base", -1));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Edibles", "Edible_Base", -1));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Tools", "ToolBase", -1));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Books", "ItemBook", -1));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Flags", "Flag_Base", -1));
			gearCategory.InsertNewSubCategory(new IAT_CodexCategory("Pelts", "Pelt_Base", -1));

			IAT_CodexCategory weaponGearCategory = new IAT_CodexCategory("Weapon Gear", "", -1);
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Buttstocks", "ButtstockBase", -1));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("AK Handguards", "AK_RailHndgrd", -1));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Optics", "ItemOptics", -1));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Grenades", "Grenade_Base", -1));
			weaponGearCategory.InsertNewSubCategory(new IAT_CodexCategory("Ghillies", "GhillieAtt_ColorBase", -1));

			IAT_CodexCategory containersCategory = new IAT_CodexCategory("Containers", "", -1);
			containersCategory.InsertNewSubCategory(new IAT_CodexCategory("Boxes", "Box_Base", -1));
			containersCategory.InsertNewSubCategory(new IAT_CodexCategory("Storage", "Container_Base", -1));

			IAT_CodexCategory vehiclesCategory = new IAT_CodexCategory("Vehicles", "", -1);
			vehiclesCategory.InsertNewSubCategory(new IAT_CodexCategory("Car Doors", "CarDoor", -1));
			vehiclesCategory.InsertNewSubCategory(new IAT_CodexCategory("Cars", "CarScript", -1));
			vehiclesCategory.InsertNewSubCategory(new IAT_CodexCategory("Boats", "BoatScript", -1));

			IAT_CodexCategory weaponsCategory = new IAT_CodexCategory("Weapons", "", -1);
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Guns", "Weapon_Base", -1));
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Magazines", "MagazineStorage", -1));
			weaponsCategory.InsertNewSubCategory(new IAT_CodexCategory("Ammunition", "Ammunition_Base", -1));

			IAT_CodexCategory baseBuildingCategory = new IAT_CodexCategory("Base Building", "", -1);
			baseBuildingCategory.InsertNewSubCategory(new IAT_CodexCategory("Buildings", "BaseBuildingBase", -1));

			rootCategory.InsertNewSubCategory(aiCategory);
			rootCategory.InsertNewSubCategory(clothingCategory);
			rootCategory.InsertNewSubCategory(gearCategory);
			rootCategory.InsertNewSubCategory(weaponGearCategory);
			rootCategory.InsertNewSubCategory(containersCategory);
			rootCategory.InsertNewSubCategory(vehiclesCategory);
			rootCategory.InsertNewSubCategory(weaponsCategory);
			rootCategory.InsertNewSubCategory(baseBuildingCategory);

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


	void PrettyPrint()
	{
		Print("--[IAT_DayZCodexConfig BEGIN]");
		m_Codex.PrettyPrint();
		Print("--[IAT_DayZCodexConfig END]");
	}
};