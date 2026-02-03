class IAT_CodexCategory
{
	protected string m_CategoryName;
	protected string m_ClassNameMatch;
	protected int m_DisplayOrder;
	protected ref array<ref IAT_CodexCategory> m_SubCategories;

	void IAT_CodexCategory(string categoryName, string classNameMatch, int displayOrder)
	{
		m_CategoryName = categoryName;
		m_ClassNameMatch = classNameMatch;
		m_DisplayOrder = displayOrder;
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
				return true;
			}
			// is this the same kind of item?
			else if (g_Game.IsKindOf(className, m_ClassNameMatch))
			{
				return true;
			}
		}
		else
		{
			if (classType == categoryType)
			{
				return true;
			}
			else if (classType.IsInherited(categoryType))
			{
				return true;
			}
		}
		// no classname or type match
		return false;
	}

	string GetApplicableCategory(string className)
	{
		// PrintFormat("===================Find Applicable category: %1", className);
		string bestCategory = "";
		int bestDepth = -1;
		FindMostSpecificMatch(className, 0, bestCategory, bestDepth);
		return bestCategory;
	}

	protected void FindMostSpecificMatch(string className, int depth, out string bestCategory, out int bestDepth)
	{
		if (IsInheritedOrKindOf(className))
		{
			bestCategory = GetCategoryName();
			bestDepth = depth;
			// PrintFormat("found match: %1 depth: %2", bestCategory, bestDepth);
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