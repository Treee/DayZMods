class IAT_ActionReadBook extends ActionSingleUseBase
{
	void IAT_ActionReadBook()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	override bool HasTarget()
	{
		return false;
	}
	override string GetText()
	{
		return "#read";
	}
	override void OnExecuteClient( ActionData action_data )
	{
        PlayerBase player;
        ItemBook book;
        // sanity check
        if (Class.CastTo(player, action_data.m_Player) && Class.CastTo(book, action_data.m_MainItem))
        {
            if (GetGame().GetMission())
            {
                // do vanilla dance
                GetGame().GetMission().OnItemUsed(book, player);
            }
        }
	}
};
