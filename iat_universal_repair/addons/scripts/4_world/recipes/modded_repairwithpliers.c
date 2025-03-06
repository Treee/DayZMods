modded class RepairWithPliers
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like pliers
		InsertIngredient(0,"IAT_UniversalRepair_MultiTool");
	}
};