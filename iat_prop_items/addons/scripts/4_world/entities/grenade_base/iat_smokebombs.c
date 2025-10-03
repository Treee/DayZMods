class IAT_SmokeBomb_ColorBase extends Grenade_Base
{
	protected bool m_Exploded;
	protected Particle m_ParticleSmoke;
	protected EffectSound m_ExplosionSound;
	protected int m_ParticleIDToPlay = ParticleList.GRENADE_RDG2_BLACK_START;

	void IAT_SmokeBomb_ColorBase()
	{
		SetParticleExplosion(ParticleList.RGD5);
		SetGrenadeType(EGrenadeType.CHEMICAL);
		m_Pinned = false;
		SetPinnable(false);
		Arm();
	}

	void ~IAT_SmokeBomb_ColorBase()
	{
		if (m_ParticleSmoke)
			m_ParticleSmoke.Stop();
	}

	override protected void OnExplode()
	{
		m_Exploded = true;
	}
	override void EOnContact(IEntity other, Contact extra)
	{
		if (GetGame().IsServer())
		{
			if (!m_Exploded)
			{
				OnActivateFinished();
			}
		}
	}
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
	}
	override void OnDamageDestroyed(int oldLevel)
	{
		if (GetGame().IsDedicatedServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DeleteSafe, 5000);
		}
		#ifndef SERVER
		ClearFlags(EntityFlags.VISIBLE, false);
		m_ParticleSmoke = ParticleManager.GetInstance().PlayInWorld(m_ParticleIDToPlay, GetPosition());
		m_ParticleSmoke.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(4.5, 6.3));
		// m_ParticleSmoke.ScaleParticleParam(EmitorParam.LIFETIME, Math.RandomFloatInclusive(3, 5));
		m_ParticleSmoke.ScaleParticleParam(EmitorParam.VELOCITY, Math.RandomFloatInclusive(2.3, 3.7));
		PlaySoundSet( m_ExplosionSound, GetExplosionSoundSet(), 0, 0 );
		#endif
	}

	override protected void Activate()
	{
		//we don't want base functionality here
	}
	protected string GetExplosionSoundSet()
	{
		return "Grenade_detonation_SoundSet";
	}
};

class IAT_SmokeBomb_Red extends IAT_SmokeBomb_ColorBase
{
	void IAT_SmokeBomb_Red()
	{
		m_ParticleIDToPlay = ParticleList.GRENADE_M18_RED_START;
	}
};
class IAT_SmokeBomb_Green extends IAT_SmokeBomb_ColorBase
{
	void IAT_SmokeBomb_Green()
	{
		m_ParticleIDToPlay = ParticleList.GRENADE_M18_GREEN_START;
	}
};
class IAT_SmokeBomb_Yellow extends IAT_SmokeBomb_ColorBase
{
	void IAT_SmokeBomb_Yellow()
	{
		m_ParticleIDToPlay = ParticleList.GRENADE_M18_YELLOW_START;
	}
};
class IAT_SmokeBomb_Purple extends IAT_SmokeBomb_ColorBase
{
	void IAT_SmokeBomb_Purple()
	{
		m_ParticleIDToPlay = ParticleList.GRENADE_M18_PURPLE_START;
	}
};
class IAT_SmokeBomb_White extends IAT_SmokeBomb_ColorBase
{
	void IAT_SmokeBomb_White()
	{
		m_ParticleIDToPlay = ParticleList.GRENADE_M18_WHITE_START;
	}
};
class IAT_SmokeBomb_Black extends IAT_SmokeBomb_ColorBase
{
	void IAT_SmokeBomb_Black()
	{
		m_ParticleIDToPlay = ParticleList.GRENADE_M18_BLACK_START;
	}
};