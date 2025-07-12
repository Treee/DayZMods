class IAT_MoreDoor_Kit extends ItemBase
{
	protected int m_IAT_SelectedDoorOption = -1;

	protected ref TStringArray m_KitOptionDisplayNames;
	protected ref TStringArray m_KitOptionClassNames;

	// ===================================================================== VANILLA OVERIDE
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		if ( GetGame().IsServer() )
		{
			string selectedDoorName = GetDoorClassNameFromSelection();
			if (selectedDoorName == "")
				return; // short circuit if we have a bad option for some reason

			IAT_ConstructionDoor_Colorbase newDoor;
			if (Class.CastTo(newDoor, GetGame().CreateObjectEx(selectedDoorName, GetPosition(), ECE_PLACE_ON_SURFACE)))
			{
				newDoor.SetPosition( position );
				newDoor.SetOrientation( orientation );
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
		if (HasDoorKitSelection())
		{
			displayName = string.Format("Door Kit - %1", GetDoorDisplayNameFromIndex(m_IAT_SelectedDoorOption));
		}
		return displayName;
	}
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
		AddAction(IAT_ActionSelectDoorOption);
	}
	override void InitItemVariables()
	{
		super.InitItemVariables();
		LoadDoorOptionDisplayNames();
		LoadDoorOptionClassNames();
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
		return true;
	}
	override float HeightCheckOverride()
	{
		return 2.54;
	}
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	override string GetLoopDeploySoundset()
	{
		return "Shelter_Site_Build_Loop_SoundSet";
	}
	// ===================================================================== CUSTOM CODE
	void LoadDoorOptionDisplayNames()
	{
		if (ConfigIsExisting("iat_KitOptionDisplayNames"))
        {
			m_KitOptionDisplayNames = new TStringArray;
            ConfigGetTextArray("iat_KitOptionDisplayNames", m_KitOptionDisplayNames);
        }
	}
	void LoadDoorOptionClassNames()
	{
		if (ConfigIsExisting("iat_KitOptionClassNames"))
        {
			m_KitOptionClassNames = new TStringArray;
            ConfigGetTextArray("iat_KitOptionClassNames", m_KitOptionClassNames);
        }
	}
	TStringArray GetDoorOptions()
	{
		return m_KitOptionClassNames;
	}
	string GetDoorClassNameFromSelection()
	{
		if (m_IAT_SelectedDoorOption > -1)
		{
			return GetDoorOptions().Get(m_IAT_SelectedDoorOption);
		}
		return "";
	}
	TStringArray GetDoorDisplayOptions()
	{
		return m_KitOptionDisplayNames;
	}
	string GetDoorDisplayNameFromIndex(int index)
	{
		if (index > -1)
		{
			TStringArray displayOptions = GetDoorDisplayOptions();
			if (displayOptions)
			{
				return displayOptions.Get(index);
			}
			return "";
		}
		return "";
	}
	void SetSelectedDoorOption(int index)
	{
		m_IAT_SelectedDoorOption = index;
	}
	int GetSelectedDoorOption()
	{
		return m_IAT_SelectedDoorOption;
	}
	bool HasDoorKitSelection()
	{
		return m_IAT_SelectedDoorOption > -1;
	}
};