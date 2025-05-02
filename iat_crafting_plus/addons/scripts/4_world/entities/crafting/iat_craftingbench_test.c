class IAT_CraftingPlus_CraftingBench_Test extends IAT_CraftingPlus_CraftingBench_Base
{
	override string GetWorkbenchManagerName()
	{
		return "TestManager";
	}
	override int GetCraftingDamage()
	{
		return 0;
	}
};