class IAT_ActionPaintFaceCB extends ActionContinuousBaseCB
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
			if (GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(IAT_MENU_RADIAL_MULTI))
				GetGame().GetUIManager().FindMenu(IAT_MENU_RADIAL_MULTI).Close();
		}
		else if (pCurrentState == STATE_LOOP_LOOP && pOldState != STATE_LOOP_LOOP && (!GetGame().IsDedicatedServer()))
		{
      		GetGame().GetUIManager().EnterScriptedMenu(IAT_MENU_RADIAL_MULTI, GetGame().GetUIManager().GetMenu());
		}
	}
};

class IAT_ActionPaintFace extends ActionContinuousBase
{
  	void IAT_ActionPaintFace()
	{
		m_CallbackClass = IAT_ActionPaintFaceCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_SHAVE;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    	m_Text = "Paint Face";
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
		PlayerBase man;
		if (target && Class.CastTo(man, target.GetObject()) )
			return false;

		EntityAI equipedMask = player.FindAttachmentBySlotName("Mask");

		EntityAI equipedGlasses = player.FindAttachmentBySlotName("Eyewear");

		// cannot apply when wearing eyewear or masks
		return !(equipedMask || equipedGlasses);
	}
  	override void OnUpdate(ActionData action_data)
	{
		super.OnUpdate(action_data);

		// end the action when the menu closes
		if(!GetGame().IsDedicatedServer())
			if (action_data.m_State == UA_FINISHED && GetGame().GetUIManager() && !GetGame().GetUIManager().IsMenuOpen(IAT_MENU_RADIAL_MULTI))
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

		IAT_FacePaintStick_ColorBase paintStick;
		if (Class.CastTo(paintStick, action_data.m_MainItem))
		{
			paintStick.SetCamoIndex(action_data.m_Player.m_TempFacePaintCategory, action_data.m_Player.m_TempFacePaintIndex);
			paintStick.OnApply(action_data.m_Player);
		}
	}
};

class IAT_ActionPaintFaceTarget extends IAT_ActionPaintFace
{
	void IAT_ActionPaintFaceTarget()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
    	m_Text = "Paint Face - Target";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
	override bool HasTarget()
	{
		return true;
	}
  	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase man;
		if (target && Class.CastTo(man, target.GetObject()) )
		{
			EntityAI equipedMask = man.FindAttachmentBySlotName("Mask");

			EntityAI equipedGlasses = man.FindAttachmentBySlotName("Eyewear");

			// cannot apply when wearing eyewear or masks
			return !(equipedMask || equipedGlasses);
    	}
    	return false;
	}
  	override void OnEndServer(ActionData action_data)
	{
		IAT_FacePaintStick_ColorBase paintStick;
		if (!Class.CastTo(paintStick, action_data.m_MainItem))
			return;

		PlayerBase targetPlayer;
		if (!Class.CastTo(targetPlayer, action_data.m_Target.GetObject()) )
			return;

		PlayerBase currentPlayer;
		if (!Class.CastTo(currentPlayer, action_data.m_Player))
			return;

		paintStick.SetCamoIndex(currentPlayer.m_TempFacePaintCategory, currentPlayer.m_TempFacePaintIndex);
		paintStick.OnApply(targetPlayer);
	}
};