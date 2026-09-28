class IAT_ActionOpenLootBox: ActionSingleUseBase
{
	void IAT_ActionOpenLootBox()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTYSEEDSPACK;
		m_FullBody = false;
		m_Text = "Open Loot Box";
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
		IAT_LootBox_ColorBase lootBox;
		if (Class.CastTo(lootBox, action_data.m_MainItem))
		{
			lootBox.OpenLootBox();
			lootBox.DeleteSafe();
		}
	}
};