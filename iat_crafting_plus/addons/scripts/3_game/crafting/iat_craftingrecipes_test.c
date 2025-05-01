class IAT_TestWorkbenchRecipes extends IAT_RecipeManager
{
  override void Init()
  {
    super.Init();
    // MISC
    craftableItems.Insert(Register_TestBenchRecipe_Recipe());
    craftableItems.Insert(Register_TestBenchRecipe1_Recipe());
    craftableItems.Insert(Register_TestBenchRecipe2_Recipe());
  }
//===========================TEMPLATE
  // IAT_CraftableItem Register_X_Recipe()
  // {
  //   IAT_CraftableItem craftableItem = new IAT_CraftableItem("ITEM_CLASS_NAME", "ITEM_DISPLAY_NAME");
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 1));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 1));

  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 2));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
  //   craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
  //   return craftableItem;
  // }
//===========================MISC
  IAT_CraftableItem Register_TestBenchRecipe_Recipe()
  {
    IAT_CraftableItem craftableItem = new IAT_CraftableItem("WoodenLog", "Wooden Log");

    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_WoodenLogs", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_L1_WoodenPlanks", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_MetalSheets", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_Shelter_Fabric", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("MetalWire", IAT_COLOR.NONE, 1));
    return craftableItem;
  }
  IAT_CraftableItem Register_TestBenchRecipe1_Recipe()
  {
    IAT_CraftableItem craftableItem = new IAT_CraftableItem("SewingKit", "Sewing kit");

    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_WoodenLogs", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_L1_WoodenPlanks", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_MetalSheets", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_Shelter_Fabric", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("MetalWire", IAT_COLOR.NONE, 1));
    return craftableItem;
  }
  IAT_CraftableItem Register_TestBenchRecipe2_Recipe()
  {
    IAT_CraftableItem craftableItem = new IAT_CraftableItem("WoodenStick", "Wooden Stick");

    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_WoodenLogs", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_L1_WoodenPlanks", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Rags", IAT_COLOR.NONE, 2));
    return craftableItem;
  }

//===========================END

};