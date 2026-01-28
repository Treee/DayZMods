modded class MissionBase
{
	protected ref IAT_CodexDictionary m_Codex;

	void MissionBase()
	{
		m_Codex = new IAT_CodexDictionary();
		Print("================================================================= FILL ITEM SCHEMA");
		IAT_Codex_ParseCfgItems(CFG_VEHICLESPATH);
		IAT_Codex_ParseCfgItems(CFG_WEAPONSPATH);
		IAT_Codex_ParseCfgItems(CFG_MAGAZINESPATH);
		m_Codex.PrettyPrint();
	}
	// Hook scripted menu creation to add our own.
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = super.CreateScriptedMenu(id);
		if (id == IAT_MENU_COLLECTOR_CODEX)
		{
			menu = new IAT_CollectorCodexMenu();
		}
		return menu;
	}

	void IAT_Codex_ParseCfgItems(string cfg_path)
	{
		// PrintFormat("Config Path: %1", cfg_path);
		if (g_Game.ConfigIsExisting(cfg_path))
		{
			string className;
			string classPathScope;
			int numRootChildren = g_Game.ConfigGetChildrenCount(cfg_path);
			for(int rootIndex = 0; rootIndex < numRootChildren; rootIndex++)
			{
				g_Game.ConfigGetChildName(cfg_path, rootIndex, className);
				classPathScope = string.Format("%1 %2 scope", cfg_path, className);
				// only scope 2 objects pass this check
				if (g_Game.ConfigGetInt(classPathScope) == 2)
				{
					m_Codex.TryAddType(className);
				}
			}
		}
	}
};
