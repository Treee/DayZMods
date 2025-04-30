class StaticObj_iat_wallconsole extends House
{
	protected const int RPC_HARD_SYNC_DATA = 5432161;
	protected const int MAX_DIAL_SETTING = 7;
	protected bool m_IsPoweredOn; // is the radio tower powered on
	protected bool m_IsCPUOn; // is the cpu on (encryption/ciphered hacking)
	protected bool m_IsServerConnected; // is the server connected (read messages for pda)
	protected bool m_IsRelayConnected; // is the relay connected (connected to ic radio)
	protected int m_DialSetting; // is the timer wound up (number of restarts left to be on automatically)
	protected int m_ConsoleId; // only used on server; this is the unique id of the console for json list for quick searching

	void StaticObj_iat_wallconsole()
	{
		RegisterNetSyncVariableBool("m_IsPoweredOn");
		RegisterNetSyncVariableBool("m_IsCPUOn");
		RegisterNetSyncVariableBool("m_IsServerConnected");
		RegisterNetSyncVariableBool("m_IsRelayConnected");
		RegisterNetSyncVariableInt("m_DialSetting", 0, MAX_DIAL_SETTING); // 7 days max reset timer
	}
	// ============================================ VANILLA OVERRIDE
	override void DeferredInit()
	{
		super.DeferredInit();
		if (!GetGame().IsDedicatedServer())
		{
			// we need to sync that first load of data to the client. lazy loading felt the best approach to minimize rpc's
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(HardSyncServerData, 1000, false);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		IAT_UpdateConsoleVisuals();
	};

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type,ctx);
		if (rpc_type == RPC_HARD_SYNC_DATA)
		{
			HandleClientServerRPC(sender, ctx);
		}
	}

	// ============================================ CUSTOM
	void HandleClientServerRPC(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(IsPoweredOn());
			rpc.Write(IsRelayConnected());
			rpc.Write(IsServerConnected());
			rpc.Write(IsCPUOn());
			rpc.Write(GetDialSetting());
			rpc.Send(this, RPC_HARD_SYNC_DATA, true, sender);
			return;
		}
		HandleOnClientRPCRead(ctx);
	}
	void HandleOnClientRPCRead(ParamsReadContext ctx)
	{
		bool isOn, relayOn, serverOn, cpuOn;
		int dialSetting;
		if ( !ctx.Read(isOn) )
			return;
		if ( !ctx.Read(relayOn) )
			return;
		if ( !ctx.Read(serverOn) )
			return;
		if ( !ctx.Read(cpuOn) )
			return;
		if ( !ctx.Read(dialSetting) )
			return;

		SetIsPoweredOn(isOn);
		SetIsRelayConnected(relayOn);
		SetIsServerConnected(serverOn);
		SetIsCPUOn(cpuOn);
		SetDialSetting(dialSetting);
		IAT_UpdateConsoleVisuals();
	}

	void HardSyncServerData()
	{
		if (!GetGame().IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			PlayerBase player;
			if (Class.CastTo(player, GetGame().GetPlayer()))
			{
				rpc.Send(this, RPC_HARD_SYNC_DATA, true, player.GetIdentity());
			}
		}
	}

	void IAT_UpdateConsoleVisuals()
	{
		IAT_UpdatePowerSwitchVisuals();
		IAT_UpdateRelaySwitchVisuals();
		IAT_UpdateServerSwitchVisuals();
		IAT_UpdateCPUSwitchVisuals();
		IAT_UpdateRestartDialVisuals();
	}

	void IAT_UpdatePowerSwitchVisuals()
	{
		if (IsPoweredOn())
		{
			SetAnimationPhase("power", 1);
		}
		else
		{
			SetAnimationPhase("power", 0);
		}
	}
	void IAT_UpdateRelaySwitchVisuals()
	{
		if (IsRelayConnected())
		{
			SetAnimationPhase("relay", 1);
		}
		else
		{
			SetAnimationPhase("relay", 0);
		}
	}
	void IAT_UpdateServerSwitchVisuals()
	{
		if (IsServerConnected())
		{
			SetAnimationPhase("server", 1);
		}
		else
		{
			SetAnimationPhase("server", 0);
		}
	}
	void IAT_UpdateCPUSwitchVisuals()
	{
		if (IsCPUOn())
		{
			SetAnimationPhase("cpu", 1);
		}
		else
		{
			SetAnimationPhase("cpu", 0);
		}
	}
	void IAT_UpdateRestartDialVisuals()
	{
		float phase = Math.Min(m_DialSetting / MAX_DIAL_SETTING, 1);
		SetAnimationPhase("dial", phase);
	}

	void UpdateConfigData()
	{
		GetDayZGame().GetIATPoweredRadioTowerConfig().UpdateConsole(GetConsoleId(), IsPoweredOn(), IsRelayConnected(), IsServerConnected(), IsCPUOn(), GetDialSetting());
	}
	// can only toggle the switches when power is on
	bool CanToggleSwitch()
	{
		return IsPoweredOn();
	}
	void ToggleRelay()
	{
		// flip the bits
		SetIsRelayConnected(!m_IsRelayConnected);
		UpdateConfigData();
	}
	void ToggleServer()
	{
		SetIsServerConnected(!m_IsServerConnected);
		UpdateConfigData();
	}
	void ToggleCpu()
	{
		SetIsCPUOn(!m_IsCPUOn);
		UpdateConfigData();
	}
	// business logic for enforcing some sort of order of switches
	bool CanPowerOn()
	{
		// World Power Override
		#ifdef AdmiralsTerminalsMod
        if(GetGame().IsDedicatedServer())
        {
			IAT_PoweredRadioTowerConfig radioConsoleConfig = GetDayZGame().GetIATPoweredRadioTowerConfig();
			float requiredPower = radioConsoleConfig.GetRequiredTowerPower();
			float currentPower = GetWorldPower().GetGridPower01();
			if (currentPower >= requiredPower)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		#endif
		return true;
	}
	void TogglePower()
	{
		SetIsPoweredOn(!m_IsPoweredOn);
		if (!IsPoweredOn())
		{
			SetIsRelayConnected(false);
			SetIsServerConnected(false);
			SetIsCPUOn(false);
		}
		UpdateConfigData();
	}
	void TurnDial()
	{
		// calculate the next dial setting by adding 1 days to the current time
		int nextDialSetting = m_DialSetting + 1;
		if (nextDialSetting >= MAX_DIAL_SETTING)
		{
			m_DialSetting = 0;
		}
		else
		{
			m_DialSetting = nextDialSetting;
		}
		UpdateConfigData();
	}
	// ============================================ HELPERS
	bool IsPoweredOn()
	{
		return m_IsPoweredOn;
	}
	void SetIsPoweredOn(bool newPowerState)
	{
		m_IsPoweredOn = newPowerState;
	}
	bool IsCPUOn()
	{
		return m_IsCPUOn;
	}
	void SetIsCPUOn(bool newCPUState)
	{
		m_IsCPUOn = newCPUState;
	}
	bool IsServerConnected()
	{
		return m_IsServerConnected;
	}
	void SetIsServerConnected(bool newServerState)
	{
		m_IsServerConnected = newServerState;
	}
	bool IsRelayConnected()
	{
		return m_IsRelayConnected;
	}
	void SetIsRelayConnected(bool newRelayState)
	{
		m_IsRelayConnected = newRelayState;
	}
	int GetDialSetting()
	{
		return m_DialSetting;
	}
	void SetDialSetting(int newDialSetting)
	{
		m_DialSetting = newDialSetting;
	}
	int GetConsoleId()
	{
		return m_ConsoleId;
	}
	void SetConsoleId(int newId)
	{
		m_ConsoleId = newId;
	}
};