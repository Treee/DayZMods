class IAT_PoweredRadioTowerConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$profile:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "PoweredRadioTowerConfig.json";

	protected int m_RangeDefault; // Default: 5000meters (vanilla)
	protected int m_RangeMin; // Default: 50 meters (shortest config defined radio range in this mod)
	protected int m_RangeMax; // Default: 17000 meters (longest config defined radio range in this mod)
	protected int m_ExponentialScale; // Default: 200; Arbitrary number for smoothing the multiplicative growth
	// The number represents the shortest time period the energy can last at full consumption
	protected int m_EnergyConsumptionTimeMin; // Default: 3 minutes 3 * 60 = 180 seconds
	// The number represents the longest time period the energy can last at lowest consumption
	protected int m_EnergyConsumptionTimeMax; // Default: 8hours 8 * 60 * 60 = 28800 seconds

	protected float m_DefaultEnergyUsage; // Default: 0.01 energy consumption per second (vanilla)
	protected float m_DefaultTotalEnergy; // Default: 50 units (vanilla)

	// These four values are precalculated based on the above
	protected float m_EnergyMin; // Energy use at 50m; lowest range
	protected float m_EnergyMax; // Energy use at 17000m; max  range
	protected float m_LinearDecreaseRate; // linear decrease rate below m_RangeDefault meters
	protected float m_MultiplicativeGrowthConstant; // multiplicative growth rate above m_RangeDefault meters

	IAT_PoweredRadioTowerConfig TryGetPoweredRadioTowerConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_PoweredRadioTowerConfig iat_DRConfig;
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// new config object
			iat_DRConfig = new IAT_PoweredRadioTowerConfig();
			// set some default values
			iat_DRConfig.SetDefaultRange(5000);
			iat_DRConfig.SetMinRange(50);
			iat_DRConfig.SetMaxRange(17000);
			iat_DRConfig.SetExponentialScale(200);
			iat_DRConfig.SetMinConsumptionTime(180);
			iat_DRConfig.SetMaxConsumptionTime(28800);
			iat_DRConfig.SetDefaultEnergyUsage(0.01);
			iat_DRConfig.SetDefaultTotalEnergy(50);
			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_PoweredRadioTowerConfig>.SaveFile(jsonConfig, iat_DRConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_PoweredRadioTowerConfig>.LoadFile(jsonConfig, iat_DRConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		iat_DRConfig.InitPreComputedValues();
		// return what we found
        return iat_DRConfig;
	}

	// Solves for the exponential growth constant k2 given:
	// - max energy use at max range (E_max)
	// - baseline energy use at 5000m (E0)
	// - maximum range (rangeMax)
	// - scale factor (s)
	// dayz doesnt have Math.Log (non base 2 log functions) so we precalculated k2 on paper

	// float SolveK2(float E_max, float E0, float rangeMax, float s)
	// {
	// 	float rangeDelta = rangeMax - 5000.0;
	// 	if (rangeDelta <= 0 || E_max <= E0)
	// 		return 0.0;  // Invalid inputs or no growth needed

	// 	float exponent = Math.Log(E_max / E0);
	// 	float k2 = Math.Exp(exponent / (rangeDelta / s)) - 1.0;
	// 	return k2;
	// }

	void InitPreComputedValues()
	{
		// energy use at lowest range for the longest time duraton
		m_EnergyMin = m_DefaultTotalEnergy / m_EnergyConsumptionTimeMax;
		// energy use at max range for the longest time duraton
		m_EnergyMax = m_DefaultTotalEnergy / m_EnergyConsumptionTimeMin;
		m_LinearDecreaseRate = (m_DefaultEnergyUsage - m_EnergyMin) / (m_RangeDefault - m_RangeMin);
		// solved on paper.
		m_MultiplicativeGrowthConstant = 0.064085;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	void SetDefaultRange(int value)
	{
		m_RangeDefault = value;
	}
	int GetDefaultRange()
	{
		return m_RangeDefault;
	}
	void SetMinRange(int value)
	{
		m_RangeMin = value;
	}
	int GetMinRange()
	{
		return m_RangeMin;
	}
	void SetMaxRange(int value)
	{
		m_RangeMax = value;
	}
	int GetMaxRange()
	{
		return m_RangeMax;
	}
	void SetExponentialScale(int value)
	{
		m_ExponentialScale = value;
	}
	int GetExponentialScale()
	{
		return m_ExponentialScale;
	}
	void SetMinConsumptionTime(int value)
	{
		m_EnergyConsumptionTimeMin = value;
	}
	int GetMinConsumptionTime()
	{
		return m_EnergyConsumptionTimeMin;
	}
	void SetMaxConsumptionTime(int value)
	{
		m_EnergyConsumptionTimeMax = value;
	}
	int GetMaxConsumptionTime()
	{
		return m_EnergyConsumptionTimeMax;
	}
	void SetDefaultEnergyUsage(float value)
	{
		m_DefaultEnergyUsage = value;
	}
	float GetDefaultEnergyUsage()
	{
		return m_DefaultEnergyUsage;
	}
	void SetDefaultTotalEnergy(float value)
	{
		m_DefaultTotalEnergy = value;
	}
	float GetDefaultTotalEnergy()
	{
		return m_DefaultTotalEnergy;
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	// returns an energy consumption value relative to the broadcast range of a given radio
	// the linear decrease is an incentive to run radios at lower range to get more battery life
	// the exponential decrease is a disincentive to run radios at longer ranges by draining battery faster
	/*
	* since we cannot modify the amount of consumed energy per `OnWork`, this function returns the delta
	* that needs to be appended to the energy source of the radio. since t he linear decrease effectively
	* elongates the energy source from the default range (5000) we need to ADD this value back to the energy
	* source. The opposite is true for greater than 5000 where we remove MORE energy from the source than the default.
	*/
	float GetEnergyDelta(float radioRange)
	{
		float energyDelta = 0.0;
		// linear consumption below default range
		if (radioRange <= GetDefaultRange())
		{
			energyDelta = -m_LinearDecreaseRate * (GetDefaultRange() - radioRange);
		}
		else// multiplicative consumption above default range
		{
			float number = 1.0 + m_MultiplicativeGrowthConstant;
			float exponent = (radioRange - GetDefaultRange()) / GetExponentialScale();
			energyDelta = GetDefaultEnergyUsage() * (Math.Pow(number, exponent) - 1.0);
		}
		return energyDelta;
	}

	void PrettyPrint()
	{
		Print("--[POWERED RADIO TOWER CONFIG BEGIN]");
		PrintFormat("--m_RangeDefault: %1", GetDefaultRange());
		PrintFormat("--m_RangeMin: %1", GetMinRange());
		PrintFormat("--m_RangeMax: %1", GetMaxRange());
		PrintFormat("--m_ExponentialScale: %1", GetExponentialScale());
		PrintFormat("--m_EnergyConsumptionTimeMin: %1", GetMinConsumptionTime());
		PrintFormat("--m_EnergyConsumptionTimeMax: %1", GetMaxConsumptionTime());
		PrintFormat("--m_DefaultEnergyUsage: %1", GetDefaultEnergyUsage());
		PrintFormat("--m_DefaultTotalEnergy: %1", GetDefaultTotalEnergy());
		Print("--[END]");
	}
};