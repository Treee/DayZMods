class CfgPatches
{
    class SRP_Core_Gear_Tools
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Gear_Tools",
            "Survivalists_Mods_Gear_Tools"
        };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    //==================================================== VANILLA OVERRIDE
    class LeatherSewingKit : Inventory_Base
    {
        canBeSplit = 1;
        itemSize[] = { 2,2 };
        weight = 12;
        // weightPerQuantityUnit = 0.01;
    };
    class SewingKit : Inventory_Base
    {
        canBeSplit = 1;
        weight = 2.1;
        // weightPerQuantityUnit = 0.01;
    };
    class EpoxyPutty : Inventory_Base
    {
        canBeSplit = 1;
        weight = 0.2;
        varStackMax = 100;
        varQuantityMax = 5000;
        inventorySlot[] += {"SRP_Construction_Epoxy"};
    };
    class WeaponCleaningKit : Inventory_Base
    {
        descriptionShort = "Useful tools for cleaning a weapon or salvaged part. Well oiled mechanisms are proven to reduce the chance of jamming.";
        canBeSplit = 1;
        weight = 8;
        itemSize[] = { 2,2 };
    };
};