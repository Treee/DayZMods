class CfgPatches
{
    class IAT_Prop_Items_Tools
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Tools" };
    };
};
class CfgVehicles
{
    class Inventory_Base;


    class IAT_Shovel_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "$STR_CfgVehicles_Shovel0";
        descriptionShort = "$STR_CfgVehicles_Shovel1";
        model = "iat_prop_items\tools\iat_shovel.p3d";
        debug_ItemCategory = 2;
        rotationFlags = 17;
        weight = 3000;
        itemSize[] = { 2, 5 };
        fragility = 0.008;
        itemBehaviour = 2;
        inventorySlot[] = { "Shoulder", "Melee" };
        suicideAnim = "pitchfork";
        build_action_type = 4;
        dismantle_action_type = 4;
        openItemSpillRange[] = { 30, 60 };
        soundImpactType = "metal";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\tools\data\iat_shovel_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_prop_items\tools\data\iat_shovel_wood.rvmat" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 200;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\tools\data\iat_shovel_wood.rvmat"}},
                        {0.7, {"iat_prop_items\tools\data\iat_shovel_wood.rvmat"}},
                        {0.5, {"iat_prop_items\tools\data\iat_shovel_wood_damage.rvmat"}},
                        {0.3, {"iat_prop_items\tools\data\iat_shovel_wood_damage.rvmat"}},
                        {0, {"iat_prop_items\tools\data\iat_shovel_wood_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeBluntLight_3";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "MeleeBluntHeavy_3";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "MeleeBluntHeavy_3";
                range = 3.7;
            };
        };
        class Horticulture
        {
            ToolAnim = "DIGGINGSHOVEL";
            DiggingTimeToComplete = 4.5;
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpShovel_Light
                {
                    soundSet = "pickUpShovelLight_SoundSet";
                    id = 796;
                };
                class pickUpShovel
                {
                    soundSet = "pickUpShovel_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "shovel_drop_SoundSet";
                    id = 898;
                };
                class ShoulderR_Hide
                {
                    soundset = "ShoulderR_Hide_SoundSet";
                    id = 1210;
                };
                class ShoulderR_Show
                {
                    soundset = "ShoulderR_Show_SoundSet";
                    id = 1211;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 887;
                        sakhal_snow = 900;
                        sakhal_snow_forest = 900;
                        sakhal_grass_brown = 900;
                        sakhal_ice_sea = 905;
                        sakhal_ice_lake = 905;
                    };
                    class DigSecondary
                    {
                        default = 888;
                        sakhal_snow = 901;
                        sakhal_snow_forest = 901;
                        sakhal_grass_brown = 901;
                        sakhal_ice_sea = 904;
                        sakhal_ice_lake = 904;
                    };
                };
            };
        };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0, -0.03, 0.04 };
                orientation[] = { 55, 0, 0 };
            };
            class Melee
            {
                position[] = { 0, -0.05, 0 };
                orientation[] = { 110, 0, 0 };
            };
        };
    };

    class IAT_Shovel_Basic : IAT_Shovel_Colorbase
    {
        scope = 2;
    };
    class IAT_Shovel_snaliensarereal : IAT_Shovel_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\tools\data\iat_shovel_co.paa" };
    };
};