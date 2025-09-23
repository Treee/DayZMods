class IAT_ActionTurnOnPortalSteampunk: ActionInteractBase
{
	void IAT_ActionTurnOnPortalSteampunk()
	{
		m_Text = "#switch_on";
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
			// get the portal
			StaticObj_Furniture_UniqueItem_Portal_Steampunk_chunkyhedgehog portal;
			if (Class.CastTo(portal, targetObject))
			{
				// if we have an energy manager AND can switch on
				if (portal.CanSwitchOn())
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
			EntityAI target_EAI = EntityAI.Cast( targetObject );
			target_EAI.GetCompEM().SwitchOn();
		}
	}
};