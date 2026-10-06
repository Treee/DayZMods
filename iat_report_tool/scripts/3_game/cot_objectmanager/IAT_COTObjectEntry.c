class IAT_COTObjectEntry
{
	string m_ClassName;
	vector m_Position;
	vector m_Orientation;
	float m_Scale = 1.0;

	IAT_COTObjectEntry Clone()
	{
		IAT_COTObjectEntry copy = new IAT_COTObjectEntry;
		copy.m_ClassName = m_ClassName;
		copy.m_Position = m_Position;
		copy.m_Orientation = m_Orientation;
		copy.m_Scale = m_Scale;
		return copy;
	}
}

