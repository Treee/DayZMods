class IAT_FacePaintStick_ColorBase extends Inventory_Base
{
  	protected int m_camoIndex = 0;

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionPaintFace);
		AddAction(ActionPaintFaceTarget);
	}

	// server side call!!
	override void OnApply(PlayerBase player)
	{
		// Print("PaintStick::OnApply() " + m_camoIndex);
		player.SetFacePaint(m_camoIndex);
		if (GetDayZGame().GetIATFacePaintConfig())
		{
			float dmg = GetDayZGame().GetIATFacePaintConfig().GetPaintStickDamagerPerUse();
			AddHealth(-dmg);
		}
		else
			AddHealth(-2);
	}

	// helper function for radial menu context menu selection
	void SetCamoIndex(int currentIndex)
	{
		m_camoIndex = currentIndex;
	}
};

class IAT_FacePaintStick_Default extends IAT_FacePaintStick_ColorBase{};
