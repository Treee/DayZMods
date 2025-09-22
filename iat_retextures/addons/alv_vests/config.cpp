class CfgPatches
{
    class IAT_Retextures_ALV_Vests
    {
        requiredAddons[] = { "ACO_Upper_Vests" };
    };
};
class CfgVehicles
{
    class ALV_6B25Vest_Colorbase;

    //==================================================== VANILLA RETEXTURES
    class ALV_6B25Vest_nekomaid_chan : ALV_6B25Vest_Colorbase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_retextures\alv_vests\data\StagVest_nekomain_chan_CO.paa" };
    };
    class ALV_6B25Vest_grimstif : ALV_6B25Vest_Colorbase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_retextures\alv_vests\data\StagVest_grimstif_CO.paa" };
    };
};
