modded class ActionOpenFence
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if vanilla says we can open the fence
		if (super.ActionCondition(player, target, item))
		{
			Fence targetFence;
			// is the target a fence? (we know it is because super but we need the cast for later)
			if (Class.CastTo(targetFence, target.GetObject()))
			{
				if (targetFence.GetInventory())
				{
					IAT_Codelock_Colorbase iat_codelock;
					// is our codelock attached?
					if (Class.CastTo(iat_codelock, targetFence.GetInventory().FindAttachmentByName("Att_CombinationLock")))
					{
						// if the codelock is actually locked
						if (iat_codelock.IAT_IsLocked())
						{
							// if the player performing the action has access
							if (iat_codelock.HasAccess(player.GetIdentity()))
							{
								// return true
								return true;
							}
							// the player does not have access, deny entry
							return false;
						}
						// if the codelock is not locked
						else
						{
							return true;
						}
					}
				}
			}
			// vanilla says this passes so pass through
			return true;
		}
		// vanilla says no so we also say no
		return false;
	}
};