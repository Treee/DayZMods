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
					if (config.CanSendReports())
					{
						IAT_ReportWebHookMessage rwhm;
						if (Class.CastTo(rwhm, dataClass))
						{
							GetWebHooksManager().GetConnectionManager().Post(GetURL(), rwhm.BuildMessage(SimplifyMessages()));
						}
					}
				}
				break;
			}
		}
	}
};