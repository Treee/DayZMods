modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = NULL;
		if (id == IAT_SC_MENU_RADIAL_MULTI)
			menu = new IAT_SC_RadialMenuDisplay;

		if (menu)
		{
			menu.SetID(id);
			return menu;
		}
		return super.CreateScriptedMenu(id);
	}
};