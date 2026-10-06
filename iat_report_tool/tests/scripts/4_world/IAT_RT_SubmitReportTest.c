#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Replace external delivery while exercising the real public submission operation.
class IAT_RT_RecordingReportServer : IAT_PluginReportToolServer
{
	int m_PostCount;
	ref IAT_ReportData m_PostedReport;

	override protected void PostReportToCOT(IAT_ReportData report)
	{
		m_PostCount++;
		m_PostedReport = report;
	}
}

class IAT_RT_SubmitReportTest : IAT_ScenarioCase
{
	protected int m_ReportType;
	protected int m_ExpectedEvents;
	protected int m_EventCount;
	protected string m_EntryName;
	protected vector m_Position;
	protected ref IAT_RT_RecordingReportServer m_Server;

	void IAT_RT_SubmitReportTest(string caseName, int reportType, int expectedEvents)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ReportSubmission";
		m_Name = caseName;
		m_ReportType = reportType;
		m_ExpectedEvents = expectedEvents;
	}

	override bool Prepare()
	{
		m_Server = new IAT_RT_RecordingReportServer();
		m_Server.GetTerrainReportLocationEvent().Insert(OnTerrainLocation);
		m_EventCount = 0;
		return true;
	}

	protected void OnTerrainLocation(string entryName, vector position)
	{
		m_EventCount++;
		m_EntryName = entryName;
		m_Position = position;
	}

	override bool Execute()
	{
		if (!m_Server)
			return true;
		IAT_ReportData report = new IAT_ReportData(m_ReportType, "Floating rock", "123", "River", "321 54 876", "0 0 0", "2026-10-05T12:34:56Z", 1791203696);

		m_Server.SubmitReport(report);

		Check(m_Server.m_PostCount == 1, "Submission passes report to delivery once", "1", m_Server.m_PostCount.ToString());
		Check(m_Server.m_PostedReport == report, "Delivery receives the submitted report", "same report", (m_Server.m_PostedReport == report).ToString());
		Check(m_EventCount == m_ExpectedEvents, "Only terrain submissions emit a location", m_ExpectedEvents.ToString(), m_EventCount.ToString());
		if (m_ExpectedEvents == 1)
		{
			Check(m_EntryName == "TRPT [River] - [2026-10-05T12:34:56Z]", "Terrain entry includes TRPT prefix, player and UTC text", "TRPT [River] - [2026-10-05T12:34:56Z]", m_EntryName);
			Check(m_Position == "321 54 876", "Terrain event preserves report position", "321 54 876", m_Position.ToString());
		}
		return true;
	}

	override bool Cleanup()
	{
		if (m_Server)
			m_Server.GetTerrainReportLocationEvent().Remove(OnTerrainLocation);
		m_Server = null;
		return true;
	}
}
#endif
#endif
