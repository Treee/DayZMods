class CfgPatches
{
    class IAT_Prop_Items_Characters_Scarfs
    {
        requiredAddons[] = { "DZ_Data", "DZ_Characters", "DZ_Characters_Belts" };
    };
};
class CfgVehicles
{
    class Clothing;
    class IAT_GunslingerBelt_ColorBase : Clothing
    {
        scope = 0;
        displayName = "Gunslinger Belt";
        descriptionShort = "A loose fitting belt with a slot for long a barreled pistol.";
        model = "iat_prop_items\characters\belts\iat_gunslingerbelt_g.p3d";
        attachments[] = { "Pistol" };
        inventorySlot[] = { "Hips" };
        itemInfo[] = { "Clothing", "Hips" };
        weight = 1000;
        itemSize[] = { 3, 2 };
        quickBarBonus = 1;
        varWetMax = 0.249;
        heatIsolation = 0;
        repairableWithKits[] = { 3 };
        repairCosts[] = { 25 };
        visibilityModifier = 0.95;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\belts\data\iat_gunslingerbelt_co.paa" };
        class ClothingTypes
        {
            male = "iat_prop_items\characters\belts\iat_gunslingerbelt_m.p3d";
            female = "iat_prop_items\characters\belts\iat_gunslingerbelt_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    transferToAttachmentsCoef = 0.5;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\characters\belts\data\iat_gunslingerbelt.rvmat"}},
                        {0.7, {"iat_prop_items\characters\belts\data\iat_gunslingerbelt.rvmat"}},
                        {0.5, {"iat_prop_items\characters\belts\data\iat_gunslingerbelt_damage.rvmat"}},
                        {0.3, {"iat_prop_items\characters\belts\data\iat_gunslingerbelt_damage.rvmat"}},
                        {0, {"iat_prop_items\characters\belts\data\iat_gunslingerbelt_destruct.rvmat"}}
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

    class IAT_GunslingerBelt_Basic : IAT_GunslingerBelt_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\belts\data\iat_gunslingerbelt_co.paa" };
    };
    class IAT_GunslingerBelt_weebyboi : IAT_GunslingerBelt_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\belts\data\iat_gunslingerbelt_weebyboi_co.paa" };
    };

    class IAT_FlagBelt_ColorBase : Clothing
    {
        scope = 0;
        displayName = "Battle Standard Belt";
        descriptionShort = "A leather belt with an attachment for a flag.";
        model = "iat_prop_items\characters\belts\iat_flagbelt_g.p3d";
        attachments[] = { "IAT_VanillaFlag", "IAT_BeltFlag" };
        inventorySlot[] = { "Hips" };
        itemInfo[] =
        {
            "Clothing",
            "Hips"
        };
        weight = 4000;
        itemSize[] = { 2,4 };
        itemsCargoSize[] = { 1,2 };
        absorbency = 0;
        heatIsolation = 0.40;
        repairableWithKits[] = { 3 };
        repairCosts[] = { 25 };
        simulation = "clothing";
        vehicleClass = "Clothing";
        hiddenSelections[] = { "zbytek", "personality" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\belts\data\iat_flagbelt_co.paa" };
        class ClothingTypes
        {
            male = "iat_prop_items\characters\belts\iat_flagbelt_m.p3d";
            female = "iat_prop_items\characters\belts\iat_flagbelt_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1.0, { "iat_prop_items\characters\belts\data\iat_flagbelt.rvmat"}},
                        {0.7, { "iat_prop_items\characters\belts\data\iat_flagbelt.rvmat"}},
                        {0.5, { "iat_prop_items\characters\belts\data\iat_flagbelt_damage.rvmat"}},
                        {0.3, { "iat_prop_items\characters\belts\data\iat_flagbelt_damage.rvmat"}},
                        {0.0, { "iat_prop_items\characters\belts\data\iat_flagbelt_destruct.rvmat"}}
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
    class IAT_FlagBelt_Basic : IAT_FlagBelt_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\belts\data\iat_flagbelt_co.paa" };
    };
};