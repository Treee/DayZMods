modded class Land_FuelStation_Feed
{
	override bool HasFuelToGive()
	{
		#ifdef AdmiralsTerminalsMod
        if(GetGame().IsDedicatedServer())
        {
			// need full power for pumps to work
			if (GetWorldPower().GetGridPower01() >= 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		#endif
		return super.HasFuelToGive();
	}

	override void EEKilled(Object killer)
	{
		// if there is no fuel to give, there is no major explosion or other effects
		if (!HasFuelToGive())
		{
			return;
		}

		// do vanilla stuff
		super.EEKilled(killer);

		if (GetGame().IsDedicatedServer())
		{
			EntityAI entityResult;
			int iFlags = ECE_SETUP|ECE_PLACE_ON_SURFACE|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY;
			#ifdef IAT_Roll_Tables
			// get the loot table from the dayz game
			IAT_RollTableConfig rollConfig;
			if (Class.CastTo(rollConfig, GetDayZGame().GetIATRollTableConfig()))
			{
				string lootTable = "GasStationExplosion";
				// 3 - 12 results
				int numResults = Math.RandomIntInclusive(3, 12);

				string potentialItem = "";
				// loot table should roll until results are found
				TStringArray initialResults = rollConfig.GetResultsForItem(lootTable);
				TStringArray innerResults = {};
				for (int i = 0; i < numResults; i++)
				{
					// get some random result
					potentialItem = initialResults.GetRandomElement();
					// PrintFormat("===================================================Index: %1 Potential: %2", i, potentialItem);
					// recursively check for a loot table until we find a result that is just items
					while (rollConfig.RollTableExists(potentialItem))
					{
						// get the next level down results
						innerResults = rollConfig.GetResultsForItem(potentialItem);
						// get some random result
						potentialItem = innerResults.GetRandomElement();
						// PrintFormat("result was a roll table, new result is: %1", potentialItem);
					}

					bool isAi = GetGame().IsKindOf(potentialItem, "DZ_LightAI") || GetGame().IsKindOf(potentialItem, "SurvivorBase");
					if (isAi)
					{
						iFlags |= ECE_INITAI|ECE_CREATEPHYSICS;
					}
					// PrintFormat("===================attempt to create: %1", potentialItem);
					// at this point we know we have a result that is just an item or AI
					if (Class.CastTo(entityResult, GetGame().CreateObjectEx(potentialItem, GetPositionWithinArea(33), iFlags)))
					{
						// PrintFormat("================================================ CREATED: %1", potentialItem);
						Magazine ammo;
						ItemBase resultBase;
						// treat ammo special
						if (Class.CastTo(ammo, entityResult))
						{
							ammo.ServerSetAmmoCount(entityResult.GetQuantityMax());
						}
						// else normal quantity set
						else if (Class.CastTo(resultBase, entityResult))
						{
							resultBase.SetQuantity(entityResult.GetQuantityMax());
						}
					}
				}
			}
			#endif

			#ifdef IAT_Molotov_Grenades
			// create a molotov
			if (Class.CastTo(entityResult, GetGame().CreateObjectEx("IAT_Molotov_Grenade_Incendiary", GetPositionWithinArea(), iFlags)))
			{
				// PrintFormat("===========================================creating molotov!!");
				// destroy it
				entityResult.SetHealth(-1);

			}
			#endif
		}
	}

	vector GetPositionWithinArea(int offset = 1)
	{
		vector minMax[2];
        vector min, max;
        if (GetCollisionBox(minMax))
        {
            min = minMax[0];
            max = minMax[1];
        }
		// get the min vector
		float minX = Math.Min(min[0], max[0]);
		float minY = Math.Min(min[1], max[1]);
		float minZ = Math.Min(min[2], max[2]);
		// get the distances in each dimension that is within the boundaries
		float maxX = Math.AbsFloat(max[0] - min[0]) * offset;
		float maxY = Math.AbsFloat(max[1] - min[1]);
		float maxZ = Math.AbsFloat(max[2] - min[2]) * offset;
		// add some percentage distance to our minimums
		float newX = minX + (maxX * Math.RandomFloat01());
		float newY = minY + (maxY * Math.RandomFloat01());
		float newZ = minZ + (maxZ * Math.RandomFloat01());
		// construct the vector as a string
		string uniformRandomPosition = string.Format("%1 %2 %3", newX, newY, newZ);
		vector randomPosition = ModelToWorld(uniformRandomPosition.ToVector());
		return randomPosition;
	}
};
