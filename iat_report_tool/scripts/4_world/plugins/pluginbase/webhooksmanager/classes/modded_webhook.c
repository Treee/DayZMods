modded class WebHook
{
	/*
	* Server side only, handled in the super call
	*/
    override void PostMessage(typename messageType, WebHookMessageBase dataClass)
    {
        super.PostMessage(messageType, dataClass);

		IAT_ReportToolConfig config;
		if (Class.CastTo(config, GetDayZGame().GetIATReportToolConfig()))
		{
			switch (messageType)
			{
				case IAT_ReportWebHookMessage:
				{
					if (!config.CanSendReports())
					break;

					IAT_PostMessage(config.GetDiscordWebhookUrl(), dataClass);
					break;
				}
			}
		}
	}

	// Simple wrapper to cut down on duplicate code.
	protected void IAT_PostMessage(string url, WebHookMessageBase msg)
	{
		GetWebHooksManager().GetConnectionManager().Post(url, msg.BuildMessage(SimplifyMessages()));
	}
};