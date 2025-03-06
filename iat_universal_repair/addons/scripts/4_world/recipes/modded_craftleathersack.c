modded class CraftLeatherSack
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like leather sewing kit
		InsertIngredient(1,"IAT_UniversalRepair_MultiTool");
	}
};