// helpers for passing data around actions
class IAT_MD_VariantIdActionReciveData extends ActionReciveData
{
	int m_IATVariantId;
}
class IAT_MD_VariantIdActionData extends ActionData
{
	int m_IATVariantId;
};

// time taken to make the selection
class IAT_ActionSelectDoorOptionCB extends ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(1.0);
	}
};
class IAT_ActionSelectDoorOption extends ActionContinuousBase
{
	void IAT_ActionSelectDoorOption()
	{
		m_CallbackClass		= IAT_ActionSelectDoorOptionCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "Select Door Option";
		// only hook up the variant manager on client
		if (!GetGame().IsDedicatedServer())
		{
			GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
		}
	}
	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINonRuined();
		m_ConditionTarget 	= new CCTNone();
	}
	override bool HasTarget()
	{
		return false;
	}
	override bool HasProgress()
	{
		return true;
	}
	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// update action info for frames that have our item in hand
		IAT_MoreDoorKit_ColorBase doorKit;
		if (Class.CastTo(doorKit, item))
		{
			// get the display name based on local selection
			string variantDisplayName = doorKit.GetDoorDisplayNameFromIndex(m_VariantID);
			// if it is not empty
			if (variantDisplayName != "")
			{
				// modify the text
				m_Text = string.Format("Select Door - %1", variantDisplayName);
			}
		}
		else
		{
			m_Text = "No Options Available";
		}
	}
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// disallow selecting options while placing a hologram
		if (player.IsPlacingLocal())
			return false;

		// otherwise if we are holding our door kit, let us select the option
		IAT_MoreDoorKit_ColorBase doorKit;
		if (Class.CastTo(doorKit, item))
		{
			return true;
		}
		return false;
	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		// do vanilla
		super.OnFinishProgressServer(action_data);

		// if the main item in hands is our door kit
		IAT_MoreDoorKit_ColorBase doorKit;
		if (Class.CastTo(doorKit, action_data.m_MainItem))
		{
			// pump the variant id into our action data
			int variantId = IAT_MD_VariantIdActionData.Cast(action_data).m_IATVariantId;
			// set the selection on the kit itself for later use
			doorKit.SetSelectedDoorOption(variantId);
		}
	}
	override void OnFinishProgressClient(ActionData action_data)
	{
		// do vanilla
		super.OnFinishProgressClient(action_data);

		//if the main item in hand is our door kit
		IAT_MoreDoorKit_ColorBase doorKit;
		if (Class.CastTo(doorKit, action_data.m_MainItem))
		{
			// set the client side kit selection for later use
			doorKit.SetSelectedDoorOption(m_VariantID);
		}
	}

	void OnUpdateActions(Object item, Object target, int component_index)
	{
		// fill the variant manager list with our count of options
        IAT_MoreDoorKit_ColorBase doorKit;
		if (Class.CastTo(doorKit, item))
		{
			GetVariantManager().SetActionVariantCount(doorKit.GetDoorOptions().Count());
        }
        else
            GetVariantManager().Clear();
	}

	override string GetSoundCategory(ActionData action_data)
	{
		return "Base_building";
	}

	//==================================================== ACTION VARIANT STUFF
	// stub my action data class inbetween client and server so i can send variantID to the server
	override ActionData CreateActionData()
	{
		IAT_MD_VariantIdActionData action_data = new IAT_MD_VariantIdActionData;
		return action_data;
	}
	// setup the action data flow.
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		// let vanilla build our object for us
		if (super.SetupAction(player, target, item, action_data, extra_data))
		{
			// if we are on the client
			if (!GetGame().IsDedicatedServer())
			{
				// cast action data to our action data with variant info included
				IAT_MD_VariantIdActionData.Cast(action_data).m_IATVariantId = m_VariantID;
			}
			// pass through vanilla bool super call
			return true;
		}
		// vanilla failed, return false
		return false;
	}
	// write extra data to action data context
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		// vanilla write to context
		super.WriteToContext(ctx, action_data);
		// write our extra data to the context (order matters)
		ctx.Write(IAT_MD_VariantIdActionData.Cast(action_data).m_IATVariantId);
	}
	// read extra data from the action data context
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		// new custom action data object we will stuff vanilla into
		action_recive_data = new IAT_MD_VariantIdActionReciveData;

		// read the vanilla context into our data object
		super.ReadFromContext(ctx, action_recive_data);

		// setup variables for reading out data
		int variantId;
		// if we CAN read the variantID from context
		if ( ctx.Read(variantId) )
		{
			// Print("[ReadFromContext] - " + variantId);
			// set the server side action data value
			IAT_MD_VariantIdActionReciveData.Cast( action_recive_data ).m_IATVariantId = variantId;
			return true;
		}
		else
		{
			// otherwise hard fail this read
			return false;
		}
	}
	// handle receiving extra data from client
	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		// do vanilla receive data
		super.HandleReciveData(action_recive_data, action_data);
		// stuff the received variant information into the appropriate place
		IAT_MD_VariantIdActionData.Cast(action_data).m_IATVariantId = IAT_MD_VariantIdActionReciveData.Cast( action_recive_data ).m_IATVariantId;
	}
};