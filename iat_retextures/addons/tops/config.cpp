class CfgPatches
{
    class IAT_Retextures_Tops
    {
        requiredAddons[] = { "DZ_Characters_Tops" };
    };
};
class CfgVehicles
{
    class ManSuit_ColorBase;
    //==================================================== VANILLA RETEXTURES
    class ManSuit_Gringo : ManSuit_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_retextures\tops\data\mansuit_jacket_gringo_co.paa","iat_retextures\tops\data\mansuit_jacket_gringo_co.paa","iat_retextures\tops\data\mansuit_jacket_gringo_co.paa" };
    };
    class ManSuit_Salmon : ManSuit_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_retextures\tops\data\mansuit_jacket_salmon_co.paa","iat_retextures\tops\data\mansuit_jacket_salmon_co.paa","iat_retextures\tops\data\mansuit_jacket_salmon_co.paa" };
    };
};