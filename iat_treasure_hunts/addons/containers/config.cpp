class CfgPatches
{
    class IAT_Treasure_Hunts_Containers
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Containers" };
    };
};
class CfgVehicles
{
    class GiftBox_Base;
    class GiftBox_IAT_TreasureHunt : GiftBox_Base
    {
        scope=2;
        displayName="$STR_cfgvehicles_xmasboxsmall0";
        descriptionShort="This giftbox feels lighter than others.";
        hiddenSelectionsTextures[]={"dz\gear\containers\data\christmas_paper1_CO.paa", "dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
        hiddenSelectionsMaterials[]={"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"};
        itemsCargoSize[]={10, 10};
        class DamageSystem : DamageSystem
        {
            class GlobalHealth : GlobalHealth
            {
                class Health
                {
                    hitpoints=30;
                    healthLevels[]={{1, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}}, {0.7, {"DZ\gear\containers\data\christmas_paper1.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}}, {0.5, {"DZ\gear\containers\data\christmas_paper1_damage.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}}, {0.3, {}}, {0, {"DZ\gear\containers\data\christmas_paper1_destruct.rvmat", "DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}}};
                };
            };
        };
    };
};
