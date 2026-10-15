modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = NULL;
		if (id == IAT_DYNAMICRADIO_MENU_RADIAL_MULTI)
			menu = new IAT_DR_RadialMenuDisplay;

		if (menu)
		{
			menu.SetID(id);
			return menu;
		}
		return super.CreateScriptedMenu(id);
	}
};