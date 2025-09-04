class IAT_DyeVariantActionReciveData extends ActionReciveData
{
  	int m_IATDyeVariant;
}

class IAT_DyeVariantActionData extends ActionData
{
  	int m_IATDyeVariant;
};


class IAT_DyeObjectCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(2); //default value can be set in recipes
	}
};

class IAT_DyeObject: ActionContinuousBase
{
	void IAT_DyeObject()
	{
		m_Sound = "craft_universal_0";
		m_CallbackClass = IAT_DyeObjectCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Text = "Dye Object";

		if (!GetGame().IsDedicatedServer())
        {
            GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
        }
	}

	void OnUpdateActions(Object item, Object target, int component_index)
	{
    	// Print("on update actions start");
    	ItemBase clothingItem;
		if (Class.CastTo(clothingItem, target))
		{
			// Print("on update actions clothing cast: " + clothingItem);
			GetVariantManager().SetActionVariantCount(clothingItem.GetTotalColorVariations());
		}
		else
		{
      		// Print("clear items");
			GetVariantManager().Clear();
		}
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
		m_Text = "No Option";

		ItemBase target_clothing;
		if ( target && Class.CastTo(target_clothing, target.GetObject()) )
		{
			if (target_clothing.HasDyableOptions())
			{
				string displayOption = target_clothing.GetDyeOption(m_VariantID);
				if (displayOption != "" )
				{
					m_Text = string.Format("Dye - %1", displayOption);
				}
			}
		}
	}

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// Print("Action condition start");
		IAT_DyeVial_ColorBase dye;
		if (Class.CastTo(dye, item) && item.GetQuantity() < 99)
		{
			return false;
		}
		// Print("Action condition- item in hands is spray can: " + dye);
		ItemBase target_clothing;
		if (target && Class.CastTo(target_clothing, target.GetObject()))
		{
			if (target_clothing.GetNumberOfItems() > 0)
				return false;
			if (target_clothing.IsContainer() && !target_clothing.IsInherited(PlateCarrierPouches))
				return false;
			if (target_clothing.HasDyableOptions())
				return true;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		super.OnFinishProgressServer(action_data);

		IAT_DyeVial_ColorBase dye;
		if (action_data.m_MainItem && Class.CastTo(dye, action_data.m_MainItem))
		{
			ItemBase target_clothing;
			if ( action_data.m_Target && Class.CastTo(target_clothing, action_data.m_Target.GetObject()) )
			{
				int variantId = IAT_DyeVariantActionData.Cast(action_data).m_IATDyeVariant;

				string newItemName = target_clothing.GetDyableBaseClassName();

				if (target_clothing.HasDyableOptions())
				{
					// make it so players cant just dye things to full hp
					float old_hp = target_clothing.GetHealth();
					// construct the new item name
					newItemName = string.Format("%1_%2", newItemName, target_clothing.GetDyeOption(variantId));
					// spawn it
					ItemBase newItemSpawn;
					if (Class.CastTo(newItemSpawn, GetGame().CreateObjectEx(newItemName, target_clothing.GetPosition(), ECE_SETUP|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY)))
					{
						// set the hp
						newItemSpawn.SetHealth(old_hp);
						// consume the item
						dye.AddQuantity(-100);
					}
				}
			}
		}
	}

	override ActionData CreateActionData()
	{
		IAT_DyeVariantActionData action_data = new IAT_DyeVariantActionData;
		return action_data;
	}

	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			if ( !GetGame().IsDedicatedServer() )
			{
				IAT_DyeVariantActionData.Cast(action_data).m_IATDyeVariant = m_VariantID;
			}
			return true;
		}
		return false;
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		ctx.Write(IAT_DyeVariantActionData.Cast(action_data).m_IATDyeVariant);
	}

	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new IAT_DyeVariantActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);

		int variantId;
		if ( ctx.Read(variantId) )
		{
			IAT_DyeVariantActionReciveData.Cast( action_recive_data ).m_IATDyeVariant = variantId;
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
		IAT_DyeVariantActionData.Cast(action_data).m_IATDyeVariant = IAT_DyeVariantActionReciveData.Cast( action_recive_data ).m_IATDyeVariant;
	}

};