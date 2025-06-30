modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new IAT_CraftLegCast);
		RegisterRecipe(new IAT_CraftLegCast_Permanent);
	}
};