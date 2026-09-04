class IAT_PluginMapBoundary extends PluginBase
{
	/*
	* Precomputed values so we do not have to do the calculations each set interval
	*/
	protected int m_WorldSizeX;
	protected int m_WorldSizeY;

	// Initialize variables
	override void OnInit()
	{
		super.OnInit();

		m_WorldSizeX = g_Game.GetWorld().GetWorldSize() - GameConstants.IAT_MDT_MAP_OFFSET_X;
		m_WorldSizeY = g_Game.GetWorld().GetWorldSize() - GameConstants.IAT_MDT_MAP_OFFSET_Y;
	}

	// Return the closest edge distance to the player
	protected float GetDistanceToEdge(vector position)
	{
		float left   = position[0];
		float right  = m_WorldSizeX - position[0];

		float bottom = position[2];
		float top    = m_WorldSizeY - position[2];

		float nearest = Math.Min(left, right);
		nearest = Math.Min(nearest, bottom);
		nearest = Math.Min(nearest, top);

		return nearest;
	}

	/*
	* Teleport the player given a new position
	*/
	protected void TeleportPlayer(PlayerBase player, vector position)
	{
		player.SetPosition(position);

		g_Game.RPCSingleParam(player, ERPCs.RPC_WARNING_TELEPORT, null, true, player.GetIdentity());

		PluginAdminLog adminLog;
		if (Class.CastTo(adminLog, GetPlugin(PluginAdminLog)))
		{
			adminLog.PlayerTeleportedLog(player, player.GetPosition(), position, "Player is out of map boundaries.");
		}
	}

	// Return the normalized value (0-1) of the closest edge to the player
	float GetEdgeFactor(vector position, float warningDistance)
	{
		float distance = GetDistanceToEdge(position);

		return Math.Clamp((warningDistance - distance) / warningDistance, 0, 1);
	}

	float GetSafeHeading(vector position)
	{
		vector steer = GetSteeringVector(position, GameConstants.IAT_MDT_WARNING_DISTANCE);
		return Math.Atan2(steer[0], steer[2]);
	}

	protected vector GetSteeringVector(vector position, float warningDistance)
	{
		float left   = position[0];
		float right  = m_WorldSizeX - position[0];
		float bottom = position[2];
		float top    = m_WorldSizeY - position[2];

		vector steer = "0 0 0";
		float weight = 0.0;

		if (left < warningDistance)
		{
			weight = 1.0 - (left / warningDistance);
			steer += Vector(1,0,0) * Math.Pow(weight, 2);
		}

		if (right < warningDistance)
		{
			weight = 1.0 - (right / warningDistance);
			steer += Vector(-1,0,0) * Math.Pow(weight, 2);
		}

		if (bottom < warningDistance)
		{
			weight = 1.0 - (bottom / warningDistance);
			steer += Vector(0,0,1) * Math.Pow(weight, 2);
		}

		if (top < warningDistance)
		{
			weight = 1.0 - (top / warningDistance);
			steer += Vector(0,0,-1) * Math.Pow(weight, 2);
		}

		steer.Normalize();
		return steer;
	}

	// vector GetInwardNormal(vector position)
	// {
	// 	float left   = position[0];
	// 	float right  = m_WorldSizeX - position[0];

	// 	float bottom = position[2];
	// 	float top    = m_WorldSizeY - position[2];

	// 	float nearest = left;
	// 	vector normal = "1 0 0"; // Left edge -> push East

	// 	if (right < nearest)
	// 	{
	// 		nearest = right;
	// 		normal = "-1 0 0"; // Right edge -> push West
	// 	}

	// 	if (bottom < nearest)
	// 	{
	// 		nearest = bottom;
	// 		normal = "0 0 1"; // Bottom edge -> push North
	// 	}

	// 	if (top < nearest)
	// 	{
	// 		nearest = top;
	// 		normal = "0 0 -1"; // Top edge -> push South
	// 	}

	// 	return normal;
	// }
	/*
	* Return a bool indicating if the player should be teleported.
	* Distance must be less than 0 from the edge to yield a true falue.
	*/
	bool ShouldTeleport(vector position)
	{
		return GetDistanceToEdge(position) < 0;
	}

	void CheckPlayer(PlayerBase player, int stepCounter)
	{
		float distance = GetDistanceToEdge(player.GetPosition());

		if(distance < 0) // We are at true map edge
		{
			TeleportPlayer(player, player.IAT_MBT_GetLastSafePosition());
		}
		else if(distance < GameConstants.IAT_MDT_CRITICAL_DISTANCE) // We are at the last warning point
		{
			if (distance > 1 && distance < 2) // We are at the point of no return, right before teleport
			{
				player.IAT_MBT_SaveLastSafePosition();
			}
			if(stepCounter % GameConstants.IAT_MDT_STEP_MOD_COUNT == 0)
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Map Boundary", "You are VERY close to the edge of the map. Turn around now or you will be forced back.", "set:ccgui_enforce image:Icon40Emergency");
			}
		}
		else if(distance < GameConstants.IAT_MDT_WARNING_DISTANCE) // We are at the first warning point
		{
			if(stepCounter % GameConstants.IAT_MDT_STEP_MOD_COUNT == 0)
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Map Boundary", "You are close to the edge of the map. Please turn around now.", "set:ccgui_enforce image:Icon40Emergency");
			}
		}
	}
};