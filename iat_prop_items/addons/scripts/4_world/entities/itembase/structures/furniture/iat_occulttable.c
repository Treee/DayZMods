class IAT_OccultTable_Colorbase extends BuildingSuper
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

class IAT_OccultTable_basic extends IAT_OccultTable_Colorbase{};
class IAT_OccultTable_essesentiendum extends IAT_OccultTable_Colorbase{};