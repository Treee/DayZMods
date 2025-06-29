class CfgPatches
{
    class IAT_Prop_Items_Characters_Headgear
    {
        requiredAddons[] = { "DZ_Data", "DZ_Characters", "DZ_Characters_Headgear" };
    };
};
class CfgVehicles
{
    class Clothing;
    class IAT_NailCrown_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Crown of Nails";
        descriptionShort = "A barbaric helmet for the use of torture.";
        model = "iat_prop_items\characters\headgear\iat_nailcrown_g.p3d";
        repairableWithKits[] = { 10 };
        repairCosts[] = { 25 };
        inventorySlot[] = { "Headgear" };
        simulation = "clothing";
        vehicleClass = "Clothing";
        itemInfo[] = { "Clothing", "Headgear" };
        visibilityModifier = 0.9;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_nailcrown_co.paa" };
        weight = 2000;
        itemSize[] = { 3, 3 };
        varWetMax = 0.249;
        heatIsolation = 0.3;
        headSelectionsToHide[] = { "Clipping_grathelm" };
        soundImpactType = "metal";
        class ClothingTypes
        {
            male = "iat_prop_items\characters\headgear\iat_nailcrown_m.p3d";
            female = "iat_prop_items\characters\headgear\iat_nailcrown_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 125;
                    healthLevels[] = {
                        {1, {"iat_prop_items\characters\headgear\data\iat_nailcrown.rvmat"}},
                        {0.7, {"iat_prop_items\characters\headgear\data\iat_nailcrown.rvmat"}},
                        {0.5, {"iat_prop_items\characters\headgear\data\iat_nailcrown_damage.rvmat"}},
                        {0.3, {"iat_prop_items\characters\headgear\data\iat_nailcrown_damage.rvmat"}},
                        {0, {"iat_prop_items\characters\headgear\data\iat_nailcrown_destruct.rvmat"}}
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
    class IAT_NailCrown_Basic : IAT_NailCrown_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_nailcrown_co.paa" };
    };
    class IAT_NailCrown_realsweetkid27 : IAT_NailCrown_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_nailcrown_co.paa" };
    };

    class IAT_ModernKnightHelm_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Modern Knight Helmet";
        descriptionShort = "A modern helmet fashioned out of wrought iron.";
        model = "iat_prop_items\characters\headgear\iat_modernknighthelm_g.p3d";
        repairableWithKits[] = { 10 };
        repairCosts[] = { 25 };
        inventorySlot[] = { "Headgear" };
        simulation = "clothing";
        vehicleClass = "Clothing";
        itemInfo[] = { "Clothing", "Headgear" };
        visibilityModifier = 0.9;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_modernknighthelm_co.paa" };
        weight = 2000;
        itemSize[] = { 3, 3 };
        varWetMax = 0.249;
        heatIsolation = 0.3;
        headSelectionsToHide[] = { "Clipping_grathelm" };
        soundImpactType = "metal";
        class ClothingTypes
        {
            male = "iat_prop_items\characters\headgear\iat_modernknighthelm_m.p3d";
            female = "iat_prop_items\characters\headgear\iat_modernknighthelm_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 125;
                    healthLevels[] = {
                        {1, {"iat_prop_items\characters\headgear\data\iat_modernknighthelm.rvmat"}},
                        {0.7, {"iat_prop_items\characters\headgear\data\iat_modernknighthelm.rvmat"}},
                        {0.5, {"iat_prop_items\characters\headgear\data\iat_modernknighthelm_damage.rvmat"}},
                        {0.3, {"iat_prop_items\characters\headgear\data\iat_modernknighthelm_damage.rvmat"}},
                        {0, {"iat_prop_items\characters\headgear\data\iat_modernknighthelm_destruct.rvmat"}}
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
    class IAT_ModernKnightHelm_Basic : IAT_ModernKnightHelm_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_modernknighthelm_co.paa" };
    };
    class IAT_ModernKnightHelm_GuyBiggsley : IAT_ModernKnightHelm_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_modernknighthelm_guybiggsley_co.paa" };
    };
};