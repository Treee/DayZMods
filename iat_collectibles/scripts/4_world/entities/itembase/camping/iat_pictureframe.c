class IAT_PictureFrame_ColorBase extends ItemBase
{
	override void SetActions()
  	{
    	super.SetActions();

    	AddAction(ActionTogglePlaceObject);
    	AddAction(ActionDeployObject);
  	}
	override bool IsHealthVisible()
	{
		return false;
	}
    override bool IgnoreOutOfReachCondition()
    {
        return true;
    }
};

class IAT_PictureFrame_Landscape_ColorBase extends IAT_PictureFrame_ColorBase{};
class IAT_PictureFrame_Portrait_ColorBase extends IAT_PictureFrame_ColorBase{};
class IAT_PictureFrame_Square_ColorBase extends IAT_PictureFrame_ColorBase{};


class IAT_PictureFrame_Landscape_SaltWoodCastle extends IAT_PictureFrame_Landscape_ColorBase{};

class IAT_PictureFrame_Portrait_AliensAttack extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_BGroup extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_BitterRose extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_MilitaryMen extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_SettlerWarning extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_TheCenturion extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_UniverseFighters extends IAT_PictureFrame_Portrait_ColorBase{};
class IAT_PictureFrame_Portrait_Unsinkable extends IAT_PictureFrame_Portrait_ColorBase{};

class IAT_PictureFrame_Square_RomeSunset extends IAT_PictureFrame_Square_ColorBase{};