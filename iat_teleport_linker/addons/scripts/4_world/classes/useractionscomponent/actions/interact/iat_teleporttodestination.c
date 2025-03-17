class IAT_ActionTeleportToDestination: ActionInteractBase
{
	void IAT_ActionTeleportToDestination()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Teleport";
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
				// does the palyer have the correct key card in hand

				return true;
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
			if (Class.CastTo(linkData, GetDayZGame().IAT_IsValidTeleporter(targetObject.GetType(), targetObject.GetPosition())))
			{
				// link data is true
				vector newPosition = linkData.GetTeleporterDestination();
				action_data.m_Player.SetPosition(newPosition);
			}
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};