modded class PlayerBase
{
	// Client side call
	override void ADMChatUpdateRPC(string gamerword)
	{
		super.ADMChatUpdateRPC(gamerword);
		IAT_PluginReportToolClient plugin;
		if (Class.CastTo(plugin, GetPlugin(IAT_PluginReportToolClient)))
		{
			plugin.SubmitReport(IAT_ReportType.BAD_WORD, gamerword);
		}
	};
};