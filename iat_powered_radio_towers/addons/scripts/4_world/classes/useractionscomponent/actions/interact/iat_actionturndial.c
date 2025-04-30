class IAT_ActionInteractWallConsoleDial: ActionInteractBase
{
	void IAT_ActionInteractWallConsoleDial()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Turn Dial";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// if target, player exists and the target is a 'building' withing range
		if (!target)
			return false;
		if( !IsBuilding(target) )
			return false;
		if (!player)
			return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) )
			return false;


		StaticObj_iat_wallconsole wallConsole;
		if (Class.CastTo(wallConsole, target.GetObject()))
		{
			// at this point the server wont know what the player is looking at but we know we are looking at the right thing
			if (GetGame().IsDedicatedServer())
				return true;

			if (wallConsole.IsActionComponentPartOfSelection(target.GetComponentIndex(), "dial", "view"))
			{
				return true;
			}
		}
		else
			return false;

		return false;
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		StaticObj_iat_wallconsole wallConsole;
		if (Class.CastTo(wallConsole, action_data.m_Target.GetObject()))
		{
			if (wallConsole.IsActionComponentPartOfSelection(action_data.m_Target.GetComponentIndex(), "dial", "view"))
			{
				wallConsole.TurnDial();
				wallConsole.SetSynchDirty();
			}
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};