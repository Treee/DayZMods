modded class MissionServer
{
	override void OnInit()
    {
        super.OnInit();
		GetDayZGame().SetIATDynamicTrapsConfig(GetDayZGame().GetIATDynamicTrapsConfig());
		Print("[IAT_Dynamic_Traps] Config Initialized");
    }
	// no need to send to client. (yet?)
	// override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	// {
	// 	super.OnClientReadyEvent(identity, player);

	// 	Param1<IAT_DynamicTrapsConfig> configParams = new Param1<IAT_DynamicTrapsConfig>(GetDayZGame().GetIATDynamicTrapsConfig());
	// 	PrintFormat("[IAT_Dynamic_Traps] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_DYNAMICTRAPS_RPC.CHECK_DYNAMICTRAPS_CONFIG);
	// 	GetGame().RPCSingleParam(player, IAT_DYNAMICTRAPS_RPC.CHECK_DYNAMICTRAPS_CONFIG, configParams, true, identity);
	// }
};