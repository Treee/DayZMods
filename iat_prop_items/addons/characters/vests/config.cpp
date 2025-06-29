class CfgPatches
{
    class IAT_Prop_Items_Characters_Vests
    {
        requiredAddons[] = { "DZ_Data", "DZ_Characters", "DZ_Characters_Vests" };
    };
};
class CfgVehicles
{
    class Clothing_Base;
    // reset clothing since this has custom stufff
    class Clothing : Clothing_Base
    {
    };

    class IAT_ImprovisedArmor_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Improvised Armor";
        descriptionShort = "Self made armor that protects just as good as a plate carrier.";
        model = "iat_prop_items\characters\vests\iat_improvisedarmor_g.p3d";
        inventorySlot[] = { "Vest" };
        itemInfo[] = { "Clothing", "Vest" };
        weight = 12000;
        itemSize[] = { 5, 5 };
        quickBarBonus = 1;
        varWetMax = 0.1;
        heatIsolation = 0.3;
        repairableWithKits[] = { 3, 8 };
        repairCosts[] = { 75, 50 };
        visibilityModifier = 0.95;
        hiddenSelections[] = { "zbytek", "leather" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\vests\data\iat_improvisedarmor_co.paa", "iat_prop_items\characters\vests\data\iat_improvisedarmor_co.paa" };
        class ClothingTypes
        {
            male = "iat_prop_items\characters\vests\iat_improvisedarmor_m.p3d";
            female = "iat_prop_items\characters\vests\iat_improvisedarmor_f.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 225;
                    transferToAttachmentsCoef = 0.5;
                    healthLevels[] = { {1, {"DZ\characters\vests\Data\BallisticVest.rvmat"}}, {0.7, {"DZ\characters\vests\Data\BallisticVest.rvmat"}}, {0.5, {"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}}, {0.3, {"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}}, {0, {"DZ\characters\vests\Data\BallisticVest_destruct.rvmat"}} };
                };
            };
            class GlobalArmor
            {
                class Projectile
                {
                    class Health
                    {
                        damage = 0.3;
                    };
                    class Blood
                    {
                        damage = 0;
                    };
                    class Shock
                    {
                        damage = 0.6;
                    };
                };
                class Melee
                {
                    class Health
                    {
                        damage = 0.3;
                    };
                    class Blood
                    {
                        damage = 0;
                    };
                    class Shock
                    {
                        damage = 0.25;
                    };
                };
                class Infected
                {
                    class Health
                    {
                        damage = 0.3;
                    };
                    class Blood
                    {
                        damage = 0;
                    };
                    class Shock
                    {
                        damage = 0.25;
                    };
                };
                class FragGrenade
                {
                    class Health
                    {
                        damage = 0.5;
                    };
                    class Blood
                    {
                        damage = 0;
                    };
                    class Shock
                    {
                        damage = 0.26;
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "SmershVest_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "SmershVest_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };

    class IAT_ImprovisedArmor_Basic : IAT_ImprovisedArmor_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\vests\data\iat_improvisedarmor_co.paa" };
    };
    class IAT_ImprovisedArmor_GuyBiggsly : IAT_ImprovisedArmor_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek", "leather" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\vests\data\iat_improvisedarmor_guybiggsley_co.paa", "iat_prop_items\characters\vests\data\iat_improvisedarmor_guybiggsley_co.paa" };
    };
};