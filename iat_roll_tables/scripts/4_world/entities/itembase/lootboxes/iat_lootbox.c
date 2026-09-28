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

		string potentialItem = "";
		float randomQuantity = 0.0;
		// get the loot table from the dayz game
		IAT_RollTableConfig rollConfig;
		if (Class.CastTo(rollConfig, GetDayZGame().GetIATRollTableConfig()))
		{
			for (int i = 0; i < numResults; i++)
			{
				potentialItem = rollConfig.GetRollTableResult(lootTable);
				randomQuantity = Math.RandomFloatInclusive(0.3, 0.7);
				rollConfig.SpawnRollTableResult(potentialItem, GetPosition(), randomQuantity);
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