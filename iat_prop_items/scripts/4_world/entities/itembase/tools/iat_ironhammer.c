class IAT_IronHammer_Colorbase extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionMineRock);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
	}
}
class IAT_IronHammer_Basic extends IAT_IronHammer_Colorbase{};
class IAT_IronHammer_jaygarrick extends IAT_IronHammer_Colorbase{};