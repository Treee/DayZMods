class IAT_ActionReadPaperTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		EnableStateChangeCallback();
		m_ActionData.m_ActionComponent = new CAContinuousTime(-1.0);
	}

	override void EndActionComponent(){}

	override void OnStateChange(int pOldState, int pCurrentState)
	{
		if (pCurrentState == STATE_NONE && (!GetGame().IsDedicatedServer()))
		{
			if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(MENU_NOTE))
				GetGame().GetUIManager().FindMenu(MENU_NOTE).Close();
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && (!GetGame().IsMultiplayer() || GetGame().IsServer()))
		{
			Paper paper;
			if (m_ActionData.m_Target && Class.CastTo(paper, m_ActionData.m_Target.GetObject()))
			{
				Param1<string> text = new Param1<string>(paper.GetWrittenNoteData().GetNoteText());
				paper.RPCSingleParam(ERPCs.RPC_READ_NOTE, text, true, m_ActionData.m_Player.GetIdentity());
			}
		}
	}
};

class IAT_ActionReadPaperTarget: ActionContinuousBase
{
	void IAT_ActionReadPaperTarget()
	{
		m_CallbackClass = IAT_ActionReadPaperTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_VIEWNOTE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		m_Text = "#read";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
    	m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        Paper paper;
        if (Class.CastTo(paper, target.GetObject()))
            return paper.GetHasWrittenText();

		return false;
	}
	override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		if(!GetGame().IsDedicatedServer())
		{
			if (action_data.m_State == UA_FINISHED && GetGame().GetUIManager() && !GetGame().GetUIManager().IsMenuOpen(MENU_NOTE))
			{
				ActionManagerClient.Cast(action_data.m_Player.GetActionManager()).RequestEndAction();
			}
		}
	}
	override void OnEndRequest(ActionData action_data)
	{
		if (action_data.m_Callback)
		{
			action_data.m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		}
	}
};