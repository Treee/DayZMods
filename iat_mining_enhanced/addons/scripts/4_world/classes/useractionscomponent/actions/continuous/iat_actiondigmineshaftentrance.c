class IAT_ActionDigMineShaftEntranceCB : ActiondeployObjectCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_GARDEN);
	}
};

class IAT_ActionDigMineShaftEntrance: ActionDeployObject
{
	IAT_MiningSegment_Colorbase m_MiningEntrance;

	void IAT_ActionDigMineShaftEntrance()
	{
		m_CallbackClass	= IAT_ActionDigMineShaftEntranceCB;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;

		m_Text = "Dig Mine Shaft";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		//Client
		if (!GetGame().IsDedicatedServer())
		{
			//Action not allowed if player has broken legs
			if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
				return false;

			if (player.IsPlacingLocal())
			{
				Hologram hologram = player.GetHologramLocal();
				IAT_MiningSegment_Colorbase itemSegmentEntrance;
				Class.CastTo(itemSegmentEntrance,  hologram.GetProjectionEntity());
				CheckSurfaceBelowSegment(player, itemSegmentEntrance, hologram);

				if (!hologram.IsColliding())
				{
					return true;
				}
			}
			return false;
		}
		//Server
		return true;
	}

	override void SetupAnimation(ItemBase item)
	{
		if (item)
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
		}
	}

	void CheckSurfaceBelowSegment(PlayerBase player, IAT_MiningSegment_Colorbase itemSegmentEntrance, Hologram hologram)
	{
		vector min_max[2];
		itemSegmentEntrance.GetCollisionBox(min_max);
		float offset = min_max[1][1] - min_max[0][1];
		//Print(offset);
		vector pos_adjusted = itemSegmentEntrance.GetPosition();
		pos_adjusted[1] = pos_adjusted[1] + offset;

		if (itemSegmentEntrance.CanBePlaced(player, /*itemSegmentEntrance.GetPosition()*/pos_adjusted) )
		{
			if (itemSegmentEntrance.CanBePlaced(NULL, itemSegmentEntrance.CoordToParent(hologram.GetLeftCloseProjectionVector())))
			{
				if (itemSegmentEntrance.CanBePlaced(NULL, itemSegmentEntrance.CoordToParent(hologram.GetRightCloseProjectionVector())))
				{
					if (itemSegmentEntrance.CanBePlaced(NULL, itemSegmentEntrance.CoordToParent(hologram.GetLeftFarProjectionVector())))
					{
						if (itemSegmentEntrance.CanBePlaced(NULL, itemSegmentEntrance.CoordToParent(hologram.GetRightFarProjectionVector())))
						{
							hologram.SetIsCollidingGPlot(false);

							return;
						}
					}
				}
			}
		}

		hologram.SetIsCollidingGPlot(true);
	}

	override void DropDuringPlacing(PlayerBase player)
	{
	}

	override void OnFinishProgressClient(ActionData action_data)
	{
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		poActionData.m_AlreadyPlaced = true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		EntityAI entity_for_placing = action_data.m_MainItem;
		vector position = action_data.m_Player.GetLocalProjectionPosition();
		vector orientation = action_data.m_Player.GetLocalProjectionOrientation();

		if (GetGame().IsMultiplayer())
		{
			m_MiningEntrance = IAT_MiningSegment_Colorbase.Cast(action_data.m_Player.GetHologramServer().PlaceEntity(entity_for_placing));
			m_MiningEntrance.SetOrientation(orientation);
			action_data.m_Player.GetHologramServer().CheckPowerSource();
			action_data.m_Player.PlacingCompleteServer();

			m_MiningEntrance.OnPlacementComplete(action_data.m_Player);
		}

		//local singleplayer
		if (!GetGame().IsMultiplayer())
		{
			m_MiningEntrance = IAT_MiningSegment_Colorbase.Cast(action_data.m_Player.GetHologramLocal().PlaceEntity(entity_for_placing));
			m_MiningEntrance.SetOrientation(orientation);
			action_data.m_Player.PlacingCompleteServer();
			action_data.m_Player.PlacingCompleteLocal();

			m_MiningEntrance.OnPlacementComplete(action_data.m_Player);
		}

		GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
		action_data.m_MainItem.SetIsBeingPlaced(false);
		poActionData.m_AlreadyPlaced = true;




		// // truncate the entrace position vector so we have nice smooth numbers in the config
		// vector truncatedPos = MiscGameplayFunctions.TruncateVec(action_data.m_Target.GetCursorHitPos(), 0);

		// // check to see if we have anything nearby
		// IAT_MiningConfig miningConfig;
		// if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		// {
		// 	// if we can place the entrance here
		// 	if (miningConfig.CanPlaceEntrance(truncatedPos))
		// 	{
		// 		// spawn the entrance
		// 		IAT_MiningSegment_Colorbase miningEntrance;
		// 		if (Class.CastTo(miningEntrance, GetGame().CreateObjectEx("land_iat_miningsegment_entrance", truncatedPos, ECE_SETUP|ECE_PLACE_ON_SURFACE)))
		// 		{
		// 			miningEntrance.OnServerMineEntranceCreated(action_data.m_Player.GetPosition(), miningEntrance.GetPosition());
		// 			MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 35);
		// 		}
		// 	}
		// }
		// else
		// {
		// 	// TODO: On failed creation make some particles or sound?
		// 	NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Entrance Nearby", "There is another mining entrance within 100m of this position.", "set:ccgui_enforce image:Icon40Emergency");
		// }


		// MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 10);

	}
};
