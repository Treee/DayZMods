class CfgPatches
{
    class SRP_Core_Gear_Food
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Gear_Food"
        };
    };
};
class CfgVehicles
{
    class Edible_Base;

    //==================================================== VANILLA OVERRIDE
    class BoxCerealCrunchin : Edible_Base
    {
        canBeSplit = 1;
        weight = 2;
        itemSize[] = { 2,2 };
        inventorySlot[] +=
        {
            "Ingredient1",
                "Ingredient2",
                "Ingredient3",
                "Ingredient4",
                "Ingredient5",
                "Ingredient6",
                "Ingredient7",
                "Ingredient8",
        };
    };
    class SmallGuts : Edible_Base
    {
        weight = 8;
        inventorySlot[] +=
        {
            "Ingredient1",
                "Ingredient2",
                "Ingredient3",
                "Ingredient4",
                "Ingredient5",
                "Ingredient6",
                "Ingredient7",
                "Ingredient8",
        };
    };
    class Guts : Edible_Base
    {
        weight = 7;
        canBeSplit = 1;
        itemSize[] = { 2,1 };
        inventorySlot[] +=
        {
            "Ingredient1",
                "Ingredient2",
                "Ingredient3",
                "Ingredient4",
                "Ingredient5",
                "Ingredient6",
                "Ingredient7",
                "Ingredient8",
        };
    };
};


