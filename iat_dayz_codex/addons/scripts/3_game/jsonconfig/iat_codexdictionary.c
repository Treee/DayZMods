class IAT_CodexDictionary
{
	// holds the real values of all things the codex tracks (not meant to be sent over the wire)
	protected ref map<string, ref TStringArray> m_CodexDictionary;
	// holds the categories the codex should track. nested behavior here. (meant to be sent over the wire)
	protected ref IAT_CodexCategory m_CodexCategories;

	void IAT_CodexDictionary()	{}
	// ====================================================== HELPERS

	void TryAddType(string className)
	{
		if (!m_CodexCategories)
		{
			return;
		}

		// start at the root
		string applicableCategory = m_CodexCategories.GetApplicableCategory(className);
		if (applicableCategory != "")
		{
			AddType(applicableCategory, className);
		}
		else
		{
			// Debug print for finding missing categories
			// PrintFormat("No category found for: %1", className);
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
		// if (itemCount > 0)
		// {
		// 	foreach (string item : items)
		// 	{
		// 		PrintFormat("%1  - %2", indent, item);
		// 	}
		// }

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
