modded class MissionBase
{
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
};
