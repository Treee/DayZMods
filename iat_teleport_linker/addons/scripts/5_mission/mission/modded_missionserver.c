modded class MissionServer
{
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

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		Param1<IAT_TeleportLinkConfig> configParams = new Param1<IAT_TeleportLinkConfig>(GetDayZGame().GetIATTeleportLinkConfig());
		PrintFormat("[IAT_Teleport_Linker] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_TELEPORTLINK.SEND_CONFIG);
		GetGame().RPCSingleParam(player, IAT_RPC_TELEPORTLINK.SEND_CONFIG, configParams, true, identity);
	}
};