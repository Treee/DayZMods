class IAT_ActionClaimCodelock extends IAT_CodelockActionBase
{
	void IAT_ActionClaimCodelock()
	{
		m_Text = "Claim Codelock";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(target);
		if (!codelock || !codelock.GetHierarchyParent() || codelock.GetHierarchyRootPlayer())
			return false;

		// Fetch ownership before offering a claim on an attached lock.
		codelock.TryFetchOwnerId(player.GetIdentity());
		return !codelock.HasOwner();
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(action_data.m_Target);
		if (codelock && !codelock.HasOwner() && codelock.GetHierarchyParent() && !codelock.GetHierarchyRootPlayer())
			codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " assigned code lock to " + action_data.m_Player.GetIdentity().GetPlainId();
	}
};
