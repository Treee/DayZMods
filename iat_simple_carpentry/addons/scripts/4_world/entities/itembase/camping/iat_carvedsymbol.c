class IAT_CarvedSymbol_ColorBase extends ItemBase
{
	protected int m_IAT_SelectedColor = 0;
	protected int m_IAT_SelectedColorClient = 0;

	void IAT_CarvedSymbol_ColorBase()
	{
		RegisterNetSyncVariableInt("m_IAT_SelectedColor", 0, 32);
	}

	override void DeferredInit()
	{
		super.DeferredInit();
		IAT_UpdateVisuals();
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		if (m_IAT_SelectedColorClient != m_IAT_SelectedColor)
		{
			IAT_UpdateVisuals();
			m_IAT_SelectedColorClient = m_IAT_SelectedColor;
		}
	};

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}

	//=============================================== CF MOD STORAGE
	#ifndef CF_MODSTORAGE
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// preserve order of call heiarchy
		super.OnStoreSave(ctx);

		// write my value
		ctx.Write(m_IAT_SelectedColor);
	}
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		// if existing db state is not loading correctly, fail out before our stuff (sanity check)
		if (!super.OnStoreLoad(ctx, version))
			return false;

		// read the value serially
		if(!ctx.Read(m_IAT_SelectedColor))
			return false;

		// Update the netsync
		SetSynchDirty();
		return true;
	}
	#endif
	#ifdef CF_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[IAT_Simple_Carpentry];
		if (!ctx) return;

		// write my value
		ctx.Write(m_IAT_SelectedColor);
	}
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage)) return false;

		auto ctx = storage[IAT_Simple_Carpentry];
		if (!ctx) return true;

		if(!ctx.Read(m_IAT_SelectedColor))
			return false;

		// sync the values
		SetSynchDirty();
		return true;
	}
	#endif

	void IAT_UpdateVisuals()
	{
		// client side visuals only
		if (!g_Game.IsDedicatedServer())
		{
			string filepath = MiscGameplayFunctions.IAT_GetCarvedSymbolFilePath(m_IAT_SelectedColor);
			SetObjectTexture(GetHiddenSelectionIndex("zbytek"), filepath);
		}
	}
	void SetSelectedColor(int newColor)
	{
		m_IAT_SelectedColor = newColor;
	}
	int GetSelectedColor()
	{
		return m_IAT_SelectedColor;
	}
};

class IAT_CarvedSymbol_A extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_B extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_C extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_D extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_E extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_F extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_G extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_H extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_I extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_J extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_K extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_L extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_M extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_N extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_O extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_P extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Q extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_R extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_S extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_T extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_U extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_V extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_W extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_X extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Y extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Z extends IAT_CarvedSymbol_ColorBase{};

class IAT_CarvedSymbol_0 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_1 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_2 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_3 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_4 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_5 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_6 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_7 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_8 extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_9 extends IAT_CarvedSymbol_ColorBase{};

class IAT_CarvedSymbol_Ampersand   extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_ArrowDown   extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_ArrowLeft   extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_ArrowRight  extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_ArrowUp     extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Asterisk    extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Dollar      extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Equals      extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Exclamation extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Hash        extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Parenthesis extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Percent     extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Plus        extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Question    extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Slash       extends IAT_CarvedSymbol_ColorBase{};
class IAT_CarvedSymbol_Times       extends IAT_CarvedSymbol_ColorBase{};