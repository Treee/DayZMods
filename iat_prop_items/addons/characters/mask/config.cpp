class CfgPatches
{
    class IAT_Prop_Items_Characters_Masks
    {
        requiredAddons[] = { "DZ_Data", "DZ_Characters", "DZ_Characters_Masks" };
    };
};
class CfgVehicles
{
    class Clothing;
    class IAT_PredatorSkullMask_Colorbase : Clothing
    {
        scope = 0;
        displayName = "Predator Skull Mask";
        descriptionShort = "A skull mask with electrical dreads.";
        model = "iat_prop_items\characters\mask\iat_skullpredatormask_g.p3d";
        inventorySlot[] = { "Mask" };
        itemInfo[] = { "Clothing", "Mask" };
        weight = 700;
        itemSize[] = { 2, 2 };
        varWetMax = 0.2;
        heatIsolation = 0.1;
        repairableWithKits[] = { 5, 2 };
        repairCosts[] = { 30, 25 };
        headSelectionsToHide[] = { "Clipping_Balaclava_3holes" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\mask\data\iat_skullpredatormask_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\characters\mask\data\iat_skullpredatormask.rvmat"}},
                        {0.7, {"iat_prop_items\characters\mask\data\iat_skullpredatormask.rvmat"}},
                        {0.5, {"iat_prop_items\characters\mask\data\iat_skullpredatormask_damage.rvmat"}},
                        {0.3, {"iat_prop_items\characters\mask\data\iat_skullpredatormask_damage.rvmat"}},
                        {0, {"iat_prop_items\characters\mask\data\iat_skullpredatormask_destruct.rvmat"}}
                    };
                };
            };
        };
        class ClothingTypes
        {
            male = "iat_prop_items\characters\mask\iat_skullpredatormask_m.p3d";
            female = "iat_prop_items\characters\mask\iat_skullpredatormask_f.p3d";
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "Shirt_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "Shirt_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class IAT_PredatorSkullMask_Basic : IAT_PredatorSkullMask_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\mask\data\iat_skullpredatormask_co.paa" };
    };
    class IAT_PredatorSkullMask_rogueknight1995 : IAT_PredatorSkullMask_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\characters\mask\data\iat_skullpredatormask_rogueknight1995_co.paa" };
    };
};