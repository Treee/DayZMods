modded class MissionGameplay
{
	override void OnItemUsed(InventoryItem item, Man owner)
	{
		super.OnItemUsed(item, owner);

		IAT_Codelock_Colorbase iat_codelock;

		// if the item not a codelock; short circuit
		if (!Class.CastTo(iat_codelock, item))
			return;
		// if there is a menu already open; short circuit
		if (GetGame().GetUIManager().GetMenu() != null)
			return;

		IAT_MenuType menuType = iat_codelock.GetMenuType();

		IAT_CodelockPassword_BaseMenu codelockMenu;
		if (menuType == IAT_MenuType.CODELOCK_MANAGER)
		{
			// create a new scripted menu instance for managing the codelock
			if (Class.CastTo(codelockMenu, GetGame().GetUIManager().EnterScriptedMenu(IAT_MENU_CODELOCK_MANAGER, null)))
			{
				// if the menu is created, send the codelock reference to it so we can update things like locked state or combination
				codelockMenu.SetCodelock(iat_codelock);
			}
		}
		else if (menuType == IAT_MenuType.PASSCODE_ENTRY)
		{
			// create a new scripted menu instance for entering the password for the codelock
			if (Class.CastTo(codelockMenu, GetGame().GetUIManager().EnterScriptedMenu(IAT_MENU_CODELOCK_ENTRY, null)))
			{
				// if the menu is created, send the codelock reference to it so the menu can do password comparrison
				codelockMenu.SetCodelock(iat_codelock);
			}
		}
	}
};