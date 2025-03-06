class IAT_UniversalRepair_Epoxy extends ItemBase{};

class IAT_UniversalRepair_MultiTool extends ToolBase
{
	void IAT_UniversalRepair_MultiTool()
	{
		m_MineDisarmRate = 90;
	}

	override int GetKeyCompatibilityType()
	{
		return 1 << EBuildingLockType.LOCKPICK;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionUnrestrainTarget);
		AddAction(ActionLockDoors);
		AddAction(ActionUnlockDoors);
		AddAction(ActionDisarmMine);
		AddAction(ActionDisarmExplosive);
	}

	override bool IAT_IsMultiTool()
	{
		return true;
	}
};
