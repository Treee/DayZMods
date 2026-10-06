class IAT_DiscordAllowedMentions
{
	ref array<string> parse = new array<string>();
};

class IAT_DiscordTextPayload
{
	static const int SUPPRESS_EMBEDS = 4;

	string content;
	// Discord SUPPRESS_EMBEDS: keep links clickable without preview cards.
	int flags = SUPPRESS_EMBEDS;
	ref IAT_DiscordAllowedMentions allowed_mentions = new IAT_DiscordAllowedMentions();
};

modded class JMWebhookDiscordMessage
{
	protected const int IAT_TEXT_MAX_LENGTH = 1900;

	protected string IAT_GetPlainText()
	{
		string text = content;
		if (embeds)
		{
			foreach (JMWebhookDiscordEmbed embed : embeds)
			{
				if (!embed)
				{
					continue;
				}
				if (embed.title != "")
					text += string.Format("**%1**", embed.title);
				if (embed.description != "")
					text += string.Format("%1", embed.description);

				foreach (JMWebhookDiscordEmbedField field : embed.fields)
				{
					if (!field)
					{
						continue;
					}
					if (field.value == "")
					{
						continue;
					}
					string value = field.value;
					value.Replace("\r", "");
					value.Replace("\n", " | ");
					text += string.Format("**%1:** %2 ", field.name, value);
				}
			}
		}
		return text;
	}

	override string Prepare(JsonSerializer serializer)
	{
		string text = IAT_GetPlainText();
		if (!embeds && text == "")
			return super.Prepare(serializer);

		// Plain Discord messages have a 2,000-character limit.
		if (text.Length() > IAT_TEXT_MAX_LENGTH)
		{
			text = text.Substring(0, IAT_TEXT_MAX_LENGTH) + " ... [truncated]";
		}
		IAT_DiscordTextPayload payload = new IAT_DiscordTextPayload();
		payload.content = text;
		string json;
		if (!serializer.WriteToString(payload, false, json))
		{
			return super.Prepare(serializer);
		}
		return json;
	}
};
