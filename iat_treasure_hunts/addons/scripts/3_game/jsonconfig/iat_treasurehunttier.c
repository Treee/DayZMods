class IAT_TreasureHuntTier
{
	protected int m_IAT_TierValue; // index of the tier. 0 is the lowest tier. no support for negatives
	protected int m_IAT_MinNumItems;
	protected int m_IAT_MaxNumItems;
	protected float m_IAT_LootChanceMultiplier; // the chance of critical roll to get better tier loot
	protected string m_IAT_RollTableName;
	protected ref TStringArray m_IAT_ContainerOptions; // the list of containers that can be spawned to hold the loot

	void IAT_TreasureHuntTier(int tierValue, int min, int max, float multiplier, string rollTable)
	{
		m_IAT_TierValue = tierValue;
		m_IAT_MinNumItems = min;
		m_IAT_MaxNumItems = max;
		m_IAT_LootChanceMultiplier = multiplier;
		m_IAT_RollTableName = rollTable;
	}

	TStringArray IAT_GetContainerOptions()
	{
		if (!m_IAT_ContainerOptions)
		{
			m_IAT_ContainerOptions = {};
		}
		return m_IAT_ContainerOptions;
	}

	void IAT_InsertNewContainerOption(string containerType)
	{
		if (!m_IAT_ContainerOptions)
		{
			m_IAT_ContainerOptions = {};
		}
		// if the value does not exist
		if (m_IAT_ContainerOptions.Find(containerType) == -1)
		{
			// insert it
			m_IAT_ContainerOptions.Insert(containerType);
		}
	}

	string GetRandomBuriableContainer()
	{
		return m_IAT_ContainerOptions.GetRandomElement();
	}
	string GetRollTable()
	{
		return m_IAT_RollTableName;
	}
	int GetNumItemsToSpawn()
	{
		return Math.RandomIntInclusive(m_IAT_MinNumItems, m_IAT_MaxNumItems);
	}

	void PrettyPrint()
	{
		Print("--[IAT_TreasureHuntTier BEGIN]");
		PrintFormat("----m_IAT_TierValue: %1", m_IAT_TierValue);
		PrintFormat("----m_IAT_LootChanceMultiplier: %1", m_IAT_LootChanceMultiplier);
		PrintFormat("----m_IAT_RollTableName: %1", m_IAT_RollTableName);
		string containers = "";
		foreach(string s : m_IAT_ContainerOptions)
		{
			containers = string.Format("%1, ", s);
		}
		PrintFormat("----m_IAT_ContainerOptions: %1", containers);
		Print("--[IAT_TreasureHuntTier END]");
	}
};