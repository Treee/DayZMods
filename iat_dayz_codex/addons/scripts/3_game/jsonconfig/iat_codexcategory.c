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
		if (m_SubCategories) // null/sanity check
		{
			m_SubCategories.Insert(newCategory);
		}
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
		}
		// no classname or type match
		return false;
	}

	string GetApplicableCategory(string className)
	{
	}

	string RecurseSubCategories(IAT_CodexCategory parentCategory)
	{
		if (IsInheritedOrKindOf(className))
		{

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