class CfgPatches
{
    class IAT_Retextures_Camping
    {
        requiredAddons[] = { "DZ_Gear_Camping" };
    };
};
class CfgVehicles
{
    class LargeTent;
    class Flag_Base;

    //==================================================== VANILLA OVERRIDE
    class LargeTent_Stag : LargeTent
    {
        scope = 2;
        color = "LargeTent";
        hiddenSelections[] = { "camo" };
        hiddenSelectionsTextures[] = { "iat_retextures\camping\data\large_tent_STAG_co.paa" };
    };
};