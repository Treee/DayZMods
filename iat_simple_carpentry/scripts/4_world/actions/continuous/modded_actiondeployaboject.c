modded class ActionDeployObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			// only deploy selected options.
			IAT_CarvedSymbol_Kit carvedSymbolKit;
			if (Class.CastTo(carvedSymbolKit, item))
			{
				// if they actually have a selection
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