modded class IAT_ActionCreateMineShaft
{
	override bool IAT_IsTargetSurfaceCorrect(ActionTarget target)
	{
		// if the existing code did not find a suitable surface
		if (!super.IAT_IsTargetSurfaceCorrect(target))
		{
			// check this new one now too
			if (IsTargetDiggable(target))
			{
				return true;
			}
		}
		// otherwise return false
		return false;
	}
};