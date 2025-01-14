class CfgPatches
{
    class IAT_Retextures_Gloves
    {
        requiredAddons[] = { "DZ_Characters", "DZ_Characters_Gloves" };
    };
};
class CfgVehicles
{
    class OMNOGloves_ColorBase;
    class WorkingGloves_ColorBase;
    class NBCGloves_ColorBase;
    class TacticalGloves_ColorBase;
    class LeatherGloves_ColorBase;
    class SurgicalGloves_ColorBase;
    class HandsCover_Improvised;

    //==================================================== VANILLA RETEXTURES
    class NBCGloves_Blue : NBCGloves_ColorBase
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
            "iat_retextures\gloves\data\nbc_gloves_blue_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_blue_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_blue_co.paa"
        };
    };
    class NBCGloves_Gray : NBCGloves_ColorBase
    {
        scope = 2;
        color = "Gray";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\gloves\Data\NBC_Gloves_grey_co.paa",
            "\dz\characters\gloves\Data\NBC_Gloves_grey_co.paa",
            "\dz\characters\gloves\Data\NBC_Gloves_grey_co.paa"
        };
    };
    // actual vanilla retexture since the base texture is not yellow
    class NBCGlovesYellow : NBCGloves_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\nbc_gloves_yellow_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_yellow_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_yellow_co.paa"
        };
    };
    class NBCGloves_Yellow : NBCGloves_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\nbc_gloves_yellow_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_yellow_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_yellow_co.paa"
        };
    };
    class NBCGloves_White : NBCGloves_ColorBase
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
            "iat_retextures\gloves\data\nbc_gloves_white_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_white_co.paa",
            "iat_retextures\gloves\data\nbc_gloves_white_co.paa"
        };
    };

    class OMNOGloves_Green : OMNOGloves_ColorBase
    {
        scope = 2;
        color = "Green";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\Denglove_green_co.paa",
            "iat_retextures\gloves\data\Denglove_green_co.paa",
            "iat_retextures\gloves\data\Denglove_green_co.paa"
        };
    };
    class OMNOGloves_Black : OMNOGloves_ColorBase
    {
        scope = 2;
        color = "Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\denglove_co.paa",
            "iat_retextures\gloves\data\denglove_co.paa",
            "iat_retextures\gloves\data\denglove_co.paa"
        };
    };

    class TacticalGloves_MTP : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG01_co.paa",
            "iat_retextures\gloves\data\TacticalG01_co.paa",
            "iat_retextures\gloves\data\TacticalG01_co.paa"
        };
    };
    class TacticalGloves_ATAC : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG04_co.paa",
            "iat_retextures\gloves\data\TacticalG04_co.paa",
            "iat_retextures\gloves\data\TacticalG04_co.paa"
        };
    };
    class TacticalGloves_ATACSFG : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG38_co.paa",
            "iat_retextures\gloves\data\TacticalG38_co.paa",
            "iat_retextures\gloves\data\TacticalG38_co.paa"
        };
    };
    class TacticalGloves_USNAOR2 : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG09_co.paa",
            "iat_retextures\gloves\data\TacticalG09_co.paa",
            "iat_retextures\gloves\data\TacticalG09_co.paa"
        };
    };
    class TacticalGloves_USNAOR1 : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG10_co.paa",
            "iat_retextures\gloves\data\TacticalG10_co.paa",
            "iat_retextures\gloves\data\TacticalG10_co.paa"
        };
    };
    class TacticalGloves_SURPAT : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG12_co.paa",
            "iat_retextures\gloves\data\TacticalG12_co.paa",
            "iat_retextures\gloves\data\TacticalG12_co.paa"
        };
    };
    class TacticalGloves_MARPATWinter : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG19_co.paa",
            "iat_retextures\gloves\data\TacticalG19_co.paa",
            "iat_retextures\gloves\data\TacticalG19_co.paa"
        };
    };
    class TacticalGloves_EMP6 : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\TacticalG57_co.paa",
            "iat_retextures\gloves\data\TacticalG57_co.paa",
            "iat_retextures\gloves\data\TacticalG57_co.paa"
        };
    };
    class TacticalGloves_Officer : TacticalGloves_ColorBase
    {
        scope = 2;
        color = "Officer";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\Dillard_OfficerGloves_co.paa",
            "iat_retextures\gloves\data\Dillard_OfficerGloves_co.paa",
            "iat_retextures\gloves\data\Dillard_OfficerGloves_co.paa"
        };
    };

    class WorkingGloves_White : WorkingGloves_ColorBase
    {
        scope = 2;
        color = "White";
        visibilityModifier = 0.89999998;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\WorkingGloves_white_co.paa",
            "iat_retextures\gloves\data\WorkingGloves_white_co.paa",
            "iat_retextures\gloves\data\WorkingGloves_white_co.paa"
        };
    };
    class WorkingGloves_Red : WorkingGloves_ColorBase
    {
        scope = 2;
        color = "Red";
        visibilityModifier = 0.89999998;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\WorkingGloves_red_co.paa",
            "iat_retextures\gloves\data\WorkingGloves_red_co.paa",
            "iat_retextures\gloves\data\WorkingGloves_red_co.paa"
        };
    };

    class LeatherGloves_Choco : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Choco";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_choco_co.paa",
            "iat_retextures\gloves\data\leather_gloves_choco_co.paa",
            "iat_retextures\gloves\data\leather_gloves_choco_co.paa",
        };
    };
    class LeatherGloves_Lime : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Lime";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_Lime_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Lime_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Lime_co.paa",
        };
    };
    class LeatherGloves_Orange : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_Orange_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Orange_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Orange_co.paa",
        };
    };
    class LeatherGloves_Pink : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_Pink_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Pink_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Pink_co.paa",
        };
    };
    class LeatherGloves_Purple : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Purple";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_Purple_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Purple_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Purple_co.paa",
        };
    };
    class LeatherGloves_Storm : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Storm";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_Storm_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Storm_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Storm_co.paa",
        };
    };
    class LeatherGloves_Yellow : LeatherGloves_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelections[] = { "camomale","camofemale","camoground" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\leather_gloves_Yellow_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Yellow_co.paa",
            "iat_retextures\gloves\data\leather_gloves_Yellow_co.paa",
        };
    };

    class SurgicalGloves_SkyBlue : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "SkyBlue";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_blue_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_blue_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_blue_co.paa"
        };
    };
    class SurgicalGloves_Coal : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Coal";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_coal_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_coal_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_coal_co.paa"
        };
    };
    class SurgicalGloves_Lime : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Lime";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_green_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_green_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_green_co.paa"
        };
    };
    class SurgicalGloves_LightGreen : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "LightGreen";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_lime_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_lime_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_lime_co.paa"
        };
    };
    class SurgicalGloves_Orange : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_orange_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_orange_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_orange_co.paa"
        };
    };
    class SurgicalGloves_Pink : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_pink_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_pink_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_pink_co.paa"
        };
    };
    class SurgicalGloves_Purple : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Purple";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_purple_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_purple_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_purple_co.paa"
        };
    };
    class SurgicalGloves_Red : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Red";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_red_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_red_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_red_co.paa"
        };
    };
    class SurgicalGloves_Yellow : SurgicalGloves_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\gloves\data\surgical_gloves_yellow_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_yellow_co.paa",
            "iat_retextures\gloves\data\surgical_gloves_yellow_co.paa"
        };
    };

    class HandsCover_Improvised_green : HandsCover_Improvised
    {
        scope = 2;
        color = "green";
        hiddenSelectionsTextures[] = { "iat_retextures\gloves\data\handscover_improvised_green_CO.paa","iat_retextures\gloves\data\handscover_improvised_green_CO.paa","iat_retextures\gloves\data\handscover_improvised_green_CO.paa" };
    };
    class HandsCover_Improvised_black : HandsCover_Improvised
    {
        scope = 2;
        color = "black";
        hiddenSelectionsTextures[] = { "iat_retextures\gloves\data\handscover_improvised_black_CO.paa","iat_retextures\gloves\data\handscover_improvised_black_CO.paa","iat_retextures\gloves\data\handscover_improvised_black_CO.paa" };
    };
    class HandsCover_Improvised_orange : HandsCover_Improvised
    {
        scope = 2;
        color = "orange";
        hiddenSelectionsTextures[] = { "iat_retextures\gloves\data\handscover_improvised_orange_CO.paa","iat_retextures\gloves\data\handscover_improvised_orange_CO.paa","iat_retextures\gloves\data\handscover_improvised_orange_CO.paa" };
    };
    class HandsCover_Improvised_blue : HandsCover_Improvised
    {
        scope = 2;
        color = "blue";
        hiddenSelectionsTextures[] = { "iat_retextures\gloves\data\handscover_improvised_blue_CO.paa","iat_retextures\gloves\data\handscover_improvised_blue_CO.paa","iat_retextures\gloves\data\handscover_improvised_blue_CO.paa" };
    };
    class HandsCover_Improvised_Red : HandsCover_Improvised
    {
        scope = 2;
        color = "Red";
        hiddenSelectionsTextures[] = { "iat_retextures\gloves\data\handscover_improvised_red_CO.paa","iat_retextures\gloves\data\handscover_improvised_red_CO.paa","iat_retextures\gloves\data\handscover_improvised_red_CO.paa" };
    };

};
