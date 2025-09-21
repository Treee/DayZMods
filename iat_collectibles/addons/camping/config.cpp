class CfgPatches
{
    class IAT_Collectibles_Camping
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping" };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    class Container_Base;
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

    class IAT_Bear_Beige : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_brown_co.paa" }; };
    class IAT_Bear_Dark : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_dark_co.paa" }; };
    class IAT_Bear_Pink : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_pink_co.paa" }; };
    class IAT_Bear_White : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "\dz\gear\containers\Data\teddybear_white_co.paa" }; };
    class IAT_Bear_BuzzingGhosts : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_buzzingghosts_co.paa" }; };
    class IAT_Bear_MidnightCollective : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_midnightcollective_co.paa" }; };
    class IAT_Bear_Rainbow : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_rainbow_co.paa" }; };
    class IAT_Bear_TigerCamo : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_woodhouse_co.paa" }; };
    class IAT_Bear_Liam : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_liam_co.paa" }; };
    class IAT_Bear_Deadpool : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_deadpool_co.paa" }; };

    //=================================== PLAYING CARDS
    class IAT_CardDeck_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Playing Card Deck";
        descriptionShort = "A small container that holds playing cards. Will you collect them all?";
        model = "iat_collectibles\camping\iat_playingcarddeck.p3d";
        weight = 100;
        absorbency = 1;
        rotationFlags = 16;
        itemSize[] = { 1, 2 };
        itemsCargoSize[] = { 0,0 };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\iat_deckofcards_co.paa" };
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
                        {1, {"iat_collectibles\camping\data\cards\playing\iat_deckofcards.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\cards\playing\iat_deckofcards.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\cards\playing\iat_deckofcards_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\cards\playing\iat_deckofcards_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\cards\playing\iat_deckofcards_destruct.rvmat"}}
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
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\iat_deckofcards_co.paa" };
    };

    class IAT_PlayingCard_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Playing Card";
        descriptionShort = "A dirty playing card that has seen many years of use.";
        model = "iat_collectibles\camping\iat_playingcard.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { "IAT_Card1","IAT_Card2","IAT_Card3","IAT_Card4","IAT_Card5","IAT_Card6","IAT_Card7","IAT_Card8","IAT_Card9","IAT_Card10","IAT_Card11","IAT_Card12","IAT_Card13","IAT_Card14","IAT_Card15","IAT_Card16","IAT_Card17","IAT_Card18","IAT_Card19","IAT_Card20","IAT_Card21","IAT_Card22","IAT_Card23","IAT_Card24","IAT_Card25","IAT_Card26","IAT_Card27","IAT_Card28","IAT_Card29","IAT_Card30","IAT_Card31","IAT_Card32","IAT_Card33","IAT_Card34","IAT_Card35","IAT_Card36","IAT_Card37","IAT_Card38","IAT_Card39","IAT_Card40","IAT_Card41","IAT_Card42","IAT_Card43","IAT_Card44","IAT_Card45","IAT_Card46","IAT_Card47","IAT_Card48","IAT_Card49","IAT_Card50","IAT_Card51","IAT_Card52","IAT_Card53","IAT_Card54" };
        soundImpactType = "textile";
        hiddenSelections[] = { "front", "back" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_a_co.paa", "iat_collectibles\camping\data\cards\playing\card_back_1_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\cards\playing\iat_playingcard.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\cards\playing\iat_playingcard.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\cards\playing\iat_playingcard_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\cards\playing\iat_playingcard_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\cards\playing\iat_playingcard_destruct.rvmat"}}
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

    // Hearts
    class IAT_PlayingCard_A_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_a_co.paa" }; };
    class IAT_PlayingCard_2_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_2_co.paa" }; };
    class IAT_PlayingCard_3_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_3_co.paa" }; };
    class IAT_PlayingCard_4_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_4_co.paa" }; };
    class IAT_PlayingCard_5_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_5_co.paa" }; };
    class IAT_PlayingCard_6_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_6_co.paa" }; };
    class IAT_PlayingCard_7_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_7_co.paa" }; };
    class IAT_PlayingCard_8_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_8_co.paa" }; };
    class IAT_PlayingCard_9_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_9_co.paa" }; };
    class IAT_PlayingCard_10_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_10_co.paa" }; };
    class IAT_PlayingCard_J_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_j_co.paa" }; };
    class IAT_PlayingCard_Q_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_q_co.paa" }; };
    class IAT_PlayingCard_K_H : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_k_co.paa" }; };

    // Diamonds
    class IAT_PlayingCard_A_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_a_co.paa" }; };
    class IAT_PlayingCard_2_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_2_co.paa" }; };
    class IAT_PlayingCard_3_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_3_co.paa" }; };
    class IAT_PlayingCard_4_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_4_co.paa" }; };
    class IAT_PlayingCard_5_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_5_co.paa" }; };
    class IAT_PlayingCard_6_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_6_co.paa" }; };
    class IAT_PlayingCard_7_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_7_co.paa" }; };
    class IAT_PlayingCard_8_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_8_co.paa" }; };
    class IAT_PlayingCard_9_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_9_co.paa" }; };
    class IAT_PlayingCard_10_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_10_co.paa" }; };
    class IAT_PlayingCard_J_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_j_co.paa" }; };
    class IAT_PlayingCard_Q_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_q_co.paa" }; };
    class IAT_PlayingCard_K_D : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_k_co.paa" }; };

    // Spades
    class IAT_PlayingCard_A_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_a_co.paa" }; };
    class IAT_PlayingCard_2_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_2_co.paa" }; };
    class IAT_PlayingCard_3_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_3_co.paa" }; };
    class IAT_PlayingCard_4_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_4_co.paa" }; };
    class IAT_PlayingCard_5_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_5_co.paa" }; };
    class IAT_PlayingCard_6_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_6_co.paa" }; };
    class IAT_PlayingCard_7_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_7_co.paa" }; };
    class IAT_PlayingCard_8_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_8_co.paa" }; };
    class IAT_PlayingCard_9_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_9_co.paa" }; };
    class IAT_PlayingCard_10_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_10_co.paa" }; };
    class IAT_PlayingCard_J_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_j_co.paa" }; };
    class IAT_PlayingCard_Q_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_q_co.paa" }; };
    class IAT_PlayingCard_K_S : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_k_co.paa" }; };

    // Clubs
    class IAT_PlayingCard_A_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_a_co.paa" }; };
    class IAT_PlayingCard_2_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_2_co.paa" }; };
    class IAT_PlayingCard_3_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_3_co.paa" }; };
    class IAT_PlayingCard_4_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_4_co.paa" }; };
    class IAT_PlayingCard_5_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_5_co.paa" }; };
    class IAT_PlayingCard_6_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_6_co.paa" }; };
    class IAT_PlayingCard_7_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_7_co.paa" }; };
    class IAT_PlayingCard_8_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_8_co.paa" }; };
    class IAT_PlayingCard_9_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_9_co.paa" }; };
    class IAT_PlayingCard_10_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_10_co.paa" }; };
    class IAT_PlayingCard_J_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_j_co.paa" }; };
    class IAT_PlayingCard_Q_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_q_co.paa" }; };
    class IAT_PlayingCard_K_C : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_k_co.paa" }; };

    // Jokers
    class IAT_PlayingCard_Joker_1 : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\joker_1_co.paa" }; };
    class IAT_PlayingCard_Joker_2 : IAT_PlayingCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\joker_2_co.paa" }; };

    //=================================== TAROT CARDS
    class IAT_TarotCardDeck_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Tarot Card Deck";
        descriptionShort = "A small container that holds tarot cards. Will you collect them all?";
        model = "iat_collectibles\camping\iat_tarotcarddeck.p3d";
        weight = 100;
        absorbency = 1;
        rotationFlags = 16;
        itemSize[] = { 1, 2 };
        itemsCargoSize[] = { 0,0 };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_co.paa" };
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
                        {1, {"iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_destruct.rvmat"}}
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
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_co.paa" };

    };
    class IAT_TarotCardDeck_essesentiendum : IAT_TarotCardDeck_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_essesentiendum_co.paa" };
    };

    class IAT_TarotCard_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Tarot Card";
        descriptionShort = "A dirty tarot card that has seen many years of use.";
        model = "iat_collectibles\camping\iat_tarotcard.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { "IAT_OccultCard1", "IAT_OccultCard2", "IAT_OccultCard3", "IAT_OccultCard4", "IAT_OccultCard5", "IAT_OccultCard6", "IAT_OccultCard7", "IAT_OccultCard8","IAT_TCard1","IAT_TCard2","IAT_TCard3","IAT_TCard4","IAT_TCard5","IAT_TCard6","IAT_TCard7","IAT_TCard8","IAT_TCard9","IAT_TCard10","IAT_TCard11","IAT_TCard12","IAT_TCard13","IAT_TCard14","IAT_TCard15","IAT_TCard16","IAT_TCard17","IAT_TCard18","IAT_TCard19","IAT_TCard20","IAT_TCard21","IAT_TCard22","IAT_TCard23","IAT_TCard24","IAT_TCard25","IAT_TCard26","IAT_TCard27","IAT_TCard28","IAT_TCard29","IAT_TCard30","IAT_TCard31","IAT_TCard32","IAT_TCard33","IAT_TCard34","IAT_TCard35","IAT_TCard36","IAT_TCard37","IAT_TCard38","IAT_TCard39","IAT_TCard40","IAT_TCard41","IAT_TCard42","IAT_TCard43","IAT_TCard44","IAT_TCard45","IAT_TCard46","IAT_TCard47","IAT_TCard48","IAT_TCard49","IAT_TCard50","IAT_TCard51","IAT_TCard52","IAT_TCard53","IAT_TCard54","IAT_TCard55","IAT_TCard56","IAT_TCard57","IAT_TCard58","IAT_TCard59","IAT_TCard60","IAT_TCard61","IAT_TCard62","IAT_TCard63","IAT_TCard64","IAT_TCard65","IAT_TCard66","IAT_TCard67","IAT_TCard68","IAT_TCard69","IAT_TCard70","IAT_TCard71","IAT_TCard72","IAT_TCard73","IAT_TCard74","IAT_TCard75","IAT_TCard76","IAT_TCard77","IAT_TCard78" };
        soundImpactType = "textile";
        hiddenSelections[] = { "front", "back" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_01_co.paa", "iat_collectibles\camping\data\cards\tarot\card_back_1_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\cards\tarot\iat_tarotcard.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\cards\tarot\iat_tarotcard.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\cards\tarot\iat_tarotcard_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\cards\tarot\iat_tarotcard_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\cards\tarot\iat_tarotcard_destruct.rvmat"}}
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

    // Tarot Cards - Cups (C)
    class IAT_TarotCard_C_1 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_01_co.paa" }; };
    class IAT_TarotCard_C_2 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_02_co.paa" }; };
    class IAT_TarotCard_C_3 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_03_co.paa" }; };
    class IAT_TarotCard_C_4 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_04_co.paa" }; };
    class IAT_TarotCard_C_5 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_05_co.paa" }; };
    class IAT_TarotCard_C_6 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_06_co.paa" }; };
    class IAT_TarotCard_C_7 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_07_co.paa" }; };
    class IAT_TarotCard_C_8 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_08_co.paa" }; };
    class IAT_TarotCard_C_9 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_09_co.paa" }; };
    class IAT_TarotCard_C_10 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_10_co.paa" }; };
    class IAT_TarotCard_C_11 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_11_co.paa" }; };
    class IAT_TarotCard_C_12 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_12_co.paa" }; };
    class IAT_TarotCard_C_13 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_13_co.paa" }; };
    class IAT_TarotCard_C_14 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_14_co.paa" }; };

    // Tarot Cards - Wands (W)
    class IAT_TarotCard_W_1 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_01_co.paa" }; };
    class IAT_TarotCard_W_2 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_02_co.paa" }; };
    class IAT_TarotCard_W_3 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_03_co.paa" }; };
    class IAT_TarotCard_W_4 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_04_co.paa" }; };
    class IAT_TarotCard_W_5 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_05_co.paa" }; };
    class IAT_TarotCard_W_6 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_06_co.paa" }; };
    class IAT_TarotCard_W_7 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_07_co.paa" }; };
    class IAT_TarotCard_W_8 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_08_co.paa" }; };
    class IAT_TarotCard_W_9 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_09_co.paa" }; };
    class IAT_TarotCard_W_10 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_10_co.paa" }; };
    class IAT_TarotCard_W_11 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_11_co.paa" }; };
    class IAT_TarotCard_W_12 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_12_co.paa" }; };
    class IAT_TarotCard_W_13 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_13_co.paa" }; };
    class IAT_TarotCard_W_14 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_14_co.paa" }; };

    // Tarot Cards - Pentacles (P)
    class IAT_TarotCard_P_1 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_01_co.paa" }; };
    class IAT_TarotCard_P_2 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_02_co.paa" }; };
    class IAT_TarotCard_P_3 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_03_co.paa" }; };
    class IAT_TarotCard_P_4 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_04_co.paa" }; };
    class IAT_TarotCard_P_5 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_05_co.paa" }; };
    class IAT_TarotCard_P_6 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_06_co.paa" }; };
    class IAT_TarotCard_P_7 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_07_co.paa" }; };
    class IAT_TarotCard_P_8 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_08_co.paa" }; };
    class IAT_TarotCard_P_9 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_09_co.paa" }; };
    class IAT_TarotCard_P_10 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_10_co.paa" }; };
    class IAT_TarotCard_P_11 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_11_co.paa" }; };
    class IAT_TarotCard_P_12 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_12_co.paa" }; };
    class IAT_TarotCard_P_13 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_13_co.paa" }; };
    class IAT_TarotCard_P_14 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_14_co.paa" }; };

    // Tarot Cards - Swords (S)
    class IAT_TarotCard_S_1 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_01_co.paa" }; };
    class IAT_TarotCard_S_2 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_02_co.paa" }; };
    class IAT_TarotCard_S_3 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_03_co.paa" }; };
    class IAT_TarotCard_S_4 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_04_co.paa" }; };
    class IAT_TarotCard_S_5 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_05_co.paa" }; };
    class IAT_TarotCard_S_6 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_06_co.paa" }; };
    class IAT_TarotCard_S_7 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_07_co.paa" }; };
    class IAT_TarotCard_S_8 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_08_co.paa" }; };
    class IAT_TarotCard_S_9 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_09_co.paa" }; };
    class IAT_TarotCard_S_10 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_10_co.paa" }; };
    class IAT_TarotCard_S_11 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_11_co.paa" }; };
    class IAT_TarotCard_S_12 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_12_co.paa" }; };
    class IAT_TarotCard_S_13 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_13_co.paa" }; };
    class IAT_TarotCard_S_14 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_14_co.paa" }; };

    // Tarot Cards - Major Arcana (MA)
    class IAT_TarotCard_MA_1 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_01_co.paa" }; };
    class IAT_TarotCard_MA_2 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_02_co.paa" }; };
    class IAT_TarotCard_MA_3 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_03_co.paa" }; };
    class IAT_TarotCard_MA_4 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_04_co.paa" }; };
    class IAT_TarotCard_MA_5 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_05_co.paa" }; };
    class IAT_TarotCard_MA_6 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_06_co.paa" }; };
    class IAT_TarotCard_MA_7 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_07_co.paa" }; };
    class IAT_TarotCard_MA_8 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_08_co.paa" }; };
    class IAT_TarotCard_MA_9 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_09_co.paa" }; };
    class IAT_TarotCard_MA_10 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_10_co.paa" }; };
    class IAT_TarotCard_MA_11 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_11_co.paa" }; };
    class IAT_TarotCard_MA_12 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_12_co.paa" }; };
    class IAT_TarotCard_MA_13 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_13_co.paa" }; };
    class IAT_TarotCard_MA_14 : IAT_TarotCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_14_co.paa" }; };

    //=================================== Collectible CARDS
    class IAT_CollectibleDeck_Colorbase : Container_Base
    {
        scope = 0;
        displayName = "Collectible Card Deck";
        descriptionShort = "A small container that holds collectible cards. Will you collect them all?";
        model = "iat_collectibles\camping\iat_collectiblecarddeck.p3d";
        weight = 100;
        absorbency = 1;
        rotationFlags = 16;
        itemSize[] = { 2, 2 };
        itemsCargoSize[] = { 10,15 };
        allowOwnedCargoManipulation = 1;
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck_co.paa" };
        attachments[] = { };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 200;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck_destruct.rvmat"}}
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
    class IAT_CollectibleDeck_Basic : IAT_CollectibleDeck_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck_co.paa" };
    };

    class IAT_CollectibleCard_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Collectible Card";
        descriptionShort = "A dirty playing card that has seen many years of use.";
        model = "iat_collectibles\camping\iat_collectiblecard.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "front", "back" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_1_co.paa", "iat_collectibles\camping\data\cards\srp_bitterroot\card_back_3_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_brcard.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_brcard.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_brcard_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_brcard_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\cards\srp_bitterroot\iat_brcard_destruct.rvmat"}}
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

    // SRP BITTERROOT
    class IAT_CollectibleCard_SRP_BR_1 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_1_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_2 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_2_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_3 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_3_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_4 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_4_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_5 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_5_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_6 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_6_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_7 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_7_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_8 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_8_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_9 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_9_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_10 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_10_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_11 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_11_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_12 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_12_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_13 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_13_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_14 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_14_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_15 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_15_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_16 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_16_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_17 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_17_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_18 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_18_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_19 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_19_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_20 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_20_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_21 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_21_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_22 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_22_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_23 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_23_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_24 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_24_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_25 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_25_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_26 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_26_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_27 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_27_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_28 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_28_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_29 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_29_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_30 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_30_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_31 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_31_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_32 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_32_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_33 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_33_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_34 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_34_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_35 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_35_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_36 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_36_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_37 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_37_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_38 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_38_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_39 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_39_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_40 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_40_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_41 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_41_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_42 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_42_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_43 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_43_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_44 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_44_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_45 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_45_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_46 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_46_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_47 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_47_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_48 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_48_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_49 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_49_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_50 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_50_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_51 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_51_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_52 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_52_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_53 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_53_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_54 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_54_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_55 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_55_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_56 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_56_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_57 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_57_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_58 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_58_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_59 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_59_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_60 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_60_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_61 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_61_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_62 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_62_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_63 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_63_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_64 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_64_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_65 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_65_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_66 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_66_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_67 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_67_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_68 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_68_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_69 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_69_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_70 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_70_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_71 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_71_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_72 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_72_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_73 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_73_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_74 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_74_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_75 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_75_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_76 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_76_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_77 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_77_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_78 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_78_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_79 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_79_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_80 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_80_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_81 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_81_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_82 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_82_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_83 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_83_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_84 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_84_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_85 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_85_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_86 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_86_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_87 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_87_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_88 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_88_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_89 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_89_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_90 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_90_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_91 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_91_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_92 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_92_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_93 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_93_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_94 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_94_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_95 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_95_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_96 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_96_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_97 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_97_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_98 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_98_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_99 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_99_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_100 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_100_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_101 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_101_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_102 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_102_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_103 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_103_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_104 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_104_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_105 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_105_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_106 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_106_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_107 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_107_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_108 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_108_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_109 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_109_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_110 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_110_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_111 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_111_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_112 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_112_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_113 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_113_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_114 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_114_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_115 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_115_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_116 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_116_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_117 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_117_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_118 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_118_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_119 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_119_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_120 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_120_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_121 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_121_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_122 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_122_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_123 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_123_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_124 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_124_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_125 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_125_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_126 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_126_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_127 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_127_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_128 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_128_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_129 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_129_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_130 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_130_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_131 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_131_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_132 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_132_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_133 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_133_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_134 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_134_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_135 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_135_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_136 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_136_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_137 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_137_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_138 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_138_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_139 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_139_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_140 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_140_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_141 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_141_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_142 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_142_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_143 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_143_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_144 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_144_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_145 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_145_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_146 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_146_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_147 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_147_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_148 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_148_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_149 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_149_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_150 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_150_co.paa" }; };

    // SRP PLAYERS
    class IAT_CollectibleCard_SRP_PL_1 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_1_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_2 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_2_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_3 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_3_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_4 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_4_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_5 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_5_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_6 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_6_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_7 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_7_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_8 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_8_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_9 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_9_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_10 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_10_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_11 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_11_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_12 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_12_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_13 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_13_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_14 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_14_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_15 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_15_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_16 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_16_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_17 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_17_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_18 : IAT_CollectibleCard_Colorbase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_18_co.paa" }; };
};
class CfgSlots
{
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