class CfgPatches
{
    class IAT_Prop_Items_Camping
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping", "DZ_Pistols_Flaregun" };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    //=================================== Flags (for the belt)
    class Flag_Base : Inventory_Base // slot overrides
    {
        inventorySlot[] += { "IAT_VanillaFlag", "IAT_BeltFlag" };
    };
    class IAT_BeltFlag_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Belt Flag";
        descriptionShort = "This small flag attaches to the leather flag belt.";
        model = "iat_prop_items\camping\iat_beltflag.p3d";
        itemSize[] = { 2,2 };
        absorbency = 0.89999998;
        ragQuantity = 6;
        rotationFlags = 16;
        inventorySlot[] = { "IAT_VanillaFlag", "IAT_BeltFlag" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_beltflag_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1,{""}},
                        {0.69999999,{""}},
                        {0.5,{""}},
                        {0.30000001,{""}},
                        {0,{""}}
                    };
                };
                class GlobalArmor
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage = 0;
                        };
                        class Blood
                        {
                            damage = 0;
                        };
                        class Shock
                        {
                            damage = 0;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage = 0;
                        };
                        class Blood
                        {
                            damage = 0;
                        };
                        class Shock
                        {
                            damage = 0;
                        };
                    };
                };
            };
        };
    };
    class IAT_BeltFlag_Basic : IAT_BeltFlag_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_beltflag_co.paa" };
    };

    //=================================== STEPLADDER
    class IAT_Ladder_Closed_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Closed Ladder";
        descriptionShort = "A ladder that can be used to vault over tall walls or reach high places.";
        model = "iat_prop_items\camping\iat_ladder_closed.p3d";
        itemBehaviour = 1;
        rotationFlags = 16;
        weight = 27000;
        slopeTolerance = 0.4;
        yawPitchRollLimit[] = { 45, 45, 45 };
        itemSize[] = { 12, 12 };
        carveNavmesh = 1;
        soundImpactType = "wood";
        projectionTypename = "IAT_Ladder_Opened_Basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1.0, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.69999999, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.5, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.30000001, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.0, { "iat_prop_items\camping\data\iat_ladder_destruct.rvmat"}}
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class movement
                {
                    soundSet = "seachest_movement_SoundSet";
                    id = 1;
                };
                class pickUpItem_Light
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "seachest_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };

    class IAT_Ladder_Closed_Basic : IAT_Ladder_Closed_ColorBase
    {
        scope = 2;
        color = "basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
    };

    class IAT_Ladder_Opened_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "deployed Ladder";
        descriptionShort = "A ladder that can be used to vault over tall walls or reach high places.";
        model = "iat_prop_items\camping\iat_ladder_opened.p3d";
        itemBehaviour = 2;
        rotationFlags = 64;
        weight = 17000;
        carveNavmesh = 1;
        itemSize[] = { 12, 12 };
        soundImpactType = "wood";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1.0, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.69999999, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.5, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.30000001, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.0, { "iat_prop_items\camping\data\iat_ladder_destruct.rvmat"}}
                    };
                };
            };
        };
    };
    class IAT_Ladder_Opened_Basic : IAT_Ladder_Opened_ColorBase
    {
        scope = 2;
        color = "basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
    };

};
class CfgWeapons
{
    class Flaregun_Base;
    class IAT_Flaregun_Staff : Flaregun_Base
    {
        scope = 2;
        displayName = "Sun Staff";
        descriptionShort = "A metal staff that praises the sun.";
        model = "iat_prop_items\camping\iat_flaregunstaff.p3d";
        attachments[] = {};
        inventorySlot[] = { "Shoulder", "Melee" };
        itemSize[] = { 1, 7 };
        repairableWithKits[] = { 5,8 };
        repairCosts[] = { 100,100 };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_flaregunstaff_co.paa" };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0, 0, 0 };//FB,UD,LR
                orientation[] = { 90, 90, 0 };//x,y,z
            };
            class Melee
            {
                position[] = { 0, 0, 0 };//FB,UD,LR
                orientation[] = { 90, 90, 0 };//x,y,z
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 150;
                    healthLevels[] = { {1, {"iat_prop_items\camping\data\iat_flaregunstaff.rvmat"}}, {0.7, {"iat_prop_items\camping\data\iat_flaregunstaff.rvmat"}}, {0.5, {"iat_prop_items\camping\data\iat_flaregunstaff_damage.rvmat"}}, {0.3, {"iat_prop_items\camping\data\iat_flaregunstaff_damage.rvmat"}}, {0, {"iat_prop_items\camping\data\iat_flaregunstaff_destruct.rvmat"}} };
                };
            };
        };
        class Particles
        {
            class OnFire
            {
                class SmokeCloud
                {
                    overrideParticle = "weapon_shot_winded_smoke";
                };
                class MuzzleFlash
                {
                    overrideParticle = "weapon_shot_fnx_01";
                    ignoreIfSuppressed = 1;
                    illuminateWorld = 1;
                    positionOffset[] = { 0, 0, 0 };
                };
            };
            class OnOverheating
            {
                maxOverheatingValue = 8;
                shotsToStartOverheating = 8;
                overheatingDecayInterval = 1;
                class SmokingBarrel1
                {
                    overrideParticle = "smoking_barrel_small";
                    onlyWithinOverheatLimits[] = { 0, 1 };
                    positionOffset[] = { 0, 0, 0 };
                    onlyWithinRainLimits[] = { 0, 1 };
                };
                class OpenChamberSmoke
                {
                    onlyIfBoltIsOpen = 1;
                    overrideParticle = "smoking_barrel_small";
                    overridePoint = "Nabojnicestart";
                };
            };
            class OnBulletCasingEject
            {
                class ChamberSmokeRaise
                {
                    overrideParticle = "weapon_shot_chamber_smoke";
                    overridePoint = "Nabojnicestart";
                };
            };
        };
    };
};


class CfgSlots
{
    class Slot_IAT_VanillaFlag
    {
        name = "IAT_VanillaFlag";
        displayName = "Flag";
        ghostIcon = "set:dayz_inventory image:tf_flag";
    };
    class Slot_IAT_BeltFlag
    {
        name = "IAT_BeltFlag";
        displayName = "Belt Flag";
        ghostIcon = "set:dayz_inventory image:tf_flag";
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyiat_vanillaflag_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_VanillaFlag" };
        model = "iat_prop_items\camping\proxy\iat_vanillaflag_proxy.p3d";
    };
    class Proxyiat_beltflag_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_BeltFlag" };
        model = "iat_prop_items\camping\proxy\iat_beltflag_proxy.p3d";
    };
};