modded class ActionMineRock
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if the vanilla code returns false
		if (!super.ActionCondition(player, target, item))
		{
			// check our custom walls
		}
		//super returns true, pass it through
		return true;
	}
};