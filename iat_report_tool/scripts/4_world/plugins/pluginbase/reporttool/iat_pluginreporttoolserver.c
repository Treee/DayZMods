class IAT_PluginReportToolServer extends PluginBase
{
	protected int m_LastReportTime;
	protected const float REPORT_COOLDOWN_MS = 10000;
	// Initialize variables
	override void OnInit()
	{
		super.OnInit();
		m_LastReportTime = 0;
	}

	void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
		if (rpc_type == IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT)
		{
			float elapsed = g_Game.GetTime() - m_LastReportTime;
			if (elapsed < REPORT_COOLDOWN_MS)
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended(sender, NotificationSystem.DEFAULT_TIME_DISPLAYED, "Report Tool", "Please wait up to one minute before sending another report.", "set:ccgui_enforce image:Icon40Emergency");
			}
			else
			{
				IAT_ReportType reportType;
				string reportDescription;

				if (!ctx.Read(reportType))
					return;
				if (!ctx.Read(reportDescription))
					return;

				IAT_ReportData reportData = CreateReportData(reportType, reportDescription, sender);
				SubmitReport(reportData);
			}
		}
    }

	IAT_ReportData CreateReportData(IAT_ReportType reportType, string description, PlayerIdentity sender)
	{
		string steamId =  sender.GetPlainId();
		string playerName = sender.GetName();
		string timestamp = GetUTCTimestamp();

		vector pos = "0 0 0";
		vector orientation = "0 0 0";
		PlayerBase player;
		if (Class.CastTo(player, sender.GetPlayer()))
		{
			pos = player.GetPosition();
			orientation = player.GetOrientation();
		}
		if (reportType == IAT_ReportType.BAD_WORD)
		{
			description = string.Format("Player wrote [%1] which is considered a bad word.", description);
		}
		return new IAT_ReportData(reportType, description, steamId, playerName, pos, orientation, timestamp);
	}

	void SubmitReport(IAT_ReportData reportData)
	{
		// Reset timer
		m_LastReportTime = g_Game.GetTime();
		// Send webhook thingy
		GetWebHooksManager().PostData(IAT_ReportWebHookMessage, new IAT_ReportWebHookMessage(reportData));

		// if the report is a terrain report
		if (reportData.IsTerrainReport())
		{
			// if the config exists
			IAT_ReportToolConfig config;
			if (Class.CastTo(config, GetDayZGame().GetIATReportToolConfig()))
			{
				// if the config is allowed to write teleport locations
				if (config.CanAddLocationsToVPPTeleportList())
				{
					string entryName = string.Format("%1 [%2] - [%3]", config.GetTeleportEntryNamePrefix(), reportData.GetPlayerName(), reportData.GetTimestamp());

					// VPP Teleport Manager
					TeleportManager tpm;
					if (Class.CastTo(tpm, GetTeleportManager()))
					{
						tpm.AddLocation(entryName, reportData.GetReportPosition());
						tpm.Save();
					}
				}
			}
		}
	}

	protected string GetUTCTimestamp()
	{
		int year, month, day;
		int hour, minute, second;

		GetYearMonthDayUTC(year, month, day);
		GetHourMinuteSecondUTC(hour, minute, second);

		return string.Format("%1-%2-%3T%4:%5:%6Z", year.ToStringLen(4), month.ToStringLen(2), day.ToStringLen(2), hour.ToStringLen(2), minute.ToStringLen(2), second.ToStringLen(2));
	}
};