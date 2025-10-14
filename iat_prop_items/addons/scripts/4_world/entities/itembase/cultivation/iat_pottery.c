class IAT_Pot_ColorBase extends ItemBase
{
	override bool IsDeployable()
	{
		return true;
	}
	override bool CanAssignAttachmentsToQuickbar()
	{
		return false;
	}
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	override float GetDeployTime()
	{
		return 0;
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		SeedBase seed;
		// seed items need to be converted
		if (Class.CastTo(seed, item))
		{
			// plant slot; ignore
			if (slot_name == "IAT_PottedPlant")
			{
				return;
			}
			else // other slots are growth seeds
			{
				// construct the new item name for the replacement
				string newItemName = seed.IAT_GetSeedToChangeInto();
				if (seed.ConfigIsExisting("IAT_SeedToReplace"))
				{
					newItemName = seed.ConfigGetString("IAT_SeedToReplace");
				}
				CreatePottedPlant(newItemName, slot_name);
				ToggleLockPlantSlots(true);
			}
		}
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		// ignore removing the potted plant
		if (slot_name == "IAT_PottedPlant")
		{
			return;
		}
		// any slot past here is a seed growth slot.
		else
		{
			// remove the potted plant because we removed the seeds
			RemovePottedPlant();
			ToggleLockPlantSlots(false);
		}
	}
	TStringArray GetGrowthStageSlots()
	{
		return {
			"IAT_PottedSeed1",
			"IAT_PottedSeed2",
			"IAT_PottedSeed3",
			"IAT_PottedSeed4",
			"IAT_PottedSeed5",
			"IAT_PottedSeed6",
			"IAT_PottedSeed7",
			"IAT_PottedSeed8"
		};
	}
	void ToggleLockPlantSlots(bool isLocked)
	{
		int plantSlot = InventorySlots.GetSlotIdFromString("IAT_PottedPlant");
		GetInventory().SetSlotLock(plantSlot, isLocked);
	}
	void CreatePottedPlant(string className, string slotName)
	{
		// intercept the initial slot and turn it into an actual plant
		if (GetGame().IsDedicatedServer())
		{
			slotName.Replace("IAT_PottedSeed", "");
			int slotIndex = slotName.ToInt();
			className = string.Format("%1%2", className, slotIndex);
			IAT_SeedPlant_ColorBase seedPlant;
			// if we successfully created a visual plant
			if (Class.CastTo(seedPlant, GetInventory().CreateAttachment(className)))
			{
				// created successfully
			}
		}
	}
	void RemovePottedPlant()
	{
		// intercept removing a growth stage seed
		if (GetGame().IsDedicatedServer())
		{
			// remove IAT_PottedPlant
			EntityAI attachedPlant;
			if (Class.CastTo(attachedPlant, GetInventory().FindAttachmentByName("IAT_PottedPlant")))
			{
				attachedPlant.DeleteSafe();
			}
		}
	}
};

// Base Pots
class IAT_Pot1_ColorBase extends IAT_Pot_ColorBase{};
class IAT_Pot2_ColorBase extends IAT_Pot_ColorBase{};

// Retextures
class IAT_Pot1_Default extends IAT_Pot1_ColorBase{};
class IAT_Pot2_Default extends IAT_Pot2_ColorBase{};
