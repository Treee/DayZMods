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

    class IAT_FieldShovel_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "$STR_CfgVehicles_FieldShovel0";
        descriptionShort = "$STR_CfgVehicles_FieldShovel1";
        model = "iat_prop_items\tools\iat_shovel.p3d";
        debug_ItemCategory = 2;
        rotationFlags = 17;
        inventorySlot[] = { "Backpack_1" };
        suicideAnim = "woodaxe";
        weight = 1800;
        itemSize[] = { 2, 5 };
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
                ammo = "MeleeSharpLight_3";
                range = 1.4;
            };
            class Heavy
            {
                ammo = "MeleeSharpHeavy_3";
                range = 1.4;
            };
            class Sprint
            {
                ammo = "MeleeSharpHeavy_3";
                range = 3.3;
            };
        };
        class Horticulture
        {
            ToolAnim = "DIGGINGSHOVEL";
            DiggingTimeToComplete = 5;
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
    };

    class IAT_FieldShovel_Basic : IAT_FieldShovel_Colorbase
    {
        scope = 2;
    };
    class IAT_FieldShovel_snaliensarereal : IAT_FieldShovel_Colorbase
    {
        scope = 2;
        displayName = "PJ’s Shovel";
        descriptionShort = "Ain’t nothin’ ordinary about it. This here tool’s dug ditches, planted dreams, and cracked a few heads clean open.";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\tools\data\iat_shovel_co.paa" };
    };

    class IAT_IronHammer_Colorbase : Inventory_Base
    {
        scope = 0;
        debug_ItemCategory = 2;
        displayName = "Iron Hammer";
        descriptionShort = "A strong iron hammer that can be used in place of a sledgehammer.";
        model = "iat_prop_items\tools\iat_ironhammer.p3d";
        itemInfo[] = { "SledgeHammer" };
        rotationFlags = 12;
        weight = 5000;
        itemSize[] = { 2, 6 };
        itemBehaviour = 2;
        openItemSpillRange[] = { 30, 50 };
        inventorySlot[] = { "Shoulder", "Melee" };
        isMeleeWeapon = 1;
        build_action_type = 16;
        dismantle_action_type = 16;
        soundImpactType = "metal";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\tools\data\iat_thunderhammer_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 300;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\tools\data\iat_thunderhammer.rvmat"}},
                        {0.7, {"iat_prop_items\tools\data\iat_thunderhammer.rvmat"}},
                        {0.5, {"iat_prop_items\tools\data\iat_thunderhammer_damage.rvmat"}},
                        {0.3, {"iat_prop_items\tools\data\iat_thunderhammer_damage.rvmat"}},
                        {0, {"iat_prop_items\tools\data\iat_thunderhammer_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeBluntLight_5";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "MeleeBluntHeavy_5";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "MeleeBluntHeavy_5";
                range = 3.7;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class SledgeWoodHammer_loop
                {
                    soundSet = "SledgeWoodHammer_loop_SoundSet";
                    id = 1117;
                };
                class SledgeWoodHammer_end
                {
                    soundSet = "SledgeWoodHammer_end_SoundSet";
                    id = 1118;
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
        };
    };

    class IAT_IronHammer_Basic : IAT_IronHammer_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\tools\data\iat_thunderhammer_co.paa" };
    };
    class IAT_IronHammer_jaygarrick : IAT_IronHammer_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\tools\data\iat_thunderhammer_jaygarrick_co.paa" };
    };
};