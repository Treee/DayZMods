class IAT_IncendiaryArea_Local extends IAT_IncendiaryArea_Dynamic
{
	protected ParticleSource 		m_IAT_ParticleExploded_Puff;
	protected ParticleSource 		m_IAT_ParticleExploded_Fire;
	protected ParticleSource 		m_IAT_ParticleExploded_Shell;
	protected ParticleSource 		m_IAT_ParticleExploded_SmokeStack;
	protected EffectSound 			m_IAT_FireLoopSound;

	const float TICK_RATE 	= 1;
	ref Timer 	m_Timer1 	= new Timer;
	float 		m_Lifetime 	= 360;
	// ----------------------------------------------
	// 				INITIAL SETUP
	// ----------------------------------------------

	void IAT_IncendiaryArea_Local()
	{
		m_EffectsPriority = -10;
	}
	void ~IAT_IncendiaryArea_Local()
	{
		#ifndef SERVER

		if (m_IAT_ParticleExploded_Puff)
		{
			m_IAT_ParticleExploded_Puff.Stop();
		}
		if (m_IAT_ParticleExploded_Shell)
		{
			m_IAT_ParticleExploded_Shell.Stop();
		}
		if (m_IAT_ParticleExploded_Fire)
		{
			m_IAT_ParticleExploded_Fire.Stop();
		}
		if (m_IAT_ParticleExploded_SmokeStack)
		{
			m_IAT_ParticleExploded_SmokeStack.Stop();
		}
		if (m_IAT_FireLoopSound)
		{
			m_IAT_FireLoopSound.SoundStop();
		}

		#endif
	}

	override void SetupZoneData(  EffectAreaParams params )
	{
		params.m_ParamPartId 		= ParticleList.IAT_GRENADE_INCENDIARY_AROUND;
		params.m_ParamInnerRings 	= 0;
		params.m_ParamPosHeight 	= 3;
		params.m_ParamNegHeight 	= 5;
		params.m_ParamRadius 		= 10;
		params.m_ParamOuterToggle 	= false;
		params.m_ParamTriggerType 	= "IAT_IncendiaryTrigger_Local";

		// params.m_ParamAroundPartId 	= 0;
		// params.m_ParamTinyPartId 	= 0;

		super.SetupZoneData( params );
	}

	override void EEInit()
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			SetupZoneData(new EffectAreaParams);
			m_Timer1.Run(TICK_RATE, this, "Tick", NULL, true);
		}

		// why not else here? to fully remove code on server? preference?
		#ifndef SERVER

		m_IAT_ParticleExploded_Puff = ParticleManager.GetInstance().PlayInWorld(ParticleList.IAT_GRENADE_INCENDIARY_PUFF, GetPosition());
		m_IAT_ParticleExploded_Shell = ParticleManager.GetInstance().PlayInWorld(ParticleList.IAT_GRENADE_INCENDIARY_SHELL, GetPosition());
		m_IAT_ParticleExploded_Fire = ParticleManager.GetInstance().PlayInWorld(ParticleList.IAT_GRENADE_INCENDIARY_FIRE, GetPosition());
		m_IAT_ParticleExploded_SmokeStack = ParticleManager.GetInstance().PlayInWorld(ParticleList.SMOKING_HELI_WRECK, GetPosition());

		if (!m_IAT_FireLoopSound)
		{
			PlaySoundSetLoop( m_IAT_FireLoopSound, GetFireLoopSoundSet(), 1.0, 1.0 );
		}
		#endif
	}

	override void SpawnItems()
	{
		// override base funcionality as we don't want any items spawned here
	}

	override float GetStartDecayLifetime()
	{
		return 20;
	}

	override float GetFinishDecayLifetime()
	{
		return 10;
	}

	override float GetRemainingTime()
	{
		return m_Lifetime;
	}

	override void Tick()
	{
		m_Lifetime -= TICK_RATE;
		if (m_Lifetime <= 0)
		{
			Delete();
		}
	}

	string GetFireLoopSoundSet()
	{
		return "IAT_Incendiary_SoundSet_LargeFire";
	}
};