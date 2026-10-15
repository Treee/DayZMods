modded class Clothing
{
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		super.OnWasAttached(parent, slot_id);
		// forward declare the player variable
		PlayerBase player;
		// attempt to cast parent into the player shape (parent could be a locker or the ground so only consider players)
		if(Class.CastTo(player, parent))
		{
			// forward declare the player variable
			ItemBase clothingItem;
			// attempt to cast this clothing into an itembase shape
			if (Class.CastTo(clothingItem, this))
			{
				// get the chemical protection level of the clothing
				float protection = clothingItem.GetProtectionLevel(DEF_CHEMICAL);
				// if that protection is greater than 0
				if (protection > 0)
				{
					// add it to our overall protection
					player.ModifyChemicalProtection(protection);
				}
				// get the biological protection level of the clothing
				protection = clothingItem.GetProtectionLevel(DEF_BIOLOGICAL);
				// if that protection is greater than 0
				if (protection > 0)
				{
					// add it to our overall protection
					player.ModifyBiologicalProtection(protection);
				}
			}
		}
	}
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);

		// forward declare the player variable
		PlayerBase player;
		// attempt to cast parent into the player shape (parent could be a locker or the ground so only consider players)
		if(Class.CastTo(player, parent))
		{
			// forward declare the player variable
			ItemBase clothingItem;
			// attempt to cast this clothing into an itembase shape
			if (Class.CastTo(clothingItem, this))
			{
				// get the chemical protection level of the clothing
				float protection = clothingItem.GetProtectionLevel(DEF_CHEMICAL);
				// if that protection is greater than 0
				if (protection > 0)
				{
					// subtract it from our overall protection
					player.ModifyChemicalProtection(-protection);
				}
				// get the biological protection level of the clothing
				protection = clothingItem.GetProtectionLevel(DEF_BIOLOGICAL);
				// if that protection is greater than 0
				if (protection > 0)
				{
					// add it to our overall protection
					player.ModifyBiologicalProtection(protection);
				}
			}
		}
	}
};