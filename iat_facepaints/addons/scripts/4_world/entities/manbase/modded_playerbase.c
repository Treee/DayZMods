modded class PlayerBase
{
	protected int m_FacePaintCategoryIndex;
	protected int m_FacePaintIndex;

	int m_TempFacePaintIndex;
	int m_TempFacePaintCategory;
	//=============================================== VANILLA OVERRIDE
	override void Init()
	{
		// preserve call chain
		super.Init();

		// default state is no paints
		m_FacePaintIndex = -1;
		m_FacePaintCategoryIndex = -1;

		// register an int for netsyncing which is our face paint state. clamp max value to total face paints
		RegisterNetSyncVariableInt("m_FacePaintIndex", -1, m_ModuleLifespan.GetFacePaintCount());
		RegisterNetSyncVariableInt("m_FacePaintCategoryIndex", -1, m_ModuleLifespan.GetFacePaintCategoryCount());
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		// PrintFormat("Category: %1 Paint: %2", GetFacePaintCategoryIndex(), GetFacePaintIndex());
		// if any changes are measured, update visuals
		if (GetFacePaintIndex() >= -1 && GetFacePaintCategoryIndex() >= -1 && (IsPlayerLoaded() || IsControlledPlayer()))
			UpdateFacePaintVisual();
	}
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		switch(rpc_type)
		{
			// server is sending copy of config to client (not authority, just for action checking)
			case IAT_FACEPAINT_RPC.CHECK_FACEPAINT_CONFIG:
			{
				Param1<IAT_FacePaintsConfig> configParams;
				// read the params, short circuit if there is an error
				if(!ctx.Read(configParams))
					return;

				// set client local copy of the config
				GetDayZGame().SetIATFacePaintConfig(configParams.param1);
				break;
			}
			// server side action context sync from menu option selection
			case IAT_FACEPAINT_RPC.IAT_RPC_FP_RADIAL_MENU:
			{
				if (GetGame().IsDedicatedServer())
				{
					// read serially the value as an integer
					if (!ctx.Read(m_TempFacePaintCategory))
						return;

					if (!ctx.Read(m_TempFacePaintIndex))
						return;
				}
			}
			break;
		}
	}


	//=============================================== CF MOD STORAGE "FIX"
	#ifndef CF_MODSTORAGE
	override void OnStoreSaveLifespan( ParamsWriteContext ctx )
	{
		// preserve order of call heiarchy
		super.OnStoreSaveLifespan(ctx);

		if (GetDayZGame().GetIATFacePaintConfig())
		{
			if (GetDayZGame().GetIATFacePaintConfig().GetSavePlayerPaintsToDatabase())
			{
				// write my value
				ctx.Write(m_FacePaintIndex);
				ctx.Write(m_FacePaintCategoryIndex);
			}
		}
	}
	override bool OnStoreLoadLifespan( ParamsReadContext ctx, int version )
	{
		// if existing db state is not loading correctly, fail out before our stuff (sanity check)
		if (!super.OnStoreLoadLifespan(ctx, version))
			return false;

		// default face paint state is no paint, -1
		int facePaintIndex = -1;
		int facePaintCategoryIndex = -1;

		if (GetDayZGame().GetIATFacePaintConfig())
		{
			if (GetDayZGame().GetIATFacePaintConfig().GetSavePlayerPaintsToDatabase())
			{
				// read the value serially
				if(ctx.Read( facePaintIndex ))
					m_FacePaintIndex = facePaintIndex;

				if(ctx.Read( facePaintCategoryIndex ))
					m_FacePaintCategoryIndex = facePaintCategoryIndex;
			}
		}

		// who cares if it works, return true lol
		return true;
	}
	#endif
	#ifdef CF_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[IAT_FacePaints_Scripts];
		if (!ctx) return;

		if (GetDayZGame().GetIATFacePaintConfig())
		{
			if (GetDayZGame().GetIATFacePaintConfig().GetSavePlayerPaintsToDatabase())
			{
				// write my value
				ctx.Write(m_FacePaintIndex);
				ctx.Write(m_FacePaintCategoryIndex);
			}
		}
	}
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage)) return false;

		auto ctx = storage[IAT_FacePaints_Scripts];
		if (!ctx) return true;

		int facePaintIndex = -1;
		int facePaintCategoryIndex = -1;

		if (GetDayZGame().GetIATFacePaintConfig())
		{
			if (GetDayZGame().GetIATFacePaintConfig().GetSavePlayerPaintsToDatabase())
			{
				// read the value serially
				if(ctx.Read( facePaintIndex ))
					m_FacePaintIndex = facePaintIndex;

				if(ctx.Read( facePaintCategoryIndex ))
					m_FacePaintCategoryIndex = facePaintCategoryIndex;
			}
		}
		return true;
	}
	#endif
	//=============================================== CF MOD STORAGE "FIX"

	// ===============================================
	// CUSTOM
	// ===============================================
	void SetFacePaint(int categoryIndex, int paintIndex)
	{
		m_FacePaintCategoryIndex = categoryIndex;
		m_FacePaintIndex = paintIndex;
		SetSynchDirty();
	}

	int GetFacePaintIndex()
	{
		return m_FacePaintIndex;
	}
	int GetFacePaintCategoryIndex()
	{
		return m_FacePaintCategoryIndex;
	}

	void ClearPaint()
	{
		SetFacePaint(-1, -1);
	}

	void UpdateFacePaintVisual()
	{
		// female characters need this because they dont have beard so no player lifespan level stuff
		if (!IsMale())
		{
			string camoMaterial;
			if (m_FacePaintIndex == -1)
				camoMaterial = m_ModuleLifespan.GetFemaleBaseMaterial(GetType());
			else
				camoMaterial = m_ModuleLifespan.GetPaintPathFemale(m_FacePaintCategoryIndex, m_FacePaintIndex, GetType());

			if (camoMaterial)
				SetFaceMaterial(camoMaterial);
		}
	}
};
