modded class Hologram
{
	protected const float LARGE_PROJECTION_DISTANCE_LIMIT = 10;

	override void SetProjectionPosition(vector position)
	{
		if (m_ProjectionTypename == "land_iat_miningsegment_entrance")
		{
			position[0] = Math.Round(position[0]);
			position[1] = Math.Round(position[1]);
			position[2] = Math.Round(position[2]);
			// vector clamped = position;

			// // 8 is the default junction space so clamp it by that
			// clamped[0] = clamped[0] / 8;
			// clamped[1] = clamped[1] / 8;
			// clamped[2] = clamped[2] / 8;

			// // remove any decimals
			// clamped = MiscGameplayFunctions.TruncateVec(clamped, 0);

			// // rescale back to best position
			// clamped[0] = clamped[0] * 8;
			// clamped[1] = clamped[1] * 8;
			// clamped[2] = clamped[2] * 8;

			// position = clamped;
		}
		super.SetProjectionPosition(position);
	}
};