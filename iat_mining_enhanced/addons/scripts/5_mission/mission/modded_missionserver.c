modded class MissionServer
{
	void MissionServer()
	{
		IAT_MiningConfig miningConfig = GetDayZGame().GetIATMiningConfig();
		GetDayZGame().SetIATMiningConfig(miningConfig);
		InitializeMiningTunnelSystem(miningConfig);
	}

	void InitializeMiningTunnelSystem(IAT_MiningConfig miningConfig)
	{
		array<ref IAT_MiningSegmentConfig> miningSegments = miningConfig.GetMiningSegments();
		foreach(IAT_MiningSegmentConfig miningSegment : miningSegments)
		{
			// create object
		}
	}

	// no current need to send to client atm
	// override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	// {
	// 	super.OnClientReadyEvent(identity, player);

	// 	auto configParams = new Param1<IAT_MiningConfig>(GetDayZGame().GetIATMiningConfig());
	// 	PrintFormat("Sending IAT_Codelock Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG);
	// 	GetGame().RPCSingleParam(player, IAT_RPC_Codelock.CHECK_CODELOCK_CONFIG, configParams, true, identity);
	// }
};