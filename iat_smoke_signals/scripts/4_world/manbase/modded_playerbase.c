modded class PlayerBase
{
	//=============================================== VANILLA OVERRIDE
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		switch(rpc_type)
		{
			// server is sending copy of config to client (not authority, just for action checking)
			case IAT_RPC_SMOKESIGNALS.CHECK_CONFIG:
			{
				Param1<IAT_SmokeSignalsConfig> configParams;
				// read the params, short circuit if there is an error
				if(!ctx.Read(configParams))
					return;

				// set client local copy of the config
				GetDayZGame().SetIATSmokeSignalsConfig(configParams.param1);
				break;
			}
			break;
		}
	}
};
