modded class FireplaceBase
{
	override protected void CalcAndSetTotalEnergy()
	{
		if (GetGame() && GetGame().IsDedicatedServer())
		{
			foreach (FireConsumableType fireConsumableType : m_FireConsumableTypes)
			{
				fireConsumableType.m_Energy = fireConsumableType.GetEnergy() * 2;
			}

			super.CalcAndSetTotalEnergy();
		}
	}
};