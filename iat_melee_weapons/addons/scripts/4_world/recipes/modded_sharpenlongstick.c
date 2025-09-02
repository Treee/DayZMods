modded class SharpenLongStick
{
	override void Init()
	{
		// make sure existing behavior is set up
		super.Init();

		// multi tool is like can opener
		InsertIngredient(1,"IAT_Narsil_Colorbase");
		InsertIngredient(1,"IAT_DamascusBowieKnife_Colorbase");
	}
};