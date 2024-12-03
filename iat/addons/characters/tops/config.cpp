class CfgPatches
{
    class IAT_Characters_Tops
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Characters_Tops",
        };
    };
};
class CfgVehicles
{
    class ManSuit_ColorBase;
    //==================================================== VANILLA RETEXTURES
    class ManSuit_Gringo : ManSuit_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat\characters\tops\data\mansuit_jacket_gringo_co.paa","iat\characters\tops\data\mansuit_jacket_gringo_co.paa","iat\characters\tops\data\mansuit_jacket_gringo_co.paa" };
    };
    class ManSuit_Salmon : ManSuit_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat\characters\tops\data\mansuit_jacket_salmon_co.paa","iat\characters\tops\data\mansuit_jacket_salmon_co.paa","iat\characters\tops\data\mansuit_jacket_salmon_co.paa" };
    };
};