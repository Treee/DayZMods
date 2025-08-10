modded class DynamicMusicPlayer
{
	void DynamicMusicPlayer(DynamicMusicPlayerRegistry configuration)
	{
		// add our dynamic music category to the buffer system
		m_LastPlayedTrackBufferPerCategory[IAT_EDynamicMusicPlayerCategory.MINING_SYSTEM] = new SimpleCircularBuffer<int>(TRACKS_BUFFER_HISTORY_SIZE, -1);
	}

	override protected void DetermineTrackByCategory(EDynamicMusicPlayerCategory category)
	{
		super.DetermineTrackByCategory(category);
		// if the category is ours
		if (category == IAT_EDynamicMusicPlayerCategory.MINING_SYSTEM)
		{
			// try to set the selected track from category
			if (SetSelectedTrackFromCategory(category, m_DynamicMusicPlayerRegistry.m_IAT_MineSystemMusic, DynamicMusicPlayerTrackHistoryLookupType.BUFFER))
				return;

			// otherwise try to determine the track to set
			g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DetermineTrackByCategory, 5000, false, category);
			return;
		}
	}
};