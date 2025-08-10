class IAT_ActionDescendIntoMine extends ActionInteractBase
{
	void IAT_ActionDescendIntoMine()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Enter Mineshaft";
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

		land_iat_miningsegment_entrance mineEntrance;
		if (Class.CastTo(mineEntrance, target.GetObject()))
		{
			if (mineEntrance.CanEnterMine())
			{
				return true;
			}
		}
		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		land_iat_miningsegment_entrance mineEntrance;
		if (Class.CastTo(mineEntrance, action_data.m_Target.GetObject()))
		{
			if (mineEntrance.CanEnterMine())
			{
				vector destination = mineEntrance.GetTeleportDestination();
				if (destination != vector.Zero)
				{
					if (MiscGameplayFunctions.TeleportPlayerToSafeLocation3D(action_data.m_Player, destination))
					{
						// teleported
						// Print("teleported");
					}
				}
			}
		}
	}

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		// start underground ambient music loop
		PlayerBase player;
		if (Class.CastTo(player, action_data.m_Player))
		{
			player.StartUndergroundMusic();
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		land_iat_miningsegment_entrance mineEntrance;
		if (Class.CastTo(mineEntrance, action_data.m_Target.GetObject()))
		{
			return string.Format(" teleported using a mine entrance: %1 ", action_data.m_Target.GetObject().GetPosition());
		}
		return "";
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};