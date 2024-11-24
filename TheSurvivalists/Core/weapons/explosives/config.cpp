class CfgPatches
{
    class SRP_Core_Weapons_Explosives
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
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