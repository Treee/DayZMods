class IAT_SmeltingRecipe
{
	protected string m_ResultClassName;		// the classname of the object to spawn
	protected float m_ResultHp;				// the hp the object should spawn with. 0-1
	protected int m_ResultQuantity;			// the quantity to spawn the item with
	protected int m_RequiredTemperature;	// this will enforce accelerants for higher tier without needing to explicitly list which accelerants are expected
	protected string m_RequiredOre1;		// the expected ore1
	protected string m_RequiredOre2;		// the expected ore2

	void IAT_SmeltingRecipe(string name, string reqOre1, string reqOre2, float hp, int quantity, int reqTemp)
	{
		m_ResultClassName = name;
		m_RequiredOre1 = reqOre1;
		m_RequiredOre2 = reqOre2;
		m_ResultHp = hp;
		m_ResultQuantity = quantity;
		m_RequiredTemperature = reqTemp;
	}

	bool CanCraft(string ore1, string ore2, int currentTemp)
	{
		bool hasRequiredOre1 = false;
		bool hasRequiredOre2 = false;
		bool isRequiredTemp = false;
		// if ore1 has no requirement or we have what is expected
		if (m_RequiredOre1 == "" || ore1 == m_RequiredOre1)
		{
			hasRequiredOre1 = true;
		}
		// if ore1 has no requirement or we have what is expected
		if (m_RequiredOre2 == "" || ore2 == m_RequiredOre2)
		{
			hasRequiredOre2 = true;
		}
		if (m_RequiredTemperature < currentTemp)
		{
			isRequiredTemp = true;
		}

		if (hasRequiredOre1 && hasRequiredOre2 && isRequiredTemp)
		{
			return true;
		}
		return false;
	}
	string GetResultClassName()
	{
		return m_ResultClassName;
	}
	float GetResultHp()
	{
		return m_ResultHp;
	}
	int GetResultQuantity()
	{
		return m_ResultQuantity;
	}
	string PrettyPrint()
	{
		return string.Format("Result: %1 Hp: %2 Quantity: %3 Temp: %4 Ore1: %5 Ore2: %6", m_ResultClassName, m_ResultHp, m_ResultQuantity, m_RequiredTemperature, m_RequiredOre1, m_RequiredOre2);
	}
};