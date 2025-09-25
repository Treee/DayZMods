class CfgPatches
{
    class IAT_Prop_Items_Explosives
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Weapons_Explosives" };
    };
};
class CfgVehicles
{
    class Grenade_Base;

    class IAT_SmokeBomb_ColorBase : Grenade_Base
    {
        scope = 0;
        displayName = "Smoke Grenade";
        descriptionShort = "A small handful of pocket sand!";
        model = "\dz\weapons\explosives\Grenade_ChemGas.p3d";
        weight = 500;
        itemSize[] = { 1, 1 };
        inventorySlot[] = { "VestGrenadeA", "VestGrenadeB", "VestGrenadeC", "VestGrenadeD", "IEDExplosiveA", "IEDExplosiveB" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_red_co.paa" };
        hiddenSelectionsMaterials[] = {};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5;
                    healthLevels[] = { {1, {"iat_prop_items\explosives\data\grenade_smoke.rvmat"}}, {0.7, {"iat_prop_items\explosives\data\grenade_smoke.rvmat"}}, {0.5, {"iat_prop_items\explosives\data\grenade_smoke_damage.rvmat"}}, {0.3, {"iat_prop_items\explosives\data\grenade_smoke_damage.rvmat"}}, {0, {"iat_prop_items\explosives\data\grenade_smoke_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_SmokeBomb_Red : IAT_SmokeBomb_ColorBase
    {
        scope = 2;
        displayName = "Smoke Grenade - Red";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_red_co.paa" };
    };
    class IAT_SmokeBomb_Green : IAT_SmokeBomb_ColorBase
    {
        scope = 2;
        displayName = "Smoke Grenade - Green";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_green_co.paa" };
    };
    class IAT_SmokeBomb_Yellow : IAT_SmokeBomb_ColorBase
    {
        scope = 2;
        displayName = "Smoke Grenade - Yellow";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_yellow_co.paa" };
    };
    class IAT_SmokeBomb_Purple : IAT_SmokeBomb_ColorBase
    {
        scope = 2;
        displayName = "Smoke Grenade - Purple";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_purple_co.paa" };
    };
    class IAT_SmokeBomb_White : IAT_SmokeBomb_ColorBase
    {
        scope = 2;
        displayName = "Smoke Grenade - White";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_white_co.paa" };
    };
    class IAT_SmokeBomb_Black : IAT_SmokeBomb_ColorBase
    {
        scope = 2;
        displayName = "Smoke Grenade - Black";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\explosives\data\grenade_smoke_black_co.paa" };
    };
};