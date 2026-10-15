modded class ActionOpenDoors
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// if vanilla lets the door be open
		if (super.ActionCondition(player, target, item))
		{
			IAT_MiningSegment_Colorbase iat_Junction;
			// check our custom walls
			if (Class.CastTo(iat_Junction, target.GetObject()))
			{
				// do not let them be opened
				return false;
			}
			// pass through vanilla
			return true;
		}
		// pass through vanilla
		return false;
	}
};