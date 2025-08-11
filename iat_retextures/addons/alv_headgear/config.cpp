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
    class ALV_AssaultHelmet_Colorbase;

    //==================================================== VANILLA RETEXTURES
    class ALV_SkullMask_Kalli : ALV_SkullMask_Colorbase
    {
        scope = 2;
        // color = "Kalli";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\alv_headgear\data\skullMask_kalli_CO.paa" };
    };



    class ALV_AssaultHelmet_Black : ALV_AssaultHelmet_Colorbase
    {
        scope = 2;
        hiddenSelections[] =
        {
            "zbytek"
        };
        hiddenSelectionsTextures[] =
        {
            "ACO_Headgear\Characters\Headgear\data\AssaultHelmet_CO.paa"
        };
    };

    class ALV_6B25Vest_Black : ALV_6B25Vest_Colorbase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "ACO_Upper\Characters\Vests\Data\StagVest_CO.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "ACO_Upper\Characters\Vests\Data\StagVest.rvmat"
        };
    };
};
