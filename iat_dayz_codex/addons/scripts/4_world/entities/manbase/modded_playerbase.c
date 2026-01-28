modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == IAT_RPC_DayZCodex.CHECK_CONFIG)
		{
			OnCheckConfig(ctx);
		}
	}

	// ================================================================================== CUSTOM CODE
	void OnCheckConfig(ParamsReadContext ctx)
	{
		Param1<IAT_DayZCodexConfig> configParams;
		// read the params, short circuit if there is an error
		if (!ctx.Read(configParams))
		{
			Print("IAT_DayZCodex::PlayerBase::OnCheckConfig - Failed to read IAT_DayZCodexConfig params");
			return;
		}
		// set client local copy of the config
		GetDayZGame().SetIATDayZCodexConfig(configParams.param1);
		// construct the codex

	}
};