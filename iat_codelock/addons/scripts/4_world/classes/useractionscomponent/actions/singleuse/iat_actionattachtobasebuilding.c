// essentially a copy/pass through of ActionAttach to change m_ConditionTarget to include tents in the first pass
class IAT_ActionAttachToBaseBuilding extends ActionAttach
{
	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINonRuined();
		m_ConditionTarget 	= new CCTCursor(UAMaxDistances.DEFAULT);
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask 		= DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Attach To Base Building";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			// does it have an inventory?
			if (targetEntity.GetInventory())
			{
				IAT_Codelock_Colorbase iat_codelock;
				// is our codelock in hand?
				if (Class.CastTo(iat_codelock, item))
				{
					InventoryLocation loc = new InventoryLocation;
					// if the inventory of what we are looking at can find a free location for our codelock
					if (targetEntity.GetInventory().FindFreeLocationFor(iat_codelock, FindInventoryLocationType.ATTACHMENT, loc))
					{
						// if we have a config
						if (GetDayZGame().GetIATCodelockConfig())
						{
							// if we can attach codelocks to tents
							if (GetDayZGame().GetIATCodelockConfig().CanAttachCodelockToBaseBuilding())
							{
								// if the target is a fence
								if (targetEntity.IsInherited(Fence))
								{
									Fence targetFence;
									// check if it has hinges
									if (Class.CastTo(targetFence, targetEntity))
									{
										return targetFence.HasHinges();
									}
								}
								if (targetEntity.IsInherited(ItemBase))
								{
									ItemBase targetItem;
									// check if we have a attachable target
									if (Class.CastTo(targetItem, targetEntity))
									{
										if (targetItem.CanAttachCodelockToObject())
										{
											return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer(action_data);

		IAT_Codelock_Colorbase iat_codelock;
		if (Class.CastTo(iat_codelock, action_data.m_MainItem))
		{
			iat_codelock.AssignLockTo(action_data.m_Player.GetIdentity().GetPlainId());
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		IAT_Codelock_Colorbase iat_codelock;
		// is our codelock in hand?
		if (Class.CastTo(iat_codelock, action_data.m_MainItem))
		{
			return " attached code lock to " + action_data.m_Target.GetObject().GetDisplayName();
		}
		return super.GetAdminLogMessage(action_data);
	}
};
