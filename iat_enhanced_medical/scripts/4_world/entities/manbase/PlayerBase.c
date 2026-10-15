// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Server medical records, replicated bullet presence, attachments, and persistence.
// Integration: server authority and save compatibility.
// Documentation: iat_enhanced_medical/README.md

modded class PlayerBase
{
	protected ref IAT_MedicalState m_IAT_MedicalState;
	protected IAT_PluginMedical m_IAT_MedicalPlugin;
	protected bool m_IAT_HasRetainedBullet;

	void PlayerBase()
	{
		RegisterNetSyncVariableBool("m_IAT_HasRetainedBullet");
	}

	//! Actions use authoritative records on the server and replicated presence on clients.
	bool IAT_HasRetainedBullet()
	{
		if (g_Game.IsServer())
		{
			IAT_MedicalState state = IAT_GetMedicalState();
			return state && state.m_Bullets != 0;
		}
		return m_IAT_HasRetainedBullet;
	}

	//! Publish the derived summary after recording, extracting, or restoring bullets.
	void IAT_SyncBulletPresence()
	{
		if (!g_Game.IsServer())
			return;
		bool hasBullet = IAT_HasRetainedBullet();
		if (m_IAT_HasRetainedBullet == hasBullet)
			return;
		m_IAT_HasRetainedBullet = hasBullet;
		SetSynchDirty();
	}

	IAT_MedicalState IAT_GetMedicalState()
	{
		// Medical records are owned by the dedicated server.
		if (!g_Game.IsDedicatedServer())
			return null;

		if (!m_IAT_MedicalState)
			m_IAT_MedicalState = new IAT_MedicalState;

		return m_IAT_MedicalState;
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (!g_Game.IsDedicatedServer())
			return;

		WZ_Bandage_Base bandage;
		if (Class.CastTo(bandage, item))
		{
			if (Class.CastTo(m_IAT_MedicalPlugin, GetPlugin(IAT_PluginMedical)))
				m_IAT_MedicalPlugin.OnBandageAttached(this, item, slot_name);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (!g_Game.IsDedicatedServer())
			return;

		WZ_Bandage_Base bandage;
		if (Class.CastTo(bandage, item))
		{
			if (Class.CastTo(m_IAT_MedicalPlugin, GetPlugin(IAT_PluginMedical)))
				m_IAT_MedicalPlugin.OnBandageDetached(this, bandage, slot_name);
		}
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		IAT_GetMedicalState().Save(ctx);
		if (Class.CastTo(m_IAT_MedicalPlugin, GetPlugin(IAT_PluginMedical)))
		{
			m_IAT_MedicalPlugin.LogSnapshot(this, "SAVE_SERIALIZED");
		}
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (super.OnStoreLoad(ctx, version))
		{
			bool loaded = IAT_GetMedicalState().Load(ctx);
			if (loaded)
				IAT_SyncBulletPresence();
			if (Class.CastTo(m_IAT_MedicalPlugin, GetPlugin(IAT_PluginMedical)))
			{
				m_IAT_MedicalPlugin.LogEvent(this, "LOAD_RESULT", string.Format("success=%1 %2", loaded, m_IAT_MedicalState.m_LoadResult));
				if (loaded)
					m_IAT_MedicalPlugin.LogSnapshot(this, "LOAD_READ");
			}
			return loaded;
		}
		else
		{
			if (Class.CastTo(m_IAT_MedicalPlugin, GetPlugin(IAT_PluginMedical)))
			{
				m_IAT_MedicalPlugin.LogEvent(this, "LOAD_FAILED", "base_player_load_failed");
			}
			return false;
		}
	}

	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		IAT_SyncBulletPresence();
		if (Class.CastTo(m_IAT_MedicalPlugin, GetPlugin(IAT_PluginMedical)))
		{
			m_IAT_MedicalPlugin.LogSnapshot(this, "AFTER_STORE_LOAD");
		}
	}
};
