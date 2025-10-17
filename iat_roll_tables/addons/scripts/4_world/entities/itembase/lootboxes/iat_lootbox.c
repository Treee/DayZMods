class IAT_LootBox_ColorBase extends ItemBase
{
	// ================================== VANILLA EVENTS
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionOpenLootBox);
	}

	// ================================== CUSTOM CODE
	void OpenLootBox()
	{
		// get the loot table
		string lootTable = "";
		if (ConfigIsExisting("IAT_LootTable"))
            lootTable = ConfigGetString("IAT_LootTable");
		else
			return; // short circuit on no loot table found

		int numResults = 0;
		if (ConfigIsExisting("IAT_NumberOfResults"))
            numResults = ConfigGetInt("IAT_NumberOfResults");
		else
			return; // short circuit on no results found found

		// get the loot table from the dayz game
		IAT_RollTableConfig rollConfig;
		if (Class.CastTo(rollConfig, GetDayZGame().GetIATRollTableConfig()))
		{
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
				// at this point we know we have a result that is just an item
				EntityAI entityResult;
				if (Class.CastTo(entityResult, GetGame().CreateObjectEx(potentialItem, GetPosition(), ECE_SETUP|ECE_PLACE_ON_SURFACE|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY)))
				{
					Magazine ammo;
					ItemBase resultBase;
					// treat ammo special
					if (Class.CastTo(ammo, entityResult))
						ammo.ServerSetAmmoCount(entityResult.GetQuantityMax());
					// else normal quantity set
					else if (Class.CastTo(resultBase, entityResult))
						resultBase.SetQuantity(entityResult.GetQuantityMax());
				}
			}
		}
	}
};

class IAT_LootBox_Small_ColorBase extends IAT_LootBox_ColorBase{};
class IAT_LootBox_Medium_ColorBase extends IAT_LootBox_ColorBase{};
class IAT_LootBox_Large_ColorBase extends IAT_LootBox_ColorBase{};

class IAT_LootBox_Small_1 extends IAT_LootBox_Small_ColorBase{};
class IAT_LootBox_Small_2 extends IAT_LootBox_Small_ColorBase{};
class IAT_LootBox_Small_3 extends IAT_LootBox_Small_ColorBase{};
class IAT_LootBox_Small_4 extends IAT_LootBox_Small_ColorBase{};
class IAT_LootBox_Medium_1 extends IAT_LootBox_Medium_ColorBase{};
class IAT_LootBox_Medium_2 extends IAT_LootBox_Medium_ColorBase{};
class IAT_LootBox_Medium_3 extends IAT_LootBox_Medium_ColorBase{};
class IAT_LootBox_Medium_4 extends IAT_LootBox_Medium_ColorBase{};
class IAT_LootBox_Large_1 extends IAT_LootBox_Large_ColorBase{};
class IAT_LootBox_Large_2 extends IAT_LootBox_Large_ColorBase{};
class IAT_LootBox_Large_3 extends IAT_LootBox_Large_ColorBase{};
class IAT_LootBox_Large_4 extends IAT_LootBox_Large_ColorBase{};