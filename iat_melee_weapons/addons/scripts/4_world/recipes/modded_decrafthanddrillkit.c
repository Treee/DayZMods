modded class DeCraftHandDrillKit
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like can opener
		InsertIngredient(1,"IAT_Narsil_ColorBase");
		InsertIngredient(1,"IAT_DamascusBowieKnife_ColorBase");
		InsertIngredient(1,"IAT_TrenchKnife_ColorBase");
		InsertIngredient(1,"IAT_MorgulBlade_ColorBase");
	}
};