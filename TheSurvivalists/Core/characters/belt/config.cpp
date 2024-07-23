class CfgPatches
{
    class SRP_Core_Characters_Belts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Characters_Belts",
            "Alv_Tac_Gear_Belt",
            "Alv_Tac_Gear_Other" //rifle sling
        };
    };
};
class CfgVehicles
{
    class Clothing;

    //==================================================== MODDED OVERRIDE
    class AlV_MV_WarBelt_Colorbase : Clothing
    {
        weight = 1500;
    };
    class AlV_MV_DroplegBelt_Colorbase : Clothing
    {
        weight = 1500;
    };
    class ALV_MV_LeatherBelt_Colorbase : Clothing
    {
        weight = 1500;
    };
    class AlV_MV_DroplegBeltSingle_Colorbase : Clothing
    {
        weight = 1000;
    };
    class AlV_MV_WarBeltDropLeg_Colorbase : Clothing
    {
        weight = 1500;
    };
    class ALV_MV_RifleSling_Colorbase : Clothing
    {
        weight = 1500;
    };
};