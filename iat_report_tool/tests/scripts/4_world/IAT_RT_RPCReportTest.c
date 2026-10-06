#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Keep real decoding/submission; replace native identity enrichment and delivery.
// This double cannot prove identity authentication or multiplayer transport.
class IAT_RT_RPCReportServer : IAT_RT_RecordingReportServer
{
	int m_CreateCount;

	override IAT_ReportData CreateReportData(IAT_ReportType reportType, string description, PlayerIdentity sender, string discordName = "")
	{
		m_CreateCount++;
		return new IAT_ReportData(reportType, description, "123", "River", "1 2 3", "4 5 6", "fixed", 0, false, discordName);
	}
}

class IAT_RT_RPCReportTest : IAT_ScenarioCase
{
	protected int m_Variant;

	void IAT_RT_RPCReportTest(string caseName, int variant)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ReportRPC";
		m_Name = caseName;
		m_Variant = variant;
	}

	override bool Execute()
	{
		IAT_RT_RPCReportServer server = new IAT_RT_RPCReportServer;
		int requests = 1;
		if (m_Variant == 0)
			requests = 2;
		int expected = requests;
		if (m_Variant == 3 || m_Variant == 4 || m_Variant == 5)
			expected = 0;
		string discord = "  river\r\ndiscord  ";
		if (m_Variant == 2)
		{
			discord = "";
			for (int charIndex = 0; charIndex < 65; charIndex++)
				discord += "d";
		}
		for (int requestIndex = 0; requestIndex < requests; requestIndex++)
		{
			ScriptReadWriteContext packet = new ScriptReadWriteContext;
			int category = IAT_ReportType.BUG;
			if (m_Variant == 4)
				category = 8;
			if (m_Variant == 5)
				category = IAT_ReportType.NO_SELECTION;
			packet.GetWriteContext().Write(category);
			if (m_Variant != 3)
				packet.GetWriteContext().Write("Door\nSecond line");
			if (m_Variant != 1 && m_Variant != 3)
				packet.GetWriteContext().Write(discord);

			server.OnRPC(null, IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT, packet.GetReadContext());
		}

		Check(server.m_PostCount == expected, "Decoded report count follows the request contract", expected.ToString(), server.m_PostCount.ToString());
		Check(server.m_CreateCount == expected, "Invalid packets are rejected before enrichment", expected.ToString(), server.m_CreateCount.ToString());
		if (server.m_PostedReport)
		{
			Check(server.m_PostedReport.m_Description == "Door\nSecond line", "RPC preserves description", "Door\nSecond line", server.m_PostedReport.m_Description);
			string expectedDiscord = "river discord";
			if (m_Variant == 1)
				expectedDiscord = "";
			if (m_Variant == 2)
				expectedDiscord = discord.Substring(0, 64);
			Check(server.m_PostedReport.m_DiscordName == expectedDiscord, "Optional Discord name is normalized and bounded", expectedDiscord, server.m_PostedReport.m_DiscordName);
		}
		return true;
	}
}
#endif
#endif
