class IAT_ReportWebHookMessage extends WebHookMessageBase
{
    void IAT_ReportWebHookMessage(IAT_ReportData report)
    {
        WbEmbed embed = new WbEmbed("In Game Report", 16753920);

        WbField field;
        field = embed.AddField();
        field.SetName("Report Type");
        field.SetValue(report.GetReportTypeDisplayName());


        field = embed.AddField();
        field.SetName("Position");
        field.SetValue(report.m_Position.ToString());

        field = embed.AddField();
        field.SetName("Heading");
        field.SetValue(report.m_Heading.ToString());

        field = embed.AddField();
        field.SetName("Player Name");
        field.SetValue(report.m_PlayerName);

        field = embed.AddField();
        field.SetName("SteamID");
        field.SetValue(report.m_SteamID);

        field = embed.AddField();
        field.SetName("Timestamp");
        field.SetValue(report.m_Timestamp);

        field = embed.AddField();
        field.SetName("Report Description");
        field.SetValue(report.m_Description);

        embeds.Insert(embed);
    }
}