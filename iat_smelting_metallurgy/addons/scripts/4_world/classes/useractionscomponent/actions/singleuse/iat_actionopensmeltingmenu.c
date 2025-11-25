class IAT_ActionOpenSmeltingMenu extends ActionInteractBase
{
	void IAT_ActionOpenSmeltingMenu()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Start Smelting";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// if vanilla passes, make sure we have accelerant and ore attached
		if (super.ActionCondition(player, target, item))
		{
			IAT_SmeltingFurnace_ColorBase furnace;
			if (Class.CastTo(furnace, target.GetObject()))
			{
				return furnace.IAT_CanOpenMiniGameMenu();
			}
		}
		// vanilla didnt pass so do not return true
		return false;
	}

	override void OnExecuteClient( ActionData action_data )
	{
		super.OnExecuteClient(action_data);
		IAT_SmeltingFurnace_ColorBase furnace;
		if (Class.CastTo(furnace, action_data.m_Target.GetObject()))
		{
			furnace.IAT_OpenMiniGameMenu();
		}
	}
};