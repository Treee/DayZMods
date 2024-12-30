class IAT_FacePaintStick_ColorBase extends Inventory_Base
{
  	protected int m_camoIndex = 0;
	protected int m_camoCategoryIndex = -1;

	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionPaintFace);
		AddAction(IAT_ActionPaintFaceTarget);
	}

	// server side call!!
	override void OnApply(PlayerBase player)
	{
		// Print("PaintStick::OnApply() " + m_camoIndex);
		player.SetFacePaint(m_camoCategoryIndex, m_camoIndex);
		if (GetDayZGame().GetIATFacePaintConfig())
		{
			float dmg = GetDayZGame().GetIATFacePaintConfig().GetPaintStickDamagerPerUse();
			AddHealth(-dmg);
		}
		else
			AddHealth(-2);
	}

	// helper function for radial menu context menu selection
	void SetCamoIndex(int categoryIndex, int currentIndex)
	{
		m_camoCategoryIndex = categoryIndex;
		m_camoIndex = currentIndex;
	}
};

class IAT_FacePaintStick_Default extends IAT_FacePaintStick_ColorBase{};
