modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = NULL;
		if (id == IAT_MENU_RADIAL_MULTI)
			menu = new IAT_FP_RadialMenuItem;

		if (menu)
		{
			menu.SetID(id);
			return menu;
		}
		return super.CreateScriptedMenu(id);
	}
};