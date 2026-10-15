class IAT_CarvedSymbol_Kit extends ItemBase
{
	protected int m_IAT_SymbolIndex = -1;

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
		AddAction(IAT_ActionSelectCarvedSymbolOption);
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		if (g_Game.IsDedicatedServer())
		{
			string selectedDoorName = GetSymbolClassNameFromSelection();
			if (selectedDoorName == "")
				return; // short circuit if we have a bad option for some reason

			IAT_CarvedSymbol_ColorBase newSymbols;
			if (Class.CastTo(newSymbols, g_Game.CreateObjectEx(selectedDoorName, GetPosition(), ECE_SETUP|ECE_KEEPHEIGHT)))
			{
				newSymbols.SetPosition( position );
				newSymbols.SetOrientation( orientation );
				// remove the object
				DeleteSafe();
			}
		}
	}

	override string GetDisplayName()
	{
		// get the display name from the super call
		string displayName = super.GetDisplayName();
		// if the current item has an inventory
		if (HasCarvedSymbolSelection())
		{
			displayName = string.Format("Symbol Kit - %1", MiscGameplayFunctions.IAT_GetCarvedSymbolName(m_IAT_SymbolIndex));
		}
		return displayName;
	}
	override bool IsBasebuildingKit()
	{
		return true;
	}
	override bool IsDeployable()
	{
		return true;
	}
	override bool DoPlacingHeightCheck()
	{
		return false;
	}
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	override string GetLoopDeploySoundset()
	{
		return "Shelter_Site_Build_Loop_SoundSet";
	}

	string GetSymbolClassNameFromSelection()
	{
		return string.Format("IAT_CarvedSymbol_%1", MiscGameplayFunctions.IAT_GetCarvedSymbolName(m_IAT_SymbolIndex));
	}

	void SetCarvedSymbolSelection(int symbolIndex)
	{
		m_IAT_SymbolIndex = symbolIndex;
	}

	bool HasCarvedSymbolSelection()
	{
		if (m_IAT_SymbolIndex == -1)
		{
			return false;
		}
		return true;
	}
};