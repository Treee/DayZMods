class IncendiaryArea_Base extends EffectArea
{
	override void OnPlayerEnterServer(PlayerBase player, EffectTrigger trigger)
	{
		super.OnPlayerEnterServer(player, trigger);
		player.IAT_IncreaseIncendiaryAreaCount();
	}

	override void OnPlayerExitServer(PlayerBase player, EffectTrigger trigger)
	{
		super.OnPlayerExitServer(player, trigger);
		player.IAT_DecreaseIncendiaryAreaCount();
	}

	override void InitZoneClient()
	{
		super.InitZoneClient();

		g_Game.GetMission().GetDynamicMusicPlayer().RegisterDynamicLocation(this, DynamicMusicLocationTypes.CONTAMINATED_ZONE, m_Radius);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (!g_Game.IsServer())
			g_Game.GetMission().GetDynamicMusicPlayer().UnregisterDynamicLocation(this);
	}
};

class IAT_IncendiaryArea_Static extends IncendiaryArea_Base
{
	// ----------------------------------------------
	// 				INITIAL SETUP
	// ----------------------------------------------
	// override void SetupZoneData(  EffectAreaParams params )
	// {
	// 	super.SetupZoneData( params );
	// }

	override void EEInit()
	{
		// We make sure we have the particle array
		if ( !m_ToxicClouds )
			m_ToxicClouds = new array<Particle>;

		SetSynchDirty();

		super.EEInit();
	}

	override void DeferredInit()
	{
		super.DeferredInit();

		InitZone();
	}


	override void InitZoneServer()
	{
		super.InitZoneServer();

		// We create the trigger on server
		if ( m_TriggerType != "" )
			CreateTrigger( m_Position, m_Radius );
	}

	override void InitZoneClient()
	{
		super.InitZoneClient();

		// We spawn VFX on client
		PlaceParticles( GetWorldPosition(), m_Radius, m_InnerRings, m_InnerSpacing, m_OuterRingToggle, m_OuterSpacing, m_OuterRingOffset, m_ParticleID );
	}

	override void OnDebugSpawn()
	{
		super.OnDebugSpawn();

		InitZone();
	}
};