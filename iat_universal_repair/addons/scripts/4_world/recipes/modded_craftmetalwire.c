modded class CraftMetalWire
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like pliers
		InsertIngredient(1,"IAT_UniversalRepair_MultiTool");
	}
};