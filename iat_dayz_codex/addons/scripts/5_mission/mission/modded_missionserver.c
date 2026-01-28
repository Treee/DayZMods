modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATDayZCodexConfig(GetDayZGame().GetIATDayZCodexConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		auto configParams = new Param1<IAT_DayZCodexConfig>(GetDayZGame().GetIATDayZCodexConfig());
		PrintFormat("Sending IAT_DayZCodex Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_DayZCodex.CHECK_CONFIG);
		g_Game.RPCSingleParam(player, IAT_RPC_DayZCodex.CHECK_CONFIG, configParams, true, identity);
	}
};