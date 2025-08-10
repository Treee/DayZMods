class CfgPatches
{
    class IAT_Prop_Items_Characters_Accessories
    {
        requiredAddons[] = { "DZ_Data", "DZ_Characters" };
    };
};
class CfgVehicles
{
    class Clothing;
    class IAT_IronPauldron_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Iron Pauldron";
        descriptionShort = "A pauldron that protects the shoulder.";
        model = "iat_prop_items\characters\accessories\iat_ironpauldron_g.p3d";
        repairableWithKits[] = { 10 };
        repairCosts[] = { 25 };
        inventorySlot[] = { "Scarf", "Beard" };
        simulation = "clothing";
        vehicleClass = "Clothing";
        itemInfo[] = { "Clothing", "Armband" };
        visibilityModifier = 0.9;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\accessories\data\iat_metalpauldron_co.paa" };
        weight = 2000;
        itemSize[] = { 2, 2 };
        varWetMax = 0.249;
        heatIsolation = 0.3;
        soundImpactType = "metal";
        class ClothingTypes
        {
            male = "iat_prop_items\characters\accessories\iat_ironpauldron_m.p3d";
            female = "iat_prop_items\characters\accessories\iat_ironpauldron_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 125;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\characters\accessories\data\iat_metalpauldron.rvmat"}},
                        {0.7, {"iat_prop_items\characters\accessories\data\iat_metalpauldron.rvmat"}},
                        {0.5, {"iat_prop_items\characters\accessories\data\iat_metalpauldron_damage.rvmat"}},
                        {0.3, {"iat_prop_items\characters\accessories\data\iat_metalpauldron_damage.rvmat"}},
                        {0, {"iat_prop_items\characters\accessories\data\iat_metalpauldron_destruct.rvmat"}}
                    };
                };
            };
            class GlobalArmor
            {
                class Projectile
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
                        damage = 1;
                    };
                };
                class Melee
                {
                    class Health
                    {
                        damage = 0.35;
                    };
                    class Blood
                    {
                        damage = 0;
                    };
                    class Shock
                    {
                        damage = 0.35;
                    };
                };
                class Infected
                {
                    class Health
                    {
                        damage = 0.35;
                    };
                    class Blood
                    {
                        damage = 0;
                    };
                    class Shock
                    {
                        damage = 0.35;
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
                        damage = 0.5;
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
                    soundSet = "pickUpPot_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "GreatHelm_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };

    class IAT_IronPauldron_Basic : IAT_IronPauldron_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\accessories\data\iat_metalpauldron_co.paa" };
    };
    class IAT_IronPauldron_autumn2187 : IAT_IronPauldron_Colorbase
    {
        scope = 2;
        TradeClassName = "MetalPlate";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\accessories\data\iat_metalpauldron_autumn2187_co.paa" };
    };
};