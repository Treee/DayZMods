modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATSmokeSignalsConfig(GetDayZGame().GetIATSmokeSignalsConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		auto configParams = new Param1<IAT_SmokeSignalsConfig>(GetDayZGame().GetIATSmokeSignalsConfig());
		PrintFormat("Sending IAT_SmokeSignals Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_SMOKESIGNALS.CHECK_CONFIG);
		GetGame().RPCSingleParam(player, IAT_RPC_SMOKESIGNALS.CHECK_CONFIG, configParams, true, identity);
	}
};