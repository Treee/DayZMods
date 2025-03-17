modded class PlayerBase
{
	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(IAT_ActionTeleportToDestination, InputActionMap);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == IAT_RPC_TELEPORTLINK.SEND_CONFIG)
		{
			Param1<IAT_TeleportLinkConfig> configParams;
			// read the params, short circuit if there is an error
			if(!ctx.Read(configParams))
				return;

			// set client local copy of the config
			GetDayZGame().SetIATTeleportLinkConfig(configParams.param1);
		}
	}
};