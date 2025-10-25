class CfgPatches
{
    class IAT_Prop_Items_Cultivation
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Cultivation" };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    class SeedBase;
    //=================================== VANILLA OVERRIDE
    class TomatoSeeds : SeedBase
    {
        inventorySlot[] += { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        IAT_SeedToReplace = "IAT_SeedPlant_TomatoSeeds";
    };
    class PepperSeeds : SeedBase
    {
        inventorySlot[] += { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        IAT_SeedToReplace = "IAT_SeedPlant_PepperSeeds";
    };
    class PumpkinSeeds : SeedBase
    {
        inventorySlot[] += { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        IAT_SeedToReplace = "IAT_SeedPlant_PumpkinSeeds";
    };
    class ZucchiniSeeds : SeedBase
    {
        inventorySlot[] += { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        IAT_SeedToReplace = "IAT_SeedPlant_ZucchiniSeeds";
    };
    class PotatoSeed : SeedBase
    {
        inventorySlot[] += { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        IAT_SeedToReplace = "IAT_SeedPlant_PotatoSeed";
    };
    class CannabisSeeds : SeedBase
    {
        inventorySlot[] += { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        IAT_SeedToReplace = "IAT_SeedPlant_CannabisSeeds";
    };

    //=================================== POTTED PLANTS
    class IAT_SeedPlant_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Potted Plant Seed";
        descriptionShort = "A seed used to grow plants inside a small container.";
        model = "\dz\gear\cultivation\tomato_seeds.p3d";
        weight = 10;
        itemSize[] = { 1, 1 };
        spawnOffset = 0;
        lootCategory = "Crafted";
        inventorySlot[] = { "IAT_PottedPlant" };
        hiddenSelections[] = { "infestedParts" };
        hiddenSelectionsTextures[] = { "" };
        hiddenSelectionsMaterials[] = { "" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5;
                    healthLevels[] = { {1, {"DZ\gear\cultivation\data\seeds.rvmat"}}, {0.7, {"DZ\gear\cultivation\data\seeds.rvmat"}}, {0.5, {"DZ\gear\cultivation\data\seeds_damage.rvmat"}}, {0.3, {"DZ\gear\cultivation\data\seeds_damage.rvmat"}}, {0, {"DZ\gear\cultivation\data\seeds_destruct.rvmat"}} };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickup
                {
                    soundSet = "seeds_pickup_SoundSet";
                    id = 797;
                };
            };
        };
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    class IAT_SeedPlant_TomatoSeeds1 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds2 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds3 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds4 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds5 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds6 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds7 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_TomatoSeeds8 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\tomato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\tomato_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\tomato_plant.rvmat" };
        IAT_SeedToReplace = "TomatoSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    class IAT_SeedPlant_PepperSeeds1 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds2 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds3 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds4 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds5 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds6 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds7 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PepperSeeds8 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pepper_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pepper_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pepper_plant.rvmat" };
        IAT_SeedToReplace = "PepperSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    class IAT_SeedPlant_PotatoSeed1 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed2 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed3 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed4 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed5 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed6 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed7 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PotatoSeed8 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\potato_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\potato_plant_co.paa", "dz\gear\cultivation\data\potato_plant_nohq.paa", "dz\gear\cultivation\data\potato_plant_smdi.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\potato_plant.rvmat" };
        IAT_SeedToReplace = "PotatoSeed";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    class IAT_SeedPlant_PumpkinSeeds1 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds2 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds3 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds4 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds5 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds6 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds7 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_PumpkinSeeds8 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\pumpkin_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\pumpkin_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\pumpkin_plant.rvmat" };
        IAT_SeedToReplace = "PumpkinSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    class IAT_SeedPlant_ZucchiniSeeds1 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds2 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds3 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds4 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds5 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds6 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds7 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_ZucchiniSeeds8 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\zucchini_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\zucchini_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\zucchini_plant.rvmat" };
        IAT_SeedToReplace = "ZucchiniSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    class IAT_SeedPlant_CannabisSeeds1 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds2 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds3 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds4 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds5 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds6 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds7 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };
    class IAT_SeedPlant_CannabisSeeds8 : IAT_SeedPlant_ColorBase
    {
        scope = 2;
        model = "DZ\gear\cultivation\Cannabis_plant.p3d";
        hiddenSelectionsTextures[] = { "dz\gear\cultivation\data\Cannabis_plant_co.paa" };
        hiddenSelectionsMaterials[] = { "dz\gear\cultivation\data\Cannabis_plant.rvmat" };
        IAT_SeedToReplace = "CannabisSeeds";
        class AnimationSources
        {
            class pile_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class pile_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_01_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_02_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_03_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_04_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class plantStage_05
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_05_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 0;
            };
            class plantStage_06_crops
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
            class stake
            {
                source = "user";
                animPeriod = 0.01;
                initPhase = 1;
            };
        };
    };

    //=================================== Pots
    class IAT_Pot_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Clay Pot";
        descriptionShort = "A handmade clay pot used to for various things.";
        model = "iat_prop_items\cultivation\iat_pot1.p3d";
        lootCategory = "Crafted";
        itemBehaviour = 0;
        weight = 8500;
        itemSize[] = { 12, 12 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        carveNavmesh = 1;
        minPlacingDist = 10;
        attachments[] = { "IAT_PottedPlant", "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pot_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_prop_items\cultivation\data\iat_pot.rvmat" };
        class GUIInventoryAttachmentsProps
        {
            class Plant
            {
                name = "Plant";
                description = "The plant in the pot.";
                attachmentSlots[] = { "IAT_PottedPlant" };
                icon = "set:dayz_inventory image:plant";
            };
            class Seeds
            {
                name = "Plant Growth Stages";
                description = "Each slot is a stage in the plants growth.";
                attachmentSlots[] = { "IAT_PottedSeed1", "IAT_PottedSeed2", "IAT_PottedSeed3", "IAT_PottedSeed4", "IAT_PottedSeed5", "IAT_PottedSeed6", "IAT_PottedSeed7", "IAT_PottedSeed8" };
                icon = "set:dayz_inventory image:seedbase";
            };
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
                        {1,{"iat_prop_items\cultivation\data\iat_pot.rvmat"}},
                        {0.69999999,{"iat_prop_items\cultivation\data\iat_pot.rvmat"}},
                        {0.5,{"iat_prop_items\cultivation\data\iat_pot_damage.rvmat"}},
                        {0.30000001,{"iat_prop_items\cultivation\data\iat_pot_damage.rvmat"}},
                        {0,{"iat_prop_items\cultivation\data\iat_pot_destruct.rvmat"}}
                    };
                };
                class GlobalArmor
                {
                    class Projectile
                    {
                        class Health { damage = 0; };
                        class Blood { damage = 0; };
                        class Shock { damage = 0; };
                    };
                    class FragGrenade
                    {
                        class Health { damage = 0; };
                        class Blood { damage = 0; };
                        class Shock { damage = 0; };
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class movement
                {
                    soundSet = "seachest_movement_SoundSet";
                    id = 1;
                };
                class pickUpItem_Light
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "seachest_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };

    class IAT_Pot1_ColorBase : IAT_Pot_ColorBase
    {
        scope = 0;
        displayName = "Clay Pot - Short";
        descriptionShort = "A handmade clay pot used to for various things.";
        model = "iat_prop_items\cultivation\iat_pot1.p3d";
    };
    class IAT_Pot2_ColorBase : IAT_Pot_ColorBase
    {
        scope = 0;
        displayName = "Clay Pot - Tall";
        descriptionShort = "A handmade clay pot used to for various things.";
        model = "iat_prop_items\cultivation\iat_pot2.p3d";
    };


    class IAT_Pot1_Default : IAT_Pot1_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pot_co.paa" };
    };
    class IAT_Pot2_Default : IAT_Pot2_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pot_co.paa" };
    };

    //==================================== PUMPKINS
    class IAT_Pumpkin_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Pumpkin";
        descriptionShort = "A plump pumpkin with a solid color.";
        model = "iat_prop_items\cultivation\iat_pumpkin_wide_small.p3d";
        itemBehaviour = 0;
        weight = 2500;
        itemSize[] = { 2, 2 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        carveNavmesh = 1;
        minPlacingDist = 10;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1,{"iat_prop_items\cultivation\data\iat_pumpkin.rvmat"}},
                        {0.69999999,{"iat_prop_items\cultivation\data\iat_pumpkin.rvmat"}},
                        {0.5,{"iat_prop_items\cultivation\data\iat_pumpkin_damage.rvmat"}},
                        {0.30000001,{"iat_prop_items\cultivation\data\iat_pumpkin_damage.rvmat"}},
                        {0,{"iat_prop_items\cultivation\data\iat_pumpkin_destruct.rvmat"}}
                    };
                };
                class GlobalArmor
                {
                    class Projectile
                    {
                        class Health { damage = 0; };
                        class Blood { damage = 0; };
                        class Shock { damage = 0; };
                    };
                    class FragGrenade
                    {
                        class Health { damage = 0; };
                        class Blood { damage = 0; };
                        class Shock { damage = 0; };
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class movement
                {
                    soundSet = "seachest_movement_SoundSet";
                    id = 1;
                };
                class pickUpItem_Light
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "seachest_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class IAT_Pumpkin_Wide_Small_ColorBase : IAT_Pumpkin_ColorBase
    {
        scope = 0;
        model = "iat_prop_items\cultivation\iat_pumpkin_wide_small.p3d";
    };
    class IAT_Pumpkin_Wide_Medium_ColorBase : IAT_Pumpkin_ColorBase
    {
        scope = 0;
        itemSize[] = { 3, 3 };
        model = "iat_prop_items\cultivation\iat_pumpkin_wide_medium.p3d";
    };
    class IAT_Pumpkin_Wide_Large_ColorBase : IAT_Pumpkin_ColorBase
    {
        scope = 0;
        itemSize[] = { 4, 4 };
        model = "iat_prop_items\cultivation\iat_pumpkin_wide_large.p3d";
    };
    class IAT_Pumpkin_Tall_Small_ColorBase : IAT_Pumpkin_ColorBase
    {
        scope = 0;
        model = "iat_prop_items\cultivation\iat_pumpkin_tall_small.p3d";
    };
    class IAT_Pumpkin_Tall_Large_ColorBase : IAT_Pumpkin_ColorBase
    {
        scope = 0;
        itemSize[] = { 3, 4 };
        model = "iat_prop_items\cultivation\iat_pumpkin_tall_large.p3d";
    };

    class IAT_Pumpkin_Wide_Small_Orange : IAT_Pumpkin_Wide_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_co.paa" }; };
    class IAT_Pumpkin_Wide_Small_Ivory : IAT_Pumpkin_Wide_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_ivory_co.paa" }; };
    class IAT_Pumpkin_Wide_Small_Purple : IAT_Pumpkin_Wide_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_purple_co.paa" }; };
    class IAT_Pumpkin_Wide_Small_Yellow : IAT_Pumpkin_Wide_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_yellow_co.paa" }; };

    class IAT_Pumpkin_Wide_Medium_Orange : IAT_Pumpkin_Wide_Medium_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_co.paa" }; };
    class IAT_Pumpkin_Wide_Medium_Ivory : IAT_Pumpkin_Wide_Medium_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_ivory_co.paa" }; };
    class IAT_Pumpkin_Wide_Medium_Purple : IAT_Pumpkin_Wide_Medium_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_purple_co.paa" }; };
    class IAT_Pumpkin_Wide_Medium_Yellow : IAT_Pumpkin_Wide_Medium_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_yellow_co.paa" }; };

    class IAT_Pumpkin_Wide_Large_Orange : IAT_Pumpkin_Wide_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_co.paa" }; };
    class IAT_Pumpkin_Wide_Large_Ivory : IAT_Pumpkin_Wide_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_ivory_co.paa" }; };
    class IAT_Pumpkin_Wide_Large_Purple : IAT_Pumpkin_Wide_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_purple_co.paa" }; };
    class IAT_Pumpkin_Wide_Large_Yellow : IAT_Pumpkin_Wide_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_yellow_co.paa" }; };

    class IAT_Pumpkin_Tall_Small_Orange : IAT_Pumpkin_Tall_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_co.paa" }; };
    class IAT_Pumpkin_Tall_Small_Ivory : IAT_Pumpkin_Tall_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_ivory_co.paa" }; };
    class IAT_Pumpkin_Tall_Small_Purple : IAT_Pumpkin_Tall_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_purple_co.paa" }; };
    class IAT_Pumpkin_Tall_Small_Yellow : IAT_Pumpkin_Tall_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_yellow_co.paa" }; };

    class IAT_Pumpkin_Tall_Large_Orange : IAT_Pumpkin_Tall_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_co.paa" }; };
    class IAT_Pumpkin_Tall_Large_Ivory : IAT_Pumpkin_Tall_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_ivory_co.paa" }; };
    class IAT_Pumpkin_Tall_Large_Purple : IAT_Pumpkin_Tall_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_purple_co.paa" }; };
    class IAT_Pumpkin_Tall_Large_Yellow : IAT_Pumpkin_Tall_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkin_yellow_co.paa" }; };

    class IAT_PumpkinCarved_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Carved Pumpkin";
        descriptionShort = "A plump pumpkin with a solid color. A face has been carved into the front.";
        model = "iat_prop_items\cultivation\iat_carvedpumpkin_large.p3d";
        itemBehaviour = 0;
        weight = 2500;
        itemSize[] = { 2, 2 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        carveNavmesh = 1;
        minPlacingDist = 10;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkincarved_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1,{"iat_prop_items\cultivation\data\iat_pumpkincarved.rvmat"}},
                        {0.69999999,{"iat_prop_items\cultivation\data\iat_pumpkincarved.rvmat"}},
                        {0.5,{"iat_prop_items\cultivation\data\iat_pumpkincarved_damage.rvmat"}},
                        {0.30000001,{"iat_prop_items\cultivation\data\iat_pumpkincarved_damage.rvmat"}},
                        {0,{"iat_prop_items\cultivation\data\iat_pumpkincarved_destruct.rvmat"}}
                    };
                };
                class GlobalArmor
                {
                    class Projectile
                    {
                        class Health { damage = 0; };
                        class Blood { damage = 0; };
                        class Shock { damage = 0; };
                    };
                    class FragGrenade
                    {
                        class Health { damage = 0; };
                        class Blood { damage = 0; };
                        class Shock { damage = 0; };
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class movement
                {
                    soundSet = "seachest_movement_SoundSet";
                    id = 1;
                };
                class pickUpItem_Light
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpSeaChest_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "seachest_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class IAT_PumpkinCarved_Large_ColorBase : IAT_PumpkinCarved_ColorBase
    {
        scope = 0;
        itemSize[] = { 4, 4 };
        model = "iat_prop_items\cultivation\iat_carvedpumpkin_large.p3d";
    };
    class IAT_PumpkinCarved_Medium_ColorBase : IAT_PumpkinCarved_ColorBase
    {
        scope = 0;
        itemSize[] = { 3, 3 };
        model = "iat_prop_items\cultivation\iat_carvedpumpkin_medium.p3d";
    };
    class IAT_PumpkinCarved_Small_ColorBase : IAT_PumpkinCarved_ColorBase
    {
        scope = 0;
        model = "iat_prop_items\cultivation\iat_carvedpumpkin_small.p3d";
    };

    class IAT_PumpkinCarved_Small_Orange : IAT_PumpkinCarved_Small_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkincarved_co.paa" }; };
    class IAT_PumpkinCarved_Medium_Orange : IAT_PumpkinCarved_Medium_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkincarved_co.paa" }; };
    class IAT_PumpkinCarved_Large_Orange : IAT_PumpkinCarved_Large_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_prop_items\cultivation\data\iat_pumpkincarved_co.paa" }; };

};
class CfgSlots
{
    class Slot_IAT_PottedSeed1
    {
        name = "IAT_PottedSeed1";
        displayName = "Growth Stage 1";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed2
    {
        name = "IAT_PottedSeed2";
        displayName = "Growth Stage 2";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed3
    {
        name = "IAT_PottedSeed3";
        displayName = "Growth Stage 3";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed4
    {
        name = "IAT_PottedSeed4";
        displayName = "Growth Stage 4";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed5
    {
        name = "IAT_PottedSeed5";
        displayName = "Growth Stage 5";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed6
    {
        name = "IAT_PottedSeed6";
        displayName = "Growth Stage 6";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed7
    {
        name = "IAT_PottedSeed7";
        displayName = "Growth Stage 7";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
    class Slot_IAT_PottedSeed8
    {
        name = "IAT_PottedSeed8";
        displayName = "Growth Stage 8";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };

    class Slot_IAT_PottedPlant
    {
        name = "IAT_PottedPlant";
        displayName = "Potted Plant";
        ghostIcon = "set:dayz_inventory image:seedbase";
        stackMax = 1;
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyiat_pottedplant_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_PottedPlant" };
        model = "iat_prop_items\cultivation\proxy\iat_pottedplant_proxy.p3d";
    };
};