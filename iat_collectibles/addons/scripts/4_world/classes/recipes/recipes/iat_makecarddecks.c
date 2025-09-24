class IAT_CreateDeck_Base extends RecipeBase
{
	override void Init()
	{
		m_Name = "Create Playing Card Deck";
		m_IsInstaRecipe = false;								// should this recipe be performed instantly without animation
		m_AnimationLength = 0.5;								// animation length in relative time units

		//conditions
		m_MinDamageIngredient[0]			= -1;				//-1 = disable check
		m_MaxDamageIngredient[0]			= -1;				//-1 = disable check
		m_MinQuantityIngredient[0]			= -1;				//-1 = disable check
		m_MaxQuantityIngredient[0]			= -1;				//-1 = disable check

		m_MinDamageIngredient[1]			= -1;
		m_MaxDamageIngredient[1]			= -1;
		m_MinQuantityIngredient[1]			= -1;
		m_MaxQuantityIngredient[1]			= -1;

		//----------------------------------------------------------------------------------------------------------------------
		//INGREDIENTS
		//ingredient 1
		// InsertIngredient(0,"IAT_PlayingCard_Colorbase");		// you can insert multiple ingredients this way

		m_IngredientAddHealth[0]			= 0;				// 0 = do nothing
		m_IngredientSetHealth[0]			= -1;				// -1 = do nothing
		m_IngredientAddQuantity[0]			= 0;				// 0 = do nothing
		m_IngredientDestroy[0]				= false;				// true = destroy, false = do nothing

		//ingredient 2
		InsertIngredient(1,"Paper");

		m_IngredientAddHealth[1]			= 0;
		m_IngredientSetHealth[1]			= -1;
		m_IngredientAddQuantity[1]			= 0;
		m_IngredientDestroy[1]				= true;

		//----------------------------------------------------------------------------------------------------------------------
		//RESULTS
		//result1
		// AddResult("IAT_CardDeck_Basic");									// add results here

		m_ResultSetFullQuantity[0]			= false;			// true = set full quantity, false = do nothing
		m_ResultSetQuantity[0]				= -1;				// -1 = do nothing
		m_ResultSetHealth[0]				= -1;				// -1 = do nothing
		m_ResultInheritsHealth[0]			= 1;				// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0]			= -1;				// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0]				= -2;				// (value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultReplacesIngredient[0]		= -1;				// (value) == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}
};

class IAT_CreateDeck_PlayingCards extends IAT_CreateDeck_Base
{
	override void Init()
	{
		super.Init();
		m_Name = "Create Playing Card Deck";

		InsertIngredient(0,"IAT_PlayingCard_Colorbase");		// you can insert multiple ingredients this way

		AddResult("IAT_CardDeck_Basic");									// add results here
	}
};
class IAT_CreateDeck_TarotCards extends IAT_CreateDeck_Base
{
	override void Init()
	{
		super.Init();
		m_Name = "Create Tarot Card Deck";

		InsertIngredient(0,"IAT_TarotCard_Colorbase");		// you can insert multiple ingredients this way

		AddResult("IAT_TarotCardDeck_Basic");									// add results here
	}
};
class IAT_CreateDeck_CollectibleCards extends IAT_CreateDeck_Base
{
	override void Init()
	{
		super.Init();
		m_Name = "Create Collectible Card Deck";

		InsertIngredient(0,"IAT_CollectibleCard_ColorBase");		// you can insert multiple ingredients this way

		AddResult("IAT_CollectibleDeck_Basic");									// add results here
	}
};