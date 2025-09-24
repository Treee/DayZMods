class IAT_ActionOpenBoosterPack: ActionSingleUseBase
{
	void IAT_ActionOpenBoosterPack()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTYSEEDSPACK;
		m_FullBody = false;
		m_Text = "Open Booster Pack";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return true;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		IAT_BoosterPack_ColorBase boosterPack;
		if (Class.CastTo(boosterPack, action_data.m_MainItem))
		{
			boosterPack.OpenBoosterPack();
			boosterPack.DeleteSafe();
		}
	}
};