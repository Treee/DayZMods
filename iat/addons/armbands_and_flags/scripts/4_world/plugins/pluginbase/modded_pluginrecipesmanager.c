modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();				// Calling base RegisterRecipies()
		UnregisterRecipe("CraftArmbandRag");	// Removing an existing recipe
	}
};