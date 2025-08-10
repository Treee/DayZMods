class CfgPatches
{
    class IAT_Retextures_ALV_Upper
    {
        requiredAddons[] = { "ACO_Upper_Tops" };
    };
};
class CfgVehicles
{
    class ALV_FlannelShirt_Colorbase;

    //==================================================== VANILLA RETEXTURES
    class ALV_FlannelShirt_Nekomain_chan : ALV_FlannelShirt_Colorbase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\alv_upper\data\FlannelShirt_nekomaid_chan_co.paa"
        };
    };
};
