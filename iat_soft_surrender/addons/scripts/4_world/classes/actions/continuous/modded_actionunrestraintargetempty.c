modded class ActionUnrestrainTargetHands
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if we can be restrained
		if (super.ActionCondition(player, target, item))
		{
			PlayerBase otherPlayer;
			if (Class.CastTo(otherPlayer, target.GetObject()))
			{
				// pass through targets that are soft surrendered
				if (otherPlayer.IAT_IsSoftSurrendered())
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
};