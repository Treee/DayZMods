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
		// start at the root
		IAT_CodexCategory rootCategory = m_CodexCategories;
		// foreach root level category
		foreach(IAT_CodexCategory rootSubCategory : rootCategory)
		{
			string applicableCategory = rootSubCategory.GetApplicableCategory(className);
			if (applicableCategory != "")
			{
				AddType(applicableCategory, className);
			}
		}
	}

	protected void AddType(string category, string className)
	{
		TStringArray items;
		if (!m_CodexDictionary.Contains(category))
		{
			items = { className };
			m_CodexDictionary.Set(category, items);
		}
		else
		{
			item = m_CodexDictionary.Get(category);
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
		// TStringArray values;
		// TTypenameArray keys = GetCodexCategories();
		// string valuesString;
		// foreach (typename key : keys)
		// {
		// 	valuesString = "";
		// 	values = m_IAT_Codex_Dictionary.Get(key);
		// 	PrintFormat("---------------------------Category Key: %1 Count: %2", key, values.Count());
		// 	foreach(int index, string value : values)
		// 	{
		// 		valuesString = string.Format("%1, %2", valuesString, value);
		// 		if (index % 10 == 0)
		// 		{
		// 			PrintFormat("----Values: %1", valuesString);
		// 			valuesString = "";
		// 		}
		// 	}
		// 	PrintFormat("----Values: %1", valuesString);
		// }
		Print("[IAT_CodexDictionary END]");
	}
};
