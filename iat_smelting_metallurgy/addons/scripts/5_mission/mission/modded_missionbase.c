modded class MissionBase
{
	// hooking into the existing scripted menu creation to add our own
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		// call vanilla first
		UIScriptedMenu menu = super.CreateScriptedMenu(id);
		// if the menu id requested matches our dialog menu const
		if (id == IAT_MENU_SMELTING_MINIGAME)
		{
			// create a new codelock dialog menu instance
			menu = new IAT_SmeltingMinigameHUD();
			menu.SetID(id);
		}
		// return the menu instanc
		return menu;
	}
};