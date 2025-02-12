class IAT_InfinityGauntlet_ColorBase extends Gloves_Base
{
	protected EffectSound m_SnappingSound;
	protected ParticleSource m_GloveParticle;

	void ~IAT_InfinityGauntlet_ColorBase()
	{
		StopParticles();
	}

	bool HasAllStones()
	{
		return GetInventory().AttachmentCount() == 6;
	}

	void BalanceTheUniverse()
	{
		array<Man> players = new array<Man>();
		GetGame().GetPlayers(players);

		players.ShuffleArray();

		int numPlayersHalf = players.Count() / 2;
		PrintFormat("BalanceTheUniverse================================================== %1", numPlayersHalf);
		PlayerBase player;
		foreach (int index, Man p : players)
		{
			// short circuit when we are done
			if (index >= numPlayersHalf)
				return;

			PrintFormat("index: %1", index);
			// cast to a playerbase for rpc fun
			if (Class.CastTo(player, p))
			{
				// tell them thanos has claimed their soul
				GetGame().RPCSingleParam(player, ERPCs.RPC_WARNING_TELEPORT, null, true, player.GetIdentity());
				// kill the player
				player.SetHealth(0);
			}
		}
	}

	void DeleteAllStones()
	{
		int totalSlots = GetInventory().AttachmentCount();
		EntityAI infinityStone;
		for (int i = 0; i < totalSlots; i++)
		{
			if (Class.CastTo(infinityStone, GetInventory().GetAttachmentFromIndex(i)))
			{
				infinityStone.DeleteSafe();
			}
		}
	}

	void RuinGlove()
	{
		SetHealth(0);
	}

	void StopParticles()
	{
		if (m_GloveParticle)
			m_GloveParticle.StopParticle();
	}
	void PlayParticleEffect()
	{
		// client only
		if (!GetGame().IsDedicatedServer())
		{
			if (m_GloveParticle)
				m_GloveParticle.StopParticle();

			// EASTER_EGG_ACTIVATE
			// FIREWORKS_EXPLOSION_BLUE
			m_GloveParticle = ParticleManager.GetInstance().PlayOnObject(ParticleList.EASTER_EGG_ACTIVATE, this, GetSnapParticlePosition());
			// m_GloveParticle.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(0.1, 0.5));
			// m_GloveParticle.ScaleParticleParam(EmitorParam.LIFETIME, Math.RandomFloatInclusive(1, 3));
			// m_GloveParticle.ScaleParticleParam(EmitorParam.VELOCITY, Math.RandomFloatInclusive(0.1, 0.5));
			m_GloveParticle.ScaleParticleParam(EmitorParam.SIZE, Math.RandomFloatInclusive(1.8, 2.5));
        	m_GloveParticle.ScaleParticleParam(EmitorParam.LIFETIME, Math.RandomFloatInclusive(5, 13));

		}
	}
	vector GetSnapParticlePosition()
	{
		return "0 0 0";
	}

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        if (rpc_type == IAT_IG_RPC.SOUND_GAUNTLET_SNAP)
        {
            bool playSound;
            vector pos;
            string sound_set;

            //Helicrash is a world event, we want anyone to be able to hear it
            Param3<bool, vector, int> playCrashSound = new Param3<bool, vector, int>(false, "0 1.5 0",0);
            if (ctx.Read(playCrashSound))
            {
                playSound = playCrashSound.param1;
                pos = playCrashSound.param2;
                sound_set = GetGauntletSnapSound();
            }

            if (playSound)
            {
                m_SnappingSound = SEffectManager.PlaySound(sound_set, pos);
                m_SnappingSound.SetAutodestroy(true);
            }
        }
        super.OnRPC(sender, rpc_type, ctx);
    };

	// server side
    void PlaySnapSound()
    {
        Param3<bool, vector, int> playSound = new Param3<bool, vector, int>(true, GetPosition(), 0);
        RPCSingleParam(IAT_IG_RPC.SOUND_GAUNTLET_SNAP, playSound, true);
    }

	string GetGauntletSnapSound()
	{
		return "IAT_InfinityGauntlet_SoundSet_FingerSnap";
	}
};