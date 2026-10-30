class IAT_ActionInteractCodelock extends IAT_CodelockActionBase
{
	void IAT_ActionInteractCodelock()
	{
		m_Text = "Interact with Codelock";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(target);
		return IAT_CanPlayerInteractWithCodelockedObject(codelock, player);
	}

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(action_data.m_Target);
		if (codelock)
			codelock.OpenPasscodeEntryMenu();
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " interact with code lock ";
	}
};
