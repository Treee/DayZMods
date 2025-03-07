class IAT_ActionToggleMuteTransmitterTarget: ActionSingleUseBase
{
	void IAT_ActionToggleMuteTransmitterTarget()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_ON;
		m_Text = "Toggle Mute Transmitter";
	}

  	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		TransmitterBase transmitter;
		// check item in hands is actually a transmitter
		if (Class.CastTo(transmitter, target.GetObject()))
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
		if (Class.CastTo(transmitter, target.GetObject()) && transmitter.IsTransmitter())
		{
			if (transmitter.HasEnergyManager() && transmitter.GetCompEM().IsWorking())
			{
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
		if (Class.CastTo(transmitter, action_data.m_Target.GetObject()))
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
