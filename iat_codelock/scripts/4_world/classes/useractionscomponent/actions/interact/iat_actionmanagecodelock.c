class IAT_ActionManageCodelock extends IAT_CodelockActionBase
{
	void IAT_ActionManageCodelock()
	{
		m_Text = "Manage Codelock";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_Codelock_Colorbase targetCodelock;
		// is the target a codelock?
		if (Class.CastTo(targetCodelock, target.GetObject()))
		{
			if (targetCodelock.HasAccess(player.GetIdentity()))
			{
				// if the player performing the action has access
				if (targetCodelock.IsOwner(player.GetIdentity().GetPlainId()))
				{
					// return true
					return true;
				}
			}
		}
		EntityAI targetEntity;
		// is the target something that has the codelock attached but not a visible proxy
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			IAT_Codelock_Colorbase iat_codelock;
			if (Class.CastTo(iat_codelock, IAT_FindAttachedCodelockByAttachmentName(targetEntity)))
			{
				// if the player performing the action has access
				if (iat_codelock.HasAccess(player.GetIdentity()))
				{
					// if the player performing the action has access
					if (iat_codelock.IsOwner(player.GetIdentity().GetPlainId()))
					{
						// return true
						return true;
					}
				}
			}
		}
		return false;
	};

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);
        // sanity check player
		PlayerBase player;
        if (Class.CastTo(player, action_data.m_Player))
        {
			// sanity check direct codelock target
        	IAT_Codelock_Colorbase iat_codelock;
			if (!Class.CastTo(iat_codelock, action_data.m_Target.GetObject()))
			{
				// sanity check indirect iat_codelock target
				EntityAI targetEntity;
				if (Class.CastTo(targetEntity, action_data.m_Target.GetObject()))
				{
					if (targetEntity.GetInventory())
					{
						if (!Class.CastTo(iat_codelock, IAT_FindAttachedCodelockByAttachmentName(targetEntity)))
						{
							// if we still don't have a iat_codelock, return
							return;
						}
					}
				}
			}
			if (iat_codelock)
			{
				// do client side dance
				iat_codelock.OpenCodelockManagerMenu();
			}
        }
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " managing code lock " + action_data.m_Target.GetObject().GetDisplayName();
	}
};