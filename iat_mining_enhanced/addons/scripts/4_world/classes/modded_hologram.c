modded class Hologram
{
	protected const float LARGE_PROJECTION_DISTANCE_LIMIT = 10;

	override void SetProjectionPosition(vector position)
	{
		if (m_ProjectionTypename == "land_iat_miningsegment_entrance")
		{
			// // 8 is the default junction space so clamp it by that
			position[0] = position[0] / 8;
			// position[1] = position[1] / 8;
			position[2] = position[2] / 8;

			// // remove any decimals
			position = MiscGameplayFunctions.TruncateVec(position, 0);

			// rescale back to best position
			position[0] = position[0] * 8;
			// position[1] = position[1] * 8;
			position[2] = position[2] * 8;
		}
		super.SetProjectionPosition(position);
	}
};