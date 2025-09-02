class IAT_Codelock_Colorbase extends ItemBase
{
	static ref ScriptInvoker SyncEvent_OnClientCodelockInfoUpdate = new ScriptInvoker();

	protected IAT_MenuType m_MenuType = -1; // the current menu type that is open for this codelock

	protected string m_Owner_SteamId; // steam id of the lock owner
	protected string m_Combination = "1234"; // default passcode for starters

	protected bool m_IsItemLocked; // is the code lock locked? this allows for temporary open/clos
	protected bool m_LastIsItemLocked; // tracks when the above value changes so we can sync to client only when necessary
	protected bool m_HasFetchedId = false; // relay switch to clamp rpcs to only 1 per codelock
	protected bool m_NeedsResyncPermissions = false; // used to trigger client to refetch codelock permissions

	protected float m_CodelockHealth; // hp of codelock for the UI display. hp is not normally synced to client so we have to provide that feature

	protected ref TStringArray m_Whitelist_SteamIds; // the list of approved steam ids for this codelock

	void IAT_Codelock_Colorbase()
	{
		RegisterNetSyncVariableBool("m_IsItemLocked");
		// auto toggle's back to false once signals to clients
		RegisterNetSyncVariableBoolSignal("m_NeedsResyncPermissions");
		RegisterNetSyncVariableFloat("m_CodelockHealth");
		m_Whitelist_SteamIds = new TStringArray();

		ProcessInvulnerabilityCheck(GetInvulnerabilityTypeString());
	}

	//========================================================== EVENTS
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		// we need a way to signal to our client that the locked state has changed so if any UI's are open
		// they can update the visuals accordingly
		if (m_LastIsItemLocked != m_IsItemLocked)
		{
			// if the state has change from last time
			// invoke the script invoker to update the codelock info
			SyncEvent_OnClientCodelockInfoUpdate.Invoke(this);
			m_LastIsItemLocked = m_IsItemLocked;
		}
	}

	// can only grab the codelock if it is unlocked
	override bool IsTakeable()
	{
		return !m_IsItemLocked;
	}

	override bool CanDetachAttachment (EntityAI parent)
	{
		return !m_IsItemLocked;
	}
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		// reset the codelock
		ClearCodelock();
		ClearWhitelist();
		FlagPermissionsToBeRechecked();
		SetSynchDirty();
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	override string GetInvulnerabilityTypeString()
	{
		return "disableBaseDamage";
	}

	//=============================================== CF MOD STORAGE
	#ifndef CF_MODSTORAGE
	override void OnStoreSave( ParamsWriteContext ctx )
	{
		// preserve order of call heiarchy
		super.OnStoreSave(ctx);
		// if we have a config
		if (GetDayZGame().GetIATCodelockConfig())
		{
			if (GetDayZGame().GetIATCodelockConfig().CanSaveCodelockDataToDatabase())
			{
				// write my value
				ctx.Write(m_Owner_SteamId);
				ctx.Write(m_Combination);
				ctx.Write(m_IsItemLocked);
				ctx.Write(m_Whitelist_SteamIds);
			}
		}
	}
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		// if existing db state is not loading correctly, fail out before our stuff (sanity check)
		if (!super.OnStoreLoad(ctx, version))
			return false;
		if (GetDayZGame().GetIATCodelockConfig())
		{
			if (GetDayZGame().GetIATCodelockConfig().CanSaveCodelockDataToDatabase())
			{
				// read the value serially
				if(!ctx.Read( m_Owner_SteamId ))
					return false;
				if(!ctx.Read( m_Combination ))
					return false;
				if(!ctx.Read( m_IsItemLocked ))
					return false;
				if(!ctx.Read( m_Whitelist_SteamIds ))
					return false;
			}
		}
		ServerUpdateSyncedCodelockHealth();
		SetSynchDirty();
		return true;
	}
	#endif
	#ifdef CF_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[IAT_Codelock];
		if (!ctx) return;

		if (GetDayZGame().GetIATCodelockConfig())
		{
			if (GetDayZGame().GetIATCodelockConfig().CanSaveCodelockDataToDatabase())
			{
				// write my value
				ctx.Write(m_Owner_SteamId);
				ctx.Write(m_Combination);
				ctx.Write(m_IsItemLocked);

				int whitelistCount = m_Whitelist_SteamIds.Count();
				ctx.Write(whitelistCount);
				for (int i = 0; i < whitelistCount; i++)
				{
					ctx.Write(m_Whitelist_SteamIds[i]);
				}
			}
		}
	}
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage)) return false;

		auto ctx = storage[IAT_Codelock];
		if (!ctx) return true;

		if (GetDayZGame().GetIATCodelockConfig())
		{
			if (GetDayZGame().GetIATCodelockConfig().CanSaveCodelockDataToDatabase())
			{
				if(!ctx.Read( m_Owner_SteamId ))
					return false;
				if(!ctx.Read( m_Combination ))
					return false;
				if(!ctx.Read( m_IsItemLocked ))
					return false;

				int whitelistCount;
				if(!ctx.Read( whitelistCount ))
					return false;

				string whitelistId;
				for (int i = 0; i < whitelistCount; i++)
				{
					if (!ctx.Read(whitelistId))
						return false;

					m_Whitelist_SteamIds.Insert(whitelistId);
				}
			}
		}
		ServerUpdateSyncedCodelockHealth();
		SetSynchDirty();
		return true;
	}
	#endif

	override void SetActions()
	{
		super.SetActions();
		// ActionAttach is already on itembase which handles all the others that have a codelock attachment

		AddAction(IAT_ActionAttachToBaseBuilding); // basebuildings with a codelock attachment
		AddAction(IAT_ActionAttachToTent); // tents with a codelock attachment
	}

	//================================================== RPC'S
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        switch (rpc_type)
        {
            case IAT_RPC_Codelock.UPDATE_OWNER: // server side update to all players
                HandleOnClientServerUpdateOwner(null, ctx);
				break;
			case IAT_RPC_Codelock.UPDATE_OWNER_CLIENT: // server side update to specific player
				HandleOnClientServerUpdateOwner(sender, ctx);
				break;
			case IAT_RPC_Codelock.UPDATE_LOCK_STATE_CLIENT: // client side telling server to toggle lock
				ToggleLock();
				break;
			case IAT_RPC_Codelock.UPDATE_PASSCODE_CLIENT: // client side telling server to change the passcode
				HandleOnServerUpdatePassword(ctx);
				break;
			case IAT_RPC_Codelock.UPDATE_WHITELIST: // server side telling client to update whitelist
				HandleOnServerUpdateWhitelist();
				break;
			case IAT_RPC_Codelock.ENTER_PASSCODE_CLIENT: // client side telling server to enter the passcode
				HandleOnServerEnterPasscode(sender, ctx);
            	break;
			case IAT_RPC_Codelock.CLEAR_WHITELIST: // server side telling client that whitelist has been changed
				ClearWhitelist();
				break;
        }
        super.OnRPC(sender, rpc_type, ctx);
    }
	// meant to be used first time a lock is interacte with by a player
	void HandleOnClientServerUpdateOwner(PlayerIdentity sender, ParamsReadContext ctx)
	{
		if (GetGame().IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(GetOwnerId());
			rpc.Write(GetCombination());
			rpc.Write(GetHealth());
			rpc.Write(m_Whitelist_SteamIds);
			rpc.Send(this, IAT_RPC_Codelock.UPDATE_OWNER_CLIENT, true, sender);
			return;
		}
		// handle the rpc on the client side
		HandleOnServerUpdateOwner(ctx);
	}
	// client side function to set owner of codelock
    void HandleOnServerUpdateOwner(ParamsReadContext ctx)
    {
		// client only
        if (!GetGame().IsDedicatedServer())
        {
			// if we run into issues deserializing the data
			if (!ctx.Read(m_Owner_SteamId))
			{
				PrintFormat("[IAT_Codelock] Unable to read owner; short circuit. Codelock Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(m_Combination))
			{
				PrintFormat("[IAT_Codelock] Unable to read passcode; short circuit. Codelock Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(m_CodelockHealth))
			{
				PrintFormat("[IAT_Codelock] Unable to read current health; short circuit. Codelock Position: %1", GetPosition());
				return;
			}
			if (!ctx.Read(m_Whitelist_SteamIds))
			{
				PrintFormat("[IAT_Codelock] Unable to read whitelist; short circuit. Codelock Position: %1", GetPosition());
				return;
			}
        }
    }
	// server side function to update the passcode
    void HandleOnServerUpdatePassword(ParamsReadContext ctx)
    {
		// server only
        if (GetGame().IsDedicatedServer())
        {
			// if we run into issues deserializing the data
			if (!ctx.Read(m_Combination))
			{
				PrintFormat("[IAT_Codelock] Unable to set new passcode; short circuit. Codelock Position: %1", GetPosition());
				return;
			}
			ClearWhitelist();
			FlagPermissionsToBeRechecked();
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(this, IAT_RPC_Codelock.CLEAR_WHITELIST, true, null);
        }
    }
	// client side function to try and open the codelock with a passcode
    void HandleOnServerEnterPasscode(PlayerIdentity sender, ParamsReadContext ctx)
    {
		// server only
        if (GetGame().IsDedicatedServer())
        {
			string clientPasscode;
			// if we run into issues deserializing the data
			if (!ctx.Read(clientPasscode))
			{
				PrintFormat("[HandleOnServerEnterPasscode] Unable to apply client passcode; short circuit. Codelock Position: %1", GetPosition());
				return;
			}
			TryAddWhiteList(sender, clientPasscode);
        }
    }
	// client side function to update the whitelist
	void HandleOnServerUpdateWhitelist()
	{
		if (!GetGame().IsDedicatedServer())
		{
			AddNewWhitelistId(GetGame().GetPlayer().GetIdentity().GetPlainId());
		}
	}
	// client UI function to toggle the loc
	void ClientRPC_ToggleLock()
	{
		if (!GetGame().IsDedicatedServer())
		{
			// script rpc to server to toggle the lock
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(this, IAT_RPC_Codelock.UPDATE_LOCK_STATE_CLIENT, true, GetGame().GetPlayer().GetIdentity());
		}
	}
	// client UI function to change the passcode
	void ClientRPC_ChangePasscode(string newPasscode)
	{
		if (!GetGame().IsDedicatedServer())
		{
			// script rpc to server to change the passcode
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(newPasscode);
			rpc.Send(this, IAT_RPC_Codelock.UPDATE_PASSCODE_CLIENT, true, GetGame().GetPlayer().GetIdentity());
		}
	}
	void ClientRPC_EnterPassword(string clientPasscode)
	{
		if (!GetGame().IsDedicatedServer())
		{
			// script rpc to server to change the passcode
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(clientPasscode);
			rpc.Send(this, IAT_RPC_Codelock.ENTER_PASSCODE_CLIENT, true, GetGame().GetPlayer().GetIdentity());
		}
	}
	//========================================================== CUSTOM CODE
	void AssignLockTo(string playerIdentity)
	{
		m_Owner_SteamId = playerIdentity;
		m_IsItemLocked = true;
		m_NeedsResyncPermissions = true;

		ServerUpdateSyncedCodelockHealth();
		// script rpc to client this information
		PushOwnerIdToClients();
		// propogate update to client for other information
		SetSynchDirty();
	}
	// meant to be sent to all client on first creation
    void PushOwnerIdToClients()
    {
		// server side only
        if (GetGame().IsDedicatedServer())
        {
			// write the new owner id to the context
            ScriptRPC rpc = new ScriptRPC();
			rpc.Write(GetOwnerId());
			rpc.Write(GetCombination());
			rpc.Write(GetHealth());
			rpc.Write(m_Whitelist_SteamIds);
			// send the rpc to this item on the other side
            rpc.Send(this, IAT_RPC_Codelock.UPDATE_OWNER, true, null);
        }
    }
	void TryFetchOwnerId(PlayerIdentity invokingPlayer)
	{
		// client only
		if (!GetGame().IsDedicatedServer())
		{
			// if we do not need to resync permissions, check if we can short circuit
			// permissions need to be synced when changing password, and clearing whitelist
			if (!m_NeedsResyncPermissions)
			{
				// if the owner id exists on the client or is not locked
				if (m_Owner_SteamId || !m_IsItemLocked)
					return;
				// if we have already fetched the id before
				if (m_HasFetchedId)
					return;
			}
			else
			{
				// we know we need to sync the permissions, do so and retoggle flag to false
				m_NeedsResyncPermissions = false;
			}

			// debouncer so we dont burst send rpcs due to network lag
			m_HasFetchedId = true;
			// get the id from the server
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(this, IAT_RPC_Codelock.UPDATE_OWNER_CLIENT, true, invokingPlayer);
		}
	}
	void TryAddWhiteList(PlayerIdentity invokingPlayer, string passcode)
	{
		// server side check!
		if (GetGame().IsDedicatedServer())
		{
			if (IsCorrectPasscode(passcode))
			{
				OnSuccessfulPasscodeEntry(invokingPlayer);
			}
			else
			{
				OnFailedPasscodeEntry(invokingPlayer);
			}
		}
	}
	void ClearWhitelist()
	{
		if (m_Whitelist_SteamIds)
		{
			m_Whitelist_SteamIds.Clear();
		}
	}
	void FlagPermissionsToBeRechecked()
	{
		m_NeedsResyncPermissions = true;
		SetSynchDirty();
	}
	bool HasAccess(PlayerIdentity playerIdentity)
	{
		string steamId = playerIdentity.GetPlainId();
		TryFetchOwnerId(playerIdentity);
		if (IsTempOpen())
		{
			return true;
		}
		else if (IsOwner(steamId))
		{
			return true;
		}
		else if (IsWhitelisted(steamId))
		{
			return true;
		}
		else if (IsCodelockAdmin(steamId))
		{
			return true;
		}
		return false;
	}
	bool IsOwner(string steamId)
	{
		return m_Owner_SteamId == steamId;
	}
	bool IsWhitelisted(string steamId)
	{
		foreach(string id : m_Whitelist_SteamIds)
		{
			if (id == steamId)
			{
				return true;
			}
		}
		return false;
	}
	bool IsTempOpen()
	{
		// TODO: add ability to open the codelock publicly for some time
		return false;
	}
	bool IsCodelockAdmin(string steamId)
	{
		#ifdef VPPADMINTOOLS
		// client side check (for the action server check is the real check)
		if (!GetGame().IsDedicatedServer())
		{
			MissionBaseWorld mission;
			if (Class.CastTo(mission, GetGame().GetMission()))
			{
				// if the vpp tools are toggled
				if (mission.VPPAT_AdminToolsToggled())
				{
					return true;
				}
			}
		}
		// there is no real "easy" way to check on the server if the tools have been toggled on by an admin
		// because its all RPCs for some reason
		// else
		// {
		// 	// this is to check on the server for "actual" permissions whehn client side is just looking for open tools
		// 	PermissionManager permissionManager;
		// 	if (Class.CastTo(permissionManager, GetPermissionManager()))
		// 	{
		// 		if (permissionManager.IsSuperAdmin(steamId))
		// 		{
		// 			return true;
		// 		}
		// 		UserGroup userGroup;
		// 		if (Class.CastTo(userGroup, permissionManager.GetUserGroup(steamId)))
		// 		{
		// 			if (userGroup.GetGroupName() == "Admins")
		// 			{
		// 				return true;
		// 			}
		// 		}
		// 	}
		// }
		#endif

		#ifdef JM_COT
		return GetCommunityOnlineToolsBase().IsActive();
		#endif

		return false;
	}
	void ToggleLock()
	{
		// server specific code
		if (GetGame().IsDedicatedServer())
		{
			// flip the bool each time this is called
			SetIsLocked(!IAT_IsLocked());
			// sync
			SetSynchDirty();
		}
		else
		{
			// client specific code
			ClientRPC_ToggleLock();
		}
	}
	bool IsCorrectPasscode(string passcode)
	{
		return m_Combination == passcode;
	}
	void OnSuccessfulPasscodeEntry(PlayerIdentity playerIdentity)
	{
		AddNewWhitelistId(playerIdentity.GetPlainId());
		// server send rpc to client to add this id into whitelist
		ScriptRPC rpc = new ScriptRPC();
		// send the rpc to this item on the other side
		rpc.Send(this, IAT_RPC_Codelock.UPDATE_WHITELIST, true, playerIdentity);
	}
	void OnFailedPasscodeEntry(PlayerIdentity playerIdentity)
	{
		DamagePlayer(playerIdentity);
	}
	void OpenCodelockManagerMenu()
	{
		// client only;
		if (!GetGame().IsDedicatedServer())
		{
			m_MenuType = IAT_MenuType.CODELOCK_MANAGER;
			GetGame().GetMission().OnItemUsed(this, GetGame().GetPlayer());
		}
	}
	void OpenPasscodeEntryMenu()
	{
		// client only;
		if (!GetGame().IsDedicatedServer())
		{
			m_MenuType = IAT_MenuType.PASSCODE_ENTRY;
			GetGame().GetMission().OnItemUsed(this, GetGame().GetPlayer());
		}
	}
	void AddNewWhitelistId(string steamId)
	{
		if (!m_Whitelist_SteamIds)
		{
			m_Whitelist_SteamIds = new TStringArray();
		}
		m_Whitelist_SteamIds.Insert(steamId);
	}
	void PerformRaidDamage(int toolDamage, bool deleteLock = false)
	{
		// server side only
		if (GetGame().IsDedicatedServer())
		{
			// remove hp
			AddHealth(-toolDamage);
			// if the item is below 0 hp
			if (GetHealth() <= 0)
			{
				// if we are NOT deleting the lock
				if (!deleteLock)
				{
					//spawn a new one on the ground, central economy setup but no lifetime or persistency until player brings to hands
					GetGame().CreateObjectEx(GetType(), GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
				}
				DeleteSafe();
			}
		}
	}
	void ServerUpdateSyncedCodelockHealth()
	{
		if (GetGame().IsDedicatedServer())
		{
			m_CodelockHealth = GetHealth();
		}
	}
	void DamagePlayer(PlayerIdentity playerIdentity)
	{
		if (GetGame().IsDedicatedServer())
		{
			// if we have a config
			if (GetDayZGame().GetIATCodelockConfig())
			{
				// if we allow damage on failed passcode entry
				if (GetDayZGame().GetIATCodelockConfig().CanDamagePlayerOnFailedPasscodeEntry())
				{
					PlayerBase player;
					if (Class.CastTo(player, playerIdentity.GetPlayer()))
					{
						// get the damage amount from the config
						int playerDamage = GetDayZGame().GetIATCodelockConfig().GetDamagePerFailedPasscodeEntry();
						// apply it to the character
						player.AddHealth(-playerDamage);
						// increment the failed passcode entry attempts
						player.AddFailedCodelockEntryAttempt(1);
						// reset the cooldown since we just failed a passcode entry
						player.ResetPasscodeEntryAttemptsCooldown();
					}
				}
			}
		}
	}
	void ClearCodelock()
	{
		m_Owner_SteamId = "unowned";
		m_Combination = "1234";
		m_IsItemLocked = false;
	}

	//========================================================== SETTERS & SETTERS
	bool IAT_IsLocked()
	{
		return m_IsItemLocked;
	}
	void SetIsLocked(bool newState)
	{
		m_IsItemLocked = newState;
	}
	string GetCombination()
	{
		return m_Combination;
	}
	// not really used
	void SetCombination(string newState)
	{
		m_Combination = newState;
	}
	string GetOwnerId()
	{
		return m_Owner_SteamId;
	}
	IAT_MenuType GetMenuType()
	{
		return m_MenuType;
	}
	float GetSyncedCodelockHealth()
	{
		return m_CodelockHealth;
	}
};
class IAT_Codelock_Basic extends IAT_Codelock_Colorbase{};
class IAT_Codelock_Painted extends IAT_Codelock_Colorbase{};
class IAT_Codelock_DebugNoOwner extends IAT_Codelock_Colorbase
{
	override void AssignLockTo(string playerIdentity)
	{
		// debug code for testing as a solo player
		super.AssignLockTo("TEST_STEAMID");
	}
};
