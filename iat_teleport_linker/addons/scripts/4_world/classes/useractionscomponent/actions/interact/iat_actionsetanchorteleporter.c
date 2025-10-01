class IAT_ActionSetAnchorTeleporter: ActionSingleUseBase
{
	void IAT_ActionSetAnchorTeleporter()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM_ONCE;
		m_Text 			= "Set Anchor Teleporter";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget 	= new CCTCursor();
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Set Anchor Teleporter - No Target";
		if (target && target.GetObject())
		{
			m_Text = string.Format("Set Anchor Teleporter - %1", target.GetObject().GetType());
		}
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;

		// let any object pass
		if (target.GetObject())
			return true;

		return false;
	}

	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);

		IAT_TeleportLinker_Basic linker;
		if (Class.CastTo(linker, action_data.m_MainItem))
		{
			// set the main anchor object on the hammer
			linker.SetBaseTeleporterAnchor(action_data.m_Target.GetObject());
			// have the server side memory config update itself
			linker.UpdateAnchorTeleporter();
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};