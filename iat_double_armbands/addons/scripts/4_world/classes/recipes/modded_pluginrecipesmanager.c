modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new IAT_CraftDoubleArmband);
		RegisterRecipe(new IAT_DeCraftDoubleArmband);
	}
};