class IAT_SmokeSignalsConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "SmokeSignalsConfig.json";

	protected float m_IAT_GrenadeParticleScaleMin;
	protected float m_IAT_SignalParticleScaleMin;
	protected float m_IAT_GrenadeParticleScaleMax;
	protected float m_IAT_SignalParticleScaleMax;

	protected bool m_IAT_SmokeGrenadesEnabled;
	protected bool m_IAT_SmokeSignalsEnabled;

	IAT_SmokeSignalsConfig TryGetSmokeSignalsConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_SmokeSignalsConfig iat_SSConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_SSConfig = new IAT_SmokeSignalsConfig();
			// set some default values
			iat_SSConfig.m_IAT_SmokeSignalsEnabled = true;
			iat_SSConfig.m_IAT_GrenadeParticleScaleMin = 2.5;
			iat_SSConfig.m_IAT_GrenadeParticleScaleMax = 5.0;
			iat_SSConfig.m_IAT_SmokeGrenadesEnabled = true;
			iat_SSConfig.m_IAT_SignalParticleScaleMin = 2.5;
			iat_SSConfig.m_IAT_SignalParticleScaleMax = 5.0;

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_SmokeSignalsConfig>.SaveFile(jsonConfig, iat_SSConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_SmokeSignalsConfig>.LoadFile(jsonConfig, iat_SSConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_SSConfig;
	}

	// ================================================================================== HELPERS
	float GetSmokeSignalParticleScaleMin()
	{
		return m_IAT_SignalParticleScaleMin;
	}
	float GetSmokeSignalParticleScaleMax()
	{
		return m_IAT_SignalParticleScaleMax;
	}
	float GetSmokeGrenadeParticleScaleMin()
	{
		return m_IAT_GrenadeParticleScaleMin;
	}
	float GetSmokeGrenadeParticleScaleMax()
	{
		return m_IAT_GrenadeParticleScaleMax;
	}
	bool IsSmokeSignalsEnabled()
	{
		return m_IAT_SmokeSignalsEnabled;
	}
	bool IsSmokeGrenadesEnabled()
	{
		return m_IAT_SmokeGrenadesEnabled;
	}

	void PrettyPrint()
	{
		Print("--[IAT_SmokeSignalsConfig BEGIN]");
		PrintFormat("----m_IAT_SignalParticleScaleMin: %1", GetSmokeSignalParticleScaleMin());
		PrintFormat("----m_IAT_GrenadeParticleScaleMin: %1", GetSmokeGrenadeParticleScaleMin());
		PrintFormat("----m_IAT_SignalParticleScaleMax: %1", GetSmokeSignalParticleScaleMax());
		PrintFormat("----m_IAT_GrenadeParticleScaleMax: %1", GetSmokeGrenadeParticleScaleMax());
		PrintFormat("----m_IAT_SmokeSignalsEnabled: %1", IsSmokeSignalsEnabled());
		PrintFormat("----m_IAT_SmokeGrenadesEnabled: %1", IsSmokeGrenadesEnabled());
		Print("--[IAT_SmokeSignalsConfig END]");
	}
};