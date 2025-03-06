modded class WoodBase
{
	override int GetAmountOfDrops(ItemBase item)
	{
		// get the value the other code would return
		int amount = super.GetAmountOfDrops(item);
		// if the item is our multi tool
		if (item && item.IAT_IsMultiTool())
		{
			// if we have more than 0 primary drops
			if ( GetPrimaryDropsAmount() > 0 )
			{
				// check if the thing is a tree
				if (IsTree())
					amount = -1; // no items added if it is
				else
					amount = GetPrimaryDropsAmount(); // get the number of drops for bushes and other stuff
			}
			else // we have no more drops available
			{
				amount = -1; // return no quantity
			}
		}
		// return the amount
		return amount;
	}

	override void GetMaterialAndQuantityMap(ItemBase item, out map<string,int> output_map)
	{
		// do vanilla stuff
		super.GetMaterialAndQuantityMap(item, output_map);

		// if the item is our multi tool
		if ( IsTree() && item && item.IAT_IsMultiTool() && GetBarkType() != "" )
		{
			// let it cut bark
			output_map.Insert(GetBarkType(), 1);
		}
	}

	override float GetDamageToMiningItemEachDrop(ItemBase item)
	{
		// get the damage for the tool
		float toolDamage = super.GetDamageToMiningItemEachDrop(item);
		// if it has damage, use it
		if (toolDamage > -1)
			return toolDamage;

		// otherwise, if this is a tree
		if ( IsTree() )
		{	// and our multi tool, do 20 dmg
			if (item && item.IAT_IsMultiTool())
			{
				toolDamage = 20;
			}
		}
		else // not a tree
		{   // and our multi tool, do 30 dmg
			if (item && item.IAT_IsMultiTool())
			{
				toolDamage = 30;
			}
		}
		return toolDamage;
	}
};