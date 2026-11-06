#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
class IAT_RT_ZombieDamageFilterTest : IAT_ScenarioCase
{
	protected int m_Variant;

	void IAT_RT_ZombieDamageFilterTest(string caseName, int variant)
	{
		m_Mod = "IAT_ReportTool";
		m_Suite = "ZombieDamageFilter";
		m_Name = caseName;
		m_Variant = variant;
	}

	override bool Execute()
	{
		string zombieName = "#WZ_Zombie_GibZmb_DisplayName";
		string playerLink = "[FireWulf](https://steamcommunity.com/profiles/76561199142417866)";
		string connectionType = "PlayerDamage";
		string attacker = "**" + zombieName + "**";
		bool suppressed = m_Variant == 0 || m_Variant == 6;
		if (m_Variant == 1)
			attacker = "[River](https://steamcommunity.com/profiles/76561198012345678)";
		else if (m_Variant == 2)
			connectionType = "PlayerDeath";
		else if (m_Variant == 3)
			connectionType = "PlayerDeathNoPos";
		else if (m_Variant == 4)
			connectionType = "PlayerKillfeed";
		else if (m_Variant == 5)
			attacker = "[" + zombieName + "](https://steamcommunity.com/profiles/76561198012345678)";

		JMWebhookDiscordMessage message = new JMWebhookDiscordMessage;
		if (m_Variant == 6)
		{
			message.embeds.Insert(null);
			message.CreateEmbed().SetTitle("Unrelated embed");
		}
		JMWebhookDiscordEmbed embed = message.CreateEmbed();
		embed.SetTitle("Player Damaged");
		embed.SetDescription(playerLink + " was hit by " + attacker);
		embed.fields.Insert(null);
		embed.AddField("From:", attacker, true);
		embed.AddField("To:", playerLink + "\n14386, 79, 2402", true);
		embed.AddField("Weapon:", zombieName, true);
		embed.AddField("Ammo:", "Dummy_Light", true);
		embed.AddField("Hit zone:", "RightLeg", true);
		embed.AddField("Type:", "Melee", true);

		bool actual = IAT_ReportWebhookFilter.ShouldSuppress(connectionType, message);
		Check(actual == suppressed, "Only zombie damage is suppressed", suppressed.ToString(), actual.ToString());
		return true;
	}
}
#endif
#endif
