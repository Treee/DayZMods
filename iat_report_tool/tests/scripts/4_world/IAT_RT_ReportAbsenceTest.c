#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_ReportAbsenceTest : IAT_ScenarioCase
{
	void IAT_RT_ReportAbsenceTest()
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ReportSubmission";
		m_Name = "AbsentSenderAndReportHaveNoDelivery";
	}

	override bool Execute()
	{
		IAT_RT_RecordingReportServer server = new IAT_RT_RecordingReportServer;
		IAT_ReportData report = server.CreateReportData(IAT_ReportType.BUG, "Door", null);
		Check(report == null, "Absent identity cannot create an enriched report", "null", (report == null).ToString());
		server.SubmitReport(report);
		Check(server.m_PostCount == 0, "Absent report produces no delivery", "0", server.m_PostCount.ToString());

		ScriptReadWriteContext packet = new ScriptReadWriteContext;
		packet.GetWriteContext().Write(IAT_ReportType.BUG);
		packet.GetWriteContext().Write("Door");
		server.OnRPC(null, IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT, packet.GetReadContext());
		Check(server.m_PostCount == 0, "Real identity enrichment rejects senderless RPC", "0", server.m_PostCount.ToString());
		return true;
	}
}
#endif
#endif
