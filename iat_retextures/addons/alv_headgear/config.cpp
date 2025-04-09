class CfgPatches
{
    class IAT_Retextures_ALV_Headgear
    {
        requiredAddons[] = { "ACO_Headgear_Masks" };
    };
};
class CfgVehicles
{
    class ALV_SkullMask_Colorbase;

    //==================================================== VANILLA RETEXTURES
    class ALV_SkullMask_Kalli : ALV_SkullMask_Colorbase
    {
        scope = 2;
        // color = "Kalli";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\alv_headgear\data\skullMask_kalli_CO.paa" };
    };
};
