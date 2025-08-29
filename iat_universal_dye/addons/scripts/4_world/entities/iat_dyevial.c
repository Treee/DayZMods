class IAT_DyeVial_ColorBase extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_DyeObject);
	}
};
class IAT_DyeVial_Basic extends IAT_DyeVial_ColorBase {};
