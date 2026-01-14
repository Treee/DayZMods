class IAT_DeconstructDisplayCase extends RecipeBase
{
	override void Init()
	{
		m_Name = "Deconstruct Display Case";
		m_IsInstaRecipe = false;								// should this recipe be performed instantly without animation
		m_AnimationLength = 0.5;								// animation length in relative time units

		//conditions
		m_MinDamageIngredient[0]			= -1;				//-1 = disable check
		m_MaxDamageIngredient[0]			= 3;				//-1 = disable check
		m_MinQuantityIngredient[0]			= -1;				//-1 = disable check
		m_MaxQuantityIngredient[0]			= -1;				//-1 = disable check

		m_MinDamageIngredient[1]			= -1;
		m_MaxDamageIngredient[1]			= -1;
		m_MinQuantityIngredient[1]			= -1;
		m_MaxQuantityIngredient[1]			= -1;

		//----------------------------------------------------------------------------------------------------------------------
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"IAT_DisplayCase_ColorBase");		// you can insert multiple ingredients this way

		m_IngredientAddHealth[0]			= 0;				// 0 = do nothing
		m_IngredientSetHealth[0]			= -1;				// -1 = do nothing
		m_IngredientAddQuantity[0]			= 0;				// 0 = do nothing
		m_IngredientDestroy[0]				= true;				// true = destroy, false = do nothing

		//ingredient 2
		InsertIngredient(1,"Pliers");
		InsertIngredient(1,"Screwdriver");
		InsertIngredient(1,"Hammer");

		m_IngredientAddHealth[1]			= -5;
		m_IngredientSetHealth[1]			= -1;
		m_IngredientAddQuantity[1]			= 0;
		m_IngredientDestroy[1]				= false;

		//----------------------------------------------------------------------------------------------------------------------
		//RESULTS
		//result1
		AddResult("IAT_DisplayCaseKit_");									// add results here

		m_ResultSetFullQuantity[0]			= false;			// true = set full quantity, false = do nothing
		m_ResultSetQuantity[0]				= -1;				// -1 = do nothing
		m_ResultSetHealth[0]				= -1;				// -1 = do nothing
		m_ResultInheritsHealth[0]			= 0;				// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0]			= 0;				// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0]				= -2;				// (value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultReplacesIngredient[0]		= -1;				// (value) == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		// only allow if there is nothing inside AND is not locked
		IAT_DisplayCase_ColorBase displayCase;
		if (Class.CastTo(displayCase, ingredients[0]))
		{
			// if the display case is not empty, short circuit
			if (!displayCase.IsEmpty())
			{
				return false;
			}
			// if the display case is locked, short circuit
			if (displayCase.IAT_IsDisplayCaseLocked())
			{
				return false;
			}
			return true;
		}
		return false;
	}
};