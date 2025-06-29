class IAT_ActionLegCastTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.APPLY_SPLINT);
	}
};

class IAT_ActionLegCastTarget: ActionContinuousBase
{
	void IAT_ActionLegCastTarget()
	{
		m_CallbackClass = IAT_ActionLegCastTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Apply Leg Cast";
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		PlayerBase playerTarget;
		if (Class.CastTo(playerTarget, target.GetObject()))
		{
			if (playerTarget.GetBrokenLegs() != eBrokenLegs.BROKEN_LEGS || IsWearingSplint(playerTarget) || playerTarget.IsInVehicle())
			{
				return false;
			}
		}
		return super.ActionCondition(player, target, item);

	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase playerTarget;
		if (Class.CastTo(playerTarget, action_data.m_Target.GetObject()))
		{
			if (CanReceiveAction(action_data.m_Target))
			{
				action_data.m_MainItem.TransferModifiers(playerTarget);
				playerTarget.ApplySplint();

				string castColor = action_data.m_MainItem.ConfigGetString("color");
				if (!castColor || castColor == "")
					castColor = "Basic";

				IAT_LegCastApplied_Colorbase new_item;
				if (Class.CastTo(new_item, playerTarget.GetInventory().CreateInInventory(string.Format("IAT_LegCastApplied_%1", castColor))))
				{
					MiscGameplayFunctions.TransferItemProperties(action_data.m_MainItem, new_item, true, false, true);
					action_data.m_MainItem.Delete();
				}
				playerTarget.SetBrokenLegs(eBrokenLegs.BROKEN_LEGS_SPLINT);
			}
		}
	}
	bool IsWearingSplint( PlayerBase player )
	{
		if ( player.GetItemOnSlot("Splint_Right") )
		{
			return true;
		}
		return false;
	}
};

class IAT_ActionLegCastSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.APPLY_SPLINT);
	}
};

class IAT_ActionLegCastSelf: ActionContinuousBase
{
	void IAT_ActionLegCastSelf()
	{
		m_CallbackClass = IAT_ActionLegCastSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Apply Leg Cast";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		action_data.m_MainItem.TransferModifiers(action_data.m_Player);
		action_data.m_Player.ApplySplint();

		//Double check to not enter splinted state if legs are not broken
		if (action_data.m_Player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
		{
			action_data.m_Player.SetBrokenLegs(eBrokenLegs.BROKEN_LEGS_SPLINT);

			string castColor = action_data.m_MainItem.ConfigGetString("color");
			if (!castColor || castColor == "")
				castColor = "Basic";

			IAT_LegCastApplied_Colorbase new_item;
			if (Class.CastTo(new_item, action_data.m_Player.GetInventory().CreateInInventory(string.Format("IAT_LegCastApplied_%1", castColor))))
			{
				MiscGameplayFunctions.TransferItemProperties(action_data.m_MainItem, new_item, true, false, true);
				action_data.m_MainItem.Delete();
			}
		}
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.GetBrokenLegs() != eBrokenLegs.BROKEN_LEGS || IsWearingSplint(player))
		{
			return false;
		}
		return super.ActionCondition(player, target, item);

	}

	bool IsWearingSplint( PlayerBase player )
	{
		if ( player.GetItemOnSlot("Splint_Right") )
		{
			return true;
		}
		return false;
	}
};