modded class DynamicMusicPlayerRegistry
{
	// make a new array for our music
	ref array<ref DynamicMusicTrackData> m_IAT_MineSystemMusic;

	override protected void PreloadData()
	{
		super.PreloadData();
		// register our tracks
		RegisterTracksIATMiningSystem();
	}

	override protected void RegisterCategorySettings()
	{
		super.RegisterCategorySettings();
		// register our track settings
		RegisterIATMineSystemSettings();
	}

	private void RegisterIATMineSystemSettings()
	{
		// set some default settings for our mining ambience transition
		DynamicMusicPlayerSettings settings = new DynamicMusicPlayerSettings();
		settings.m_MinWaitTimeSeconds = 1.0;
		settings.m_MaxWaitTimeSeconds = 3.0;

		settings.m_PreviousTrackFadeoutSeconds = 2.0;

		m_SettingsByCategory[IAT_EDynamicMusicPlayerCategory.MINING_SYSTEM] = settings;
	}

	protected void RegisterTracksIATMiningSystem()
	{
		m_IAT_MineSystemMusic = new array<ref DynamicMusicTrackData>();
		// register the tracks to the array
		RegisterTrackIATMiningSystem("Sakhal_WindBigCaveHeavy_SoundSet");
		RegisterTrackIATMiningSystem("Sakhal_bigCave_SoundSet");
		RegisterTrackIATMiningSystem("Sakhal_WindSmallCaveLight_SoundSet");
		RegisterTrackIATMiningSystem("Underground_SoundSet");
		// eventually add different tracks to night and day
	}

	protected void RegisterTrackIATMiningSystem(string soundSetName, int locationType = DynamicMusicLocationTypes.NONE, int timeOfDay = DynamicMusicPlayerTimeOfDay.ANY)
	{
		DynamicMusicTrackData track = new DynamicMusicTrackData();
		track.m_Category 		= IAT_EDynamicMusicPlayerCategory.MINING_SYSTEM;
		track.m_SoundSet 		= soundSetName;
		track.m_LocationType	= locationType;
		track.m_TimeOfDay 		= timeOfDay;

		m_IAT_MineSystemMusic.Insert(track);
	}
};