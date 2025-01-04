class CfgPatches
{
    class IAT_Retextures_Backpacks
    {
        requiredAddons[] = { "DZ_Characters", "DZ_Characters_Backpacks" };
    };
};

class CfgVehicles
{
    class CourierBag;
    class DryBag_ColorBase;
    class GhillieBushrag_ColorBase;
    class GhillieTop_ColorBase;
    class GhillieSuit_ColorBase;
    class HuntingBag;
    class SmershBag;
    class MountainBag_ColorBase;
    class AssaultBag_ColorBase;
    class TaloonBag_ColorBase;
    class AssaultBag_Ttsko;
    class TortillaBag;
    class AliceBag_ColorBase;
    class CanvasBag_ColorBase;
    class ArmyPouch_ColorBase;

    //==================================================== VANILLA OVERRIDE

    //==================================================== VANILLA RETEXTURES
    class AliceBag_MTP : AliceBag_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb01_co.paa",
            "iat_retextures\backpacks\data\aliceb01_co.paa",
            "iat_retextures\backpacks\data\aliceb01_co.paa"
        };
    };
    class AliceBag_ATAC : AliceBag_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb04_co.paa",
            "iat_retextures\backpacks\data\aliceb04_co.paa",
            "iat_retextures\backpacks\data\aliceb04_co.paa"
        };
    };
    class AliceBag_ATACSFG : AliceBag_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb38_co.paa",
            "iat_retextures\backpacks\data\aliceb38_co.paa",
            "iat_retextures\backpacks\data\aliceb38_co.paa"
        };
    };
    class AliceBag_USNAOR2 : AliceBag_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb09_co.paa",
            "iat_retextures\backpacks\data\aliceb09_co.paa",
            "iat_retextures\backpacks\data\aliceb09_co.paa"
        };
    };
    class AliceBag_USNAOR1 : AliceBag_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb10_co.paa",
            "iat_retextures\backpacks\data\aliceb10_co.paa",
            "iat_retextures\backpacks\data\aliceb10_co.paa"
        };
    };
    class AliceBag_SURPAT : AliceBag_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb12_co.paa",
            "iat_retextures\backpacks\data\aliceb12_co.paa",
            "iat_retextures\backpacks\data\aliceb12_co.paa"
        };
    };
    class AliceBag_MARPATWinter : AliceBag_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb19_co.paa",
            "iat_retextures\backpacks\data\aliceb19_co.paa",
            "iat_retextures\backpacks\data\aliceb19_co.paa"
        };
    };
    class AliceBag_EMP6 : AliceBag_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\aliceb57_co.paa",
            "iat_retextures\backpacks\data\aliceb57_co.paa",
            "iat_retextures\backpacks\data\aliceb57_co.paa"
        };
    };
    class AliceBag_Camo1 : AliceBag_ColorBase
    {
        scope = 2;
        color = "Camo1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\alicebackpack_bdu_camo_co.paa",
            "iat_retextures\backpacks\data\alicebackpack_bdu_camo_co.paa",
            "iat_retextures\backpacks\data\alicebackpack_bdu_camo_co.paa"
        };
    };

    class AssaultBag_Denim : AssaultBag_ColorBase
    {
        scope = 2;
        color = "Denim";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\denbp_co.paa",
            "iat_retextures\backpacks\data\denbp_co.paa",
            "iat_retextures\backpacks\data\denbp_co.paa"
        };
    };
    class AssaultBag_MTP : AssaultBag_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_01_co.paa",
            "iat_retextures\backpacks\data\m53_01_co.paa",
            "iat_retextures\backpacks\data\m53_01_co.paa"
        };
    };
    class AssaultBag_ATAC : AssaultBag_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_04_co.paa",
            "iat_retextures\backpacks\data\m53_04_co.paa",
            "iat_retextures\backpacks\data\m53_04_co.paa"
        };
    };
    class AssaultBag_ATACSFG : AssaultBag_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_38_co.paa",
            "iat_retextures\backpacks\data\m53_38_co.paa",
            "iat_retextures\backpacks\data\m53_38_co.paa"
        };
    };
    class AssaultBag_USNAOR2 : AssaultBag_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_09_co.paa",
            "iat_retextures\backpacks\data\m53_09_co.paa",
            "iat_retextures\backpacks\data\m53_09_co.paa"
        };
    };
    class AssaultBag_USNAOR1 : AssaultBag_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_10_co.paa",
            "iat_retextures\backpacks\data\m53_10_co.paa",
            "iat_retextures\backpacks\data\m53_10_co.paa"
        };
    };
    class AssaultBag_SURPAT : AssaultBag_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_12_co.paa",
            "iat_retextures\backpacks\data\m53_12_co.paa",
            "iat_retextures\backpacks\data\m53_12_co.paa"
        };
    };
    class AssaultBag_MARPATWinter : AssaultBag_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_19_co.paa",
            "iat_retextures\backpacks\data\m53_19_co.paa",
            "iat_retextures\backpacks\data\m53_19_co.paa"
        };
    };
    class AssaultBag_EMP6 : AssaultBag_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\m53_57_co.paa",
            "iat_retextures\backpacks\data\m53_57_co.paa",
            "iat_retextures\backpacks\data\m53_57_co.paa"
        };
    };

    class CourierBag_Black : CourierBag
    {
        scope = 2;
        color = "black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\impcourierbag_black_co.paa",
            "iat_retextures\backpacks\data\impcourierbag_black_co.paa",
            "iat_retextures\backpacks\data\impcourierbag_black_co.paa"
        };
    };

    class DryBag_Pink : DryBag_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\drybag_Pink_co.paa",
            "iat_retextures\backpacks\data\drybag_Pink_co.paa",
            "iat_retextures\backpacks\data\drybag_Pink_co.paa"
        };
    };
    class DryBag_MintBlue : DryBag_ColorBase
    {
        scope = 2;
        color = "MintBlue";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\drybag_mintblue_co.paa",
            "iat_retextures\backpacks\data\drybag_mintblue_co.paa",
            "iat_retextures\backpacks\data\drybag_mintblue_co.paa"
        };
    };
    class DryBag_Espen : DryBag_ColorBase
    {
        scope = 2;
        color = "Espen";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\backpacks\data\drybag_Espen_co.paa",
          "iat_retextures\backpacks\data\drybag_Espen_co.paa",
          "iat_retextures\backpacks\data\drybag_Espen_co.paa"
        };
    };
    class DryBag_Camo : DryBag_ColorBase
    {
        scope = 2;
        color = "Camo";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\backpacks\data\drybag_camo_co.paa",
          "iat_retextures\backpacks\data\drybag_camo_co.paa",
          "iat_retextures\backpacks\data\drybag_camo_co.paa"
        };
    };
    class DryBag_ChernaRussian : DryBag_ColorBase
    {
        scope = 2;
        color = "ChernaRussian";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\backpacks\data\drybag_chernarussian_co.paa",
          "iat_retextures\backpacks\data\drybag_chernarussian_co.paa",
          "iat_retextures\backpacks\data\drybag_chernarussian_co.paa"
        };
    };
    class DryBag_NordicStripe : DryBag_ColorBase
    {
        scope = 2;
        color = "NordicStripe";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\backpacks\data\drybag_nordic_stripe_co.paa",
          "iat_retextures\backpacks\data\drybag_nordic_stripe_co.paa",
          "iat_retextures\backpacks\data\drybag_nordic_stripe_co.paa"
        };
    };
    class DryBag_Soviet : DryBag_ColorBase
    {
        scope = 2;
        color = "Soviet";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\backpacks\data\drybag_soviet_co.paa",
          "iat_retextures\backpacks\data\drybag_soviet_co.paa",
          "iat_retextures\backpacks\data\drybag_soviet_co.paa"
        };
    };
    class DryBag_UnionJack : DryBag_ColorBase
    {
        scope = 2;
        color = "UnionJack";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\backpacks\data\drybag_unionjack_co.paa",
          "iat_retextures\backpacks\data\drybag_unionjack_co.paa",
          "iat_retextures\backpacks\data\drybag_unionjack_co.paa"
        };
    };

    class GhillieBushrag_White : GhillieBushrag_ColorBase
    {
        scope = 2;
        color = "White";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa"
        };
    };
    class GhillieBushrag_Black : GhillieBushrag_ColorBase
    {
        scope = 2;
        color = "Black";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa"
        };
    };
    class GhillieTop_White : GhillieTop_ColorBase
    {
        scope = 2;
        color = "White";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa"
        };
    };
    class GhillieTop_Black : GhillieTop_ColorBase
    {
        scope = 2;
        color = "Black";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa"
        };
    };
    class GhillieSuit_White : GhillieSuit_ColorBase
    {
        scope = 2;
        color = "White";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa"
        };
    };
    class GhillieSuit_Black : GhillieSuit_ColorBase
    {
        scope = 2;
        color = "Black";
        visibilityModifier = 0.69999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa"
        };
    };

    class MountainBag_Black : MountainBag_ColorBase
    {
        scope = 2;
        color = "Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mon_black_co.paa",
            "iat_retextures\backpacks\data\mon_black_co.paa",
            "iat_retextures\backpacks\data\mon_black_co.paa"
        };
    };
    class MountainBag_MTP : MountainBag_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_01_co.paa",
            "iat_retextures\backpacks\data\mountain_01_co.paa",
            "iat_retextures\backpacks\data\mountain_01_co.paa"
        };
    };
    class MountainBag_ATAC : MountainBag_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_04_co.paa",
            "iat_retextures\backpacks\data\mountain_04_co.paa",
            "iat_retextures\backpacks\data\mountain_04_co.paa"
        };
    };
    class MountainBag_ATACSFG : MountainBag_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_38_co.paa",
            "iat_retextures\backpacks\data\mountain_38_co.paa",
            "iat_retextures\backpacks\data\mountain_38_co.paa"
        };
    };
    class MountainBag_USNAOR2 : MountainBag_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_09_co.paa",
            "iat_retextures\backpacks\data\mountain_09_co.paa",
            "iat_retextures\backpacks\data\mountain_09_co.paa"
        };
    };
    class MountainBag_USNAOR1 : MountainBag_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_10_co.paa",
            "iat_retextures\backpacks\data\mountain_10_co.paa",
            "iat_retextures\backpacks\data\mountain_10_co.paa"
        };
    };
    class MountainBag_SURPAT : MountainBag_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_12_co.paa",
            "iat_retextures\backpacks\data\mountain_12_co.paa",
            "iat_retextures\backpacks\data\mountain_12_co.paa"
        };
    };
    class MountainBag_MARPATWinter : MountainBag_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_19_co.paa",
            "iat_retextures\backpacks\data\mountain_19_co.paa",
            "iat_retextures\backpacks\data\mountain_19_co.paa"
        };
    };
    class MountainBag_EMP6 : MountainBag_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountain_57_co.paa",
            "iat_retextures\backpacks\data\mountain_57_co.paa",
            "iat_retextures\backpacks\data\mountain_57_co.paa"
        };
    };
    class MountainBag_Survivor1 : MountainBag_ColorBase
    {
        scope = 2;
        color = "Survivor1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountainbagsurvivor1_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor1_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor1_co.paa"
        };
    };
    class MountainBag_Survivor2 : MountainBag_ColorBase
    {
        scope = 2;
        color = "Survivor2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountainbagsurvivor2_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor2_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor2_co.paa"
        };
    };
    class MountainBag_Survivor3 : MountainBag_ColorBase
    {
        scope = 2;
        color = "Survivor3";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountainbagsurvivor3_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor3_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor3_co.paa"
        };
    };
    class MountainBag_Survivor4 : MountainBag_ColorBase
    {
        scope = 2;
        color = "Survivor4";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\mountainbagsurvivor4_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor4_co.paa",
            "iat_retextures\backpacks\data\mountainbagsurvivor4_co.paa"
        };
    };

    class SmershBag_White : SmershBag
    {
        scope = 2;
        color = "White";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\smersh_white_co.paa",
            "iat_retextures\backpacks\data\smersh_white_co.paa",
            "iat_retextures\backpacks\data\smersh_white_co.paa"
        };
    };
    class SmershBag_Black : SmershBag
    {
        scope = 2;
        color = "Black";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\smersh_black_co.paa",
            "iat_retextures\backpacks\data\smersh_black_co.paa",
            "iat_retextures\backpacks\data\smersh_black_co.paa"
        };
    };
    class SmershBag_Green : SmershBag
    {
        scope = 2;
        color = "Green";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\smersh_green_co.paa",
            "iat_retextures\backpacks\data\smersh_green_co.paa",
            "iat_retextures\backpacks\data\smersh_green_co.paa"
        };
    };
    class SmershBag_Tan : SmershBag
    {
        scope = 2;
        color = "Tan";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\smersh_tan_co.paa",
            "iat_retextures\backpacks\data\smersh_tan_co.paa",
            "iat_retextures\backpacks\data\smersh_tan_co.paa"
        };
    };
    class SmershBag_NBC : SmershBag
    {
        scope = 2;
        color = "NBC";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_NBC_CO.paa",
            "iat_retextures\backpacks\data\Smersh_NBC_CO.paa",
            "iat_retextures\backpacks\data\Smersh_NBC_CO.paa"
        };
    };
    class SmershBag_Red : SmershBag
    {
        scope = 2;
        color = "Red";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_Red_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Red_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Red_CO.paa"
        };
    };
    class SmershBag_Purple : SmershBag
    {
        scope = 2;
        color = "Purple";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_Purple_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Purple_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Purple_CO.paa"
        };
    };
    class SmershBag_Blue : SmershBag
    {
        scope = 2;
        color = "Blue";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_Blue_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Blue_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Blue_CO.paa"
        };
    };
    class SmershBag_Pink : SmershBag
    {
        scope = 2;
        color = "Pink";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_Pink_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Pink_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Pink_CO.paa"
        };
    };
    class SmershBag_Olive : SmershBag
    {
        scope = 2;
        color = "Olive";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_Olive_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Olive_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Olive_CO.paa"
        };
    };
    class SmershBag_Storm : SmershBag
    {
        scope = 2;
        color = "Storm";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\Smersh_Storm_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Storm_CO.paa",
            "iat_retextures\backpacks\data\Smersh_Storm_CO.paa"
        };
    };

    class TaloonBag_Black1 : TaloonBag_ColorBase
    {
        scope = 2;
        color = "Black1";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\taloon_bl_co.paa",
            "iat_retextures\backpacks\data\taloon_bl_co.paa",
            "iat_retextures\backpacks\data\taloon_bl_co.paa"
        };
    };
    class TaloonBag_Black2 : TaloonBag_ColorBase
    {
        scope = 2;
        color = "Black2";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\taloon_bl1_co.paa",
            "iat_retextures\backpacks\data\taloon_bl1_co.paa",
            "iat_retextures\backpacks\data\taloon_bl1_co.paa"
        };
    };

    class TortillaBag_MTP : TortillaBag
    {
        scope = 2;
        color = "MTP";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila01_co.paa",
            "iat_retextures\backpacks\data\tortila01_co.paa",
            "iat_retextures\backpacks\data\tortila01_co.paa"
        };
    };
    class TortillaBag_ATAC : TortillaBag
    {
        scope = 2;
        color = "ATAC";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila04_co.paa",
            "iat_retextures\backpacks\data\tortila04_co.paa",
            "iat_retextures\backpacks\data\tortila04_co.paa"
        };
    };
    class TortillaBag_ATACSFG : TortillaBag
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila38_co.paa",
            "iat_retextures\backpacks\data\tortila38_co.paa",
            "iat_retextures\backpacks\data\tortila38_co.paa"
        };
    };
    class TortillaBag_USNAOR2 : TortillaBag
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila09_co.paa",
            "iat_retextures\backpacks\data\tortila09_co.paa",
            "iat_retextures\backpacks\data\tortila09_co.paa"
        };
    };
    class TortillaBag_USNAOR1 : TortillaBag
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila10_co.paa",
            "iat_retextures\backpacks\data\tortila10_co.paa",
            "iat_retextures\backpacks\data\tortila10_co.paa"
        };
    };
    class TortillaBag_SURPAT : TortillaBag
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila12_co.paa",
            "iat_retextures\backpacks\data\tortila12_co.paa",
            "iat_retextures\backpacks\data\tortila12_co.paa"
        };
    };
    class TortillaBag_MARPATWinter : TortillaBag
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila19_co.paa",
            "iat_retextures\backpacks\data\tortila19_co.paa",
            "iat_retextures\backpacks\data\tortila19_co.paa"
        };
    };
    class TortillaBag_EMP6 : TortillaBag
    {
        scope = 2;
        color = "EMP6";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\tortila57_co.paa",
            "iat_retextures\backpacks\data\tortila57_co.paa",
            "iat_retextures\backpacks\data\tortila57_co.paa"
        };
    };

    class HuntingBag_Mawlee : HuntingBag
    {
        scope = 2;
        color = "Mawlee";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_mawlee_co.paa",
            "iat_retextures\backpacks\data\hunting_mawlee_co.paa",
            "iat_retextures\backpacks\data\hunting_mawlee_co.paa"
        };
    };
    class HuntingBag_Black : HuntingBag
    {
        scope = 2;
        color = "Black";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_black_co.paa",
            "iat_retextures\backpacks\data\hunting_black_co.paa",
            "iat_retextures\backpacks\data\hunting_black_co.paa"
        };
    };
    class HuntingBag_Gorka : HuntingBag
    {
        scope = 2;
        color = "Gorka";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_gorka_co.paa",
            "iat_retextures\backpacks\data\hunting_gorka_co.paa",
            "iat_retextures\backpacks\data\hunting_gorka_co.paa"
        };
    };
    class HuntingBag_MTP : HuntingBag
    {
        scope = 2;
        color = "MTP";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB01_co.paa",
            "iat_retextures\backpacks\data\huntingB01_co.paa",
            "iat_retextures\backpacks\data\huntingB01_co.paa"
        };
    };
    class HuntingBag_ATAC : HuntingBag
    {
        scope = 2;
        color = "ATAC";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB04_co.paa",
            "iat_retextures\backpacks\data\huntingB04_co.paa",
            "iat_retextures\backpacks\data\huntingB04_co.paa"
        };
    };
    class HuntingBag_ATACSFG : HuntingBag
    {
        scope = 2;
        color = "ATACSFG";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB38_co.paa",
            "iat_retextures\backpacks\data\huntingB38_co.paa",
            "iat_retextures\backpacks\data\huntingB38_co.paa"
        };
    };
    class HuntingBag_USNAOR2 : HuntingBag
    {
        scope = 2;
        color = "USNAOR2";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB09_co.paa",
            "iat_retextures\backpacks\data\huntingB09_co.paa",
            "iat_retextures\backpacks\data\huntingB09_co.paa"
        };
    };
    class HuntingBag_USNAOR1 : HuntingBag
    {
        scope = 2;
        color = "USNAOR1";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB10_co.paa",
            "iat_retextures\backpacks\data\huntingB10_co.paa",
            "iat_retextures\backpacks\data\huntingB10_co.paa"
        };
    };
    class HuntingBag_SURPAT : HuntingBag
    {
        scope = 2;
        color = "SURPAT";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB12_co.paa",
            "iat_retextures\backpacks\data\huntingB12_co.paa",
            "iat_retextures\backpacks\data\huntingB12_co.paa"
        };
    };
    class HuntingBag_MARPATWinter : HuntingBag
    {
        scope = 2;
        color = "MARPATWinter";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB19_co.paa",
            "iat_retextures\backpacks\data\huntingB19_co.paa",
            "iat_retextures\backpacks\data\huntingB19_co.paa"
        };
    };
    class HuntingBag_EMP6 : HuntingBag
    {
        scope = 2;
        color = "EMP6";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\huntingB57_co.paa",
            "iat_retextures\backpacks\data\huntingB57_co.paa",
            "iat_retextures\backpacks\data\huntingB57_co.paa"
        };
    };
    class HuntingBag_Blue : HuntingBag
    {
        scope = 2;
        color = "Blue";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_blu_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_blu_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_blu_co.paa"
        };
    };
    class HuntingBag_Red : HuntingBag
    {
        scope = 2;
        color = "Red";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_red_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_red_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_red_co.paa"
        };
    };
    class HuntingBag_Yellow : HuntingBag
    {
        scope = 2;
        color = "Yellow";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_yellow_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_yellow_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_fjallraven_yellow_co.paa"
        };
    };
    class HuntingBag_Travel : HuntingBag
    {
        scope = 2;
        color = "Travel";
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\hunting_bag_travel_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_travel_co.paa",
            "iat_retextures\backpacks\data\hunting_bag_travel_co.paa"
        };
    };

    class CanvasBag_WaldoRescue : CanvasBag_ColorBase
    {
        scope = 2;
        color = "WaldoRescue";
        descriptionShort = "Bag for the search and rescue personnel";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\CanvasBag_Rescue_co.paa",
            "iat_retextures\backpacks\data\CanvasBag_Rescue_co.paa",
            "iat_retextures\backpacks\data\CanvasBag_Rescue_co.paa"
        };
    };

    class ArmyPouch_Drugs : ArmyPouch_ColorBase
    {
        scope = 2;
        color = "Drugs";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\armypouch_drugs_co.paa",
            "iat_retextures\backpacks\data\armypouch_drugs_co.paa",
            "iat_retextures\backpacks\data\armypouch_drugs_co.paa"
        };
    };
    class ArmyPouch_Grenade : ArmyPouch_ColorBase
    {
        scope = 2;
        color = "Grenade";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\armypouch_granade_co.paa",
            "iat_retextures\backpacks\data\armypouch_granade_co.paa",
            "iat_retextures\backpacks\data\armypouch_granade_co.paa"
        };
    };
    class ArmyPouch_Kitty : ArmyPouch_ColorBase
    {
        scope = 2;
        color = "Kitty";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\armypouch_Kitty_co.paa",
            "iat_retextures\backpacks\data\armypouch_Kitty_co.paa",
            "iat_retextures\backpacks\data\armypouch_Kitty_co.paa"
        };
    };
    class ArmyPouch_Meat : ArmyPouch_ColorBase
    {
        scope = 2;
        color = "Meat";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\armypouch_meat_co.paa",
            "iat_retextures\backpacks\data\armypouch_meat_co.paa",
            "iat_retextures\backpacks\data\armypouch_meat_co.paa"
        };
    };
    class ArmyPouch_Tomato : ArmyPouch_ColorBase
    {
        scope = 2;
        color = "Tomato";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\armypouch_tomato_co.paa",
            "iat_retextures\backpacks\data\armypouch_tomato_co.paa",
            "iat_retextures\backpacks\data\armypouch_tomato_co.paa"
        };
    };

};
