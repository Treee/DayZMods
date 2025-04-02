class IAT_ActionToggleMuteTransmitter: ActionSingleUseBase
{
	void IAT_ActionToggleMuteTransmitter()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_ON;
		m_Text = "Toggle Mute Transmitter";
	}

  	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		TransmitterBase transmitter;
		// check item in hands is actually a transmitter
		if (Class.CastTo(transmitter, item))
		{
			if (transmitter.IAT_IsMuted())
			{
				m_Text = "Toggle Radio Mute - Currently Muted";
			}
			else
			{
				m_Text = "Toggle Radio Mute - Currently Transmitting";
			}
		}
	}

  	override bool HasTarget()
	{
		return false;
	}

  	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
    	TransmitterBase transmitter;
		// check item in hands
		if (Class.CastTo(transmitter, item) && transmitter.IsTransmitter())
		{
			if (transmitter.HasEnergyManager() && transmitter.GetCompEM().IsWorking())
			{
				// dont let the action show when world radio is active
				#ifdef AdmiralsWorldRadioModMod
				if (transmitter.IsRadioMode())
					return false;
				#endif
				return true;
			}
		}

		// check target consoles
		// TransmitterBase transmitter;
		// if (Class.CastTo(transmitter, item) && transmitter.IsTransmitter())
		// {
		// 	if (transmitter.HasEnergyManager() && transmitter.GetCompEM().IsWorking())
		// 	{
		// 		return true;
		// 	}
		// }

		return false;
  	}

	override void OnExecuteServer( ActionData action_data )
	{
    	TransmitterBase transmitter;
		if (Class.CastTo(transmitter, action_data.m_MainItem))
		{
			if(!transmitter.IAT_IsMuted())
			{
        		SendMessageToClient( action_data.m_Player, "Transmitter Muted" );
				transmitter.IAT_MuteTransmitter();
			}
			else
			{
        		SendMessageToClient( action_data.m_Player, "Transmitter UnMuted" );
				transmitter.IAT_UnMuteTransmitter();
			}
		}
  	}
};