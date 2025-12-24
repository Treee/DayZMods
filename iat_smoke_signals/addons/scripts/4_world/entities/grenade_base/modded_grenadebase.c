modded class SmokeGrenadeBase
{
	override protected void PlaySmokeParticle()
	{
		super.PlaySmokeParticle();
		IAT_SmokeSignalsConfig smokeSignals;
		if (Class.CastTo(smokeSignals, GetDayZGame().GetIATSmokeSignalsConfig()))
		{
			if (smokeSignals.IsSmokeGrenadesEnabled())
			{
				if (m_ParticleSmoke)
				{
					m_ParticleSmoke.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(smokeSignals.GetSmokeGrenadeParticleScaleMin(), smokeSignals.GetSmokeGrenadeParticleScaleMax()));
				}
			}
		}
	}
};