class IAT_ActionCreateMineShaftCB extends ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent = UATimeSpent.BURY_BODY;

		if (m_ActionData.m_Player.GetInColdArea())
			time_spent *= GameConstants.COLD_AREA_DIG_WORMS_MODIF;

		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

class IAT_ActionCreateMineShaft extends ActionContinuousBase
{
	void IAT_ActionCreateMineShaft()
	{
		m_CallbackClass = IAT_ActionCreateMineShaftCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGGIN_WORMS;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "Dig Mine Shaft";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
	}

	override bool Can(PlayerBase player, ActionTarget target, ItemBase item, int condition_mask)
	{
		if (!super.Can(player, target, item, condition_mask))
			return false;

		return player.CheckFreeSpace(vector.Forward, 0.8, false);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.IsPlacingLocal())
			return false;

		if (!IsTargetFertile(target))
			return false;

		if (!IsPlayerOnGround(player))
			return false;

		// check to see if the cursor is in a good spot for an entrance (center of an 8x8 grid)
		vector cursor = target.GetCursorHitPos();
		cursor[0] = Math.Round(cursor[0]);
		cursor[2] = Math.Round(cursor[2]);
		if (Math.ModFloat(cursor[0], 8) == 4 && Math.ModFloat(cursor[2], 8) == 4)
		{
			// PrintFormat("cursor is in a good spot: %1", cursor);
			return true;
		}
		// Print("cursor is not in a good position to spawn");
		return false;
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		return IsPlayerOnGround(action_data.m_Player);
	}

	override bool HasTarget()
	{
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{

		// check to see if we have anything nearby
		IAT_MiningConfig miningConfig;
		if (GetDayZGame() && Class.CastTo(miningConfig, GetDayZGame().GetIATMiningConfig()))
		{
			// truncate the entrace position vector so we have nice smooth numbers in the config
			vector truncatedPos = miningConfig.GetEntranceSpawnPosition(action_data.m_Target.GetCursorHitPos());

			// if we can place the entrance here
			if (miningConfig.CanPlaceEntrance(truncatedPos))
			{
				// spawn the entrance
				IAT_MiningSegment_Colorbase miningEntrance;
				if (Class.CastTo(miningEntrance, GetGame().CreateObjectEx("land_iat_miningsegment_entrance", truncatedPos, ECE_SETUP|ECE_PLACE_ON_SURFACE)))
				{
					miningEntrance.OnServerMineEntranceCreated(action_data.m_Player.GetPosition(), miningEntrance.GetPosition());
					MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 35);
				}
			}
		}
		else
		{
			// TODO: On failed creation make some particles or sound?
			NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Entrance Nearby", "There is another mining entrance within 100m of this position.", "set:ccgui_enforce image:Icon40Emergency");
		}
	}

	bool IsTargetFertile(ActionTarget target)
	{
		if (target)
		{
			string surface_type;
			vector position;
			position = target.GetCursorHitPos();

			GetGame().SurfaceGetType(position[0], position[2], surface_type);

			if (GetGame().IsSurfaceFertile(surface_type))
			{
				return true;
			}
		}

		return false;
	}

	bool IsPlayerOnGround(PlayerBase player)
	{
		vector position = player.GetPosition();
		float heightDiff = GetGame().SurfaceY(position[0], position[2]);
		heightDiff = position[1] - heightDiff;

		return heightDiff <= 0.4; // Player is considered on ground
	}
};