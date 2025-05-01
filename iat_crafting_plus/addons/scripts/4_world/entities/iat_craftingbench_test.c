class IAT_CraftingPlus_CraftingBench_Test extends IAT_CraftingPlus_CraftingBench_Base
{
  override IAT_RecipeManager GetRecipeManager()
  {
    return GetDayZGame().GetIATTestWorkbenchRecipes();
  }
  override int GetCraftingDamage()
  {
    return 0;
  }
  override bool CanAcceptTool(ItemBase item)
  {
    if (item.IsDamageDestroyed())
      return false;
    if (item.GetType() == "Hammer")
      return true;
    if (item.IsInherited(Pliers))
      return true;
    return super.CanAcceptTool(item);    
  }
};