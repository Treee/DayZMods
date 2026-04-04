modded class PlayerBase
{
	protected bool m_IAT_CanDeployPersonalTent = false;

	//================================================== OVERRIDES
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		TryFetchCanDeployPersonalTent();
	}
	//================================================== RPC'S
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
			case IAT_RPC_PERSONALTENT.UPDATE_CAN_PLACE_CLIENT: // server side update to specific player
				IAT_ClientCanDeployTentRequest(sender, ctx);
				break;
        }
        super.OnRPC(sender, rpc_type, ctx);
    }
	// meant to be used the first time the player loads in to see if any tents on the map belong to them
	void IAT_ClientCanDeployTentRequest(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (g_Game.IsDedicatedServer())
		{
			IAT_TentManager tentManager;
			if (Class.CastTo(tentManager, GetDayZGame().IAT_GetTentManager()))
			{
				IAT_SetCanDeployPersonalTent(tentManager.IAT_HasDeployedTent(sender.GetPlainId()));
			}

			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(m_IAT_CanDeployPersonalTent);
			rpc.Send(this, IAT_RPC_PERSONALTENT.UPDATE_CAN_PLACE_CLIENT, true, sender);
			return;
		}
		// handle the rpc on the client side
		IAT_ClientCanDeployTentResponse(ctx);
	}
	// client side function to set if this player can deploy a personal tent
    void IAT_ClientCanDeployTentResponse(ParamsReadContext ctx)
    {
		// client only
        if (!g_Game.IsDedicatedServer())
        {
			// if we run into issues deserializing the data
			if (!ctx.Read(m_IAT_CanDeployPersonalTent))
			{
				PrintFormat("[IAT_PersonalTent] Unable to read can deploy; short circuit.");
				return;
			}
        }
    }

	//================================================== CUSTOM CODE
	void TryFetchCanDeployPersonalTent()
	{
		// server side only check
		if (g_Game.IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(this, IAT_RPC_PERSONALTENT.UPDATE_CAN_PLACE_CLIENT, true, GetIdentity());
		}
	}
	//================================================== GETTERS & SETTERS
	bool IAT_CanDeployPersonalTent()
	{
		// we can deploy a personal tent if we
		// have not deployed one already
		return !m_IAT_CanDeployPersonalTent;
	}
	void IAT_SetCanDeployPersonalTent(bool canDeploy)
	{
		m_IAT_CanDeployPersonalTent = canDeploy;
	}

};