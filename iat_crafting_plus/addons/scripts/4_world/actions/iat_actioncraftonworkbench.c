class IAT_CP_VariantIdActionReciveData extends ActionReciveData
{
	int m_IATVariantId;
}
class IAT_CP_VariantIdActionData extends ActionData
{
	int m_IATVariantId;
};

class IAT_ActioncraftOnWorkbenchCB extends ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(2.0);
	}
};
class IAT_ActionCraftOnWorkbench extends ActionContinuousBase
{
	void IAT_ActionCraftOnWorkbench()
	{
		m_CallbackClass = IAT_ActioncraftOnWorkbenchCB;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		if (!GetGame().IsDedicatedServer())
		{
			GetVariantManager().GetOnUpdateInvoker().Insert(OnUpdateActions);
		}
	}
	//====================================== EVENTS
	override void CreateConditionComponents()
	{
		// item in hand cannot be ruined
		m_ConditionItem = new CCINonRuined;
		// object must be within default distanct of player
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}
	override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
		if (Class.CastTo(craftingWorkbench, target.GetObject()))
		{
			// (client side)
			// if the bench has any crafts available, show its option using the variant id
			if (craftingWorkbench.HasCraftableMatches())
				m_Text = "Craft " + craftingWorkbench.GetCraftableItemDisplayNameByIndex(item, m_VariantID);
		}
	}
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if there is no target; short circuit
		if (!target)
			return false;

		IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
		if (Class.CastTo(craftingWorkbench, target.GetObject()))
		{
			// string.Format("Looking at the correct bench, has recipes? %1", craftingWorkbench.HasCraftableMatches());
			if (craftingWorkbench.HasCraftableMatches())
			{
				// check to see if the tool in hand can craft any of the recipes
				return craftingWorkbench.CanAcceptTool(item);
			}

		}
		return false;
	}
	override void OnFinishProgressServer( ActionData action_data )
	{
		IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
		if (Class.CastTo(craftingWorkbench, action_data.m_Target.GetObject()))
		{
			// pull the client selected variantid from action dddata
			int variantId = IAT_CP_VariantIdActionData.Cast(action_data).m_IATVariantId;
			// get the cratable item based on client selection
			IAT_CraftingRecipe selectedRecipe = craftingWorkbench.GetCraftableItemByIndex(action_data.m_MainItem, variantId);

			// if the tool in hand can complete the craft
			if (craftingWorkbench.CanToolCraftRecipe(action_data.m_MainItem, selectedRecipe))
			{
				// reduce the attached quantities on the crafting workbench
				craftingWorkbench.ReduceAttachedQuantities(selectedRecipe);
				// do dmg to the workbench if you want
				craftingWorkbench.DecreaseHealth(craftingWorkbench.GetCraftingDamage());
				// spawn the results
				CreateRecipeResults(selectedRecipe, craftingWorkbench.GetMemoryPointPosition("item_spawn_position"));

				if (selectedRecipe.GetToolDamagePerCraft() > 0)
				{
					action_data.m_MainItem.DecreaseHealth(selectedRecipe.GetToolDamagePerCraft());
				}
				else if (selectedRecipe.GetToolQuantityPerCraft() > 0)
				{
					if (action_data.m_MainItem.HasEnergyManager())
					{
						if (action_data.m_MainItem.GetInventory().AttachmentCount() > 0)
						{
							EntityAI energySource;
							if (Class.CastTo(energySource, action_data.m_MainItem.GetInventory().GetAttachmentFromIndex(0)))
							{
								// PrintFormat("expected: %1 actual: %2", selectedRecipe.GetToolQuantityPerCraft(), energySource.GetCompEM().GetEnergy());
								energySource.GetCompEM().ConsumeEnergy(selectedRecipe.GetToolQuantityPerCraft());
							}
						}
					}
					else
					{
						action_data.m_MainItem.AddQuantity(-selectedRecipe.GetToolQuantityPerCraft());
					}
				}
			}
			else
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended(action_data.m_Player.GetIdentity(), NotificationSystem.DEFAULT_TIME_DISPLAYED, "Incorrect Tool", "The attached ingredients can form a recipe. The tool in hands is incorrect.", "set:ccgui_enforce image:Icon40Emergency");
			}
		}
	}

	//====================================== VANILLA RPC STUFF
	void CreateRecipeResults(IAT_CraftingRecipe recipe, vector position)
	{
		// get the list of results since i cannot just inline the iterator in the foreach
		array<ref IAT_CraftingResult> craftingResults = recipe.GetCraftingResults();
		EntityAI entityResult;
		float newQuantity;
		float newHP;
		// for each crafting result
		foreach(IAT_CraftingResult result : craftingResults)
		{
			// Print(string.Format("Creating %1 from inded %2",selectedRecipe.GetDisplayName(), variantId));
			// make a new object with some default stuff
			Object newObject = GetGame().CreateObjectEx(result.GetResultClassName(), position, ECE_SETUP|ECE_NOSURFACEALIGN|ECE_KEEPHEIGHT|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
			if (Class.CastTo(entityResult, newObject))
			{
				newQuantity = result.GetExpectedQuantity(entityResult.GetQuantityMax());
				newHP = result.GetExpectedHP(entityResult.GetMaxHealth());
			}

			newObject.SetHealth(newHP);

			Magazine ammo;
			ItemBase resultBase;
			// treat ammo special
			if (Class.CastTo(ammo, newObject))
				ammo.ServerSetAmmoCount(newQuantity);
			// else normal quantity set
			else if (Class.CastTo(resultBase, newObject))
				resultBase.SetQuantity(newQuantity);
		}
	}

	// stub my action data class inbetween client and server so i can send variantID to the server
	override ActionData CreateActionData()
	{
		IAT_CP_VariantIdActionData action_data = new IAT_CP_VariantIdActionData;
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
				// if there is no target or target object; short circuit (sanity check guard rail)
				if (!target || !target.GetObject())
					return false;

				// cast action data to our action data with variant info included
				IAT_CP_VariantIdActionData.Cast(action_data).m_IATVariantId = m_VariantID;

				// change the animation based on what bench is targetted
				SetupAnimation(target.GetObject().GetType(), item.GetType());
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
		ctx.Write(IAT_CP_VariantIdActionData.Cast(action_data).m_IATVariantId);
	}
	// read extra data from the action data context
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		// new custom action data object we will stuff vanilla into
		action_recive_data = new IAT_CP_VariantIdActionReciveData;

		// read the vanilla context into our data object
		super.ReadFromContext(ctx, action_recive_data);

		// setup variables for reading out data
		int variantId;
		// if we CAN read the variantID from context
		if ( ctx.Read(variantId) )
		{
			// Print("[ReadFromContext] - " + variantId);
			// set the server side action data value
			IAT_CP_VariantIdActionReciveData.Cast( action_recive_data ).m_IATVariantId = variantId;
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
		IAT_CP_VariantIdActionData.Cast(action_data).m_IATVariantId = IAT_CP_VariantIdActionReciveData.Cast( action_recive_data ).m_IATVariantId;
	}
	//====================================== Custom Events

	// event triggered when the action needs to update its possible results
	void OnUpdateActions( Object item, Object target, int component_index )
	{
		IAT_CraftingPlus_CraftingBench_Base craftingWorkbench;
		if (Class.CastTo(craftingWorkbench, target))
		{
			ItemBase itemInHands;
			if (Class.CastTo(itemInHands, item))
			{
				// sets the count because all we really need is an ordinal index to loop through the array
				if (craftingWorkbench.HasCraftableMatches())
					GetVariantManager().SetActionVariantCount(craftingWorkbench.GetPotentialCraftableItemCount(itemInHands));
			}
		}
		else
			GetVariantManager().Clear();
	}
	void SetupAnimation(string targetBench, string itemInHands){}

	// to make your workbench or tool do a different animation, override this
	// override void SetupAnimation(string targetBench, string itemInHands)
	// {
	// 	// Don't mix and match CMD Actions. Only use ActionFB (full body)
	// 	switch(targetBench)
	// 	{
	// 		case "Test_Bench1":
	// 		case "AnotherBenchWithSameAnimation":
	// 		case "AndAnotherOne":
	// 			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
	// 	 	break;

	// 		case "Test_Bench2":
	// 		case "AnotherBench":
	// 		case "etc":
	// 		case "etc":
	// 			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_RESTRAINTARGET;
	// 	  	break;
	// 	}
	// }
	//====================================== END
};
