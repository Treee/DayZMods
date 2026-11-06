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
		if (IAT_ShouldSuppress(connectionType, message))
			return;

		super.Post(connectionType, message);
	}

	override void Post(string connectionType, JMWebhookMessage message, string targetGUID, string targetRole = "")
	{
		if (IAT_ShouldSuppress(connectionType, message))
			return;

		super.Post(connectionType, message, targetGUID, targetRole);
	}

	override void PostAs(string connectionType, JMWebhookMessage message, JMPlayerInstance player, JMPlayerInstance other = null)
	{
		// Current COT damage reports use PostAs, which queues directly.
		if (IAT_ShouldSuppress(connectionType, message))
			return;

		super.PostAs(connectionType, message, player, other);
	}


	bool IAT_ShouldSuppress(string connectionType, JMWebhookMessage message)
	{
		// Death and killfeed connections must always reach COT's queue.
		if (connectionType != "PlayerDamage")
			return false;

		JMWebhookDiscordMessage discordMessage;
		if (!Class.CastTo(discordMessage, message) || !discordMessage.embeds)
			return false;

		foreach (JMWebhookDiscordEmbed embed : discordMessage.embeds)
		{
			if (!embed || embed.title != "Player Damaged" || !embed.fields)
				continue;

			foreach (JMWebhookDiscordEmbedField field : embed.fields)
			{
				if (!field || field.name != "From:")
					continue;

				// COT bolds non-player attackers; match the whole value so a
				// Steam-linked player using the zombie's name is still logged.
				if (field.value == "**#WZ_Zombie_GibZmb_DisplayName**" || field.value == "#WZ_Zombie_GibZmb_DisplayName")
					return true;
			}
		}
		return false;
	}
};
