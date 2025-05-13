modded class PlayerBase
{
	private bool m_IsAffectedByAreaExposure = false;

	override protected void OnContaminatedAreaEnterServer()
	{
		// try to add corrosion to all slots, needs to happen before a fully protected player is short circuited
		// because they could have an exposed backpack or belt.
		TryAddCorrosiveAgentsToWornSlots();

		TryAddCorrosiveAgentsToInHandsItem(GetItemInHands());

		// check if the player is affected by area exposure
		if (!m_IsAffectedByAreaExposure)
			return;

		// call existing behavior (will ignore players with full protection)
		super.OnContaminatedAreaEnterServer();
	}

	override protected void OnUpdateEffectAreaServer(float timeSlice)
	{
		super.OnUpdateEffectAreaServer(timeSlice);

		float timeSpent;

		if (IsInEffectArea(IAT_EffectAreaType.CORROSIVE_BIOGAS))
		{
			// if we dont have enough bioprotection
			if (!HasEnoughChemicalProtection())
			{
				// start timing how long weve been here
				timeSpent = m_EffectAreaTimeToTick.Get(IAT_EffectAreaType.CORROSIVE_BIOGAS);
				timeSpent += timeSlice;
				// if we exceed the timer threshhold
				if (timeSpent > ContaminatedTrigger.EXPOSURE_DAMAGE_TICK_TIME)
				{
					// reset the timer
					m_EffectAreaTimeToTick.Set(IAT_EffectAreaType.CORROSIVE_BIOGAS, 0);
					// do the thing
					DamageWornClothing();
				}
				else
				{
					// keep counting cowboy
					m_EffectAreaTimeToTick.Set(IAT_EffectAreaType.CORROSIVE_BIOGAS, timeSpent);
				}
			}
		}
		else
		{
			m_IsAffectedByAreaExposure = false;
		}
	}

	override protected void OnContaminatedAreaExitServer()
	{
		super.OnContaminatedAreaExitServer();

		// try to add corrosion to all slots
		TryAddCorrosiveAgentsToWornSlots();
	}

	override void EEItemIntoHands(EntityAI item)
	{
		super.EEItemIntoHands(item);
		if (IsInEffectArea(IAT_EffectAreaType.CORROSIVE_BIOGAS))
			TryAddCorrosiveAgentsToInHandsItem(item);
	}

	override void EEItemOutOfHands(EntityAI item)
	{
		super.EEItemOutOfHands(item);
		if (IsInEffectArea(IAT_EffectAreaType.CORROSIVE_BIOGAS))
			TryAddCorrosiveAgentsToInHandsItem(item);
	}

	TStringArray GetProtectiveClothingSlotList()
	{
		return {"Headgear", "Body", "Gloves", "Legs", "Feet", "Back"};
	}

	TStringArray GetCorrisionApplicableSlotsList()
	{
		return {"Headgear", "Mask", "Eyewear", "Shoulder", "Melee", "Vest", "Body", "Hips", "Legs", "Back", "Gloves", "Hands", "Armband", "Feet", "Coat", "Scarf"};
	}
	override void InsertAgent(int agent, float count = 1)
	{
		// keep corrosion from being given to the player
		if (agent == IAT_CB_Agents.CORROSION)
			return;

		#ifdef AdmiralsMutantMod
		if (agent == ADM_MutantAgent.MUTANT_AGENT)
			return;
		#endif

		super.InsertAgent(agent, count);
	}

	void DamageWornClothing()
	{
		// if the player inventory exists
		if (GetInventory())
		{
			TStringArray protectiveClothingList = GetProtectiveClothingSlotList();
			ItemBase clothingPiece;
			// foreach normal bioprotection slot
			foreach(string slot_name: protectiveClothingList)
			{
				// if there is something on the player in this slot
				if (Class.CastTo(clothingPiece, GetItemOnSlot(slot_name)))
				{
					// get any protection on the item
					float protectiveArmor = clothingPiece.GetProtectionLevel(DEF_CHEMICAL);

					float damageToDealPerInterval = clothingPiece.GetMaxHealth() / 6;
					// get the percent value of protection armor
					float mitigatedDamageFromProtection = protectiveArmor * damageToDealPerInterval;

					// subtract damage to deal minus protection (we can have the case of protection be 1x or more)
					float expectedDamage = damageToDealPerInterval - mitigatedDamageFromProtection;

					// make sure we never go below 0 in damage (this is because a negative amount would heal the item)
					float actualDamage = Math.Min(expectedDamage, clothingPiece.GetMaxHealth());
					actualDamage = Math.Max(actualDamage, 0);
					// damage that clothing
					// PrintFormat("Protection: %1 IntervalDmg: %2 ExpectedDmg: %3 ActualDmg: %4", protectiveArmor, damageToDealPerInterval, expectedDamage, actualDamage);
					clothingPiece.AddHealth(-actualDamage);

					if (clothingPiece.IsDamageDestroyed())
					{
						// PrintFormat("%1 is destroyed", clothingPiece.GetType());
						ServerDropEntity(clothingPiece);
					}
				}
				else // this specific slot has nothing attached
				{
					// start activating the exposure modifier on the player
					m_IsAffectedByAreaExposure = true;
					StartAreaExposureEffects();
				}
			}
		}
	}

	void StartAreaExposureEffects()
	{
		if (m_IsAffectedByAreaExposure && !HasEnoughChemicalProtection())
			GetModifiersManager().ActivateModifier( eModifiers.MDF_AREAEXPOSURE );
	}

	void TryAddCorrosiveAgentsToWornSlots()
	{
		// if the player inventory exists
		if (GetInventory())
		{
			array<EntityAI> itemsArray = new array<EntityAI>;
			TStringArray attachedClothing = GetCorrisionApplicableSlotsList();
			ItemBase clothingPiece;
			ItemBase clothingItem;
			float agentsToAdd = 1;
			// foreach normal bioprotection slot
			foreach(string slot_name: attachedClothing)
			{
				if (Class.CastTo(clothingPiece, GetItemOnSlot(slot_name)))
				{
					itemsArray.Clear();
					clothingPiece.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
					// get any protection on the item
					float protectiveArmor = clothingPiece.GetProtectionLevel(DEF_CHEMICAL);
					// short circuit protected clothing
					if (protectiveArmor >= 1)
						continue;

					foreach (EntityAI cargoItem : itemsArray)
					{
						agentsToAdd = 1;
						if (Class.CastTo(clothingItem, cargoItem))
						{
							clothingItem.InsertAgent(IAT_CB_Agents.CORROSION, agentsToAdd);
							clothingItem.SetCorrosiveAgents(true);
							clothingItem.SetSynchDirty();
						}
						// if (protectiveArmor > 0)
						// {
						// 	agentsToAdd = Math.Max(0, (agentsToAdd - protectiveArmor));
						// 	cargoItem.InsertAgent(IAT_CB_Agents.CORROSION, agentsToAdd);
						// 	// add agents relative to the protection
						// 	// technically vanilal doesnt have a concept of an agent pool for items so this is useless for now
						// }
						// else
						// {
						// }
					}
				}
			}
		}
	}
	void TryAddCorrosiveAgentsToInHandsItem(EntityAI inHandsEntity)
	{
		int agentsToAdd = 1;
		ItemBase inHandsItem;
		if (Class.CastTo(inHandsItem, inHandsEntity))
		{
			array<EntityAI> itemsArray = new array<EntityAI>;
			inHandsItem.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);

			// get any protection on the item
			float protectiveArmor = inHandsItem.GetProtectionLevel(DEF_CHEMICAL);
			// short circuit protected items
			if (protectiveArmor >= 1)
				return;

			ItemBase attachedItem;
			foreach (EntityAI cargoItem : itemsArray)
			{
				if (Class.CastTo(attachedItem, cargoItem))
				{
					attachedItem.InsertAgent(IAT_CB_Agents.CORROSION, agentsToAdd);
					attachedItem.SetCorrosiveAgents(true);
					attachedItem.SetSynchDirty();
				}
			}
		}
	}
};