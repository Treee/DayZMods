modded class PlayerBase
{
	protected ref IAT_MedicalState m_IAT_MedicalState;
	protected bool m_IAT_LoadingMedical;
	// Suppress the attachment callback until the source dressing is copied.
	protected bool m_IAT_ApplyingBandage;
	protected bool m_IAT_LogReconcilePending;

	IAT_MedicalState IAT_GetMedicalState()
	{
		if (!g_Game.IsServer())
			return null;
		if (!m_IAT_MedicalState)
			m_IAT_MedicalState = new IAT_MedicalState;
		return m_IAT_MedicalState;
	}

	bool IAT_IsLoadingMedical()
	{
		return m_IAT_LoadingMedical;
	}

	EntityAI IAT_CreateBandageAttachment(string itemType, string slot)
	{
		// Inventory creation fires EEItemAttached synchronously.
		m_IAT_ApplyingBandage = true;
		EntityAI created = GetInventory().CreateAttachmentEx(itemType, InventorySlots.GetSlotIdFromString(slot));
		m_IAT_ApplyingBandage = false;
		return created;
	}

	void IAT_OnMedicalReconciled()
	{
		if (!m_IAT_LogReconcilePending)
			return;
		m_IAT_LogReconcilePending = false;
		IAT_MedicalLog.Snapshot(this, "LOAD_RECONCILED");
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		if (!g_Game.IsServer() || m_IAT_LoadingMedical || m_IAT_ApplyingBandage)
			return;
		PluginIATMedical medical = PluginIATMedical.Get();
		if (medical)
			medical.OnBandageAttached(this, item, slot_name);
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		if (!g_Game.IsServer() || m_IAT_LoadingMedical)
			return;
		PluginIATMedical medical = PluginIATMedical.Get();
		if (medical)
			medical.OnBandageDetached(this, item, slot_name);
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		if (g_Game.IsServer() && g_Game.IsMultiplayer())
		{
			IAT_GetMedicalState().Save(ctx);
			IAT_MedicalLog.Snapshot(this, "SAVE_SERIALIZED");
		}
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		m_IAT_LoadingMedical = true;
		if (!super.OnStoreLoad(ctx, version))
		{
			IAT_MedicalLog.Event(this, "LOAD_FAILED", "base_player_load_failed");
			return false;
		}
		if (g_Game.IsServer() && g_Game.IsMultiplayer())
		{
			bool loaded = IAT_GetMedicalState().Load(ctx);
			IAT_MedicalLog.Event(this, "LOAD_RESULT", string.Format("success=%1 %2", loaded, m_IAT_MedicalState.LoadResult));
			if (loaded)
				IAT_MedicalLog.Snapshot(this, "LOAD_READ");
			return loaded;
		}
		return true;
	}

	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		m_IAT_LoadingMedical = false;
		m_IAT_LogReconcilePending = true;
		IAT_MedicalLog.Snapshot(this, "AFTER_STORE_LOAD");
		// Bleeding-manager tick reconciles state after inventory restoration.
	}
}
