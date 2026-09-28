modded class BleedingSource
{
	override void OnUpdateServer(float deltatime, float blood_scale, bool no_blood_loss)
	{
		string zone = PluginIATMedical.IAT_MapBoneNameToDamageZone(m_Bone);
		if (!no_blood_loss && zone != "" && m_Player.GetMaxHealth(zone, "Blood") > 0)
		{
			float flow = m_FlowModifier;
			if (m_Type == eBleedingSourceType.CONTAMINATED)
				flow *= PlayerConstants.BLEEDING_SOURCE_BURN_MODIFIER;
			float loss = PlayerConstants.BLEEDING_SOURCE_BLOODLOSS_PER_SEC * blood_scale * deltatime * flow;
			m_Player.AddHealth(zone, "Blood", loss * PluginIATMedical.IAT_ZONE_BLOODLOSS_SCALE);
		}
		// Keep vanilla global blood loss, particle state and source lifetime.
		super.OnUpdateServer(deltatime, blood_scale, no_blood_loss);
		// Vanilla sets this even when RequestDeletion rejects a severe wound.
		PluginIATMedical medical = PluginIATMedical.Get();
		if (medical && zone != "" && medical.IsSevere(m_Player, zone))
			m_DeleteRequested = false;
	}
}

modded class BleedingSourcesManagerServer
{
	protected float m_IAT_HealingTick;

	string IAT_GetDamageZoneFromMostSignificantSource()
	{
		BleedingSourceZone meta = GetBleedingSourceMeta(GetMostSignificantBleedingSource());
		if (!meta)
			return "";
		return PluginIATMedical.IAT_MapBoneNameToDamageZone(meta.GetBoneName());
	}

	override protected void AddBleedingSource(int bit)
	{
		super.AddBleedingSource(bit);
		PluginIATMedical medical = PluginIATMedical.Get();
		BleedingSourceZone meta = GetBleedingSourceMeta(bit);
		if (medical && meta && (m_Player.GetBleedingBits() & bit) != 0)
			medical.RecordWound(m_Player, meta.GetBoneName());
	}

	override void RequestDeletion(int bit)
	{
		PluginIATMedical medical = PluginIATMedical.Get();
		BleedingSourceZone meta = GetBleedingSourceMeta(bit);
		if (medical && meta && medical.IsSevere(m_Player, PluginIATMedical.IAT_MapBoneNameToDamageZone(meta.GetBoneName())))
			return;
		super.RequestDeletion(bit);
	}

	void IAT_CloseSourcesInSlot(string slot, ItemBase material)
	{
		IAT_MedicalState state = m_Player.IAT_GetMedicalState();
		for (int i = m_BleedingSources.Count() - 1; i >= 0; i--)
		{
			int bit = m_BleedingSources.GetKey(i);
			BleedingSourceZone meta = GetBleedingSourceMeta(bit);
			if (!meta)
				continue;
			string bone = meta.GetBoneName();
			string zone = PluginIATMedical.IAT_MapBoneNameToDamageZone(bone);
			if (PluginIATMedical.IAT_GetBandageSlot(zone) != slot)
				continue;
			int woundBit = PluginIATMedical.IAT_GetBulletBoneBit(bone);
			state.Wounds |= woundBit;
			state.DressedWounds |= woundBit;
			// Cancel pending natural closure before this bit can be reopened.
			int queued = m_DeleteList.Find(bit);
			if (queued != -1)
				m_DeleteList.Remove(queued);
			SetItem(material);
			RemoveBleedingSource(bit);
			IAT_MedicalLog.Event(m_Player, "WOUND_DRESSED", "bone=" + bone + " slot=" + slot + " material=" + material.GetType());
		}
	}

	override void ProcessHit(float damage, EntityAI source, int component, string zone, string ammo, vector modelPos)
	{
		super.ProcessHit(damage, source, component, zone, ammo, modelPos);
		PluginIATMedical medical = PluginIATMedical.Get();
		if (!medical || damage <= 0 || !medical.IsBulletAmmo(ammo))
			return;
		BleedingSourceZone meta = GetBleedingSourceMeta(GetBitFromSelectionID(component));
		if (meta)
			medical.RecordBullet(m_Player, meta.GetBoneName());
		else
		{
			// Some hit components have no registered bleeding selection.
			string bone = PluginIATMedical.IAT_GetFirstBoneForZone(zone);
			if (bone != "")
				medical.RecordBullet(m_Player, bone);
		}
	}

	override void OnTick(float delta_time)
	{
		super.OnTick(delta_time);
		m_IAT_HealingTick += delta_time;
		if (m_IAT_HealingTick < TICK_INTERVAL_SEC)
			return;
		m_IAT_HealingTick = 0;
		PluginIATMedical medical = PluginIATMedical.Get();
		if (medical)
			medical.UpdateHealing(m_Player);
	}
}
