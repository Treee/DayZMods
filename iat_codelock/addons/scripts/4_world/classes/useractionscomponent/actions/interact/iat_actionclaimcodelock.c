class IAT_ActionClaimCodelock extends ActionInteractBase
{
	void IAT_ActionClaimCodelock()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;

		m_Text = "Claim Codelock";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone();
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override bool HasProneException()
	{
		return true;
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_Codelock_Colorbase targetCodelock;
		// is the target a codelock?
		if (Class.CastTo(targetCodelock, target.GetObject()))
		{
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
			// does it have an inventory
			if (targetEntity.GetInventory())
			{
				IAT_Codelock_Colorbase iat_codelock;
				// is our codelock attached?
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					// if the lock has no owner
					if (!iat_codelock.HasOwner())
					{
						return true;
					}
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
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					iat_codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
					return; // short circuit
				}
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, action_data.m_Target.GetParent()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					iat_codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
					return; // short circuit
				}
			}
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " assigned code lock to " + action_data.m_Player.GetIdentity().GetPlainId();
	}
};