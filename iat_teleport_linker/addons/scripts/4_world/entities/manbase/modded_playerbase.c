modded class PlayerBase
{
	protected vector m_IAT_PreviousLocation = "0 0 0";

	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		AddAction(IAT_ActionTeleportToDestination, InputActionMap);
		AddAction(IAT_ActionTeleportToPreviousLocation, InputActionMap);
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

	bool IAT_HasPreviousLocation()
	{
		if (IAT_GetPreviousLocation() == "0 0 0")
			return false;
		return true;
	}

	vector IAT_GetPreviousLocation()
	{
		if (m_IAT_PreviousLocation)
			return m_IAT_PreviousLocation;
		return "0 0 0";
	}

	void IAT_SetPreviousLocation(vector lastPosition)
	{
		m_IAT_PreviousLocation = lastPosition;
	}

	void IAT_ClearPreviousLocation()
	{
		m_IAT_PreviousLocation = "0 0 0";
	}
};