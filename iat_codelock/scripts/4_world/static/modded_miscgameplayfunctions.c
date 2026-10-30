modded class MiscGameplayFunctions
{
	static IAT_Codelock_Colorbase IAT_FindAttachedCodelock(EntityAI targetEntity)
	{
		if (!targetEntity || !targetEntity.GetInventory())
			return null;

		TStringArray slots = IAT_GetCodelockSlots();
		foreach (string slotName : slots)
		{
			IAT_Codelock_Colorbase codelock = IAT_Codelock_Colorbase.Cast(targetEntity.FindAttachmentBySlotName(slotName));
			if (codelock)
				return codelock;
		}
		return null;
	}

	static IAT_Codelock_Colorbase IAT_GetTargetCodelock(ActionTarget target)
	{
		if (!target)
			return null;

		IAT_Codelock_Colorbase codelock = IAT_Codelock_Colorbase.Cast(target.GetObject());
		if (codelock)
			return codelock;

		BuildingBase building = BuildingBase.Cast(target.GetObject());
		if (building && building.CanUseConstruction())
			return building.IAT_GetDoorCodelock(building.GetDoorIndex(target.GetComponentIndex()));

		codelock = IAT_FindAttachedCodelock(EntityAI.Cast(target.GetObject()));
		if (codelock)
			return codelock;

		building = BuildingBase.Cast(target.GetParent());
		if (building && building.CanUseConstruction())
			return building.IAT_GetDoorCodelock(building.GetDoorIndex(target.GetComponentIndex()));

		return IAT_FindAttachedCodelock(EntityAI.Cast(target.GetParent()));
	}

	static TStringArray IAT_GetCodelockSlots()
	{
		return {
			"Att_CodeLock",
            "Att_CodeLock1_Wood",
            "Att_CodeLock1_Metal",
            "Att_CodeLock2_Wood",
            "Att_CodeLock2_Metal",
            "Att_CodeLock3_Wood",
            "Att_CodeLock3_Metal",
            "Att_CodeLock4_Wood",
            "Att_CodeLock4_Metal",
            "Att_CodeLock5_Wood",
            "Att_CodeLock5_Metal",
            "Att_CodeLock6_Wood",
            "Att_CodeLock6_Metal",
            "Att_CodeLock7_Wood",
            "Att_CodeLock7_Metal",
            "Att_CodeLock8_Wood",
            "Att_CodeLock8_Metal",
            "Att_CodeLock9_Wood",
            "Att_CodeLock9_Metal",
            "Att_CodeLock10_Wood",
            "Att_CodeLock10_Metal",
			"Att_CombinationLock",
            "Att_CombinationLock1_Wood",
            "Att_CombinationLock1_Metal",
            "Att_CombinationLock2_Wood",
            "Att_CombinationLock2_Metal",
            "Att_CombinationLock3_Wood",
            "Att_CombinationLock3_Metal",
            "Att_CombinationLock4_Wood",
            "Att_CombinationLock4_Metal",
            "Att_CombinationLock5_Wood",
            "Att_CombinationLock5_Metal",
            "Att_CombinationLock6_Wood",
            "Att_CombinationLock6_Metal",
            "Att_CombinationLock7_Wood",
            "Att_CombinationLock7_Metal",
            "Att_CombinationLock8_Wood",
            "Att_CombinationLock8_Metal",
            "Att_CombinationLock9_Wood",
            "Att_CombinationLock9_Metal",
            "Att_CombinationLock10_Wood",
            "Att_CombinationLock10_Metal"
		};
	}
}
