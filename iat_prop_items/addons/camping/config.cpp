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
    class IAT_CardDeck_Tarot : IAT_CardDeck_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\camping\data\iat_deckoftarotcards_co.paa" };
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
};