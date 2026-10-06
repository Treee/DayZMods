class IAT_PluginReportToolServer extends PluginBase
{
	protected ref ScriptInvoker m_OnTerrainReportLocation = new ScriptInvoker();

	protected const float NEARBY_PLAYER_RADIUS = 35;
	protected const int DISCORD_NAME_MAX_LENGTH = 64;
	protected const int REPORT_EMBED_COLOR = 16753920;

	void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type != IAT_RPC_REPORTTOOL.CLIENT_SEND_REPORT)
			return;

		IAT_ReportType reportType;
		string reportDescription;
		if (!ctx.Read(reportType) || !ctx.Read(reportDescription))
			return;
		if (reportType < IAT_ReportType.TERRAIN || reportType >= IAT_ReportType.NO_SELECTION)
			return;

		// Optional trailing field keeps reports from older clients usable.
		string discordName;
		if (!ctx.Read(discordName))
			discordName = "";
		discordName.Replace("\r", "");
		discordName.Replace("\n", " ");
		discordName.TrimInPlace();
		if (discordName.Length() > DISCORD_NAME_MAX_LENGTH)
			discordName = discordName.Substring(0, DISCORD_NAME_MAX_LENGTH);

		IAT_ReportData reportData = CreateReportData(reportType, reportDescription, sender, discordName);
		if (reportData)
			SubmitReport(reportData);
	}

	IAT_ReportData CreateReportData(IAT_ReportType reportType, string description, PlayerIdentity sender, string discordName = "")
	{
		if (!sender)
			return null;

		string steamId = sender.GetPlainId();
		string playerName = sender.GetName();
		string timestamp = GetUTCTimestamp();
		int unixTimestamp = GetUnixTimestamp();

		vector position = "0 0 0";
		vector orientation = "0 0 0";
		bool isEmbed = false;

		PlayerBase player;
		if (Class.CastTo(player, sender.GetPlayer()))
		{
			position = player.GetPosition();
			orientation = player.GetOrientation();
		}
		if (reportType == IAT_ReportType.BAD_WORD)
		{
			description = string.Format("Player wrote [%1] which is considered a bad word.", description);
		}
		if (reportType == IAT_ReportType.PLAYER && player)
		{
			string nearbyPlayers = "";
			array<Man> players = new array<Man>();
			g_Game.GetPlayers(players);

			foreach (Man man : players)
			{
				PlayerBase otherPlayer;
				if (!Class.CastTo(otherPlayer, man) || otherPlayer == player)
					continue;

				if (vector.Distance(otherPlayer.GetPosition(), position) > NEARBY_PLAYER_RADIUS)
					continue;

				PlayerIdentity otherIdentity = otherPlayer.GetIdentity();
				if (!otherIdentity) // Exclude AI without a player identity.
					continue;

				if (nearbyPlayers != "")
					nearbyPlayers += " | ";

				nearbyPlayers += otherIdentity.GetPlainId();
			}
			if (nearbyPlayers == "")
				nearbyPlayers = "None";

			description = string.Format("Description: %1 | Nearby Players: %2", description, nearbyPlayers);
		}
		if (reportType == IAT_ReportType.TERRAIN || reportType == IAT_ReportType.BUG || reportType == IAT_ReportType.SUGGESTION || reportType == IAT_ReportType.PLAYER || reportType == IAT_ReportType.EXPLOIT)
		{
			isEmbed = true;
		}
		IAT_ReportData reportData = new IAT_ReportData(reportType, description, steamId, playerName, position, orientation, timestamp, unixTimestamp, isEmbed, discordName);
		return reportData;
	}

	void SubmitReport(IAT_ReportData reportData)
	{
		if (!reportData)
			return;

		PostReportToCOT(reportData);

		if (reportData.IsTerrainReport())
		{
			string entryName = string.Format("TRPT [%1] - [%2]", reportData.GetPlayerName(), reportData.GetTimestamp());
			AddTerrainReportLocation(entryName, reportData.GetReportPosition());
		}
	}

	protected void PostReportToCOT(IAT_ReportData report)
	{
		if (!report)
			return;

		string eventType = GetReportWebhookType(report.m_ReportType);
		if (eventType == "")
			return;

		JMWebhookModule webhook;
		if (!Class.CastTo(webhook, GetModuleManager().GetModule(JMWebhookModule)))
		{
			Print("[IAT Report Tool] COT webhook module unavailable.");
			return;
		}

		JMWebhookDiscordMessage message = new JMWebhookDiscordMessage();

		if (report.IsEmbedReport())
		{
			JMWebhookDiscordEmbed embed = message.CreateEmbed();

			embed.SetTitle("IAT Report: ");
			embed.SetColor(REPORT_EMBED_COLOR);

			embed.AddField(":clipboard:", report.GetReportTypeDisplayName(), false);
			embed.AddField(":person_walking:", report.GetFormattedPlayerName(), true);
			if (report.m_DiscordName != "")
				embed.AddField(":name_badge:", report.m_DiscordName, false);
			embed.AddField(":round_pushpin:", report.m_Position.ToString(), false);
			embed.AddField(":timer:", report.GetFormattedTimestamp(), false);
			embed.AddField(":speech_balloon:", report.m_Description, false);
		}
		else
		{
			string text = string.Format("**[%1]** %2 (%3) Position: %4 | Heading: %5 | %6 | %7", report.GetReportTypeDisplayName(), report.m_PlayerName, report.m_SteamID, report.m_Position.ToString(), report.m_Heading.ToString(), report.m_Description, report.GetFormattedTimestamp());
			if (report.m_DiscordName != "")
				text = string.Format("%1 Discord: %2", text, report.m_DiscordName);

			message.content = text;
		}

		webhook.Post(eventType, message);
	}

	protected string GetReportWebhookType(IAT_ReportType reportType)
	{
		switch (reportType)
		{
			case IAT_ReportType.TERRAIN:
				return "IAT_Report_Terrain";

			case IAT_ReportType.BUG:
				return "IAT_Report_Bug";

			case IAT_ReportType.SUGGESTION:
				return "IAT_Report_Suggestion";

			case IAT_ReportType.PLAYER:
				return "IAT_Report_Player";

			case IAT_ReportType.PLAYER_MUTE:
			case IAT_ReportType.BAD_WORD:
				return "IAT_Report_Moderation";

			case IAT_ReportType.EXPLOIT:
				return "IAT_Report_Exploit";
		}

		return "";
	}

	protected string GetUTCTimestamp()
	{
		int year, month, day;
		int hour, minute, second;

		GetYearMonthDayUTC(year, month, day);
		GetHourMinuteSecondUTC(hour, minute, second);

		return string.Format("%1-%2-%3T%4:%5:%6Z", year.ToStringLen(4), month.ToStringLen(2), day.ToStringLen(2), hour.ToStringLen(2), minute.ToStringLen(2), second.ToStringLen(2));
	}

	protected int GetUnixTimestamp()
	{
		CF_Date nowUTC = CF_Date.Now(true);
		return nowUTC.GetTimestamp();
	}

	ScriptInvoker GetTerrainReportLocationEvent()
	{
		return m_OnTerrainReportLocation;
	}
	// Implemented in 5_Mission, where COT's teleport classes are available.
	protected void AddTerrainReportLocation(string entryName, vector position)
	{
		m_OnTerrainReportLocation.Invoke(entryName, position);
	}
};
