class IAT_SmokeSignalHouse_Base extends House
{
    Particle m_ParticleEfx;

	void IAT_SmokeSignalHouse_Base()
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			m_ParticleEfx = ParticleManager.GetInstance().PlayOnObject(GetSmokeParticle(), this, GetPosition());

			IAT_SmokeSignalsConfig smokeSignals;
			if (Class.CastTo(smokeSignals, GetDayZGame().GetIATSmokeSignalsConfig()))
			{
				if (smokeSignals.IsSmokeSignalsEnabled())
				{
					if (m_ParticleEfx)
					{
						m_ParticleEfx.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(smokeSignals.GetSmokeSignalParticleScaleMin(), smokeSignals.GetSmokeSignalParticleScaleMax()));
					}
				}
			}
		}
	}
    override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsDedicatedServer() )
		{
			if ( m_ParticleEfx )
			{
				m_ParticleEfx.Stop();
			}
		}
	}

    int GetSmokeParticle()
    {
        return ParticleList.SMOKING_HELI_WRECK;
    }
};

class StaticObj_IAT_SmokeSignal_green extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.GRENADE_M18_GREEN_LOOP;
    }
};
class StaticObj_IAT_SmokeSignal_purple extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.GRENADE_M18_PURPLE_LOOP;
    }
};
class StaticObj_IAT_SmokeSignal_red extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.GRENADE_M18_RED_LOOP;
    }
};
class StaticObj_IAT_SmokeSignal_white extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.GRENADE_M18_WHITE_LOOP;
    }
};
class StaticObj_IAT_SmokeSignal_yellow extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.GRENADE_M18_YELLOW_LOOP;
    }
};
class StaticObj_IAT_SmokeSignal_black extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.GRENADE_M18_BLACK_LOOP;
    }
};
class StaticObj_IAT_SmokeSignal_crash extends IAT_SmokeSignalHouse_Base
{
	override int GetSmokeParticle()
    {
        return ParticleList.SMOKING_HELI_WRECK;
    }
};