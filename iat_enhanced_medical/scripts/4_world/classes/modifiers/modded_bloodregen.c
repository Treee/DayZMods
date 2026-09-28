modded class BloodRegenMdfr
{
	// Diagnostic caches only; do not serialize. Log once per zone state change.
	protected int m_IAT_LogObservedZones;
	protected int m_IAT_LogBlockedZones;
	protected bool IAT_NeedsMedicalTick(PlayerBase player)
	{
		PluginIATMedical medical = PluginIATMedical.Get();
		return medical && (medical.NeedsZoneRegen(player) || medical.HasHealedBandage(player));
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return super.ActivateCondition(player) || IAT_NeedsMedicalTick(player);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		// ModifierBase checks deactivation before OnTick. Keep one cleanup tick.
		return super.DeactivateCondition(player) && !IAT_NeedsMedicalTick(player);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		// Sample the same pre-tick blood level as vanilla for its unconscious bonus.
		float globalBefore = player.GetHealth("", "Blood");
		float globalMaximum = player.GetMaxHealth("", "Blood");
		float rate = PlayerConstants.BLOOD_REGEN_RATE_PER_SEC * GetRegenModifierWater(player.GetStatWater().Get()) * GetRegenModifierEnergy(player.GetStatEnergy().Get());
		if (player.IsUnconscious() && globalBefore <= PlayerConstants.SL_BLOOD_CRITICAL)
			rate *= PlayerConstants.UNCONSCIOUS_BLOOD_REGEN_MLTP;
		// Retained bullets never block vanilla global blood regeneration.
		super.OnTick(player, deltaT);
		PluginIATMedical medical = PluginIATMedical.Get();
		if (!medical)
			return;
		foreach (string zone : PluginIATMedical.IAT_GetDamageZones())
		{
			bool blocked = medical.HasBulletInZone(player, zone);
			float before = player.GetHealth(zone, "Blood");
			float zoneMaximum = player.GetMaxHealth(zone, "Blood");
			// Equal percentage recovery per second: 100/5000 = 0.02.
			// Use the rate, not actual global gain, so zones can keep healing
			// after global blood has reached its cap.
			float zoneRate = 0;
			if (globalMaximum > 0 && zoneMaximum > 0)
				zoneRate = rate * zoneMaximum / globalMaximum;
			if (!blocked && before < zoneMaximum)
				player.AddHealth(zone, "Blood", Math.Min(zoneRate * deltaT, zoneMaximum - before));
			int zoneBit = PluginIATMedical.IAT_GetDamageZoneBit(zone);
			bool wasBlocked = (m_IAT_LogBlockedZones & zoneBit) != 0;
			if (IAT_MedicalLog.Enabled && ((m_IAT_LogObservedZones & zoneBit) == 0 || wasBlocked != blocked))
			{
				string eventName = "REGEN_ALLOWED";
				if (blocked)
					eventName = "REGEN_BLOCKED";
				IAT_MedicalLog.Event(player, eventName, string.Format("zone=%1 before=%2 after=%3 globalRate=%4 zoneRate=%5 globalBefore=%6 globalAfter=%7", zone, before, player.GetHealth(zone, "Blood"), rate, zoneRate, globalBefore, player.GetHealth("", "Blood")));
				m_IAT_LogObservedZones |= zoneBit;
				if (blocked)
					m_IAT_LogBlockedZones |= zoneBit;
				else
					m_IAT_LogBlockedZones &= ~zoneBit;
			}
		}
		medical.RemoveHealedBandages(player);
	}
}
