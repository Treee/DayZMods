class StaticObj_Furniture_UniqueItem_Portal_Steampunk_chunkyhedgehog extends House
{
	protected const float MAX_TIMER = 27; // the length of the powerup soundset
	protected float m_RunTimer = 0;	// how long has this been running since turned on?
	// portal state determines what client should be seeing
	// 0 - off, 1 - power up, 2 - power down, 3 - max power
	protected int m_PortalState = 0;
	protected int m_LastPortalState = 0; // client side only debouncer

	protected EffectSound m_PowerUpSound;
	protected EffectSound m_PowerDownSound;
	protected EffectSound m_PowerFullSound;
	protected EffectSound m_ElectricitySound;

	static protected const string POWERUP_SOUND = "IAT_Mods_Ambience_PortalSounds_Steampunk_PowerUp_SoundSet";
	static protected const string POWERDOWN_SOUND = "IAT_Mods_Ambience_PortalSounds_Steampunk_PowerDown_SoundSet";
	static protected const string POWERFULL_SOUND = "IAT_Mods_Ambience_PortalSounds_Steampunk_PowerMax_SoundSet";
	static protected const string ELECTRICITY_SOUND = "IAT_Mods_Ambience_ElectricalSounds_SoundSet";

	// 3 different shocking particles
	protected Particle m_Tesla1;
	protected Particle m_Tesla2;
	protected Particle m_Tesla3;

	static protected int PARTICLE_EXPLOSION_YELLOW = ParticleList.FIREWORKS_EXPLOSION_YELLOW;
	static protected int PARTICLE_EXPLOSION_BLUE = ParticleList.FIREWORKS_EXPLOSION_BLUE;
	static protected int PARTICLE_EASTER_EGG = ParticleList.EASTER_EGG_ACTIVATE;

	static protected ref TIntArray PARTICLE_INDEXS = {1,2,3,4,5,6,7,8};

	void StaticObj_Furniture_UniqueItem_Portal_Steampunk_chunkyhedgehog()
	{
		RegisterNetSyncVariableInt("m_PortalState", 0, 8);
	}

	// ================================================= VANILLA CODE
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		// if the state has changed
		if (m_LastPortalState != m_PortalState)
		{
			// off, destroy sounds and particles
			if (m_PortalState == 0)
			{
				StopParticles();
				StopSounds();
				StopAnimations();
			}
			// powering up
			else if (m_PortalState == 1)
			{
				PlayElectricalEffects();
				PlayPowerUpSound();
				StartAnimations();
			}
			// powering down
			else if (m_PortalState == 2)
			{
				PlayPowerDownSound();
			}
			// max power
			else if (m_PortalState == 3)
			{
				DoMaxPowerThing();
			}
			// set the last state to the new state
			m_LastPortalState = m_PortalState;
		}
	};
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionTurnOnPortalSteampunk);
	}
	override void OnSwitchOn()
	{
		if (!GetCompEM().CanWork())
		{
			GetCompEM().SwitchOff();
		}
	}
	override void OnWorkStart()
	{
		// if its the server
		if (GetGame().IsDedicatedServer())
		{
			// start powering up
			m_PortalState = 1;
			SetSynchDirty();
		}
	}
	override void OnWorkStop()
	{
		// if its the server
		if (GetGame().IsDedicatedServer())
		{
			// energy manager is off, power down
			m_PortalState = 0;
			SetSynchDirty();
		}
	}
	override void OnWork( float consumed_energy )
	{
		if (GetGame().IsDedicatedServer())
		{
			// if the portal is powering up
			if (m_PortalState == 1)
			{
				// counts up to the max
				m_RunTimer += 1;

				// if we are at max power up time
				if (m_RunTimer >= MAX_TIMER)
				{
					m_PortalState = 3;
					SetSynchDirty();

					BeginShutDown();
				}
			}
			// powering down
			else if (m_PortalState == 2)
			{
				// counts down to 0
				m_RunTimer -= 1;

				// if we are at 0
				if (m_RunTimer <= 0)
				{
					m_PortalState = 0;
					SetSynchDirty();
				}
			}
			// keep the timer from escaping the sounds limits
			m_RunTimer = Math.Clamp(m_RunTimer, 0, MAX_TIMER);
		}
	}
	override bool IsHealthVisible()
	{
		return true;
	}
	override bool IsInventoryVisible()
	{
		return true;
	}
	override bool DisableVicinityIcon()
	{
		return false;
	}

	// ================================================= CUSTOM CODE
	bool CanSwitchOn()
	{
		// no glowplug attached
		if (!HasGlowPlugAttached())
		{
			return false;
		}
		// no energy manager
		if (!HasEnergyManager())
		{
			return false;
		}
		// cant switch on
		if (!GetCompEM().CanSwitchOn())
		{
			return false;
		}
		return true;
	}
	bool HasGlowPlugAttached()
	{
		if (FindAttachmentBySlotName("GlowPlug"))
		{
			return true;
		}
		return false;
	}

	void StopParticles()
	{
		if (m_Tesla1)
		{
			m_Tesla1.StopParticle();
		}
		if (m_Tesla2)
		{
			m_Tesla2.StopParticle();
		}
		if (m_Tesla3)
		{
			m_Tesla3.StopParticle();
		}
	}
	void StopSounds()
	{
		StopSoundSet(m_PowerUpSound);
		StopSoundSet(m_PowerDownSound);
		StopSoundSet(m_PowerFullSound);
		StopSoundSet(m_ElectricitySound);
	}

	void StartAnimations()
	{
		SetAnimationPhase("clock_rotate",50);
		SetAnimationPhase("platform_rotate",50);
	}
	void StopAnimations()
	{
		SetAnimationPhaseNow("clock_rotate",0);
		SetAnimationPhaseNow("platform_rotate",0);
	}

	void PlayElectricalEffects()
	{
		StopParticles();
		// if we are not on the server
		if (!GetGame().IsDedicatedServer())
		{
			PlayParticle1Loop();
			PlayParticle2Loop();
			PlayParticle3Loop();
    	}
	}
	void PlayParticle1Loop()
	{
		if (m_Tesla1)
		{
			m_Tesla1.StopParticle();
		}
		vector particlePosition = GetParticlePositionFromIndex(PARTICLE_INDEXS.GetRandomElement());
		m_Tesla1 = ParticleManager.GetInstance().PlayOnObject(GetRandomParticleType(), this, particlePosition);
		m_Tesla1.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(0.2, 0.5));
		m_Tesla1.ScaleParticleParam(EmitorParam.LIFETIME, Math.RandomFloatInclusive(1, 3));
		m_Tesla1.ScaleParticleParam(EmitorParam.VELOCITY, Math.RandomFloatInclusive(0.2, 0.5));
		if (GetCompEM().IsWorking())
		{
			float time = Math.RandomIntInclusive(1, 3) * 1000;
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayParticle1Loop, time, false);
		}
	}
	void PlayParticle2Loop()
	{
		if (m_Tesla2)
		{
			m_Tesla2.StopParticle();
		}
		vector particlePosition = GetParticlePositionFromIndex(PARTICLE_INDEXS.GetRandomElement());
		m_Tesla2 = ParticleManager.GetInstance().PlayOnObject(GetRandomParticleType(), this, particlePosition);
		m_Tesla2.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(0.2, 0.5));
		m_Tesla2.ScaleParticleParam(EmitorParam.LIFETIME, Math.RandomFloatInclusive(1, 3));
		m_Tesla2.ScaleParticleParam(EmitorParam.VELOCITY, Math.RandomFloatInclusive(0.2, 0.5));
		if (GetCompEM().IsWorking())
		{
			float time = Math.RandomIntInclusive(2, 4) * 1000;
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayParticle2Loop, time, false);
		}
	}
	void PlayParticle3Loop()
	{
		if (m_Tesla3)
		{
			m_Tesla3.StopParticle();
		}
		vector particlePosition = GetParticlePositionFromIndex(PARTICLE_INDEXS.GetRandomElement());
		m_Tesla3 = ParticleManager.GetInstance().PlayOnObject(GetRandomParticleType(), this, particlePosition);
		m_Tesla3.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(0.2, 0.5));
		m_Tesla3.ScaleParticleParam(EmitorParam.LIFETIME, Math.RandomFloatInclusive(1, 3));
		m_Tesla3.ScaleParticleParam(EmitorParam.VELOCITY, Math.RandomFloatInclusive(0.2, 0.5));
		if (GetCompEM().IsWorking())
		{
			float time = Math.RandomIntInclusive(2, 5) * 1000;
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayParticle3Loop, time, false);
		}
	}
	void PlayPowerUpSound()
	{
		if (!GetGame().IsDedicatedServer())
		{
			PlaySoundSet(m_PowerUpSound, POWERUP_SOUND, 1, 1);
		}
	}
	void PlayPowerDownSound()
	{
		if (!GetGame().IsDedicatedServer())
		{
			PlaySoundSet(m_PowerUpSound, POWERDOWN_SOUND, 1, 1);
		}
	}
	void DoMaxPowerThing()
	{
		// play big sound and particle
		if (!GetGame().IsDedicatedServer())
		{
			PlaySoundSet(m_PowerUpSound, POWERFULL_SOUND, 1, 1);
		}
	}
	void BeginShutDown()
	{
		// in 2 seconds begin to turn off the machine
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PreShutDown, 2000, false);
		// in 30 seconds turn off the machine
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ShutDown, 28000, false);
	}
	void PreShutDown()
	{
		// tell client to begin shutting down
		m_PortalState = 2;
		SetSynchDirty();
	}
	void ShutDown()
	{
		GetCompEM().SwitchOff();
	}
	int GetRandomParticleType()
	{
		TIntArray particleTypes = new TIntArray();
		particleTypes.Insert(ParticleList.FIREWORKS_EXPLOSION_YELLOW);
		particleTypes.Insert(ParticleList.FIREWORKS_EXPLOSION_BLUE);
		particleTypes.Insert(ParticleList.EASTER_EGG_ACTIVATE);
		return particleTypes.GetRandomElement();
	}
	vector GetParticlePositionFromIndex(int index)
	{
		string selection = string.Format("tesla%1", index);
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = GetMemoryPointPos( selection );
			return selection_pos;
		}
		return GetPosition();
	}
};