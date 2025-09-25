class IAT_BellTower_ColorBase extends House
{
  	protected EffectSound m_BellSound;

	protected bool m_IsPlayingSound = false; // used to control the sound on client side
	protected const string BELL_SOUND = "IAT_Mods_Ambience_BellSounds_SoundShader_SoundSet";
	void IAT_BellTower_ColorBase()
	{
		RegisterNetSyncVariableBool("m_IsPlayingSound");
	}

	// ========================================== VANILLA OVERRIDE
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if (m_IsPlayingSound)
		{
			PlayBellSound();
		}
		else
		{
			StopSoundSet(m_BellSound);
		}
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionRingBellTower);
	}
	override bool IsBuilding()
	{
		return false;
	}

	// ========================================== CUSTOM CODE
	bool CanRingTower()
	{
		// check to see if the sound in playing, otherwise let them ring the bell
		return !m_IsPlayingSound;
	}
	void PlayBellSound()
	{
		if (!GetGame().IsDedicatedServer())
		{
			PlaySoundSet(m_BellSound, BELL_SOUND, 0.3, 0.3, true);
		}
	}
	void RingBellTower()
	{
		m_IsPlayingSound = true;
		SetSynchDirty();

		float time = 30 * 1000;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(AutoTurnOffRinging, time, false);
	}

	void AutoTurnOffRinging()
	{
		m_IsPlayingSound = false;
		SetSynchDirty();
	}
};

class StaticObj_Furniture_TownBell_Default extends IAT_BellTower_ColorBase{};