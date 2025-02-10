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
        attachments[] = {
            "IAT_InfinityStone_Mind",
            "IAT_InfinityStone_Power",
            "IAT_InfinityStone_Reality",
            "IAT_InfinityStone_Soul",
            "IAT_InfinityStone_Space",
            "IAT_InfinityStone_Time"
        };
        hiddenSelections[] = { "camoGround", "camoMale", "camoFemale", "personality" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 165;
                    healthLevels[] = { {1, {"DZ\Characters\gloves\data\TacticalGloves.rvmat"}}, {0.7, {"DZ\Characters\gloves\data\TacticalGloves.rvmat"}}, {0.5, {"DZ\Characters\gloves\data\TacticalGloves_damage.rvmat"}}, {0.3, {"DZ\Characters\gloves\data\TacticalGloves_damage.rvmat"}}, {0, {"DZ\Characters\gloves\data\TacticalGloves_destruct.rvmat"}} };
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
            female = "iat_infinity_gauntlet\gloves\iat_infinitygauntlet_m.p3d";
        };
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

    class IAT_InfinityGauntlet_Default : IAT_InfinityGauntlet_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.7;
        hiddenSelectionsTextures[] = { "DZ\characters\gloves\data\TacticalGloves_beige_co.paa", "DZ\characters\gloves\data\TacticalGloves_beige_co.paa", "DZ\characters\gloves\data\TacticalGloves_beige_co.paa" };
    };
};