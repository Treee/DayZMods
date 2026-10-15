modded class PlayerBase
{
	override void EEKilled( Object killer )
    {
		if (IAT_IsEventPlayer())
		{
			RuinEventPlayerItems();
		}
        super.EEKilled( killer );
	}

	void RuinEventPlayerItems()
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
        ItemBase item;
        GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
        for (int i = 0; i < itemsArray.Count(); i++)
        {
			if (Class.CastTo(item, itemsArray.Get(i)))
			{
				if (!item.IsInherited(SurvivorBase))
				{
					// 10% chance to let something pass
					if (Math.RandomFloat01() < 0.9)
					{
						item.AddHealth(-9999999);
					}
				}
			}
        }
	}

	bool IAT_IsEventPlayer()
	{
		IAT_DoubleArmband_ColorBase armband;
        if (Class.CastTo(armband, FindAttachmentBySlotName("Armband")))
        {
            if (armband.IAT_IsEventArmband())
			{
				return true;
			}
        }
		return false;
	}
};