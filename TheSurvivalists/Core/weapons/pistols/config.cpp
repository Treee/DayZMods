class CfgPatches
{
    class SRP_Core_Weapons_Pistols
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Pistols_Encore",
            "Dressupbox_Weapons"
        };
    };
};
class CfgWeapons
{
    class LongHorn_Base;
    class LongHorn : LongHorn_Base
    {
        inventorySlot[] +=
        {
            "SRP_GunDerringer",
                "SRP_Pistol1",
                "SRP_Pistol2",
                "SRP_Pistol3",
                "SRP_Pistol4",
                "pistol", "LeftHand1", "pistol2"
        };
    };
};