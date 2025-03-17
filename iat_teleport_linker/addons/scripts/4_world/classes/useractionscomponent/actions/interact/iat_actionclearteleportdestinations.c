class IAT_ActionClearTeleportDestination: ActionSingleUseBase
{
	void IAT_ActionClearTeleportDestination()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM_ONCE;
		m_Text 			= "Clear Teleport Destinations";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget 	= new CCTCursor();
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Clear Teleport Destinations - No Target";
		// target exists
		if (target && target.GetObject())
		{
			IAT_TeleportLinker_Basic linker;
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

		IAT_TeleportLinker_Basic linker;
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

	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);

		IAT_TeleportLinker_Basic linker;
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