modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();

		RegisterRecipe(new IAT_ConvertShovelToMiner);
		RegisterRecipe(new IAT_ConvertMinerToShovel);
	}
}