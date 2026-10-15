modded class DayZGame
{
	protected ref IAT_CraftingPlusConfig m_IAT_CraftingPlusConfig;

	void SetIATCraftingPlusConfig(IAT_CraftingPlusConfig config)
	{
		Print("IAT_CraftingPlusConfig Settings Initialized");
		// config.PrettyPrint();
		m_IAT_CraftingPlusConfig = config;
	}

	IAT_CraftingPlusConfig GetIATCraftingPlusConfig()
	{
		if (!m_IAT_CraftingPlusConfig)
		{
			IAT_CraftingPlusConfig tempConfig = new IAT_CraftingPlusConfig();
			m_IAT_CraftingPlusConfig = tempConfig.TryGetCraftingPlusConfig();
		}
		return m_IAT_CraftingPlusConfig;
	}
};