class CfgPatches
{
    class IAT_Prop_Items_Characters_Scarfs
    {
        requiredAddons[] = { "DZ_Data", "DZ_Characters" };
    };
};
class CfgVehicles
{
    class Clothing;
    class IAT_LeatherNecklace_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Leather Necklace";
        descriptionShort = "A necklace made from a belt";
        model = "iat_prop_items\characters\scarfs\iat_leatherneck_g.p3d";
        inventorySlot[] = { "scarf" };
        itemInfo[] =
        {
            "Clothing",
            "Vest"
        };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\scarfs\data\iat_leatherneck_co.paa" };
        weight = 25;
        itemSize[] = { 2,1 };
        varWetMax = 0.29000001;
        heatIsolation = 0.40000001;
        repairableWithKits[] = { 5,2 };
        repairCosts[] = { 75,50 };
        class ClothingTypes
        {
            male = "iat_prop_items\characters\scarfs\iat_leatherneck_m.p3d";
            female = "iat_prop_items\characters\scarfs\iat_leatherneck_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 125;
                    healthLevels[] = {
                        {1, {"iat_prop_items\characters\scarfs\data\iat_leatherneckleather.rvmat"}},
                        {0.7, {"iat_prop_items\characters\scarfs\data\iat_leatherneckleather.rvmat"}},
                        {0.5, {"iat_prop_items\characters\scarfs\data\iat_leatherneckleather_damage.rvmat"}},
                        {0.3, {"iat_prop_items\characters\scarfs\data\iat_leatherneckleather_damage.rvmat"}},
                        {0, {"iat_prop_items\characters\scarfs\data\iat_leatherneckleather_destruct.rvmat"}}
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

    class IAT_LeatherNecklace_Basic : IAT_LeatherNecklace_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\scarfs\data\iat_leatherneck_co.paa" };
    };

    class IAT_LeatherNecklace_reggetti : IAT_LeatherNecklace_Colorbase
    {
        scope = 2;
        TradeClassName = "TannedLeather";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\scarfs\data\iat_leatherneck_reggetti_co.paa" };
    };
};