class IAT_FacePaintsConfig
{
	protected string m_DayZFolder = "$profile:";
    protected string m_RootConfigFolder = "ItsATreeMods";
    protected string m_JsonFile = "FacePaintsConfig.json";

	protected float m_PaintStickDamagePerUse;

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
};