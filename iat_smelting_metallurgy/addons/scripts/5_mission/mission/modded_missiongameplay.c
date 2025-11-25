modded class MissionGameplay
{
	override void OnItemUsed(InventoryItem item, Man owner)
	{
		super.OnItemUsed(item, owner);

		IAT_SmeltingFurnace_ColorBase iat_furnace;
		// if the item not a furnace; short circuit
		if (!Class.CastTo(iat_furnace, item))
			return;

		// if the ui manager is not avalable
		if (!g_Game.GetUIManager())
			return;

		IAT_SmeltingMinigameHUD smeltingMenu;
		// if there is no menu open
		if (g_Game.GetUIManager().GetMenu() == null)
		{
			if (Class.CastTo(smeltingMenu, g_Game.GetUIManager().EnterScriptedMenu(IAT_MENU_SMELTING_MINIGAME, null)))
			{
				smeltingMenu.SetFurnace(iat_furnace);
				// min/max temps max ores
				smeltingMenu.SetFurnaceInputValues(iat_furnace.IAT_GetAccelerantHP(), iat_furnace.IAT_GetMinTemperature(), iat_furnace.IAT_GetMaxTemperature(), iat_furnace.IAT_GetMaxOreQuantity(0), iat_furnace.IAT_GetMaxOreQuantity(1));
			}
			return;
		}
		else if (g_Game.GetUIManager().IsMenuOpen(IAT_MENU_SMELTING_MINIGAME)) // our smelting mini game menu is open
		{
			// if the furnace has a client side update to show
			if (iat_furnace.HasClientResultUpdate())
			{
				// if we found the smelting menu
				if (Class.CastTo(smeltingMenu, g_Game.GetUIManager().GetMenu()))
				{
					// update the UI
					smeltingMenu.UpdateWinLossUI();
					// min/max temps max ores
					smeltingMenu.SetFurnaceInputValues(iat_furnace.IAT_GetAccelerantHP(), iat_furnace.IAT_GetMinTemperature(), iat_furnace.IAT_GetMaxTemperature(), iat_furnace.IAT_GetMaxOreQuantity(0), iat_furnace.IAT_GetMaxOreQuantity(1));
				}
				iat_furnace.ResetHasClientResultUpdate();
			}
		}
	}
};