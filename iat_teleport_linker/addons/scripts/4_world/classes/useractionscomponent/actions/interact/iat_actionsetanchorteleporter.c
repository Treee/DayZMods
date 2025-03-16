class IAT_ActionSetAnchorTeleporter: ActionInteractBase
{
	void IAT_ActionSetAnchorTeleporter()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Set Anchor Teleporter";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
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
		if (target && target.GetObject())
			return true;

		return false;
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		IAT_Teleport_Linker linker;
		if (Class.CastTo(linker, action_data.m_MainItem))
		{
			// set the main anchor object on the hammer
			linker.SetBaseTeleporterAnchor(action_data.m_Target.GetObject());
			linker.SetSynchDirty();
			// have the server side memory config update itself
			linker.UpdateAnchorTeleporter();
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};