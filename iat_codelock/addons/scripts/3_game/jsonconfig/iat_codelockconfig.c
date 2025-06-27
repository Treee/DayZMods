class IAT_CodelockConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "CodelockConfig.json";


	protected bool m_SaveToDatabase; // save codelock data to the database
	protected bool m_ShowHpOnCodelock; // show codelock health on the codelock item
	protected bool m_CanAttachCodelockToBaseBuilding; // can codelocks be attached to base building items
	protected bool m_CanAttachCodelockToTents; // can codelocks be attached to tents
	protected bool m_CanAttachCodelockToContainers; // can codelocks be attached to containers
	protected bool m_DamagePlayerOnFailedPasscodeEntry; // damage player on failed passcode entry
	protected bool m_ClearAllPasscodeEntriesOnInterval; // clear all passcode entries on interval
	protected int m_DamagePerFailedPasscodeEntry; // damage per failed passcode entry
	protected int m_MaxPasscodeEntriesPerInterval; // max passcode entries per interval
	protected int m_MaxPasscodeEntriesCooldown; // cooldown in seconds for passcode entries

	protected ref array<ref IAT_CodelockRaidTool> m_RaidTools; // the raid tools that can be used on codelocks

	IAT_CodelockConfig TryGetCodelockConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_CodelockConfig iat_CLConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_CLConfig = new IAT_CodelockConfig();
			// set some default values
			iat_CLConfig.m_SaveToDatabase = true;
			iat_CLConfig.m_ShowHpOnCodelock = true;
			iat_CLConfig.m_CanAttachCodelockToBaseBuilding = true;
			iat_CLConfig.m_CanAttachCodelockToTents = true;
			iat_CLConfig.m_CanAttachCodelockToContainers = false;
			iat_CLConfig.m_DamagePlayerOnFailedPasscodeEntry = true;
			iat_CLConfig.m_ClearAllPasscodeEntriesOnInterval = true;
			iat_CLConfig.m_DamagePerFailedPasscodeEntry = 20;
			iat_CLConfig.m_MaxPasscodeEntriesPerInterval = 5;
			iat_CLConfig.m_MaxPasscodeEntriesCooldown = 600;
			iat_CLConfig.m_RaidTools = new array<ref IAT_CodelockRaidTool>();

			iat_CLConfig.m_RaidTools.Insert(new IAT_CodelockRaidTool("Hacksaw", 10, 250, 20, true));
			iat_CLConfig.m_RaidTools.Insert(new IAT_CodelockRaidTool("Crowbar", 15, 150, 60, false));
			iat_CLConfig.m_RaidTools.Insert(new IAT_CodelockRaidTool("IAT_RaidHacksaw_Admin", 0, 1500, 2, true));
			iat_CLConfig.m_RaidTools.Insert(new IAT_CodelockRaidTool("IAT_RaidHacksaw_Colorbase", 10, 250, 20, true));

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_CodelockConfig>.SaveFile(jsonConfig, iat_CLConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_CodelockConfig>.LoadFile(jsonConfig, iat_CLConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_CLConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	bool CanSaveCodelockDataToDatabase()
	{
		return m_SaveToDatabase;
	}
	void SetSaveCodelockDataToDatabase(bool saveToDatabase)
	{
		m_SaveToDatabase = saveToDatabase;
	}
	bool CanShowCodelockHealth()
	{
		return m_ShowHpOnCodelock;
	}
	void SetShowCodelockHealth(bool showHpOnCodelock)
	{
		m_ShowHpOnCodelock = showHpOnCodelock;
	}
	bool CanAttachCodelockToBaseBuilding()
	{
		return m_CanAttachCodelockToBaseBuilding;
	}
	void SetAttachCodelockToBaseBuilding(bool canAttachCodelockToBaseBuilding)
	{
		m_CanAttachCodelockToBaseBuilding = canAttachCodelockToBaseBuilding;
	}
	bool CanAttachCodelockToTents()
	{
		return m_CanAttachCodelockToTents;
	}
	void SetAttachCodelockToTents(bool canAttachCodelockToTents)
	{
		m_CanAttachCodelockToTents = canAttachCodelockToTents;
	}
	bool CanAttachCodelockToContainers()
	{
		return m_CanAttachCodelockToContainers;
	}
	void SetAttachCodelockToContainers(bool canAttachCodelockToContainers)
	{
		m_CanAttachCodelockToContainers = canAttachCodelockToContainers;
	}
	bool CanDamagePlayerOnFailedPasscodeEntry()
	{
		return m_DamagePlayerOnFailedPasscodeEntry;
	}
	void SetDamagePlayerOnFailedPasscodeEntry(bool damagePlayerOnFailedPasscodeEntry)
	{
		m_DamagePlayerOnFailedPasscodeEntry = damagePlayerOnFailedPasscodeEntry;
	}
	bool CanClearAllPasscodeEntriesOnInterval()
	{
		return m_ClearAllPasscodeEntriesOnInterval;
	}
	void SetClearAllPasscodeEntriesOnInterval(bool clearAllPasscodeEntriesOnInterval)
	{
		m_ClearAllPasscodeEntriesOnInterval = clearAllPasscodeEntriesOnInterval;
	}
	int GetDamagePerFailedPasscodeEntry()
	{
		return m_DamagePerFailedPasscodeEntry;
	}
	void SetDamagePerFailedPasscodeEntry(int damagePerFailedPasscodeEntry)
	{
		m_DamagePerFailedPasscodeEntry = damagePerFailedPasscodeEntry;
	}
	int GetMaxPasscodeEntriesPerInterval()
	{
		return m_MaxPasscodeEntriesPerInterval;
	}
	void SetMaxPasscodeEntriesPerInterval(int maxPasscodeEntriesPerInterval)
	{
		m_MaxPasscodeEntriesPerInterval = maxPasscodeEntriesPerInterval;
	}
	int GetMaxPasscodeEntriesCooldown()
	{
		return m_MaxPasscodeEntriesCooldown;
	}
	void SetMaxPasscodeEntriesCooldown(int maxPasscodeEntriesCooldown)
	{
		m_MaxPasscodeEntriesCooldown = maxPasscodeEntriesCooldown;
	}
	array<ref IAT_CodelockRaidTool> GetRaidTools()
	{
		if (!m_RaidTools)
		{
			m_RaidTools = new array<ref IAT_CodelockRaidTool>();
		}
		return m_RaidTools;
	}
	// ================================================================================== HELPERS
	void PrettyPrint()
	{
		Print("--[IAT_CodelockConfig BEGIN]");
		PrintFormat("--m_SaveToDatabase: %1", m_SaveToDatabase);
		PrintFormat("--m_ShowHpOnCodelock: %1", m_ShowHpOnCodelock);
		PrintFormat("--m_CanAttachCodelockToBaseBuilding: %1", m_CanAttachCodelockToBaseBuilding);
		PrintFormat("--m_CanAttachCodelockToTents: %1", m_CanAttachCodelockToTents);
		PrintFormat("--m_CanAttachCodelockToContainers: %1", m_CanAttachCodelockToContainers);
		PrintFormat("--m_DamagePlayerOnFailedPasscodeEntry: %1", m_DamagePlayerOnFailedPasscodeEntry);
		PrintFormat("--m_ClearAllPasscodeEntriesOnInterval: %1", m_ClearAllPasscodeEntriesOnInterval);
		PrintFormat("--m_DamagePerFailedPasscodeEntry: %1", m_DamagePerFailedPasscodeEntry);
		PrintFormat("--m_MaxPasscodeEntriesPerInterval: %1", m_MaxPasscodeEntriesPerInterval);
		PrintFormat("--m_MaxPasscodeEntriesCooldown: %1", m_MaxPasscodeEntriesCooldown);
		foreach (IAT_CodelockRaidTool tool : m_RaidTools)
		{
			tool.PrettyPrint();
		}
		Print("--[IAT_CodelockConfig END]");
	}
};