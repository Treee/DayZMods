modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new IAT_CraftMoreDoorKit_AllOptions);
		RegisterRecipe(new IAT_CraftMoreDoorKit_WoodOnly);
		RegisterRecipe(new IAT_CraftMoreDoorKit_MetalOnly);
		RegisterRecipe(new IAT_CraftMoreDoorKit_IronOnly);
	}
};