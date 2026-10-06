class PPERequester_IAT_MapBorderTeleport extends PPERequester_GameplayBase
{
	// Public MEthod exposed for the player to invoke
	void SetMapBorderEffects(float normalizedDistance = 0.0)
	{
		// Flip the scale. 0 is full grey in SetTargetValueFloat and we want it to be fully saturated. 1 is where we want full grey
		normalizedDistance = 1 - normalizedDistance;
		// PrintFormat("ppe requester values: %1", normalizedDistance);
		SetTargetValueFloat(PostProcessEffectType.Glow, PPEGlow.PARAM_SATURATION, true, normalizedDistance, PPEGlow.L_22_BLOODLOSS, PPOperators.SET);
	}
};