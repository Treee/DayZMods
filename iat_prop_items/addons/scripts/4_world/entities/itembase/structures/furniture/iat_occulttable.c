class IAT_OccultTable_ColorBase extends BuildingSuper
{
	override bool DisableVicinityIcon()
	{
		return false;
	}
	override bool IsHealthVisible()
    {
        return true;
    }
    override bool CanPutIntoHands (EntityAI parent)
    {
        return false;
    }
	override bool IsInventoryVisible()
	{
		return true;
	}
};

class IAT_OccultTable_basic extends IAT_OccultTable_ColorBase{};
class IAT_OccultTable_essesentiendum extends IAT_OccultTable_ColorBase{};