# What Is Crafting Plus?

Crafting Plus is a _simple_ framework that allows advanced recipes with multiple ingredients. DayZ vanilla is currently limited to the combination of **only** two items at a time with a `configurable` maximum of 20 recipes per combination. Crafting Plus allows any object to serve as a crafting workbench given a list of attachments. Like vanilla, you register recipes with ingredients on slots and required quantities for a specific crafted item along with the expected tool for the workbench. Players are then able to use the tools provided to craft advanced recipes.

# How To Use

## JSON Config

The recipes of this mod are controlled by a server side json that is sent to the clients when they connect. This allows for dynamic recipes on each server restart AND uncrackable recipes from curious or knowledgable players. You will find the json in your server profile folder after first mod start. `$profile:\ItsATreeMods\CraftingPlusConfig.json`

### Creating A New Recipe

To create a new recipe take the template provided below or in the json and apply the required properties of the recipe. The first run of the mod will generate a template json with 5 example recipes if the below is not sufficient.

```json
[
    {
        // The unique identifier for your workbenches recipes. This is how you make different recipe sets for multiple benches
        "m_ManagerName": "TestManager",
        // The array/list of recipes associated with the bench
        "m_CraftingRecipes": [
            {
                // The unique display name for a given recipe. This is shown as "Craft - Display Name".
                "m_DisplayName": "Single Item Result",
                // The tool required to craft the recipe. Empty string "" for any item in hands to work.
                "m_RequiredTool": "Hammer",
                // The damage to apply to the tool in hands per craft. 0 for no damage
                "m_ToolDamagePerCraft": 2,
                // The quantity to remove from the tool per craft. 0 for no quantity
                "m_ToolQuantityPerCraft": 0,
                // The array/list of required attached ingredients for the craft prompt to show.
                "m_RequiredIngredients": [
                    {
                        // The slot name of the bench required
                        "m_AttachmentSlotName": "Material_WoodenLogs",
                        // The color="xxx" requirement if desired
                        "m_RequiredColor": "",
                        // The expected quantity to be attached.
                        "m_RequiredQuantity": 1,
                        // This bool toggles whether the craft does quantity or hp dmg on result. Some items are hp only with no quantity.
                        "m_ReduceHP": 0,
                        // This bool toggles whether the ingredient is "protected" and not consumed or damaged on craft. Some attachments are "augments" not meant to be destroyed
                        "m_IsProtectedItem": 0
                    }
                    //.... More required ingredients defined
                ],
                // This is the array/list of results to spawn when the craft is successful
                "m_RecipeResults": [
                    {
                        // The config.cpp classname name of the item to spawn
                        "m_ItemClassName": "SewingKit",
                        // The quantity to spawn the item with. -1 for max
                        "m_ItemQuantity": 50.0,
                        // The hp to spawn the item with. -1 for max
                        "m_ItemHP": 75.0
                    }
                    //.... More results defined
                ]
            }
            //..... More recipes defined
        ]
    }
]
```

## Making a Workbench

The amount of code needed to make your own bench is very small. You just need to inherit from `IAT_CraftingPlus_CraftingBench_Base` and override 2 methods.

1. `GetWorkbenchManagerName`
2. `GetCraftingDamage`

```c++
class Your_Workbench_Classname extends IAT_CraftingPlus_CraftingBench_Base
{
  // The method that connects the json recipe list to your workbench. Note the names should match exactly as shown in the json.
	override string GetWorkbenchManagerName()
	{
		return "TheNameOfYourRecipeManager_ProbablySomethingCloseToYourWorkbenchNameOrRecipes";
	}
  // The amount of damage to apply to the bench per craft. Some benches need to degenerate over time and this allows that to happen.
	override int GetCraftingDamage()
	{
		return 0;
	}
};
```

## Wrapup

That is it! Compared to the first version of this mod the setup is FAR simpler and can be mostly done in a text editor. Feel free to send feedback on areas that are unclear.
