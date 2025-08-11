class CfgPatches
{
    class IAT_Retextures_ALV_Vests
    {
        requiredAddons[] = { "ACO_Upper_Vests" };
    };
};
class CfgVehicles
{
    class ALV_SkullMask_Colorbase;
    class ALV_AssaultHelmet_Colorbase;

    //==================================================== VANILLA RETEXTURES
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
