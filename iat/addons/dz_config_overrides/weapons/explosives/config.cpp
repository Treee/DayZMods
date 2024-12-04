class CfgPatches
{
    class IAT_DZ_ConfigOverrides_Weapons_Explosives
    {
        requiredAddons[] =
        {
            "DZ_Weapons_Explosives"
        };
    };
};
class CfgWeapons
{
    class Grenade_Base;
    class M18SmokeGrenade_ColorBase : Grenade_Base
    {
        weightPerQuantityUnit = 5.56;
    };
};