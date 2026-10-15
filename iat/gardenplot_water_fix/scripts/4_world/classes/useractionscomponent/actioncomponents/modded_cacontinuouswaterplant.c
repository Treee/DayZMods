modded class CAContinuousWaterPlant
{
    override void Setup( ActionData action_data )
	{
		PlantBase target_PB;
		if (Class.CastTo(target_PB, action_data.m_Target.GetObject()))
		{
			m_SpentQuantity = 0;
			if ( !m_SpentUnits )
			{
				m_SpentUnits = new Param1<float>(0);
			}
			else
			{
				m_SpentUnits.param1 = 0;
			}
			if ( action_data.m_MainItem )
			{
				m_ItemQuantity = action_data.m_MainItem.GetQuantity();
			}
			if ( target_PB )
			{
				m_PlantThirstyness = 200;//target_PB.GetWaterMax();// - target_PB.GetWater();
			}

			m_TimeToComplete = (Math.Min(m_PlantThirstyness,m_ItemQuantity))/m_QuantityUsedPerSecond;
		}
	}
};