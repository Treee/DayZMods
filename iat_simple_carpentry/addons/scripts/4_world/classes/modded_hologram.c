modded class Hologram
{
	override string GetProjectionName(ItemBase item)
	{
		// when our door kits are in hand
		IAT_CarvedSymbol_Kit carvedLetterKit;
		if (Class.CastTo(carvedLetterKit, item))
		{
			// swap the hologram to the door selected
			string hologramName = carvedLetterKit.GetSymbolClassNameFromSelection();
			if (hologramName != "")
			{
				return hologramName;
			}
		}
		return super.GetProjectionName(item);
	}
};