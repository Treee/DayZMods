#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_ReportFieldsTest : IAT_ScenarioCase
{
	protected bool m_ExplicitOptions;

	void IAT_RT_ReportFieldsTest(bool explicitOptions)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ReportData";
		m_ExplicitOptions = explicitOptions;
		m_Name = "ReportFieldsWithDefaultOptions";
		if (explicitOptions)
			m_Name = "ReportFieldsWithExplicitOptions";
	}

	override bool Execute()
	{
		IAT_ReportData report;
		if (m_ExplicitOptions)
			report = new IAT_ReportData(IAT_ReportType.BUG, "Door stays open\nSecond line", "76561198012345678", "River", "123 45 678", "90 10 -5", "2026-10-05T12:34:56Z", 1791203696, true, "river.discord");
		else
			report = new IAT_ReportData(IAT_ReportType.BUG, "Door stays open\nSecond line", "76561198012345678", "River", "123 45 678", "90 10 -5", "2026-10-05T12:34:56Z", 1791203696);

		Check(report.m_ReportType == IAT_ReportType.BUG, "Report retains category", "BUG", report.GetReportTypeDisplayName());
		Check(report.m_Description == "Door stays open\nSecond line", "Description retains line breaks", "Door stays open\nSecond line", report.m_Description);
		Check(report.GetPlayerName() == "River", "Player name is preserved", "River", report.GetPlayerName());
		Check(report.m_SteamID == "76561198012345678", "Steam identity is preserved", "76561198012345678", report.m_SteamID);
		Check(report.GetReportPosition() == "123 45 678", "Position is preserved", "123 45 678", report.GetReportPosition().ToString());
		Check(report.m_Heading == "90 10 -5", "Heading is preserved", "90 10 -5", report.m_Heading.ToString());
		Check(report.GetTimestamp() == "2026-10-05T12:34:56Z", "UTC text is preserved", "2026-10-05T12:34:56Z", report.GetTimestamp());
		Check(report.m_UnixTimestamp == 1791203696, "Unix timestamp is preserved", "1791203696", report.m_UnixTimestamp.ToString());
		Check(report.IsEmbedReport() == m_ExplicitOptions, "Embed option is preserved", m_ExplicitOptions.ToString(), report.IsEmbedReport().ToString());
		string expectedDiscord = "";
		if (m_ExplicitOptions)
			expectedDiscord = "river.discord";
		Check(report.m_DiscordName == expectedDiscord, "Discord name follows optional argument", expectedDiscord, report.m_DiscordName);
		return true;
	}
}
#endif
#endif
