modded class PlayerBase
{
	protected int m_CodelockFailedPasscodeEntryAttempts;
	protected int m_CodelockFailedPasscodeEntryAttemptsCooldown;
	protected float m_TimeSinceLastFailedPasscodeEntry;

	// ================================================================================== OVERRIDES
	void PlayerBase()
	{
		RegisterNetSyncVariableInt("m_CodelockFailedPasscodeEntryAttempts", 0, 100);
	}
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		// owner manage menu
		AddAction(IAT_ActionManageCodelock, InputActionMap);
		// player interact menu
		AddAction(IAT_ActionInteractCodelock, InputActionMap);
		// player claim codelock
		AddAction(IAT_ActionClaimCodelock, InputActionMap);
	}

	// Sync failed passcode entry attempts for action checking
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG)
		{
			OnCheckConfig(ctx);
		}
	}

	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		// increment our counter ONLY if we have a cooldown set
		if (m_CodelockFailedPasscodeEntryAttemptsCooldown > 0)
			m_TimeSinceLastFailedPasscodeEntry += deltaTime;

		// if the counter surpasses the cooldown time (in cases where 0 is in play it will never surpass)
		if (m_TimeSinceLastFailedPasscodeEntry > m_CodelockFailedPasscodeEntryAttemptsCooldown)
		{
			// reset the failed passcode entry attempts
			ResetPasscodeEntryAttempts();
		}
	}

	// ================================================================================== CUSTOM CODE
	void OnCheckConfig(ParamsReadContext ctx)
	{
		Param1<IAT_CodelockConfig> configParams;
		// read the params, short circuit if there is an error
		if (!ctx.Read(configParams))
		{
			Print("IAT_Codelock::PlayerBase::OnCheckConfig - Failed to read IAT_CodelockConfig params");
			return;
		}
		// set client local copy of the config
		GetDayZGame().SetIATCodelockConfig(configParams.param1);
		// set cooldown variable so we are not constantly pulling config in the update loop
		if (GetDayZGame().GetIATCodelockConfig())
		{
			m_CodelockFailedPasscodeEntryAttemptsCooldown = GetDayZGame().GetIATCodelockConfig().GetMaxPasscodeEntriesCooldown();
		}
	}

	void ResetPasscodeEntryAttemptsCooldown()
	{
		// if we have a config
		if (GetDayZGame().GetIATCodelockConfig())
		{
			// if we have a cooldown set
			if ( GetDayZGame().GetIATCodelockConfig().GetMaxPasscodeEntriesCooldown() > 0)
			{
				// reset the cooldown timer so it can count up to the next reset
				m_TimeSinceLastFailedPasscodeEntry = 0;
			}
			// if we have hit our max passcode entry attempts
			if (m_CodelockFailedPasscodeEntryAttempts > GetDayZGame().GetIATCodelockConfig().GetMaxPasscodeEntriesPerInterval())
			{
				// sync the failed passcode entry attempts
				SetSynchDirty();
			}
		}
	}
	void ResetPasscodeEntryAttempts()
	{
		// if we have a config
		if (GetDayZGame().GetIATCodelockConfig())
		{
			// if we can clear all passcode entries on the interval
			if (GetDayZGame().GetIATCodelockConfig().CanClearAllPasscodeEntriesOnInterval())
			{
				// reset ALL failed passcode entry attempts to 0
				m_CodelockFailedPasscodeEntryAttempts = 0;
			}
			else
			{
				// remove ONE failed passcode entry attempt
				m_CodelockFailedPasscodeEntryAttempts--;
			}
			// sync the failed passcode entry attempts
			SetSynchDirty();
		}
		// reset the cooldown timer
		m_TimeSinceLastFailedPasscodeEntry = 0;
	}
	bool HasFailedPasscodeEntryTooManyTimes()
	{
		if (GetDayZGame().GetIATCodelockConfig())
		{
			// if we have a config
			if (m_CodelockFailedPasscodeEntryAttempts >= GetDayZGame().GetIATCodelockConfig().GetMaxPasscodeEntriesPerInterval())
			{
				return true;
			}
		}
		return false;
	}
	int GetCodelockFailedPasscodeEntryAttempts()
	{
		return m_CodelockFailedPasscodeEntryAttempts;
	}
	void AddFailedCodelockEntryAttempt(int delta)
	{
		m_CodelockFailedPasscodeEntryAttempts += delta;
	}
};