class IAT_DynamicTrapsConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "DynamicTrapsConfig.json";

	protected bool m_IsEnabled;
	protected int m_MaxRoll;
	protected int m_MinRoll;
	protected ref array<ref IAT_DynamicTrap> m_DynamicTraps;

	IAT_DynamicTrapsConfig TryGetDynamicTrapsConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		// new config object
		IAT_DynamicTrapsConfig iat_DTConfig = new IAT_DynamicTrapsConfig();

		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			bool persistency = true; // dynamic persistence (no lifetime or saving)
			bool initAI = true;
			bool placeOnSurface = true;
			bool keepHeight = true;
			// set some default values
			iat_DTConfig.SetIsEnabled(true);
			iat_DTConfig.SetMinRoll(0);
			iat_DTConfig.SetMaxRoll(100);

			IAT_DynamicTrap trap;
			IAT_DynamicTrapResult result;
			trap = new IAT_DynamicTrap("Land_Container_1Aoh", -1);

			result = new IAT_DynamicTrapResult(35, 69, 5, persistency, !initAI, placeOnSurface, !keepHeight);
			result.AddResult("Nailbox");
			result.AddResult("Nail");
			result.AddResult("Pliers");
			result.AddResult("Hammer");
			result.AddResult("Handcuffs");
			result.AddResult("HandcuffKeys");
			result.AddResult("Crowbar");
			result.AddResult("Broom");
			result.AddResult("Paddle");
			result.AddResult("Whetstone");
			result.AddResult("EpoxyPutty");
			result.AddResult("WeaponCleaningKit");
			result.AddResult("Lockpick");
			trap.AddDynamicTrapResult(result);


			result = new IAT_DynamicTrapResult(70, 79, 2, !persistency, initAI, placeOnSurface, !keepHeight);
			result.AddResult("ZmbM_SoldierNormal");
			result.AddResult("ZmbM_usSoldier_normal_Woodland");
			result.AddResult("ZmbM_usSoldier_normal_Desert");
			result.AddResult("ZmbM_usSoldier_Officer_Desert");
			result.AddResult("ZmbM_usSoldier_Officer_Convoy");
			result.AddResult("ZmbM_usSoldier_Heavy_Woodland");
			result.AddResult("ZmbM_PatrolNormal_PautRev");
			result.AddResult("ZmbM_PatrolNormal_Autumn");
			result.AddResult("ZmbM_PatrolNormal_Flat");
			result.AddResult("ZmbM_PatrolNormal_Summer");
			result.AddResult("ZmbM_NBC_Grey");
			result.AddResult("ZmbM_VillagerOld_Blue");
			result.AddMemoryPointSpawnLocation("sound_rainobjectinner1metal2_1");
			trap.AddDynamicTrapResult(result);

			result = new IAT_DynamicTrapResult(80, 89, 4, !persistency, initAI, placeOnSurface, !keepHeight);
			result.AddResult("ZmbM_HermitSkinny_Red");
			result.AddResult("ZmbM_FarmerFat_Brown");
			result.AddResult("ZmbF_CitizenANormal_Beige");
			result.AddResult("ZmbM_CitizenBFat_Red");
			result.AddResult("ZmbF_CitizenBSkinny");
			result.AddResult("ZmbM_PrisonerSkinny");
			result.AddResult("ZmbM_FishermanOld_Blue");
			result.AddResult("ZmbF_JournalistNormal_Green");
			result.AddResult("ZmbF_HikerSkinny_Green");
			result.AddResult("ZmbM_CommercialPilotOld_Olive");
			result.AddResult("ZmbF_SkaterYoung_Striped");
			result.AddResult("ZmbF_MechanicNormal_Orange");
			result.AddResult("ZmbM_ConstrWorkerNormal_Black");
			result.AddResult("ZmbM_OffshoreWorker_Red");
			result.AddResult("ZmbM_HandymanNormal_Green");
			result.AddResult("ZmbF_MilkMaidOld_Black");
			result.AddResult("ZmbF_Clerk_Normal_Red");
			result.AddResult("ZmbM_usSoldier_normal_Woodland");
			result.AddResult("ZmbM_usSoldier_Heavy_Woodland");
			result.AddResult("ZmbM_PatrolNormal_Summer");
			result.AddResult("ZmbM_PolicemanFat");
			result.AddResult("ZmbM_ParamedicNormal_Red");
			result.AddResult("ZmbM_NBC_Yellow");
			result.AddResult("ZmbF_CitizenANormal_Brown");
			result.AddResult("ZmbF_JoggerSkinny_Blue");
			result.AddResult("ZmbF_VillagerOld_Blue");
			result.AddResult("ZmbM_JoggerSkinny_Green");
			result.AddMemoryPointSpawnLocation("sound_rainobjectinner1metal2_1");
			trap.AddDynamicTrapResult(result);

			result = new IAT_DynamicTrapResult(90, 96, 1, !persistency, !initAI, !placeOnSurface, keepHeight);
			result.AddResult("IAT_LightTrapExplosion");
			result.AddMemoryPointSpawnLocation("doorstwin1_action");
			result.AddMemoryPointSpawnLocation("doorstwin2_action");
			trap.AddDynamicTrapResult(result);

			result = new IAT_DynamicTrapResult(97, 99, 1, !persistency, !initAI, !placeOnSurface, keepHeight);
			result.AddResult("IAT_HeavyTrapExplosion");
			result.AddMemoryPointSpawnLocation("doorstwin1_action");
			result.AddMemoryPointSpawnLocation("doorstwin2_action");
			trap.AddDynamicTrapResult(result);

			result = new IAT_DynamicTrapResult(100, 100, 5, persistency, !initAI, placeOnSurface, !keepHeight);
			result.AddResult("Nailbox");
			result.AddResult("Nail");
			result.AddResult("AmmoBox_556x45_20Rnd");
			result.AddResult("AmmoBox_556x45Tracer_20Rnd");
			result.AddResult("AmmoBox_357_20Rnd");
			result.AddResult("AmmoBox_545x39_20Rnd");
			result.AddResult("AmmoBox_545x39Tracer_20Rnd");
			result.AddResult("AmmoBox_12gaFlash_10Rnd");
			result.AddResult("AmmoBox_00buck_10rnd");
			result.AddResult("AmmoBox_12gaSlug_10Rnd");
			result.AddResult("AmmoBox_762x39_20Rnd");
			result.AddResult("AmmoBox_762x54_20Rnd");
			trap.AddDynamicTrapResult(result);

			iat_DTConfig.m_DynamicTraps = new array<ref IAT_DynamicTrap>;
			iat_DTConfig.m_DynamicTraps.Insert(trap);


			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_DynamicTrapsConfig>.SaveFile(jsonConfig, iat_DTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_DynamicTrapsConfig>.LoadFile(jsonConfig, iat_DTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_DTConfig;
	}
	// ==================================================================================
	// Helpers
	// ==================================================================================
	bool IsObjectAPotentialTrap(string objectName, typename objectType)
	{
		// PrintFormat("Object Name: %1 ObjectType: %2", objectName, objectType);

		foreach (IAT_DynamicTrap trap : m_DynamicTraps)
		{
			if (trap.IsObjectTrapped(objectName))
			{
				return true;
			}
			else if (trap.IsObjectTrapped(objectType))
			{
				return true;
			}
		}
		return false;
	}

	int RollTrapChance()
	{
		return Math.RandomIntInclusive(m_MinRoll, m_MaxRoll);
	}

	IAT_DynamicTrap GetTrapResults(string objectName, typename objectType)
	{
		foreach (IAT_DynamicTrap trap : m_DynamicTraps)
		{
			if (trap.IsObjectTrapped(objectName))
			{
				return trap;
			}
			else if (trap.IsObjectTrapped(objectType))
			{
				return trap;
			}
		}
		return null;
	}

	void PrettyPrint()
	{
		Print("--[DYNAMIC TRAPS CONFIG BEGIN]");
		PrintFormat("--m_IsEnabled: %1", IsTrapsEnabled());
		PrintFormat("--m_MinRoll: %1", GetMinRoll());
		PrintFormat("--m_MaxRoll: %1", GetMaxRoll());
		Print("--[END]");
	}
	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	bool IsTrapsEnabled()
	{
		return m_IsEnabled;
	}
	void SetIsEnabled(bool newState)
	{
		m_IsEnabled = newState;
	}
	int GetMaxRoll()
	{
		return m_MaxRoll;
	}
	void SetMaxRoll(int newState)
	{
		m_MaxRoll = newState;
	}
	int GetMinRoll()
	{
		return m_MinRoll;
	}
	void SetMinRoll(int newState)
	{
		m_MinRoll = newState;
	}
};