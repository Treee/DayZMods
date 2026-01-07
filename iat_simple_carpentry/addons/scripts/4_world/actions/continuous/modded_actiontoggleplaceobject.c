modded class ActionTogglePlaceObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			// only show toggle action if we actually have a kit option selected
			IAT_CarvedSymbol_Kit carvedSymbolKit;
			if (Class.CastTo(carvedSymbolKit, item))
			{
				// only if it has an actual selection
				if (carvedSymbolKit.HasCarvedSymbolSelection())
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