class IAT_ReportToolConfig
{
	[NonSerialized()]
	protected string m_DayZFolder = "$mission:";
	[NonSerialized()]
    protected string m_RootConfigFolder = "ItsATreeMods";
	[NonSerialized()]
    protected string m_JsonFile = "ReportToolConfig.json";

	protected string m_DiscordWebhookUrl = "";
	protected bool m_CanSendReports = 0;

	protected bool m_AddTerrainReportsToTeleportList = 0;
	protected string m_TeleportEntryNamePrefix = "TRPT";

	IAT_ReportToolConfig TryGetReportToolConfig()
	{
		string rootFilePath = string.Format("%1\\%2", m_DayZFolder, m_RootConfigFolder);
		// if the folder doesnt exist (we probably just loaded this for the first time)
		if (!FileExist(rootFilePath))
		{
			MakeDirectory(rootFilePath);
		}

		string errorMessage;
		IAT_ReportToolConfig iat_RTConfig = new IAT_ReportToolConfig();
		string jsonConfig = string.Format("%1\\%2", rootFilePath, m_JsonFile);
		// if the actual config file doesnt exist
		if (!FileExist(jsonConfig))
		{
			// set some default values
			iat_RTConfig.m_DiscordWebhookUrl = "Replace With Your Discord Webhook";
			iat_RTConfig.m_CanSendReports = 0;

			iat_RTConfig.m_AddTerrainReportsToTeleportList = 1;
			iat_RTConfig.m_TeleportEntryNamePrefix = "TRPT";

			// write the file to "create it"
			if (!JsonFileLoader<ref IAT_ReportToolConfig>.SaveFile(jsonConfig, iat_RTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		else
		{
			// file exists, just load it from disk
			if (!JsonFileLoader<ref IAT_ReportToolConfig>.LoadFile(jsonConfig, iat_RTConfig, errorMessage))
				ErrorEx(errorMessage);
		}
		// return what we found
        return iat_RTConfig;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	string GetDiscordWebhookUrl()
	{
		return m_DiscordWebhookUrl;
	}

	bool CanSendReports()
	{
		return m_CanSendReports;
	}

	bool CanAddLocationsToVPPTeleportList()
	{
		return m_AddTerrainReportsToTeleportList;
	}

	string GetTeleportEntryNamePrefix()
	{
		return m_TeleportEntryNamePrefix;
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	void PrettyPrint()
	{
		Print("--[REPORT TOOL CONFIG BEGIN]");
		Print(m_DiscordWebhookUrl);
		Print(m_CanSendReports);
		Print("--[END]");
	}
};