modded class StaminaHandler
{
	override protected void SetCooldown(float time, int modifier = -1)
	{
		// Vanilla
		if ( m_StaminaDepleted || m_Stamina <= 0.0 )
		{
			ResetCooldown(modifier);
			return;
		}

		m_IsInCooldown = true;

		Timer timer;
		if (m_TimerMap.Find(modifier, timer) && timer.IsRunning())
		{
			timer.Stop();
		}
		else
		{
			timer = new ref Timer;
			m_TimerMap.Set(modifier,timer);
		}
		///////
		time = time * GetAdditionalWaitTime();

		timer.Run(time, this, "ResetCooldown",  new Param1<int>( modifier ));
		//Print(m_TimerMap.Count());
	}

	float GetAdditionalWaitTime()
	{
		// this essentially comes down to regen * loadmodifier * 5 and the number i have set with leave 30ish seconds for half loaded kits
		// const float STAMINA_REGEN_COOLDOWN_DEPLETION = 3; // in secs (how much time we will spend in cooldown before the stamina will starts with regeneration)
		// const float STAMINA_REGEN_COOLDOWN_EXHAUSTION = 20;
		// max stamina is 120 and when unencumbered, staminaCap is 120 which makes best case 1 and worse case large
		float playerLoadModifier = GameConstants.STAMINA_MAX / m_StaminaCap;
		// 1.5x is smallest unit of regen
		playerLoadModifier *= 2.5;
		return playerLoadModifier;
	}
};
