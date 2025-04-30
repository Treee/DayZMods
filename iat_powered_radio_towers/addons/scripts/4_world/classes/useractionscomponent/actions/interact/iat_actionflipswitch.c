class IAT_ActionInteractWallConsoleSwitch: ActionInteractBase
{
	void IAT_ActionInteractWallConsoleSwitch()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Flip Switch";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}
    override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Building building;
		if (Class.CastTo(building, target.GetObject()))
        {
			string name = "";

			if (building.IsActionComponentPartOfSelection(target.GetComponentIndex(), "relay", "view"))
				name = "Relay";
			else if (building.IsActionComponentPartOfSelection(target.GetComponentIndex(), "server", "view"))
				name = "Server";
			else if (building.IsActionComponentPartOfSelection(target.GetComponentIndex(), "cpu", "view"))
				name = "CPU";
			else if (building.IsActionComponentPartOfSelection(target.GetComponentIndex(), "power", "view"))
				name = "Power";

			m_Text = string.Format("Flip Switch - %1", name);
        }
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

			if (wallConsole.IsActionComponentPartOfSelection(target.GetComponentIndex(), "relay", "view"))
			{
				return wallConsole.CanToggleSwitch();
			}
			else if (wallConsole.IsActionComponentPartOfSelection(target.GetComponentIndex(), "server", "view"))
			{
				return wallConsole.CanToggleSwitch();
			}
			else if (wallConsole.IsActionComponentPartOfSelection(target.GetComponentIndex(), "cpu", "view"))
			{
				return wallConsole.CanToggleSwitch();
			}
			else if (wallConsole.IsActionComponentPartOfSelection(target.GetComponentIndex(), "power", "view"))
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
			if (wallConsole.IsActionComponentPartOfSelection(action_data.m_Target.GetComponentIndex(), "relay", "view"))
			{
				wallConsole.ToggleRelay();
				wallConsole.SetSynchDirty();
			}
			else if (wallConsole.IsActionComponentPartOfSelection(action_data.m_Target.GetComponentIndex(), "server", "view"))
			{
				wallConsole.ToggleServer();
				wallConsole.SetSynchDirty();
			}
			else if (wallConsole.IsActionComponentPartOfSelection(action_data.m_Target.GetComponentIndex(), "cpu", "view"))
			{
				wallConsole.ToggleCpu();
				wallConsole.SetSynchDirty();
			}
			else if (wallConsole.IsActionComponentPartOfSelection(action_data.m_Target.GetComponentIndex(), "power", "view"))
			{
				// on consoles can always be turned off
				if (wallConsole.IsPoweredOn())
				{
					wallConsole.TogglePower();
					wallConsole.SetSynchDirty();
				}
				// if we are not powered on AND we can turn on power
				else
				{
					if (wallConsole.CanPowerOn())
					{
						wallConsole.TogglePower();
						wallConsole.SetSynchDirty();
					}
				}

			}
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};