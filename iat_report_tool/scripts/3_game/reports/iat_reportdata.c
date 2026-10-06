class IAT_ReportData
{
	IAT_ReportType m_ReportType;

	vector m_Position;
	vector m_Heading;

	string m_PlayerName;
	string m_SteamID;
	string m_Description;
	string m_Timestamp;
	int m_UnixTimestamp;
	string m_DiscordName;
	bool m_ShouldEmbed;

	void IAT_ReportData(int reportType, string description, string steamId, string playerName, vector position, vector heading, string timestamp, int unixTime, bool isEmbed = false, string discordName = "")
	{
		m_ReportType = reportType;
		m_Description = description;

		m_SteamID = steamId;
		m_PlayerName = playerName;

		m_Position = position;
		m_Heading = heading;

		m_Timestamp = timestamp;
		m_UnixTimestamp = unixTime;
		m_DiscordName = discordName;

		m_ShouldEmbed = isEmbed;
	}

	string GetReportTypeDisplayName()
	{
		string enumName = EnumTools.EnumToString(IAT_ReportType, m_ReportType);
		if (enumName == "unknown")
			return "No Report Type";
		return enumName;
	}

	string GetPlayerName()
	{
		return m_PlayerName;
	}

	vector GetReportPosition()
	{
		return m_Position;
	}

	string GetTimestamp()
	{
		return m_Timestamp;
	}

	string GetFormattedTimestamp()
	{
		return string.Format("<t:%1:F>", m_UnixTimestamp);
	}

	bool IsEmbedReport()
	{
		return m_ShouldEmbed;
	}

	bool IsTerrainReport()
	{
		return m_ReportType == IAT_ReportType.TERRAIN;
	}

	string GetFormattedPlayerName()
	{
		return string.Format("[%1](https://steamcommunity.com/profiles/%2)", m_PlayerName, m_SteamID);
	}
};
