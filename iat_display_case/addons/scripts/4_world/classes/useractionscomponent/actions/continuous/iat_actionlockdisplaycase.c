class IAT_ActionLockDisplayCaseCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3);
	}
};

class IAT_ActionLockDisplayCase: ActionContinuousBase
{
	void IAT_ActionLockDisplayCase()
	{
		m_CallbackClass = IAT_ActionLockDisplayCaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_HIGH;
		m_Text = "Lock Case";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if there is a not a target, short circuit
		if(!target)
		{
			return false;
		}
		// if the target is our display case
		IAT_DisplayCase_ColorBase displayCase;
		if (Class.CastTo(displayCase, target.GetObject()))
		{
			// and it is not locked
			return !displayCase.IAT_IsDisplayCaseLocked();
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		IAT_DisplayCase_ColorBase displayCase;
		if (Class.CastTo(displayCase, action_data.m_Target.GetObject()))
		{
			displayCase.IAT_SetLocked(true);
			displayCase.SetSynchDirty();
		}
	}
};

class IAT_ActionUnLockDisplayCaseCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(10);
	}
};

class IAT_ActionUnLockDisplayCase: ActionContinuousBase
{
	void IAT_ActionUnLockDisplayCase()
	{
		m_CallbackClass = IAT_ActionUnLockDisplayCaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_HIGH;
		m_Text = "Unlock Case";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if there is a not a target, short circuit
		if(!target)
		{
			return false;
		}
		// if the target is our display case
		IAT_DisplayCase_ColorBase displayCase;
		if (Class.CastTo(displayCase, target.GetObject()))
		{
			// and it is locked
			return displayCase.IAT_IsDisplayCaseLocked();
		}
		return false;
	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		IAT_DisplayCase_ColorBase displayCase;
		if (Class.CastTo(displayCase, action_data.m_Target.GetObject()))
		{
			displayCase.IAT_SetLocked(false);
			displayCase.SetSynchDirty();
		}
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 2.0);
	}
};