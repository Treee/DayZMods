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
    class Inventory_Base;

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

    class IAT_AltynHelmet_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Altyn Helmet";
        descriptionShort = "A sturdy helmet with a visor that can be raised and lowered.";
        model = "iat_prop_items\characters\headgear\iat_altyn_g.p3d";
        repairableWithKits[] = { 8 };
        repairCosts[] = { 25 };
        inventorySlot[] = { "Headgear" };
        simulation = "clothing";
        vehicleClass = "Clothing";
        itemInfo[] = { "Clothing", "Headgear" };
        visibilityModifier = 0.9;
        attachments[] = { "IAT_Altyn_Raised", "IAT_Altyn_Lowered" };
        weight = 1100;
        itemSize[] = { 4, 4 };
        color = "";
        varWetMax = 0.49;
        heatIsolation = 0.8;
        lootCategory = "Crafted";
        headSelectionsToHide[] = { "Clipping_Maska" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_co.paa" };
        class ClothingTypes
        {
            male = "iat_prop_items\characters\headgear\iat_altyn_m.p3d";
            female = "iat_prop_items\characters\headgear\iat_altyn_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    transferToAttachmentsCoef = 3;
                    healthLevels[] = { {1, {"iat_prop_items\characters\headgear\data\iat_altyn.rvmat"}}, {0.7, {"iat_prop_items\characters\headgear\data\iat_altyn.rvmat"}}, {0.5, {"iat_prop_items\characters\headgear\data\iat_altyn_damage.rvmat"}}, {0.3, {"iat_prop_items\characters\headgear\data\iat_altyn_damage.rvmat"}}, {0, {"iat_prop_items\characters\headgear\data\iat_altyn_destruct.rvmat"}} };
                };
            };
            class GlobalArmor
            {
                class Projectile
                {
                    class Health
                    {
                        damage = 0.25;
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
                        damage = 0.26;
                    };
                };
            };
        };
        soundImpactType = "metal";
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "DarkMotoHelmet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "DarkMotoHelmet_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class IAT_AltynHelmet_Basic : IAT_AltynHelmet_Colorbase
    {
        scope = 2;
        color = "Basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_co.paa" };
    };
    class IAT_AltynHelmet_Black : IAT_AltynHelmet_Colorbase
    {
        scope = 2;
        color = "Black";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_black_co.paa" };
    };
    class IAT_AltynHelmet_moon_x : IAT_AltynHelmet_Colorbase
    {
        scope = 2;
        TradeClassName = "IAT_AltynHelmet_Colorbase";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_moon_x_co.paa" };
    };

    class IAT_AltynHelmetVisor_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Altyn Helmet Visor";
        descriptionShort = "A sturdy visor that can be attached to an Altyn helmet.";
        model = "iat_prop_items\characters\headgear\iat_altynvisor.p3d";
        hiddenSelections[] = { "zbytek", "glass" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_co.paa", "iat_prop_items\characters\headgear\data\iat_glass_ca.paa" };
        hiddenSelectionsMaterials[] = { "iat_prop_items\characters\headgear\data\iat_altyn.rvmat", "iat_prop_items\characters\headgear\data\iat_glass.rvmat" };
        rotationFlags = 16;
        weight = 350;
        itemSize[] = { 3, 2 };
        inventorySlot[] = { "IAT_Altyn_Raised", "IAT_Altyn_Lowered" };
        soundImpactType = "glass";
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] = { {1, {"iat_prop_items\characters\headgear\data\iat_altyn.rvmat"}}, {0.7, {"iat_prop_items\characters\headgear\data\iat_altyn.rvmat"}}, {0.5, {"iat_prop_items\characters\headgear\data\iat_altyn_damage.rvmat"}}, {0.3, {"iat_prop_items\characters\headgear\data\iat_altyn_damage.rvmat"}}, {0, {"iat_prop_items\characters\headgear\data\iat_altyn_destruct.rvmat"}} };
                };
            };
        };
    };

    class IAT_AltynHelmetVisor_Basic : IAT_AltynHelmetVisor_Colorbase
    {
        scope = 2;
        color = "Basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_co.paa" };
    };
    class IAT_AltynHelmetVisor_Black : IAT_AltynHelmetVisor_Colorbase
    {
        scope = 2;
        color = "Black";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_black_co.paa" };
    };
    class IAT_AltynHelmetVisor_moon_x : IAT_AltynHelmetVisor_Colorbase
    {
        scope = 2;
        TradeClassName = "IAT_AltynHelmetVisor_Colorbase";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\headgear\data\iat_altyn_moon_x_co.paa" };
    };
};

class CfgSlots
{
    class Slot_IAT_Altyn_Raised
    {
        name = "IAT_Altyn_Raised";
        displayName = "Alytn Raised Position";
        ghostIcon = "set:dayz_inventory image:headgear";
    };
    class Slot_IAT_Altyn_Lowered
    {
        name = "IAT_Altyn_Lowered";
        displayName = "Alytn Lowered Position";
        ghostIcon = "set:dayz_inventory image:headgear";
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyiat_alytn_raised : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_Altyn_Raised" };
        model = "iat_prop_items\characters\headgear\proxy\iat_alytn_raised.p3d";
    };
    class Proxyiat_alytn_lowered : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_Altyn_Lowered" };
        model = "iat_prop_items\characters\headgear\proxy\iat_alytn_lowered.p3d";
    };

};