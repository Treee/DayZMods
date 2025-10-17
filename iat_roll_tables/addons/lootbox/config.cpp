class CfgPatches
{
    class IAT_Roll_Tables_LootBox
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    //==================================================== VANILLA RETEXTURES
    // the "based" class nothin lower than this
    class IAT_LootBox_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Box of Chance";
        descriptionShort = "A box with many thing(s) inside.";
        model = "\DZ\gear\containers\ChristmasBox1.p3d";
        weight = 100;
        itemSize[] = { 2, 2 };
        itemsCargoSize[] = { 0, 0 };
        absorbency = 0;
        reversed = 1;
        IAT_NumberOfResults = 0;
        IAT_LootTable = "";
        hiddenSelections[] = { "ChristmasBox1", "ChristmasBox1_ribbon" };
        hiddenSelectionsTextures[] = { "\dz\gear\containers\data\christmas_paper1_CO.paa", "\dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 40;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}}, {0.3, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}} };
                };
            };
        };
    };
    // base class for 1 item yield (Default)
    class IAT_LootBox_Small_ColorBase : IAT_LootBox_ColorBase
    {
        IAT_NumberOfResults = 1;
        displayName = "Box of Chance - Small";
    };

    // base class for 3 item yield (Default)
    class IAT_LootBox_Medium_ColorBase : IAT_LootBox_ColorBase
    {
        IAT_NumberOfResults = 3;
        displayName = "Box of Chance - Medium";
        model = "\DZ\gear\containers\ChristmasBox2.p3d";
        weight = 300;
        itemSize[] = { 4, 4 };
        hiddenSelections[] = { "ChristmasBox2", "ChristmasBox2_ribbon" };
    };

    // base class for 5 item yield (Default)
    class IAT_LootBox_Large_ColorBase : IAT_LootBox_ColorBase
    {
        IAT_NumberOfResults = 5;
        displayName = "Box of Chance - Large";
        model = "\DZ\gear\containers\ChristmasBox3.p3d";
        weight = 500;
        itemSize[] = { 5, 5 };
        hiddenSelections[] = { "ChristmasBox3", "ChristmasBox3_ribbon" };
    };

    // ============================== SMALLS
    class IAT_LootBox_Small_1 : IAT_LootBox_Small_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Small1";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper1_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 30;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Small_2 : IAT_LootBox_Small_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Small2";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper2_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 30;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Small_3 : IAT_LootBox_Small_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Small3";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper3_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 30;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Small_4 : IAT_LootBox_Small_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Small4";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper4_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 30;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER_destruct.rvmat"}} };
                };
            };
        };
    };

    // ============================== MEDIUMS
    class IAT_LootBox_Medium_1 : IAT_LootBox_Medium_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Medium1";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper1_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 35;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Medium_2 : IAT_LootBox_Medium_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Medium2";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper2_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 35;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Medium_3 : IAT_LootBox_Medium_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Medium3";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper3_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 35;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Medium_4 : IAT_LootBox_Medium_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Medium4";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper4_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 35;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}} };
                };
            };
        };
    };

    // ============================== LARGES
    class IAT_LootBox_Large_1 : IAT_LootBox_Large_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Large1";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper1_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 40;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_RED_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Large_2 : IAT_LootBox_Large_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Large2";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper2_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 40;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_SILVER_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Large_3 : IAT_LootBox_Large_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Large3";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper3_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 40;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_LootBox_Large_4 : IAT_LootBox_Large_ColorBase
    {
        scope = 2;
        IAT_LootTable = "Large4";
        hiddenSelectionsTextures[] = { "dz\gear\containers\data\christmas_paper4_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa" };
        hiddenSelectionsMaterials[] = { "DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat" };
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints = 40;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}} };
                };
            };
        };
    };
};
