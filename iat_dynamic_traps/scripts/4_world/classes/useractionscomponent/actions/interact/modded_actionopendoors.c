modded class ActionOpenDoors
{
	override void OnEndServer( ActionData action_data )
	{
		super.OnEndServer(action_data);
		House dynamicHouse;
		if( Class.CastTo(dynamicHouse, action_data.m_Target.GetObject()))
		{
			if (dynamicHouse.IsTrappedObject())
			{
				dynamicHouse.IAT_DoRandomDoorOpenEvent();
			}
		}
	}
};

modded class ActionCloseDoors
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if a door has been opened and a random event happened, dont let it close until some time passes
		House dynamicHouse;
		if( Class.CastTo(dynamicHouse, target.GetObject()))
		{
			// if a random event has been performed on this house
			if (dynamicHouse.IAT_HasRandomEventPerformed())
				return false; // dont allow the doors to be closed for some time
			// if the house is not on cooldown, set it being checked
			if (!dynamicHouse.IAT_IsInCooldown())
				dynamicHouse.IAT_SetHasBeenChecked(true);
		}
		// continue vanilla close doors stuff
		return super.ActionCondition(player, target, item);
	}
};
