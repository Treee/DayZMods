modded class SplitBroom
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like sewing kit
		InsertIngredient(1,"IAT_UniversalRepair_MultiTool");
	}
};