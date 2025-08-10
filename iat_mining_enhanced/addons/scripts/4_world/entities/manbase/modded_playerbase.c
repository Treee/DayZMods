modded class PlayerBase
{
	// client side only
	void StartUndergroundMusic()
	{
		DynamicMusicPlayer musicPlayer;
		if (Class.CastTo(musicPlayer, GetGame().GetMission().GetDynamicMusicPlayer()))
		{
			DynamicMusicPlayerCategoryPlaybackData playbackData = new DynamicMusicPlayerCategoryPlaybackData();
			playbackData.m_Category = IAT_EDynamicMusicPlayerCategory.MINING_SYSTEM;
			playbackData.m_Forced 	= true;
			playbackData.m_FadeOut 	= false;
			musicPlayer.SetCategory(playbackData);
		}
	}
	void StopUndergroundMusic()
	{
		DynamicMusicPlayer musicPlayer;
		if (Class.CastTo(musicPlayer, GetGame().GetMission().GetDynamicMusicPlayer()))
		{
			DynamicMusicPlayerCategoryPlaybackData playbackData = new DynamicMusicPlayerCategoryPlaybackData();
			playbackData.m_Category = EDynamicMusicPlayerCategory.NONE;
			playbackData.m_Forced 	= true;
			playbackData.m_FadeOut 	= true;
			musicPlayer.SetCategory(playbackData);
		}
	}

	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(IAT_ActionDescendIntoMine, InputActionMap);
		AddAction(IAT_ActionAscendOutOfMine, InputActionMap);
	}
};