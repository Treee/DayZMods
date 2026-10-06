#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_ReportTypeTest : IAT_ScenarioCase
{
	protected int m_ReportType;
	protected string m_ExpectedName;
	protected bool m_ExpectedTerrain;

	void IAT_RT_ReportTypeTest(string caseName, int reportType, string expectedName, bool expectedTerrain = false)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ReportData";
		m_Name = caseName;
		m_ReportType = reportType;
		m_ExpectedName = expectedName;
		m_ExpectedTerrain = expectedTerrain;
	}

	override bool Execute()
	{
		IAT_ReportData report = new IAT_ReportData(m_ReportType, "Description", "123", "Player", "0 0 0", "0 0 0", "fixed", 0);

		Check(report.GetReportTypeDisplayName() == m_ExpectedName, "Category display name", m_ExpectedName, report.GetReportTypeDisplayName());
		Check(report.IsTerrainReport() == m_ExpectedTerrain, "Only terrain is classified as terrain", m_ExpectedTerrain.ToString(), report.IsTerrainReport().ToString());
		Check(!report.IsEmbedReport(), "Category alone does not enable embeds in report data", "false", report.IsEmbedReport().ToString());
		return true;
	}
}
#endif
#endif
