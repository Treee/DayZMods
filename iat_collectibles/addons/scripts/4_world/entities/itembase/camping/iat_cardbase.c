class IAT_CardBase extends ItemBase
{
	override bool IsDeployable()
	{
		return true;
	}
	// override bool IsInventoryVisible()
	// {
	// 	return false;
	// }
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	void Flip()
	{
		vector currentOrientation = GetOrientation();
		SetOrientation(currentOrientation + "0 180 0");
		currentOrientation = GetOrientation();
	}
}