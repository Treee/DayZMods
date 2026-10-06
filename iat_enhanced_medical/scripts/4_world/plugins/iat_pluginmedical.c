// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Server-side dressing, bleeding, extraction, and healing rules.
// Integration: server medical state and wound lifecycle.
// Documentation: iat_enhanced_medical/README.md

class IAT_PluginMedical : PluginBase
{
	static const float IAT_SEVERE_WOUND_THRESHOLD = 0.5;
	static const float IAT_ZONE_BLOOD_FLOOR_OFFSET = 500;
	static const float IAT_ZONE_BLOODLOSS_MULTIPLIER = 1.0;
	static const float IAT_BULLET_EXTRACTION_SECONDS = 10;
	static const float IAT_BANDAGE_REMOVAL_SECONDS = 5;

	// Keys are vanilla bleeding selection names, not particle attachment bones.
	// Keep registration order for extraction; IDs are vanilla bleeding bits.
	protected ref TStringArray m_Bones;
	protected int m_RegisteredBoneMask;
	protected ref map<string, ref IAT_MedicalBoneDefinition> m_BoneDefinitions;
	protected ref map<string, ref IAT_MedicalZoneDefinition> m_ZoneDefinitions;
	protected ref map<string, ref IAT_MedicalBandageDefinition> m_BandageDefinitions;

	bool m_LoggingEnabled = true;

	void IAT_PluginMedical()
	{
		IAT_InitBandageCoverageWZ();
	}

	// Functional

	//! Apply regional recovery using the modifier's pre-vanilla global rate.
	void IAT_RegenerateZones(PlayerBase player, float deltaT, float globalRate)
	{
		map<string, ref IAT_MedicalZoneDefinition> zoneDefinitions = IAT_GetDamageZones();
		foreach (string zone, IAT_MedicalZoneDefinition zoneDefinition : zoneDefinitions)
		{
			if (!CanRegenerateZone(player, zone))
				continue;
			float before = player.GetHealth(zone, "Blood");
			float maximum = player.GetMaxHealth(zone, "Blood");
			float zoneRate = globalRate * IAT_GetZoneBloodScale(player, maximum);

			if (before < maximum)
				player.AddHealth(zone, "Blood", Math.Min(zoneRate * deltaT, maximum - before));
		}
	}

	//! Retain modifier ticks for regional recovery or healed-dressing cleanup.
	bool IAT_NeedsMedicalTick(PlayerBase player)
	{
		return NeedsZoneRegen(player) || HasHealedBandage(player);
	}


	void OnBleedingSourceAdded(PlayerBase player, string bone)
	{
		IAT_MedicalState state = player.IAT_GetMedicalState();
		int bit = IAT_GetBulletBoneBit(bone);
		// Clear only this bone's dressed bit; preserve other treated bones.
		state.m_DressedWounds &= ~bit;
		LogEvent(player, "BLEEDING_SOURCE_ADDED", "bone=" + bone);
	}

	void OnBleedingSourceClosed(PlayerBase player, string bone, ItemBase material)
	{
		// Natural expiry has no treatment item and must not create dressed history.
		if (!material)
			return;
		string zone = IAT_MapBoneNameToDamageZone(bone);
		if (!IsWearingBandage(player, zone))
			return;
		IAT_MedicalState state = player.IAT_GetMedicalState();
		// Set this bone's dressed bit while preserving earlier treatments.
		state.m_DressedWounds |= IAT_GetBulletBoneBit(bone);
		LogEvent(player, "WOUND_DRESSED", "bone=" + bone + " slot=" + IAT_GetBandageSlot(zone) + " material=" + material.GetType());
	}

	void RecordBullet(PlayerBase player, string bone)
	{
		IAT_MedicalState state = player.IAT_GetMedicalState();
		// Mark a retained bullet at this bone; repeated hits share the same bit.
		state.m_Bullets |= IAT_GetBulletBoneBit(bone);
		LogEvent(player, "BULLET_RECORDED", "bone=" + bone + " zone=" + IAT_MapBoneNameToDamageZone(bone));
	}

	bool PrepareDressing(PlayerBase player, ItemBase material)
	{
		BleedingSourcesManagerServer manager = player.GetBleedingManagerServer();
		if (!manager || !material || material.IsRuined())
			return false;
		string zone = manager.IAT_GetDamageZoneFromMostSignificantSource();
		string slot = IAT_GetBandageSlot(zone);
		string itemType = IAT_GetBandageClass(zone);
		if (slot == "" || itemType == "")
			return false;

		EntityAI attached = player.FindAttachmentBySlotName(slot);
		WZ_Bandage_Base existingBandage;
		if (attached)
		{
			if (!Class.CastTo(existingBandage, attached) || existingBandage.IsRuined())
			{
				LogEvent(player, "BANDAGE_FAILED", "occupied_or_ruined slot=" + slot);
				player.MessageStatus("#IAT_EM_REMOVE_INCOMPATIBLE_DRESSING");
				return false;
			}
		}
		else
		{
			// Prepare the attachment before vanilla closes the selected bleed.
			EntityAI created = player.GetInventory().CreateAttachmentEx(itemType, InventorySlots.GetSlotIdFromString(slot));
			if (!Class.CastTo(existingBandage, created))
			{
				if (created)
					created.DeleteSafe();
				LogEvent(player, "BANDAGE_FAILED", "creation_failed slot=" + slot + " class=" + itemType);
				player.MessageStatus("#IAT_EM_DRESSING_ATTACHMENT_FAILED");
				return false;
			}
		}
		MiscGameplayFunctions.TransferItemProperties(material, existingBandage, true, false, true);
		existingBandage.SetCleanness(material.GetCleanness());
		LogEvent(player, "BANDAGE_PREPARED", "slot=" + slot + " class=" + itemType + " material=" + material.GetType());
		return true;
	}

	bool ExtractBullet(PlayerBase patient, out string zone)
	{
		zone = "";
		if (!g_Game.IsServer() || !patient || !patient.IsAlive())
			return false;
		IAT_MedicalState state = patient.IAT_GetMedicalState();
		TStringArray bones = IAT_GetBones();
		foreach (string bone : bones)
		{
			int bit = IAT_GetBulletBoneBit(bone);
			// Skip bones whose retained-bullet bit is not set.
			if ((state.m_Bullets & bit) == 0)
				continue;
			// Clear only the extracted bone's bullet bit.
			state.m_Bullets &= ~bit;
			zone = IAT_MapBoneNameToDamageZone(bone);
			LogEvent(patient, "BULLET_EXTRACTED", "bone=" + bone + " zone=" + zone);
			return true;
		}
		LogEvent(patient, "EXTRACTION_EMPTY");
		return false;
	}

	void OnBandageAttached(PlayerBase player, EntityAI item, string slotName)
	{
		if (item && item.IsInherited(WZ_Bandage_Base) && !item.IsRuined())
		{
			LogEvent(player, "BANDAGE_ATTACHED", "slot=" + slotName + " item=" + item.GetType());
		}
	}

	void OnBandageDetached(PlayerBase player, EntityAI item, string slotName)
	{
		if (item && item.IsInherited(WZ_Bandage_Base))
		{
			LogEvent(player, "BANDAGE_DETACHED", "slot=" + slotName + " item=" + item.GetType());
			ReopenDressedWounds(player, slotName);
		}
	}

	void UpdateHealing(PlayerBase player)
	{
		if (!player.IsAlive())
			return;
		IAT_MedicalState state = player.IAT_GetMedicalState();
		TStringArray bones = IAT_GetBones();
		foreach (string bone : bones)
		{
			int bit = IAT_GetBulletBoneBit(bone);
			// Skip bones with no recorded dressed wound.
			if ((state.m_DressedWounds & bit) == 0)
				continue;
			string zone = IAT_MapBoneNameToDamageZone(bone);
			if (IsZoneHealed(player, zone) && !player.GetBleedingManagerServer().IsBleedingSourceActive(bone))
			{
				// Clear only this bone's dressed bit; preserve other treated bones.
				state.m_DressedWounds &= ~bit;
				LogEvent(player, "WOUND_HEALED", "bone=" + bone + " zone=" + zone);
			}
		}
		// Also catches ruined/deleted dressings and missing attachments on load.
		map<string, ref IAT_MedicalBandageDefinition> bandageDefinitions = IAT_GetBandageSlots();
		foreach (string slot, IAT_MedicalBandageDefinition bandageDefinition : bandageDefinitions)
			ReopenDressedWounds(player, slot);
	}

	void RemoveHealedBandages(PlayerBase player)
	{
		map<string, ref IAT_MedicalBandageDefinition> bandageDefinitions = IAT_GetBandageSlots();
		foreach (string slot, IAT_MedicalBandageDefinition bandageDefinition : bandageDefinitions)
		{
			if (!CanRemoveBandage(player, slot))
				continue;
			EntityAI bandage = player.FindAttachmentBySlotName(slot);
			LogEvent(player, "BANDAGE_HEALED_REMOVAL", "slot=" + slot + " item=" + bandage.GetType());
			// Like an applied splint, the finished dressing is deleted, not dropped.
			bandage.DeleteSafe();
		}
	}

	void LogEvent(PlayerBase player, string eventName, string detail = "")
	{
		if (!m_LoggingEnabled || !g_Game || !g_Game.IsServer() || !player)
			return;
		int a, b, c, d;
		player.GetPersistentID(a, b, c, d);
		PrintFormat("[IAT MEDICAL] event=%1 pid=%2:%3:%4:%5 entity=%6 %7", eventName, a, b, c, d, player, detail);
	}

	void LogSnapshot(PlayerBase player, string eventName)
	{
		if (!m_LoggingEnabled || !g_Game || !g_Game.IsServer() || !player)
			return;
		IAT_MedicalState state = player.IAT_GetMedicalState();
		LogEvent(player, eventName, string.Format("version=%1 bullets=%2 dressed=%3 activeBleeds=%4", IAT_MedicalState.STORAGE_VERSION, state.m_Bullets, state.m_DressedWounds, player.GetBleedingBits()));
		LogEvent(player, "BONES", "bullets=" + LogBones(state.m_Bullets) + " dressed=" + LogBones(state.m_DressedWounds));
		string attachments;
		map<string, ref IAT_MedicalBandageDefinition> bandageDefinitions = IAT_GetBandageSlots();
		foreach (string slot, IAT_MedicalBandageDefinition bandageDefinition : bandageDefinitions)
		{
			EntityAI item = player.FindAttachmentBySlotName(slot);
			if (item)
				attachments += string.Format(" %1=%2(ruined=%3)", slot, item.GetType(), item.IsRuined());
			else
				attachments += " " + slot + "=empty";
		}
		LogEvent(player, "ATTACHMENTS", attachments);
		string pools;
		map<string, ref IAT_MedicalZoneDefinition> zoneDefinitions = IAT_GetDamageZones();
		foreach (string zone, IAT_MedicalZoneDefinition zoneDefinition : zoneDefinitions)
			pools += string.Format(" %1=%2/%3", zone, player.GetHealth(zone, "Blood"), player.GetMaxHealth(zone, "Blood"));
		LogEvent(player, "BLOOD_POOLS", pools);
	}

	// Helpers

	protected string LogBones(int mask)
	{
		string result;
		TStringArray bones = IAT_GetBones();
		foreach (string bone : bones)
		{
			// Include only bones whose bits are present in the supplied mask.
			if ((mask & IAT_GetBulletBoneBit(bone)) == 0)
				continue;
			if (result != "")
				result += ",";
			result += bone;
		}
		return "[" + result + "]";
	}

	void ReopenDressedWounds(PlayerBase player, string slot)
	{
		if (!player.IsAlive() || !player.GetBleedingManagerServer())
			return;
		TStringArray coveredBones = IAT_GetBandageBones(slot);
		if (!coveredBones)
			return;
		IAT_MedicalState state = player.IAT_GetMedicalState();
		foreach (string bone : coveredBones)
		{
			int bit = IAT_GetBulletBoneBit(bone);
			// Skip bones with no recorded dressed wound.
			if ((state.m_DressedWounds & bit) == 0)
				continue;
			string zone = IAT_MapBoneNameToDamageZone(bone);
			if (IsWearingBandage(player, zone))
				continue;
			if (IsZoneHealed(player, zone))
			{
				// Clear only this bone's dressed bit; preserve other treated bones.
				state.m_DressedWounds &= ~bit;
				LogEvent(player, "WOUND_HEALED", "bone=" + bone + " zone=" + zone);
			}
			else
			{
				// OnBleedingSourceAdded clears m_DressedWounds only when creation succeeds.
				if (player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(bone))
					LogEvent(player, "WOUND_REOPENED", "bone=" + bone + " slot=" + slot + " reason=missing_or_ruined_dressing");
			}
		}
	}

	protected bool CanRemoveBandage(PlayerBase player, string slot)
	{
		if (!g_Game.IsServer() || !player.IsAlive())
			return false;
		EntityAI bandage = player.FindAttachmentBySlotName(slot);
		if (!bandage || !bandage.IsInherited(WZ_Bandage_Base))
			return false;
		TStringArray coveredZones = IAT_GetBandageZones(slot);
		if (!coveredZones || coveredZones.Count() == 0)
			return false;
		foreach (string zone : coveredZones)
		{
			if (!IsZoneHealed(player, zone))
				return false;
		}
		// A fresh bleed can exist before its first zone-damage tick.
		BleedingSourcesManagerServer manager = player.GetBleedingManagerServer();
		if (!manager)
			return false;
		TStringArray coveredBones = IAT_GetBandageBones(slot);
		foreach (string bone : coveredBones)
		{
			if (manager.IsBleedingSourceActive(bone))
				return false;
		}
		return true;
	}

	bool IsBulletAmmo(string ammo)
	{
		if (ammo == "" || (!g_Game.IsKindOf(ammo, "Bullet_Base") && !g_Game.IsKindOf(ammo, "Shotgun_Base")))
			return false;
		// Exclude these projectile families, including their derived ammo classes.
		if (g_Game.IsKindOf(ammo, "Bolt_Base") || g_Game.IsKindOf(ammo, "Bullet_Flare") || g_Game.IsKindOf(ammo, "Bullet_40mm_Base") || g_Game.IsKindOf(ammo, "Bullet_12GaugeRubberSlug") || g_Game.IsKindOf(ammo, "Bullet_12GaugeBeanbag"))
			return false;
		return true;
	}

	protected void IAT_InitBandageCoverageWZ()
	{
		if (m_BoneDefinitions)
			return;
		m_Bones = new TStringArray;
		m_BoneDefinitions = new map<string, ref IAT_MedicalBoneDefinition>;
		m_ZoneDefinitions = new map<string, ref IAT_MedicalZoneDefinition>;
		m_BandageDefinitions = new map<string, ref IAT_MedicalBandageDefinition>;

		IAT_RegisterBandage("WZBandageHead", "WZ_Bandage_Head");
		IAT_RegisterBandage("WZBandageChest", "WZ_Bandage_Chest");
		IAT_RegisterBandage("WZBandageLArm", "WZ_Bandage_LArm");
		IAT_RegisterBandage("WZBandageRArm", "WZ_Bandage_RArm");
		IAT_RegisterBandage("WZBandageLLeg", "WZ_Bandage_LLeg");
		IAT_RegisterBandage("WZBandageRLeg", "WZ_Bandage_RLeg");

		IAT_RegisterZone("Head", 0, "WZBandageHead");
		IAT_RegisterZone("Torso", 1, "WZBandageChest");
		IAT_RegisterZone("LeftArm", 2, "WZBandageLArm");
		IAT_RegisterZone("RightArm", 3, "WZBandageRArm");
		IAT_RegisterZone("RightHand", 4, "WZBandageRArm");
		IAT_RegisterZone("LeftHand", 5, "WZBandageLArm");
		IAT_RegisterZone("LeftLeg", 6, "WZBandageLLeg");
		IAT_RegisterZone("RightLeg", 7, "WZBandageRLeg");
		IAT_RegisterZone("LeftFoot", 8, "WZBandageLLeg");
		IAT_RegisterZone("RightFoot", 9, "WZBandageRLeg");

		// Bleeding selections are supplied by vanilla RegisterBleedingZoneEx.
	}

	protected void IAT_RegisterBandage(string slot, string itemType)
	{
		IAT_MedicalBandageDefinition definition = new IAT_MedicalBandageDefinition(itemType);
		m_BandageDefinitions.Insert(slot, definition);
	}

	protected void IAT_RegisterZone(string zone, int bitIndex, string slot)
	{
		// Shift a single set bit into this zone's assigned position.
		IAT_MedicalZoneDefinition definition = new IAT_MedicalZoneDefinition(1 << bitIndex, slot);
		m_ZoneDefinitions.Insert(zone, definition);
		m_BandageDefinitions.Get(slot).AddZone(zone);
	}

	// Bleeding registrations name skeleton selections, which need not appear in
	// DamageZones.componentNames. Resolve anatomy once at registration; runtime
	// lookups still use the definition map. Registration supplies the list and IDs.
	protected string IAT_ResolveBleedingSelectionZone(PlayerBase player, string selection)
	{
		selection.ToLower();
		switch (selection)
		{
			case "head":
			case "brain":
				return "Head";
			case "neck":
			case "pelvis":
			case "spine":
			case "spine1":
			case "spine2":
			case "spine3":
				return "Torso";
			case "leftshoulder":
			case "leftarm":
			case "leftarmroll":
			case "leftforearm":
				return "LeftArm";
			case "rightshoulder":
			case "rightarm":
			case "rightarmroll":
			case "rightforearm":
				return "RightArm";
			case "leftforearmroll":
				return "LeftHand";
			case "rightforearmroll":
				return "RightHand";
			case "leftleg":
			case "leftlegroll":
			case "leftupleg":
			case "leftuplegroll":
				return "LeftLeg";
			case "rightleg":
			case "rightlegroll":
			case "rightupleg":
			case "rightuplegroll":
				return "RightLeg";
			case "leftfoot":
			case "lefttoebase":
				return "LeftFoot";
			case "rightfoot":
			case "righttoebase":
				return "RightFoot";
		}
		// A modded bleeding selection may also be a configured damage component.
		string zone;
		if (DamageSystem.GetDamageZoneFromComponentName(player, selection, zone))
			return zone;
		return "";
	}

	void IAT_RegisterBleedingSelection(PlayerBase player, string selection, int bit)
	{
		selection.ToLower();
		IAT_MedicalBoneDefinition existing = m_BoneDefinitions.Get(selection);
		if (existing)
		{
			// Every player registers the same vanilla sources; never append duplicates.
			if (existing.GetBit() != bit)
				Error("[IAT MEDICAL] Conflicting bleeding bit for " + selection);
			return;
		}
		string zone = IAT_ResolveBleedingSelectionZone(player, selection);
		if (zone == "")
		{
			Error("[IAT MEDICAL] No damage zone for bleeding selection " + selection);
			return;
		}
		IAT_MedicalZoneDefinition zoneDefinition = m_ZoneDefinitions.Get(zone);
		if (!zoneDefinition)
		{
			// New body zones still need an explicit WesternZ bandage coverage choice.
			Error("[IAT MEDICAL] No bandage coverage for damage zone " + zone);
			return;
		}
		// A nonzero intersection means this bit is already registered.
		if ((m_RegisteredBoneMask & bit) != 0)
		{
			Error("[IAT MEDICAL] Bleeding bit already assigned: " + selection);
			return;
		}
		IAT_MedicalBoneDefinition definition = new IAT_MedicalBoneDefinition(bit, zone);
		m_Bones.Insert(selection);
		m_BoneDefinitions.Insert(selection, definition);
		// Add this selection to the mask of all supported bleeding bits.
		m_RegisteredBoneMask |= bit;
		zoneDefinition.AddBone(selection, bit);
		m_BandageDefinitions.Get(zoneDefinition.GetSlot()).AddBone(selection);
	}

	// Getters

	float IAT_GetZoneBloodScale(PlayerBase player, float zoneMaximum)
	{
		// Use a recovery floor above the fatal threshold; never change vanilla death rules.
		float recoveryFloor = PlayerConstants.BLOOD_THRESHOLD_FATAL + IAT_ZONE_BLOOD_FLOOR_OFFSET;
		float recoveryRange = player.GetMaxHealth("", "Blood") - recoveryFloor;
		if (recoveryRange <= 0 || zoneMaximum <= 0)
			return 0;
		// Defaults: 100 / (5000 - (2500 + 500)) = 0.05 for both loss and recovery.
		return zoneMaximum / recoveryRange;
	}

	bool IsWearingBandage(PlayerBase player, string zone)
	{
		string slot = IAT_GetBandageSlot(zone);
		if (slot == "")
			return false;
		EntityAI dressing = player.FindAttachmentBySlotName(slot);
		return dressing && dressing.IsInherited(WZ_Bandage_Base) && !dressing.IsRuined();
	}

	bool CanRegenerateZone(PlayerBase player, string zone)
	{
		return !HasBulletInZone(player, zone) && (!IsSevere(player, zone) || IsWearingBandage(player, zone));
	}

	bool NeedsZoneRegen(PlayerBase player)
	{
		map<string, ref IAT_MedicalZoneDefinition> zoneDefinitions = IAT_GetDamageZones();
		foreach (string zone, IAT_MedicalZoneDefinition zoneDefinition : zoneDefinitions)
		{
			if (CanRegenerateZone(player, zone) && player.GetHealth(zone, "Blood") < player.GetMaxHealth(zone, "Blood"))
				return true;
		}
		return false;
	}

	bool HasHealedBandage(PlayerBase player)
	{
		map<string, ref IAT_MedicalBandageDefinition> bandageDefinitions = IAT_GetBandageSlots();
		foreach (string slot, IAT_MedicalBandageDefinition bandageDefinition : bandageDefinitions)
		{
			if (CanRemoveBandage(player, slot))
				return true;
		}
		return false;
	}

	bool HasBulletInZone(PlayerBase player, string zone)
	{
		IAT_MedicalState state = player.IAT_GetMedicalState();
		// Any shared bit means at least one retained bullet belongs to this zone.
		return state && (state.m_Bullets & IAT_GetZoneBoneMask(zone)) != 0;
	}

	bool IsZoneHealed(PlayerBase player, string zone)
	{
		float maximum = player.GetMaxHealth(zone, "Blood");
		return maximum > 0 && player.GetHealth(zone, "Blood") >= maximum && !HasBulletInZone(player, zone);
	}

	bool IsSevere(PlayerBase player, string zone)
	{
		float maximum = player.GetMaxHealth(zone, "Blood");
		return maximum > 0 && player.GetHealth(zone, "Blood") < maximum * IAT_SEVERE_WOUND_THRESHOLD;
	}

	int IAT_GetRegisteredBoneMask()
	{
		return m_RegisteredBoneMask;
	}

	TStringArray IAT_GetBones()
	{
		return m_Bones;
	}

	map<string, ref IAT_MedicalZoneDefinition> IAT_GetDamageZones()
	{
		return m_ZoneDefinitions;
	}

	map<string, ref IAT_MedicalBandageDefinition> IAT_GetBandageSlots()
	{
		return m_BandageDefinitions;
	}

	TStringArray IAT_GetBandageZones(string slot)
	{
		IAT_MedicalBandageDefinition definition = m_BandageDefinitions.Get(slot);
		if (definition)
			return definition.GetZones();
		return null;
	}

	TStringArray IAT_GetBandageBones(string slot)
	{
		IAT_MedicalBandageDefinition definition = m_BandageDefinitions.Get(slot);
		if (definition)
			return definition.GetBones();
		return null;
	}

	int IAT_GetBulletBoneBit(string boneName)
	{
		boneName.ToLower();
		IAT_MedicalBoneDefinition definition = m_BoneDefinitions.Get(boneName);
		if (definition)
			return definition.GetBit();
		return 0;
	}

	int IAT_GetDamageZoneBit(string zone)
	{
		IAT_MedicalZoneDefinition definition = m_ZoneDefinitions.Get(zone);
		if (definition)
			return definition.GetBit();
		return 0;
	}

	int IAT_GetZoneBoneMask(string zone)
	{
		IAT_MedicalZoneDefinition definition = m_ZoneDefinitions.Get(zone);
		if (definition)
			return definition.GetBoneMask();
		return 0;
	}

	string IAT_GetFirstBoneForZone(string zone)
	{
		IAT_MedicalZoneDefinition definition = m_ZoneDefinitions.Get(zone);
		if (definition)
			return definition.GetFirstBone();
		return "";
	}

	string IAT_GetBandageSlot(string zone)
	{
		IAT_MedicalZoneDefinition definition = m_ZoneDefinitions.Get(zone);
		if (definition)
			return definition.GetSlot();
		return "";
	}

	string IAT_GetBandageClass(string zone)
	{
		string slot = IAT_GetBandageSlot(zone);
		IAT_MedicalBandageDefinition definition = m_BandageDefinitions.Get(slot);
		if (definition)
			return definition.GetItemClass();
		return "";
	}

	string IAT_MapBoneNameToDamageZone(string boneName)
	{
		boneName.ToLower();
		IAT_MedicalBoneDefinition definition = m_BoneDefinitions.Get(boneName);
		if (definition)
			return definition.GetZone();
		Error("[IAT MEDICAL] Bone: " + boneName + " needs a mapping.");
		return "";
	}
};
