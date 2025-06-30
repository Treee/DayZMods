modded class StaminaHandler
{
	protected ref Timer m_IAT_DepletionTimer;

	protected int m_IAT_LastMovementIndex;
	protected int m_IAT_LastStanceIndex;

	override protected void SetCooldown(float time, int modifier = -1)
	{
		// hijack the vanilla reset cooldown logic
		if ( m_StaminaDepleted || m_Stamina <= 0.0 )
		{
			if (!m_IAT_DepletionTimer)
			{
				m_IAT_DepletionTimer = new Timer;

				float regenTime = GameConstants.STAMINA_REGEN_COOLDOWN_EXHAUSTION * 1000;
				m_IAT_DepletionTimer.Run(regenTime, this, "ResetCooldown", new Param1<int>( modifier ));
				// short circuit like vanilla
				return;
			}
		}
		// modify the time needed to allow stamina to recover
		time = time * GetAdditionalWaitTime();
		// do existing code calls
		super.SetCooldown(time, modifier);
	}

	override protected void ResetCooldown(int modifier = -1)
	{
		super.ResetCooldown(modifier);
		if (m_IAT_DepletionTimer)
		{
			m_IAT_DepletionTimer.Stop();
			m_IAT_DepletionTimer = null;
		}
	}

	override protected void StaminaProcessor_Move(HumanMovementState pHumanMovementState)
	{
		super.StaminaProcessor_Move(pHumanMovementState);

		// if we are sprinting
		if (pHumanMovementState.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_SPRINT)
		{
			// if our stance has changed
			if (pHumanMovementState.m_iStanceIdx != m_IAT_LastStanceIndex)
			{
				// consume some stamina (stops players from infinite stamina stance swapping)
				m_StaminaDepletion += Math.RandomFloatInclusive(0.5, 2.7);
			}
		}

		// set last states after all said and done
		m_IAT_LastMovementIndex = pHumanMovementState.m_iMovement;
		m_IAT_LastStanceIndex = pHumanMovementState.m_iStanceIdx;
	}

	float GetAdditionalWaitTime()
	{
		// this essentially comes down to regen * loadmodifier * 5 and the number i have set with leave 30ish seconds for half loaded kits
		// const float STAMINA_REGEN_COOLDOWN_DEPLETION = 3; // in secs (how much time we will spend in cooldown before the stamina will starts with regeneration)
		// const float STAMINA_REGEN_COOLDOWN_EXHAUSTION = 20;
		// max stamina is 120 and when unencumbered, staminaCap is 120 which makes best case 1 and worse case large
		float normalizedStaminaCap = GameConstants.STAMINA_MAX / m_StaminaCap;
		// give some randomness between players
		float minStamina = normalizedStaminaCap * 1.1;
		float maxStamina = normalizedStaminaCap * 1.9;
		// 1.5x is smallest unit of regen
		float playerLoadModifier = Math.RandomFloatInclusive(minStamina, maxStamina);
		return playerLoadModifier;
	}
};
