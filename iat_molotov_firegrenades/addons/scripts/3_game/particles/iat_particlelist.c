modded class ParticleList
{
	static const int IAT_GRENADE_INCENDIARY_PUFF = RegisterParticle("iat_molotov_firegrenades/graphics/particles/", "incendiary_area_gas_grenade");
	static const int IAT_GRENADE_INCENDIARY_AROUND = RegisterParticle("iat_molotov_firegrenades/graphics/particles/", "incendiary_area_gas_around");
	static const int IAT_GRENADE_INCENDIARY_SHELL = RegisterParticle("iat_molotov_firegrenades/graphics/particles/", "incendiary_area_gas_shell");
	static const int IAT_GRENADE_INCENDIARY_FIRE = RegisterParticle("iat_molotov_firegrenades/graphics/particles/", "incendiary_fire");
	static const int IAT_GRENADE_INCENDIARY_AROUNDTINY = RegisterParticle("iat_molotov_firegrenades/graphics/particles/", "incendiary_area_gas_around_tiny");
	static const int IAT_GRENADE_INCENDIARY_BIGASS = RegisterParticle("iat_molotov_firegrenades/graphics/particles/", "incendiary_area_gas_bigass");


	#ifdef DIAG_DEVELOPER
	// need this for diag mode for some reason as loading particles gets hung up and crashes client load.
	// injecting some level of "wait" by writing to file seems to fix this issue.
	// prod version of dayz exe does not have this issue...
	//! Preloads all particles
	override static void PreloadParticles()
	{
		if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) // client side
		{
			int count = m_ParticlePaths.Count();
			PrintFormat("count of particles: %1", count);
			for (int i = 0; i < count; ++i)
			{
				vobject vobj = GetObject( string.Format("%1.ptc", m_ParticlePaths[i]) );
				PrintFormat("loading particle: %1.ptc type: %2", m_ParticlePaths[i], vobj);
				ReleaseObject(vobj);
			}
		}
	}
	#endif
};