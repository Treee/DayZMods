class IAT_ActionSetTeleportDestination: ActionInteractBase
{
	void IAT_ActionSetTeleportDestination()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Set Teleport Destination";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Set Teleport Destination - No Position";

		IAT_Teleport_Linker linker;
		if (player && Class.CastTo(linker, item))
		{
			if (linker.HasAnchorTeleport())
			{
				m_Text = string.Format("Set Teleport Destination - %1", player.GetPosition());
			}
		}
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_Teleport_Linker linker;
		if (player && Class.CastTo(linker, item))
		{
			if (linker.HasAnchorTeleport())
			{
				return true;
			}
		}
		return false;
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		IAT_Teleport_Linker linker;
		if (Class.CastTo(linker, action_data.m_MainItem))
		{
			// have the server side memory config update itself with the players position
			linker.UpdateTeleporterDestination(action_data.m_Player.GetPosition());
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};