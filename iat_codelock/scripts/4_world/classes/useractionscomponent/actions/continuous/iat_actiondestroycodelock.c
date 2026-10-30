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

	override void OnActionInfoUpdate(PlayerBase player, ActionTarget target, ItemBase item)
	{
		m_Text = "Destroy Codelock";
		IAT_CodelockConfig config = GetDayZGame().GetIATCodelockConfig();
		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(target);
		if (config && config.CanShowCodelockHealth() && codelock)
			m_Text = string.Format("Destroy Codelock (HP: %1%)", codelock.GetSyncedCodelockHealth());
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return item && item.IAT_IsRaidItem() && MiscGameplayFunctions.IAT_GetTargetCodelock(target) != null;
	}

	override protected void OnFinishProgressServer(ActionData action_data)
	{
		IAT_Codelock_Colorbase codelock = MiscGameplayFunctions.IAT_GetTargetCodelock(action_data.m_Target);
		if (codelock)
			PerformDestroyAction(codelock, action_data.m_MainItem);
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
