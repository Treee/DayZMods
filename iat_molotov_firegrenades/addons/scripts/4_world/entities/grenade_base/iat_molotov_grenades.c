class IAT_Incendiary_Base extends Grenade_Base
{
	protected bool 					m_IAT_Exploded;
	protected EffectSound 			m_IAT_ExplosionSound;
	protected EffectSound 			m_IAT_ExplosionSound1;

	void IAT_Incendiary_Base()
	{
		IAT_Init();
	}
	void ~IAT_Incendiary_Base(){}

	void IAT_Init()
	{
		SetParticleExplosion(ParticleList.RGD5);
		SetGrenadeType(EGrenadeType.CHEMICAL);
		m_Pinned = false;
		SetPinnable(false);
		Arm();
	}

	override protected void OnExplode()
	{
		m_IAT_Exploded = true;

		if (GetGame().IsServer())
		{
			GetGame().CreateObject("IAT_IncendiaryArea_Local", GetPosition());
		}
	}

	protected string GetExplosionSoundSet()
	{
		return "Grenade_detonation_SoundSet";
	}

	override void EOnContact(IEntity other, Contact extra)
	{
		if (GetGame().IsServer())
		{
			if (!m_IAT_Exploded)
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
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Delete, 1000);
		}

		// why not else here? to fully remove code on server? preference?
		#ifndef SERVER

		ClearFlags(EntityFlags.VISIBLE, false);
		PlaySoundSet( m_IAT_ExplosionSound, GetExplosionSoundSet(), 0, 0 );
		PlaySoundSet( m_IAT_ExplosionSound1, "GasStation_Explosion_SoundSet", 0, 0 );
		#endif
	}

	override protected void Activate()
	{
		//we don't want base functionality here
	}
};

class IAT_Molotov_Grenade_Incendiary extends IAT_Incendiary_Base{};
class IAT_Molotov_Grenade_Molotov extends IAT_Incendiary_Base{};