class IAT_ReportData
{
    IAT_ReportType m_ReportType;

    vector m_Position;
    vector m_Heading;

    string m_PlayerName;
    string m_SteamID;
    string m_Description;
    string m_Timestamp;

    void IAT_ReportData(int reportType, string description, string steamId, string playerName, vector position, vector heading, string timestamp)
    {
        m_ReportType = reportType;
        m_Description = description;

        m_SteamID = steamId;
        m_PlayerName = playerName;

        m_Position = position;
        m_Heading = heading;

        m_Timestamp = timestamp;
    }

    string GetReportTypeDisplayName()
    {
        if (m_ReportType == IAT_ReportType.TERRAIN)
            return "Terrain Report";
        if (m_ReportType == IAT_ReportType.BUG)
            return "Bug Report";
        if (m_ReportType == IAT_ReportType.SUGGESTION)
            return "Suggestion Report";
        if (m_ReportType == IAT_ReportType.PLAYER)
            return "Player Report";
        if (m_ReportType == IAT_ReportType.EXPLOIT)
            return "Exploit Report";
        return "No Report Type";
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

    bool IsTerrainReport()
    {
        if (m_ReportType == IAT_ReportType.TERRAIN)
        {
            return true;
        }
        return false;
    }
};