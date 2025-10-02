class PPERequester_IAT_MiningTunnels extends PPERequester_GameplayBase
{
	protected float m_Value;
	protected bool m_DeltaSwap;
	override protected void OnStart(Param par = null)
	{
		super.OnStart(par);
		m_DeltaSwap = false;
		m_Value = GetDayZGame().GetCurrentEVValue();
	}
	override protected void OnUpdate(float delta)
	{
		if (!m_IsRunning)
			return;

		if(!m_DeltaSwap)
		{
			m_Value -= delta * 5;
			if(m_Value <= -10)
			{
				m_DeltaSwap = true;
			}
		}
		else
		{
			m_Value += delta * 0.65;
			if(m_Value >= 0)
			{
				SetRequesterUpdating(false);
				m_Value = 0;
				this.Stop();
			}
		}
		PPEffects.SetEVValuePP(m_Value);
	}
	override protected void OnStop(Param par = null)
	{
		PPEffects.SetEVValuePP(0);
		super.OnStop(par);
	}
}