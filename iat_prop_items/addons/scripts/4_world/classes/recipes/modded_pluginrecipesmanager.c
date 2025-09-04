modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new IAT_CraftLegCast);
		RegisterRecipe(new IAT_CraftLegCast_Permanent);
		RegisterRecipe(new IAT_CraftFlagBelt);
		RegisterRecipe(new IAT_DismantleLadder);
	}
};