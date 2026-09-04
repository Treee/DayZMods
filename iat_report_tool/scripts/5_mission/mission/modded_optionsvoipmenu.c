modded class OptionsVOIPMuteMenu
{
	override void AddMutePlayer(string steamid)
	{
		super.AddMutePlayer(steamid);

		IAT_PluginReportToolClient plugin;
		if (Class.CastTo(plugin, GetPlugin(IAT_PluginReportToolClient)))
		{
            string reportDescription = string.Format("Player: %1 (%2) has muted Player: %3 (%4)", m_Player.GetIdentity().GetPlainName(), m_Player.GetIdentity().GetPlainId(), MiscGameplayFunctions.GetVOIPPlayerDisplayName(steamid), steamid);
            // PrintFormat("Report Type: %1 Description: %2", reportType, reportDescription);
			plugin.SubmitReport(IAT_ReportType.PLAYER_MUTE, reportDescription);
		}
	};
};