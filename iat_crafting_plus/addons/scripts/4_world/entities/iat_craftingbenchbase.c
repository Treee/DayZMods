class IAT_CraftingPlus_CraftingBench_Base extends ItemBase
{
  const int RPC_IAT_UPDATE_RECIPE_INFO = 2863649;
  ref array<IAT_CraftableItem> potentialCraftableItems = new array<IAT_CraftableItem>;
  protected bool m_HasCraftableMatches = false;

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
  override void OnAttachmentQuantityChanged(ItemBase item)
	{
		super.OnAttachmentQuantityChanged(item);
    CheckRecipes();
    // this is server side only event, trigger rpc to tell client to update
    SendServerRecipeRPC();
	}
//================================================== RPC'S
	override void OnRPC( PlayerIdentity sender, int rpc_type,ParamsReadContext ctx )
	{
		switch (rpc_type)
		{
			case RPC_IAT_UPDATE_RECIPE_INFO:
				HandleOnClientRPCRead(ctx);
			break;
		}
		super.OnRPC(sender, rpc_type, ctx);
	}
	void SendServerRecipeRPC()
	{
		if (GetGame().IsDedicatedServer())
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Send(this, RPC_IAT_UPDATE_RECIPE_INFO, true, null);
		}
	}
	void HandleOnClientRPCRead(ParamsReadContext ctx)
	{
		if (!GetGame().IsDedicatedServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckRecipes, 500, false);
		}
	}
//=================================================== CUSTOM
  void CheckRecipes()
  {
    if (!potentialCraftableItems)
      potentialCraftableItems = new array<IAT_CraftableItem>;

    potentialCraftableItems.Clear();

    if (CheckPotentialRecipeMatches(potentialCraftableItems))
    {
      // print("Has matches");
      SetHasCraftableMatches(true);
    }
    else
    {
      // print("Has no matches");
      SetHasCraftableMatches(false);
    }
  }
bool CheckPotentialRecipeMatches(out array<IAT_CraftableItem> craftableItems)
{
	IAT_CraftableItem craftableItem = new IAT_CraftableItem("", "");
	EntityAI attachment;
	int totalSlots = GetInventory().AttachmentCount();
	int slotId;
	int quantity;
	string slotName;
	string colorName;
	int enumId = -1;

	for (int i = 0; i < totalSlots; i++)
	{
		// Print("Sending: index " + i + " with max " + totalSlots);
		if (Class.CastTo(attachment, GetInventory().GetAttachmentFromIndex(i)))
		{
			attachment.GetInventory().GetCurrentAttachmentSlotInfo(slotId, slotName);
			colorName = attachment.ConfigGetString("color");
			colorName.ToUpper();

			enumId = EnumTools.StringToEnum(IAT_COLOR, colorName);
			// non null items with 0 quantity should be seen as 1
			quantity = Math.Max(1, attachment.GetQuantity());
			// Print(string.Format("item: %1 slot: %2 color: %3 enumId: %4 quantity: %5", attachment.GetType(), slotName, colorName, enumId, quantity));
			craftableItem.RegisterIngredient(new IAT_ItemRequirement(slotName, enumId, quantity));
		}
	}
	// craftableItem.PrintIngredients();
	return GetRecipeManager().IsRecipeMatch(craftableItem, craftableItems);
}
  IAT_RecipeManager GetRecipeManager()
  {
    return NULL;
  }
  bool HasCraftableMatches()
  {
    // Print(string.Format("has matches? %1 has array count? %2", m_HasCraftableMatches, potentialCraftableItems.Count()));
    return m_HasCraftableMatches;
  }
  void SetHasCraftableMatches(bool hasMatches)
  {
    m_HasCraftableMatches = hasMatches;
  }
  IAT_CraftableItem GetCraftableItemByIndex(int index)
  {
    if (potentialCraftableItems && potentialCraftableItems.IsValidIndex(index));
      return potentialCraftableItems.Get(index);
    return NULL;
  }
  string GetCraftableItemDisplayNameByIndex(int index)
  {
    if (potentialCraftableItems && potentialCraftableItems.IsValidIndex(index));
      return potentialCraftableItems.Get(index).GetDisplayName();
    return "No Item Found";
  }
  int GetPotentialCraftableItemCount()
  {
    if (!potentialCraftableItems)
      return 0;
    return potentialCraftableItems.Count();
  }
  void GetPotentialRecipeMatchesDisplayName(out TStringArray recipeDisplayNames)
  {
    foreach (IAT_CraftableItem craftable : potentialCraftableItems)
    {
      recipeDisplayNames.Insert(craftable.GetDisplayName());
    }
  }
  string ReduceAttachedQuantities(IAT_CraftableItem craftable)
  {
    if (craftable)
    {
      ItemBase attachment;
      foreach(IAT_ItemRequirement requirement : craftable.m_RequiredIngredients)
      {
        if (Class.CastTo(attachment, GetInventory().FindAttachmentByName(requirement.GetAttachmentSlotName())))
        {
          // attached augments do not get damaged
          if (attachment.IsAugmentAttachment())
            continue;
          // if the item is hp reduced and is not an augment attchment
          if (requirement.ShouldReduceHP())
            attachment.AddHealth(requirement.GetRequiredQuantity());
          else
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
    return craftable.GetItemClassName();
  }
  vector GetMemoryPointPosition(string selection="")
  {
    if ( MemoryPointExists( selection ) )
		{
			vector selection_pos = ModelToWorld( GetMemoryPointPos( selection ) );
      return selection_pos;
		}
		return GetPosition();
  }
  int GetCraftingDamage()
  {
    return 0;
  }
  bool CanAcceptTool(ItemBase item)
  {
    return false;
  }
};
