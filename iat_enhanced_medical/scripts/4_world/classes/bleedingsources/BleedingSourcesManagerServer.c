// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Medical wound history, expiry, hits, and reconciliation.
// Integration: server medical state and wound lifecycle.
// Documentation: iat_enhanced_medical/README.md

modded class BleedingSourcesManagerServer
{
	protected float m_IAT_HealingTick;
	protected float m_IAT_RetainedBleedingTick;

	protected float IAT_GetRetentionRoll()
	{
		return Math.RandomFloat(0, 1);
	}

	// Prepare the attachment for the same source vanilla will bandage next.
	// Multiple bones/zones can share one regional attachment.
	string IAT_GetDamageZoneFromMostSignificantSource()
	{
		return IAT_GetDamageZoneFromSourceBit(GetMostSignificantBleedingSource());
	}

	// Resolve using selection identity; the particle bone can differ.
	string IAT_GetDamageZoneFromSourceBit(int bit)
	{
		BleedingSourceZone meta = GetBleedingSourceMeta(bit);
		if (!meta)
			return "";
		IAT_PluginMedical medical;
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
			return medical.IAT_MapBoneNameToDamageZone(meta.GetSelectionName());
		return "";
	}

	// After vanilla creates a source, clear that bone's previous dressed bit.
	// The plugin does not maintain a separate general wound/active-bleed mask.
	override protected void AddBleedingSource(int bit)
	{
		super.AddBleedingSource(bit);
		IAT_PluginMedical medical;
		BleedingSourceZone meta = GetBleedingSourceMeta(bit);
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) && meta && (m_Player.GetBleedingBits() & bit) != 0)
			medical.OnBleedingSourceAdded(m_Player, meta.GetSelectionName());
	}

	// Observe individual closure; vanilla still removes the source and rolls infection.
	// Only treatment with a covering dressing records dressed history. Natural
	// expiry has no treatment item and must not create a wound that later reopens.
	override protected bool RemoveBleedingSource(int bit)
	{
		// Vanilla clears m_Item during removal, so capture the treatment first.
		ItemBase material = m_Item;
		BleedingSourceZone meta = GetBleedingSourceMeta(bit);
		bool wasActive = m_BleedingSources.Contains(bit);
		if (wasActive && material)
		{
			// A pending expiry must not later delete a newly reopened source.
			int queued = m_DeleteList.Find(bit);
			if (queued != -1)
				m_DeleteList.Remove(queued);
		}
		bool removed = super.RemoveBleedingSource(bit);
		// Vanilla returns true even for an absent source; verify the state transition.
		IAT_PluginMedical medical;
		if (wasActive && !m_BleedingSources.Contains(bit) && meta && material && Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
			medical.OnBleedingSourceClosed(m_Player, meta.GetSelectionName(), material);
		return removed;
	}

	// Gate natural expiry only: below 50% zone Blood the bleed must be treated.
	// At 50% or above, allow vanilla expiry. Bandaging calls RemoveBleedingSource
	// directly, so this guard never prevents deliberate treatment.
	override void RequestDeletion(int bit)
	{
		IAT_PluginMedical medical;
		BleedingSourceZone meta = GetBleedingSourceMeta(bit);
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) && meta && medical.IsSevere(m_Player, medical.IAT_MapBoneNameToDamageZone(meta.GetSelectionName())))
			return;
		super.RequestDeletion(bit);
	}

	// Vanilla decides whether the hit causes bleeding. Record retained bullets
	// independently: a qualifying bullet hit can exist without an active bleed.
	override void ProcessHit(float damage, EntityAI source, int component, string zone, string ammo, vector modelPos)
	{
		super.ProcessHit(damage, source, component, zone, ammo, modelPos);
		IAT_PluginMedical medical;
		if (!Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) || damage <= 0 || !medical.IsBulletAmmo(ammo))
			return;
		if (IAT_GetRetentionRoll() >= IAT_PluginMedical.IAT_BULLET_RETENTION_CHANCE)
			return;
		BleedingSourceZone meta = GetBleedingSourceMeta(GetBitFromSelectionID(component));
		if (meta)
			medical.RecordBullet(m_Player, meta.GetSelectionName());
		else
		{
			// Some hit components have no registered bleeding selection.
			string bone = medical.IAT_GetFirstBoneForZone(zone);
			if (bone != "")
				medical.RecordBullet(m_Player, bone);
		}
	}

	// Reconcile dressed history at the bleeding tick interval, even with no bleeds.
	// Clear healed entries and reopen treated bones when dressings are missing or
	// ruined, including after load. Creation/removal hooks alone cannot detect
	// a worn dressing becoming ruined or a zone finishing its recovery.
	override void OnTick(float delta_time)
	{
		super.OnTick(delta_time);
		m_IAT_RetainedBleedingTick += delta_time;
		if (m_IAT_RetainedBleedingTick >= IAT_PluginMedical.IAT_RETAINED_BULLET_LOSS_INTERVAL)
		{
			int intervals = Math.Floor(m_IAT_RetainedBleedingTick / IAT_PluginMedical.IAT_RETAINED_BULLET_LOSS_INTERVAL);
			m_IAT_RetainedBleedingTick -= intervals * IAT_PluginMedical.IAT_RETAINED_BULLET_LOSS_INTERVAL;
			IAT_PluginMedical retainedMedical;
			if (!m_DisableBloodLoss && Class.CastTo(retainedMedical, GetPlugin(IAT_PluginMedical)))
				retainedMedical.IAT_ApplyRetainedBulletBloodLoss(m_Player, intervals);
		}
		m_IAT_HealingTick += delta_time;
		if (m_IAT_HealingTick < TICK_INTERVAL_SEC)
			return;
		m_IAT_HealingTick = 0;
		IAT_PluginMedical medical;
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
			medical.UpdateHealing(m_Player);
	}
}
