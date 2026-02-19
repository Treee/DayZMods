class IAT_BuildingRequirements
{
	protected bool m_IsLastStage;
	protected ref TStringArray m_AllowedTools;
	protected ref array<ref IAT_BuildingRequiredItems> m_RequiredItems;

	void IAT_BuildingRequirements(bool lastStage = false)
	{
		m_IsLastStage = lastStage;
	}

	//================================================== GETTERS & SETTERS
	void SetLastStage(bool isLastStage)
	{
		m_IsLastStage = isLastStage;
	}
	bool IsLastStage()
	{
		return m_IsLastStage;
	}
	void SetAllowedTools(TStringArray allowedTools)
	{
		m_AllowedTools = allowedTools;
	}
	TStringArray GetAllowedTools()
	{
		return m_AllowedTools;
	}
	bool HasAllowedTool(string toolName)
	{
		if (!m_AllowedTools)
		{
			return false;
		}
		foreach(string tool : m_AllowedTools)
		{
			if (tool == toolName)
			{
				return true;
			}
		}
		return false;
	}
	array<ref IAT_BuildingRequiredItems> GetRequiredItems()
	{
		return m_RequiredItems;
	}
	void AddRequiredItem(IAT_BuildingRequiredItems requiredItem)
	{
		if (!m_RequiredItems)
		{
			m_RequiredItems = new array<ref IAT_BuildingRequiredItems>;
		}
		m_RequiredItems.Insert(requiredItem);
	}
	//================================================== HELPERS
	int GetRequiredQuantity(string className)
	{
		if (!m_RequiredItems)
		{
			return -1;
		}
		foreach (IAT_BuildingRequiredItems requiredItem : m_RequiredItems)
		{
			if (requiredItem.IsRequiredClassName(className))
			{
				return requiredItem.GetRequiredQuantity();
			}
		}
		return -1;
	}
	bool HasRequiredItemsAndQuantities(IAT_BuildingRequirements materialsOnGround)
	{
		// No requirements means the craft is always valid.
		if (!HasRequiredMaterials())
			return true;

		// If we have requirements but no materials list, the craft cannot succeed.
		if (!materialsOnGround.HasRequiredMaterials())
			return false;

		array<ref IAT_BuildingRequiredItems> groundMaterials = materialsOnGround.GetRequiredItems();
		int totalQuantityOnGround = 0;
		// For each required item, ensure there is a matching item on the ground with enough quantity.
		// Extra/non-required items on the ground are ignored.
		foreach (IAT_BuildingRequiredItems requiredItem : m_RequiredItems)
		{
			// PrintFormat("required item: %1 quantity: %2", requiredItem.GetRequiredItemName(), requiredItem.GetRequiredQuantity());
			totalQuantityOnGround = 0;
			foreach (IAT_BuildingRequiredItems itemOnGround : groundMaterials)
			{
				// PrintFormat("checking actual item: %1 quantity: %2", itemOnGround.GetRequiredItemName(), itemOnGround.GetRequiredQuantity());
				if (requiredItem.IsRequiredClassName(itemOnGround.GetRequiredItemName()))
				{
					// sum the same items on the ground
					totalQuantityOnGround += itemOnGround.GetRequiredQuantity();
					// PrintFormat("sum of items: %1", totalQuantityOnGround);
				}
			}
			// if the total on ground is not enough this craft fails here
			if (totalQuantityOnGround < requiredItem.GetRequiredQuantity())
			{
				// PrintFormat("sum: %1 required: %2", totalQuantityOnGround, requiredItem.GetRequiredQuantity());
				return false; // short circuit
			}
		}
		// by this point, all required items are check and they have proper ingredients/quantities
		return true;
	}
	bool HasRequiredMaterials()
	{
		if (!m_RequiredItems)
		{
			return false;
		}
		if (m_RequiredItems.Count() == 0)
		{
			return false;
		}
		return true;
	}
	void PrettyPrint()
	{
		PrintFormat("--m_IsLastStage: %1", m_IsLastStage);
		foreach (string allowedTool : m_AllowedTools)
		{
			PrintFormat("--allowedTool: %1", allowedTool);
		}
		foreach(IAT_BuildingRequiredItems requiredItem : m_RequiredItems)
		{
			requiredItem.PrettyPrint();
		}
	}
};