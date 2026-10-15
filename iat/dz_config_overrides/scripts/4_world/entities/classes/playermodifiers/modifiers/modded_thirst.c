modded class ThirstMdfr
{
	override void OnTick(PlayerBase player, float deltaT)
	{
		// if the player is less than 15 health
		if (player.GetHealth() < 15)
		{
			// short circuit
			return;
		}
		// more than 15 hp keep doing vanilla things
		super.OnTick(player, deltaT);
	}
};