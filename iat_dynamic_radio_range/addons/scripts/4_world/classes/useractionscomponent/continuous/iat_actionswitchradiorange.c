class IAT_ActionSwitchRadioRangeCB extends ActionContinuousBaseCB
{
 	override void EndActionComponent()
	{
	}
	override void CreateActionComponent()
	{
    	EnableStateChangeCallback();
		m_ActionData.m_ActionComponent = new CAContinuousTime(-1.0);
	}
  	override void OnStateChange(int pOldState, int pCurrentState)
	{
		if (pCurrentState == STATE_NONE && (!GetGame().IsDedicatedServer()))
		{
			if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(IAT_DYNAMICRADIO_MENU_RADIAL_MULTI))
				GetGame().GetUIManager().FindMenu(IAT_DYNAMICRADIO_MENU_RADIAL_MULTI).Close();
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && (!GetGame().IsDedicatedServer()))
		{
      		GetGame().GetUIManager().EnterScriptedMenu(IAT_DYNAMICRADIO_MENU_RADIAL_MULTI, GetGame().GetUIManager().GetMenu());
		}
	}
};

class IAT_ActionSwitchRadioRange extends ActionContinuousBase
{
  	void IAT_ActionSwitchRadioRange()
	{
		m_CallbackClass = IAT_ActionSwitchRadioRangeCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ITEM_TUNE;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_ITEM_TUNE;
		// m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		// m_FullBody = false;
		// m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    	m_Text = "Change Radio Range";
	}
	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINonRuined;
	}
  	// override bool CanBeUsedLeaning()
	// {
	// 	return true;
	// }
	override bool HasProneException()
	{
		return true;
	}

	override bool HasTarget()
	{
		return false;
	}

  	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// check to see if the radio is on and working.
		PersonalRadio radio;
		if (Class.CastTo(radio, item))
		{
			if (radio.GetCompEM().IsWorking())
			{
				return true;
			}
		}
		return false;
	}
  	override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		// end the action when the menu closes
		if(!GetGame().IsDedicatedServer())
			if (action_data.m_State == UA_FINISHED && GetGame().GetUIManager() && !GetGame().GetUIManager().IsMenuOpen(IAT_DYNAMICRADIO_MENU_RADIAL_MULTI))
				ActionManagerClient.Cast(action_data.m_Player.GetActionManager()).RequestEndAction();
	}
	override void OnEndRequest(ActionData action_data)
	{
		// on end request just sends an interupt command
		if (action_data.m_Callback)
			action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
	}
  	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		PlayerBase player;
		if (Class.CastTo(player, action_data.m_Player))
		{
			// lambda swap radio in hands for radio range selected
			string yieldResult = player.IAT_GetRadioClassNameFromRange();
			if (yieldResult != "")
			{
				IAT_ReplaceRadioWithNewRange lambda = new IAT_ReplaceRadioWithNewRange(action_data.m_MainItem, yieldResult, player);
				lambda.SetTransferParams(true, true, true);
				player.ServerReplaceItemWithNew(lambda);
			}
		}
	}
};