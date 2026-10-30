class IAT_ActionManageCodelock extends IAT_CodelockActionBase
{
	void IAT_ActionManageCodelock()
	{
		m_Text = "Manage Codelock";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(target);
		return codelock && codelock.HasAccess(player.GetIdentity()) && codelock.IsOwner(player.GetIdentity().GetPlainId());
	}

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(action_data.m_Target);
		if (codelock)
			codelock.OpenCodelockManagerMenu();
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " managing code lock " + action_data.m_Target.GetObject().GetDisplayName();
	}
};
