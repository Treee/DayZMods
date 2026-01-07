modded class Spraycan_ColorBase
{
	protected int m_IAT_TempColorIndex = -1;
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionSelectPaintColor);
		AddAction(IAT_ActionPaintCarvedSymbol);
	}

	override string GetDisplayName()
	{
		// get the display name from the super call
		string displayName = super.GetDisplayName();
		// if the current item has an inventory
		if (IAT_HasCarvedSymbolColorSelection())
		{
			displayName = string.Format("Color - %1", MiscGameplayFunctions.IAT_GetCarvedSymbolColorName(m_IAT_TempColorIndex));
		}
		return displayName;
	}

	bool IAT_HasCarvedSymbolColorSelection()
	{
		if (m_IAT_TempColorIndex == -1)
		{
			return false;
		}
		return true;
	}

	void IAT_SetCarvedLetterColorIndex(int newIndex)
	{
		m_IAT_TempColorIndex = newIndex;
	}
	int IAT_GetCarvedLetterColorIndex()
	{
		return m_IAT_TempColorIndex;
	}
};