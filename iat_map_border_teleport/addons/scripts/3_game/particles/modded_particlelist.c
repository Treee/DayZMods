modded class ParticleList
{
	static const int IAT_MBT_MAP_BORDER_FOG = RegisterParticle("iat_map_border_teleport/graphics/particles/", "iat_border_edge_fog");

	// #ifdef DIAG_DEVELOPER
	// // need this for diag mode for some reason as loading particles gets hung up and crashes client load.
	// // injecting some level of "wait" by writing to file seems to fix this issue.
	// // prod version of dayz exe does not have this issue...
	// //! Preloads all particles
	// override static void PreloadParticles()
	// {
	// 	if ( !g_Game.IsServer() || !g_Game.IsMultiplayer() ) // client side
	// 	{
	// 		int count = m_ParticlePaths.Count();
	// 		PrintFormat("[[MAP BORDER TELEPORT MOD]] Count of Particles: %1", count);
	// 		for (int i = 0; i < count; ++i)
	// 		{
	// 			vobject vobj = GetObject( string.Format("%1.ptc", m_ParticlePaths[i]) );
	// 			PrintFormat("Loading Particle: %1.ptc Type: %2", m_ParticlePaths[i], vobj);
	// 			ReleaseObject(vobj);
	// 		}
	// 	}
	// }
	// #endif
};