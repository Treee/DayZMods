class IAT_ActionAscendOutOfMine extends ActionInteractBase
{
	void IAT_ActionAscendOutOfMine()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Leave Mineshaft";
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

		land_iat_miningsegment_junction mineJunction;
		if (Class.CastTo(mineJunction, target.GetObject()))
		{
			if (mineJunction.IsExit())
			{
				return true;
			}
		}
		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		land_iat_miningsegment_junction mineJunction;
		if (Class.CastTo(mineJunction, action_data.m_Target.GetObject()))
		{
			if (mineJunction.IsExit())
			{
				vector destination = mineJunction.GetTeleportDestination();
				if (destination != vector.Zero)
				{
					MiscGameplayFunctions.IAT_Mining_TeleportCheck(action_data.m_Player, destination);
					// teleported
					// Print("teleported");
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
			UndergroundHandlerClient handler;
			if (Class.CastTo(handler, player.GetUndergroundHandler()))
			{
				handler.IAT_ExitUndergroundMines();
			}
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};