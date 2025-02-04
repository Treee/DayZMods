class IAT_ActionCraftArmbandOptionsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(2); //default value can be set in recipes
	}
};

class IAT_ActionCraftArmbandOptions: ActionContinuousBase
{
	void IAT_ActionCraftArmbandOptions()
	{
		m_Sound = "craft_universal_0";
		m_CallbackClass = IAT_ActionCraftArmbandOptionsCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "#craft";

		if (!GetGame().IsDedicatedServer())
        {
            GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
        }
	}

	void OnUpdateActions( Object item, Object target, int component_index )
	{
		TStringArray m_ArmbandOptions = GetArmbandOptions();
		if (m_ArmbandOptions.Count() > 0)
			GetVariantManager().SetActionVariantCount(m_ArmbandOptions.Count());
		else
			GetVariantManager().Clear();
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

	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = "Craft Armband - No Option";
		Rag stackOfRags;
		if (target && Class.CastTo(stackOfRags, target.GetObject()))
		{
			if (stackOfRags.GetQuantity() > 1)
			{
				// if the main item sewing kit has enough quantity to sew a flag
				if (item && item.GetQuantity() > 24)
				{
					TStringArray m_ArmbandOptions = GetArmbandOptions();
					if (m_ArmbandOptions.IsValidIndex(m_VariantID))
					{
						m_Text = string.Format("Craft Armband - %1", m_ArmbandOptions.Get(m_VariantID));
					}
				}
			}
		}
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if the target is rags and the stack is full
		Rag stackOfRags;
		if (target && Class.CastTo(stackOfRags, target.GetObject()))
		{
			if (stackOfRags.GetQuantity() < 2)
			{
				return false;
			}
			// if the main item sewing kit has enough quantity to sew a flag
			if (item && item.GetQuantity() > 24)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	TStringArray GetArmbandOptions()
	{
		return {
			"White",
			"Yellow",
			"Orange",
			"Red",
			"Green",
			"Pink",
			"Blue",
			"Black",
			"Chernarus",
			"Chedaki",
			"NAPA",
			"CDF",
			"Livonia",
			"Altis",
			"SSahrani",
			"NSahrani",
			"DayZ",
			"LivoniaArmy",
			"Bohemia",
			"APA",
			"UEC",
			"Pirates",
			"Cannibals",
			"Bear",
			"Wolf",
			"BabyDeer",
			"Rooster",
			"LivoniaPolice",
			"CMC",
			"TEC",
			"CHEL",
			"Zenit",
			"HunterZ",
			"BrainZ",
			"Refuge",
			"RSTA",
			"Snake",
			"Crook",
			"Rex",
			"Zagorky",
		};
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);

		if (action_data.m_Player)
		{
			int newItemIndex = IAT_FlagArmbandVariantActionData.Cast(action_data).m_IATFlagArmbandVariant;
			TStringArray m_ArmbandOptions = GetArmbandOptions();
			if (m_ArmbandOptions.IsValidIndex(newItemIndex))
			{
				string newItem = string.Format("Armband_%1", m_ArmbandOptions.Get(newItemIndex));
				GetGame().CreateObjectEx(newItem, action_data.m_Player.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
				Rag rags;
				if (Class.CastTo(rags, action_data.m_Target.GetObject()))
				{
					rags.AddQuantity(-2);
				}
				SewingKit sewingKit;
				if (Class.CastTo(sewingKit, action_data.m_MainItem))
				{
					sewingKit.AddQuantity(-25);
				}
			}
		}
	}

	override ActionData CreateActionData()
	{
		IAT_FlagArmbandVariantActionData action_data = new IAT_FlagArmbandVariantActionData;
		return action_data;
	}

	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			if ( !GetGame().IsDedicatedServer() )
			{
				IAT_FlagArmbandVariantActionData.Cast(action_data).m_IATFlagArmbandVariant = m_VariantID;
			}
			return true;
		}
		return false;
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_FlagArmbandVariantActionData.Cast(action_data).m_IATFlagArmbandVariant);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_FlagArmbandVariantActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);

		int variantId;
		if ( ctx.Read(variantId) )
		{
			IAT_FlagArmbandVariantActionReciveData.Cast( action_recive_data ).m_IATFlagArmbandVariant = variantId;
			return true;
		}
		else
		{
			return false;
		}
	}

	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		IAT_FlagArmbandVariantActionData.Cast(action_data).m_IATFlagArmbandVariant = IAT_FlagArmbandVariantActionReciveData.Cast( action_recive_data ).m_IATFlagArmbandVariant;
	}

};