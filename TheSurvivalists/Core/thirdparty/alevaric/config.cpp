class CfgPatches
{
    class SRP_Core_ThirdParty_Alevaric
    {
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "Alv_Tac_Gear_Other" };
    };
};

class CfgVehicles
{
    class Clothing;

    // ----------------------  MODDED OVERRIDES
    class ALV_MV_Roman_Vest_Colorbase : Clothing
    {
        weight = 6000;
    };
    class ALV_MV_Roman_Vest_2_Colorbase : Clothing
    {
        weight = 6000;
    };
    class ALV_MV_Roman_Boots_Colorbase : Clothing
    {
        weight = 3000;
    };
    class ALV_MV_Roman_Helmet_Colorbase : Clothing
    {
        weight = 3000;
    };
    class ALV_MV_Roman_Cloak_Colorbase : Clothing
    {
        weight = 2500;
    };
    class ALV_MV_Roman_Belt_Colorbase : Clothing
    {
        weight = 1000;
    };
    class ALV_MV_Roman_Shoulder_Colorbase : Clothing
    {
        weight = 4500;
    };
};