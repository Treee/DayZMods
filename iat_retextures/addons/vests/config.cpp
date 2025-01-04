class CfgPatches
{
    class IAT_Retextures_Vests
    {
        requiredAddons[] = { "DZ_Characters", "DZ_Characters_Vests" };
    };
};
class CfgVehicles
{
    class PoliceVest;
    class PlateCarrierVest;
    class PressVest_ColorBase;
    class ChestHolster;
    class HighCapacityVest_ColorBase;
    class PlateCarrierPouches;
    class SmershVest;
    class PlateCarrierHolster;
    class UKAssVest_ColorBase;
    class HuntingVest;
    class LeatherStorageVest_ColorBase;

    //==================================================== VANILLA RETEXTURES
    class PlateCarrierVest_ThirstyDevil : PlateCarrierVest
    {
        scope = 2;
        color = "ThirstyDevil";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_ttd_co.paa",
            "iat_retextures\vests\data\ballisticvest_ttd_co.paa",
            "iat_retextures\vests\data\ballisticvest_ttd_co.paa"
        };
    };
    class PlateCarrierVest_Trader : PlateCarrierVest
    {
        scope = 2;
        color = "Trader";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_trader_co.paa",
            "iat_retextures\vests\data\ballisticvest_trader_co.paa",
            "iat_retextures\vests\data\ballisticvest_trader_co.paa"
        };
    };
    class PlateCarrierVest_Black : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest_black_co.paa",
            "iat_retextures\vests\data\ballisticvest_black_co.paa",
            "iat_retextures\vests\data\ballisticvest_black_co.paa"
        };
    };
    class PlateCarrierVest_White : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest_white_co.paa",
            "iat_retextures\vests\data\ballisticvest_white_co.paa",
            "iat_retextures\vests\data\ballisticvest_white_co.paa"
        };
    };
    class PlateCarrierVest_Pseudo : PlateCarrierVest
    {
        scope = 2;
        color = "Pseudo";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa",
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa",
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa"
        };
    };
    class PlateCarrierVest_MTP : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest01_co.paa",
            "iat_retextures\vests\data\ballisticvest01_co.paa",
            "iat_retextures\vests\data\ballisticvest01_co.paa"
        };
    };
    class PlateCarrierVest_ATAC : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest04_co.paa",
            "iat_retextures\vests\data\ballisticvest04_co.paa",
            "iat_retextures\vests\data\ballisticvest04_co.paa"
        };
    };
    class PlateCarrierVest_ATACSFG : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest38_co.paa",
            "iat_retextures\vests\data\ballisticvest38_co.paa",
            "iat_retextures\vests\data\ballisticvest38_co.paa"
        };
    };
    class PlateCarrierVest_USNAOR2 : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest09_co.paa",
            "iat_retextures\vests\data\ballisticvest09_co.paa",
            "iat_retextures\vests\data\ballisticvest09_co.paa"
        };
    };
    class PlateCarrierVest_USNAOR1 : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest10_co.paa",
            "iat_retextures\vests\data\ballisticvest10_co.paa",
            "iat_retextures\vests\data\ballisticvest10_co.paa"
        };
    };
    class PlateCarrierVest_SURPAT : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest12_co.paa",
            "iat_retextures\vests\data\ballisticvest12_co.paa",
            "iat_retextures\vests\data\ballisticvest12_co.paa"
        };
    };
    class PlateCarrierVest_MARPATWinter : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest19_co.paa",
            "iat_retextures\vests\data\ballisticvest19_co.paa",
            "iat_retextures\vests\data\ballisticvest19_co.paa"
        };
    };
    class PlateCarrierVest_EMP6 : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest57_co.paa",
            "iat_retextures\vests\data\ballisticvest57_co.paa",
            "iat_retextures\vests\data\ballisticvest57_co.paa"
        };
    };
    class PlateCarrierVest_Lavender : PlateCarrierVest
    {
        scope = 2;
        color = "Lavender";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa",
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa",
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa"
        };
    };
    class PlateCarrierVest_Petal : PlateCarrierVest
    {
        scope = 2;
        color = "Petal";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_petal_co.paa",
            "iat_retextures\vests\data\ballisticvest_petal_co.paa",
            "iat_retextures\vests\data\ballisticvest_petal_co.paa"
        };
    };
    class PlateCarrierVest_Stone : PlateCarrierVest
    {
        scope = 2;
        color = "Stone";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_stone_co.paa",
            "iat_retextures\vests\data\ballisticvest_stone_co.paa",
            "iat_retextures\vests\data\ballisticvest_stone_co.paa"
        };
    };
    class PlateCarrierVest_Storm : PlateCarrierVest
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
            "iat_retextures\vests\data\ballisticvest_storm_co.paa",
            "iat_retextures\vests\data\ballisticvest_storm_co.paa",
            "iat_retextures\vests\data\ballisticvest_storm_co.paa"
        };
    };
    class PlateCarrierVest_Sunny : PlateCarrierVest
    {
        scope = 2;
        color = "Sunny";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa",
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa",
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa"
        };
    };

    class PlateCarrierHolster_White : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest_white_co.paa",
            "iat_retextures\vests\data\ballisticvest_white_co.paa",
            "iat_retextures\vests\data\ballisticvest_white_co.paa"
        };
    };
    class PlateCarrierHolster_Pseudo : PlateCarrierHolster
    {
        scope = 2;
        color = "Pseudo";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa",
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa",
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa"
        };
    };
    class PlateCarrierHolster_Tan : PlateCarrierHolster
    {
        scope = 2;
        color = "Tan";
        displayName = "Tan Holster";
        descriptionShort = "Tan Holster";
        hiddenSelections[] =
        {
            "zbytek",
            "camoGround"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\Holster_Tan_CO.paa",
            "iat_retextures\vests\data\Holster_Tan_CO.paa"
        };
    };
    class PlateCarrierHolster_Green1 : PlateCarrierHolster
    {
        scope = 2;
        color = "Green1";
        displayName = "Green Holster";
        descriptionShort = "Green Holster";
        hiddenSelections[] =
        {
            "zbytek",
            "camoGround"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\Holster_Green_CO.paa",
            "iat_retextures\vests\data\Holster_Green_CO.paa"
        };
    };
    class PlateCarrierHolster_Black1 : PlateCarrierHolster
    {
        scope = 2;
        color = "Black1";
        displayName = "Black Holster";
        descriptionShort = "Black Holster";
        hiddenSelections[] =
        {
            "zbytek",
            "camoGround"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\Holster_Black_CO.paa",
            "iat_retextures\vests\data\Holster_Black_CO.paa"
        };
    };
    class PlateCarrierHolster_Lavender : PlateCarrierHolster
    {
        scope = 2;
        color = "Lavender";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa",
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa",
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa"
        };
    };
    class PlateCarrierHolster_Petal : PlateCarrierHolster
    {
        scope = 2;
        color = "Petal";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_petal_co.paa",
            "iat_retextures\vests\data\ballisticvest_petal_co.paa",
            "iat_retextures\vests\data\ballisticvest_petal_co.paa"
        };
    };
    class PlateCarrierHolster_Stone : PlateCarrierHolster
    {
        scope = 2;
        color = "Stone";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_stone_co.paa",
            "iat_retextures\vests\data\ballisticvest_stone_co.paa",
            "iat_retextures\vests\data\ballisticvest_stone_co.paa"
        };
    };
    class PlateCarrierHolster_Storm : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest_storm_co.paa",
            "iat_retextures\vests\data\ballisticvest_storm_co.paa",
            "iat_retextures\vests\data\ballisticvest_storm_co.paa"
        };
    };
    class PlateCarrierHolster_Sunny : PlateCarrierHolster
    {
        scope = 2;
        color = "Sunny";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa",
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa",
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa"
        };
    };
    class PlateCarrierHolster_MTP : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest01_co.paa",
            "iat_retextures\vests\data\ballisticvest01_co.paa",
            "iat_retextures\vests\data\ballisticvest01_co.paa",
        };
    };
    class PlateCarrierHolster_ATAC : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest04_co.paa",
            "iat_retextures\vests\data\ballisticvest04_co.paa",
            "iat_retextures\vests\data\ballisticvest04_co.paa",
        };
    };
    class PlateCarrierHolster_ATACSFG : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest38_co.paa",
            "iat_retextures\vests\data\ballisticvest38_co.paa",
            "iat_retextures\vests\data\ballisticvest38_co.paa",
        };
    };
    class PlateCarrierHolster_USNAOR2 : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest09_co.paa",
            "iat_retextures\vests\data\ballisticvest09_co.paa",
            "iat_retextures\vests\data\ballisticvest09_co.paa",
        };
    };
    class PlateCarrierHolster_USNAOR1 : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest10_co.paa",
            "iat_retextures\vests\data\ballisticvest10_co.paa",
            "iat_retextures\vests\data\ballisticvest10_co.paa",
        };
    };
    class PlateCarrierHolster_SURPAT : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest12_co.paa",
            "iat_retextures\vests\data\ballisticvest12_co.paa",
            "iat_retextures\vests\data\ballisticvest12_co.paa",
        };
    };
    class PlateCarrierHolster_MARPATWinter : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest19_co.paa",
            "iat_retextures\vests\data\ballisticvest19_co.paa",
            "iat_retextures\vests\data\ballisticvest19_co.paa",
        };
    };
    class PlateCarrierHolster_ThirstyDevil : PlateCarrierHolster
    {
        scope = 2;
        color = "ThirstyDevil";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TTD_vest_co.paa",
            "iat_retextures\vests\data\TTD_vest_co.paa",
            "iat_retextures\vests\data\TTD_vest_co.paa",
        };
    };
    class PlateCarrierHolster_EMP6 : PlateCarrierHolster
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
            "iat_retextures\vests\data\ballisticvest57_co.paa",
            "iat_retextures\vests\data\ballisticvest57_co.paa",
            "iat_retextures\vests\data\ballisticvest57_co.paa",
        };
    };

    class PlateCarrierPouches_White : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest_white_co.paa",
            "iat_retextures\vests\data\ballisticvest_white_co.paa",
            "iat_retextures\vests\data\ballisticvest_white_co.paa"
        };
    };
    class PlateCarrierPouches_Pseudo : PlateCarrierPouches
    {
        scope = 2;
        color = "Pseudo";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa",
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa",
            "iat_retextures\vests\data\ballisticvest_pseudo_co.paa"
        };
    };
    class PlateCarrierPouches_Tan : PlateCarrierPouches
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
            "iat_retextures\vests\data\Holster_Tan_CO.paa",
            "iat_retextures\vests\data\Holster_Tan_CO.paa",
            "iat_retextures\vests\data\Holster_Tan_CO.paa"
        };
    };
    class PlateCarrierPouches_Green1 : PlateCarrierPouches
    {
        scope = 2;
        color = "Green1";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\Holster_Green_CO.paa",
            "iat_retextures\vests\data\Holster_Green_CO.paa",
            "iat_retextures\vests\data\Holster_Green_CO.paa"
        };
    };
    class PlateCarrierPouches_Black1 : PlateCarrierPouches
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
            "iat_retextures\vests\data\Holster_Black_CO.paa",
            "iat_retextures\vests\data\Holster_Black_CO.paa",
            "iat_retextures\vests\data\Holster_Black_CO.paa"
        };
    };
    class PlateCarrierPouches_Lavender : PlateCarrierPouches
    {
        scope = 2;
        color = "Lavender";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa",
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa",
            "iat_retextures\vests\data\ballisticvest_lavender_co.paa"
        };
    };
    class PlateCarrierPouches_Petal : PlateCarrierPouches
    {
        scope = 2;
        color = "Petal";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_petal_co.paa",
            "iat_retextures\vests\data\ballisticvest_petal_co.paa",
            "iat_retextures\vests\data\ballisticvest_petal_co.paa"
        };
    };
    class PlateCarrierPouches_Stone : PlateCarrierPouches
    {
        scope = 2;
        color = "Stone";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_stone_co.paa",
            "iat_retextures\vests\data\ballisticvest_stone_co.paa",
            "iat_retextures\vests\data\ballisticvest_stone_co.paa"
        };
    };
    class PlateCarrierPouches_Storm : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest_storm_co.paa",
            "iat_retextures\vests\data\ballisticvest_storm_co.paa",
            "iat_retextures\vests\data\ballisticvest_storm_co.paa"
        };
    };
    class PlateCarrierPouches_Sunny : PlateCarrierPouches
    {
        scope = 2;
        color = "Sunny";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa",
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa",
            "iat_retextures\vests\data\ballisticvest_sunny_co.paa"
        };
    };
    class PlateCarrierPouches_MTP : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest01_co.paa",
            "iat_retextures\vests\data\ballisticvest01_co.paa",
            "iat_retextures\vests\data\ballisticvest01_co.paa",
        };
    };
    class PlateCarrierPouches_ATAC : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest04_co.paa",
            "iat_retextures\vests\data\ballisticvest04_co.paa",
            "iat_retextures\vests\data\ballisticvest04_co.paa",
        };
    };
    class PlateCarrierPouches_ATACSFG : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest38_co.paa",
            "iat_retextures\vests\data\ballisticvest38_co.paa",
            "iat_retextures\vests\data\ballisticvest38_co.paa",
        };
    };
    class PlateCarrierPouches_USNAOR2 : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest09_co.paa",
            "iat_retextures\vests\data\ballisticvest09_co.paa",
            "iat_retextures\vests\data\ballisticvest09_co.paa",
        };
    };
    class PlateCarrierPouches_USNAOR1 : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest10_co.paa",
            "iat_retextures\vests\data\ballisticvest10_co.paa",
            "iat_retextures\vests\data\ballisticvest10_co.paa",
        };
    };
    class PlateCarrierPouches_SURPAT : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest12_co.paa",
            "iat_retextures\vests\data\ballisticvest12_co.paa",
            "iat_retextures\vests\data\ballisticvest12_co.paa",
        };
    };
    class PlateCarrierPouches_MARPATWinter : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest19_co.paa",
            "iat_retextures\vests\data\ballisticvest19_co.paa",
            "iat_retextures\vests\data\ballisticvest19_co.paa",
        };
    };
    class PlateCarrierPouches_EMP6 : PlateCarrierPouches
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
            "iat_retextures\vests\data\ballisticvest57_co.paa",
            "iat_retextures\vests\data\ballisticvest57_co.paa",
            "iat_retextures\vests\data\ballisticvest57_co.paa",
        };
    };
    class PlateCarrierPouches_ThirstyDevil : PlateCarrierPouches
    {
        scope = 2;
        color = "ThirstyDevil";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TTD_vest_co.paa",
            "iat_retextures\vests\data\TTD_vest_co.paa",
            "iat_retextures\vests\data\TTD_vest_co.paa",
        };
    };

    class SmershVest_White : SmershVest
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
    class SmershVest_Black : SmershVest
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
    class SmershVest_Green : SmershVest
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
    class SmershVest_Tan : SmershVest
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
    class SmershVest_Red : SmershVest
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
    class SmershVest_Purple : SmershVest
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
    class SmershVest_Blue : SmershVest
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
    class SmershVest_Pink : SmershVest
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
    class SmershVest_Olive : SmershVest
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
    class SmershVest_Storm : SmershVest
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

    class PressVest_Black : PressVest_ColorBase
    {
        scope = 2;
        color = "Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\pressvest_black_co.paa",
            "iat_retextures\vests\data\pressvest_black_co.paa",
            "iat_retextures\vests\data\pressvest_black_co.paa"
        };
    };
    class PressVest_ATFBlue : PressVest_ColorBase
    {
        scope = 2;
        color = "ATFBlue";
        displayName = "ATF Press Vest";
        descriptionShort = "A press vest with the letters ATF embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\atf_pressvest_blue_co.paa",
            "iat_retextures\vests\data\atf_pressvest_blue_co.paa",
            "iat_retextures\vests\data\atf_pressvest_blue_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat"
        };
    };
    class PressVest_CIABlue : PressVest_ColorBase
    {
        scope = 2;
        color = "CIABlue";
        displayName = "CIA Press Vest";
        descriptionShort = "A press vest with the letters CIA embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\cia_pressvest_blue_co.paa",
            "iat_retextures\vests\data\cia_pressvest_blue_co.paa",
            "iat_retextures\vests\data\cia_pressvest_blue_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat"
        };
    };
    class PressVest_FBIBlue : PressVest_ColorBase
    {
        scope = 2;
        color = "FBIBlue";
        displayName = "FBI Press Vest";
        descriptionShort = "A vest with the letters FBI embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\fbi_pressvest_blue_co.paa",
            "iat_retextures\vests\data\fbi_pressvest_blue_co.paa",
            "iat_retextures\vests\data\fbi_pressvest_blue_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat"
        };
    };
    class PressVest_MTP : PressVest_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest01_co.paa",
            "iat_retextures\vests\data\PressVest01_co.paa",
            "iat_retextures\vests\data\PressVest01_co.paa"
        };
    };
    class PressVest_ATAC : PressVest_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest05_co.paa",
            "iat_retextures\vests\data\PressVest05_co.paa",
            "iat_retextures\vests\data\PressVest05_co.paa"
        };
    };
    class PressVest_ATACSFG : PressVest_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest39_co.paa",
            "iat_retextures\vests\data\PressVest39_co.paa",
            "iat_retextures\vests\data\PressVest39_co.paa"
        };
    };
    class PressVest_USNAOR2 : PressVest_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest10_co.paa",
            "iat_retextures\vests\data\PressVest10_co.paa",
            "iat_retextures\vests\data\PressVest10_co.paa"
        };
    };
    class PressVest_USNAOR1 : PressVest_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest11_co.paa",
            "iat_retextures\vests\data\PressVest11_co.paa",
            "iat_retextures\vests\data\PressVest11_co.paa"
        };
    };
    class PressVest_SURPAT : PressVest_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest13_co.paa",
            "iat_retextures\vests\data\PressVest13_co.paa",
            "iat_retextures\vests\data\PressVest13_co.paa"
        };
    };
    class PressVest_MARPATWinter : PressVest_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest20_co.paa",
            "iat_retextures\vests\data\PressVest20_co.paa",
            "iat_retextures\vests\data\PressVest20_co.paa"
        };
    };
    class PressVest_EMP6 : PressVest_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\PressVest58_co.paa",
            "iat_retextures\vests\data\PressVest58_co.paa",
            "iat_retextures\vests\data\PressVest58_co.paa"
        };
    };
    class PressVest_NoLetters : PressVest_ColorBase
    {
        scope = 2;
        color = "NoLetters";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\pressvest_blue_noletters_co.paa",
            "iat_retextures\vests\data\pressvest_blue_noletters_co.paa",
            "iat_retextures\vests\data\pressvest_blue_noletters_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat",
            "iat_retextures\vests\data\pressvest.rvmat"
        };
    };

    class UKAssVest_White : UKAssVest_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\ukassvest_white_co.paa",
            "iat_retextures\vests\data\ukassvest_white_co.paa",
            "iat_retextures\vests\data\ukassvest_white_co.paa"
        };
    };

    class PoliceVest_Sheriff : PoliceVest
    {
        scope = 2;
        color = "Sheriff";
        displayName = "Sheriff Vest";
        descriptionShort = "Hackcock Sheriffs Department Vest";
        heatIsolation = 0.60000002;
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\policevest_co.paa",
            "iat_retextures\vests\data\policevest_co.paa",
            "iat_retextures\vests\data\policevest_co.paa"
        };
    };
    class PoliceVest_ATF : PoliceVest
    {
        scope = 2;
        color = "ATF";
        displayName = "ATF Police Vest";
        descriptionShort = "A police vest with the letters ATF embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\atf_policevest_co.paa",
            "iat_retextures\vests\data\atf_policevest_co.paa",
            "iat_retextures\vests\data\atf_policevest_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat"
        };
    };
    class PoliceVest_CIA : PoliceVest
    {
        scope = 2;
        color = "CIA";
        displayName = "CIA Police Vest";
        descriptionShort = "A police vest with the letters CIA embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\cia_policevest_co.paa",
            "iat_retextures\vests\data\cia_policevest_co.paa",
            "iat_retextures\vests\data\cia_policevest_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat"
        };
    };
    class PoliceVest_FBI : PoliceVest
    {
        scope = 2;
        color = "FBI";
        displayName = "FBI Police Vest";
        descriptionShort = "A vest with the letters FBI embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\fbi_policevest_co.paa",
            "iat_retextures\vests\data\fbi_policevest_co.paa",
            "iat_retextures\vests\data\fbi_policevest_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat"
        };
    };
    class PoliceVest_NoLetters : PoliceVest
    {
        scope = 2;
        color = "NoLetters";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\policevest_noletters_co.paa",
            "iat_retextures\vests\data\policevest_noletters_co.paa",
            "iat_retextures\vests\data\policevest_noletters_co.paa"
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat",
            "iat_retextures\vests\data\policevest.rvmat"
        };
    };

    class ChestHolster_Black : ChestHolster
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
            "iat_retextures\vests\data\chest_holster_black_co.paa",
            "iat_retextures\vests\data\chest_holster_black_co.paa",
            "iat_retextures\vests\data\chest_holster_black_co.paa"
        };
    };
    class ChestHolster_White : ChestHolster
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
            "iat_retextures\vests\data\chest_holster_white_co.paa",
            "iat_retextures\vests\data\chest_holster_white_co.paa",
            "iat_retextures\vests\data\chest_holster_white_co.paa"
        };
    };

    class HighCapacityVest_Olive : HighCapacityVest_ColorBase
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
            "iat_retextures\vests\data\tacticalvest_olive_co.paa",
            "iat_retextures\vests\data\tacticalvest_olive_co.paa",
            "iat_retextures\vests\data\tacticalvest_olive_co.paa"
        };
    };
    class HighCapacityVest_ATFBlack : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "ATFBlack";
        displayName = "ATF Black Vest";
        descriptionShort = "A vest with the letters ATF embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\atf_tacticalvest2_black_co.paa",
            "iat_retextures\vests\data\atf_tacticalvest2_black_co.paa",
            "iat_retextures\vests\data\atf_tacticalvest2_black_co.paa"
        };
    };
    class HighCapacityVest_ATFOlive : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "ATFOlive";
        displayName = "ATF Olive Vest";
        descriptionShort = "A vest with the letters ATF embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\atf_tacticalvest2_olive_co.paa",
            "iat_retextures\vests\data\atf_tacticalvest2_olive_co.paa",
            "iat_retextures\vests\data\atf_tacticalvest2_olive_co.paa"
        };
    };
    class HighCapacityVest_CIABlack : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "CIABlack";
        displayName = "CIA Black Vest";
        descriptionShort = "A vest with the letters CIA embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\cia_tacticalvest2_black_co.paa",
            "iat_retextures\vests\data\cia_tacticalvest2_black_co.paa",
            "iat_retextures\vests\data\cia_tacticalvest2_black_co.paa"
        };
    };
    class HighCapacityVest_CIAOlive : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "CIAOlive";
        displayName = "CIA Olive Vest";
        descriptionShort = "A vest with the letters CIA embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\cia_tacticalvest2_olive_co.paa",
            "iat_retextures\vests\data\cia_tacticalvest2_olive_co.paa",
            "iat_retextures\vests\data\cia_tacticalvest2_olive_co.paa"
        };
    };
    class HighCapacityVest_FBIBlack : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "FBIBlack";
        displayName = "FBI Black Vest";
        descriptionShort = "A vest with the letters FBI embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\fbi_tacticalvest2_black_co.paa",
            "iat_retextures\vests\data\fbi_tacticalvest2_black_co.paa",
            "iat_retextures\vests\data\fbi_tacticalvest2_black_co.paa"
        };
    };
    class HighCapacityVest_FBIOlive : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "FBIOlive";
        displayName = "FBI Olive Vest";
        descriptionShort = "A vest with the letters FBI embroidered on the front and back.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\fbi_tacticalvest2_olive_co.paa",
            "iat_retextures\vests\data\fbi_tacticalvest2_olive_co.paa",
            "iat_retextures\vests\data\fbi_tacticalvest2_olive_co.paa"
        };
    };
    class HighCapacityVest_MTP : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest03_co.paa",
            "iat_retextures\vests\data\TacticalVest03_co.paa",
            "iat_retextures\vests\data\TacticalVest03_co.paa"
        };
    };
    class HighCapacityVest_ATAC : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest05_co.paa",
            "iat_retextures\vests\data\TacticalVest05_co.paa",
            "iat_retextures\vests\data\TacticalVest05_co.paa"
        };
    };
    class HighCapacityVest_ATACSFG : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest39_co.paa",
            "iat_retextures\vests\data\TacticalVest39_co.paa",
            "iat_retextures\vests\data\TacticalVest39_co.paa"
        };
    };
    class HighCapacityVest_USNAOR2 : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest10_co.paa",
            "iat_retextures\vests\data\TacticalVest10_co.paa",
            "iat_retextures\vests\data\TacticalVest10_co.paa"
        };
    };
    class HighCapacityVest_USNAOR1 : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest11_co.paa",
            "iat_retextures\vests\data\TacticalVest11_co.paa",
            "iat_retextures\vests\data\TacticalVest11_co.paa"
        };
    };
    class HighCapacityVest_SURPAT : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest13_co.paa",
            "iat_retextures\vests\data\TacticalVest13_co.paa",
            "iat_retextures\vests\data\TacticalVest13_co.paa"
        };
    };
    class HighCapacityVest_MARPATWinter : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest20_co.paa",
            "iat_retextures\vests\data\TacticalVest20_co.paa",
            "iat_retextures\vests\data\TacticalVest20_co.paa"
        };
    };
    class HighCapacityVest_EMP6 : HighCapacityVest_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\TacticalVest58_co.paa",
            "iat_retextures\vests\data\TacticalVest58_co.paa",
            "iat_retextures\vests\data\TacticalVest58_co.paa"
        };
    };

    class HuntingVest_Leather : HuntingVest
    {
        scope = 2;
        color = "Leather";
        hiddenSelections[] =
        {
            "zbytek",
            "camoMale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\hunting_vest_Leather_co.paa",
            "iat_retextures\vests\data\hunting_vest_Leather_co.paa"
        };
    };

    class LeatherStorageVest_Choco : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Choco";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_choco_co.paa"
        };
    };
    class LeatherStorageVest_Lime : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Lime";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_Lime_co.paa"
        };
    };
    class LeatherStorageVest_Orange : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_Orange_co.paa"
        };
    };
    class LeatherStorageVest_Pink : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_Pink_co.paa"
        };
    };
    class LeatherStorageVest_Purple : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Purple";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_Purple_co.paa"
        };
    };
    class LeatherStorageVest_Storm : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Storm";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_Storm_co.paa"
        };
    };
    class LeatherStorageVest_Yellow : LeatherStorageVest_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\vests\data\crafted_leather_vest_Yellow_co.paa"
        };
    };
};