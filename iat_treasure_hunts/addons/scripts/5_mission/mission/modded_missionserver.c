modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATTreasureHuntConfig(GetDayZGame().GetIATTreasureHuntConfig());
	}

	// currently there is no need to sync to the client. if there is a need, probly need invoke client connect
	// instead of this so first time joiners get it
	// override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	// {
	// 	super.OnClientReadyEvent(identity, player);

	// 	auto configParams = new Param1<IAT_TreasureHuntConfig>(GetDayZGame().GetIATTreasureHuntConfig());
	// 	PrintFormat("Sending IAT_TreasureHunt Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_TreasureHunts.CHECK_CONFIG);
	// 	g_Game.RPCSingleParam(player, IAT_RPC_TreasureHunts.CHECK_CONFIG, configParams, true, identity);
	// }
};