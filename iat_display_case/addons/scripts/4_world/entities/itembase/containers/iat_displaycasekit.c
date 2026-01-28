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
			DeleteSafe();
		}
	}
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	};
    override bool IsDeployable()
    {
        return true;
    };
};

class IAT_DisplayCaseKit_Coaster : IAT_DisplayCaseKit_ColorBase{};
class IAT_DisplayCaseKit_Glass : IAT_DisplayCaseKit_ColorBase{};
class IAT_DisplayCaseKit_GlassAnimated : IAT_DisplayCaseKit_ColorBase{};
