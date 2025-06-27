modded class ActionDetach
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (super.ActionCondition(player, target, item))
		{
			IAT_Codelock_Colorbase targetCodelock;
			// is the target a codelock?
			if (Class.CastTo(targetCodelock, target.GetObject()))
			{
				// has access
				if (targetCodelock.HasAccess(player.GetIdentity()))
				{
					// ignore locked codelocks
					if (targetCodelock.IAT_IsLocked())
						return false;
					// if the player performing the action has access
					if (targetCodelock.IsOwner(player.GetIdentity().GetPlainId()))
					{
						// return true
						return true;
					}
				}
				// no access and not owner
				return false;
			}
			// pass through vanilla if our target is not the codelock
			return true;
		}
		// vanilla fails so pass through
		return false;
	}
	override string GetAdminLogMessage(ActionData action_data)
	{
		IAT_Codelock_Colorbase iat_codelock;
		// is our codelock in hand?
		if (Class.CastTo(iat_codelock, action_data.m_Target.GetObject()))
		{
			return " detached code lock owned by " + iat_codelock.GetOwnerId();
		}
		return super.GetAdminLogMessage(action_data);
	}
};
