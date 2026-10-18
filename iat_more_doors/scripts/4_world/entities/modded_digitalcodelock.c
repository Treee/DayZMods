modded class DigitalCodeLock
{
	override bool HasValidParent()
	{
		if (IAT_ConstructionDoor_Colorbase.Cast(GetHierarchyRoot()))
		{
			return true;
		}
		if (IAT_LandDoor_Colorbase.Cast(GetHierarchyRoot()))
		{
			return true;
		}
		return super.HasValidParent();
	}
}