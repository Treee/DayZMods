modded class MissionBase
{
	// hooking into the existing scripted menu creation to add our own
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		// call vanilla first
		UIScriptedMenu menu = super.CreateScriptedMenu(id);
		// if the menu id requested matches our dialog menu const
		if (id == IAT_MENU_REPORTTOOL_MENU)
		{
			// create a new menu instance
			menu = new IAT_ReportMenu();
			menu.SetID(id);
		}
		// return the menu instance
		return menu;
	}
};