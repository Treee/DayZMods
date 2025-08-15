modded class MiscGameplayFunctions
{
	// straight copy of vanillas teleport check. needed to remove the RPC menu warning
	static void IAT_Mining_TeleportCheck(PlayerBase player, vector safe_position)
	{
		vector player_pos = player.GetPosition();

		if (player_pos != safe_position)
		{
			player.SetPosition( safe_position );

			PluginAdminLog adminLog = PluginAdminLog.Cast(GetPlugin(PluginAdminLog));
			if (adminLog)
				adminLog.PlayerTeleportedLog(player, player_pos,safe_position, "IAT_Mining_Teleport");
		}
	}
};