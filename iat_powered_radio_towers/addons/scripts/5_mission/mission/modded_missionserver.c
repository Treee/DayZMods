modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATPoweredRadioTowerConfig(GetDayZGame().GetIATPoweredRadioTowerConfig());
		InitializeRadioTowerConsoles();
	}

	// override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	// {
	// 	super.OnClientReadyEvent(identity, player);

	// 	Param1<IAT_PoweredRadioTowerConfig> configParams = new Param1<IAT_PoweredRadioTowerConfig>(GetDayZGame().GetIATPoweredRadioTowerConfig());
	// 	PrintFormat("[IAT_PoweredRadioTowerConfig] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_POWEREDRADIOTOWER_RPC.CHECK_POWEREDRADIOTOWER_CONFIG);
	// 	GetGame().RPCSingleParam(player, IAT_POWEREDRADIOTOWER_RPC.CHECK_POWEREDRADIOTOWER_CONFIG, configParams, true, identity);
	// }

	void InitializeRadioTowerConsoles()
	{
		Print("--[POWERED RADIO TOWER WALL CONSOLE INIT]");
		Object object;
		StaticObj_iat_wallconsole wallConsole;
		int flags = ECE_SETUP | ECE_UPDATEPATHGRAPH | ECE_CREATEPHYSICS | ECE_NOLIFETIME | ECE_DYNAMIC_PERSISTENCY | ECE_KEEPHEIGHT;
		array<ref IAT_PoweredTowerConsoleData> m_TowerConsoleData = GetDayZGame().GetIATPoweredRadioTowerConfig().GetTowerConsoleData();
		foreach (IAT_PoweredTowerConsoleData data : m_TowerConsoleData)
		{
			// decrement restart counter
			data.ConsumeRestartToken();

			object = GetGame().CreateObjectEx("StaticObj_iat_wallconsole", data.GetConsolePosition(), flags, RF_IGNORE);
			if (Class.CastTo(wallConsole, object))
			{
				wallConsole.SetOrientation(data.GetConsoleOrientation());
				// if the console has no more restart tokens, default state to off
				if (!data.HasRestartToken())
				{
					wallConsole.SetIsPoweredOn(false);
					wallConsole.SetIsCPUOn(false);
					wallConsole.SetIsServerConnected(false);
					wallConsole.SetIsRelayConnected(false);
					wallConsole.SetDialSetting(0);
					PrintFormat("ID: %1 Power: %2 CPU: %3 Server: %4 Relay: %5 Dial: %6", data.GetConsoleId(), false, false, false, false, 0);
				}
				else
				{
					wallConsole.SetIsPoweredOn(data.IsPoweredOn());
					wallConsole.SetIsCPUOn(data.IsCPUOn());
					wallConsole.SetIsServerConnected(data.IsServerConnected());
					wallConsole.SetIsRelayConnected(data.IsRelayConnected());
					wallConsole.SetDialSetting(data.GetDialSetting());
					PrintFormat("ID: %1 Power: %2 CPU: %3 Server: %4 Relay: %5 Dial: %6", data.GetConsoleId(), data.IsPoweredOn(), data.IsCPUOn(), data.IsServerConnected(), data.IsRelayConnected(), data.GetDialSetting());
				}

				wallConsole.SetConsoleId(data.GetConsoleId());
				// wallConsole.SetSynchDirty();
				PrintFormat("Create Console at location %1", data.GetConsolePosition());
			}
			else
			{
				PrintFormat("==Error== Create Console at location %1", data.GetConsolePosition());
			}
		}
	}
};