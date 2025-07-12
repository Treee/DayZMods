modded class ActionDeployObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			// only deploy selected options.
			IAT_MoreDoor_Kit doorKit;
			if (Class.CastTo(doorKit, item))
			{
				// if they actually have a selection
				if (doorKit.HasDoorKitSelection())
				{
					return true;
				}
				return false;
			}
			return true;
		}
		return false;
	}
};