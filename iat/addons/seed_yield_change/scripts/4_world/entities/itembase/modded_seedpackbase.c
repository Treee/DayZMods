modded class SeedPackBase
{
	override void EmptySeedPack( PlayerBase player )
	{
		string pack_type = GetType();
		string seeds_type = "";

		GetGame().ConfigGetText( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsType", seeds_type );

		int seeds_quantity_max = GetGame().ConfigGetInt( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsQuantity" );
		int seeds_quantity = seeds_quantity_max;

		// normalize quantity based on pack health
		seeds_quantity = Math.Round( seeds_quantity_max * GetHealth01("","") );

		// clamp quantity to 1
		if ( seeds_quantity < 1 )
		{
			seeds_quantity = 1;
		}

		if (player)
		{
			IAT_EmptySeedsPackLambda lambda = new IAT_EmptySeedsPackLambda(this, seeds_type, player, seeds_quantity);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
		{
			EntityAI seeds;
			vector pos = GetPosition();
			if (Class.CastTo(seeds, GetGame().CreateObjectEx(seeds_type, pos, ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY)))
			{
				int randomCount = Math.RandomIntInclusive(0, seeds_quantity_max);
				if (randomCount == 0)
				{
					seeds.AddHealth(-99999);
				}
			}

			GetGame().ObjectDelete( this );
		}
	}
};

class IAT_EmptySeedsPackLambda : ReplaceItemWithNewLambdaBase
{
	int m_ItemCount;

	void IAT_EmptySeedsPackLambda (EntityAI old_item, string new_item_type, PlayerBase player, int count)
	{
		m_ItemCount = count;
	}

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		int randomCount = Math.RandomIntInclusive(0, m_ItemCount);
		ItemBase unboxed;
		if (Class.CastTo(unboxed, new_item))
		{
			unboxed.SetQuantity(m_ItemCount);
			if (randomCount == 0)
			{
				unboxed.AddHealth(-99999);
			}
		}
	}

	override void OnSuccess(EntityAI new_item)
	{
		super.OnSuccess(new_item);

		//spawns wrapping Paper
		ItemBase paper = ItemBase.Cast( GetGame().CreateObjectEx("Paper", new_item.GetHierarchyRoot().GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY) );
	}
};