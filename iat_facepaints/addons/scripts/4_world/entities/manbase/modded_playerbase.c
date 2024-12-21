modded class PlayerBase
{
	protected int m_FacePaintState;
	int m_TempFacePaintState;
	//=============================================== VANILLA OVERRIDE
	override void Init()
	{
		// preserve call chain
		super.Init();

		// default state is no paints
		m_FacePaintState = -1;

		// register an int for netsyncing which is our face paint state. clamp max value to total face paints
		RegisterNetSyncVariableInt("m_FacePaintState", -1, m_ModuleLifespan.GetFacePaintCount());
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		// if any changes are measured, update visuals
		if (GetFacePaintIndex() >= -1 && (IsPlayerLoaded() || IsControlledPlayer()))
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
					int camoId;
					// read serially the value as an integer
					if ( !ctx.Read(camoId) )
						return;
					m_TempFacePaintState = camoId;
				}
			}
			break;
		}
	}
	override void OnStoreSaveLifespan( ParamsWriteContext ctx )
	{
		// preserve order of call heiarchy
		super.OnStoreSaveLifespan(ctx);
		// write my value
		ctx.Write(m_FacePaintState);
	}
	override bool OnStoreLoadLifespan( ParamsReadContext ctx, int version )
	{
		// if existing db state is not loading correctly, fail out before our stuff (sanity check)
		if (!super.OnStoreLoadLifespan(ctx, version))
			return false;

		// default face paint state is no paint, -1
		int facePaintState = -1;
		// read the value serially
		if(ctx.Read( facePaintState ))
			m_FacePaintState = facePaintState;

		// who cares if it works, return true lol
		return true;
	}

	// ===============================================
	// CUSTOM
	// ===============================================
	void SetFacePaint(int index)
	{
		m_FacePaintState = index;
		SetSynchDirty();
	}

	int GetFacePaintIndex()
	{
		return m_FacePaintState;
	}

	void ClearPaint()
	{
		SetFacePaint(-1);
	}

	TStringArray GetFacePaintList(int index)
	{
		if (m_ModuleLifespan)
		{
			switch(index)
			{
				case 1:
					return m_ModuleLifespan.GetFacePaintCamoOptions();
				break;
				case 2:
					return m_ModuleLifespan.GetFacePaintFlagOptions();
				break;
				case 3:
					return m_ModuleLifespan.GetFacePaintMaskOptions();
				break;
				case 4:
					return m_ModuleLifespan.GetFacePaintScarOptions();
				break;
			}
		}
		return {};
	}

	void UpdateFacePaintVisual()
	{
		// female characters need this because they dont have beard so no player lifespan level stuff
		if (!IsMale())
		{
			string camoMaterial;
			if (m_FacePaintState == -1)
				camoMaterial = m_ModuleLifespan.GetFemaleBaseMaterial(GetType());
			else
				camoMaterial = m_ModuleLifespan.GetPaintPathFemale(m_FacePaintState, GetType());

			if (camoMaterial)
				SetFaceMaterial(camoMaterial);
		}
	}
};
