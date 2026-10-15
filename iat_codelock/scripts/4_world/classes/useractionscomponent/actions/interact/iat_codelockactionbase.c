class IAT_CodelockActionBase extends ActionInteractBase
{
	void IAT_CodelockActionBase()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;
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

	bool IAT_CanPlayerInteractWithCodelockedObject(IAT_Codelock_Colorbase iat_codelock, PlayerBase player)
	{
		// does the player NOT have access to the codelock?
		if (iat_codelock && !iat_codelock.HasAccess(player.GetIdentity()))
		{
			// if the codelock has no owner, do not allow interacting
			if (!iat_codelock.HasOwner())
			{
				return false;
			}
			// have they already tried to access it too many times?
			if (player.HasFailedPasscodeEntryTooManyTimes())
			{
				// if so, return false
				return false;
			}
			return true;
		}
		return false;
	}

	IAT_Codelock_Colorbase IAT_FindAttachedCodelock(EntityAI targetEntity)
	{
		IAT_Codelock_Colorbase iat_codelock;
		if (targetEntity.GetInventory())
		{
			TStringArray lockSlots = MiscGameplayFunctions.IAT_GetCodelockSlots();
			foreach (string slot : lockSlots)
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName(slot)))
				{
					return iat_codelock;
				}
			}
		}
		return null;
	}
};