class IAT_ActionFlipCard: ActionInteractBase
{
	void IAT_ActionFlipCard()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		return "Flip Card";
	}

  	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target )
		{
			return false;
		}

		IAT_CardBase playingCard;
		if (Class.CastTo(playingCard, target.GetObject()))
		{
			return true;
		}
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		IAT_CardBase playingCard;
		if (Class.CastTo(playingCard, action_data.m_Target.GetObject()))
		{
			playingCard.Flip();
		}
	}
};