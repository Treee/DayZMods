modded class ContaminatedTrigger
{
	static const float EXPOSURE_DAMAGE_TICK_TIME = 10;

	protected ParticleSource m_VaporParticle;

	override void EEDelete( EntityAI parent )
	{
		StopParticle();
		super.EEDelete(parent);
	}

	override void OnEnterServerEvent( TriggerInsider insider )
	{
		super.OnEnterServerEvent( insider );
		if ( insider )
		{
			PlayerBase playerInsider;
			if (Class.CastTo(playerInsider, insider.GetObject()) )
			{
        		playerInsider.SetInEffectAreaTypeFlag(IAT_EffectAreaType.CORROSIVE_BIOGAS);
			}
		}
	}
	override void OnEnterClientEvent( TriggerInsider insider )
	{
		super.OnEnterClientEvent( insider );
    	if ( insider )
		{
			PlayerBase playerInsider;
			if (Class.CastTo(playerInsider, insider.GetObject()) )
			{
        		playerInsider.SetInEffectAreaTypeFlag(IAT_EffectAreaType.CORROSIVE_BIOGAS);
				PlayParticleOnPlayer(playerInsider);
			}
		}
	}

	override void OnLeaveServerEvent( TriggerInsider insider )
	{
		super.OnLeaveServerEvent( insider );
		if ( insider )
		{
			PlayerBase playerInsider;
			if (Class.CastTo(playerInsider, insider.GetObject()) )
			{
        		playerInsider.UnsetInEffectAreaTypeFlag(IAT_EffectAreaType.CORROSIVE_BIOGAS);
			}
		}
	}
	override void OnLeaveClientEvent( TriggerInsider insider )
	{
		super.OnLeaveClientEvent( insider );
    	if ( insider )
		{
			PlayerBase playerInsider;
			if (Class.CastTo(playerInsider, insider.GetObject()) )
			{
        		playerInsider.UnsetInEffectAreaTypeFlag(IAT_EffectAreaType.CORROSIVE_BIOGAS);
				StopParticle();
			}
		}
	}

	void PlayParticleOnPlayer(PlayerBase playerInsider)
	{
		// Print("player entered zone");
		if (!playerInsider.HasEnoughChemicalProtection())
		{
			m_VaporParticle = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BOILING_DONE, playerInsider, "0 1.6 0");

			int randSize = Math.RandomIntInclusive(2.5,4.5);
			int randRate = Math.RandomIntInclusive(0.5,2);

			m_VaporParticle.IncrementParticleParam(EmitorParam.SIZE, randSize);
			m_VaporParticle.IncrementParticleParam(EmitorParam.BIRTH_RATE, randRate);
			// Print("not enough biprotection, play particles")
		}
	}

	void StopParticle()
	{
		if (m_VaporParticle)
			m_VaporParticle.Stop();
	}
};