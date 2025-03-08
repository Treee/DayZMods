modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();

        RegisterRecipe(new IAT_DecraftBook_Paper);
        RegisterRecipe(new IAT_CraftNoteBook);
	}
};