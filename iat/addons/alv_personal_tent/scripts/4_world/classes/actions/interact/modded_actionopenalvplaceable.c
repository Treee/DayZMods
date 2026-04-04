modded class ActionOpenALVPlaceable
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// preserve vanilla chain
		// a true super call will verify if our target exists
		// and is our deployable base so im not duplicating those checks
		if (super.ActionCondition(player, target, item))
		{
			// if our target is a personal tent
			IAT_PersonalTent_ColorBase personalTent;
			if (Class.CastTo(personalTent, target.GetObject()))
			{
				// if we are the owner of that tent
				if (personalTent.IAT_CanOpenPersonalTent(player.GetIdentity()))
				{
					return true;
				}
				// we are not the owner so do not show open
				return false;
			}
			// preserve vanilla call chain
			return true;
		}
		// preserve vanilla call chain
		return false;
	}
};