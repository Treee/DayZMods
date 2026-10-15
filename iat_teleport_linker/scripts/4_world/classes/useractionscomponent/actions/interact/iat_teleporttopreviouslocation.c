class IAT_ActionTeleportToPreviousLocation: ActionInteractBase
{
	void IAT_ActionTeleportToPreviousLocation()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Teleport to Previous Location";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;

		Object targetObject;
		if (Class.CastTo(targetObject, target.GetObject()))
		{
			IAT_TeleportLinkData linkData;
			// this ensures anchor teleport doesnt move
			if (Class.CastTo(linkData, GetDayZGame().IAT_IsValidTeleporter(targetObject.GetType(), targetObject.GetPosition())))
			{
				if (player.IAT_HasPreviousLocation())
				{
					// no item required, use the teleporter
					return true;
				}
			}
		}

		return false;
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		Object targetObject;
		if (Class.CastTo(targetObject, action_data.m_Target.GetObject()))
		{
			IAT_TeleportLinkData linkData;
			// link data is true
			if (Class.CastTo(linkData, GetDayZGame().IAT_IsValidTeleporter(targetObject.GetType(), targetObject.GetPosition())))
			{
				if (action_data.m_Player.IAT_HasPreviousLocation())
				{
					vector newPosition = action_data.m_Player.IAT_GetPreviousLocation();
					action_data.m_Player.SetPosition(newPosition);
					action_data.m_Player.IAT_ClearPreviousLocation();
				}
			}
		}
	}

	override void OnEndClient( ActionData action_data )
	{
		super.OnEndClient(action_data);

		action_data.m_Player.IAT_ClearPreviousLocation();
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};