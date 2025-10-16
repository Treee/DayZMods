class IAT_Gramaphone_Colorbase extends ItemBase
{
	static const string SLOT_NAME = "IAT_VinylRecord";

	EffectSound m_ActiveSound;

	protected bool m_IAT_IsPlaying = false;  // server state variable
	protected bool m_IAT_IsPlayingLocal = false; // client debouncer

	protected string m_SoundSetName = "";

	void IAT_Gramaphone_Colorbase()
	{
		RegisterNetSyncVariableBool("m_IAT_IsPlaying");
	}

	//========================================================== EVENTS
	// this is really only for players that walk into a netsync bubble AFTER the sound is playing
	// or maybe they logged in after
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		// if we are not playing a sound locally
		if (!m_IAT_IsPlayingLocal)
		{
			// if the server says we SHOULD be playing a sound
			if (m_IAT_IsPlaying)
			{
				// play music
				TurnOn();
				m_IAT_IsPlayingLocal = true;
			}
			else
			{
				// stop sound
				TurnOff();
				m_IAT_IsPlayingLocal = false;
			}
		}
	}

    override void EEInit()
    {
        super.EEInit();
        UpdateAppearance();
    }
	override void OnWorkStart()
	{
		// short circuit to play / stop in one line
		if (!Play())
		{
			TurnOff();
		}
	}
	override void OnWorkStop()
	{
		Stop();
	}
	override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item, slot_name);
        if (slot_name == SLOT_NAME)
		{
			string cfgPath = string.Format("CfgVehicles %1 CfgCassette soundSet", item.GetType());
			if(GetGame().ConfigIsExisting(cfgPath))
			{
				m_SoundSetName = GetGame().ConfigGetTextOut(cfgPath);
			}
            SetAnimationPhase("vinyl", 0.0); // show when attached
		}
    }
    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item, slot_name);
        if (slot_name == SLOT_NAME)
		{
			m_SoundSetName = "";
            SetAnimationPhase("vinyl", 1.0); // hide when removed
			TurnOff();
		}
    }
	override bool CanPutInCargo (EntityAI parent)
	{
		return false;
	}
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
		AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTurnOffWhileOnGround);
	}

	//========================================================== CUSTOM CODE
	void TurnOff()
	{
		GetCompEM().SwitchOff();
	}

	void TurnOn()
	{
		if ( GetCompEM().CanWork() )
		{
			GetCompEM().SwitchOn();
		}
	}
	// bool return helpful fdr short circuiting on certain conditions
	protected bool Play()
	{
		if (!HasRecordAttached())
		{
			return false;
		}

		// client side sound
		if (!GetGame().IsDedicatedServer())
		{
			StopRecordSound();

			PlayRecordSound();

			SetAnimationPhase("vinyl_rotate", 5000); // start rotation

			m_IAT_IsPlayingLocal = true;
		}
		else // server side state
		{
			m_IAT_IsPlaying = true;
			SetSynchDirty();
		}
		return true;
	}
	protected void Stop()
	{
		// client side
		if (!GetGame().IsDedicatedServer())
		{
			StopRecordSound();
			SetAnimationPhaseNow("vinyl_rotate", 0); // stop rotation
		}
		else
		{
			m_IAT_IsPlaying = false;
			SetSynchDirty();
		}
	}
    protected void PlayRecordSound()
	{
		if (m_SoundSetName != "")
		{
			PlaySoundSetLoop(m_ActiveSound, m_SoundSetName, 0, 0);
		}
	}
	protected void StopRecordSound()
	{
		if (m_ActiveSound)
		{
			StopSoundSet(m_ActiveSound);
		}
	}
	protected void UpdateAppearance()
    {
		EntityAI vinyl;
		if (Class.CastTo(vinyl, FindAttachmentBySlotName(SLOT_NAME)))
		{
        	SetAnimationPhaseNow("vinyl", 0.0);
		}
		else
		{
			SetAnimationPhaseNow("vinyl", 1.0);
		}
    }
	void SetSoundIsPlaying(bool state)
	{
		m_IAT_IsPlaying = state;
	}
	bool IsPlayingSound()
	{
		return m_IAT_IsPlaying;
	}
	bool HasRecordAttached()
	{
		EntityAI vinyl;
        if (Class.CastTo(vinyl, FindAttachmentBySlotName(SLOT_NAME)))
        {
            return true;
        }
		return false;
	}
};

class IAT_Gramaphone_Basic extends IAT_Gramaphone_Colorbase{};
class IAT_Gramaphone_Essesentiendum extends IAT_Gramaphone_Colorbase{};