class IAT_RaidHacksaw_Colorbase extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMineBush);
		AddAction(ActionSawPlanks);
		AddAction(ActionDismantlePart);
		AddAction(ActionSkinning);
		AddAction(ActionMineTreeBark);
	}
};

class IAT_RaidHacksaw_Admin extends IAT_RaidHacksaw_Colorbase{};
class IAT_RaidHacksaw_Basic extends IAT_RaidHacksaw_Colorbase{};
