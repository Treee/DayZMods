class IAT_DayZCodex_ColorBase extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionOpenDayZCodex);
	}

	bool CanBeOpened(PlayerIdentity identity)
	{
		return true;
	}
};


class IAT_DayZCodex_Journal extends IAT_DayZCodex_ColorBase{};
