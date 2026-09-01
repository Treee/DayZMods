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

    bool IsTerrainReport()
    {
        if (m_ReportType == IAT_ReportType.TERRAIN)
        {
            return true;
        }
        return false;
    }
};