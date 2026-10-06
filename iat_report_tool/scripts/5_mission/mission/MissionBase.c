modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = super.CreateScriptedMenu(id);
		if (id == IAT_MENU_REPORTTOOL_MENU)
		{
			menu = new IAT_ReportMenu();
			menu.SetID(id);
		}
		return menu;
	}
};
