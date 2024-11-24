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
		// max delay for stamina regen is 15 seconds
		float adjustedLoad = Math.Max((GameConstants.STAMINA_MAX - (((m_PlayerLoad - GameConstants.STAMINA_WEIGHT_LIMIT_THRESHOLD)/GameConstants.STAMINA_KG_TO_GRAMS) * GameConstants.STAMINA_KG_TO_STAMINAPERCENT_PENALTY)),GameConstants.STAMINA_MIN_CAP);
		float x = GameConstants.STAMINA_MAX - m_StaminaCap;
		Print(string.Format("staminacap: %1 max: %2 delta: %3", m_StaminaCap, GameConstants.STAMINA_MAX, x));
		// if low weight, reduce timer
		// if high weight increase timer
		timer.Run(time, this, "ResetCooldown",  new Param1<int>( modifier ));
		//Print(m_TimerMap.Count());
	}
};
