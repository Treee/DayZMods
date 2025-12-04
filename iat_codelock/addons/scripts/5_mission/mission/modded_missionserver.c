modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATCodelockConfig(GetDayZGame().GetIATCodelockConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		auto configParams = new Param1<IAT_CodelockConfig>(GetDayZGame().GetIATCodelockConfig());
		PrintFormat("Sending IAT_Codelock Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG);
		g_Game.RPCSingleParam(player, IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG, configParams, true, identity);
	}
};