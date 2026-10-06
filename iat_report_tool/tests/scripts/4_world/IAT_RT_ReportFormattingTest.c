#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_ReportFormattingTest : IAT_ScenarioCase
{
	protected string m_PlayerName;
	protected string m_SteamID;
	protected int m_UnixTime;
	protected string m_ExpectedLink;
	protected string m_ExpectedTimestamp;

	void IAT_RT_ReportFormattingTest(string caseName, string playerName, string steamId, int unixTime, string expectedLink, string expectedTimestamp)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ReportData";
		m_Name = caseName;
		m_PlayerName = playerName;
		m_SteamID = steamId;
		m_UnixTime = unixTime;
		m_ExpectedLink = expectedLink;
		m_ExpectedTimestamp = expectedTimestamp;
	}

	override bool Execute()
	{
		IAT_ReportData report = new IAT_ReportData(IAT_ReportType.PLAYER, "", m_SteamID, m_PlayerName, "0 0 0", "0 0 0", "UTC text is independent", m_UnixTime);

		Check(report.GetFormattedPlayerName() == m_ExpectedLink, "Steam profile Markdown link", m_ExpectedLink, report.GetFormattedPlayerName());
		Check(report.GetFormattedTimestamp() == m_ExpectedTimestamp, "Discord full-date timestamp uses Unix time", m_ExpectedTimestamp, report.GetFormattedTimestamp());
		return true;
	}
}
#endif
#endif
