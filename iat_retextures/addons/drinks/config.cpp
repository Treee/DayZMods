class CfgPatches
{
    class IAT_Retextures_Drinks
    {
        requiredAddons[] = { "DZ_Data", "DZ_Gear_Drinks" };
    };
};
class CfgVehicles
{
    class Canteen;

    //==================================================== VANILLA OVERRIDE
    class Canteen_Blue : Canteen { scope = 2; hiddenSelections[] = { "zbytek" };hiddenSelectionsTextures[] = { "iat_retextures\drinks\data\iat_canteen_blue_co.paa" }; };
    class Canteen_Pink : Canteen { scope = 2; hiddenSelections[] = { "zbytek" };hiddenSelectionsTextures[] = { "iat_retextures\drinks\data\iat_canteen_pink_co.paa" }; };
    class Canteen_Purple : Canteen { scope = 2; hiddenSelections[] = { "zbytek" };hiddenSelectionsTextures[] = { "iat_retextures\drinks\data\iat_canteen_purple_co.paa" }; };
    class Canteen_Neon : Canteen { scope = 2; hiddenSelections[] = { "zbytek" };hiddenSelectionsTextures[] = { "iat_retextures\drinks\data\iat_canteen_neon_co.paa" }; };
    class Canteen_Red : Canteen { scope = 2; hiddenSelections[] = { "zbytek" };hiddenSelectionsTextures[] = { "iat_retextures\drinks\data\iat_canteen_red_co.paa" }; };
};