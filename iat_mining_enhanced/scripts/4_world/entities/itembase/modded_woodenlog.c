modded class WoodenLog
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionFortifyJunction);
	}

	override bool CanFortifyMiningJunction()
	{
		return true;
	}
};