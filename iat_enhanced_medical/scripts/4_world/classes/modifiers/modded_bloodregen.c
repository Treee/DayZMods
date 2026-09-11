modded class BloodRegenMdfr
{
	override bool ActivateCondition(PlayerBase player)
	{
		// vanilla takes precedent
		if (super.ActivateCondition(player))
		{
			return true;
		}
		float maxBloodInZone = 0;
		// Check each individual damage zone for completeness
		foreach (string zone : PlayerConstants.IAT_DAMAGE_ZONES)
		{
			maxBloodInZone = player.GetMaxHealth(zone, "Blood");
			if (player.GetHealth(zone, "Blood") <= maxBloodInZone)
			{
				// PrintFormat("Zone: %1 needs regen", zone);
				return true;
			}
		}
		// nothing needs regen
		return false;
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		// if global blood is still regenerating
		if (!super.DeactivateCondition(player))
		{
			return false; // do not deactivate
		}

		bool hasDamagedParts = false;
		float maxBloodInZone = 0;
		// Check each individual damage zone for completeness
		foreach (string zone : PlayerConstants.IAT_DAMAGE_ZONES)
		{
			maxBloodInZone = player.GetMaxHealth(zone, "Blood");
			// if any zone is not fully healed
			if (player.GetHealth(zone, "Blood") < maxBloodInZone)
			{
				// early return
				// PrintFormat("Zone: %1 does still needs regen, dont deactivate", zone);
				hasDamagedParts = true;
				break;
			}
		}
		// if the number of fully healed zones is not equal to all the damage zones
		if (hasDamagedParts)
		{
			return false; // do not deactivate regen
		}

		// nothing needs regen, deactivate
		return true;
	}

	// hard override on purpose
	// TODO check every so often with vanilla to make sure nothing is updated
	override void OnTick(PlayerBase player, float deltaT)
	{
		float regen_modifier_water = GetRegenModifierWater( player.GetStatWater().Get() );
		float regen_modifier_energy = GetRegenModifierEnergy( player.GetStatEnergy().Get() );
		float blood_regen_speed = PlayerConstants.BLOOD_REGEN_RATE_PER_SEC * regen_modifier_water * regen_modifier_energy;
		float playerBlood = player.GetHealth("GlobalHealth", "Blood");

		// Regen global player blood
		if ( player.IsUnconscious() && playerBlood <= PlayerConstants.SL_BLOOD_CRITICAL )
		{
			blood_regen_speed *= PlayerConstants.UNCONSCIOUS_BLOOD_REGEN_MLTP;
		}
		player.AddHealth("","Blood", blood_regen_speed * deltaT );

		// PrintFormat("OnTick Player Global Blood. WaterMDF: %1 EnergyMDF: %2 BloodRegenSpd: %3 PlayerBlood: %4", regen_modifier_water, regen_modifier_energy, blood_regen_speed, playerBlood);

		// Regen Each body part that is bandaged
		float zoneHP = 0;
		float maxZoneHP = 0;
		float hpLeft = 0;

		foreach (string zone : PlayerConstants.IAT_DAMAGE_ZONES)
		{
			maxZoneHP = player.GetMaxHealth(zone, "Blood");
			// if the dmg of this zone is less than max
			if (player.GetHealth(zone, "Blood") < maxZoneHP)
			{
				zoneHP = player.GetHealth(zone, "Blood");
				hpLeft = zoneHP / maxZoneHP;
				// If the hp of this zone is less than 50% of total hp
				if (hpLeft < 0.5)
				{
					// If the player is NOT wearing a bandage on the current body part
					if (player.IAT_IsWearingBandageOnBodyPart(zone))
					{
						player.AddHealth(zone, "Blood", blood_regen_speed * deltaT);
						// PrintFormat("Zone Healed: %1 ZoneHP: %2 MaxHp: %3 HpLeft: %4 Regen:%5", zone, zoneHP, maxZoneHP, hpLeft, blood_regen_speed);
					}
				}
				else
				{
					// the player has > 50% of hp and can regen normally without a bandage
					player.AddHealth(zone, "Blood", blood_regen_speed * deltaT);
					// PrintFormat("Zone Healed: %1 ZoneHP: %2 MaxHp: %3 HpLeft: %4 Regen:%5", zone, zoneHP, maxZoneHP, hpLeft, blood_regen_speed);
				}
			}
		}
	}
};