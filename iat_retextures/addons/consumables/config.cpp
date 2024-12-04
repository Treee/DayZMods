class CfgPatches
{
    class IAT_Retextures_Consumables
    {
        requiredAddons[] = { "DZ_Gear_Consumables" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    //==================================================== VANILLA OVERRIDE
    class GardenLime : Inventory_Base
    {
        hiddenSelections[] =
        {
            "zbytek"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\consumables\data\garden_lime_espen_co.paa"
        };
    };
};