class IAT_ActionBuildStageCB extends ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time = SetCallbackDuration(m_ActionData.m_MainItem);
		m_ActionData.m_ActionComponent = new CAContinuousTime(time);
	}

	float SetCallbackDuration(ItemBase item)
	{
		return UATimeSpent.BASEBUILDING_CONSTRUCT_MEDIUM;
	}
};

class IAT_ActionBuildStage extends ActionContinuousBase
{
	void IAT_ActionBuildStage()
	{
		m_CallbackClass = IAT_ActionBuildStageCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;

		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "#build";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTDummy;
		// m_ConditionTarget = new CCTObject(UAMaxDistances.LARGE);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.IsPlacingLocal() || player.IsPlacingServer())
		{
			return false;
		}
		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
		{
			return false;
		}
		if (!item)
		{
			return false;
		}
		//needs target
		IAT_BuildingStage_ColorBase buildingStage;
		if (Class.CastTo(buildingStage, target.GetObject()))
		{
			// fires once per client
			buildingStage.TryGetBuildingRequirements(player.GetIdentity());

			// if this is not on the last stage of building
			if (!buildingStage.IsLastTier())
			{
				// if the item is not destroyed
				if (!item.IsDamageDestroyed())
				{
					// if the correct tool is in hand
					if (buildingStage.HasCorrectTool(item.GetType()))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		// if the target is our building stage
		IAT_BuildingStage_ColorBase buildingStage;
		if (Class.CastTo(buildingStage, action_data.m_Target.GetObject()))
		{
			// do the area check for materials
			if (buildingStage.HasMaterialsInArea())
			{
				// if exists, consume and transition to next stage
				buildingStage.CraftNextStage();
				// damage the tool a bit
				action_data.m_MainItem.AddHealth(-10);
			}
			else
			{
				// if not exists, give notification
				NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Missing Materials", "There are missing building materials preventing the craft.", "set:ccgui_enforce image:Icon40Emergency");
			}
		}
	}

	override string GetSoundCategory(ActionData action_data)
    {
        return "Base_building";
    }

	override string GetAdminLogMessage(ActionData action_data)
	{
		string message = string.Format("Built %1 with %2 at position: %3", action_data.m_Target.GetObject().GetDisplayName(), action_data.m_MainItem.GetDisplayName(), action_data.m_Target.GetObject().GetPosition());
		return message;
	}
}

// class IAT_ActionBuildStageNoTool extends IAT_ActionBuildStage
// {
// 	override typename GetInputType()
// 	{
// 		return ContinuousInteractActionInput;
// 	}

// 	override bool UseMainItem()
// 	{
// 		return false;
// 	}

// 	override bool HasProgress()
// 	{
// 		return true;
// 	}

// 	override bool HasAlternativeInterrupt()
// 	{
// 		return false;
// 	}
// }