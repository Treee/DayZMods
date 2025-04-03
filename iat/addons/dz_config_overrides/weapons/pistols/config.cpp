class CfgPatches
{
    class IAT_DZ_ConfigOverrides_Weapons_Pistols
    {
        requiredAddons[] = { "DZ_Pistols","DZ_Pistols_Encore", "DZ_Pistols_Derringer", "DZ_Pistols_Magnum" };
    };
};
class CfgWeapons
{
    class Pistol_Base;
    class Magnum_Base;
    class Derringer_Base : Pistol_Base
    {
        inventorySlot[] += { "IAT_Weapon_Derringer" };
    };

    class SawedoffMagnum : Magnum_Base
    {
        inventorySlot[] += { "IAT_Weapon_Derringer" };
    };
};