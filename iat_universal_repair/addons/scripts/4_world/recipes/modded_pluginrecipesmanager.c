modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
        RegisterRecipe(new IAT_UniversalRepair_RepairItem);
	}
};