modded class MissionServer
{
	override bool ShouldPlayerBeKilled(PlayerBase player)
	{
		// a soft surrendered target should never die
		if (player.IAT_IsSoftSurrendered())
		{
			return false;
		}
		return super.ShouldPlayerBeKilled(player);
	}

	override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
	{
		if (player)
		{
			// a soft surrendered player should never die
			if (player.IAT_IsSoftSurrendered())
			{
				return;
			}
		}
		super.OnClientRespawnEvent(identity, player);
	}
};