modded class JMWebhookModule
{
	override void OnMissionStart()
	{
		super.OnMissionStart();

		AddConnection("IAT_Report_Terrain", "");
		AddConnection("IAT_Report_Bug", "");
		AddConnection("IAT_Report_Suggestion", "");
		AddConnection("IAT_Report_Player", "");
		AddConnection("IAT_Report_Moderation", "");
		AddConnection("IAT_Report_Exploit", "");
	}

	override void Post(string connectionType, JMWebhookMessage message)
	{
		// this logic here will ignore zombie hits on players to reduce log spam.
		// deaths are still recorded from zeds but in a different connection type
		if (connectionType == "PlayerDamage")
		{
			JMWebhookDiscordMessage discordMessage;

			if (Class.CastTo(discordMessage, message))
			{
				foreach (JMWebhookDiscordEmbed embed : discordMessage.embeds)
				{
					if (!embed)
						continue;

					foreach (JMWebhookDiscordEmbedField field : embed.fields)
					{
						if (!field || field.name != "Player Damaged")
							continue;

						if (field.value.Contains("#WZ_Zombie_GibZmb_DisplayName"))
							return;
					}
				}
			}
		}

		super.Post(connectionType, message);
	}
};
