class CfgPatches
{
    class IAT_InfinityGauntlet_Gloves
    {
        requiredAddons[] = { "DZ_Characters_Gloves" };
    };
};
class CfgVehicles
{
    class Clothing;
    class IAT_InfinityGauntlet_ColorBase : Clothing
    {
        scope = 0;
        displayName = "Infinity Gauntlet";
        descriptionShort = "A gauntlet originally from Thanos' own armor modified to house the Infinity Gems.";
        model = "iat_infinity_gauntlet\gloves\iat_infinitygauntlet_g.p3d";
        inventorySlot[] = { "Gloves" };
        simulation = "clothing";
        itemInfo[] = { "Clothing", "Gloves" };
        repairableWithKits[] = { 5, 2 };
        repairCosts[] = { 30, 25 };
        visibilityModifier = 0.9;
        weight = 15000;
        itemSize[] = { 4, 4 };
        varWetMax = 0;
        varWetMin = 0;
        heatIsolation = 1;
        attachments[] =
        {
            "IAT_InfinityStone_Mind",
            "IAT_InfinityStone_Power",
            "IAT_InfinityStone_Reality",
            "IAT_InfinityStone_Soul",
            "IAT_InfinityStone_Space",
            "IAT_InfinityStone_Time"
        };
        hiddenSelections[] = { "camo", "personality" };
        hiddenSelectionsMaterials[] =
        {
            "iat_infinity_gauntlet\gloves\data\iat_infinitygauntlet_AJgold.rvmat"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 16500;
                    healthLevels[] = { {1, {""}}, {0.7, {""}}, {0.5, {""}}, {0.3, {""}}, {0, {""}} };
                };
            };
            class GlobalArmor
            {
                class Melee
                {
                    class Health
                    {
                        damage = 0.85;
                    };
                    class Blood
                    {
                        damage = 0.8;
                    };
                    class Shock
                    {
                        damage = 0.8;
                    };
                };
            };
        };
        class ClothingTypes
        {
            male = "iat_infinity_gauntlet\gloves\iat_infinitygauntlet_m.p3d";
            female = "iat_infinity_gauntlet\gloves\iat_infinitygauntlet_f.p3d";
        };
        soundImpactType = "metal";
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "WorkingGloves_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "WorkingGloves_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };

    class IAT_InfinityGauntlet : IAT_InfinityGauntlet_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.7;
        hiddenSelectionsTextures[] =
        {
            "iat_infinity_gauntlet\gloves\data\iat_infinitygauntlet_2_co.paa"
        };
    };
};