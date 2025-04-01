modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATFacePaintConfig(GetDayZGame().GetIATFacePaintConfig());
	}

	// there is no need to send the client the config yet
	// override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	// {
	// 	super.OnClientReadyEvent(identity, player);

	// 	auto configParams = new Param1<IAT_FacePaintsConfig>(GetDayZGame().GetIATFacePaintConfig());
	// 	PrintFormat("Sending IAT_FacePaints Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_FACEPAINT_RPC.CHECK_FACEPAINT_CONFIG);
	// 	GetGame().RPCSingleParam(player, IAT_FACEPAINT_RPC.CHECK_FACEPAINT_CONFIG, configParams, true, identity);
	// }
};