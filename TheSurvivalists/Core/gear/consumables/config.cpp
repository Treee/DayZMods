class CfgPatches
{
    class SRP_Core_Gear_Consumables
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Gear_Consumables",
            "Survivalists_Gaming_Gear_Consumables",
            "Survivalists_MasonryMetallurgy_Gear_Consumables",
            "Notes_Gear" //WrittenNote from Notes
        };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    class Box_Base;

    //==================================================== VANILLA OVERRIDE
    class DuctTape : Inventory_Base
    {
        canBeSplit = 1;
        itemSize[] = { 1,2 };
        weight = 5;
    };
    class GardenLime : Inventory_Base
    {
        canBeSplit = 1;
        itemSize[] = { 2,3 };
        weight = 1;
    };
    class NailBox : Box_Base
    {
        weight = 1414;
    };
    class Nail : Inventory_Base
    {
        varStackMax = 99;
        varQuantityMax = 990;
        weight = 20.20;
        inventorySlot[] +=
        {
            "SRP_Construction_Nails"
        };
    };
    class Stone : Inventory_Base
    {
        varQuantityMax = 400;
        weight = 1000;
        inventorySlot[] += {"SRP_Construction_Stone", "StonesFlagTax"};
    };

    //==================================================== MODDED OVERRIDE
    class SRP_GamingToken_ColorBase : Inventory_Base
    {
        weight = 0.25;
    };
    class SRP_Coinage_Iron : Inventory_Base
    {
        weight = 0.5;
    };
    class SRP_Coinage_BrassBlank : Inventory_Base
    {
        weight = 0.6;
    };
    class SRP_Coinage_Bronze : Inventory_Base
    {
        weight = 0.65;
    };
    class SRP_Coinage_Copper : Inventory_Base
    {
        weight = 0.8;
    };
    class SRP_Coinage_Gold : Inventory_Base
    {
        weight = 0.12;
    };
    class SRP_Coinage_GoldWorn : Inventory_Base
    {
        weight = 0.12;
    };
    class SRP_Coinage_Platinum : Inventory_Base
    {
        weight = 0.15;
    };

    // wardog note override
    class WrittenNote : Inventory_Base
    {
        weight = 2;
        inventorySlot[] = { "Paper" };
    };
};