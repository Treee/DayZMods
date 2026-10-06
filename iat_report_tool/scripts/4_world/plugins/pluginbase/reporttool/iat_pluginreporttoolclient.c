class IAT_PluginReportToolClient extends PluginBase
{
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

	void SubmitReport(int reportType, string reportDescription, string discordName = "")
	{
		ScriptRPC rpc = new ScriptRPC();
		rpc.Write(reportType);
		rpc.Write(reportDescription);
		rpc.Write(discordName);
		rpc.Send(null, IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT, true, null);
	}
};
