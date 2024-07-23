class CfgPatches
{
    class SRP_Retextures_Gear_Consumables
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Gear_Consumables",
            "SRP_Core_Gear_Consumables"
        };
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
            "TheSurvivalists\Retextures\gear\consumables\data\garden_lime_espen_co.paa"
        };
    };
};