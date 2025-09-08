class CfgPatches
{
    class IAT_Prop_Items_Camping
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping" };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    //=================================== BEARS
    class IAT_Bear_ColorBase : Inventory_Base
    {
        displayName = "$STR_CfgVehicles_Bear_ColorBase0";
        descriptionShort = "$STR_CfgVehicles_Bear_ColorBase1";
        model = "\dz\gear\containers\teddybear.p3d";
        weight = 130;
        itemSize[] = { 2, 3 };
        itemsCargoSize[] = { 0, 0 };
        canBeDigged = 1;
        allowOwnedCargoManipulation = 1;
        repairableWithKits[] = { 2 };
        repairCosts[] = { 25 };
        hiddenSelections[] = { "camoGround" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 30;
                    healthLevels[] = { {1, {"DZ\gear\containers\data\teddybear.rvmat"}}, {0.7, {"DZ\gear\containers\data\teddybear.rvmat"}}, {0.5, {"DZ\gear\containers\data\teddybear_damage.rvmat"}}, {0.3, {"DZ\gear\containers\data\teddybear_damage.rvmat"}}, {0, {"DZ\gear\containers\data\teddybear_destruct.rvmat"}} };
                };
            };
        };
        soundImpactType = "textile";
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem_Light
                {
                    soundSet = "pickUpCourierBag_Light_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpCourierBag_SoundSet";
                    id = 797;
                };
            };
        };
    };

    class IAT_Bear_Beige : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_brown_co.paa" };
    };
    class IAT_Bear_Dark : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_dark_co.paa" };
    };
    class IAT_Bear_Pink : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_pink_co.paa" };
    };
    class IAT_Bear_White : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_white_co.paa" };
    };
    class IAT_Bear_BuzzingGhosts : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_buzzingghosts_co.paa" };
    };
    class IAT_Bear_MidnightCollective : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_midnightcollective_co.paa" };
    };
    class IAT_Bear_Rainbow : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_rainbow_co.paa" };
    };
    class IAT_Bear_TigerCamo : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_woodhouse_co.paa" };
    };
    class IAT_Bear_Liam : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_liam_co.paa" };
    };
    class IAT_Bear_Deadpool : IAT_Bear_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\teddybear_deadpool_co.paa" };
    };

    //=================================== Flags (for the belt)
    class Flag_Base : Inventory_Base // slot overrides
    {
        inventorySlot[] += { "IAT_VanillaFlag", "IAT_BeltFlag" };
    };
    class IAT_BeltFlag_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Belt Flag";
        descriptionShort = "This small flag attaches to the leather flag belt.";
        model = "iat_prop_items\camping\iat_beltflag.p3d";
        itemSize[] = { 2,2 };
        absorbency = 0.89999998;
        ragQuantity = 6;
        rotationFlags = 16;
        inventorySlot[] = { "IAT_VanillaFlag", "IAT_BeltFlag" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_beltflag_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1,{""}},
                        {0.69999999,{""}},
                        {0.5,{""}},
                        {0.30000001,{""}},
                        {0,{""}}
                    };
                };
                class GlobalArmor
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage = 0;
                        };
                        class Blood
                        {
                            damage = 0;
                        };
                        class Shock
                        {
                            damage = 0;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage = 0;
                        };
                        class Blood
                        {
                            damage = 0;
                        };
                        class Shock
                        {
                            damage = 0;
                        };
                    };
                };
            };
        };
    };
    class IAT_BeltFlag_Basic : IAT_BeltFlag_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_beltflag_co.paa" };
    };

    //=================================== STEPLADDER
    class IAT_Ladder_Closed_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Closed Ladder";
        descriptionShort = "A ladder that can be used to vault over tall walls or reach high places.";
        model = "iat_prop_items\camping\iat_ladder_closed.p3d";
        itemBehaviour = 1;
        rotationFlags = 16;
        weight = 27000;
        slopeTolerance = 0.4;
        yawPitchRollLimit[] = { 45, 45, 45 };
        itemSize[] = { 12, 12 };
        carveNavmesh = 1;
        soundImpactType = "wood";
        projectionTypename = "IAT_Ladder_Opened_Basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1.0, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.69999999, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.5, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.30000001, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.0, { "iat_prop_items\camping\data\iat_ladder_destruct.rvmat"}}
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

    class IAT_Ladder_Closed_Basic : IAT_Ladder_Closed_ColorBase
    {
        scope = 2;
        color = "basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
    };

    class IAT_Ladder_Opened_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "deployed Ladder";
        descriptionShort = "A ladder that can be used to vault over tall walls or reach high places.";
        model = "iat_prop_items\camping\iat_ladder_opened.p3d";
        itemBehaviour = 2;
        rotationFlags = 64;
        weight = 17000;
        carveNavmesh = 1;
        itemSize[] = { 12, 12 };
        soundImpactType = "wood";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1.0, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.69999999, { "iat_prop_items\camping\data\iat_ladder.rvmat"}},
                        {0.5, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.30000001, { "iat_prop_items\camping\data\iat_ladder_damage.rvmat"}},
                        {0.0, { "iat_prop_items\camping\data\iat_ladder_destruct.rvmat"}}
                    };
                };
            };
        };
    };
    class IAT_Ladder_Opened_Basic : IAT_Ladder_Opened_ColorBase
    {
        scope = 2;
        color = "basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_ladder_co.paa" };
    };

    //=================================== PLAYING CARDS
    class IAT_CardDeck_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Playing Card Deck";
        descriptionShort = "A small container that holds playing cards. Will you collect them all?";
        model = "iat_prop_items\camping\iat_playingcarddeck.p3d";
        weight = 100;
        absorbency = 1;
        rotationFlags = 16;
        itemSize[] = { 1, 2 };
        itemsCargoSize[] = { 0,0 };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_deckofcards_co.paa" };
        attachments[] = { "IAT_Card1","IAT_Card2","IAT_Card3","IAT_Card4","IAT_Card5","IAT_Card6","IAT_Card7","IAT_Card8","IAT_Card9","IAT_Card10","IAT_Card11","IAT_Card12","IAT_Card13","IAT_Card14","IAT_Card15","IAT_Card16","IAT_Card17","IAT_Card18","IAT_Card19","IAT_Card20","IAT_Card21","IAT_Card22","IAT_Card23","IAT_Card24","IAT_Card25","IAT_Card26","IAT_Card27","IAT_Card28","IAT_Card29","IAT_Card30","IAT_Card31","IAT_Card32","IAT_Card33","IAT_Card34","IAT_Card35","IAT_Card36","IAT_Card37","IAT_Card38","IAT_Card39","IAT_Card40","IAT_Card41","IAT_Card42","IAT_Card43","IAT_Card44","IAT_Card45","IAT_Card46","IAT_Card47","IAT_Card48","IAT_Card49","IAT_Card50","IAT_Card51","IAT_Card52","IAT_Card53","IAT_Card54" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 200;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\camping\data\iat_deckofcards.rvmat"}},
                        {0.7, {"iat_prop_items\camping\data\iat_deckofcards.rvmat"}},
                        {0.5, {"iat_prop_items\camping\data\iat_deckofcards_damage.rvmat"}},
                        {0.3, {"iat_prop_items\camping\data\iat_deckofcards_damage.rvmat"}},
                        {0, {"iat_prop_items\camping\data\iat_deckofcards_destruct.rvmat"}}
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
                    soundSet = "pickUpPaper_SoundSet";
                    id = 797;
                };
            };
        };
        class GUIInventoryAttachmentsProps
        {
            class Hearts
            {
                name = "Hearts";
                attachmentSlots[] = { "IAT_Card1","IAT_Card2","IAT_Card3","IAT_Card4","IAT_Card5","IAT_Card6","IAT_Card7","IAT_Card8","IAT_Card9","IAT_Card10","IAT_Card11","IAT_Card12","IAT_Card13" };
                icon = "set:dayz_inventory image:paper";
            };
            class Clubs
            {
                name = "Clubs";
                attachmentSlots[] = { "IAT_Card14","IAT_Card15","IAT_Card16","IAT_Card17","IAT_Card18","IAT_Card19","IAT_Card20","IAT_Card21","IAT_Card22","IAT_Card23","IAT_Card24","IAT_Card25","IAT_Card26" };
                icon = "set:dayz_inventory image:paper";
            };
            class Diamonds
            {
                name = "Diamonds";
                attachmentSlots[] = { "IAT_Card27","IAT_Card28","IAT_Card29","IAT_Card30","IAT_Card31","IAT_Card32","IAT_Card33","IAT_Card34","IAT_Card35","IAT_Card36","IAT_Card37","IAT_Card38","IAT_Card39" };
                icon = "set:dayz_inventory image:paper";
            };
            class Spades
            {
                name = "Spades";
                attachmentSlots[] = { "IAT_Card40","IAT_Card41","IAT_Card42","IAT_Card43","IAT_Card44","IAT_Card45","IAT_Card46","IAT_Card47","IAT_Card48","IAT_Card49","IAT_Card50","IAT_Card51","IAT_Card52" };
                icon = "set:dayz_inventory image:paper";
            };
            class Jokers
            {
                name = "Jokers";
                attachmentSlots[] = { "IAT_Card53","IAT_Card54" };
                icon = "set:dayz_inventory image:paper";
            };
        };
    };
    class IAT_CardDeck_Basic : IAT_CardDeck_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_deckofcards_co.paa" };
    };

    class IAT_PlayingCard_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Playing Card";
        descriptionShort = "A dirty playing card that has seen many years of use in the apocalypse.";
        model = "iat_prop_items\camping\cards\iat_playingcard_1c.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { "IAT_Card1","IAT_Card2","IAT_Card3","IAT_Card4","IAT_Card5","IAT_Card6","IAT_Card7","IAT_Card8","IAT_Card9","IAT_Card10","IAT_Card11","IAT_Card12","IAT_Card13","IAT_Card14","IAT_Card15","IAT_Card16","IAT_Card17","IAT_Card18","IAT_Card19","IAT_Card20","IAT_Card21","IAT_Card22","IAT_Card23","IAT_Card24","IAT_Card25","IAT_Card26","IAT_Card27","IAT_Card28","IAT_Card29","IAT_Card30","IAT_Card31","IAT_Card32","IAT_Card33","IAT_Card34","IAT_Card35","IAT_Card36","IAT_Card37","IAT_Card38","IAT_Card39","IAT_Card40","IAT_Card41","IAT_Card42","IAT_Card43","IAT_Card44","IAT_Card45","IAT_Card46","IAT_Card47","IAT_Card48","IAT_Card49","IAT_Card50","IAT_Card51","IAT_Card52","IAT_Card53","IAT_Card54" };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_playingcards_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\camping\data\iat_playingcards.rvmat"}},
                        {0.7, {"iat_prop_items\camping\data\iat_playingcards.rvmat"}},
                        {0.5, {"iat_prop_items\camping\data\iat_playingcards_damage.rvmat"}},
                        {0.3, {"iat_prop_items\camping\data\iat_playingcards_damage.rvmat"}},
                        {0, {"iat_prop_items\camping\data\iat_playingcards_destruct.rvmat"}}
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
                    soundSet = "pickUpPaper_SoundSet";
                    id = 797;
                };
            };
        };
    };
    // hearts
    class IAT_PlayingCard_1h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_1h.p3d";
    };
    class IAT_PlayingCard_2h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_2h.p3d";
    };
    class IAT_PlayingCard_3h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_3h.p3d";
    };
    class IAT_PlayingCard_4h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_4h.p3d";
    };
    class IAT_PlayingCard_5h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_5h.p3d";
    };
    class IAT_PlayingCard_6h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_6h.p3d";
    };
    class IAT_PlayingCard_7h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_7h.p3d";
    };
    class IAT_PlayingCard_8h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_8h.p3d";
    };
    class IAT_PlayingCard_9h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_9h.p3d";
    };
    class IAT_PlayingCard_10h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_10h.p3d";
    };
    class IAT_PlayingCard_11h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Jack of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_11h.p3d";
    };
    class IAT_PlayingCard_12h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_12h.p3d";
    };
    class IAT_PlayingCard_13h : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "King of Hearts";
        model = "iat_prop_items\camping\cards\iat_playingcard_13h.p3d";
    };
    // clubs
    class IAT_PlayingCard_1c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_1c.p3d";
    };
    class IAT_PlayingCard_2c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_2c.p3d";
    };
    class IAT_PlayingCard_3c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_3c.p3d";
    };
    class IAT_PlayingCard_4c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_4c.p3d";
    };
    class IAT_PlayingCard_5c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_5c.p3d";
    };
    class IAT_PlayingCard_6c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_6c.p3d";
    };
    class IAT_PlayingCard_7c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_7c.p3d";
    };
    class IAT_PlayingCard_8c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_8c.p3d";
    };
    class IAT_PlayingCard_9c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_9c.p3d";
    };
    class IAT_PlayingCard_10c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_10c.p3d";
    };
    class IAT_PlayingCard_11c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Jack of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_11c.p3d";
    };
    class IAT_PlayingCard_12c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_12c.p3d";
    };
    class IAT_PlayingCard_13c : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "King of Clubs";
        model = "iat_prop_items\camping\cards\iat_playingcard_13c.p3d";
    };
    // diamonds
    class IAT_PlayingCard_1d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_1d.p3d";
    };
    class IAT_PlayingCard_2d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_2d.p3d";
    };
    class IAT_PlayingCard_3d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_3d.p3d";
    };
    class IAT_PlayingCard_4d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_4d.p3d";
    };
    class IAT_PlayingCard_5d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_5d.p3d";
    };
    class IAT_PlayingCard_6d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_6d.p3d";
    };
    class IAT_PlayingCard_7d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_7d.p3d";
    };
    class IAT_PlayingCard_8d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_8d.p3d";
    };
    class IAT_PlayingCard_9d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_9d.p3d";
    };
    class IAT_PlayingCard_10d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_10d.p3d";
    };
    class IAT_PlayingCard_11d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Jack of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_11d.p3d";
    };
    class IAT_PlayingCard_12d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_12d.p3d";
    };
    class IAT_PlayingCard_13d : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "King of Diamonds";
        model = "iat_prop_items\camping\cards\iat_playingcard_13d.p3d";
    };
    // spades
    class IAT_PlayingCard_1s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_1s.p3d";
    };
    class IAT_PlayingCard_2s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_2s.p3d";
    };
    class IAT_PlayingCard_3s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_3s.p3d";
    };
    class IAT_PlayingCard_4s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_4s.p3d";
    };
    class IAT_PlayingCard_5s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_5s.p3d";
    };
    class IAT_PlayingCard_6s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_6s.p3d";
    };
    class IAT_PlayingCard_7s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_7s.p3d";
    };
    class IAT_PlayingCard_8s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_8s.p3d";
    };
    class IAT_PlayingCard_9s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_9s.p3d";
    };
    class IAT_PlayingCard_10s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_10s.p3d";
    };
    class IAT_PlayingCard_11s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Jack of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_11s.p3d";
    };
    class IAT_PlayingCard_12s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_12s.p3d";
    };
    class IAT_PlayingCard_13s : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "King of Spades";
        model = "iat_prop_items\camping\cards\iat_playingcard_13s.p3d";
    };
    // jokers
    class IAT_PlayingCard_1j : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Joker";
        model = "iat_prop_items\camping\cards\iat_playingcard_joker1.p3d";
    };
    class IAT_PlayingCard_2j : IAT_PlayingCard_Colorbase
    {
        scope = 2;
        displayName = "Joker";
        model = "iat_prop_items\camping\cards\iat_playingcard_joker2.p3d";
    };

    //=================================== TAROT CARDS
    class IAT_TarotCardDeck_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Tarot Card Deck";
        descriptionShort = "A small container that holds tarot cards. Will you collect them all?";
        model = "iat_prop_items\camping\iat_tarotcarddeck.p3d";
        weight = 100;
        absorbency = 1;
        rotationFlags = 16;
        itemSize[] = { 1, 2 };
        itemsCargoSize[] = { 0,0 };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_deckoftarotcards_co.paa" };
        attachments[] = { "IAT_TCard1","IAT_TCard2","IAT_TCard3","IAT_TCard4","IAT_TCard5","IAT_TCard6","IAT_TCard7","IAT_TCard8","IAT_TCard9","IAT_TCard10","IAT_TCard11","IAT_TCard12","IAT_TCard13","IAT_TCard14","IAT_TCard15","IAT_TCard16","IAT_TCard17","IAT_TCard18","IAT_TCard19","IAT_TCard20","IAT_TCard21","IAT_TCard22","IAT_TCard23","IAT_TCard24","IAT_TCard25","IAT_TCard26","IAT_TCard27","IAT_TCard28","IAT_TCard29","IAT_TCard30","IAT_TCard31","IAT_TCard32","IAT_TCard33","IAT_TCard34","IAT_TCard35","IAT_TCard36","IAT_TCard37","IAT_TCard38","IAT_TCard39","IAT_TCard40","IAT_TCard41","IAT_TCard42","IAT_TCard43","IAT_TCard44","IAT_TCard45","IAT_TCard46","IAT_TCard47","IAT_TCard48","IAT_TCard49","IAT_TCard50","IAT_TCard51","IAT_TCard52","IAT_TCard53","IAT_TCard54","IAT_TCard55","IAT_TCard56","IAT_TCard57","IAT_TCard58","IAT_TCard59","IAT_TCard60","IAT_TCard61","IAT_TCard62","IAT_TCard63","IAT_TCard64","IAT_TCard65","IAT_TCard66","IAT_TCard67","IAT_TCard68","IAT_TCard69","IAT_TCard70","IAT_TCard71","IAT_TCard72","IAT_TCard73","IAT_TCard74","IAT_TCard75","IAT_TCard76","IAT_TCard77","IAT_TCard78" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 200;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\camping\data\iat_deckoftarotcards.rvmat"}},
                        {0.7, {"iat_prop_items\camping\data\iat_deckoftarotcards.rvmat"}},
                        {0.5, {"iat_prop_items\camping\data\iat_deckoftarotcards_damage.rvmat"}},
                        {0.3, {"iat_prop_items\camping\data\iat_deckoftarotcards_damage.rvmat"}},
                        {0, {"iat_prop_items\camping\data\iat_deckoftarotcards_destruct.rvmat"}}
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
                    soundSet = "pickUpPaper_SoundSet";
                    id = 797;
                };
            };
        };
        class GUIInventoryAttachmentsProps
        {
            class Wands
            {
                name = "Wands";
                attachmentSlots[] = { "IAT_TCard1","IAT_TCard2","IAT_TCard3","IAT_TCard4","IAT_TCard5","IAT_TCard6","IAT_TCard7","IAT_TCard8","IAT_TCard9","IAT_TCard10","IAT_TCard11","IAT_TCard12","IAT_TCard13","IAT_TCard14" };
                icon = "set:dayz_inventory image:paper";
            };
            class Cups
            {
                name = "Cups";
                attachmentSlots[] = { "IAT_TCard15","IAT_TCard16","IAT_TCard17","IAT_TCard18","IAT_TCard19","IAT_TCard20","IAT_TCard21","IAT_TCard22","IAT_TCard23","IAT_TCard24","IAT_TCard25","IAT_TCard26","IAT_TCard27","IAT_TCard28" };
                icon = "set:dayz_inventory image:paper";
            };
            class Swords
            {
                name = "Swords";
                attachmentSlots[] = { "IAT_TCard29","IAT_TCard30","IAT_TCard31","IAT_TCard32","IAT_TCard33","IAT_TCard34","IAT_TCard35","IAT_TCard36","IAT_TCard37","IAT_TCard38","IAT_TCard39","IAT_TCard40","IAT_TCard41","IAT_TCard42" };
                icon = "set:dayz_inventory image:paper";
            };
            class Pentacles
            {
                name = "Pentacles";
                attachmentSlots[] = { "IAT_TCard43","IAT_TCard44","IAT_TCard45","IAT_TCard46","IAT_TCard47","IAT_TCard48","IAT_TCard49","IAT_TCard50","IAT_TCard51","IAT_TCard52","IAT_TCard53","IAT_TCard54","IAT_TCard55","IAT_TCard56" };
                icon = "set:dayz_inventory image:paper";
            };
            class MajorArcana
            {
                name = "MajorArcana";
                attachmentSlots[] = { "IAT_TCard57","IAT_TCard58","IAT_TCard59","IAT_TCard60","IAT_TCard61","IAT_TCard62","IAT_TCard63","IAT_TCard64","IAT_TCard65","IAT_TCard66","IAT_TCard67","IAT_TCard68","IAT_TCard69","IAT_TCard70","IAT_TCard71","IAT_TCard72","IAT_TCard73","IAT_TCard74","IAT_TCard75","IAT_TCard76","IAT_TCard77","IAT_TCard78" };
                icon = "set:dayz_inventory image:paper";
            };
        };
    };
    class IAT_TarotCardDeck_Basic : IAT_TarotCardDeck_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_deckoftarotcards_co.paa" };

    };
    class IAT_TarotCardDeck_essesentiendum : IAT_TarotCardDeck_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_deckofcards_essesentiendum_co.paa" };
    };

    class IAT_TarotCard_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Tarot Card";
        descriptionShort = "A dirty tarot card that has seen many years of use in the apocalypse.";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_1w.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { "IAT_OccultCard1", "IAT_OccultCard2", "IAT_OccultCard3", "IAT_OccultCard4", "IAT_OccultCard5", "IAT_OccultCard6", "IAT_OccultCard7", "IAT_OccultCard8","IAT_TCard1","IAT_TCard2","IAT_TCard3","IAT_TCard4","IAT_TCard5","IAT_TCard6","IAT_TCard7","IAT_TCard8","IAT_TCard9","IAT_TCard10","IAT_TCard11","IAT_TCard12","IAT_TCard13","IAT_TCard14","IAT_TCard15","IAT_TCard16","IAT_TCard17","IAT_TCard18","IAT_TCard19","IAT_TCard20","IAT_TCard21","IAT_TCard22","IAT_TCard23","IAT_TCard24","IAT_TCard25","IAT_TCard26","IAT_TCard27","IAT_TCard28","IAT_TCard29","IAT_TCard30","IAT_TCard31","IAT_TCard32","IAT_TCard33","IAT_TCard34","IAT_TCard35","IAT_TCard36","IAT_TCard37","IAT_TCard38","IAT_TCard39","IAT_TCard40","IAT_TCard41","IAT_TCard42","IAT_TCard43","IAT_TCard44","IAT_TCard45","IAT_TCard46","IAT_TCard47","IAT_TCard48","IAT_TCard49","IAT_TCard50","IAT_TCard51","IAT_TCard52","IAT_TCard53","IAT_TCard54","IAT_TCard55","IAT_TCard56","IAT_TCard57","IAT_TCard58","IAT_TCard59","IAT_TCard60","IAT_TCard61","IAT_TCard62","IAT_TCard63","IAT_TCard64","IAT_TCard65","IAT_TCard66","IAT_TCard67","IAT_TCard68","IAT_TCard69","IAT_TCard70","IAT_TCard71","IAT_TCard72","IAT_TCard73","IAT_TCard74","IAT_TCard75","IAT_TCard76","IAT_TCard77","IAT_TCard78" };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_tarotcards_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\camping\data\iat_playingcards.rvmat"}},
                        {0.7, {"iat_prop_items\camping\data\iat_playingcards.rvmat"}},
                        {0.5, {"iat_prop_items\camping\data\iat_playingcards_damage.rvmat"}},
                        {0.3, {"iat_prop_items\camping\data\iat_playingcards_damage.rvmat"}},
                        {0, {"iat_prop_items\camping\data\iat_playingcards_destruct.rvmat"}}
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
                    soundSet = "pickUpPaper_SoundSet";
                    id = 797;
                };
            };
        };
    };
    // wands
    class IAT_TarotCard_1w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_1w.p3d";
    };
    class IAT_TarotCard_2w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_2w.p3d";
    };
    class IAT_TarotCard_3w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_3w.p3d";
    };
    class IAT_TarotCard_4w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_4w.p3d";
    };
    class IAT_TarotCard_5w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_5w.p3d";
    };
    class IAT_TarotCard_6w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_6w.p3d";
    };
    class IAT_TarotCard_7w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_7w.p3d";
    };
    class IAT_TarotCard_8w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_8w.p3d";
    };
    class IAT_TarotCard_9w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_9w.p3d";
    };
    class IAT_TarotCard_10w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_10w.p3d";
    };
    class IAT_TarotCard_11w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Page of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_11w.p3d";
    };
    class IAT_TarotCard_12w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Knight of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_12w.p3d";
    };
    class IAT_TarotCard_13w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_13w.p3d";
    };
    class IAT_TarotCard_14w : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "King of Wands";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_14w.p3d";
    };

    // cups
    class IAT_TarotCard_1c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_1c.p3d";
    };
    class IAT_TarotCard_2c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_2c.p3d";
    };
    class IAT_TarotCard_3c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_3c.p3d";
    };
    class IAT_TarotCard_4c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_4c.p3d";
    };
    class IAT_TarotCard_5c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_5c.p3d";
    };
    class IAT_TarotCard_6c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_6c.p3d";
    };
    class IAT_TarotCard_7c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_7c.p3d";
    };
    class IAT_TarotCard_8c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_8c.p3d";
    };
    class IAT_TarotCard_9c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_9c.p3d";
    };
    class IAT_TarotCard_10c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_10c.p3d";
    };
    class IAT_TarotCard_11c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Page of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_11c.p3d";
    };
    class IAT_TarotCard_12c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Knight of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_12c.p3d";
    };
    class IAT_TarotCard_13c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_13c.p3d";
    };
    class IAT_TarotCard_14c : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "King of Cups";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_14c.p3d";
    };

    // swords
    class IAT_TarotCard_1s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_1s.p3d";
    };
    class IAT_TarotCard_2s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_2s.p3d";
    };
    class IAT_TarotCard_3s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_3s.p3d";
    };
    class IAT_TarotCard_4s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_4s.p3d";
    };
    class IAT_TarotCard_5s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_5s.p3d";
    };
    class IAT_TarotCard_6s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_6s.p3d";
    };
    class IAT_TarotCard_7s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_7s.p3d";
    };
    class IAT_TarotCard_8s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_8s.p3d";
    };
    class IAT_TarotCard_9s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_9s.p3d";
    };
    class IAT_TarotCard_10s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_10s.p3d";
    };
    class IAT_TarotCard_11s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Page of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_11s.p3d";
    };
    class IAT_TarotCard_12s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Knight of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_12s.p3d";
    };
    class IAT_TarotCard_13s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_13s.p3d";
    };
    class IAT_TarotCard_14s : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "King of Swords";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_14s.p3d";
    };

    // swords
    class IAT_TarotCard_1p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Ace of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_1p.p3d";
    };
    class IAT_TarotCard_2p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "2 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_2p.p3d";
    };
    class IAT_TarotCard_3p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "3 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_3p.p3d";
    };
    class IAT_TarotCard_4p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "4 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_4p.p3d";
    };
    class IAT_TarotCard_5p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "5 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_5p.p3d";
    };
    class IAT_TarotCard_6p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "6 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_6p.p3d";
    };
    class IAT_TarotCard_7p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "7 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_7p.p3d";
    };
    class IAT_TarotCard_8p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "8 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_8p.p3d";
    };
    class IAT_TarotCard_9p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "9 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_9p.p3d";
    };
    class IAT_TarotCard_10p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "10 of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_10p.p3d";
    };
    class IAT_TarotCard_11p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Page of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_11p.p3d";
    };
    class IAT_TarotCard_12p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Knight of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_12p.p3d";
    };
    class IAT_TarotCard_13p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Queen of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_13p.p3d";
    };
    class IAT_TarotCard_14p : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "King of Pentacles";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_14p.p3d";
    };

    // major arcana
    class IAT_TarotCard_1ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Fool";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_1ma.p3d";
    };
    class IAT_TarotCard_2ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Magician";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_2ma.p3d";
    };
    class IAT_TarotCard_3ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The High Priestess";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_3ma.p3d";
    };
    class IAT_TarotCard_4ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Empress";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_4ma.p3d";
    };
    class IAT_TarotCard_5ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Emperor";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_5ma.p3d";
    };
    class IAT_TarotCard_6ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Hierophant";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_6ma.p3d";
    };
    class IAT_TarotCard_7ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Lovers";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_7ma.p3d";
    };
    class IAT_TarotCard_8ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Chariot";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_8ma.p3d";
    };
    class IAT_TarotCard_9ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Strength";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_9ma.p3d";
    };
    class IAT_TarotCard_10ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Hermit";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_10ma.p3d";
    };
    class IAT_TarotCard_11ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Wheel of Fortune";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_11ma.p3d";
    };
    class IAT_TarotCard_12ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Justice";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_12ma.p3d";
    };
    class IAT_TarotCard_13ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Hanged Man";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_13ma.p3d";
    };
    class IAT_TarotCard_14ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Death";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_14ma.p3d";
    };
    class IAT_TarotCard_15ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Temperance";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_15ma.p3d";
    };
    class IAT_TarotCard_16ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The  Devil";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_16ma.p3d";
    };
    class IAT_TarotCard_17ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Tower";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_17ma.p3d";
    };
    class IAT_TarotCard_18ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Star";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_18ma.p3d";
    };
    class IAT_TarotCard_19ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Moon";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_19ma.p3d";
    };
    class IAT_TarotCard_20ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The Sun";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_20ma.p3d";
    };
    class IAT_TarotCard_21ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "Judgement";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_21ma.p3d";
    };
    class IAT_TarotCard_22ma : IAT_TarotCard_Colorbase
    {
        scope = 2;
        displayName = "The World";
        model = "iat_prop_items\camping\cardstarot\iat_tarotcard_22ma.p3d";
    };

};
class CfgSlots
{
    class Slot_IAT_VanillaFlag
    {
        name = "IAT_VanillaFlag";
        displayName = "Flag";
        ghostIcon = "set:dayz_inventory image:tf_flag";
    };
    class Slot_IAT_BeltFlag
    {
        name = "IAT_BeltFlag";
        displayName = "Belt Flag";
        ghostIcon = "set:dayz_inventory image:tf_flag";
    };
    // hearts
    class Slot_IAT_Card1
    {
        name = "IAT_Card1";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card2
    {
        name = "IAT_Card2";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card3
    {
        name = "IAT_Card3";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card4
    {
        name = "IAT_Card4";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card5
    {
        name = "IAT_Card5";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card6
    {
        name = "IAT_Card6";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card7
    {
        name = "IAT_Card7";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card8
    {
        name = "IAT_Card8";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card9
    {
        name = "IAT_Card9";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card10
    {
        name = "IAT_Card10";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card11
    {
        name = "IAT_Card11";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card12
    {
        name = "IAT_Card12";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card13
    {
        name = "IAT_Card13";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    // clubs
    class Slot_IAT_Card14
    {
        name = "IAT_Card14";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card15
    {
        name = "IAT_Card15";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card16
    {
        name = "IAT_Card16";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card17
    {
        name = "IAT_Card17";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card18
    {
        name = "IAT_Card18";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card19
    {
        name = "IAT_Card19";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card20
    {
        name = "IAT_Card20";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card21
    {
        name = "IAT_Card21";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card22
    {
        name = "IAT_Card22";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card23
    {
        name = "IAT_Card23";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card24
    {
        name = "IAT_Card24";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card25
    {
        name = "IAT_Card25";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card26
    {
        name = "IAT_Card26";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    // diamonds
    class Slot_IAT_Card27
    {
        name = "IAT_Card27";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card28
    {
        name = "IAT_Card28";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card29
    {
        name = "IAT_Card29";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card30
    {
        name = "IAT_Card30";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card31
    {
        name = "IAT_Card31";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card32
    {
        name = "IAT_Card32";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card33
    {
        name = "IAT_Card33";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card34
    {
        name = "IAT_Card34";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card35
    {
        name = "IAT_Card35";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card36
    {
        name = "IAT_Card36";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card37
    {
        name = "IAT_Card37";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card38
    {
        name = "IAT_Card38";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card39
    {
        name = "IAT_Card39";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    // spades
    class Slot_IAT_Card40
    {
        name = "IAT_Card40";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card41
    {
        name = "IAT_Card41";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card42
    {
        name = "IAT_Card42";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card43
    {
        name = "IAT_Card43";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card44
    {
        name = "IAT_Card44";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card45
    {
        name = "IAT_Card45";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card46
    {
        name = "IAT_Card46";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card47
    {
        name = "IAT_Card47";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card48
    {
        name = "IAT_Card48";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card49
    {
        name = "IAT_Card49";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card50
    {
        name = "IAT_Card50";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card51
    {
        name = "IAT_Card51";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card52
    {
        name = "IAT_Card52";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    // jokers
    class Slot_IAT_Card53
    {
        name = "IAT_Card53";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_Card54
    {
        name = "IAT_Card54";
        displayName = "Playing Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };

    // tarot
    // wands
    class Slot_IAT_TCard1
    {
        name = "IAT_TCard1";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard2
    {
        name = "IAT_TCard2";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard3
    {
        name = "IAT_TCard3";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard4
    {
        name = "IAT_TCard4";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard5
    {
        name = "IAT_TCard5";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard6
    {
        name = "IAT_TCard6";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard7
    {
        name = "IAT_TCard7";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard8
    {
        name = "IAT_TCard8";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard9
    {
        name = "IAT_TCard9";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard10
    {
        name = "IAT_TCard10";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard11
    {
        name = "IAT_TCard11";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard12
    {
        name = "IAT_TCard12";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard13
    {
        name = "IAT_TCard13";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard14
    {
        name = "IAT_TCard14";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };

    // cups
    class Slot_IAT_TCard15
    {
        name = "IAT_TCard15";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard16
    {
        name = "IAT_TCard16";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard17
    {
        name = "IAT_TCard17";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard18
    {
        name = "IAT_TCard18";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard19
    {
        name = "IAT_TCard19";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard20
    {
        name = "IAT_TCard20";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard21
    {
        name = "IAT_TCard21";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard22
    {
        name = "IAT_TCard22";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard23
    {
        name = "IAT_TCard23";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard24
    {
        name = "IAT_TCard24";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard25
    {
        name = "IAT_TCard25";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard26
    {
        name = "IAT_TCard26";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard27
    {
        name = "IAT_TCard27";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard28
    {
        name = "IAT_TCard28";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };

    // swords
    class Slot_IAT_TCard29
    {
        name = "IAT_TCard29";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard30
    {
        name = "IAT_TCard30";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard31
    {
        name = "IAT_TCard31";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard32
    {
        name = "IAT_TCard32";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard33
    {
        name = "IAT_TCard33";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard34
    {
        name = "IAT_TCard34";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard35
    {
        name = "IAT_TCard35";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard36
    {
        name = "IAT_TCard36";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard37
    {
        name = "IAT_TCard37";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard38
    {
        name = "IAT_TCard38";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard39
    {
        name = "IAT_TCard39";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard40
    {
        name = "IAT_TCard40";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard41
    {
        name = "IAT_TCard41";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard42
    {
        name = "IAT_TCard42";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };

    // pentacles
    class Slot_IAT_TCard43
    {
        name = "IAT_TCard43";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard44
    {
        name = "IAT_TCard44";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard45
    {
        name = "IAT_TCard45";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard46
    {
        name = "IAT_TCard46";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard47
    {
        name = "IAT_TCard47";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard48
    {
        name = "IAT_TCard48";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard49
    {
        name = "IAT_TCard49";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard50
    {
        name = "IAT_TCard50";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard51
    {
        name = "IAT_TCard51";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard52
    {
        name = "IAT_TCard52";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard53
    {
        name = "IAT_TCard53";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard54
    {
        name = "IAT_TCard54";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard55
    {
        name = "IAT_TCard55";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard56
    {
        name = "IAT_TCard56";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };

    // major arcana
    class Slot_IAT_TCard57
    {
        name = "IAT_TCard57";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard58
    {
        name = "IAT_TCard58";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard59
    {
        name = "IAT_TCard59";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard60
    {
        name = "IAT_TCard60";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard61
    {
        name = "IAT_TCard61";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard62
    {
        name = "IAT_TCard62";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard63
    {
        name = "IAT_TCard63";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard64
    {
        name = "IAT_TCard64";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard65
    {
        name = "IAT_TCard65";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard66
    {
        name = "IAT_TCard66";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard67
    {
        name = "IAT_TCard67";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard68
    {
        name = "IAT_TCard68";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard69
    {
        name = "IAT_TCard69";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard70
    {
        name = "IAT_TCard70";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard71
    {
        name = "IAT_TCard71";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard72
    {
        name = "IAT_TCard72";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard73
    {
        name = "IAT_TCard73";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard74
    {
        name = "IAT_TCard74";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard75
    {
        name = "IAT_TCard75";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard76
    {
        name = "IAT_TCard76";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard77
    {
        name = "IAT_TCard77";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_TCard78
    {
        name = "IAT_TCard78";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };

};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyiat_vanillaflag_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_VanillaFlag" };
        model = "iat_prop_items\camping\proxy\iat_vanillaflag_proxy.p3d";
    };
    class Proxyiat_beltflag_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_BeltFlag" };
        model = "iat_prop_items\camping\proxy\iat_beltflag_proxy.p3d";
    };
};