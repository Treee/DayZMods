class CfgPatches
{
    class IAT_Double_Armbands_Tops
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Characters" };
    };
};
class CfgVehicles
{
    class Clothing;

    class IAT_DoubleArmband_ColorBase : Clothing
    {
        scope = 0;
        displayName = "$STR_CfgVehicles_Armband_ColorBase0";
        descriptionShort = "$STR_CfgVehicles_Armband_ColorBase1";
        model = "\DZ\characters\tops\armbend_g.p3d";
        inventorySlot[] = { "Armband" };
        itemInfo[] = { "Clothing", "Armband" };
        rotationFlags = 34;
        weight = 80;
        itemSize[] = { 1,2 };
        ragQuantity = 1;
        varWetMax = 1;
        repairCosts[] = { 30,25 };
        repairableWithKits[] = { 5,8 };
        itemsCargoSize[] = { 1,1 };
        absorbency = 0;
        heatIsolation = 0.80;
        attachments[] = {};
        hiddenSelections[] =
        {
            "camoGround",
            "camoFemale_big_a", // female selections represent right arms
            "camoFemale_small_a",
            "camoMale_big_a", // male selections represent left arms
            "camoMale_small_a",
        };
        hiddenSelectionsTextures[] =
        {
            "\DZ\characters\tops\data\armbend_big_white_co.paa",
            "\DZ\characters\tops\data\armbend_big_white_co.paa",
            "\DZ\characters\tops\data\armbend_big_white_co.paa",
            "\DZ\characters\tops\data\armbend_big_white_co.paa",
            "\DZ\characters\tops\data\armbend_big_white_co.paa",
        };
        class ClothingTypes
        {
            male = "iat_double_armbands\armbands\iat_doublearmband_m.p3d";
            female = "iat_double_armbands\armbands\iat_doublearmband_f.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                      {1.0,{"DZ\characters\tops\Data\armband_big_a.rvmat"}},
                      {0.7,{"DZ\characters\tops\Data\armband_big_a.rvmat"}},
                      {0.5,{"DZ\characters\tops\Data\armband_big_a_damage.rvmat"}},
                      {0.3,{"DZ\characters\tops\Data\armband_big_a_damage.rvmat"}},
                      {0.0,{"DZ\characters\tops\Data\armband_big_a_destruct.rvmat"}}
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
                    soundSet = "Shirt_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "Shirt_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };

    // ==================================================== VANILLA VARIANTS
    class IAT_DoubleArmband_White : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        color = "White";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)", "#(argb,8,8,3)color(0.65098,0.65098,0.65098,1.0,CO)" };
    };
    class IAT_DoubleArmband_Yellow : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)", "#(argb,8,8,3)color(0.521569,0.533333,0,1.0,CO)" };
    };
    class IAT_DoubleArmband_Orange : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0.701961,0.34902,0,1.0,CO)" };
    };
    class IAT_DoubleArmband_Red : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        color = "Red";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)", "#(argb,8,8,3)color(0.615686,0,0,1.0,CO)" };
    };
    class IAT_DoubleArmband_Green : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        color = "Green";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)", "#(argb,8,8,3)color(0,0.34902,0,1.0,CO)" };
    };
    class IAT_DoubleArmband_Pink : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)", "#(argb,8,8,3)color(0.592157,0.27451,0.584314,1.0,CO)" };
    };
    class IAT_DoubleArmband_Blue : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Blue";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)", "#(argb,8,8,3)color(0.188235,0.384314,0.678431,1.0,CO)" };
    };
    class IAT_DoubleArmband_Black : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.85;
        color = "Black";
        hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)", "#(argb,8,8,3)color(0.0784314,0.0784314,0.0784314,1.0,CO)" };
    };
    class IAT_DoubleArmband_Chernarus : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Chernarus";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa", "\dz\gear\camping\data\Flag_Chern_co.paa" };
    };
    class IAT_DoubleArmband_Chedaki : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Chedaki";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa", "\dz\gear\camping\data\Flag_Ched_co.paa" };
    };
    class IAT_DoubleArmband_NAPA : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "NAPA";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa", "\dz\gear\camping\data\Flag_NAPA_co.paa" };
    };
    class IAT_DoubleArmband_CDF : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "CDF";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa", "\dz\gear\camping\data\Flag_CDF_co.paa" };
    };
    class IAT_DoubleArmband_Livonia : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Livonia";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa", "\dz\gear\camping\data\Flag_Livo_co.paa" };
    };
    class IAT_DoubleArmband_Altis : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Altis";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa", "\dz\gear\camping\data\Flag_Alti_co.paa" };
    };
    class IAT_DoubleArmband_SSahrani : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "SSahrani";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa", "\dz\gear\camping\data\Flag_KoS_co.paa" };
    };
    class IAT_DoubleArmband_NSahrani : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "NSahrani";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa", "\dz\gear\camping\data\Flag_DRoS_co.paa" };
    };
    class IAT_DoubleArmband_DayZ : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "DayZ";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa", "\dz\gear\camping\data\Flag_DAYZ_armband_co.paa" };
    };
    class IAT_DoubleArmband_LivoniaArmy : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "LivoniaArmy";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa", "\dz\gear\camping\data\Flag_LDF_co.paa" };
    };
    class IAT_DoubleArmband_Bohemia : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Bohemia";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa", "\dz\gear\camping\data\Flag_BI_co.paa" };
    };
    class IAT_DoubleArmband_APA : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "APA";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa", "\dz\gear\camping\data\Flag_APA_co.paa" };
    };
    class IAT_DoubleArmband_UEC : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "UEC";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa", "\dz\gear\camping\data\Flag_UEC_armband_co.paa" };
    };
    class IAT_DoubleArmband_Pirates : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Pirates";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_armband_co.paa" };
    };
    class IAT_DoubleArmband_Cannibals : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Cannibals";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa", "\dz\gear\camping\data\Flag_jolly_c_armband_co.paa" };
    };
    class IAT_DoubleArmband_Bear : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Bear";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa", "\dz\gear\camping\data\Flag_bear_co.paa" };
    };
    class IAT_DoubleArmband_Wolf : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Wolf";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa", "\dz\gear\camping\data\Flag_wolf_co.paa" };
    };
    class IAT_DoubleArmband_BabyDeer : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "BabyDeer";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa", "\dz\gear\camping\data\Flag_Fawn_co.paa" };
    };
    class IAT_DoubleArmband_Rooster : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Rooster";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa", "\dz\gear\camping\data\Flag_cock_co.paa" };
    };
    class IAT_DoubleArmband_LivoniaPolice : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "LivoniaPolice";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa", "\dz\gear\camping\data\Flag_police_co.paa" };
    };
    class IAT_DoubleArmband_CMC : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "CMC";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa", "\dz\gear\camping\data\Flag_CMC_co.paa" };
    };
    class IAT_DoubleArmband_TEC : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "TEC";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa", "\dz\gear\camping\data\Flag_TEC_co.paa" };
    };
    class IAT_DoubleArmband_CHEL : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "CHEL";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa", "\dz\gear\camping\data\Flag_CHEL_co.paa" };
    };
    class IAT_DoubleArmband_Zenit : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Zenit";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa", "\dz\gear\camping\data\Flag_Zenit_co.paa" };
    };
    class IAT_DoubleArmband_HunterZ : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "HunterZ";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa", "\dz\gear\camping\data\Flag_zhunters_co.paa" };
    };
    class IAT_DoubleArmband_BrainZ : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "BrainZ";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa", "\dz\gear\camping\data\Flag_brain_co.paa" };
    };
    class IAT_DoubleArmband_Refuge : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Refuge";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa", "\dz\gear\camping\data\Flag_refuge_co.paa" };
    };
    class IAT_DoubleArmband_RSTA : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "RSTA";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa", "\dz\gear\camping\data\Flag_rsta_co.paa" };
    };
    class IAT_DoubleArmband_Snake : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Snake";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa", "\dz\gear\camping\data\Flag_snake_co.paa" };
    };
    class IAT_DoubleArmband_Crook : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Crook";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa", "\dz\gear\camping\data\Flag_Crook_co.paa" };
    };
    class IAT_DoubleArmband_Rex : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Rex";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa", "\dz\gear\camping\data\Flag_Rex_co.paa" };
    };
    class IAT_DoubleArmband_Zagorky : IAT_DoubleArmband_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.95;
        color = "Zagorky";
        hiddenSelectionsTextures[] = { "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa", "\dz\gear\camping\data\Flag_Zagorky_co.paa" };
    };
};