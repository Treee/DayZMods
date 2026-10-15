class IAT_ActionRingBellTower extends ActionInteractBase
{
	void IAT_ActionRingBellTower()
	{
		m_Text = "Ring Bell Tower";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if no target, sanity check
		if (!target)
			return false;

		// get the target
		Object targetObject;
		if (Class.CastTo(targetObject, target.GetObject()))
		{
			// get the belltower
			IAT_BellTower_ColorBase bellTower;
			if (Class.CastTo(bellTower, targetObject))
			{
				// if we have an energy manager AND can switch on
				if (bellTower.CanRingTower())
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
			IAT_BellTower_ColorBase bellTower;
			if (Class.CastTo(bellTower, targetObject))
			{
      			bellTower.RingBellTower();
			}
		}
	}
};