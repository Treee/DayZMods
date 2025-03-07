modded class TransmitterBase
{
	protected bool m_IAT_IsMuted = false;

	void TransmitterBase()
	{
		RegisterNetSyncVariableBool("m_IAT_IsMuted");
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		UpdateMuteRadioState();
  	};

	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionToggleMuteTransmitter);
	}

	override void OnWorkStart()
	{
		//turn on broadcasting/receiving
		super.OnWorkStart();

		//stop the static noise
		SoundTurnedOnNoiseStop();
		// set mute or not
		UpdateMuteRadioState();
	}

  	override void OnWorkStop()
	{
		//turn on broadcasting/receiving
		super.OnWorkStop();
		// set mute or not
		UpdateMuteRadioState();
	}

	override void OnInventoryEnter(Man player)
	{
		super.OnInventoryEnter(player);
		PlayerBase player_PB;
		if (Class.CastTo(player_PB, player))
		{
			// is server, player has a radio in hands, is not muted
			if(GetGame().IsDedicatedServer() && player_PB.GetItemInHands() == this)
			{
				string messageText;
				if ( IAT_IsMuted())
					messageText = "Transmitter is Muted";
				else
					messageText = "Transmitter is UnMuted";

				MessageToOwnerImportant(messageText);
			}
		}
	}

	void UpdateMuteRadioState()
	{
		if (GetCompEM().IsWorking())
		{
			// flip the boolean lol stupid bug and silly oversight
			bool isMuted = !IAT_IsMuted();

			// turn on or off the ability for this transmitter to broadcast
			EnableBroadcast(isMuted);
		}
	}

	// ========================================== GETTERS & SETTERS & HELPERS
	void IAT_MuteTransmitter()
	{
		if (GetGame().IsDedicatedServer())
		{
			IAT_SetMuted(true);
			UpdateMuteRadioState();
			SetSynchDirty();
		}
	}

	void IAT_UnMuteTransmitter()
	{
		if (GetGame().IsDedicatedServer())
		{
			IAT_SetMuted(false);
			UpdateMuteRadioState();
			SetSynchDirty();
		}
	}

	void IAT_SetMuted(bool newState)
	{
		m_IAT_IsMuted = newState;
	}

	bool IAT_IsMuted()
	{
		return m_IAT_IsMuted;
	}
};