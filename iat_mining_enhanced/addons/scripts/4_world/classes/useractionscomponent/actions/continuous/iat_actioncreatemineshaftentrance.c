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

		return IsTargetFertile(target) && IsPlayerOnGround(player);
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
		// spawn the entrance
		land_iat_miningsegment_entrance miningEntrance;
		if (Class.CastTo(miningEntrance, GetGame().CreateObjectEx("land_iat_miningsegment_entrance", action_data.m_Target.GetCursorHitPos(), ECE_SETUP|ECE_PLACE_ON_SURFACE)))
		{
			miningEntrance.CreateMiningExit(action_data.m_Player.GetPosition(), action_data.m_Target.GetCursorHitPos());
			MiscGameplayFunctions.DealEvinronmentAdjustedDmg(action_data.m_MainItem, action_data.m_Player, 35);
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