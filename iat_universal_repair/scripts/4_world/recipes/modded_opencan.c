modded class OpenCan
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like can opener
		InsertIngredient(1,"IAT_UniversalRepair_MultiTool");
	}
};