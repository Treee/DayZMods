class IAT_ActionAttachToBuilding extends ActionAttachToConstruction
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item))
			return false;

		if (!target || !BuildingBase.Cast(target.GetObject()) || !IAT_Codelock_Colorbase.Cast(item))
			return false;

		IAT_CodelockConfig config = GetDayZGame().GetIATCodelockConfig();
		return config && config.CanAttachCodelockToBaseBuilding();
	}

	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);

		IAT_Codelock_Colorbase codelock = IAT_Codelock_Colorbase.Cast(action_data.m_MainItem);
		if (codelock)
			codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
	}
}
