modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new IAT_CraftLegCast);
		RegisterRecipe(new IAT_CraftLegCast_Permanent);
		RegisterRecipe(new IAT_CraftFlagBelt);
		RegisterRecipe(new IAT_DismantleLadder);
		RegisterRecipe(new IAT_CraftSmokeGrenade_Red);
		RegisterRecipe(new IAT_CraftSmokeGrenade_Green);
		RegisterRecipe(new IAT_CraftSmokeGrenade_Yellow);
		RegisterRecipe(new IAT_CraftSmokeGrenade_Purple);
		RegisterRecipe(new IAT_CraftSmokeGrenade_White);
		RegisterRecipe(new IAT_CraftSmokeGrenade_Black);
	}
};
