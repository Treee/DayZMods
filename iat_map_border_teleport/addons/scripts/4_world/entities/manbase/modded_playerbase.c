modded class PlayerBase
{
	protected vector m_IAT_LastPlayerPosition = "0 0 0";
	protected bool m_IAT_HasSentMessage = false;
	const int IAT_STEP_MOD_COUNT = 5;
	const int IAT_MAP_BOUNDARY_1 = 50;
	const int IAT_MAP_BOUNDARY_2 = 20;

	override void TryTeleportOutOfBoundsPlayer(int stepCounter)
	{
		// if we are near the edge
		if (IsNearMapEdge(IAT_MAP_BOUNDARY_1))
		{
			int modStepCounter = 0;
			// if we are closer to the edge
			if (IsNearMapEdge(IAT_MAP_BOUNDARY_2))
			{
				// if we are outside the bounds
				// we check this first because we dont want to reset player position in this chain of bools
				if (IsNearMapEdge(-1))
				{
					SetPosition(m_IAT_LastPlayerPosition);
					// teleport
					GetGame().RPCSingleParam(this, ERPCs.RPC_WARNING_TELEPORT, null, true, GetIdentity());

					PluginAdminLog adminLog = PluginAdminLog.Cast(GetPlugin(PluginAdminLog));
					if (adminLog)
						adminLog.PlayerTeleportedLog(this, GetPosition(), m_IAT_LastPlayerPosition, "Player is out of map boundaries.");

				}
				// if we are literally on the edge of the map
				else if (IsNearMapEdge(1))
				{
					// save the position so we can teleport back to it
					m_IAT_LastPlayerPosition = GetPosition();
				}
				else // we are not outside the bounds but atleast 10m away
				{
					modStepCounter = stepCounter % IAT_STEP_MOD_COUNT;
					if (modStepCounter == 0 || !m_IAT_HasSentMessage)
					{
						// imminent warning
						MessageAction("You are VERY close to the edge of the map. Turn around now or be teleported.");
						m_IAT_HasSentMessage = true;
					}
				}
			}
			else // we are near the edge of the map but between 10m and 100m
			{
				modStepCounter = stepCounter % IAT_STEP_MOD_COUNT;
				if (modStepCounter == 0 || !m_IAT_HasSentMessage)
				{
					// warning
					MessageAction("You are close to the edge of the map, turn around soon.");
					m_IAT_HasSentMessage = true;
				}
			}
		}
	}

	// simple check to see if player is less than 0 or more than WorldSize
	// offset allows me to differentiate distance to teleport
	bool IsNearMapEdge(int offset)
	{
		// original values
		vector playerPosition = GetPosition();

		// add some buffer to the check so we can inform the player BEFORE they are out of bounds
		int worldSizeOffset = GetGame().GetWorld().GetWorldSize() - offset;

		// add some buffer to the check so we can inform the player BEFORE they are out of bounds
		int zeroOffset = 0 + offset;
		// bottom left or right OR top left or top right
		if (playerPosition[0] < zeroOffset || playerPosition[2] < zeroOffset || playerPosition[0] > worldSizeOffset || playerPosition[2] > worldSizeOffset)
		{
			return true;
		}
		return false;
	}
};