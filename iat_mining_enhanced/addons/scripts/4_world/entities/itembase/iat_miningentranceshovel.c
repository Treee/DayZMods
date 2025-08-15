class IAT_MiningEntranceShovel extends Shovel
{
	override bool CanMakeGardenplot()
	{
		return false;
	}

	override bool CanMakeMiningEntrance()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionDigMineShaftEntrance);

		RemoveAction(ActionDigGardenPlot);
		RemoveAction(ActionDismantleGardenPlot);
		RemoveAction(ActionDismantlePart);

	}
};