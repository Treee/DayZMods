modded class Hologram
{
  	override void EvaluateCollision(ItemBase action_item = null)
	{
		// do all the vanilla stuff
		super.EvaluateCollision(action_item);
		// turn on collision for shelter kits
		if (m_Projection.IsInherited(ShelterKit) && IsClippingRoof())
		{
			SetIsColliding(true);
		}// turn on collision for garden plots
		else if (m_Projection.IsInherited(GardenPlot) && IsCollidingGPlot())
		{
			SetIsColliding(true);
		}
		else // everything else can be built everywhere
		{
			SetIsColliding(false);
		}
	}

	override protected vector GetProjectionEntityPosition(PlayerBase player)
	{
		float minProjectionDistance;
		float maxProjectionDistance;
		m_ContactDir = vector.Zero;
		vector minMax[2];
		float projectionRadius = GetProjectionRadius();
		float cameraToPlayerDistance = vector.Distance(GetGame().GetCurrentCameraPosition(), player.GetPosition());

		if (projectionRadius < SMALL_PROJECTION_RADIUS) // objects with radius smaller than 1m
		{
			minProjectionDistance = SMALL_PROJECTION_RADIUS;
			maxProjectionDistance = SMALL_PROJECTION_RADIUS * 2;
		}
		else
		{
			minProjectionDistance = projectionRadius;
			maxProjectionDistance = projectionRadius * 2;
			maxProjectionDistance = Math.Clamp(maxProjectionDistance, SMALL_PROJECTION_RADIUS, LARGE_PROJECTION_DISTANCE_LIMIT);
		}

		vector from = GetGame().GetCurrentCameraPosition();
		vector to = from + (GetGame().GetCurrentCameraDirection() * (maxProjectionDistance + cameraToPlayerDistance));
		vector contactPosition;
		set<Object> hitObjects = new set<Object>();

		DayZPhysics.RaycastRV(from, to, contactPosition, m_ContactDir, m_ContactComponent, hitObjects, player, m_Projection, false, false, ObjIntersectFire);

		// bool contactHitProcessed = false;
		//! will not push hologram up when there is direct hit of an item
		// if (!CfgGameplayHandler.GetDisableIsCollidingBBoxCheck())
		// {
		// 	if (hitObjects.Count() > 0)
		// 	{
		// 		if (hitObjects[0].IsInherited(Watchtower))
		// 		{
		// 			contactHitProcessed = true;
		// 			contactPosition = CorrectForWatchtower(m_ContactComponent, contactPosition, player, hitObjects[0]);
		// 		}

		// 		if (!contactHitProcessed && hitObjects[0].IsInherited(InventoryItem))
		// 			contactPosition = hitObjects[0].GetPosition();
		// 	}
		// }

		static const float raycastOriginOffsetOnFail = 0.25;
		static const float minDistFromStart = 0.01;
		// Camera isn't correctly positioned in some cases, leading to raycasts hitting the object directly behind the camera
		if ((hitObjects.Count() > 0) && (vector.DistanceSq(from, contactPosition) < minDistFromStart))
		{
			from = contactPosition + GetGame().GetCurrentCameraDirection() * raycastOriginOffsetOnFail;
			DayZPhysics.RaycastRV(from, to, contactPosition, m_ContactDir, m_ContactComponent, hitObjects, player, m_Projection, false, false, ObjIntersectFire);
		}

		bool isFloating = SetHologramPosition(player.GetPosition(), minProjectionDistance, maxProjectionDistance, contactPosition);
		SetIsFloating(isFloating);

		#ifdef DIAG_DEVELOPER
		DrawDebugArrow(minProjectionDistance, maxProjectionDistance);
		if (DiagMenu.GetBool(DiagMenuIDs.MISC_HOLOGRAM))
		{
			Debug.DrawSphere(GetProjectionPosition(), 0.1, 0x99FF0000, ShapeFlags.ONCE|ShapeFlags.TRANSP|ShapeFlags.NOOUTLINE);
		}
		#endif

		m_FromAdjusted = from;

		return contactPosition;
	}
};