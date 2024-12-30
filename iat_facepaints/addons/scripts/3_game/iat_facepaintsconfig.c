class IAT_FacePaintsConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "FacePaintsConfig.json";
	[NonSerialized()]
	protected ref IAT_FacePaintOptions m_FacePaintOptions;

	protected float m_PaintStickDamagePerUse;
	protected bool m_SavePlayerPaintsToDatabase;

	IAT_FacePaintsConfig TryGetFacePaintConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		IAT_FacePaintsConfig iat_FPConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_FPConfig = new IAT_FacePaintsConfig();
			// set some default values
			iat_FPConfig.SetPaintStickDamagePerUse(2.0);
			// write the file to "create it"
			JsonFileLoader<ref IAT_FacePaintsConfig>.JsonSaveFile(jsonConfig, iat_FPConfig);
		}
		else
		{
			// file exists, just load it from disk
			JsonFileLoader<ref IAT_FacePaintsConfig>.JsonLoadFile(jsonConfig, iat_FPConfig);
		}
		// configure paint options (auto generated file. moddable for others)
		m_FacePaintOptions = new IAT_FacePaintOptions();
		// return what we found
        return iat_FPConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	void SetPaintStickDamagePerUse(float value)
	{
		m_PaintStickDamagePerUse = value;
	}

	float GetPaintStickDamagerPerUse()
	{
		return m_PaintStickDamagePerUse;
	}

	void SetSavePlayerPaintsToDatabase(bool value)
	{
		m_SavePlayerPaintsToDatabase = value;
	}

	bool GetSavePlayerPaintsToDatabase()
	{
		return m_SavePlayerPaintsToDatabase;
	}

	IAT_FacePaintOptions GetFacePaintOptions()
	{
		return m_FacePaintOptions;
	}
};