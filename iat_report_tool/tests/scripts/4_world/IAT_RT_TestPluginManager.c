#ifdef DIAG_DEVELOPER
#ifdef IAT_TestHarness
modded class PluginManager
{
	override void Init()
	{
		super.Init();

		// The diagnostic item plugin expects this vanilla dependency even when
		// IsDebug() is false. Its settings stay in the isolated run's profile.
		if (!g_Game.IsDebug())
			RegisterPlugin("PluginConfigDebugProfile", true, true);
	}
}
#endif
#endif
