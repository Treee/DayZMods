class IAT_InfinityGauntlet_SnapAction: ActionSingleUseBase
{

	void IAT_InfinityGauntlet_SnapAction()
	{
		m_CommandUID = DayZPlayerConstants.CMD_GESTUREMOD_TAUNTKISS; //DayZPlayerConstants.CMD_ACTIONMOD_CLEANHANDSBOTTLE;
		m_CommandUIDProne = DayZPlayerConstants.CMD_GESTUREFB_TAUNTKISS; //DayZPlayerConstants.CMD_ACTIONFB_CLEANHANDSBOTTLE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "Snap Fingers";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINotRuinedAndEmpty;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool HasProneException()
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_InfinityGauntlet_ColorBase infinityGauntlet;
		if (Class.CastTo(infinityGauntlet, item))
		{
			return infinityGauntlet.HasAllStones();
		}
		return false;
	}

	override void OnEndServer( ActionData action_data )
	{
		super.OnEndServer(action_data);

		if (action_data.m_State != UA_CANCEL)
		{
			IAT_InfinityGauntlet_ColorBase infinityGauntlet;
			if (Class.CastTo(infinityGauntlet, action_data.m_MainItem))
			{
				infinityGauntlet.BalanceTheUniverse();
			}
		}
	}
};