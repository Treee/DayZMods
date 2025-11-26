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
    class IAT_Bear_BlueBeary : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_bluebeary_co.paa" }; };
    class IAT_Bear_LegionSanctuary : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_legionsanctuary_co.paa" }; };
    class IAT_Bear_MinervaLegion : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_minervalegion_co.paa" }; };
    class IAT_Bear_Survivalists : IAT_Bear_ColorBase { scope = 2; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\teddies\teddybear_survivalists_co.paa" }; };

    //=================================== GUN FRAMES
    class IAT_GunFrame_Rifle_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Gun Frame - Rifle";
        descriptionShort = "A frame that holds a rifle.";
        model = "iat_collectibles\camping\iat_gunframe_rifle.p3d";
        weight = 130;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 3, 2 };
        itemsCargoSize[] = { 0,0 };
        attachments[] = { "IAT_GunWall_Rifle1" };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek", "frame" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_gunwall_co.paa", "DZ\gear\consumables\data\pile_of_planks_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_destruct.rvmat"}}
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
    class IAT_GunFrame_Pistol_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Gun Frame - Pistol";
        descriptionShort = "A frame that holds three pistols.";
        model = "iat_collectibles\camping\iat_gunframe_pistol.p3d";
        weight = 130;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 2, 3 };
        itemsCargoSize[] = { 0,0 };
        attachments[] = { "IAT_GunWall_Pistol1", "IAT_GunWall_Pistol2", "IAT_GunWall_Pistol3" };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek", "frame" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_gunwall_co.paa", "DZ\gear\consumables\data\pile_of_planks_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_destruct.rvmat"}}
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

    class IAT_GunFrame_Rifle_Basic : IAT_GunFrame_Rifle_ColorBase { scope = 2; };
    class IAT_GunFrame_Pistol_Basic : IAT_GunFrame_Pistol_ColorBase { scope = 2; };

    //=================================== PICTURE FRAMES
    class IAT_PictureFrame_Landscape_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Picture Frame - Landscape";
        descriptionShort = "A picture frame for an image in landscape dimensions.";
        model = "iat_collectibles\camping\iat_pictureframe_landscape.p3d";
        weight = 130;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 3, 2 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek", "frame" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_saltwood_co.paa", "DZ\gear\consumables\data\pile_of_planks_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_destruct.rvmat"}}
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
    class IAT_PictureFrame_Portrait_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Picture Frame - Portrait";
        descriptionShort = "A picture frame for an image in portrait dimensions.";
        model = "iat_collectibles\camping\iat_pictureframe_portrait.p3d";
        weight = 130;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 2, 3 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek", "frame" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_alientsattack_co.paa", "DZ\gear\consumables\data\pile_of_planks_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_destruct.rvmat"}}
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
    class IAT_PictureFrame_Square_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Picture Frame - Square";
        descriptionShort = "A picture frame for an image in square dimensions.";
        model = "iat_collectibles\camping\iat_pictureframe_square.p3d";
        weight = 130;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 2, 2 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek", "frame" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframesquare_sunsetnearrome_co.paa", "DZ\gear\consumables\data\pile_of_planks_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\pictureframe\iat_pictureframesquare.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\pictureframe\iat_pictureframesquare.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\pictureframe\iat_pictureframesquare_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\pictureframe\iat_pictureframesquare_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\pictureframe\iat_pictureframesquare_destruct.rvmat"}}
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

    //=================================== LANDSCAPE
    class IAT_PictureFrame_Landscape_SaltWoodCastle : IAT_PictureFrame_Landscape_ColorBase { scope = 2; displayName = "Saltwood Castle"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframelandscape_saltwood_co.paa" }; };

    //=================================== PORTRAIT
    class IAT_PictureFrame_Portrait_AliensAttack : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "When Aliens Attack"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_alientsattack_co.paa" }; };
    class IAT_PictureFrame_Portrait_BGroup : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "The B Group"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_bgroup_co.paa" }; };
    class IAT_PictureFrame_Portrait_BitterRose : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "BitterRose"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_bitterrose_co.paa" }; };
    class IAT_PictureFrame_Portrait_MilitaryMen : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "Military Men"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_militarymen_co.paa" }; };
    class IAT_PictureFrame_Portrait_SettlerWarning : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "Settler Warning"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_settlerwarning_co.paa" }; };
    class IAT_PictureFrame_Portrait_TheCenturion : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "The Centurion"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_thecenturion_co.paa" }; };
    class IAT_PictureFrame_Portrait_UniverseFighters : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "Universe Fighters"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_universefighters_co.paa" }; };
    class IAT_PictureFrame_Portrait_Unsinkable : IAT_PictureFrame_Portrait_ColorBase { scope = 2; displayName = "Unsinkable"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframeportrait_unsinkable_co.paa" }; };

    //=================================== SQUARE
    class IAT_PictureFrame_Square_RomeSunset : IAT_PictureFrame_Square_ColorBase { scope = 2; displayName = "Sunset Near Rome"; hiddenSelections[] = { "zbytek" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\pictureframe\iat_pictureframesquare_sunsetnearrome_co.paa" }; };

    //=================================== PLAYING CARDS
    class IAT_CardDeck_ColorBase : Inventory_Base
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
    class IAT_CardDeck_Basic : IAT_CardDeck_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\iat_deckofcards_co.paa" };
    };

    class IAT_PlayingCard_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Playing Card";
        descriptionShort = "A dirty playing card that has seen many years of use.";
        model = "iat_collectibles\camping\iat_playingcard.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemBehaviour = 1;
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
    class IAT_PlayingCard_A_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_a_co.paa" }; };
    class IAT_PlayingCard_2_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_2_co.paa" }; };
    class IAT_PlayingCard_3_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_3_co.paa" }; };
    class IAT_PlayingCard_4_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_4_co.paa" }; };
    class IAT_PlayingCard_5_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_5_co.paa" }; };
    class IAT_PlayingCard_6_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_6_co.paa" }; };
    class IAT_PlayingCard_7_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_7_co.paa" }; };
    class IAT_PlayingCard_8_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_8_co.paa" }; };
    class IAT_PlayingCard_9_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_9_co.paa" }; };
    class IAT_PlayingCard_10_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_10_co.paa" }; };
    class IAT_PlayingCard_J_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_j_co.paa" }; };
    class IAT_PlayingCard_Q_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_q_co.paa" }; };
    class IAT_PlayingCard_K_H : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\hearts_k_co.paa" }; };

    // Diamonds
    class IAT_PlayingCard_A_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_a_co.paa" }; };
    class IAT_PlayingCard_2_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_2_co.paa" }; };
    class IAT_PlayingCard_3_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_3_co.paa" }; };
    class IAT_PlayingCard_4_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_4_co.paa" }; };
    class IAT_PlayingCard_5_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_5_co.paa" }; };
    class IAT_PlayingCard_6_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_6_co.paa" }; };
    class IAT_PlayingCard_7_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_7_co.paa" }; };
    class IAT_PlayingCard_8_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_8_co.paa" }; };
    class IAT_PlayingCard_9_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_9_co.paa" }; };
    class IAT_PlayingCard_10_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_10_co.paa" }; };
    class IAT_PlayingCard_J_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_j_co.paa" }; };
    class IAT_PlayingCard_Q_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_q_co.paa" }; };
    class IAT_PlayingCard_K_D : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\diamonds_k_co.paa" }; };

    // Spades
    class IAT_PlayingCard_A_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_a_co.paa" }; };
    class IAT_PlayingCard_2_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_2_co.paa" }; };
    class IAT_PlayingCard_3_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_3_co.paa" }; };
    class IAT_PlayingCard_4_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_4_co.paa" }; };
    class IAT_PlayingCard_5_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_5_co.paa" }; };
    class IAT_PlayingCard_6_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_6_co.paa" }; };
    class IAT_PlayingCard_7_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_7_co.paa" }; };
    class IAT_PlayingCard_8_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_8_co.paa" }; };
    class IAT_PlayingCard_9_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_9_co.paa" }; };
    class IAT_PlayingCard_10_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_10_co.paa" }; };
    class IAT_PlayingCard_J_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_j_co.paa" }; };
    class IAT_PlayingCard_Q_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_q_co.paa" }; };
    class IAT_PlayingCard_K_S : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\spades_k_co.paa" }; };

    // Clubs
    class IAT_PlayingCard_A_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_a_co.paa" }; };
    class IAT_PlayingCard_2_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_2_co.paa" }; };
    class IAT_PlayingCard_3_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_3_co.paa" }; };
    class IAT_PlayingCard_4_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_4_co.paa" }; };
    class IAT_PlayingCard_5_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_5_co.paa" }; };
    class IAT_PlayingCard_6_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_6_co.paa" }; };
    class IAT_PlayingCard_7_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_7_co.paa" }; };
    class IAT_PlayingCard_8_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_8_co.paa" }; };
    class IAT_PlayingCard_9_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_9_co.paa" }; };
    class IAT_PlayingCard_10_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_10_co.paa" }; };
    class IAT_PlayingCard_J_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_j_co.paa" }; };
    class IAT_PlayingCard_Q_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_q_co.paa" }; };
    class IAT_PlayingCard_K_C : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\clubs_k_co.paa" }; };

    // Jokers
    class IAT_PlayingCard_Joker_1 : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\joker_1_co.paa" }; };
    class IAT_PlayingCard_Joker_2 : IAT_PlayingCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\playing\joker_2_co.paa" }; };

    //=================================== TAROT CARDS
    class IAT_TarotCardDeck_ColorBase : Inventory_Base
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
    class IAT_TarotCardDeck_Basic : IAT_TarotCardDeck_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_co.paa" };

    };
    class IAT_TarotCardDeck_essesentiendum : IAT_TarotCardDeck_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_deckoftarotcards_essesentiendum_co.paa" };
    };

    class IAT_TarotCard_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Tarot Card";
        descriptionShort = "A dirty tarot card that has seen many years of use.";
        model = "iat_collectibles\camping\iat_tarotcard.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemBehaviour = 1;
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
    class IAT_TarotCard_C_1 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_01_co.paa" }; };
    class IAT_TarotCard_C_2 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_02_co.paa" }; };
    class IAT_TarotCard_C_3 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_03_co.paa" }; };
    class IAT_TarotCard_C_4 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_04_co.paa" }; };
    class IAT_TarotCard_C_5 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_05_co.paa" }; };
    class IAT_TarotCard_C_6 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_06_co.paa" }; };
    class IAT_TarotCard_C_7 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_07_co.paa" }; };
    class IAT_TarotCard_C_8 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_08_co.paa" }; };
    class IAT_TarotCard_C_9 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_09_co.paa" }; };
    class IAT_TarotCard_C_10 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_10_co.paa" }; };
    class IAT_TarotCard_C_11 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_11_co.paa" }; };
    class IAT_TarotCard_C_12 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_12_co.paa" }; };
    class IAT_TarotCard_C_13 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_13_co.paa" }; };
    class IAT_TarotCard_C_14 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_c_14_co.paa" }; };

    // Tarot Cards - Wands (W)
    class IAT_TarotCard_W_1 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_01_co.paa" }; };
    class IAT_TarotCard_W_2 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_02_co.paa" }; };
    class IAT_TarotCard_W_3 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_03_co.paa" }; };
    class IAT_TarotCard_W_4 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_04_co.paa" }; };
    class IAT_TarotCard_W_5 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_05_co.paa" }; };
    class IAT_TarotCard_W_6 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_06_co.paa" }; };
    class IAT_TarotCard_W_7 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_07_co.paa" }; };
    class IAT_TarotCard_W_8 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_08_co.paa" }; };
    class IAT_TarotCard_W_9 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_09_co.paa" }; };
    class IAT_TarotCard_W_10 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_10_co.paa" }; };
    class IAT_TarotCard_W_11 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_11_co.paa" }; };
    class IAT_TarotCard_W_12 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_12_co.paa" }; };
    class IAT_TarotCard_W_13 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_13_co.paa" }; };
    class IAT_TarotCard_W_14 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_w_14_co.paa" }; };

    // Tarot Cards - Pentacles (P)
    class IAT_TarotCard_P_1 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_01_co.paa" }; };
    class IAT_TarotCard_P_2 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_02_co.paa" }; };
    class IAT_TarotCard_P_3 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_03_co.paa" }; };
    class IAT_TarotCard_P_4 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_04_co.paa" }; };
    class IAT_TarotCard_P_5 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_05_co.paa" }; };
    class IAT_TarotCard_P_6 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_06_co.paa" }; };
    class IAT_TarotCard_P_7 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_07_co.paa" }; };
    class IAT_TarotCard_P_8 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_08_co.paa" }; };
    class IAT_TarotCard_P_9 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_09_co.paa" }; };
    class IAT_TarotCard_P_10 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_10_co.paa" }; };
    class IAT_TarotCard_P_11 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_11_co.paa" }; };
    class IAT_TarotCard_P_12 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_12_co.paa" }; };
    class IAT_TarotCard_P_13 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_13_co.paa" }; };
    class IAT_TarotCard_P_14 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_p_14_co.paa" }; };

    // Tarot Cards - Swords (S)
    class IAT_TarotCard_S_1 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_01_co.paa" }; };
    class IAT_TarotCard_S_2 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_02_co.paa" }; };
    class IAT_TarotCard_S_3 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_03_co.paa" }; };
    class IAT_TarotCard_S_4 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_04_co.paa" }; };
    class IAT_TarotCard_S_5 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_05_co.paa" }; };
    class IAT_TarotCard_S_6 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_06_co.paa" }; };
    class IAT_TarotCard_S_7 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_07_co.paa" }; };
    class IAT_TarotCard_S_8 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_08_co.paa" }; };
    class IAT_TarotCard_S_9 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_09_co.paa" }; };
    class IAT_TarotCard_S_10 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_10_co.paa" }; };
    class IAT_TarotCard_S_11 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_11_co.paa" }; };
    class IAT_TarotCard_S_12 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_12_co.paa" }; };
    class IAT_TarotCard_S_13 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_13_co.paa" }; };
    class IAT_TarotCard_S_14 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_s_14_co.paa" }; };

    // Tarot Cards - Major Arcana (MA)
    class IAT_TarotCard_MA_1 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_01_co.paa" }; };
    class IAT_TarotCard_MA_2 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_02_co.paa" }; };
    class IAT_TarotCard_MA_3 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_03_co.paa" }; };
    class IAT_TarotCard_MA_4 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_04_co.paa" }; };
    class IAT_TarotCard_MA_5 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_05_co.paa" }; };
    class IAT_TarotCard_MA_6 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_06_co.paa" }; };
    class IAT_TarotCard_MA_7 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_07_co.paa" }; };
    class IAT_TarotCard_MA_8 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_08_co.paa" }; };
    class IAT_TarotCard_MA_9 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_09_co.paa" }; };
    class IAT_TarotCard_MA_10 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_10_co.paa" }; };
    class IAT_TarotCard_MA_11 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_11_co.paa" }; };
    class IAT_TarotCard_MA_12 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_12_co.paa" }; };
    class IAT_TarotCard_MA_13 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_13_co.paa" }; };
    class IAT_TarotCard_MA_14 : IAT_TarotCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\tarot\iat_tarotcard_ma_14_co.paa" }; };

    //=================================== Collectible CARDS
    class IAT_CollectibleDeck_ColorBase : Container_Base
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
    class IAT_CollectibleDeck_Basic : IAT_CollectibleDeck_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\iat_collectibledeck_co.paa" };
    };

    class IAT_CollectibleCard_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Collectible Card";
        descriptionShort = "A dirty playing card that has seen many years of use.";
        model = "iat_collectibles\camping\iat_collectiblecard.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 1;
        itemBehaviour = 1;
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
    class IAT_CollectibleCard_SRP_BR_1 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_1_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_2 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_2_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_3 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_3_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_4 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_4_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_5 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_5_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_6 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_6_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_7 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_7_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_8 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_8_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_9 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_9_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_10 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_10_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_11 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_11_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_12 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_12_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_13 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_13_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_14 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_14_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_15 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_15_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_16 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_16_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_17 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_17_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_18 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_18_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_19 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_19_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_20 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_20_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_21 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_21_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_22 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_22_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_23 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_23_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_24 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_24_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_25 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_25_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_26 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_26_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_27 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_27_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_28 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_28_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_29 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_29_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_30 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_30_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_31 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_31_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_32 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_32_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_33 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_33_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_34 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_34_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_35 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_35_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_36 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_36_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_37 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_37_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_38 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_38_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_39 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_39_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_40 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_40_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_41 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_41_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_42 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_42_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_43 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_43_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_44 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_44_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_45 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_45_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_46 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_46_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_47 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_47_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_48 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_48_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_49 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_49_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_50 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_50_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_51 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_51_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_52 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_52_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_53 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_53_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_54 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_54_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_55 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_55_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_56 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_56_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_57 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_57_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_58 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_58_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_59 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_59_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_60 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_60_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_61 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_61_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_62 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_62_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_63 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_63_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_64 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_64_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_65 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_65_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_66 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_66_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_67 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_67_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_68 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_68_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_69 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_69_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_70 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_70_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_71 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_71_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_72 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_72_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_73 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_73_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_74 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_74_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_75 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_75_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_76 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_76_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_77 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_77_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_78 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_78_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_79 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_79_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_80 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_80_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_81 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_81_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_82 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_82_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_83 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_83_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_84 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_84_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_85 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_85_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_86 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_86_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_87 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_87_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_88 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_88_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_89 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_89_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_90 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_90_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_91 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_91_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_92 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_92_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_93 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_93_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_94 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_94_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_95 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_95_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_96 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_96_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_97 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_97_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_98 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_98_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_99 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_99_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_100 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_100_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_101 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_101_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_102 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_102_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_103 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_103_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_104 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_104_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_105 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_105_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_106 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_106_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_107 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_107_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_108 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_108_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_109 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_109_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_110 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_110_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_111 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_111_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_112 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_112_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_113 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_113_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_114 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_114_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_115 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_115_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_116 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_116_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_117 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_117_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_118 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_118_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_119 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_119_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_120 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_120_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_121 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_121_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_122 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_122_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_123 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_123_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_124 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_124_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_125 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_125_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_126 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_126_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_127 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_127_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_128 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_128_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_129 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_129_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_130 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_130_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_131 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_131_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_132 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_132_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_133 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_133_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_134 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_134_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_135 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_135_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_136 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_136_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_137 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_137_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_138 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_138_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_139 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_139_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_140 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_140_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_141 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_141_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_142 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_142_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_143 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_143_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_144 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_144_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_145 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_145_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_146 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_146_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_147 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_147_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_148 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_148_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_149 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_149_co.paa" }; };
    class IAT_CollectibleCard_SRP_BR_150 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_bitterroot\srp_br_150_co.paa" }; };

    // SRP PLAYERS
    class IAT_CollectibleCard_SRP_PL_1 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_1_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_2 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_2_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_3 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_3_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_4 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_4_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_5 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_5_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_6 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_6_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_7 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_7_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_8 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_8_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_9 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_9_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_10 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_10_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_11 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_11_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_12 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_12_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_13 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_13_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_14 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_14_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_15 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_15_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_16 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_16_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_17 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_17_co.paa" }; };
    class IAT_CollectibleCard_SRP_PL_18 : IAT_CollectibleCard_ColorBase { scope = 2; hiddenSelections[] = { "front" }; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\cards\srp_players\srp_pl_18_co.paa" }; };

    //=================================== BOOSTER PACKS
    class IAT_BoosterPack_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Booster Pack";
        descriptionShort = "A booster pack of cards. Roll the dice!";
        model = "\dz\gear\cultivation\tomato_seeds_pack.p3d";
        rotationFlags = 17;
        quantityBar = 1;
        itemSize[] = { 2, 2 };
        weight = 30;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\boosterpacks\iat_boosterpack_collectibles_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5;
                    healthLevels[] = { {1, {"iat_collectibles\camping\data\boosterpacks\iat_boosterpack.rvmat"}}, {0.7, {"iat_collectibles\camping\data\boosterpacks\iat_boosterpack.rvmat"}}, {0.5, {"iat_collectibles\camping\data\boosterpacks\iat_boosterpack_damage.rvmat"}}, {0.3, {"iat_collectibles\camping\data\boosterpacks\iat_boosterpack_damage.rvmat"}}, {0, {"iat_collectibles\camping\data\boosterpacks\iat_boosterpack_destruct.rvmat"}} };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickup
                {
                    soundSet = "seedpack_pickup_SoundSet";
                    id = 797;
                };
            };
        };
    };
    class IAT_BoosterPack_Collectibles_SRP_BR : IAT_BoosterPack_ColorBase
    {
        scope = 2;
        color = "collectibles";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\boosterpacks\iat_boosterpack_collectibles_co.paa" };
    };
    class IAT_BoosterPack_PlayingCards : IAT_BoosterPack_ColorBase
    {
        scope = 2;
        color = "playingcards";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\boosterpacks\iat_boosterpack_playingcards_co.paa" };
    };
    class IAT_BoosterPack_TarotCards : IAT_BoosterPack_ColorBase
    {
        scope = 2;
        color = "tarotcards";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\boosterpacks\iat_boosterpack_tarot_co.paa" };
    };

    class IAT_BoosterPack_VinylCover : IAT_BoosterPack_ColorBase
    {
        scope = 2;
        model = "iat_collectibles\camping\iat_vinylcover.p3d";
        displayName = "Vinyl Covers";
        color = "vinylcover";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinylcardboard_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5;
                    healthLevels[] = { {1, {"iat_collectibles\camping\data\vinyls\iat_vinylcover.rvmat"}}, {0.7, {"iat_collectibles\camping\data\vinyls\iat_vinylcover.rvmat"}}, {0.5, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_damage.rvmat"}}, {0.3, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_damage.rvmat"}}, {0, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_destruct.rvmat"}} };
                };
            };
        };
    };
    class IAT_BoosterPack_VinylRecordArt : IAT_BoosterPack_ColorBase
    {
        scope = 2;
        model = "iat_collectibles\camping\iat_vinylcover.p3d";
        displayName = "Vinyl Record Artwork";
        color = "vinylrecordart";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinylcardboard_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5;
                    healthLevels[] = { {1, {"iat_collectibles\camping\data\vinyls\iat_vinylcover.rvmat"}}, {0.7, {"iat_collectibles\camping\data\vinyls\iat_vinylcover.rvmat"}}, {0.5, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_damage.rvmat"}}, {0.3, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_damage.rvmat"}}, {0, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_destruct.rvmat"}} };
                };
            };
        };
    };

    class IAT_BoosterPack_PictureFrames : IAT_BoosterPack_ColorBase
    {
        scope = 2;
        model = "\DZ\gear\camping\wooden_case.p3d";
        displayName = "Box of Artwork";
        color = "pictureframes";
        rotationFlags = 2;
        hiddenSelections[] = { "camoGround" };
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\wooden_case_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] = { {1, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.7, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.5, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0, {"DZ\gear\camping\data\wooden_case_destruct.rvmat"}} };
                };
            };
        };
    };

    //=================================== VINYL COVERS
    class IAT_VinylCover_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Vinyl Cover";
        descriptionShort = "A cardboard cover for a vinyl record.";
        model = "iat_collectibles\camping\iat_vinylcover.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_01_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\vinyls\iat_vinylcover.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\vinyls\iat_vinylcover.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\vinyls\iat_vinylcover_destruct.rvmat"}}
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
    class IAT_VinylRecord_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Vinyl Record";
        descriptionShort = "A vinyl record.";
        model = "iat_collectibles\camping\iat_vinyl_normal.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinylcenter_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\vinyls\iat_vinyl.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\vinyls\iat_vinyl.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\vinyls\iat_vinyl_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\vinyls\iat_vinyl_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\vinyls\iat_vinyl_destruct.rvmat"}}
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
    class IAT_VinylRecordArt_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Artistic Vinyl Record";
        descriptionShort = "A vinyl record with the artwork overlayed on the vinyl.";
        model = "iat_collectibles\camping\iat_vinyl_art.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_01_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_collectibles\camping\data\vinyls\iat_vinyl.rvmat"}},
                        {0.7, {"iat_collectibles\camping\data\vinyls\iat_vinyl.rvmat"}},
                        {0.5, {"iat_collectibles\camping\data\vinyls\iat_vinyl_damage.rvmat"}},
                        {0.3, {"iat_collectibles\camping\data\vinyls\iat_vinyl_damage.rvmat"}},
                        {0, {"iat_collectibles\camping\data\vinyls\iat_vinyl_destruct.rvmat"}}
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

    class IAT_VinylRecord_Default : IAT_VinylRecord_ColorBase { scope = 2; };

    // SET 1
    class IAT_VinylCover_01 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_01_co.paa" }; };
    class IAT_VinylRecordArt_01 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_01_co.paa" }; };
    class IAT_VinylCover_02 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_02_co.paa" }; };
    class IAT_VinylRecordArt_02 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_02_co.paa" }; };
    class IAT_VinylCover_03 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_03_co.paa" }; };
    class IAT_VinylRecordArt_03 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_03_co.paa" }; };
    class IAT_VinylCover_04 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_04_co.paa" }; };
    class IAT_VinylRecordArt_04 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_04_co.paa" }; };
    class IAT_VinylCover_05 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_05_co.paa" }; };
    class IAT_VinylRecordArt_05 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_05_co.paa" }; };
    class IAT_VinylCover_06 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_06_co.paa" }; };
    class IAT_VinylRecordArt_06 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_06_co.paa" }; };
    class IAT_VinylCover_07 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_07_co.paa" }; };
    class IAT_VinylRecordArt_07 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_07_co.paa" }; };
    class IAT_VinylCover_08 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_08_co.paa" }; };
    class IAT_VinylRecordArt_08 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_08_co.paa" }; };
    class IAT_VinylCover_09 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_09_co.paa" }; };
    class IAT_VinylRecordArt_09 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_09_co.paa" }; };
    class IAT_VinylCover_10 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_10_co.paa" }; };
    class IAT_VinylRecordArt_10 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_10_co.paa" }; };
    class IAT_VinylCover_11 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_11_co.paa" }; };
    class IAT_VinylRecordArt_11 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_11_co.paa" }; };
    class IAT_VinylCover_12 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_12_co.paa" }; };
    class IAT_VinylRecordArt_12 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_12_co.paa" }; };
    class IAT_VinylCover_13 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_13_co.paa" }; };
    class IAT_VinylRecordArt_13 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_13_co.paa" }; };
    class IAT_VinylCover_14 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_14_co.paa" }; };
    class IAT_VinylRecordArt_14 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_14_co.paa" }; };
    class IAT_VinylCover_15 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_15_co.paa" }; };
    class IAT_VinylRecordArt_15 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_15_co.paa" }; };
    class IAT_VinylCover_16 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_16_co.paa" }; };
    class IAT_VinylRecordArt_16 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_16_co.paa" }; };
    class IAT_VinylCover_17 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_17_co.paa" }; };
    class IAT_VinylRecordArt_17 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_17_co.paa" }; };
    class IAT_VinylCover_18 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_18_co.paa" }; };
    class IAT_VinylRecordArt_18 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_18_co.paa" }; };
    class IAT_VinylCover_19 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_19_co.paa" }; };
    class IAT_VinylRecordArt_19 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_19_co.paa" }; };
    class IAT_VinylCover_20 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_20_co.paa" }; };
    class IAT_VinylRecordArt_20 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_20_co.paa" }; };
    class IAT_VinylCover_21 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_21_co.paa" }; };
    class IAT_VinylRecordArt_21 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_21_co.paa" }; };
    class IAT_VinylCover_22 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_22_co.paa" }; };
    class IAT_VinylRecordArt_22 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_22_co.paa" }; };
    class IAT_VinylCover_23 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_23_co.paa" }; };
    class IAT_VinylRecordArt_23 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_23_co.paa" }; };
    class IAT_VinylCover_24 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_24_co.paa" }; };
    class IAT_VinylRecordArt_24 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_24_co.paa" }; };
    class IAT_VinylCover_25 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_25_co.paa" }; };
    class IAT_VinylRecordArt_25 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_25_co.paa" }; };
    class IAT_VinylCover_26 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_26_co.paa" }; };
    class IAT_VinylRecordArt_26 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_26_co.paa" }; };
    class IAT_VinylCover_27 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_27_co.paa" }; };
    class IAT_VinylRecordArt_27 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_27_co.paa" }; };
    class IAT_VinylCover_28 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_28_co.paa" }; };
    class IAT_VinylRecordArt_28 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_28_co.paa" }; };
    class IAT_VinylCover_29 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_29_co.paa" }; };
    class IAT_VinylRecordArt_29 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_29_co.paa" }; };
    class IAT_VinylCover_30 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_30_co.paa" }; };
    class IAT_VinylRecordArt_30 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_30_co.paa" }; };
    class IAT_VinylCover_31 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_31_co.paa" }; };
    class IAT_VinylRecordArt_31 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_31_co.paa" }; };
    class IAT_VinylCover_32 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_32_co.paa" }; };
    class IAT_VinylRecordArt_32 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_32_co.paa" }; };
    class IAT_VinylCover_33 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_33_co.paa" }; };
    class IAT_VinylRecordArt_33 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_33_co.paa" }; };
    class IAT_VinylCover_34 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_34_co.paa" }; };
    class IAT_VinylRecordArt_34 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_34_co.paa" }; };
    class IAT_VinylCover_35 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_35_co.paa" }; };
    class IAT_VinylRecordArt_35 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_35_co.paa" }; };
    class IAT_VinylCover_36 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_36_co.paa" }; };
    class IAT_VinylRecordArt_36 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_36_co.paa" }; };
    class IAT_VinylCover_37 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_37_co.paa" }; };
    class IAT_VinylRecordArt_37 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_37_co.paa" }; };
    class IAT_VinylCover_38 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_38_co.paa" }; };
    class IAT_VinylRecordArt_38 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_38_co.paa" }; };
    class IAT_VinylCover_39 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_39_co.paa" }; };
    class IAT_VinylRecordArt_39 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_39_co.paa" }; };
    class IAT_VinylCover_40 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_40_co.paa" }; };
    class IAT_VinylRecordArt_40 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_40_co.paa" }; };
    class IAT_VinylCover_41 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_41_co.paa" }; };
    class IAT_VinylRecordArt_41 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_41_co.paa" }; };
    class IAT_VinylCover_42 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_42_co.paa" }; };
    class IAT_VinylRecordArt_42 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_42_co.paa" }; };
    class IAT_VinylCover_43 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_43_co.paa" }; };
    class IAT_VinylRecordArt_43 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_43_co.paa" }; };
    class IAT_VinylCover_44 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_44_co.paa" }; };
    class IAT_VinylRecordArt_44 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_44_co.paa" }; };
    class IAT_VinylCover_45 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_45_co.paa" }; };
    class IAT_VinylRecordArt_45 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_45_co.paa" }; };
    class IAT_VinylCover_46 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_46_co.paa" }; };
    class IAT_VinylRecordArt_46 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_46_co.paa" }; };
    class IAT_VinylCover_47 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_47_co.paa" }; };
    class IAT_VinylRecordArt_47 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_47_co.paa" }; };
    class IAT_VinylCover_48 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_48_co.paa" }; };
    class IAT_VinylRecordArt_48 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_48_co.paa" }; };
    class IAT_VinylCover_49 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_49_co.paa" }; };
    class IAT_VinylRecordArt_49 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_49_co.paa" }; };
    class IAT_VinylCover_50 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 1 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_50_co.paa" }; };
    class IAT_VinylRecordArt_50 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 1 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_50_co.paa" }; };

    // SET 2
    class IAT_VinylCover_51 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_51_co.paa" }; };
    class IAT_VinylRecordArt_51 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_51_co.paa" }; };
    class IAT_VinylCover_52 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_52_co.paa" }; };
    class IAT_VinylRecordArt_52 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_52_co.paa" }; };
    class IAT_VinylCover_53 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_53_co.paa" }; };
    class IAT_VinylRecordArt_53 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_53_co.paa" }; };
    class IAT_VinylCover_54 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_54_co.paa" }; };
    class IAT_VinylRecordArt_54 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_54_co.paa" }; };
    class IAT_VinylCover_55 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_55_co.paa" }; };
    class IAT_VinylRecordArt_55 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_55_co.paa" }; };
    class IAT_VinylCover_56 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_56_co.paa" }; };
    class IAT_VinylRecordArt_56 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_56_co.paa" }; };
    class IAT_VinylCover_57 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_57_co.paa" }; };
    class IAT_VinylRecordArt_57 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_57_co.paa" }; };
    class IAT_VinylCover_58 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_58_co.paa" }; };
    class IAT_VinylRecordArt_58 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_58_co.paa" }; };
    class IAT_VinylCover_59 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_59_co.paa" }; };
    class IAT_VinylRecordArt_59 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_59_co.paa" }; };
    class IAT_VinylCover_60 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_60_co.paa" }; };
    class IAT_VinylRecordArt_60 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_60_co.paa" }; };
    class IAT_VinylCover_61 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_61_co.paa" }; };
    class IAT_VinylRecordArt_61 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_61_co.paa" }; };
    class IAT_VinylCover_62 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_62_co.paa" }; };
    class IAT_VinylRecordArt_62 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_62_co.paa" }; };
    class IAT_VinylCover_63 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_63_co.paa" }; };
    class IAT_VinylRecordArt_63 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_63_co.paa" }; };
    class IAT_VinylCover_64 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_64_co.paa" }; };
    class IAT_VinylRecordArt_64 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_64_co.paa" }; };
    class IAT_VinylCover_65 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_65_co.paa" }; };
    class IAT_VinylRecordArt_65 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_65_co.paa" }; };
    class IAT_VinylCover_66 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_66_co.paa" }; };
    class IAT_VinylRecordArt_66 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_66_co.paa" }; };
    class IAT_VinylCover_67 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_67_co.paa" }; };
    class IAT_VinylRecordArt_67 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_67_co.paa" }; };
    class IAT_VinylCover_68 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_68_co.paa" }; };
    class IAT_VinylRecordArt_68 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_68_co.paa" }; };
    class IAT_VinylCover_69 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_69_co.paa" }; };
    class IAT_VinylRecordArt_69 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_69_co.paa" }; };
    class IAT_VinylCover_70 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_70_co.paa" }; };
    class IAT_VinylRecordArt_70 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_70_co.paa" }; };
    class IAT_VinylCover_71 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_71_co.paa" }; };
    class IAT_VinylRecordArt_71 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_71_co.paa" }; };
    class IAT_VinylCover_72 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_72_co.paa" }; };
    class IAT_VinylRecordArt_72 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_72_co.paa" }; };
    class IAT_VinylCover_73 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_73_co.paa" }; };
    class IAT_VinylRecordArt_73 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_73_co.paa" }; };
    class IAT_VinylCover_74 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_74_co.paa" }; };
    class IAT_VinylRecordArt_74 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_74_co.paa" }; };
    class IAT_VinylCover_75 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_75_co.paa" }; };
    class IAT_VinylRecordArt_75 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_75_co.paa" }; };
    class IAT_VinylCover_76 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_76_co.paa" }; };
    class IAT_VinylRecordArt_76 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_76_co.paa" }; };
    class IAT_VinylCover_77 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_77_co.paa" }; };
    class IAT_VinylRecordArt_77 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_77_co.paa" }; };
    class IAT_VinylCover_78 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_78_co.paa" }; };
    class IAT_VinylRecordArt_78 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_78_co.paa" }; };
    class IAT_VinylCover_79 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_79_co.paa" }; };
    class IAT_VinylRecordArt_79 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_79_co.paa" }; };
    class IAT_VinylCover_80 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_80_co.paa" }; };
    class IAT_VinylRecordArt_80 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_80_co.paa" }; };
    class IAT_VinylCover_81 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_81_co.paa" }; };
    class IAT_VinylRecordArt_81 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_81_co.paa" }; };
    class IAT_VinylCover_82 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_82_co.paa" }; };
    class IAT_VinylRecordArt_82 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_82_co.paa" }; };
    class IAT_VinylCover_83 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_83_co.paa" }; };
    class IAT_VinylRecordArt_83 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_83_co.paa" }; };
    class IAT_VinylCover_84 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_84_co.paa" }; };
    class IAT_VinylRecordArt_84 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_84_co.paa" }; };
    class IAT_VinylCover_85 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_85_co.paa" }; };
    class IAT_VinylRecordArt_85 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_85_co.paa" }; };
    class IAT_VinylCover_86 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_86_co.paa" }; };
    class IAT_VinylRecordArt_86 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_86_co.paa" }; };
    class IAT_VinylCover_87 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_87_co.paa" }; };
    class IAT_VinylRecordArt_87 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_87_co.paa" }; };
    class IAT_VinylCover_88 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_88_co.paa" }; };
    class IAT_VinylRecordArt_88 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_88_co.paa" }; };
    class IAT_VinylCover_89 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_89_co.paa" }; };
    class IAT_VinylRecordArt_89 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_89_co.paa" }; };
    class IAT_VinylCover_90 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_90_co.paa" }; };
    class IAT_VinylRecordArt_90 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_90_co.paa" }; };
    class IAT_VinylCover_91 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_91_co.paa" }; };
    class IAT_VinylRecordArt_91 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_91_co.paa" }; };
    class IAT_VinylCover_92 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_92_co.paa" }; };
    class IAT_VinylRecordArt_92 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_92_co.paa" }; };
    class IAT_VinylCover_93 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_93_co.paa" }; };
    class IAT_VinylRecordArt_93 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_93_co.paa" }; };
    class IAT_VinylCover_94 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_94_co.paa" }; };
    class IAT_VinylRecordArt_94 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_94_co.paa" }; };
    class IAT_VinylCover_95 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_95_co.paa" }; };
    class IAT_VinylRecordArt_95 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_95_co.paa" }; };
    class IAT_VinylCover_96 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_96_co.paa" }; };
    class IAT_VinylRecordArt_96 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_96_co.paa" }; };
    class IAT_VinylCover_97 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_97_co.paa" }; };
    class IAT_VinylRecordArt_97 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_97_co.paa" }; };
    class IAT_VinylCover_98 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_98_co.paa" }; };
    class IAT_VinylRecordArt_98 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_98_co.paa" }; };
    class IAT_VinylCover_99 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_99_co.paa" }; };
    class IAT_VinylRecordArt_99 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_99_co.paa" }; };
    class IAT_VinylCover_100 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 2 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_100_co.paa" }; };
    class IAT_VinylRecordArt_100 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 2 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_100_co.paa" }; };

    // SET 3
    class IAT_VinylCover_101 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_101_co.paa" }; };
    class IAT_VinylRecordArt_101 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_101_co.paa" }; };
    class IAT_VinylCover_102 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_102_co.paa" }; };
    class IAT_VinylRecordArt_102 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_102_co.paa" }; };
    class IAT_VinylCover_103 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_103_co.paa" }; };
    class IAT_VinylRecordArt_103 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_103_co.paa" }; };
    class IAT_VinylCover_104 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_104_co.paa" }; };
    class IAT_VinylRecordArt_104 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_104_co.paa" }; };
    class IAT_VinylCover_105 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_105_co.paa" }; };
    class IAT_VinylRecordArt_105 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_105_co.paa" }; };
    class IAT_VinylCover_106 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_106_co.paa" }; };
    class IAT_VinylRecordArt_106 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_106_co.paa" }; };
    class IAT_VinylCover_107 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_107_co.paa" }; };
    class IAT_VinylRecordArt_107 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_107_co.paa" }; };
    class IAT_VinylCover_108 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_108_co.paa" }; };
    class IAT_VinylRecordArt_108 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_108_co.paa" }; };
    class IAT_VinylCover_109 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_109_co.paa" }; };
    class IAT_VinylRecordArt_109 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_109_co.paa" }; };
    class IAT_VinylCover_110 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_110_co.paa" }; };
    class IAT_VinylRecordArt_110 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_110_co.paa" }; };
    class IAT_VinylCover_111 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_111_co.paa" }; };
    class IAT_VinylRecordArt_111 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_111_co.paa" }; };
    class IAT_VinylCover_112 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_112_co.paa" }; };
    class IAT_VinylRecordArt_112 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_112_co.paa" }; };
    class IAT_VinylCover_113 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_113_co.paa" }; };
    class IAT_VinylRecordArt_113 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_113_co.paa" }; };
    class IAT_VinylCover_114 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_114_co.paa" }; };
    class IAT_VinylRecordArt_114 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_114_co.paa" }; };
    class IAT_VinylCover_115 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_115_co.paa" }; };
    class IAT_VinylRecordArt_115 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_115_co.paa" }; };
    class IAT_VinylCover_116 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_116_co.paa" }; };
    class IAT_VinylRecordArt_116 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_116_co.paa" }; };
    class IAT_VinylCover_117 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_117_co.paa" }; };
    class IAT_VinylRecordArt_117 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_117_co.paa" }; };
    class IAT_VinylCover_118 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_118_co.paa" }; };
    class IAT_VinylRecordArt_118 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_118_co.paa" }; };
    class IAT_VinylCover_119 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_119_co.paa" }; };
    class IAT_VinylRecordArt_119 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_119_co.paa" }; };
    class IAT_VinylCover_120 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_120_co.paa" }; };
    class IAT_VinylRecordArt_120 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_120_co.paa" }; };
    class IAT_VinylCover_121 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_121_co.paa" }; };
    class IAT_VinylRecordArt_121 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_121_co.paa" }; };
    class IAT_VinylCover_122 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_122_co.paa" }; };
    class IAT_VinylRecordArt_122 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_122_co.paa" }; };
    class IAT_VinylCover_123 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_123_co.paa" }; };
    class IAT_VinylRecordArt_123 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_123_co.paa" }; };
    class IAT_VinylCover_124 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_124_co.paa" }; };
    class IAT_VinylRecordArt_124 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_124_co.paa" }; };
    class IAT_VinylCover_125 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_125_co.paa" }; };
    class IAT_VinylRecordArt_125 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_125_co.paa" }; };
    class IAT_VinylCover_126 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_126_co.paa" }; };
    class IAT_VinylRecordArt_126 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_126_co.paa" }; };
    class IAT_VinylCover_127 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_127_co.paa" }; };
    class IAT_VinylRecordArt_127 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_127_co.paa" }; };
    class IAT_VinylCover_128 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_128_co.paa" }; };
    class IAT_VinylRecordArt_128 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_128_co.paa" }; };
    class IAT_VinylCover_129 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_129_co.paa" }; };
    class IAT_VinylRecordArt_129 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_129_co.paa" }; };
    class IAT_VinylCover_130 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_130_co.paa" }; };
    class IAT_VinylRecordArt_130 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_130_co.paa" }; };
    class IAT_VinylCover_131 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_131_co.paa" }; };
    class IAT_VinylRecordArt_131 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_131_co.paa" }; };
    class IAT_VinylCover_132 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_132_co.paa" }; };
    class IAT_VinylRecordArt_132 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_132_co.paa" }; };
    class IAT_VinylCover_133 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_133_co.paa" }; };
    class IAT_VinylRecordArt_133 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_133_co.paa" }; };
    class IAT_VinylCover_134 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_134_co.paa" }; };
    class IAT_VinylRecordArt_134 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_134_co.paa" }; };
    class IAT_VinylCover_135 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_135_co.paa" }; };
    class IAT_VinylRecordArt_135 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_135_co.paa" }; };
    class IAT_VinylCover_136 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_136_co.paa" }; };
    class IAT_VinylRecordArt_136 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_136_co.paa" }; };
    class IAT_VinylCover_137 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_137_co.paa" }; };
    class IAT_VinylRecordArt_137 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_137_co.paa" }; };
    class IAT_VinylCover_138 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_138_co.paa" }; };
    class IAT_VinylRecordArt_138 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_138_co.paa" }; };
    class IAT_VinylCover_139 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_139_co.paa" }; };
    class IAT_VinylRecordArt_139 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_139_co.paa" }; };
    class IAT_VinylCover_140 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_140_co.paa" }; };
    class IAT_VinylRecordArt_140 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_140_co.paa" }; };
    class IAT_VinylCover_141 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_141_co.paa" }; };
    class IAT_VinylRecordArt_141 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_141_co.paa" }; };
    class IAT_VinylCover_142 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_142_co.paa" }; };
    class IAT_VinylRecordArt_142 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_142_co.paa" }; };
    class IAT_VinylCover_143 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_143_co.paa" }; };
    class IAT_VinylRecordArt_143 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_143_co.paa" }; };
    class IAT_VinylCover_144 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_144_co.paa" }; };
    class IAT_VinylRecordArt_144 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_144_co.paa" }; };
    class IAT_VinylCover_145 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_145_co.paa" }; };
    class IAT_VinylRecordArt_145 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_145_co.paa" }; };
    class IAT_VinylCover_146 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_146_co.paa" }; };
    class IAT_VinylRecordArt_146 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_146_co.paa" }; };
    class IAT_VinylCover_147 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_147_co.paa" }; };
    class IAT_VinylRecordArt_147 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_147_co.paa" }; };
    class IAT_VinylCover_148 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_148_co.paa" }; };
    class IAT_VinylRecordArt_148 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_148_co.paa" }; };
    class IAT_VinylCover_149 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_149_co.paa" }; };
    class IAT_VinylRecordArt_149 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_149_co.paa" }; };
    class IAT_VinylCover_150 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 3 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_150_co.paa" }; };
    class IAT_VinylRecordArt_150 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 3 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_150_co.paa" }; };

    // SET 4
    class IAT_VinylCover_151 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_151_co.paa" }; };
    class IAT_VinylRecordArt_151 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_151_co.paa" }; };
    class IAT_VinylCover_152 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_152_co.paa" }; };
    class IAT_VinylRecordArt_152 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_152_co.paa" }; };
    class IAT_VinylCover_153 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_153_co.paa" }; };
    class IAT_VinylRecordArt_153 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_153_co.paa" }; };
    class IAT_VinylCover_154 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_154_co.paa" }; };
    class IAT_VinylRecordArt_154 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_154_co.paa" }; };
    class IAT_VinylCover_155 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_155_co.paa" }; };
    class IAT_VinylRecordArt_155 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_155_co.paa" }; };
    class IAT_VinylCover_156 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_156_co.paa" }; };
    class IAT_VinylRecordArt_156 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_156_co.paa" }; };
    class IAT_VinylCover_157 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_157_co.paa" }; };
    class IAT_VinylRecordArt_157 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_157_co.paa" }; };
    class IAT_VinylCover_158 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_158_co.paa" }; };
    class IAT_VinylRecordArt_158 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_158_co.paa" }; };
    class IAT_VinylCover_159 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_159_co.paa" }; };
    class IAT_VinylRecordArt_159 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_159_co.paa" }; };
    class IAT_VinylCover_160 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_160_co.paa" }; };
    class IAT_VinylRecordArt_160 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_160_co.paa" }; };
    class IAT_VinylCover_161 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_161_co.paa" }; };
    class IAT_VinylRecordArt_161 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_161_co.paa" }; };
    class IAT_VinylCover_162 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_162_co.paa" }; };
    class IAT_VinylRecordArt_162 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_162_co.paa" }; };
    class IAT_VinylCover_163 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_163_co.paa" }; };
    class IAT_VinylRecordArt_163 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_163_co.paa" }; };
    class IAT_VinylCover_164 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_164_co.paa" }; };
    class IAT_VinylRecordArt_164 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_164_co.paa" }; };
    class IAT_VinylCover_165 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_165_co.paa" }; };
    class IAT_VinylRecordArt_165 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_165_co.paa" }; };
    class IAT_VinylCover_166 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_166_co.paa" }; };
    class IAT_VinylRecordArt_166 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_166_co.paa" }; };
    class IAT_VinylCover_167 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_167_co.paa" }; };
    class IAT_VinylRecordArt_167 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_167_co.paa" }; };
    class IAT_VinylCover_168 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_168_co.paa" }; };
    class IAT_VinylRecordArt_168 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_168_co.paa" }; };
    class IAT_VinylCover_169 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_169_co.paa" }; };
    class IAT_VinylRecordArt_169 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_169_co.paa" }; };
    class IAT_VinylCover_170 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_170_co.paa" }; };
    class IAT_VinylRecordArt_170 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_170_co.paa" }; };
    class IAT_VinylCover_171 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_171_co.paa" }; };
    class IAT_VinylRecordArt_171 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_171_co.paa" }; };
    class IAT_VinylCover_172 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_172_co.paa" }; };
    class IAT_VinylRecordArt_172 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_172_co.paa" }; };
    class IAT_VinylCover_173 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_173_co.paa" }; };
    class IAT_VinylRecordArt_173 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_173_co.paa" }; };
    class IAT_VinylCover_174 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_174_co.paa" }; };
    class IAT_VinylRecordArt_174 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_174_co.paa" }; };
    class IAT_VinylCover_175 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_175_co.paa" }; };
    class IAT_VinylRecordArt_175 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_175_co.paa" }; };
    class IAT_VinylCover_176 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_176_co.paa" }; };
    class IAT_VinylRecordArt_176 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_176_co.paa" }; };
    class IAT_VinylCover_177 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_177_co.paa" }; };
    class IAT_VinylRecordArt_177 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_177_co.paa" }; };
    class IAT_VinylCover_178 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_178_co.paa" }; };
    class IAT_VinylRecordArt_178 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_178_co.paa" }; };
    class IAT_VinylCover_179 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_179_co.paa" }; };
    class IAT_VinylRecordArt_179 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_179_co.paa" }; };
    class IAT_VinylCover_180 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_180_co.paa" }; };
    class IAT_VinylRecordArt_180 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_180_co.paa" }; };
    class IAT_VinylCover_181 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_181_co.paa" }; };
    class IAT_VinylRecordArt_181 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_181_co.paa" }; };
    class IAT_VinylCover_182 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_182_co.paa" }; };
    class IAT_VinylRecordArt_182 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_182_co.paa" }; };
    class IAT_VinylCover_183 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_183_co.paa" }; };
    class IAT_VinylRecordArt_183 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_183_co.paa" }; };
    class IAT_VinylCover_184 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_184_co.paa" }; };
    class IAT_VinylRecordArt_184 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_184_co.paa" }; };
    class IAT_VinylCover_185 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_185_co.paa" }; };
    class IAT_VinylRecordArt_185 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_185_co.paa" }; };
    class IAT_VinylCover_186 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_186_co.paa" }; };
    class IAT_VinylRecordArt_186 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_186_co.paa" }; };
    class IAT_VinylCover_187 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_187_co.paa" }; };
    class IAT_VinylRecordArt_187 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_187_co.paa" }; };
    class IAT_VinylCover_188 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_188_co.paa" }; };
    class IAT_VinylRecordArt_188 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_188_co.paa" }; };
    class IAT_VinylCover_189 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_189_co.paa" }; };
    class IAT_VinylRecordArt_189 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_189_co.paa" }; };
    class IAT_VinylCover_190 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_190_co.paa" }; };
    class IAT_VinylRecordArt_190 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_190_co.paa" }; };
    class IAT_VinylCover_191 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_191_co.paa" }; };
    class IAT_VinylRecordArt_191 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_191_co.paa" }; };
    class IAT_VinylCover_192 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_192_co.paa" }; };
    class IAT_VinylRecordArt_192 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_192_co.paa" }; };
    class IAT_VinylCover_193 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_193_co.paa" }; };
    class IAT_VinylRecordArt_193 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_193_co.paa" }; };
    class IAT_VinylCover_194 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_194_co.paa" }; };
    class IAT_VinylRecordArt_194 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_194_co.paa" }; };
    class IAT_VinylCover_195 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_195_co.paa" }; };
    class IAT_VinylRecordArt_195 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_195_co.paa" }; };
    class IAT_VinylCover_196 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_196_co.paa" }; };
    class IAT_VinylRecordArt_196 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_196_co.paa" }; };
    class IAT_VinylCover_197 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_197_co.paa" }; };
    class IAT_VinylRecordArt_197 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_197_co.paa" }; };
    class IAT_VinylCover_198 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_198_co.paa" }; };
    class IAT_VinylRecordArt_198 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_198_co.paa" }; };
    class IAT_VinylCover_199 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_199_co.paa" }; };
    class IAT_VinylRecordArt_199 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_199_co.paa" }; };
    class IAT_VinylCover_200 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 4 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_200_co.paa" }; };
    class IAT_VinylRecordArt_200 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 4 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_200_co.paa" }; };

    // SET 5
    class IAT_VinylCover_201 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_201_co.paa" }; };
    class IAT_VinylRecordArt_201 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_201_co.paa" }; };
    class IAT_VinylCover_202 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_202_co.paa" }; };
    class IAT_VinylRecordArt_202 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_202_co.paa" }; };
    class IAT_VinylCover_203 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_203_co.paa" }; };
    class IAT_VinylRecordArt_203 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_203_co.paa" }; };
    class IAT_VinylCover_204 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_204_co.paa" }; };
    class IAT_VinylRecordArt_204 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_204_co.paa" }; };
    class IAT_VinylCover_205 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_205_co.paa" }; };
    class IAT_VinylRecordArt_205 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_205_co.paa" }; };
    class IAT_VinylCover_206 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_206_co.paa" }; };
    class IAT_VinylRecordArt_206 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_206_co.paa" }; };
    class IAT_VinylCover_207 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_207_co.paa" }; };
    class IAT_VinylRecordArt_207 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_207_co.paa" }; };
    class IAT_VinylCover_208 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_208_co.paa" }; };
    class IAT_VinylRecordArt_208 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_208_co.paa" }; };
    class IAT_VinylCover_209 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_209_co.paa" }; };
    class IAT_VinylRecordArt_209 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_209_co.paa" }; };
    class IAT_VinylCover_210 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_210_co.paa" }; };
    class IAT_VinylRecordArt_210 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_210_co.paa" }; };
    class IAT_VinylCover_211 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_211_co.paa" }; };
    class IAT_VinylRecordArt_211 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_211_co.paa" }; };
    class IAT_VinylCover_212 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_212_co.paa" }; };
    class IAT_VinylRecordArt_212 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_212_co.paa" }; };
    class IAT_VinylCover_213 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_213_co.paa" }; };
    class IAT_VinylRecordArt_213 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_213_co.paa" }; };
    class IAT_VinylCover_214 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_214_co.paa" }; };
    class IAT_VinylRecordArt_214 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_214_co.paa" }; };
    class IAT_VinylCover_215 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_215_co.paa" }; };
    class IAT_VinylRecordArt_215 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_215_co.paa" }; };
    class IAT_VinylCover_216 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_216_co.paa" }; };
    class IAT_VinylRecordArt_216 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_216_co.paa" }; };
    class IAT_VinylCover_217 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_217_co.paa" }; };
    class IAT_VinylRecordArt_217 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_217_co.paa" }; };
    class IAT_VinylCover_218 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_218_co.paa" }; };
    class IAT_VinylRecordArt_218 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_218_co.paa" }; };
    class IAT_VinylCover_219 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_219_co.paa" }; };
    class IAT_VinylRecordArt_219 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_219_co.paa" }; };
    class IAT_VinylCover_220 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_220_co.paa" }; };
    class IAT_VinylRecordArt_220 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_220_co.paa" }; };
    class IAT_VinylCover_221 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_221_co.paa" }; };
    class IAT_VinylRecordArt_221 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_221_co.paa" }; };
    class IAT_VinylCover_222 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_222_co.paa" }; };
    class IAT_VinylRecordArt_222 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_222_co.paa" }; };
    class IAT_VinylCover_223 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_223_co.paa" }; };
    class IAT_VinylRecordArt_223 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 23 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_223_co.paa" }; };
    class IAT_VinylCover_224 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_224_co.paa" }; };
    class IAT_VinylRecordArt_224 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 24 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_224_co.paa" }; };
    class IAT_VinylCover_225 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_225_co.paa" }; };
    class IAT_VinylRecordArt_225 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 25 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_225_co.paa" }; };
    class IAT_VinylCover_226 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_226_co.paa" }; };
    class IAT_VinylRecordArt_226 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 26 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_226_co.paa" }; };
    class IAT_VinylCover_227 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_227_co.paa" }; };
    class IAT_VinylRecordArt_227 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 27 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_227_co.paa" }; };
    class IAT_VinylCover_228 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_228_co.paa" }; };
    class IAT_VinylRecordArt_228 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 28 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_228_co.paa" }; };
    class IAT_VinylCover_229 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_229_co.paa" }; };
    class IAT_VinylRecordArt_229 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 29 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_229_co.paa" }; };
    class IAT_VinylCover_230 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_230_co.paa" }; };
    class IAT_VinylRecordArt_230 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 30 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_230_co.paa" }; };
    class IAT_VinylCover_231 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_231_co.paa" }; };
    class IAT_VinylRecordArt_231 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 31 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_231_co.paa" }; };
    class IAT_VinylCover_232 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_232_co.paa" }; };
    class IAT_VinylRecordArt_232 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 32 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_232_co.paa" }; };
    class IAT_VinylCover_233 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_233_co.paa" }; };
    class IAT_VinylRecordArt_233 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 33 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_233_co.paa" }; };
    class IAT_VinylCover_234 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_234_co.paa" }; };
    class IAT_VinylRecordArt_234 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 34 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_234_co.paa" }; };
    class IAT_VinylCover_235 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_235_co.paa" }; };
    class IAT_VinylRecordArt_235 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 35 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_235_co.paa" }; };
    class IAT_VinylCover_236 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_236_co.paa" }; };
    class IAT_VinylRecordArt_236 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 36 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_236_co.paa" }; };
    class IAT_VinylCover_237 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_237_co.paa" }; };
    class IAT_VinylRecordArt_237 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 37 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_237_co.paa" }; };
    class IAT_VinylCover_238 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_238_co.paa" }; };
    class IAT_VinylRecordArt_238 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 38 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_238_co.paa" }; };
    class IAT_VinylCover_239 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_239_co.paa" }; };
    class IAT_VinylRecordArt_239 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 39 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_239_co.paa" }; };
    class IAT_VinylCover_240 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_240_co.paa" }; };
    class IAT_VinylRecordArt_240 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 40 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_240_co.paa" }; };
    class IAT_VinylCover_241 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_241_co.paa" }; };
    class IAT_VinylRecordArt_241 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 41 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_241_co.paa" }; };
    class IAT_VinylCover_242 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_242_co.paa" }; };
    class IAT_VinylRecordArt_242 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 42 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_242_co.paa" }; };
    class IAT_VinylCover_243 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_243_co.paa" }; };
    class IAT_VinylRecordArt_243 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 43 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_243_co.paa" }; };
    class IAT_VinylCover_244 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_244_co.paa" }; };
    class IAT_VinylRecordArt_244 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 44 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_244_co.paa" }; };
    class IAT_VinylCover_245 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_245_co.paa" }; };
    class IAT_VinylRecordArt_245 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 45 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_245_co.paa" }; };
    class IAT_VinylCover_246 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_246_co.paa" }; };
    class IAT_VinylRecordArt_246 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 46 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_246_co.paa" }; };
    class IAT_VinylCover_247 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_247_co.paa" }; };
    class IAT_VinylRecordArt_247 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 47 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_247_co.paa" }; };
    class IAT_VinylCover_248 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_248_co.paa" }; };
    class IAT_VinylRecordArt_248 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 48 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_248_co.paa" }; };
    class IAT_VinylCover_249 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_249_co.paa" }; };
    class IAT_VinylRecordArt_249 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 49 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_249_co.paa" }; };
    class IAT_VinylCover_250 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 5 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_250_co.paa" }; };
    class IAT_VinylRecordArt_250 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 5 - 50 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_250_co.paa" }; };

    // SET 6
    class IAT_VinylCover_251 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_251_co.paa" }; };
    class IAT_VinylRecordArt_251 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 1 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_251_co.paa" }; };
    class IAT_VinylCover_252 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_252_co.paa" }; };
    class IAT_VinylRecordArt_252 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 2 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_252_co.paa" }; };
    class IAT_VinylCover_253 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_253_co.paa" }; };
    class IAT_VinylRecordArt_253 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 3 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_253_co.paa" }; };
    class IAT_VinylCover_254 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_254_co.paa" }; };
    class IAT_VinylRecordArt_254 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 4 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_254_co.paa" }; };
    class IAT_VinylCover_255 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_255_co.paa" }; };
    class IAT_VinylRecordArt_255 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 5 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_255_co.paa" }; };
    class IAT_VinylCover_256 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_256_co.paa" }; };
    class IAT_VinylRecordArt_256 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 6 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_256_co.paa" }; };
    class IAT_VinylCover_257 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_257_co.paa" }; };
    class IAT_VinylRecordArt_257 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 7 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_257_co.paa" }; };
    class IAT_VinylCover_258 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_258_co.paa" }; };
    class IAT_VinylRecordArt_258 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 8 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_258_co.paa" }; };
    class IAT_VinylCover_259 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_259_co.paa" }; };
    class IAT_VinylRecordArt_259 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 9 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_259_co.paa" }; };
    class IAT_VinylCover_260 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_260_co.paa" }; };
    class IAT_VinylRecordArt_260 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 10 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_260_co.paa" }; };
    class IAT_VinylCover_261 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_261_co.paa" }; };
    class IAT_VinylRecordArt_261 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 11 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_261_co.paa" }; };
    class IAT_VinylCover_262 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_262_co.paa" }; };
    class IAT_VinylRecordArt_262 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 12 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_262_co.paa" }; };
    class IAT_VinylCover_263 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_263_co.paa" }; };
    class IAT_VinylRecordArt_263 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 13 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_263_co.paa" }; };
    class IAT_VinylCover_264 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_264_co.paa" }; };
    class IAT_VinylRecordArt_264 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 14 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_264_co.paa" }; };
    class IAT_VinylCover_265 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_265_co.paa" }; };
    class IAT_VinylRecordArt_265 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 15 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_265_co.paa" }; };
    class IAT_VinylCover_266 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_266_co.paa" }; };
    class IAT_VinylRecordArt_266 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 16 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_266_co.paa" }; };
    class IAT_VinylCover_267 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_267_co.paa" }; };
    class IAT_VinylRecordArt_267 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 17 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_267_co.paa" }; };
    class IAT_VinylCover_268 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_268_co.paa" }; };
    class IAT_VinylRecordArt_268 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 18 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_268_co.paa" }; };
    class IAT_VinylCover_269 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_269_co.paa" }; };
    class IAT_VinylRecordArt_269 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 19 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_269_co.paa" }; };
    class IAT_VinylCover_270 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_270_co.paa" }; };
    class IAT_VinylRecordArt_270 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 20 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_270_co.paa" }; };
    class IAT_VinylCover_271 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_271_co.paa" }; };
    class IAT_VinylRecordArt_271 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 21 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_271_co.paa" }; };
    class IAT_VinylCover_272 : IAT_VinylCover_ColorBase { scope = 2; displayName = "Vinyl Cover Set 6 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_272_co.paa" }; };
    class IAT_VinylRecordArt_272 : IAT_VinylRecordArt_ColorBase { scope = 2; displayName = "Vinyl Art Set 6 - 22 of 50"; hiddenSelectionsTextures[] = { "iat_collectibles\camping\data\vinyls\iat_vinyl_272_co.paa" }; };
};
class CfgSlots
{
    class Slot_IAT_GunWall_Pistol1
    {
        name = "IAT_GunWall_Pistol1";
        displayName = "Pistol Display";
        ghostIcon = "set:dayz_inventory image:pistol";
    };
    class Slot_IAT_GunWall_Pistol2
    {
        name = "IAT_GunWall_Pistol2";
        displayName = "Pistol Display";
        ghostIcon = "set:dayz_inventory image:pistol";
    };
    class Slot_IAT_GunWall_Pistol3
    {
        name = "IAT_GunWall_Pistol3";
        displayName = "Pistol Display";
        ghostIcon = "set:dayz_inventory image:pistol";
    };
    class Slot_IAT_GunWall_Rifle1
    {
        name = "IAT_GunWall_Rifle1";
        displayName = "Rifle Display";
        ghostIcon = "set:dayz_inventory image:shoulderleft";
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
    //====================== GUN WALL
    class Proxyiat_gunwall_pistol1_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_GunWall_Pistol1" };
        model = "iat_collectibles\camping\proxy\iat_gunwall_pistol1_proxy.p3d";
    };
    class Proxyiat_gunwall_pistol2_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_GunWall_Pistol2" };
        model = "iat_collectibles\camping\proxy\iat_gunwall_pistol2_proxy.p3d";
    };
    class Proxyiat_gunwall_pistol3_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_GunWall_Pistol3" };
        model = "iat_collectibles\camping\proxy\iat_gunwall_pistol3_proxy.p3d";
    };
    class Proxyiat_gunwall_rifle1_proxy : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_GunWall_Rifle1" };
        model = "iat_collectibles\camping\proxy\iat_gunwall_rifle1_proxy.p3d";
    };

};