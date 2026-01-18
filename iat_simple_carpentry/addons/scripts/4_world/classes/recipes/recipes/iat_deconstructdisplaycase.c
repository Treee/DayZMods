class IAT_CraftCarvedLetterKit extends RecipeBase
{
	override void Init()
	{
		m_Name = "Carve Wooden Letter";
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
		InsertIngredient(0,"Sickle");//you can insert multiple ingredients this way
		InsertIngredient(0,"KukriKnife");
		InsertIngredient(0,"FangeKnife");
		InsertIngredient(0,"Hacksaw");
		InsertIngredient(0,"HandSaw");
		InsertIngredient(0,"KitchenKnife");
		InsertIngredient(0,"SteakKnife");
		InsertIngredient(0,"StoneKnife");
		InsertIngredient(0,"Cleaver");
		InsertIngredient(0,"CombatKnife");
		InsertIngredient(0,"HuntingKnife");
		InsertIngredient(0,"Machete");
		InsertIngredient(0,"CrudeMachete");
		InsertIngredient(0,"OrientalMachete");
		InsertIngredient(0,"WoodAxe");
		InsertIngredient(0,"Hatchet");
		InsertIngredient(0,"FirefighterAxe");
		InsertIngredient(0,"Sword");
		InsertIngredient(0,"AK_Bayonet");
		InsertIngredient(0,"M9A1_Bayonet");
		InsertIngredient(0,"SKS_Bayonet");
		InsertIngredient(0,"BoneKnife");
		InsertIngredient(0,"Screwdriver");

		m_IngredientAddHealth[0]			= -2;				// 0 = do nothing
		m_IngredientSetHealth[0]			= -1;				// -1 = do nothing
		m_IngredientAddQuantity[0]			= 0;				// 0 = do nothing
		m_IngredientDestroy[0]				= false;				// true = destroy, false = do nothing

		//ingredient 2
		InsertIngredient(1,"Firewood");

		m_IngredientAddHealth[1]			= -5;
		m_IngredientSetHealth[1]			= -1;
		m_IngredientAddQuantity[1]			= 0;
		m_IngredientDestroy[1]				= true;

		//----------------------------------------------------------------------------------------------------------------------
		//RESULTS
		//result1
		AddResult("IAT_CarvedSymbol_Kit");									// add results here

		m_ResultSetFullQuantity[0]			= false;			// true = set full quantity, false = do nothing
		m_ResultSetQuantity[0]				= -1;				// -1 = do nothing
		m_ResultSetHealth[0]				= -1;				// -1 = do nothing
		m_ResultInheritsHealth[0]			= 1;				// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0]			= -1;				// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0]				= -2;				// (value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultReplacesIngredient[0]		= -1;				// (value) == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}
};