class IAT_CodexDictionary
{
	// controls if we log to the console. useful for setting up the codex items
	protected bool m_DebugLogEnabled;
	protected ref TStringArray m_IgnoredClassNames; // explicit 1:1 ignores
	protected ref TStringArray m_IgnoredClassKinds; // config.cpp isKindOf inheritence
	protected ref TStringArray m_IgnoredClassContains; // className contains this string
	// holds the real values of all things the codex tracks (not meant to be sent over the wire)
	protected ref map<string, ref TStringArray> m_CodexDictionary;
	// holds the categories the codex should track. nested behavior here. (meant to be sent over the wire)
	protected ref IAT_CodexCategory m_CodexCategories;

	void IAT_CodexDictionary()	{}
	// ====================================================== HELPERS

	void TryAddType(string cfgPath, string className)
	{
		if (!m_CodexCategories)
		{
			return;
		}
		if (IsIgnoredClass(className))
		{
			return;
		}

		// start at the root
		string applicableCategory = m_CodexCategories.GetApplicableCategory(cfgPath, className);
		if (applicableCategory == "Ignored")
		{
			if (m_DebugLogEnabled)
			{
				// PrintFormat("Ignored Class determined within the category (probly opened food): %1", className);
			}
		}
		else if (applicableCategory != "")
		{
			AddType(applicableCategory, className);
		}
		else
		{
			if (m_DebugLogEnabled)
			{
				// PrintFormat("ClassName: %1 has not found any category: %2", className, applicableCategory);
			}
		}
	}

	protected void AddType(string category, string className)
	{
		// PrintFormat("adding category: %1 and classname: %2", category, className);
		TStringArray items;
		if (!m_CodexDictionary.Contains(category))
		{
			// Print("adding new category");
			items = { className };
			m_CodexDictionary.Set(category, items);
		}
		else
		{
			// Print("updating category");
			items = m_CodexDictionary.Get(category);
			items.Insert(className);
		}
	}

	// ====================================================== GETTERS
	bool IsIgnoredClass(string className)
	{
		// things like HouseNoDestruct, AreaEffect
		if (m_IgnoredClassKinds)
		{
			foreach(string ignoredClassKind : m_IgnoredClassKinds)
			{
				if (g_Game.IsKindOf(className, ignoredClassKind))
				{
					if (m_DebugLogEnabled)
					{
						// PrintFormat("ClassName: %1 is ignored by Kind Of: %2", className, ignoredClassKind);
					}
					return true;
				}
			}
		}
		// things like TestObject
		if (m_IgnoredClassNames)
		{
			foreach(string ignoredClassName : m_IgnoredClassNames)
			{
				if (className == ignoredClassName)
				{
					if (m_DebugLogEnabled)
					{
						// PrintFormat("ClassName: %1 is ignored class: %2", className, ignoredClassName);
					}
					return true;
				}
			}
		}
		// things like underground stashes and garden plots
		if (m_IgnoredClassContains)
		{
			foreach(string ignoredClassContain : m_IgnoredClassContains)
			{
				if (className.Contains(ignoredClassContain))
				{
					if (m_DebugLogEnabled)
					{
						// PrintFormat("ClassName: %1 contains ignored characters: %2", className, ignoredClassContain);
					}
					return true;
				}
			}
		}
		return false;
	}
	void SetIgnoredClasses(TStringArray ignoredClasses)
	{
		m_IgnoredClassNames = ignoredClasses;
	}
	void SetIgnoredClassKinds(TStringArray ignoredClasses)
	{
		m_IgnoredClassKinds = ignoredClasses;
	}
	void SetIgnoredClassContains(TStringArray ignoredClasses)
	{
		m_IgnoredClassContains = ignoredClasses;
	}
	bool IsDebugMode()
	{
		return m_DebugLogEnabled;
	}
	void SetIsDebugMode(bool newState)
	{
		m_DebugLogEnabled = newState;
	}

	void SetCategories(IAT_CodexCategory categories)
	{
		m_CodexCategories = categories;
	}
	map<string, ref TStringArray> GetCodexDictionary()
	{
		if (!m_CodexDictionary)
		{
			m_CodexDictionary = new map<string, ref TStringArray>();
		}
		return m_CodexDictionary;
	}

	void PrettyPrint()
	{
		if (m_DebugLogEnabled)
		{

			Print("[IAT_CodexDictionary BEGIN]");

			if (!m_CodexCategories)
			{
				Print("[IAT_CodexDictionary] No categories set");
				Print("[IAT_CodexDictionary END]");
				return;
			}

			PrettyPrintCategory(m_CodexCategories, 0);

			Print("[IAT_CodexDictionary END]");
		}
	}

	protected void PrettyPrintCategory(IAT_CodexCategory category, int depth)
	{
		if (!category)
		{
			return;
		}

		string categoryName = category.GetCategoryName();
		string indent = PrettyPrintIndent(depth);

		TStringArray items;
		int itemCount = 0;
		if (m_CodexDictionary && m_CodexDictionary.Contains(categoryName))
		{
			items = m_CodexDictionary.Get(categoryName);
			if (items)
			{
				itemCount = items.Count();
			}
		}

		bool hasSubCategories = category.HasSubCategories();
		string nodeType = "Leaf";
		if (hasSubCategories)
		{
			nodeType = "Node";
		}

		PrintFormat("%1%2: %3 (items: %4)", indent, nodeType, categoryName, itemCount);
		if (m_DebugLogEnabled)
		{
			if (itemCount > 0)
			{
				if (category.ShouldSortItems())
				{
					items.Sort();
				}
				foreach (string item : items)
				{
					PrintFormat("%1  - %2", indent, item);
				}
			}
		}

		if (!hasSubCategories)
		{
			return;
		}
		array<ref IAT_CodexCategory> subCategories = category.GetSubCategories();
		foreach (IAT_CodexCategory subCategory : subCategories)
		{
			PrettyPrintCategory(subCategory, depth + 1);
		}
	}

	protected string PrettyPrintIndent(int depth)
	{
		string indent = "";
		for (int i = 0; i < depth; i++)
		{
			indent += "  ";
		}
		return indent;
	}
};
