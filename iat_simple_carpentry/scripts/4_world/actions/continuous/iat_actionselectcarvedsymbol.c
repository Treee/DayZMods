class IAT_ActionSelectCarvedSymbolOptionCB extends ActionContinuousBaseCB
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
		if (pCurrentState == STATE_NONE && (!g_Game.IsDedicatedServer()))
		{
			if (g_Game.GetUIManager() && g_Game.GetUIManager().IsMenuOpen(IAT_SC_MENU_RADIAL_MULTI))
				g_Game.GetUIManager().FindMenu(IAT_SC_MENU_RADIAL_MULTI).Close();
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && (!g_Game.IsDedicatedServer()))
		{
      		g_Game.GetUIManager().EnterScriptedMenu(IAT_SC_MENU_RADIAL_MULTI, g_Game.GetUIManager().GetMenu());
		}
	}
};

class IAT_ActionSelectCarvedSymbolOption extends ActionContinuousBase
{
  	void IAT_ActionSelectCarvedSymbolOption()
	{
		m_CallbackClass = IAT_ActionSelectCarvedSymbolOptionCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_CRAFTING;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    	m_Text = "Select Carved Symbol";
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
  	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return true;
	}
  	override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		// end the action when the menu closes
		if(!g_Game.IsDedicatedServer())
		{
			if (action_data.m_State == UA_FINISHED && g_Game.GetUIManager() && !g_Game.GetUIManager().IsMenuOpen(IAT_SC_MENU_RADIAL_MULTI))
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
  	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		PlayerBase player;
		if (Class.CastTo(player, action_data.m_Player))
		{
			IAT_CarvedSymbol_Kit carvedSymbolKit;
			if (Class.CastTo(carvedSymbolKit, action_data.m_MainItem))
			{
				carvedSymbolKit.SetCarvedSymbolSelection(player.IAT_GetCarvedSymbolSelection());
			}
		}
	}
	override void OnEndClient( ActionData action_data )
	{
		super.OnEndClient(action_data);

		PlayerBase player;
		if (Class.CastTo(player, action_data.m_Player))
		{
			IAT_CarvedSymbol_Kit carvedSymbolKit;
			if (Class.CastTo(carvedSymbolKit, action_data.m_MainItem))
			{
				carvedSymbolKit.SetCarvedSymbolSelection(player.IAT_GetCarvedSymbolSelection());
			}
		}
	}

};
