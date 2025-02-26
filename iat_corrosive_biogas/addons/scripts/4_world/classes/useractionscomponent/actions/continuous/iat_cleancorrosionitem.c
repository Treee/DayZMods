class IAT_ActionCleanCorrosionItemCB : ActionContinuousBaseCB
{
	bool m_RPCStopAlreadySent;//since stopping contains a sound tail, we need to stop it only once, this bool ensures that
	override void CreateActionComponent()
	{
		float EmptiedQuantity;
		Bottle_Base bottle = Bottle_Base.Cast(m_ActionData.m_MainItem);
		if (bottle)
			EmptiedQuantity = (bottle.GetLiquidEmptyRate() * bottle.GetLiquidThroughputCoef()) / 4;
		m_ActionData.m_ActionComponent = new CAContinuousEmpty(EmptiedQuantity);
	}

	override void EndActionComponent()
	{
		ActionContinuousBase action = ActionContinuousBase.Cast(m_ActionData.m_Action);
		if (action.UseAlternativeInterrupt(m_ActionData))
			SetCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
		else
			SetCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
	}
};

class IAT_ActionCleanCorrosionItem: ActionContinuousBase
{

	void IAT_ActionCleanCorrosionItem()
	{
		m_CallbackClass = IAT_ActionCleanCorrosionItemCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Clean Corrosion";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

	override bool HasTarget()
	{
		return true;
	}

	override bool HasAlternativeInterrupt()
	{
		return true;
	}

	override bool UseAlternativeInterrupt(ActionData action_data)
	{
		return HasAlternativeInterrupt() && (action_data.m_ActionComponent.GetProgress() >= 1);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase targetItem;
		if (Class.CastTo(targetItem, target.GetObject()))
		{
			// if the target object has corrosion we can clean
			if (targetItem.HasCorrosiveAgents())
			{
				// check if we have enough water to clean
				if (item.GetQuantity() >= item.GetDisinfectQuantity())
				{
					return true;
				}
			}
		}
		return false;
	}

	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}

	override void OnStartAnimationLoop( ActionData action_data )
	{
		SendRPC(action_data,true);
	}

	override void OnEndAnimationLoop( ActionData action_data )
	{
		SendRPC(action_data,false);
		ItemBase targetItem;
		if (Class.CastTo(targetItem, action_data.m_Target.GetObject()))
		{
			// set agents to 0
			targetItem.RemoveAgent(IAT_CB_Agents.CORROSION);
			targetItem.SetCorrosiveAgents(false);
			targetItem.SetSynchDirty();
		}
		// decrement bottle contents
		action_data.m_MainItem.AddQuantity( -action_data.m_MainItem.GetDisinfectQuantity(), false );
	}

	override void OnEndServer( ActionData action_data )
	{
		SendRPC(action_data,false);

		super.OnEndServer(action_data);
	}

	protected void SendRPC(ActionData actionData, bool enable)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			ActionEmptyBottleBaseCB comp = ActionEmptyBottleBaseCB.Cast(actionData.m_Callback);
			if (comp.m_RPCStopAlreadySent)
				return;

			Bottle_Base target_vessel = Bottle_Base.Cast( actionData.m_MainItem );
			Param1<bool> play = new Param1<bool>( enable );
			GetGame().RPCSingleParam( target_vessel, SoundTypeBottle.EMPTYING, play, true );
			if (!enable)
				comp.m_RPCStopAlreadySent = true;
		}
	}
};