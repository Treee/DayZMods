// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Bridge vanilla regeneration rate and modifier scheduling to medical rules.
// Integration: server medical state and wound lifecycle.
// Documentation: iat_enhanced_medical/README.md

modded class BloodRegenMdfr
{
	// Vanilla overrides

	override bool ActivateCondition(PlayerBase player)
	{
		if (super.ActivateCondition(player))
			return true;
		IAT_PluginMedical medical;
		return Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) && medical.IAT_NeedsMedicalTick(player);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		// ModifierBase checks deactivation before OnTick. Keep one cleanup tick.
		if (!super.DeactivateCondition(player))
			return false;
		IAT_PluginMedical medical;
		return !Class.CastTo(medical, GetPlugin(IAT_PluginMedical)) || !medical.IAT_NeedsMedicalTick(player);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		// Calculate before vanilla changes Blood, preserving its unconscious bonus.
		float globalRate = IAT_GetBloodRegenRate(player);
		super.OnTick(player, deltaT);

		IAT_PluginMedical medical;
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
		{
			medical.IAT_RegenerateZones(player, deltaT, globalRate);
			medical.RemoveHealedBandages(player);
		}
	}

	// Getters

	protected float IAT_GetBloodRegenRate(PlayerBase player)
	{
		float waterModifier = GetRegenModifierWater(player.GetStatWater().Get());
		float energyModifier = GetRegenModifierEnergy(player.GetStatEnergy().Get());
		float rate = PlayerConstants.BLOOD_REGEN_RATE_PER_SEC * waterModifier * energyModifier;
		if (player.IsUnconscious() && player.GetHealth("", "Blood") <= PlayerConstants.SL_BLOOD_CRITICAL)
			rate *= PlayerConstants.UNCONSCIOUS_BLOOD_REGEN_MLTP;
		return rate;
	}

}
