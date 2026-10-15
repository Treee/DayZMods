modded class ActionTogglePlaceObject
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if vanilla can place object
		if (super.ActionCondition(player, target, item))
		{
			// check if our item is in hands
			if (item.IsInherited(IAT_PersonalTent_Kit))
			{
				// if the player CAN place a personal tent
				if (player.IAT_CanDeployPersonalTent())
				{
					// let them
					return true;
				}
				// they cannot (more than 1 already placed)
				return false;
			}
			// vanilla pass through
			return true;
		}
		// vanilla pass through
		return false;
	}
};