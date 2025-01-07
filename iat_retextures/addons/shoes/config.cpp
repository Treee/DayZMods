class CfgPatches
{
    class IAT_Retextures_Shoes
    {
        requiredAddons[] = { "DZ_Characters", "DZ_Characters_Shoes" };
    };
};
class CfgVehicles
{
    class AthleticShoes_ColorBase;
    class JungleBoots_ColorBase;
    class NBCBootsBase;
    class Sneakers_ColorBase;
    class LeatherShoes_ColorBase;
    class FeetCover_Improvised;
    class CombatBoots_ColorBase;

    //====================================================== VANILLA RETEXTURES
    class NBCBootsBase_Gray : NBCBootsBase
    {
        scope = 2;
        color = "Gray";
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\shoes\data\NBC_Boots_grey_co.paa",
            "\dz\characters\shoes\data\NBC_Boots_grey_co.paa",
            "\dz\characters\shoes\data\NBC_Boots_grey_co.paa"
        };
    };
    class NBCBootsBase_Yellow : NBCBootsBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\shoes\data\NBC_Boots_yellow_co.paa",
            "\dz\characters\shoes\data\NBC_Boots_yellow_co.paa",
            "\dz\characters\shoes\data\NBC_Boots_yellow_co.paa"
        };
    };
    class NBCBootsBase_Orange : NBCBootsBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\nbc_boots_orange_co.paa",
            "iat_retextures\shoes\data\nbc_boots_orange_co.paa",
            "iat_retextures\shoes\data\nbc_boots_orange_co.paa"
        };
    };
    class NBCBootsBase_White : NBCBootsBase
    {
        scope = 2;
        color = "White";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\nbc_boots_white_co.paa",
            "iat_retextures\shoes\data\nbc_boots_white_co.paa",
            "iat_retextures\shoes\data\nbc_boots_white_co.paa"
        };
    };

    class AthleticShoes_White : AthleticShoes_ColorBase
    {
        scope = 2;
        color = "White";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\athleticshoe_white_co.paa",
            "iat_retextures\shoes\data\athleticshoe_white_co.paa",
            "iat_retextures\shoes\data\athleticshoe_white_co.paa"
        };
    };
    class AthleticShoes_Green1 : AthleticShoes_ColorBase
    {
        scope = 2;
        color = "Green1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\athleticshoe_green_co.paa",
            "iat_retextures\shoes\data\athleticshoe_green_co.paa",
            "iat_retextures\shoes\data\athleticshoe_green_co.paa"
        };
    };
    class AthleticShoes_Brown1 : AthleticShoes_ColorBase
    {
        scope = 2;
        color = "Brown1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\athleticshoe_brown_co.paa",
            "iat_retextures\shoes\data\athleticshoe_brown_co.paa",
            "iat_retextures\shoes\data\athleticshoe_brown_co.paa"
        };
    };

    class JungleBoots_Yellow : JungleBoots_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\jungleboots_yelo_co.paa",
            "iat_retextures\shoes\data\jungleboots_yelo_co.paa",
            "iat_retextures\shoes\data\jungleboots_yelo_co.paa"
        };
    };
    class JungleBoots_Red9291 : JungleBoots_ColorBase
    {
        scope = 2;
        color = "Red9291";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\jungleboots_red9291_co.paa",
            "iat_retextures\shoes\data\jungleboots_red9291_co.paa",
            "iat_retextures\shoes\data\jungleboots_red9291_co.paa"
        };
    };
    class JungleBoots_MTP : JungleBoots_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots01_co.paa",
            "iat_retextures\shoes\data\JungleBoots01_co.paa",
            "iat_retextures\shoes\data\JungleBoots01_co.paa"
        };
    };
    class JungleBoots_ATAC : JungleBoots_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots04_co.paa",
            "iat_retextures\shoes\data\JungleBoots04_co.paa",
            "iat_retextures\shoes\data\JungleBoots04_co.paa"
        };
    };
    class JungleBoots_ATACSFG : JungleBoots_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots38_co.paa",
            "iat_retextures\shoes\data\JungleBoots38_co.paa",
            "iat_retextures\shoes\data\JungleBoots38_co.paa"
        };
    };
    class JungleBoots_USNAOR2 : JungleBoots_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots09_co.paa",
            "iat_retextures\shoes\data\JungleBoots09_co.paa",
            "iat_retextures\shoes\data\JungleBoots09_co.paa"
        };
    };
    class JungleBoots_USNAOR1 : JungleBoots_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots10_co.paa",
            "iat_retextures\shoes\data\JungleBoots10_co.paa",
            "iat_retextures\shoes\data\JungleBoots10_co.paa"
        };
    };
    class JungleBoots_SURPAT : JungleBoots_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots12_co.paa",
            "iat_retextures\shoes\data\JungleBoots12_co.paa",
            "iat_retextures\shoes\data\JungleBoots12_co.paa"
        };
    };
    class JungleBoots_MARPATWinter : JungleBoots_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots19_co.paa",
            "iat_retextures\shoes\data\JungleBoots19_co.paa",
            "iat_retextures\shoes\data\JungleBoots19_co.paa"
        };
    };
    class JungleBoots_EMP6 : JungleBoots_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots57_co.paa",
            "iat_retextures\shoes\data\JungleBoots57_co.paa",
            "iat_retextures\shoes\data\JungleBoots57_co.paa"
        };
    };
    class JungleBoots_MC_Black : JungleBoots_ColorBase
    {
        scope = 2;
        color = "MC_Black";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_MC_black_co.paa",
            "iat_retextures\shoes\data\JungleBoots_MC_black_co.paa",
            "iat_retextures\shoes\data\JungleBoots_MC_black_co.paa"
        };
    };
    class JungleBoots_ChocChip : JungleBoots_ColorBase
    {
        scope = 2;
        color = "ChocChip";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_ChocChip_co.paa",
            "iat_retextures\shoes\data\JungleBoots_ChocChip_co.paa",
            "iat_retextures\shoes\data\JungleBoots_ChocChip_co.paa"
        };
    };
    class JungleBoots_ERDL : JungleBoots_ColorBase
    {
        scope = 2;
        color = "ERDL";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_ERDL_co.paa",
            "iat_retextures\shoes\data\JungleBoots_ERDL_co.paa",
            "iat_retextures\shoes\data\JungleBoots_ERDL_co.paa"
        };
    };
    class JungleBoots_M05 : JungleBoots_ColorBase
    {
        scope = 2;
        color = "M05";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_M05_co.paa",
            "iat_retextures\shoes\data\JungleBoots_M05_co.paa",
            "iat_retextures\shoes\data\JungleBoots_M05_co.paa"
        };
    };
    class JungleBoots_MARPAT : JungleBoots_ColorBase
    {
        scope = 2;
        color = "MARPAT";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_MPat_co.paa",
            "iat_retextures\shoes\data\JungleBoots_MPat_co.paa",
            "iat_retextures\shoes\data\JungleBoots_MPat_co.paa"
        };
    };
    class JungleBoots_TigerStripe : JungleBoots_ColorBase
    {
        scope = 2;
        color = "TigerStripe";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_TS_co.paa",
            "iat_retextures\shoes\data\JungleBoots_TS_co.paa",
            "iat_retextures\shoes\data\JungleBoots_TS_co.paa"
        };
    };
    class JungleBoots_CADPAT : JungleBoots_ColorBase
    {
        scope = 2;
        color = "CADPAT";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\JungleBoots_CAD_co.paa",
            "iat_retextures\shoes\data\JungleBoots_CAD_co.paa",
            "iat_retextures\shoes\data\JungleBoots_CAD_co.paa"
        };
    };

    class Sneakers_BabyBlue : Sneakers_ColorBase
    {
        scope = 2;
        color = "BabyBlue";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_BabyBlue_co.paa",
            "iat_retextures\shoes\data\sneakers_BabyBlue_co.paa",
            "iat_retextures\shoes\data\sneakers_BabyBlue_co.paa"
        };
    };
    class Sneakers_Black1 : Sneakers_ColorBase
    {
        scope = 2;
        color = "Black1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_black_co.paa",
            "iat_retextures\shoes\data\sneakers_black_co.paa",
            "iat_retextures\shoes\data\sneakers_black_co.paa"
        };
    };
    class Sneakers_DarkPurple : Sneakers_ColorBase
    {
        scope = 2;
        color = "DarkPurple";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_darkpurp_co.paa",
            "iat_retextures\shoes\data\sneakers_darkpurp_co.paa",
            "iat_retextures\shoes\data\sneakers_darkpurp_co.paa"
        };
    };
    class Sneakers_Lime : Sneakers_ColorBase
    {
        scope = 2;
        color = "Lime";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_lime_co.paa",
            "iat_retextures\shoes\data\sneakers_lime_co.paa",
            "iat_retextures\shoes\data\sneakers_lime_co.paa"
        };
    };
    class Sneakers_Purple : Sneakers_ColorBase
    {
        scope = 2;
        color = "Purple";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_purple_co.paa",
            "iat_retextures\shoes\data\sneakers_purple_co.paa",
            "iat_retextures\shoes\data\sneakers_purple_co.paa"
        };
    };
    class Sneakers_Red1 : Sneakers_ColorBase
    {
        scope = 2;
        color = "Red1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_red_co.paa",
            "iat_retextures\shoes\data\sneakers_red_co.paa",
            "iat_retextures\shoes\data\sneakers_red_co.paa"
        };
    };
    class Sneakers_Salmon : Sneakers_ColorBase
    {
        scope = 2;
        color = "Salmon";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_salmon_co.paa",
            "iat_retextures\shoes\data\sneakers_salmon_co.paa",
            "iat_retextures\shoes\data\sneakers_salmon_co.paa"
        };
    };
    class Sneakers_Tan : Sneakers_ColorBase
    {
        scope = 2;
        color = "Tan";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_tan_co.paa",
            "iat_retextures\shoes\data\sneakers_tan_co.paa",
            "iat_retextures\shoes\data\sneakers_tan_co.paa"
        };
    };
    class Sneakers_WhitePink : Sneakers_ColorBase
    {
        scope = 2;
        color = "WhitePink";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\sneakers_whitepink_co.paa",
            "iat_retextures\shoes\data\sneakers_whitepink_co.paa",
            "iat_retextures\shoes\data\sneakers_whitepink_co.paa"
        };
    };

    class LeatherShoes_Choco : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Choco";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_choco_co.paa"
        };
    };
    class LeatherShoes_Lime : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Lime";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_Lime_co.paa"
        };
    };
    class LeatherShoes_Orange : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_Orange_co.paa"
        };
    };
    class LeatherShoes_Pink : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_Pink_co.paa"
        };
    };
    class LeatherShoes_Purple : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Purple";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_Purple_co.paa"
        };
    };
    class LeatherShoes_Storm : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Storm";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_Storm_co.paa"
        };
    };
    class LeatherShoes_Yellow : LeatherShoes_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\shoes_leathermoccasins_Yellow_co.paa"
        };
    };

    class FeetCover_Improvised_green : FeetCover_Improvised
    {
        scope = 2;
        color = "green";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\shoes\data\feetCover_improvised_green_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_green_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_green_co.paa"
        };
    };
    class FeetCover_Improvised_black : FeetCover_Improvised
    {
        scope = 2;
        color = "black";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\shoes\data\feetCover_improvised_black_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_black_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_black_co.paa"
        };
    };
    class FeetCover_Improvised_orange : FeetCover_Improvised
    {
        scope = 2;
        color = "orange";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\shoes\data\feetCover_improvised_orange_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_orange_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_orange_co.paa"
        };
    };
    class FeetCover_Improvised_blue : FeetCover_Improvised
    {
        scope = 2;
        color = "blue";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\shoes\data\feetCover_improvised_blue_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_blue_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_blue_co.paa"
        };
    };
    class FeetCover_Improvised_Red : FeetCover_Improvised
    {
        scope = 2;
        color = "Red";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\shoes\data\feetCover_improvised_red_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_red_co.paa",
          "iat_retextures\shoes\data\feetCover_improvised_red_co.paa"
        };
    };

    class CombatBoots_GrenadeGreen : CombatBoots_ColorBase
    {
        scope = 2;
        color = "GrenadeGreen";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_grenadegreen_co.paa",
            "iat_retextures\shoes\data\combatboots_grenadegreen_co.paa",
            "iat_retextures\shoes\data\combatboots_grenadegreen_co.paa",
        };
    };
    class CombatBoots_NinjaBlue : CombatBoots_ColorBase
    {
        scope = 2;
        color = "NinjaBlue";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_ninjablue_co.paa",
            "iat_retextures\shoes\data\combatboots_ninjablue_co.paa",
            "iat_retextures\shoes\data\combatboots_ninjablue_co.paa",
        };
    };
    class CombatBoots_NinjaPink : CombatBoots_ColorBase
    {
        scope = 2;
        color = "NinjaPink";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_ninjapink_co.paa",
            "iat_retextures\shoes\data\combatboots_ninjapink_co.paa",
            "iat_retextures\shoes\data\combatboots_ninjapink_co.paa",
        };
    };
    class CombatBoots_NinjaYellow : CombatBoots_ColorBase
    {
        scope = 2;
        color = "NinjaYellow";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_ninjayellow_co.paa",
            "iat_retextures\shoes\data\combatboots_ninjayellow_co.paa",
            "iat_retextures\shoes\data\combatboots_ninjayellow_co.paa",
        };
    };
    class CombatBoots_OdinLemon : CombatBoots_ColorBase
    {
        scope = 2;
        color = "OdinLemon";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_Odinlemon_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinlemon_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinlemon_co.paa",
        };
    };
    class CombatBoots_OdinPetal : CombatBoots_ColorBase
    {
        scope = 2;
        color = "OdinPetal";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_Odinpetal_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinpetal_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinpetal_co.paa",
        };
    };
    class CombatBoots_OdinPurple : CombatBoots_ColorBase
    {
        scope = 2;
        color = "OdinPurple";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_Odinpurple_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinpurple_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinpurple_co.paa",
        };
    };
    class CombatBoots_OdinRed : CombatBoots_ColorBase
    {
        scope = 2;
        color = "OdinRed";
        visibilityModifier = 0.80000001;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\shoes\data\combatboots_Odinred_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinred_co.paa",
            "iat_retextures\shoes\data\combatboots_Odinred_co.paa",
        };
    };
};