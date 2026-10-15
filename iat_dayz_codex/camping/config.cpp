class CfgPatches
{
    class IAT_DayZ_Codex_Camping
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    class IAT_DayZCodex_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Worn Book";
        descriptionShort = "A worn book.";
        model="\DZ\gear\books\Book_kniga.p3d";
        weight=200;
        absorbency=1;
        varWetMax=1;
        itemSize[]={2, 2};
        rotationFlags = 16;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "dz\gear\books\data\book_kniga_co.paa" };
        quantityShow=0;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=100;
                    healthLevels[]={{1, {"DZ\gear\books\Data\book.rvmat"}}, {0.7, {"DZ\gear\books\Data\book.rvmat"}}, {0.5, {"DZ\gear\books\Data\book_damage.rvmat"}}, {0.3, {"DZ\gear\books\Data\book_damage.rvmat"}}, {0, {"DZ\gear\books\Data\book_destruct.rvmat"}}};
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet="pickUpPaper_SoundSet";
                    id=797;
                };
            };
        };
    };

    //===================== CUSTOM CODEX
    class IAT_DayZCodex_Journal : IAT_DayZCodex_ColorBase
    {
        scope = 2;
        displayName = "Collectors Codex";
        descriptionShort = "A journal that records notable things.";
        hiddenSelectionsTextures[] = { "iat_dayz_codex\camping\data\a_clean_book_example_co.paa" };
    };
};