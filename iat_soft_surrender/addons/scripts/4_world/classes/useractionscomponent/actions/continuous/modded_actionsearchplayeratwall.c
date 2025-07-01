#ifdef SurvivorAnims

modded class ActionSearchPlayerAtWall
{
  	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "#SA_search";
		PlayerBase target_player;
		if (Class.CastTo(target_player, target.GetObject()))
		{
			if (target_player.IAT_IsSoftSurrendered())
				m_Text = "#SA_search - Inspect";
		}
	}

  	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// AI debugging
		// return true;

		if (!super.ActionCondition(player, target, item))
			return false;

		PlayerBase target_player;
		if (Class.CastTo(target_player, target.GetObject()))
		{
			if (target_player.IsRestrained())
				return false;

			return target_player.IAT_IsSoftSurrendered();
		}

		return false;
	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase target;
		if (Class.CastTo(target, action_data.m_Target.GetObject()))
		{
			if (target.IsSurrendered())
			{
				target.IAT_SetSoftSurrendered(true);
				target.SetSynchDirty();
				target.AutoCloseSoftSurrender();
			}
		}
    	super.OnFinishProgressServer(action_data);
	}
};

#endif