modded class PlayerBase
{
	protected int m_IncendiaryAreaCount;

	void IAT_IncreaseIncendiaryAreaCount()
	{
		if (m_IncendiaryAreaCount == 0)
			OnIncendiaryAreaEnterServer();
		m_IncendiaryAreaCount++;
	}

	void IAT_DecreaseIncendiaryAreaCount()
	{
		m_IncendiaryAreaCount--;
		if (m_IncendiaryAreaCount <= 0)
		{
			m_IncendiaryAreaCount = 0;
			OnIncendiaryAreaExitServer();
		}
	}

	protected void OnIncendiaryAreaEnterServer()
	{
		GetModifiersManager().ActivateModifier( eModifiers.MDF_BURNING );
		//Print("Contaminated ENTERED <------------------------------------------------------------- FINAL");
	}

	protected void OnIncendiaryAreaExitServer()
	{
		GetModifiersManager().DeactivateModifier( eModifiers.MDF_BURNING );
		//Print("Contaminated LEFT <------------------------------------------------------------- FINAL");
	}
};