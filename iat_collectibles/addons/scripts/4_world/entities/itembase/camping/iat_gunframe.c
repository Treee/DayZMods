class IAT_GunFrame_ColorBase extends ItemBase
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

class IAT_GunFrame_Rifle_ColorBase extends IAT_GunFrame_ColorBase{};
class IAT_GunFrame_Rifle_Basic extends IAT_GunFrame_Rifle_ColorBase{};


class IAT_GunFrame_Pistol_ColorBase extends IAT_GunFrame_ColorBase{};
class IAT_GunFrame_Pistol_Basic extends IAT_GunFrame_Pistol_ColorBase{};