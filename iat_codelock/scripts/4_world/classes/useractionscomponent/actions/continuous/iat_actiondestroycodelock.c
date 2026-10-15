class IAT_ActionDestroyCodelockCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(GetDefaultTime());
	}

	float GetDefaultTime()
	{
		IAT_CodelockRaidTool raidToolProperties;
		if (Class.CastTo(raidToolProperties, m_ActionData.m_MainItem.GetRaidToolProperties()))
		{
			return raidToolProperties.GetTimePerDamage();
		}
		return 1000000;
	}
};

class IAT_ActionDestroyCodelock: ActionContinuousBase
{
	void IAT_ActionDestroyCodelock()
	{
		m_CallbackClass = IAT_ActionDestroyCodelockCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "Destroy Codelock";
		m_LockTargetOnUse = false;
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if we have a config
		if (GetDayZGame().GetIATCodelockConfig())
		{
			if (GetDayZGame().GetIATCodelockConfig().CanShowCodelockHealth())
			{
				IAT_Codelock_Colorbase iat_codelock;
				// check the target objects inventory to see if there is a codelock present
				EntityAI targetEntity;
				if (Class.CastTo(targetEntity, target.GetObject()))
				{
					if (targetEntity.GetInventory())
					{
						if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
						{
							m_Text = string.Format("Destroy Codelock (HP: %1%)", iat_codelock.GetSyncedCodelockHealth());
							return; // short circuit
						}
					}
				}
				// check the target objects parent to see if it has a codelock
				if (Class.CastTo(targetEntity, target.GetParent()))
				{
					if (targetEntity.GetInventory())
					{
						if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
						{
							m_Text = string.Format("Destroy Codelock (HP: %1%)", iat_codelock.GetSyncedCodelockHealth());
							return; // short circuit
						}
					}
				}
			}
		}
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!item.IAT_IsRaidItem())
			return false;

		// this action path goes from most specific to most generic (reverse funnel)
		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					return true;
				}
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, target.GetParent()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, action_data.m_Target.GetObject()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					PerformDestroyAction(iat_codelock, action_data.m_MainItem);
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
					PerformDestroyAction(iat_codelock, action_data.m_MainItem);
					return; // short circuit
				}
			}
		}
	}

	void PerformDestroyAction(IAT_Codelock_Colorbase iat_codelock, ItemBase itemInHands)
	{
		if (iat_codelock)
		{
			IAT_CodelockRaidTool raidToolProperties;
			if (Class.CastTo(raidToolProperties, itemInHands.GetRaidToolProperties()))
			{
				// do damage based on tool properties
				iat_codelock.PerformRaidDamage(raidToolProperties.GetCodelockDamagePerUse(), raidToolProperties.GetDeleteLockOnRaid());
				itemInHands.AddHealth(-raidToolProperties.GetDamagePerUse());
			}
			// if we have a config
			if (GetDayZGame().GetIATCodelockConfig())
			{
				// if we can show codelock health
				if (GetDayZGame().GetIATCodelockConfig().CanShowCodelockHealth())
				{
					iat_codelock.ServerUpdateSyncedCodelockHealth();
					iat_codelock.SetSynchDirty();
				}
			}
		}
	}
};