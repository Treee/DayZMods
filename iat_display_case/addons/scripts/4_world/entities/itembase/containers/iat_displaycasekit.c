class IAT_DisplayCaseKit_ColorBase extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		if ( g_Game.IsDedicatedServer() )
		{
			string displayCaseName = GetType();
			displayCaseName.Replace("IAT_DisplayCaseKit_", "IAT_DisplayCase_");

			IAT_DisplayCase_ColorBase displayCase;
			if (Class.CastTo(displayCase, g_Game.CreateObjectEx(displayCaseName, GetPosition(), ECE_SETUP|ECE_KEEPHEIGHT)))
			{
				displayCase.SetPosition( position );
				displayCase.SetOrientation( orientation );
			}
		}
	}
    override bool IsDeployable()
    {
        return true;
    };
	override bool IsBasebuildingKit()
	{
		return true;
	}
};

class IAT_DisplayCaseKit_Coaster : IAT_DisplayCaseKit_ColorBase{};
class IAT_DisplayCaseKit_Glass : IAT_DisplayCaseKit_ColorBase{};
class IAT_DisplayCaseKit_GlassAnimated : IAT_DisplayCaseKit_ColorBase{};
