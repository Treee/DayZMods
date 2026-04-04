class IAT_PersonalTent_ColorBase extends ALV_Deployable_Base
{
	protected string m_IAT_OwnerId = "";
	protected bool m_IAT_HasFetchedId = false;

	// set the tent owner when this thing is placed
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		// Cast to player base to get access to the identity
		PlayerBase pb_Player;
		if (Class.CastTo(pb_Player, player))
		{
			// set the player to the owner since he placed the tent
			IAT_SetTentOwner(pb_Player.GetIdentity());
			pb_Player.IAT_SetCanDeployPersonalTent(false);
		}
	};
	// helper bool to determine if the invoking player can actually open storage
	bool IAT_CanOpenPersonalTent(PlayerIdentity invokingPlayer)
	{
		// if we can open this tent
		if (super.CanBeOpened())
		{
			// check if this tent is owned by invoking player
			if (IAT_IsPersonalTentOwner(invokingPlayer))
			{
				return true;
			}
		}
		return false;
	};
	// check if the invoking player is the owner of the tent
	bool IAT_IsPersonalTentOwner(PlayerIdentity invokingPlayer)
	{
		// owner is empty (client side)
		// server should never be empty
		if (m_IAT_OwnerId == "")
		{
			// fetch the id
			IAT_TryFetchOwnerId(invokingPlayer);
			// no id so not the owner (yet possibly)
			return false;
		}
		// if the invoking player IS the owner
		if (m_IAT_OwnerId == invokingPlayer.GetPlainId())
		{
			// return true
			return true;
		}
		// false catch all
		return false;
	}
	// set the owner of this tent
	void IAT_SetTentOwner(PlayerIdentity invokingPlayer)
	{
		m_IAT_OwnerId = invokingPlayer.GetPlainId();
	}
	// get the owner id if we havent tried already
	void IAT_TryFetchOwnerId(PlayerIdentity invokingPlayer)
	{
		// restrict this call to client side only
		if (!g_Game.IsDedicatedServer())
		{
			// if the owner of this thing is empty (first client load)
			if (m_IAT_OwnerId == "")
			{
				// if we have not sent an rpc already
				if (!m_IAT_HasFetchedId)
				{
					// debouncer so we dont burst send rpcs due to network lag
					m_IAT_HasFetchedId = true;
					// get the id from the server
					ScriptRPC rpc = new ScriptRPC();
					rpc.Send(this, IAT_RPC_PERSONALTENT.UPDATE_OWNER_CLIENT, true, invokingPlayer);
				}
			}
		}
	}
	// server side tent registry to ensure only 1 tent per player
	void IAT_RegisterWithTentManager()
	{
		if (g_Game.IsDedicatedServer())
		{
			IAT_TentManager tentManager;
			if (Class.CastTo(tentManager, GetDayZGame().IAT_GetTentManager()))
			{
				tentManager.IAT_RegisterOwner(m_IAT_OwnerId);
			}
		}
	}
	// server side tent registry to ensure only 1 tent per player
	void IAT_UnRegisterWithTentManager()
	{
		if (g_Game.IsDedicatedServer())
		{
			IAT_TentManager tentManager;
			if (Class.CastTo(tentManager, GetDayZGame().IAT_GetTentManager()))
			{
				tentManager.IAT_UnRegisterOwner(m_IAT_OwnerId);
			}
		}
	}
	//================================================== RPC'S
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
			case IAT_RPC_PERSONALTENT.UPDATE_OWNER_CLIENT: // server side update to specific player
				IAT_ClientRequestOwnerId(sender, ctx);
				break;
        }
        super.OnRPC(sender, rpc_type, ctx);
    }

	// meant to be used first time a player tries to open a personal tent
	void IAT_ClientRequestOwnerId(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (g_Game.IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(m_IAT_OwnerId);
			rpc.Send(this, IAT_RPC_PERSONALTENT.UPDATE_OWNER_CLIENT, true, sender);
			return;
		}
		// handle the rpc on the client side
		IAT_ClientReadOwnerIdResponse(ctx);
	}
	// client side function to set owner of codelock
    void IAT_ClientReadOwnerIdResponse(ParamsReadContext ctx)
    {
		// client only
        if (!g_Game.IsDedicatedServer())
        {
			// if we run into issues deserializing the data
			if (!ctx.Read(m_IAT_OwnerId))
			{
				PrintFormat("[IAT_PersonalTent] Unable to read owner; short circuit. Tent Position: %1", GetPosition());
				return;
			}
        }
    }

	//=============================================== CF MOD STORAGE
	#ifndef CF_MODSTORAGE
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// preserve order of call heiarchy
		super.OnStoreSave(ctx);
		// write my value
		ctx.Write(m_IAT_OwnerId);
	}
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		// if existing db state is not loading correctly, fail out before our stuff (sanity check)
		if (!super.OnStoreLoad(ctx, version))
			return false;

		// read the value serially
		if(!ctx.Read( m_IAT_OwnerId ))
			return false;

		// register this tent with the tent manger
		IAT_RegisterWithTentManager();
		return true;
	}
	#endif
	#ifdef CF_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[IAT_ALV_PersonalTent_Scripts];
		if (!ctx) return;

		// write my value
		ctx.Write(m_IAT_OwnerId);

	}
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage)) return false;

		auto ctx = storage[IAT_ALV_PersonalTent_Scripts];
		if (!ctx) return true;


		if(!ctx.Read( m_IAT_OwnerId ))
			return false;

		// register this tent with the tent manger
		IAT_RegisterWithTentManager();
		return true;
	}
	#endif

};