modded class BuildingBase
{
	IAT_Codelock_Colorbase IAT_GetDoorCodelock(int doorIndex)
	{
		if (doorIndex < 0 || doorIndex >= GetDoorCount())
			return null;

		AdditionalDoorInfo doorInfo = GetDoorInfo(doorIndex);
		if (!doorInfo || !doorInfo.m_RelatedInventorySlotNames)
			return null;

		foreach (string slotName : doorInfo.m_RelatedInventorySlotNames)
		{
			IAT_Codelock_Colorbase codelock = IAT_Codelock_Colorbase.Cast(FindAttachmentBySlotName(slotName));
			if (codelock)
				return codelock;
		}
		return null;
	}

	override bool CanDoorBeOpened(notnull DoorManipulationParams params)
	{
		if (!super.CanDoorBeOpened(params))
			return false;

		IAT_Codelock_Colorbase codelock = IAT_GetDoorCodelock(params.m_DoorIndex);
		if (!codelock || !codelock.IAT_IsLocked())
			return true;

		PlayerBase player = PlayerBase.Cast(params.m_Caller);
		return player && codelock.HasAccess(player.GetIdentity());
	}
}
