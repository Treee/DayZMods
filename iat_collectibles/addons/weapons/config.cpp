class CfgPatches
{
    class IAT_Collectibles_Weapons
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};

class CfgWeapons
{
    //=========================================== VANILLA OVERRIDE
    class RifleCore;
    class PistolCore;

    class Rifle_Base : RifleCore
    {
        inventorySlot[] += { "IAT_GunWall_Rifle1" };
    };
    class Pistol_Base : PistolCore
    {
        inventorySlot[] += { "IAT_GunWall_Pistol1", "IAT_GunWall_Pistol2", "IAT_GunWall_Pistol3" };
    };
};