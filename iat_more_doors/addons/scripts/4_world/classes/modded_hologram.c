modded class Hologram
{
	override string GetProjectionName(ItemBase item)
	{
		// when our door kits are in hand
		IAT_MoreDoor_Kit doorKit;
		if (Class.CastTo(doorKit, item))
		{
			// swap the hologram to the door selected
			string hologramName = doorKit.GetDoorClassNameFromSelection();
			if (hologramName != "")
			{
				return hologramName;
			}
		}
		return super.GetProjectionName(item);
	}
};