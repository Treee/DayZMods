class IAT_CraftingPlus_CraftingBench_Base extends ItemBase
{
	static ref ScriptInvoker SyncEvent_IAT_OnCraftingManagerChange = new ScriptInvoker;

	const int RPC_IAT_UPDATE_RECIPE_INFO = 2863649;
	ref array<IAT_CraftingRecipe> m_CraftingRecipes = new array<IAT_CraftingRecipe>;
	protected bool m_HasCraftableMatches = false;

	void IAT_CraftingPlus_CraftingBench_Base()
	{
		SyncEvent_IAT_OnCraftingManagerChange.Insert(TryCheckRecipes);
	}
	void ~IAT_CraftingPlus_CraftingBench_Base()
	{
		SyncEvent_IAT_OnCraftingManagerChange.Remove(TryCheckRecipes);
	}

	//================================================== EVENTS
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
	// when an item is attached, go through the recipes once and see if anything can be crafted
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		CheckRecipes();
	}
	// when an item is attached, go through the recipes once and see if anything can be crafted
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		CheckRecipes();
	}

	//! Called on server side when some attachment's quantity is changed.
	// since quantity is netsynced we override the item being dragged to call the parent workbench check recipes on client side to keep results synced
	override void OnAttachmentQuantityChanged(ItemBase item)
	{
		super.OnAttachmentQuantityChanged(item);
		CheckRecipes();
	}

	//=================================================== CUSTOM
	void TryCheckRecipes()
	{
		if (!GetGame().IsDedicatedServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckRecipes, 500, false);
		}
	}
	// function to invoke parsing attachments and checking recipes
	void CheckRecipes()
	{
		// Print("check recipes");
		// new crafting recipes list/clear existing list
		if (!m_CraftingRecipes)
			m_CraftingRecipes = new array<IAT_CraftingRecipe>;
		m_CraftingRecipes.Clear();

		// if there are potential recipe matches; toggle a helper bool
		// output m_CraftingRecipes as the list of potential results
		if (CheckPotentialRecipeMatches(m_CraftingRecipes))
		{
			// Print("===================================================================== HAS MATCHES");
			SetHasCraftableMatches(true);
		}
		else
		{
			// Print("===================================================================== Has no matches");
			SetHasCraftableMatches(false);
		}
	}

	bool CheckPotentialRecipeMatches(out array<IAT_CraftingRecipe> craftableRecipes)
	{
		// stub recipe to make comparrison easier
		IAT_CraftingRecipe craftableItem = new IAT_CraftingRecipe("", "");
		// loop setup pre declares
		EntityAI attachment;
		int totalSlots = GetInventory().AttachmentCount();
		int slotId;
		int quantity;
		string slotName;
		string colorName;

		// for each slot on the bench
		for (int i = 0; i < totalSlots; i++)
		{
			// Print("Sending: index " + i + " with max " + totalSlots);
			// cast that attachment to an entity
			if (Class.CastTo(attachment, GetInventory().GetAttachmentFromIndex(i)))
			{
				// get the slot id and name information.
				attachment.GetInventory().GetCurrentAttachmentSlotInfo(slotId, slotName);
				// get the color of  the attachment
				colorName = attachment.ConfigGetString("color");
				// non null items with 0 quantity should be seen as 1
				quantity = Math.Max(1, attachment.GetQuantity());
				// insert this info into our stub recipe
				// Print(string.Format("item: %1 slot: %2 color: %3 enumId: %4 quantity: %5", attachment.GetType(), slotName, colorName, enumId, quantity));
				craftableItem.InsertCraftingRequirement(new IAT_CraftingItemRequirement(slotName, colorName, quantity));
			}
		}
		// null checking
		if (!GetRecipeManager())
			return false;
		// craftableItem.PrintIngredients();
		// check if this benches contents can match an actual recipe
		return GetRecipeManager().IsRecipeMatch(craftableItem, craftableRecipes);
	}
	protected IAT_RecipeManager GetRecipeManager()
	{
		return GetDayZGame().GetIATCraftingPlusConfig().GetRecipeManagerByName(GetWorkbenchManagerName());
	}
	// consume materials based on recipe
	void ReduceAttachedQuantities(IAT_CraftingRecipe craftable)
	{
		// if there is a recipe to reduce from
		if (craftable)
		{
			array<ref IAT_CraftingItemRequirement> otherCraftingIngredients = craftable.GetCraftingItemRequirements();
			ItemBase attachment;
			// foreach required item of the recipe
			foreach(IAT_CraftingItemRequirement requirement : otherCraftingIngredients)
			{
				// get the attached item by slot name
				if (Class.CastTo(attachment, GetInventory().FindAttachmentByName(requirement.GetAttachmentSlotName())))
				{
					// protected attachments do not get damaged
					if (requirement.IsProtectedItem())
						continue;
					// if the item is hp reduced
					if (requirement.ShouldReduceHP())
						attachment.AddHealth(requirement.GetRequiredQuantity());
					else // reduce quantity
					{
						// players that brute force recipes will find things to be most expensive.
						int quantityToRemove = Math.Max(requirement.GetRequiredQuantity(), attachment.GetQuantity());
						if (attachment.HasEnergyManager())
							attachment.GetCompEM().AddEnergy(-quantityToRemove);
						else
							attachment.AddQuantity(-quantityToRemove);
						// PrintFormat("attachquantity: %1 toRemove %2", attachment.GetQuantityMax(), quantityToRemove);
						bool isSingularItem = attachment.GetQuantityMax() == 0 || attachment.GetQuantityMax() == 1;
						if (isSingularItem && quantityToRemove == 1)
							attachment.Delete();
					}
				}
			}
		}
	}
	// ==================================================================================
	// Helpers
	// ==================================================================================
	// convenience function for spawning results on a specific location on your bench
	// item_spawn_position is the selection name that needs to be in your p3d
	vector GetMemoryPointPosition(string selection="")
	{
		if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			return selection_pos;
		}
		return GetPosition();
	}
	// damage to bench per craft. overridable
	int GetCraftingDamage()
	{
		return 0;
	}
	// the string key name of recipe manager to fetch. meant to be overriden by each bench
	string GetWorkbenchManagerName()
	{
		return "TestManager";
	}
	// Get recipe by index
	IAT_CraftingRecipe GetCraftableItemByIndex(ItemBase item, int index)
	{
		array<IAT_CraftingRecipe> actualRecipes = new array<IAT_CraftingRecipe>;
		foreach(IAT_CraftingRecipe recipe : m_CraftingRecipes)
		{
			if (CanToolCraftRecipe(item, recipe))
			{
				actualRecipes.Insert(recipe);
			}
		}

		if (actualRecipes && actualRecipes.IsValidIndex(index))
			return actualRecipes.Get(index);
		return NULL;
	}
	// Get recipe display name by index
	string GetCraftableItemDisplayNameByIndex(ItemBase item, int index)
	{
		array<IAT_CraftingRecipe> actualRecipes = new array<IAT_CraftingRecipe>;
		foreach(IAT_CraftingRecipe recipe : m_CraftingRecipes)
		{
			if (CanToolCraftRecipe(item, recipe))
			{
				actualRecipes.Insert(recipe);
			}
		}

		if (actualRecipes && actualRecipes.IsValidIndex(index))
			return actualRecipes.Get(index).GetDisplayName();
		return "No Item Found";
	}
	// get recipe count
	// int GetPotentialCraftableItemCount()
	// {
	// 	if (!m_CraftingRecipes)
	// 		return 0;
	// 	return m_CraftingRecipes.Count();
	// }
	int GetPotentialCraftableItemCount(ItemBase item)
	{
		int countOfCraftableRecipes = 0;
		foreach(IAT_CraftingRecipe recipe : m_CraftingRecipes)
		{
			if (CanToolCraftRecipe(item, recipe))
			{
				countOfCraftableRecipes++;
			}
		}
		return countOfCraftableRecipes;
	}
	// get list of crafting recipe display names
	void GetPotentialRecipeMatchesDisplayName(out TStringArray recipeDisplayNames)
	{
		foreach (IAT_CraftingRecipe craftable : m_CraftingRecipes)
		{
			recipeDisplayNames.Insert(craftable.GetDisplayName());
		}
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	// helper bool to return if any matches exist (shortcut from having to constantly check client side)
	bool HasCraftableMatches()
	{
		// PrintFormat("has matches? %1 has array count? %2", m_HasCraftableMatches, m_CraftingRecipes.Count());
		return m_HasCraftableMatches;
	}
	// set if matches are found (this way to allow hard overrides)
	void SetHasCraftableMatches(bool hasMatches)
	{
		m_HasCraftableMatches = hasMatches;
	}
	// is the tool in hand a tool that can complete a recipe?
	bool CanAcceptTool(ItemBase tool)
	{
		// pre optimization by only casting energy source once instead of inside the foreach loop
		float toolQuantity = 0;
		if (tool.HasEnergyManager())
		{
			// Print("Has energy manager.");
			if (tool.GetInventory().AttachmentCount() != 0)
			{
				EntityAI energySource;
				if (Class.CastTo(energySource, tool.GetInventory().GetAttachmentFromIndex(0)))
				{
					toolQuantity = energySource.GetCompEM().GetEnergy();
				}
			}
		}
		else
		{
			toolQuantity = tool.GetQuantity();
		}
		// PrintFormat("Tool quantity: %1", toolQuantity);

		bool isCorrectTool = false;
		string toolName = tool.GetType();
		toolName.ToLower();
		string requiredTool;
		// PrintFormat("checking tool %1")
		foreach(IAT_CraftingRecipe recipe : m_CraftingRecipes)
		{
			requiredTool = recipe.GetRequiredTool();
			requiredTool.ToLower();
			// PrintFormat("CanAcceptTool: Required Tool: %1 Actual Tool: %2", recipe.GetRequiredTool(), toolName);
			if (requiredTool == "" || requiredTool == toolName)
			{
				if (toolQuantity >= recipe.GetToolQuantityPerCraft())
				{
					isCorrectTool = true;
					break;
				}
				if (tool.HasEnergyManager() && toolQuantity >= recipe.GetToolQuantityPerCraft())
				{
					isCorrectTool = true;
					break;
				}
			}
		}
		return isCorrectTool;
	}
	bool CanToolCraftRecipe(ItemBase tool, IAT_CraftingRecipe recipe)
	{
		string recipeTool = recipe.GetRequiredTool();
		recipeTool.ToLower();
		string toolType = tool.GetType();
		toolType.ToLower();
		// PrintFormat("CanToolCraftRecipe: Required Tool: %1 Actual Tool: %2", recipeTool, tool.GetType());
		if (recipeTool == "" || recipeTool == toolType)
		{
			if (tool.GetQuantity() >= recipe.GetToolQuantityPerCraft())
			{
				return true;
			}
			if (tool.HasEnergyManager())
			{
				if (tool.GetInventory().AttachmentCount() == 0)
					return false;

				EntityAI energySource;
				if (Class.CastTo(energySource, tool.GetInventory().GetAttachmentFromIndex(0)))
				{
					return energySource.GetCompEM().GetEnergy() >= recipe.GetToolQuantityPerCraft();
				}
			}
		}
		return false;
	}
};
