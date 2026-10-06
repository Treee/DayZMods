class IAT_COTObjectGroup
{
	string m_Name;
	bool m_Enabled = true;
	ref array<ref IAT_COTObjectEntry> m_Objects = new array<ref IAT_COTObjectEntry>;

	IAT_COTObjectGroup Clone()
	{
		IAT_COTObjectGroup copy = new IAT_COTObjectGroup;
		copy.m_Name = m_Name;
		copy.m_Enabled = m_Enabled;
		array<ref IAT_COTObjectEntry> entries = m_Objects;
		foreach (IAT_COTObjectEntry entry : entries)
			copy.m_Objects.Insert(entry.Clone());
		return copy;
	}
}

