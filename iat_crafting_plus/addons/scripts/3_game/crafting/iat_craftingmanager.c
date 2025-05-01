class IAT_ItemRequirement
{
  protected string m_AttachmentSlotName;
  protected int m_RequiredColor;
  protected int m_RequiredQuantity;
  protected bool m_ReduceHP; // flag to swap dmg from quantity to hp

  void IAT_ItemRequirement(string attachmentSlotName, int requiredColor=-1, int requiredQuantity=1, bool reducehp=false)
  {
    m_AttachmentSlotName = attachmentSlotName;
    m_RequiredColor = requiredColor;
    m_RequiredQuantity = requiredQuantity;
    m_ReduceHP = reducehp;
  }

  bool IsRequirementMatch(IAT_ItemRequirement requirement)
  {
    bool correctAttachment = IsAttchmentMatch(requirement.GetAttachmentSlotName());
    bool correctColor = IsColorMatch(requirement.GetRequiredColor());    
    bool correctQuantity = IsQuantityMatch(requirement.GetRequiredQuantity());

    if (GetRequiredColor() == -1)
      correctColor = true;

    // Print(string.Format("%1", PrintDebug()));
    return correctAttachment && correctColor && correctQuantity;
  }

  bool IsAttchmentMatch(string otherAttachmentName)
  {
    return m_AttachmentSlotName == otherAttachmentName;
  }
  bool IsColorMatch(int otherColor)
  {
    return m_RequiredColor == otherColor;
  }
  bool IsQuantityMatch(int otherQuantity)
  {
    return otherQuantity >= m_RequiredQuantity;
  }
  string GetAttachmentSlotName()
  {
    return m_AttachmentSlotName;
  }
  int GetRequiredColor()
  {
    return m_RequiredColor;
  }
  int GetRequiredQuantity()
  {
    return m_RequiredQuantity;
  }
  bool ShouldReduceHP()
  {
    return m_ReduceHP;
  }
  string PrintDebug()
  {
    return string.Format("Item Requirement: %1 || %2 || %3", GetAttachmentSlotName(), GetRequiredColor(), GetRequiredQuantity());
  }
};

class IAT_CraftableItem
{
  protected string m_DisplayName;
  protected string m_ItemName;
  protected int m_Quantity;
  ref array<ref IAT_ItemRequirement> m_RequiredIngredients;

  void IAT_CraftableItem(string itemName, string displayName, int quantity = 1)
  {
    m_ItemName = itemName;
    m_DisplayName = displayName;
    m_Quantity = quantity;
    if (!m_RequiredIngredients)
    {
      m_RequiredIngredients = new array<ref IAT_ItemRequirement>;
    }
  }
  void RegisterIngredient(IAT_ItemRequirement craftingIngredient)
  {
    if (m_RequiredIngredients.Find(craftingIngredient) == -1)
      m_RequiredIngredients.Insert(craftingIngredient);
  }
  void RemoveIngredient(IAT_ItemRequirement craftingIngredient)
  {    
    m_RequiredIngredients.RemoveItem(craftingIngredient);
  }
  string GetDisplayName()
  {
    return m_DisplayName;
  }
  string GetItemClassName()
  {
    return m_ItemName;
  }
  int GetItemQuantity()
  {
    return m_Quantity;
  }
  bool CompareToOtherIngredients(IAT_CraftableItem otherCraftable)
  {
    bool isCompleteMatch = true;
    bool isIngredientMatch = false;
    // start with my ingredients
    foreach(IAT_ItemRequirement ingredient : m_RequiredIngredients)
    {
      // Print(string.Format("Comparring Recipe %1 || Ingredients %2", GetItemClassName(), ingredient.PrintDebug()));
      // look at all the other ingredients
      foreach(IAT_ItemRequirement otherIngredient : otherCraftable.m_RequiredIngredients)
      {
        // if there is a match
        // Print(string.Format("Against Matching Ingredients %1", otherIngredient.PrintDebug()));
        if (ingredient.IsRequirementMatch(otherIngredient))
        {
          // set we matched to true; break out of the inner for loop
          isIngredientMatch = true;
          break;
        }        
      }
      // if the other ingredients have a match
      if (isIngredientMatch)
      {
        // reset the boolean flag for ingredients
        isIngredientMatch = false;
        isCompleteMatch &= true;
        // Print("Ingredient MATCH!!");
        continue;
      }
      else
      {
        // the other craftable has no ingredients that match this; break loop
        isCompleteMatch &= false;
        // Print("NO MATCHING INGREDIENTS QUICK FAIL");
        break;
      }
    }
    return isCompleteMatch;
  }
  void PrintIngredients()
  {
    Print(string.Format("Printing Ingredients for Recipe: %1", GetItemClassName()));
    foreach(IAT_ItemRequirement requirement : m_RequiredIngredients)
    {
      Print(requirement.PrintDebug());
    }
  }
};

class IAT_RecipeManager
{
  protected ref array<ref IAT_CraftableItem> craftableItems;

  void IAT_RecipeManager()
  {
    Init();
  }
  void Init()
  {
    if (!craftableItems)
    {
      craftableItems = new array<ref IAT_CraftableItem>;
    }
  }
  //===========================TEMPLATE
  // IAT_CraftableItem Register_X_Recipe()
  // {
  //   IAT_CraftableItem craftableItem = new IAT_CraftableItem("ITEM_CLASS_NAME", "ITEM_DISPLAY_NAME");
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 2));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 3));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 2));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 3));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 2));

  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.IRON, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.SILVER, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.PLATINUM, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.SILVER, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.IRON, 1));

  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.JADE, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.AMETHYST, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.AMBER, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.TOPAZ, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.DIAMOND, 1));
  //   return craftableItem;
  // }
  bool IsRecipeMatch(IAT_CraftableItem otherCraftable, out array<IAT_CraftableItem> craftableResults)
  {    
    foreach(IAT_CraftableItem craftableItem : craftableItems)
    {      
      if (craftableItem.CompareToOtherIngredients(otherCraftable))
      {
        craftableResults.Insert(craftableItem);
        // Print(string.Format("Found Recipe Match %1", craftableItem.GetDisplayName()));
      }
    }
    return craftableResults.Count() > 0;
  }
  void PrintRecipes()
  {
    // Print("All Recipes");
    foreach(IAT_CraftableItem craftableItem : craftableItems)
    {      
      craftableItem.PrintIngredients();
    }
  }
};