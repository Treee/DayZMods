modded class TripwireTrap
{
	override void SnapOnObject(EntityAI victim)
	{
		super.SnapOnObject(victim);
		if (g_Game.IsDedicatedServer())
		{
			// if the triggering player is a PlayerBase
			PlayerBase playerVictim;
			if (Class.CastTo(playerVictim, victim))
			{
				float chance = Math.RandomFloat01();
				// if (chance > -1) // debug
				if (chance > 0.5) // 50% chance to fall down
				{
					playerVictim.BrokenLegForceProne();
					playerVictim.GiveShock(30);
				}
			}
		}
	}
};