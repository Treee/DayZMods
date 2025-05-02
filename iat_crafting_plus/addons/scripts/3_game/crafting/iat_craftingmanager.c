class IAT_CraftingItemRequirement
{
	protected string m_AttachmentSlotName;
	protected string m_RequiredColor;
	protected int m_RequiredQuantity;
	protected bool m_ReduceHP; // flag to swap dmg from quantity to hp
	protected bool m_IsProtectedItem; // some attachments are enhancements on the bench and should not be consumed per craft or at all

	void IAT_CraftingItemRequirement(string attachmentSlotName, string requiredColor="", int requiredQuantity=1, bool reducehp=false, bool isProtected=false)
	{
		m_AttachmentSlotName = attachmentSlotName;
		m_RequiredColor = requiredColor;
		m_RequiredQuantity = requiredQuantity;
		m_ReduceHP = reducehp;
		m_IsProtectedItem = isProtected;
	}

	bool IsRequirementMatch(IAT_CraftingItemRequirement requirement)
	{
		bool correctAttachment = IsAttchmentMatch(requirement.GetAttachmentSlotName());
		bool correctColor = IsColorMatch(requirement.GetRequiredColor());
		bool correctQuantity = IsQuantityMatch(requirement.GetRequiredQuantity());

		if (GetRequiredColor() == "")
			correctColor = true;

		return correctAttachment && correctColor && correctQuantity;
	}

	bool IsAttchmentMatch(string otherAttachmentName)
	{
		// PrintFormat("expected: %1 actual: %2", m_AttachmentSlotName, otherAttachmentName);
		return m_AttachmentSlotName == otherAttachmentName;
	}
	bool IsColorMatch(string otherColor)
	{
		m_RequiredColor.ToLower();
		otherColor.ToLower();
		// PrintFormat("expected: %1 actual: %2", m_RequiredColor, otherColor);
		return m_RequiredColor == otherColor;
	}
	bool IsQuantityMatch(int otherQuantity)
	{
		// PrintFormat("expected: %1 < actual: %2", m_RequiredQuantity, otherQuantity);
		return m_RequiredQuantity <= otherQuantity;
	}
	string GetAttachmentSlotName()
	{
		return m_AttachmentSlotName;
	}
	string GetRequiredColor()
	{
		return m_RequiredColor;
	}
	int GetRequiredQuantity()
	{
		return m_RequiredQuantity;
	}
	bool ShouldReduceHP()
	{
		return m_ReduceHP;
	}
	bool IsProtectedItem()
	{
		return m_IsProtectedItem;
	}
	string PrintDebug()
	{
		return string.Format("Slot: %1 Color: %2 Quantity: %3 HpReduction: %4", GetAttachmentSlotName(), GetRequiredColor(), GetRequiredQuantity(), ShouldReduceHP());
	}
};
class IAT_CraftingResult
{
	protected string m_ItemClassName;
	protected float m_ItemQuantity;
	protected float m_ItemHP;
	// protected int m_WetnessLevel;
	// protected int m_FoodStage;
	// protected int m_Agents; // For adding kuru or something to an item or w/e
	// protected int m_LiquidType; // for liquid results

	// negative numbers denote default max values (quantity and hp)
	void IAT_CraftingResult(string name, float quantity = -1.0, float hp = -1.0)
	{
		m_ItemClassName = name;
		m_ItemQuantity = quantity;
		m_ItemHP = hp;
	}
	// ==================================================================================
	// Helpers
	// ==================================================================================
	float GetExpectedQuantity(int max)
	{
		if (m_ItemQuantity == -1)
		{
			return max;
		}
		return m_ItemQuantity;
	}
	float GetExpectedHP(int max)
	{
		if (m_ItemHP == -1)
		{
			return max;
		}
		return m_ItemHP;
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	string GetResultClassName()
	{
		return m_ItemClassName;
	}
	float GetResultQuantity()
	{
		return m_ItemQuantity;
	}
	float GetResultItem()
	{
		return m_ItemHP;
	}
};

class IAT_CraftingRecipe
{
  	protected string m_DisplayName;
	protected string m_RequiredTool;
	protected int m_ToolDamagePerCraft;
	protected int m_ToolQuantityPerCraft;
	protected ref array<ref IAT_CraftingItemRequirement> m_RequiredIngredients;
	protected ref array<ref IAT_CraftingResult> m_RecipeResults;

	void IAT_CraftingRecipe(string name, string requiredTool, int dmg = 0, int quantity = 0)
	{
		m_DisplayName = name;
		m_RequiredTool = requiredTool;
		m_ToolDamagePerCraft = dmg;
		m_ToolQuantityPerCraft = quantity;
		if (!m_RequiredIngredients)
		{
			m_RequiredIngredients = new array<ref IAT_CraftingItemRequirement>;
		}
		if (!m_RecipeResults)
		{
			m_RecipeResults = new array<ref IAT_CraftingResult>;
		}
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	void InsertCraftingRequirement(IAT_CraftingItemRequirement newRequirement)
	{
		m_RequiredIngredients.Insert(newRequirement);
	}
	void InsertCraftingResult(IAT_CraftingResult newResult)
	{
		m_RecipeResults.Insert(newResult);
	}
	bool CompareToOtherIngredients(IAT_CraftingRecipe otherCraftable)
	{
		bool isCompleteMatch = true;
		bool isIngredientMatch = false;
		array<ref IAT_CraftingItemRequirement> otherCraftingIngredients = otherCraftable.GetCraftingItemRequirements();
		// start with my ingredients
		// Print("===========================START===============================");
		// PrintRecipe();

		foreach(IAT_CraftingItemRequirement ingredient : m_RequiredIngredients)
		{
			// Print(ingredient.PrintDebug());
			// Print("compared against");
			// look at all the other ingredients
			foreach(IAT_CraftingItemRequirement otherIngredient : otherCraftingIngredients)
			{
				// Print(otherIngredient.PrintDebug());
				// if there is a match
				if (ingredient.IsRequirementMatch(otherIngredient))
				{
					// Print("=============== MATCH ====================");
					// set we matched to true; break out of the inner for loop
					isIngredientMatch = true;
					break;
				}
				// Print("=============== NO MATCH ====================");
			}
			// if the other ingredients have a match
			if (isIngredientMatch)
			{
				// reset the boolean flag for ingredients
				isIngredientMatch = false;
				isCompleteMatch &= true;
				continue;
			}
			else
			{
				// Print("===============SHORT CIRUCIT ============================");
				// the other craftable has no ingredients that match this; break loop
				isCompleteMatch &= false;
				break;
			}
		}
		// PrintFormat("===========================End=============================== %1", isCompleteMatch);
		return isCompleteMatch;
	}
	void PrintRecipe()
	{
		PrintFormat("Recipe: %1 crafted by %2 with %3 tool dmg per craft or %4 quantity per craft.", m_DisplayName, m_RequiredTool, m_ToolDamagePerCraft, m_ToolQuantityPerCraft);
	}
	void PrintRecipeIngredients()
	{
		foreach(IAT_CraftingItemRequirement itemRequirement : m_RequiredIngredients)
		{
			Print(itemRequirement.PrintDebug());
		}
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	string GetDisplayName()
	{
		return m_DisplayName;
	}
	string GetRequiredTool()
	{
		return m_RequiredTool;
	}
	int GetToolDamagePerCraft()
	{
		return m_ToolDamagePerCraft;
	}
	int GetToolQuantityPerCraft()
	{
		return m_ToolQuantityPerCraft;
	}
	array<ref IAT_CraftingItemRequirement> GetCraftingItemRequirements()
	{
		return m_RequiredIngredients;
	}
	array<ref IAT_CraftingResult> GetCraftingResults()
	{
		return m_RecipeResults;
	}
};

class IAT_RecipeManager
{
	protected string m_ManagerName;
	protected ref array<ref IAT_CraftingRecipe> m_CraftingRecipes;

	void IAT_RecipeManager(string name)
	{
		m_ManagerName = name;
		Init();
	}
	void Init()
	{
		if (!m_CraftingRecipes)
		{
			m_CraftingRecipes = new array<ref IAT_CraftingRecipe>;
		}
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	bool IsRecipeMatch(IAT_CraftingRecipe otherCraftable, out array<IAT_CraftingRecipe> craftableResults)
	{
		foreach(IAT_CraftingRecipe craftableItem : m_CraftingRecipes)
		{
			if (craftableItem.CompareToOtherIngredients(otherCraftable))
			{
				craftableResults.Insert(craftableItem);
				// PrintFormat("==============================Found Recipe Match %1", craftableItem.GetDisplayName());
			}
		}
		return craftableResults.Count() > 0;
	}

	void InsertCraftingRecipe(IAT_CraftingRecipe newRecipe)
	{
		m_CraftingRecipes.Insert(newRecipe);
	}

	void PrintRecipes()
	{
		// Print("All Recipes");
		foreach(IAT_CraftingRecipe craftableItem : m_CraftingRecipes)
		{
			craftableItem.PrintRecipe();
			craftableItem.PrintRecipeIngredients();
		}
	}

	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	array <ref IAT_CraftingRecipe> GetCraftingRecipes()
	{
		return m_CraftingRecipes;
	}

	string GetRecipeManagerName()
	{
		return m_ManagerName;
	}
};