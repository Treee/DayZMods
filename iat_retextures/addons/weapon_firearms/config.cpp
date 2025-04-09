class CfgPatches
{
    class IAT_Retextures_Weapon_Firearms
    {
        requiredAddons[] = { "DZ_Weapons_Firearms_M4" };
    };
};
class cfgWeapons
{
    class M4A1;

    //==================================================== VANILLA RETEXTURES
    class M4A1_Illusive : M4A1
    {
        scope = 2;
        // color = "Illusive";
        hiddenSelectionsTextures[] = { "iat_retextures\weapon_firearms\data\m4_body_illusive_co.paa" };
    };
};
