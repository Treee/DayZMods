modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("PluginIATMedical", false, true);
	}
}

class PluginIATMedical : PluginBase
{
	static const int IAT_BULLET_BONE_COUNT = 30;
	static const int IAT_BULLET_BONE_MASK_ALL = (1 << IAT_BULLET_BONE_COUNT) - 1;
	static const float IAT_SEVERE_WOUND_THRESHOLD = 0.5;
	static const float IAT_ZONE_BLOODLOSS_SCALE = 0.057;
	static const float IAT_BULLET_EXTRACTION_SECONDS = 10;

	// Built once from the registrations below, including on clients without a
	// plugin instance. Ordered views are for processing, never for lookup.
	protected static ref TStringArray m_Bones;
	protected static ref TStringArray m_Zones;
	protected static ref TStringArray m_Slots;
	protected static ref map<string, string> m_BoneZones;
	protected static ref map<string, int> m_BoneBits;
	protected static ref map<string, int> m_ZoneBits;
	protected static ref map<string, int> m_ZoneBoneMasks;
	protected static ref map<string, string> m_ZoneFirstBones;
	protected static ref map<string, string> m_ZoneSlots;
	protected static ref map<string, string> m_SlotClasses;
	protected static ref map<string, ref TStringArray> m_SlotZones;
	protected static ref map<string, ref TStringArray> m_SlotBones;

	protected static void IAT_InitDefinitions()
	{
		if (m_BoneZones)
			return;
		m_Bones = new TStringArray;
		m_Zones = new TStringArray;
		m_Slots = new TStringArray;
		m_BoneZones = new map<string, string>;
		m_BoneBits = new map<string, int>;
		m_ZoneBits = new map<string, int>;
		m_ZoneBoneMasks = new map<string, int>;
		m_ZoneFirstBones = new map<string, string>;
		m_ZoneSlots = new map<string, string>;
		m_SlotClasses = new map<string, string>;
		m_SlotZones = new map<string, ref TStringArray>;
		m_SlotBones = new map<string, ref TStringArray>;

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

		// Explicit bit indices are save-format IDs, not map iteration positions.
		IAT_RegisterBone("head", 0, "Head");
		IAT_RegisterBone("brain", 1, "Head");
		IAT_RegisterBone("neck", 2, "Torso");
		IAT_RegisterBone("pelvis", 3, "Torso");
		IAT_RegisterBone("spine", 4, "Torso");
		IAT_RegisterBone("spine1", 5, "Torso");
		IAT_RegisterBone("spine2", 6, "Torso");
		IAT_RegisterBone("spine3", 7, "Torso");
		IAT_RegisterBone("leftshoulder", 8, "LeftArm");
		IAT_RegisterBone("leftarm", 9, "LeftArm");
		IAT_RegisterBone("leftarmroll", 10, "LeftArm");
		IAT_RegisterBone("leftforearm", 11, "LeftArm");
		IAT_RegisterBone("leftforearmroll", 12, "LeftHand");
		IAT_RegisterBone("rightshoulder", 13, "RightArm");
		IAT_RegisterBone("rightarm", 14, "RightArm");
		IAT_RegisterBone("rightarmroll", 15, "RightArm");
		IAT_RegisterBone("rightforearm", 16, "RightArm");
		IAT_RegisterBone("rightforearmroll", 17, "RightHand");
		IAT_RegisterBone("leftleg", 18, "LeftLeg");
		IAT_RegisterBone("leftlegroll", 19, "LeftLeg");
		IAT_RegisterBone("leftupleg", 20, "LeftLeg");
		IAT_RegisterBone("leftuplegroll", 21, "LeftLeg");
		IAT_RegisterBone("rightleg", 22, "RightLeg");
		IAT_RegisterBone("rightlegroll", 23, "RightLeg");
		IAT_RegisterBone("rightupleg", 24, "RightLeg");
		IAT_RegisterBone("rightuplegroll", 25, "RightLeg");
		IAT_RegisterBone("leftfoot", 26, "LeftFoot");
		IAT_RegisterBone("lefttoebase", 27, "LeftFoot");
		IAT_RegisterBone("rightfoot", 28, "RightFoot");
		IAT_RegisterBone("righttoebase", 29, "RightFoot");
	}

	protected static void IAT_RegisterBandage(string slot, string itemType)
	{
		m_Slots.Insert(slot);
		m_SlotClasses.Insert(slot, itemType);
		m_SlotZones.Insert(slot, new TStringArray);
		m_SlotBones.Insert(slot, new TStringArray);
	}

	protected static void IAT_RegisterZone(string zone, int bitIndex, string slot)
	{
		m_Zones.Insert(zone);
		m_ZoneBits.Insert(zone, 1 << bitIndex);
		m_ZoneSlots.Insert(zone, slot);
		m_ZoneBoneMasks.Insert(zone, 0);
		m_SlotZones.Get(slot).Insert(zone);
	}

	protected static void IAT_RegisterBone(string bone, int bitIndex, string zone)
	{
		int bit = 1 << bitIndex;
		m_Bones.Insert(bone);
		m_BoneZones.Insert(bone, zone);
		m_BoneBits.Insert(bone, bit);
		m_ZoneBoneMasks.Set(zone, m_ZoneBoneMasks.Get(zone) | bit);
		if (!m_ZoneFirstBones.Contains(zone))
			m_ZoneFirstBones.Insert(zone, bone);
		m_SlotBones.Get(m_ZoneSlots.Get(zone)).Insert(bone);
	}

	static TStringArray IAT_GetBones()
	{
		IAT_InitDefinitions();
		return m_Bones;
	}

	static TStringArray IAT_GetDamageZones()
	{
		IAT_InitDefinitions();
		return m_Zones;
	}

	static TStringArray IAT_GetBandageSlots()
	{
		IAT_InitDefinitions();
		return m_Slots;
	}

	static TStringArray IAT_GetBandageZones(string slot)
	{
		IAT_InitDefinitions();
		return m_SlotZones.Get(slot);
	}

	static TStringArray IAT_GetBandageBones(string slot)
	{
		IAT_InitDefinitions();
		return m_SlotBones.Get(slot);
	}

	static int IAT_GetBulletBoneBit(string boneName)
	{
		IAT_InitDefinitions();
		boneName.ToLower();
		return m_BoneBits.Get(boneName);
	}

	static int IAT_GetDamageZoneBit(string zone)
	{
		IAT_InitDefinitions();
		return m_ZoneBits.Get(zone);
	}

	static int IAT_GetZoneBoneMask(string zone)
	{
		IAT_InitDefinitions();
		return m_ZoneBoneMasks.Get(zone);
	}

	static string IAT_GetFirstBoneForZone(string zone)
	{
		IAT_InitDefinitions();
		return m_ZoneFirstBones.Get(zone);
	}

	static string IAT_GetBandageSlot(string zone)
	{
		IAT_InitDefinitions();
		return m_ZoneSlots.Get(zone);
	}

	static string IAT_GetBandageClass(string zone)
	{
		IAT_InitDefinitions();
		return m_SlotClasses.Get(m_ZoneSlots.Get(zone));
	}

	static string IAT_MapBoneNameToDamageZone(string boneName)
	{
		IAT_InitDefinitions();
		boneName.ToLower();
		if (m_BoneZones.Contains(boneName))
			return m_BoneZones.Get(boneName);
		PrintFormat("====================================[IAT_ENHANCED_MEDICAL] Bone: %1 needs a mapping.", boneName);
		return "";
	}

	static PluginIATMedical Get()
	{
		return PluginIATMedical.Cast(GetPlugin(PluginIATMedical));
	}

	bool IsWearingBandage(PlayerBase player, string zone)
	{
		string slot = PluginIATMedical.IAT_GetBandageSlot(zone);
		if (slot == "")
			return false;
		EntityAI dressing = player.FindAttachmentBySlotName(slot);
		return dressing && dressing.IsInherited(WZ_Bandage_Base) && !dressing.IsRuined();
	}

	bool NeedsZoneRegen(PlayerBase player)
	{
		foreach (string zone : PluginIATMedical.IAT_GetDamageZones())
		{
			if (!HasBulletInZone(player, zone) && player.GetHealth(zone, "Blood") < player.GetMaxHealth(zone, "Blood"))
				return true;
		}
		return false;
	}

	protected bool CanRemoveBandage(PlayerBase player, string slot)
	{
		if (!g_Game.IsServer() || !player.IsAlive() || player.IAT_IsLoadingMedical())
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
		foreach (string bone : IAT_GetBandageBones(slot))
		{
			if (manager.IsBleedingSourceActive(bone))
				return false;
		}
		return true;
	}

	bool HasHealedBandage(PlayerBase player)
	{
		foreach (string slot : PluginIATMedical.IAT_GetBandageSlots())
		{
			if (CanRemoveBandage(player, slot))
				return true;
		}
		return false;
	}

	void RemoveHealedBandages(PlayerBase player)
	{
		foreach (string slot : PluginIATMedical.IAT_GetBandageSlots())
		{
			if (!CanRemoveBandage(player, slot))
				continue;
			EntityAI bandage = player.FindAttachmentBySlotName(slot);
			IAT_MedicalLog.Event(player, "BANDAGE_HEALED_REMOVAL", "slot=" + slot + " item=" + bandage.GetType());
			// Like an applied splint, the finished dressing is deleted, not dropped.
			bandage.DeleteSafe();
		}
	}

	bool HasBulletInZone(PlayerBase player, string zone)
	{
		IAT_MedicalState state = player.IAT_GetMedicalState();
		return state && (state.Bullets & IAT_GetZoneBoneMask(zone)) != 0;
	}

	bool IsZoneHealed(PlayerBase player, string zone)
	{
		float maximum = player.GetMaxHealth(zone, "Blood");
		return maximum > 0 && player.GetHealth(zone, "Blood") >= maximum && !HasBulletInZone(player, zone);
	}

	bool IsSevere(PlayerBase player, string zone)
	{
		float maximum = player.GetMaxHealth(zone, "Blood");
		return maximum > 0 && player.GetHealth(zone, "Blood") < maximum * PluginIATMedical.IAT_SEVERE_WOUND_THRESHOLD;
	}

	void RecordWound(PlayerBase player, string bone)
	{
		IAT_MedicalState state = player.IAT_GetMedicalState();
		int bit = PluginIATMedical.IAT_GetBulletBoneBit(bone);
		state.Wounds |= bit;
		state.DressedWounds &= ~bit;
		IAT_MedicalLog.Event(player, "WOUND_RECORDED", "bone=" + bone);
	}

	void RecordBullet(PlayerBase player, string bone)
	{
		IAT_MedicalState state = player.IAT_GetMedicalState();
		state.Bullets |= PluginIATMedical.IAT_GetBulletBoneBit(bone);
		IAT_MedicalLog.Event(player, "BULLET_RECORDED", "bone=" + bone + " zone=" + PluginIATMedical.IAT_MapBoneNameToDamageZone(bone));
	}

	bool IsBulletAmmo(string ammo)
	{
		// CfgAmmo ancestry supports modded bullets without a naming convention.
		for (int depth = 0; depth < 64 && ammo != ""; depth++)
		{
			// These inherit bullet classes but are not retained firearm rounds.
			if (ammo == "Bolt_Base" || ammo == "Bullet_Flare" || ammo == "Bullet_40mm_Base" || ammo == "Bullet_12GaugeRubberSlug" || ammo == "Bullet_12GaugeBeanbag")
				return false;
			if (ammo == "Bullet_Base" || ammo == "Shotgun_Base")
				return true;
			string parent;
			if (!g_Game.ConfigGetBaseName("CfgAmmo " + ammo, parent) || parent == ammo)
				break;
			ammo = parent;
		}
		return false;
	}

	bool ApplyDressing(PlayerBase player, ItemBase material)
	{
		BleedingSourcesManagerServer manager = player.GetBleedingManagerServer();
		if (!manager || !material || material.IsRuined())
			return false;
		string zone = manager.IAT_GetDamageZoneFromMostSignificantSource();
		string slot = PluginIATMedical.IAT_GetBandageSlot(zone);
		string itemType = PluginIATMedical.IAT_GetBandageClass(zone);
		if (slot == "" || itemType == "")
			return false;

		EntityAI attached = player.FindAttachmentBySlotName(slot);
		WZ_Bandage_Base existingBandage;
		if (attached)
		{
			if (!Class.CastTo(existingBandage, attached) || existingBandage.IsRuined())
			{
				IAT_MedicalLog.Event(player, "BANDAGE_FAILED", "occupied_or_ruined slot=" + slot);
				player.MessageStatus("Remove the damaged or incompatible dressing before applying a new one.");
				return false;
			}
		}
		else
		{
			// CreateAttachmentEx fires EEItemAttached before returning. Defer closure
			// until properties are transferred, using the original treatment item.
			EntityAI created = player.IAT_CreateBandageAttachment(itemType, slot);
			if (!Class.CastTo(existingBandage, created))
			{
				if (created)
					g_Game.ObjectDelete(created);
				IAT_MedicalLog.Event(player, "BANDAGE_FAILED", "creation_failed slot=" + slot + " class=" + itemType);
				player.MessageStatus("The dressing could not be attached.");
				return false;
			}
		}
		MiscGameplayFunctions.TransferItemProperties(material, existingBandage, true, false, true);
		existingBandage.SetCleanness(material.GetCleanness());
		CloseDressedSources(player, slot, material);
		IAT_MedicalLog.Event(player, "BANDAGE_APPLIED", "slot=" + slot + " class=" + itemType + " material=" + material.GetType());
		return true;
	}

	void CloseDressedSources(PlayerBase player, string slot, ItemBase material)
	{
		if (player.GetBleedingManagerServer())
			player.GetBleedingManagerServer().IAT_CloseSourcesInSlot(slot, material);
	}

	void ReopenDressedWounds(PlayerBase player, string slot)
	{
		if (!player.IsAlive() || player.IAT_IsLoadingMedical() || !player.GetBleedingManagerServer())
			return;
		TStringArray coveredBones = IAT_GetBandageBones(slot);
		if (!coveredBones)
			return;
		IAT_MedicalState state = player.IAT_GetMedicalState();
		foreach (string bone : coveredBones)
		{
			int bit = PluginIATMedical.IAT_GetBulletBoneBit(bone);
			if ((state.DressedWounds & bit) == 0)
				continue;
			string zone = PluginIATMedical.IAT_MapBoneNameToDamageZone(bone);
			if (IsWearingBandage(player, zone))
				continue;
			if (IsZoneHealed(player, zone))
			{
				state.Wounds &= ~bit;
				state.DressedWounds &= ~bit;
				IAT_MedicalLog.Event(player, "WOUND_HEALED", "bone=" + bone + " zone=" + zone);
			}
			else
			{
				// RecordWound clears DressedWounds only when creation succeeds.
				if (player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(bone))
					IAT_MedicalLog.Event(player, "WOUND_REOPENED", "bone=" + bone + " slot=" + slot + " reason=missing_or_ruined_dressing");
			}
		}
	}

	void UpdateHealing(PlayerBase player)
	{
		if (!player.IsAlive() || player.IAT_IsLoadingMedical())
			return;
		IAT_MedicalState state = player.IAT_GetMedicalState();
		foreach (string bone : PluginIATMedical.IAT_GetBones())
		{
			int bit = PluginIATMedical.IAT_GetBulletBoneBit(bone);
			if ((state.Wounds & bit) == 0)
				continue;
			string zone = PluginIATMedical.IAT_MapBoneNameToDamageZone(bone);
			if (IsZoneHealed(player, zone) && !player.GetBleedingManagerServer().IsBleedingSourceActive(bone))
			{
				state.Wounds &= ~bit;
				state.DressedWounds &= ~bit;
				IAT_MedicalLog.Event(player, "WOUND_HEALED", "bone=" + bone + " zone=" + zone);
			}
		}
		// Also catches ruined/deleted dressings and missing attachments on load.
		foreach (string slot : PluginIATMedical.IAT_GetBandageSlots())
			ReopenDressedWounds(player, slot);
		player.IAT_OnMedicalReconciled();
	}

	bool ExtractBullet(PlayerBase patient, out string zone)
	{
		zone = "";
		if (!g_Game.IsServer() || !patient || !patient.IsAlive())
			return false;
		IAT_MedicalState state = patient.IAT_GetMedicalState();
		foreach (string bone : PluginIATMedical.IAT_GetBones())
		{
			int bit = PluginIATMedical.IAT_GetBulletBoneBit(bone);
			if ((state.Bullets & bit) == 0)
				continue;
			state.Bullets &= ~bit;
			zone = PluginIATMedical.IAT_MapBoneNameToDamageZone(bone);
			IAT_MedicalLog.Event(patient, "BULLET_EXTRACTED", "bone=" + bone + " zone=" + zone);
			return true;
		}
		IAT_MedicalLog.Event(patient, "EXTRACTION_EMPTY");
		return false;
	}

	void OnBandageAttached(PlayerBase player, EntityAI item, string slot_name)
	{
		if (item && item.IsInherited(WZ_Bandage_Base) && !item.IsRuined())
		{
			IAT_MedicalLog.Event(player, "BANDAGE_ATTACHED", "slot=" + slot_name + " item=" + item.GetType());
			CloseDressedSources(player, slot_name, ItemBase.Cast(item));
		}
	}

	void OnBandageDetached(PlayerBase player, EntityAI item, string slot_name)
	{
		if (item && item.IsInherited(WZ_Bandage_Base))
		{
			IAT_MedicalLog.Event(player, "BANDAGE_DETACHED", "slot=" + slot_name + " item=" + item.GetType());
			ReopenDressedWounds(player, slot_name);
		}
	}
}
