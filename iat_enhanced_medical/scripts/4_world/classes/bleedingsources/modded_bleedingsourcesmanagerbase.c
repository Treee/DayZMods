modded class BleedingSource
{
	override void OnUpdateServer(float deltatime, float blood_scale, bool no_blood_loss)
	{
		string damageZoneName = MiscGameplayFunctions.IAT_MapBoneNameToDamageZone(m_Bone);
		float zoneHP = m_Player.GetHealth(damageZoneName, "Blood");
		float maxZoneHP = m_Player.GetMaxHealth(damageZoneName, "Blood");
		float hpLeft = zoneHP / maxZoneHP;
		float constantBloodDmg = (PlayerConstants.BLEEDING_SOURCE_BLOODLOSS_PER_SEC * blood_scale * deltatime * m_FlowModifier) * 0.057;
		// constantBloodDmg = Math.Min(constantBloodDmg, 2);

		// PrintFormat("Zone Damaged: %1 ZoneHP: %2 MaxHp: %3 HpLeft: %4 DmgToApplyToZone:%5", damageZoneName, zoneHP, maxZoneHP, hpLeft, constantBloodDmg);
		// If the hp of this zone is less than 50% of total hp
		if (hpLeft < 0.5)
		{
			// If the player is NOT wearing a bandage on the current body part
			if (!m_Player.IAT_IsWearingBandageOnBodyPart(damageZoneName))
			{
				// pause the timer so the bleed is not removed (needs bandage)
				m_ActiveTime -= deltatime;
			}
		}
		// Let vanilla blood loss continue
		super.OnUpdateServer(deltatime, blood_scale, no_blood_loss);
		if (!no_blood_loss)
		{
			m_Player.AddHealth(damageZoneName, "Blood", constantBloodDmg);
		}
	}
};