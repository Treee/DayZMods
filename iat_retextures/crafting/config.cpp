class CfgPatches
{
    class IAT_Retextures_Crafting
    {
        requiredAddons[] = { "DZ_Data" };
    };
};
class CfgVehicles
{
    class BurlapSack;

    //==================================================== VANILLA OVERRIDE
    class BurlapSack_Black : BurlapSack
    {
        scope = 2;
        color = "black";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\crafting\data\head_sack_black_co.paa" };
    };
    class BurlapSack_Skull : BurlapSack
    {
        scope = 2;
        color = "skull";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\crafting\data\head_sack_black_skull_co.paa" };
    };
    class BurlapSack_White : BurlapSack
    {
        scope = 2;
        color = "white";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\crafting\data\head_sack_white_co.paa" };
    };
};