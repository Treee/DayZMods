// IAT Enhanced Medical | Owner: ItsATreee | Layer: 4_World
//! Regional blood loss alongside vanilla source lifetime.
// Integration: server medical state and wound lifecycle.
// Documentation: iat_enhanced_medical/README.md

// Vanilla owns active bleeding sources, global blood loss, and treatment removal.
// These hooks add zone Blood damage, retained bullets, and dressed-bone history.
// The below-50% natural-expiry restriction is an IAT rule, not vanilla behavior.
modded class BleedingSource
{
	// Add regional Blood loss alongside vanilla global loss; do not replace its tick.
	override void OnUpdateServer(float deltatime, float blood_scale, bool no_blood_loss)
	{
		IAT_PluginMedical medical;
		string zone;
		if (Class.CastTo(medical, GetPlugin(IAT_PluginMedical)))
			zone = m_Player.GetBleedingManagerServer().IAT_GetDamageZoneFromSourceBit(m_Bit);
		if (!no_blood_loss && zone != "" && m_Player.GetMaxHealth(zone, "Blood") > 0)
		{
			float flow = m_FlowModifier;
			if (m_Type == eBleedingSourceType.CONTAMINATED)
				flow *= PlayerConstants.BLEEDING_SOURCE_BURN_MODIFIER;
			float loss = PlayerConstants.BLEEDING_SOURCE_BLOODLOSS_PER_SEC * blood_scale * deltatime * flow;
			m_Player.AddHealth(zone, "Blood", loss * medical.IAT_GetZoneBloodScale(m_Player, m_Player.GetMaxHealth(zone, "Blood")) * IAT_PluginMedical.IAT_ZONE_BLOODLOSS_MULTIPLIER);
		}
		// Keep vanilla global blood loss, particle state and source lifetime.
		super.OnUpdateServer(deltatime, blood_scale, no_blood_loss);
		// Vanilla marks deletion requested even when our manager rejects expiry.
		// Clear the flag so it retries later, including after recovery past 50%.
		if (medical && zone != "" && medical.IsSevere(m_Player, zone))
			m_DeleteRequested = false;
	}
}
