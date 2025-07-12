modded class ActionTogglePlaceObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			// only show toggle action if we actually have a kit option selected
			IAT_MoreDoor_Kit doorKit;
			if (Class.CastTo(doorKit, item))
			{
				// only if it has an actual selection
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