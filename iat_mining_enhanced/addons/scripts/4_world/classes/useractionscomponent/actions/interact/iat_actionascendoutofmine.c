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

		if (!player.IAT_CanInteractWithMineExit())
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

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		land_iat_miningsegment_junction mineJunction;
		if (Class.CastTo(mineJunction, action_data.m_Target.GetObject()))
		{
			if (mineJunction.IsExit())
			{
				vector destination = mineJunction.GetTeleportDestination();
				if (destination != vector.Zero)
				{
					// teleport the player
					MiscGameplayFunctions.IAT_Mining_TeleportCheck(action_data.m_Player, destination, 15);
					// set the timer to allow teleporting back
					action_data.m_Player.SetInteractMineFalse();
					// teleported
					// Print("teleported");
				}
			}
		}
	}

	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		// start underground ambient music loop
		PlayerBase player;
		if (Class.CastTo(player, action_data.m_Player))
		{
			player.StartTeleportTransitionEffects();
			player.UpdateUndergroundVisualEffects(false);
		}
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};