class IAT_ActionSetTeleportDestination: ActionSingleUseBase
{
	void IAT_ActionSetTeleportDestination()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM_ONCE;
		m_Text 			= "Set Teleport Destination";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget 	= new CCTNone();
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Set Teleport Destination - No Position";

		IAT_TeleportLinker_Basic linker;
		if (player && Class.CastTo(linker, item))
		{
			if (linker.HasAnchorTeleport())
			{
				m_Text = string.Format("Set Teleport Destination - %1", player.GetPosition().ToString());
			}
		}
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_TeleportLinker_Basic linker;
		if (player && Class.CastTo(linker, item))
		{
			if (linker.HasAnchorTeleport())
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);

		IAT_TeleportLinker_Basic linker;
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