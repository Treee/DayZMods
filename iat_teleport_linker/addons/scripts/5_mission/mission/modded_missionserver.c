modded class MissionServer
{
	protected ref TStringIntMap m_IAT_TL_LoggedInPlayers = new TStringIntMap();

	override void OnInit()
    {
        super.OnInit();
		GetDayZGame().SetIATTeleportLinkConfig(GetDayZGame().GetIATTeleportLinkConfig());
		Print("[IAT_Teleport_Linker] Config Initialized");
    }

	override void OnMissionStart()
	{
		super.OnMissionStart();
		Print("[IAT_Teleport_Linker] Setup Teleports");
	}

	override void OnMissionFinish()
	{
		GetDayZGame().GetIATTeleportLinkConfig().SaveConfig();
		super.OnMissionFinish();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		// if the player is not in the list
		if (!IAT_TL_IsLoggedIn(identity.GetPlainId()))
		{
			// send them the config
			Param1<IAT_TeleportLinkConfig> configParams = new Param1<IAT_TeleportLinkConfig>(GetDayZGame().GetIATTeleportLinkConfig());
			PrintFormat("[IAT_Teleport_Linker] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_TELEPORTLINK.SEND_CONFIG);
			GetGame().RPCSingleParam(player, IAT_RPC_TELEPORTLINK.SEND_CONFIG, configParams, true, identity);
			// add them to the list for next time
			IAT_TL_AddToMap(identity.GetPlainId());
		}
	}
	override void InvokeOnDisconnect(PlayerBase player)
	{
		// if the player exists
		if (player)
		{
			// if the player is logged in
			if (IAT_TL_IsLoggedIn(player.GetIdentity().GetPlainId()))
			{
				// remove them from the list for net login
				IAT_TL_RemoveFromMap(player.GetIdentity().GetPlainId());
			}
		}
		super.InvokeOnDisconnect(player);
	}

	void IAT_TL_AddToMap(string playerId)
	{
		m_IAT_TL_LoggedInPlayers.Set(playerId, 1);
	}
	void IAT_TL_RemoveFromMap(string playerId)
	{
		m_IAT_TL_LoggedInPlayers.Remove(playerId);
	}

	bool IAT_TL_IsLoggedIn(string playerId)
	{
		return m_IAT_TL_LoggedInPlayers.Contains(playerId);
	}
};