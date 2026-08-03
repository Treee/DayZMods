class IAT_PluginReportToolClient extends PluginBase
{
	// Keep track of when the last report is sent. This should help reduce malicious spam
	protected int m_LastReportSendTime;
	// Initialize variables
	override void OnInit()
	{
		super.OnInit();
		m_LastReportSendTime = 0;
	}

	void OpenReportMenu(UAInput input)
	{
		if (!input)
			return;
		if (!input.LocalPress())
			return;
		if (g_Game.GetUIManager().GetMenu())
			return;

		g_Game.GetUIManager().EnterScriptedMenu(IAT_MENU_REPORTTOOL_MENU, NULL);
	}

	void SubmitReport(int reportType, string reportDescription)
	{
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(reportType);
		rpc.Write(reportDescription);
		rpc.Send(null, IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT, true, null);
	}
};