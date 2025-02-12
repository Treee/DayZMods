class CfgPatches
{
    class IAT_InfinityGauntlet_Consumables
    {
        requiredAddons[] = { "DZ_Gear_Consumables" };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    class IAT_InfinityStone_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Infinity Stone";
        descriptionShort = "The remnant of a singularity that existed before the Big Bang. Compressed into this stone by cosmic entities.";
        model = "\dz\gear\consumables\SmallStone.p3d";
        animClass = "NoFireClass";
        weight = 500;
        itemSize[] = { 1, 1 };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] = {
                        {1, {"DZ\gear\consumables\data\stone.rvmat"}},
                        {0.7, {"DZ\gear\consumables\data\stone.rvmat"}},
                        {0.5, {"DZ\gear\consumables\data\stone_damage.rvmat"}},
                        {0.3, {"DZ\gear\consumables\data\stone_damage.rvmat"}},
                        {0, {"DZ\gear\consumables\data\stone_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class IAT_InfinityStone_Mind : IAT_InfinityStone_ColorBase
    {
        scope = 2;
        model = "iat_infinity_gauntlet\consumables\iat_infinitystone_mind.p3d";
        displayName = "Infinity Stone - Mind";
        inventorySlot[] = { "IAT_InfinityStone_Mind" };
    };
    class IAT_InfinityStone_Power : IAT_InfinityStone_ColorBase
    {
        scope = 2;
        model = "iat_infinity_gauntlet\consumables\iat_infinitystone_power.p3d";
        displayName = "Infinity Stone - Power";
        inventorySlot[] = { "IAT_InfinityStone_Power" };
    };
    class IAT_InfinityStone_Reality : IAT_InfinityStone_ColorBase
    {
        scope = 2;
        model = "iat_infinity_gauntlet\consumables\iat_infinitystone_reality.p3d";
        displayName = "Infinity Stone - Reality";
        inventorySlot[] = { "IAT_InfinityStone_Reality" };
    };
    class IAT_InfinityStone_Soul : IAT_InfinityStone_ColorBase
    {
        scope = 2;
        model = "iat_infinity_gauntlet\consumables\iat_infinitystone_soul.p3d";
        displayName = "Infinity Stone - Soul";
        inventorySlot[] = { "IAT_InfinityStone_Soul" };
    };
    class IAT_InfinityStone_Space : IAT_InfinityStone_ColorBase
    {
        scope = 2;
        model = "iat_infinity_gauntlet\consumables\iat_infinitystone_space.p3d";
        displayName = "Infinity Stone - Space";
        inventorySlot[] = { "IAT_InfinityStone_Space" };
    };
    class IAT_InfinityStone_Time : IAT_InfinityStone_ColorBase
    {
        scope = 2;
        model = "iat_infinity_gauntlet\consumables\iat_infinitystone_time.p3d";
        displayName = "Infinity Stone - Time";
        inventorySlot[] = { "IAT_InfinityStone_Time" };
    };

};