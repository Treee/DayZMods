modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATItemBlacklistConfig(GetDayZGame().GetIATItemBlacklistConfig());
	}

	// player is joining so check to see if they have any illegal items
	// (this handles cases where people try to circumvent this system)
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player, identity);
		IAT_RemoveBlacklistedItems(player);
	}

	// player is leaving correctly so remove any illegal items
	override void OnClientDisconnectedEvent(PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed)
	{
		// do stuff before the player object is wrecked by vanilla
		IAT_RemoveBlacklistedItems(player);
		super.OnClientDisconnectedEvent(identity, player, logoutTime, authFailed);
	}

	// missionServer is only called on server side so i am safe to have no client/server checks here
	void IAT_RemoveBlacklistedItems(PlayerBase player)
	{
		// null guard check
		if (!player)
		{
			return;
		}
		// if our config exists
		IAT_ItemBlacklistConfig blacklistConfig;
		if (Class.CastTo(blacklistConfig, GetDayZGame().GetIATItemBlacklistConfig()))
		{
			// premake my object
			array<EntityAI> itemsArray = new array<EntityAI>;
			// get all the items on this player
			player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
			// for each item on the player
			foreach (EntityAI item : itemsArray)
			{
				if (blacklistConfig.IsItemBlacklisted(item.GetType()))
				{
					PrintFormat("[IAT_ItemBlacklistConfig]=========Deleting Item: %1 from Player: %2 with ID: %3", item.GetType(), player.GetIdentity().GetPlainName(), player.GetIdentity().GetPlainId());
					item.DeleteSafe();
				}
			}
		}
	}
};