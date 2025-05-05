modded class PlayerBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == IAT_CRAFTINGPLUS_RPC.CHECK_CRAFTINGPLUS_CONFIG)
		{
			Param1<IAT_CraftingPlusConfig> configParams;
			// read the params, short circuit if there is an error
			if(!ctx.Read(configParams))
				return;

			// set client local copy of the config
			GetDayZGame().SetIATCraftingPlusConfig(configParams.param1);
			// Print("=========================================================== MANAGER SYNC!!!!");
			// once we have the recipes, sync the clients recipes
			IAT_CraftingPlus_CraftingBench_Base.SyncEvent_IAT_OnCraftingManagerChange.Invoke(this);
		}
	}
};