class IAT_BuildingRequiredItems
{
	protected string m_RequiredItemClassName;
	protected int m_RequiredItemQuantity;

	void IAT_BuildingRequiredItems(string requiredItem, int requiredQuantity)
	{
		m_RequiredItemClassName = requiredItem;
		m_RequiredItemQuantity = requiredQuantity;
	}

	bool IsRequiredItem(IAT_BuildingRequiredItems otherItem)
	{
		if (IsRequiredClassName(otherItem.GetRequiredItemName()))
		{
			if (HasEnoughQuantity(otherItem.GetRequiredQuantity()))
			{
				return true;
			}
		}
		return false;
	}
	bool IsRequiredClassName(string className)
	{
		return m_RequiredItemClassName == className;
	}
	bool HasEnoughQuantity(int amount)
	{
		return amount >= m_RequiredItemQuantity;
	}
	string GetRequiredItemName()
	{
		return m_RequiredItemClassName;
	}
	int GetRequiredQuantity()
	{
		return m_RequiredItemQuantity;
	}

	void PrettyPrint()
	{
		PrintFormat("m_RequiredItemClassName: %1", m_RequiredItemClassName);
		PrintFormat("m_RequiredItemQuantity: %1", m_RequiredItemQuantity);
	}
};