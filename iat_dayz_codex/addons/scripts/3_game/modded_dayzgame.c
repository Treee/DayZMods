modded class DayZGame
{
	protected ref IAT_DayZCodexConfig m_iatDayZCodexConfig;

	void SetIATDayZCodexConfig(IAT_DayZCodexConfig config)
	{
		Print("IAT_DayZCodex Settings Initialized On Server");
		config.PrettyPrint();
		m_iatDayZCodexConfig = config;
	}

	IAT_DayZCodexConfig GetIATDayZCodexConfig()
	{
		// server side check so we do not create a config on the client
		if (g_Game.IsDedicatedServer())
		{
			if (!m_iatDayZCodexConfig)
			{
				IAT_DayZCodexConfig tempConfig = new IAT_DayZCodexConfig();
				m_iatDayZCodexConfig = tempConfig.TryGetDayZCodexConfig();
			}
		}
		return m_iatDayZCodexConfig;
	}

	// Quick way to open the Codex while developing.
	override void OnKeyPress(int key)
	{
		if (key == KeyCode.KC_F6)
		{
			UIManager ui = g_Game.GetUIManager();
			if (ui)
			{
				if (ui.IsMenuOpen(IAT_MENU_COLLECTOR_CODEX))
				{
					UIScriptedMenu m = ui.FindMenu(IAT_MENU_COLLECTOR_CODEX);
					if (m)
						m.Close();
				}
				else if (ui.GetMenu() == null)
				{
					ui.EnterScriptedMenu(IAT_MENU_COLLECTOR_CODEX, null);
				}
			}
		}

		super.OnKeyPress(key);
	}
};
