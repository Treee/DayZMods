modded class JMTeleportModule
{
	void IAT_AddReportLocation(string entryName, vector position)
	{
		if (!g_Game.IsServer() || !IsLoaded())
			return;

		string category = "IAT Terrain Reports";

		if (m_Settings.Types.Find(category) == -1)
			m_Settings.Types.Insert(category);

		m_Settings.AddLocation(category, entryName, position, 0.0);
		m_Settings.Save();

		OnSettingsUpdated();
	}
};
