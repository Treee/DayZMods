modded class FireplaceBase
{
	override protected void CalcAndSetTotalEnergy()
	{
		if (g_Game && g_Game.IsDedicatedServer())
		{
			foreach (FireConsumableType fireConsumableType : m_FireConsumableTypes)
			{
				fireConsumableType.m_Energy = fireConsumableType.GetEnergy() * 2;
			}

			super.CalcAndSetTotalEnergy();
		}
	}
};