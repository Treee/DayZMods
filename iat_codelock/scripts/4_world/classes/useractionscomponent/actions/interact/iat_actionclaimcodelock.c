class IAT_ActionClaimCodelock extends IAT_CodelockActionBase
{
	void IAT_ActionClaimCodelock()
	{
		m_Text = "Claim Codelock";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_Codelock_Colorbase targetCodelock;
		// is the target a codelock?
		if (Class.CastTo(targetCodelock, target.GetObject()))
		{
			// if the codelock is not attached to anything or is being held by the player
			if (!targetCodelock.GetParent() || targetCodelock.GetHierarchyRootPlayer())
			{
				return false; // no claim action
			}
			// if the lock has no owner
			if (!targetCodelock.HasOwner())
			{
				return true;
			}
		}
		EntityAI targetEntity;
		// is the target something that has the codelock attached but not a visible proxy
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			IAT_Codelock_Colorbase iat_codelock;
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelock(targetEntity)))
			{
				// if the lock has no owner
				if (!iat_codelock.HasOwner())
				{
					return true;
				}
			}
		}
		return false;
	};

	override void OnEndServer( ActionData action_data )
	{
		super.OnEndServer(action_data);

		// find the lock and assign it to the player interacting with the lock
		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, action_data.m_Target.GetObject()))
		{
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelock(targetEntity)))
			{
				iat_codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
				return; // short circuit
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, action_data.m_Target.GetParent()))
		{
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelock(targetEntity)))
			{
				iat_codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
				return; // short circuit
			}
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " assigned code lock to " + action_data.m_Player.GetIdentity().GetPlainId();
	}
};