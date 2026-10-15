modded class PluginRecipesManager
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new IAT_CreateDeck_PlayingCards);
		RegisterRecipe(new IAT_CreateDeck_TarotCards);
		RegisterRecipe(new IAT_CreateDeck_CollectibleCards);
	}
};