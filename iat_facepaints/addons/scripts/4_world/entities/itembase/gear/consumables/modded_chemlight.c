modded class Chemlight_ColorBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionEatGlowStick);
	}

	override bool CanBeConsumed(ConsumeConditionData data = null)
	{
		return GetQuantity() > 24;
	}
};