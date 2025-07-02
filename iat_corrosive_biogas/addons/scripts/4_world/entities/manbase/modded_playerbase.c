modded class PlayerBase
{
	private bool m_IsAffectedByAreaExposure = false;

	override protected void OnContaminatedAreaEnterServer()
	{
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



	TStringArray GetProtectiveClothingSlotList()
	{
		return {"Headgear", "Body", "Gloves", "Legs", "Feet", "Back"};
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

					float damageToDealPerInterval = clothingPiece.GetMaxHealth() * 0.25;
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
};