# What Is Crafting Plus?

Crafting Plus is a _simple_ framework that allows advanced recipes with multiple ingredients. DayZ vanilla is currently limited to the combination of **only** two items at a time with a `configurable` maximum of 20 recipes per combination. Crafting Plus allows any object to serve as a crafting workbench given a list of attachments. Like vanilla, you register recipes with ingredients on slots and required quantities for a specific crafted item along with the expected tool for the workbench. Players are then able to use the tools provided to craft advanced recipes.

# How To Use

## 3_Game

### Crafting Variant Enums

As crafting evolved with this mod it became obvious that certain parent items serve as a base and children items are considered variants that follow the `ColorBase` pattern. In order to provide a solution that removes typos, I use enums to handle the variants of items. An example of why this is necessary, take for example farming system that allows a player to gather many types of herbs with different colors. Without the enum system you would be unable to define the ingredient requirement of a specific color in a specific slot. `IAT_CraftingPlusEnums` mod is meant to be modified and repacked with your specific color variants for use in the `IAT_RecipeManager` class.

`ModRoot\scripts\3_game\your_enums.c`

```c++
enum IAT_COLOR
{
  NONE=-1, // base case
  COPPER, //metals
  TIN,
  BRONZE,
  //.....
  SOME,
  CUSTOM,
  VALUES,
  GO,
  HERE,
  ALWAYS,
  ADD,
  AT,
  THE,
  END,
};
```

### Creating A New Recipe

To create a new recipe take the template provided below or in the mod and follow the below format. A description of the class `new IAT_ItemRequirement(ATTACHMENT_SLOT_NAME, COLOR ENUM, QUANTITY)`

`ITEM_CLASS_NAME` - The class name of the result. Copy/Paste the type name from config.cpp.

`ITEM_DISPLAY_NAME` - The name of the item displayed in the crafting action prompt.

`ATTACHMENT_SLOT_NAME` - The slot name of required ingredient.

`ENUM` - The color variant of ingredient. For ingredients with no variant use `IAT_COLOR.NONE`.

`QUANTITY` - The quantity of ingredient needed. Relative to the quantity type (percentage, count). Items with no "quantity" should use the value 1; ie. metal wire/rope.

`ModRoot\scripts\3_game\crafting\your_crafting_recipes_workbench1.c`

```c++
class Your_Crafting_Recipes_Workbench1 extends IAT_RecipeManager
{
  //...

  IAT_CraftableItem Register_X_Recipe()
  {
    IAT_CraftableItem craftableItem = new IAT_CraftableItem("ITEM_CLASS_NAME", "ITEM_DISPLAY_NAME");
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 2));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
    return craftableItem;
  }
};
```

Here is an example of me using vanilla slots and items to make a random crafting recipe.

```c++
class Your_Crafting_Recipes_Workbench1 extends IAT_RecipeManager
{
  //...

  IAT_CraftableItem Register_TestBenchRecipe_Recipe()
  {
    IAT_CraftableItem craftableItem = new IAT_CraftableItem("WoodenLog", "Wooden Log");
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_WoodenLogs", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_L1_WoodenPlanks", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_MetalSheets", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("Material_Shelter_Fabric", IAT_COLOR.NONE, 1));
    craftableItem.RegisterIngredient(new IAT_ItemRequirement("MetalWire", IAT_COLOR.NONE, 1));
    return craftableItem;
  }
};
```

### Registering Recipes

I wanted to keep registering recipes as close to the vanilla workflow as possible. The `IAT_RecipeManager` has an `init` function where you place recipes to be registered to the manager. To register a new recipe, add it to the list by `creatableItems.Insert(Recipe_Method_Invoke());`

`ModRoot\scripts\3_game\crafting\your_crafting_recipes_workbench1.c`

```c++
class Your_Crafting_Recipes_Workbench1 extends IAT_RecipeManager
{
  override void Init()
  {
    super.Init();
    // Register my new recipes
    craftableItems.Insert(Register_TestBenchRecipe_Recipe());
    craftableItems.Insert(Register_TestBenchRecipe1_Recipe());
    craftableItems.Insert(Register_TestBenchRecipe2_Recipe());
  }

  //... recipes defined below
};
```

### (Optional) Adding Multiple Workbench Recipe Lists

For most users a single workbench will satisfy their need, hwoever, in some cases advanced users will want to use this crafting system for many workbenches (such as myself). The connection between 3_game and 4_world is held within `class DayZGame` with a strong reference held by the class `m_TestWorkbenchRecipes`. This object will load the recipes on server start and expose it to the default workbench provided by this mod. If you want to add multiple lists you can copy/paste/follow the template here or create your own recipe manager class that handles recipe list logic by workbenche. There are many ways to do the above and I purposfully left it out to allow other users to define what works best for them.

`ModRoot\scripts\3_game\modded_dayzgame.c`

```c++
modded class DayZGame
{
  // Reference to the recipes loaded on game start.
  // Protected on purpose to enforce getter/setter
  protected ref IAT_TestWorkbenchRecipes m_TestWorkbenchRecipes;

  void DayZGame()
  {
    // Initialize recipes and store into variable
    m_TestWorkbenchRecipes = new IAT_TestWorkbenchRecipes();
  }
  // This method is called in the workbench. Connects 3_game to 4_world in the action
  IAT_TestWorkbenchRecipes GetIATTestWorkbenchRecipes()
  {
    return m_TestWorkbenchRecipes;
  }
};
```

## 4_world

Once the recipes are registered you need a few things to enable crafting for the player.

- A workbench that which a player can attach ingredients.
- A tool that will interact with the workbench.

### Workbench

I provide a `test` class workbench in this mod you can use to serve as the foundation of your first bench. It contains the smallest amount of code to make the bench work with pliers **AND** hammer using the recipe list included in this pbo.

`ModRoot\scripts\4_world\entities\your_craftingbench_test.c`

```c++
// Classname of your workbench.           make sure it extends the crafting bench base
class IAT_CraftingPlus_CraftingBench_Test extends IAT_CraftingPlus_CraftingBench_Base
{
  // (optional) this function returns which recipe list should be searched on crafting action
  override IAT_RecipeManager GetRecipeManager()
  {
    return GetDayZGame().GetIATTestWorkbenchRecipes();
  }
  // (optional) values greater than 0 will cause damage to the workbench per craft.
  override int GetCraftingDamage()
  {
    return 0;
  }
  // this function controls what item can be accepted with the bench.
  // somewhat redundant when crafting action is not on ItemBase but I leave that decision to you.
  override bool CanAcceptTool(ItemBase item)
  {
    if (item.IsDamageDestroyed())
      return false;
    if (item.GetType() == "Hammer")
      return true;
    if (item.IsInherited(Pliers))
      return true;
    return super.CanAcceptTool(item);
  }
};
```

### Tool

There can be many tools registered to a workbench or multiple benches. In order to connect the crafting action from tool to bench you will need to add `the following action to all tools`.

`AddAction(IAT_ActionCraftOnWorkbench);`

An example of me adding the crafting action to a hammer is seen below. I have omitted the pliers action to showcase the need for both workbench and tool action to be connected.

`ModRoot\scripts\4_world\entities\tools\modded_hammer.c`

```c++
modded class Hammer
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionCraftOnWorkbench);
	}
};
```

# Wrapup

If you didn't pay attention to anything until now. To use this crafting framework you need the following in order to create recipes and add them to the list of craftables.

## Enums (3_game)

```c++
enum IAT_COLOR
{
  NONE=-1, // base case
  COPPER, //metals
  //.....
};
```

## Recipes (3_game)

```c++
IAT_CraftableItem Register_X_Recipe()
{
  IAT_CraftableItem craftableItem = new IAT_CraftableItem("ITEM_CLASS_NAME", "ITEM_DISPLAY_NAME");
  craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 1));
  craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 1));

  craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 2));
  craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
  craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
  craftableItem.RegisterIngredient(new IAT_ItemRequirement("ATTACHMENT_SLOT_NAME", IAT_COLOR.NONE, 4));
  return craftableItem;
}
```

## Recipe Registration (3_game)

```c++
override void Init()
{
  super.Init();
  // Register my new recipes
  craftableItems.Insert(Register_TestBenchRecipe_Recipe());
  craftableItems.Insert(Register_TestBenchRecipe1_Recipe());
  craftableItems.Insert(Register_TestBenchRecipe2_Recipe());
}
```

## Workbench (4_world)

```c++
class Your_Workbench_Classname extends IAT_CraftingPlus_CraftingBench_Base{};
```

## Tool Action (4_world)

```c++
// Modded only required if overriding an existing class.
modded class Some_Tool
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_ActionCraftOnWorkbench);
	}
};
```
