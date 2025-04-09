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
};

#endif