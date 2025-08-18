modded class Environment
{
	override protected float GetEnvironmentTemperature()
	{
		if (IsInMiningTunnels())
		{
			return 1;
		}
		return super.GetEnvironmentTemperature();
	}

	bool IsInMiningTunnels()
	{
		vector playerPosition = m_Player.GetPosition();

		return playerPosition[1] > 2450;
	}
};;