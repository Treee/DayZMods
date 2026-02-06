class IAT_CodexCategory
{
	protected string m_CategoryName;
	protected string m_ClassNameMatch;
	protected int m_DisplayOrder;
	protected bool m_SortItems;
	protected bool m_AllowAutoGrouping;
	protected ref array<ref IAT_CodexCategory> m_SubCategories;

	void IAT_CodexCategory(string categoryName, string classNameMatch, int displayOrder, bool sortItems, bool allowAutoGroup)
	{
		m_CategoryName = categoryName;
		m_ClassNameMatch = classNameMatch;
		m_DisplayOrder = displayOrder;
		m_SortItems = sortItems;
		m_AllowAutoGrouping = allowAutoGroup
	}

	// simple implementation with no real guard rails because i dont really think anyone
	// is going to actually interface with this object on the script side... monstly json
	// this is really convenience for me to set up a "default" json for starters
	void InsertNewSubCategory(IAT_CodexCategory newCategory)
	{
		if (!m_SubCategories)
		{
			m_SubCategories = new array<ref IAT_CodexCategory>;
		}
		m_SubCategories.Insert(newCategory);
	}

	bool HasSubCategories()
	{
		if (m_SubCategories)
		{
			if (m_SubCategories.Count() > 0)
			{
				return true;
			}
		}
		return false;
	}

	bool IsFullyIgnoredType(string className)
	{
		if (className.Contains("_Open")) // ignore investor items (for now)
		{
			// ALV_Open_Shirt
			// SomeMap_Open   length - _Open   (12 - 5 = 7)
			// CannedFood_Opened length - _Opened (17 - 7 = 10)
			int subStrOpenIndex = className.IndexOf("_Open");
			int subStrOpenedIndex = className.IndexOf("_Opened");
			if (subStrOpenIndex == (className.Length() - 5))
			{
				return true;
			}
			else if (subStrOpenedIndex == (className.Length() - 7))
			{
				return true;
			}
		}
		else if (className.Contains("_Dual")) // ignore dual wield items
		{
			int subStrDualIndex = className.IndexOf("_Dual");
			if (subStrDualIndex == (className.Length() - 5))
			{
				return true;
			}

		}
		return false;
	}

	bool IsInheritedOrKindOf(string className)
	{
		// short circuit root level categories
		if (m_ClassNameMatch == "")
		{
			return false;
		}

		typename classType = className.ToType();
		typename categoryType = m_ClassNameMatch.ToType();

		// no script type so we need iskindof matching
		if (!classType)
		{
			// exact match
			if (className == m_ClassNameMatch)
			{
				// PrintFormat("ClassName: %1 matches exactly with Match: %2", className, m_ClassNameMatch);
				return true;
			}
			// is this the same kind of item?
			else if (g_Game.IsKindOf(className, m_ClassNameMatch))
			{
				// PrintFormat("ClassName: %1 is the same kind of: %2", className, m_ClassNameMatch);
				return true;
			}
		}
		else
		{
			if (classType == categoryType)
			{
				// PrintFormat("ClassType: %1 matches exactly with categoryType: %2", className, categoryType);
				return true;
			}
			else if (classType.IsInherited(categoryType))
			{
				// PrintFormat("ClassType: %1 is inherited from: %2", className, categoryType);
				return true;
			}
		}
		// no classname or type match
		return false;
	}

	string GetApplicableCategory(string cfgPath, string className)
	{
		if (IsFullyIgnoredType(className))
		{
			return "Ignored";
		}
		// PrintFormat("===================Find Applicable category: %1", className);
		string bestCategory = "";
		int bestDepth = -1;
		FindMostSpecificMatch(className, 0, bestCategory, bestDepth);

		/*
		* At this point we have checked all prior categories and this piece of clothing
		* has no script class and no inherited helper so we have to place it based
		* on where it attaches to the player.
		*/
		if (bestCategory.Contains("Other") || bestCategory == "")
		{
			string bestFitAttachment = GetBestFitAttachmentSlotName(cfgPath, className);
			// PrintFormat("needing mapping help. check attachment: %1 bestCategory: %2", bestFitAttachment, bestCategory);
			if (bestFitAttachment != "")
			{
				bestCategory = bestFitAttachment;
			}
		}

		return bestCategory;
	}
	/*
	* get the inventory slot array this className can attach to and
	* we will use the first entry to determine which category this should
	* go
	*/
	protected string GetBestFitAttachmentSlotName(string cfgPath, string className)
	{
		TStringArray inventorySlots = {};
		string propertyPath = string.Format("%1 %2 inventorySlot", cfgPath, className);
		if (g_Game.ConfigIsExisting(propertyPath))
		{
			g_Game.ConfigGetTextArray(propertyPath, inventorySlots);
			if (inventorySlots.Count() > 0)
			{
				string bestFit = inventorySlots.Get(0);
				return ReMapCategory(bestFit);
			}
		}
		return "";
	}

	protected string ReMapCategory(string raw)
	{
		if (raw == "Face")
		{
			return "Masks";
		}
		else if (raw == "ALV_Skull")
		{
			return "Pelts";
		}
		else if (raw == "weaponButtstockM4")
		{
			return "Buttstocks";
		}
		else if (raw == "weaponButtstockAK")
		{
			return "Buttstocks";
		}
		else if (raw == "weaponButtstockAK")
		{
			return "Custom_Stock";
		}
		else if (raw == "weaponHandguardM4")
		{
			return "Handguards";
		}
		else if (raw == "weaponHandguardAK")
		{
			return "Handguards";
		}
		else if (raw == "Custom_HandGuard")
		{
			return "Handguards";
		}
		else if (raw == "Assault_HelmetCover")
		{
			return "Accessories";
		}
		else if (raw == "Shoulder")
		{
			return "Accessories";
		}
		else if (raw == "Custom_Barrel_Att")
		{
			return "Suppressors";
		}
		return raw;
	}

	protected string GetManualMapping(string className)
	{
		// if (className.Contains("_Kit"))
		// {
		// 	return "Kits";
		// }
		return "";
	}

	protected void FindMostSpecificMatch(string className, int depth, out string bestCategory, out int bestDepth)
	{
		if (IsInheritedOrKindOf(className))
		{
			bestCategory = GetCategoryName();
			bestDepth = depth;
			// PrintFormat("found match for: %1 category: %2 depth: %3", className, bestCategory, bestDepth);
		}

		if (!HasSubCategories())
		{
			// Print("has no more sub categories and hasnt matched. dead end");
			return;
		}

		foreach (IAT_CodexCategory subCategory : m_SubCategories)
		{
			// PrintFormat("check category: %1", subCategory.GetCategoryName());
			if (!subCategory)
			{
				// Print("no category... how did we get here, short circuit..")
				continue;
			}

			string subBestCategory = bestCategory;
			int subBestDepth = bestDepth;
			// recurse into the next set of sub categories
			subCategory.FindMostSpecificMatch(className, depth + 1, subBestCategory, subBestDepth);

			if (subBestDepth > bestDepth)
			{
				bestDepth = subBestDepth;
				bestCategory = subBestCategory;
				// PrintFormat("found better match: %1 better Depth: %2", bestCategory, bestDepth);
			}
		}
	}

	// =========================================== GETTERS & SETTERS
	bool ShouldSortItems()
	{
		return m_SortItems;
	}
	string GetCategoryName()
	{
		return m_CategoryName;
	}
	array<ref IAT_CodexCategory> GetSubCategories()
	{
		if (!m_SubCategories)
		{
			m_SubCategories = new array<ref IAT_CodexCategory>;
		}
		return m_SubCategories;
	}
};