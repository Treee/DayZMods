class CfgPatches
{
    class IAT_Prop_Items_Camping
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    class IAT_Bear_ColorBase : Inventory_Base
    {
        displayName = "$STR_CfgVehicles_Bear_ColorBase0";
        descriptionShort = "$STR_CfgVehicles_Bear_ColorBase1";
        model = "\dz\gear\containers\teddybear.p3d";
        weight = 130;
        itemSize[] = { 2, 3 };
        itemsCargoSize[] = { 0, 0 };
        canBeDigged = 1;
        allowOwnedCargoManipulation = 1;
        repairableWithKits[] = { 2 };
        repairCosts[] = { 25 };
        hiddenSelections[] = { "camoGround" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 30;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\teddybear.rvmat"}}, {0.7, {"DZ\gear\containers\data\teddybear.rvmat"}}, {0.5, {"DZ\gear\containers\data\teddybear_damage.rvmat"}}, {0.3, {"DZ\gear\containers\data\teddybear_damage.rvmat"}}, {0, {"DZ\gear\containers\data\teddybear_destruct.rvmat"}} };
                };
            };
        };
        soundImpactType = "textile";
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem_Light
                {
                    soundSet = "pickUpCourierBag_Light_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpCourierBag_SoundSet";
                    id = 797;
                };
            };
        };
    };

    class IAT_Bear_Beige : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_brown_co.paa" };
    };
    class IAT_Bear_Dark : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_dark_co.paa" };
    };
    class IAT_Bear_Pink : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_pink_co.paa" };
    };
    class IAT_Bear_White : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_white_co.paa" };
    };

    class IAT_Bear_BuzzingGhosts : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_buzzingghosts_co.paa" };
    };

};