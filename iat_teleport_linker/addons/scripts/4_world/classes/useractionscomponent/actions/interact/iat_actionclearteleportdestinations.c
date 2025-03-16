class IAT_ActionClearTeleportDestination: ActionInteractBase
{
	void IAT_ActionClearTeleportDestination()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Clear Teleport Destinations";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Clear Teleport Destinations - No Target";
		// target exists
		if (target && target.GetObject())
		{
			IAT_Teleport_Linker linker;
			if (Class.CastTo(linker, item))
			{
				// target is the same object as our anchor teleporter
				if (linker.IsSameObject(target.GetObject()))
				{
					m_Text = string.Format("Clear Teleport Destinations - %1", target.GetObject().GetType());
				}
			}
		}
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;

		IAT_Teleport_Linker linker;
		if (Class.CastTo(linker, item))
		{
			// target is the same object as our anchor teleporter
			if (linker.IsSameObject(target.GetObject()))
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
			// have the server side memory config update itself
			linker.ClearTeleporterDestinations();
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};