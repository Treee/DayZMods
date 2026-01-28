class IAT_ActionOpenDayZCodexCB extends ActionContinuousBaseCB
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
		if (pCurrentState == STATE_NONE && !GetGame().IsDedicatedServer())
		{
			if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(IAT_MENU_COLLECTOR_CODEX))
			{
				GetGame().GetUIManager().FindMenu(IAT_MENU_COLLECTOR_CODEX).Close();
			}
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && !GetGame().IsDedicatedServer())
		{
      		GetGame().GetUIManager().EnterScriptedMenu(IAT_MENU_COLLECTOR_CODEX, GetGame().GetUIManager().GetMenu());
		}
	}
};

class IAT_ActionOpenDayZCodex extends ActionContinuousBase
{
  	void IAT_ActionOpenDayZCodex()
	{
		m_CallbackClass = IAT_ActionOpenDayZCodexCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
    	m_Text = "Open Codex";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}
  	override bool CanBeUsedLeaning()
	{
		return true;
	}
	override bool HasTarget()
	{
		return false;
	}
  	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_DayZCodex_ColorBase codex;
		// is the item in hands a codex?
		if (Class.CastTo(codex, item))
		{
			// if the codex can be opened by this player
			if (codex.CanBeOpened(player.GetIdentity()))
			{
				return true;
			}
		}
		// if not, return false
		return false;
	};
  	override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		// end the action when the menu closes
		if(!g_Game.IsDedicatedServer())
		{
			if (action_data.m_State == UA_FINISHED && g_Game.GetUIManager() && !g_Game.GetUIManager().IsMenuOpen(IAT_MENU_COLLECTOR_CODEX))
			{
				ActionManagerClient.Cast(action_data.m_Player.GetActionManager()).RequestEndAction();
			}
		}
	}
	override void OnEndRequest(ActionData action_data)
	{
		// on end request just sends an interupt command
		if (action_data.m_Callback)
		{
			action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		}
	}
};