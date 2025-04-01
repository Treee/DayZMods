modded class WorldData
{
	array<vector> IAT_GetArtyFiringPos_Incendiary()
	{
		if (GetGame().GetWorldName() == "bitterroot")
		{
			return IAT_GetBitterrootPositions();
		}

		return IAT_GetChernoPositions();
	}

	array<vector> IAT_GetBitterrootPositions()
	{
		return {
			"1524.00 25 1812.00",
			"8424.00 25 1248.00",
			"7776.00 25 5580.00",
			"9672.00 25 8964.00",
			"3588.00 25 7860.00",
			"9720.00 25 9060.00",
		};
	}

	array<vector> IAT_GetChernoPositions()
	{
		return {
			"1000 200 1000",
			"4000 200 2000",
			"3000 200 1600",
		};
	}
};