#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
// Assert decoded external JSON, independent of serializer whitespace.
class IAT_RT_DiscordPayload
{
	string content;
	int flags;
	ref IAT_DiscordAllowedMentions allowed_mentions;
}

class IAT_RT_DiscordPayloadTest : IAT_ScenarioCase
{
	protected int m_Variant;

	void IAT_RT_DiscordPayloadTest(string caseName, int variant)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "DiscordPayload";
		m_Name = caseName;
		m_Variant = variant;
	}

	override bool Execute()
	{
		JMWebhookDiscordMessage message = new JMWebhookDiscordMessage;
		string expected;
		if (m_Variant == 0)
		{
			message.content = "A \"quoted\" report\\path\n@everyone";
			expected = "A \"quoted\" report\\path\n@everyone";
		}
		else if (m_Variant == 1)
		{
			message.content = "Prefix ";
			JMWebhookDiscordEmbed embed = message.CreateEmbed();
			embed.SetTitle("Title");
			embed.SetDescription("Description ");
			embed.AddField("Location", "one\r\ntwo", false);
			embed.AddField("Skip", "", false);
			embed.fields.Insert(null);
			message.embeds.Insert(null);
			JMWebhookDiscordEmbed second = message.CreateEmbed();
			second.AddField("Player", "River", true);
			expected = "Prefix **Title**Description **Location:** one | two **Player:** River ";
		}
		else
		{
			int length = 1900;
			if (m_Variant == 3)
				length = 1901;
			for (int index = 0; index < length; index++)
				message.content += "x";
			expected = message.content;
			if (m_Variant == 3)
				expected = expected.Substring(0, 1900) + " ... [truncated]";
		}

		string originalContent = message.content;
		JsonSerializer serializer = new JsonSerializer;
		string json = message.Prepare(serializer);
		IAT_RT_DiscordPayload payload;
		string error;
		bool decoded = JsonFileLoader<IAT_RT_DiscordPayload>.LoadData(json, payload, error);
		Check(decoded && payload != null, "Prepared payload is valid JSON", "true", decoded.ToString());
		if (!payload)
			return true;
		if (m_Variant < 2)
			Check(payload.content == expected, "Discord content preserves exact formatting", expected, payload.content);
		else
		{
			// Installed JSON reading clips long strings to 1023 characters.
			// The ASCII boundary fixture needs no escaping: check the wire value.
			bool exactWireContent = json.Contains("\"" + expected + "\"");
			Check(exactWireContent, "Wire content preserves exact truncation boundary", expected.Length().ToString(), exactWireContent.ToString());
		}
		Check(payload.flags == 4, "Link previews are suppressed", "4", payload.flags.ToString());
		Check(payload.allowed_mentions != null, "Mention policy is present", "true", (payload.allowed_mentions != null).ToString());
		if (payload.allowed_mentions)
			Check(payload.allowed_mentions.parse.Count() == 0, "Automatic mention parsing is disabled", "0", payload.allowed_mentions.parse.Count().ToString());
		Check(message.content == originalContent, "Serialization preserves source content", originalContent, message.content);
		return true;
	}
}
#endif
#endif
