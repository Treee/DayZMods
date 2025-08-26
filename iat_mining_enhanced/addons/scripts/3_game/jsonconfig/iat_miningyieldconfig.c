// Config for handling where the circle is m_Centered, its m_Radius (how big the circle is), and the m_Intensity of ore to spawn
class IAT_OreYieldAreaConfig
{
    protected vector m_Center;
    protected float m_Radius;
    protected float m_Intensity; // 1 by default. percentage number multiplied by the yield chance to increase chance to create an object

    void IAT_OreYieldAreaConfig(vector center, float radius, float intensity)
    {
        m_Center = center;
        m_Radius = radius;
        m_Intensity = intensity;
    }

	//========================================================= CUSTOM
	float GetYieldChance(vector junctionPosition, float minChance)
	{
		// get the distance from the center
		float dist = vector.Distance(m_Center, junctionPosition);
		// with the center being 1 for maximum intensity, clamp the value and subtract 1
		// this way being on the radius gives us 0 additional chance
    	float chance = 1.0 - Math.Clamp(dist / m_Radius, 0.0, 1.0);
		// multiply by intensity.
		chance *= m_Intensity;
		// make sure we dont fall below min chance
		return Math.Max(chance, minChance);
	}

	//========================================================= HELPERS
	void PrettyPrint()
	{
		PrintFormat("----m_Center: %1", m_Center);
		PrintFormat("----m_Radius: %1", m_Radius);
		PrintFormat("----m_Intensity: %1", m_Intensity);
	}
	//========================================================= GETTERS & SETTERS
	vector GetCenter()
	{
		return m_Center;
	}
	float GetRadius()
	{
		return m_Radius;
	}
	float GetIntensity()
	{
		return m_Intensity;
	}
};

// holds a list of points relative to a single ore type
class IAT_OreYieldAreaList
{
	protected string m_OreType;
    protected ref array<ref IAT_OreYieldAreaConfig> m_OreYieldList;

    void IAT_OreYieldAreaList(string oreType)
    {
		m_OreType = oreType;
    }
	//========================================================= CUSTOM
    void AddOreYieldPoint(vector m_Center, float m_Radius, float m_Intensity)
    {
		if (!m_OreYieldList)
			m_OreYieldList = new array<ref IAT_OreYieldAreaConfig>();

        m_OreYieldList.Insert(new IAT_OreYieldAreaConfig(m_Center, m_Radius, m_Intensity));
    }
    IAT_OreYieldAreaConfig GetOreYieldConfigByBestFit(vector junctionPosition)
    {
		float distance = 9999999;
		float smallestDistance = 999999;
		IAT_OreYieldAreaConfig smallestDistanceConfig;
		// loop through the ore yield list
		foreach (IAT_OreYieldAreaConfig oreYieldConfig : m_OreYieldList)
		{
			// find the config that has the smallest distance
			distance = vector.Distance(oreYieldConfig.GetCenter(), junctionPosition);
			if (distance < smallestDistance)
			{
				smallestDistance = distance;
				smallestDistanceConfig = oreYieldConfig;
			}
		}
		// return this ore config
		return smallestDistanceConfig;
    }
	//========================================================= HELPERS
	bool IsOreType(string potentialOre)
	{
		potentialOre.ToLower();
		return m_OreType == potentialOre;
	}
	string GetOreType()
	{
		return m_OreType;
	}
	void PrettyPrint()
	{
		Print("----[ORE YIELD AREA LIST]");
		PrintFormat("----OreType: %1", GetOreType());
		foreach (IAT_OreYieldAreaConfig oreYieldConfig : m_OreYieldList)
		{
			oreYieldConfig.PrettyPrint();
		}
	}
};

// holds all the ores lists of yields. allows a junction to figure out what its specific ore chances should be
class IAT_OreYieldManager
{
	protected ref TStringArray m_OreTypes;
	protected ref array<ref IAT_OreYieldAreaList> m_OreYields;

	//========================================================= HELPERS
	void InsertOreYieldList(IAT_OreYieldAreaList oreList)
	{
		if (!m_OreYields)
			m_OreYields = new array<ref IAT_OreYieldAreaList>();

		m_OreYields.Insert(oreList);
	}
	void InsertOreType(string oreType)
	{
		if (!m_OreTypes)
			m_OreTypes = new TStringArray();

		m_OreTypes.Insert(oreType);
	}
	IAT_OreYieldAreaConfig GetOreYieldConfigByBestFit(string oreType, vector junctionPosition)
	{
		foreach (IAT_OreYieldAreaList oreYieldArea : m_OreYields)
		{
			if (oreYieldArea.IsOreType(oreType))
			{
				return oreYieldArea.GetOreYieldConfigByBestFit(junctionPosition);
			}
		}
		return null;
	}
	/*
	* getting an array and then filling it seems more difficult than you would expect
	* this is here to help hint that the array should be this big. if you find yourself
	* having chance issues might need to increase this list
	*/
	TFloatArray GetEmptyOreChanceArray()
	{
		return {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	}
	TFloatArray GetJunctionOreChancesByPosition(vector junctionPosition, float minChance)
	{
		TFloatArray oreChances = GetEmptyOreChanceArray();
		IAT_OreYieldAreaConfig oreYieldArea;
		float oreYieldChance = -1;
		// foreach ore type that exists
		foreach (int index, string oreType : m_OreTypes)
		{
			// if we find a patch of ore in the area
			if (Class.CastTo(oreYieldArea, GetOreYieldConfigByBestFit(oreType, junctionPosition)))
			{
				oreYieldChance = oreYieldArea.GetYieldChance(junctionPosition, minChance);
			}
			else
			{	// use a default value.
				oreYieldChance = minChance;
			}
			oreChances.Set(index, oreYieldChance);
		}
		return oreChances;
	}
	string GetOreTypeByIndex(int index)
	{
		if (m_OreTypes.IsValidIndex(index))
		{
			return m_OreTypes.Get(index);
		}
		return "";
	}
	void PrettyPrint()
	{
		Print("----[ORE YIELD MANAGER]");
		foreach(string oreType : m_OreTypes)
		{
			PrintFormat("----OreType: %1", oreType);
		}
		foreach (IAT_OreYieldAreaList oreYieldArea : m_OreYields)
		{
			oreYieldArea.PrettyPrint();
		}
	}
};