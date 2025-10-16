class IAT_ActionTurnOnGramophone: ActionInteractBase
{
	void IAT_ActionTurnOnGramophone()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#turn_on";
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_Gramaphone_Colorbase recordPlayer;
		if (Class.CastTo(recordPlayer, item))
		{
			if (recordPlayer.HasRecordAttached())
			{
				if (!recordPlayer.IsPlayingSound())
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		IAT_Gramaphone_Colorbase recordPlayer;
		if (Class.CastTo(recordPlayer, action_data.m_MainItem))
		{
			recordPlayer.SetSoundIsPlaying(true);
			recordPlayer.SetSynchDirty();
		}
	}
}