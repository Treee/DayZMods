class CfgPatches
{
    class IAT_Retextures_Masks
    {
        requiredAddons[] = { "DZ_Characters", "DZ_Characters_Masks" };
    };
};
class CfgVehicles
{
    class SurgicalMask;
    class HockeyMask;
    class Balaclava3Holes_ColorBase;
    class BalaclavaMask_ColorBase;
    class FaceCover_Improvised;
    class NioshFaceMask;

    //==================================================== VANILLA RETEXTURES
    class SurgicalMask_Black : SurgicalMask
    {
        scope = 2;
        color = "Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\bandanafhg_65b_co.paa",
            "iat_retextures\masks\data\bandanafhg_65b_co.paa",
            "iat_retextures\masks\data\bandanafhg_65b_co.paa"
        };
    };

    class HockeyMask_Steel : HockeyMask
    {
        scope = 2;
        displayName = "Steel Mask";
        descriptionShort = "A steel mask fastened by leather strap";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\vinitagehockeym2907_co.paa",
            "iat_retextures\masks\data\vinitagehockeym2907_co.paa",
            "iat_retextures\masks\data\vinitagehockeym2907_co.paa"
        };
    };

    class Balaclava3Holes_MTP : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H01_co.paa",
            "iat_retextures\masks\data\balaklava3H01_co.paa",
            "iat_retextures\masks\data\balaklava3H01_co.paa"
        };
    };
    class Balaclava3Holes_ATAC : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H05_co.paa",
            "iat_retextures\masks\data\balaklava3H05_co.paa",
            "iat_retextures\masks\data\balaklava3H05_co.paa"
        };
    };
    class Balaclava3Holes_ATACSFG : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H39_co.paa",
            "iat_retextures\masks\data\balaklava3H39_co.paa",
            "iat_retextures\masks\data\balaklava3H39_co.paa"
        };
    };
    class Balaclava3Holes_USNAOR2 : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H10_co.paa",
            "iat_retextures\masks\data\balaklava3H10_co.paa",
            "iat_retextures\masks\data\balaklava3H10_co.paa"
        };
    };
    class Balaclava3Holes_USNAOR1 : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H11_co.paa",
            "iat_retextures\masks\data\balaklava3H11_co.paa",
            "iat_retextures\masks\data\balaklava3H11_co.paa"
        };
    };
    class Balaclava3Holes_SURPAT : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H13_co.paa",
            "iat_retextures\masks\data\balaklava3H13_co.paa",
            "iat_retextures\masks\data\balaklava3H13_co.paa"
        };
    };
    class Balaclava3Holes_MARPATWinter : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H20_co.paa",
            "iat_retextures\masks\data\balaklava3H20_co.paa",
            "iat_retextures\masks\data\balaklava3H20_co.paa"
        };
    };
    class Balaclava3Holes_EMP6 : Balaclava3Holes_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaklava3H58_co.paa",
            "iat_retextures\masks\data\balaklava3H58_co.paa",
            "iat_retextures\masks\data\balaklava3H58_co.paa"
        };
    };

    class BalaclavaMask_MTP : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava01_co.paa",
            "iat_retextures\masks\data\balaclava01_co.paa",
            "iat_retextures\masks\data\balaclava01_co.paa"
        };
    };
    class BalaclavaMask_ATAC : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava05_co.paa",
            "iat_retextures\masks\data\balaclava05_co.paa",
            "iat_retextures\masks\data\balaclava05_co.paa"
        };
    };
    class BalaclavaMask_ATACSFG : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava39_co.paa",
            "iat_retextures\masks\data\balaclava39_co.paa",
            "iat_retextures\masks\data\balaclava39_co.paa"
        };
    };
    class BalaclavaMask_USNAOR2 : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava10_co.paa",
            "iat_retextures\masks\data\balaclava10_co.paa",
            "iat_retextures\masks\data\balaclava10_co.paa"
        };
    };
    class BalaclavaMask_USNAOR1 : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava11_co.paa",
            "iat_retextures\masks\data\balaclava11_co.paa",
            "iat_retextures\masks\data\balaclava11_co.paa"
        };
    };
    class BalaclavaMask_SURPAT : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava13_co.paa",
            "iat_retextures\masks\data\balaclava13_co.paa",
            "iat_retextures\masks\data\balaclava13_co.paa"
        };
    };
    class BalaclavaMask_MARPATWinter : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava20_co.paa",
            "iat_retextures\masks\data\balaclava20_co.paa",
            "iat_retextures\masks\data\balaclava20_co.paa"
        };
    };
    class BalaclavaMask_EMP6 : BalaclavaMask_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\balaclava58_co.paa",
            "iat_retextures\masks\data\balaclava58_co.paa",
            "iat_retextures\masks\data\balaclava58_co.paa"
        };
    };

    class FaceCover_Improvised_green : FaceCover_Improvised
    {
        scope = 2;
        color = "green";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\masks\data\FaceCover_Improvised_green_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_green_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_green_co.paa"
        };
    };
    class FaceCover_Improvised_black : FaceCover_Improvised
    {
        scope = 2;
        color = "black";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\masks\data\FaceCover_Improvised_black_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_black_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_black_co.paa"
        };
    };
    class FaceCover_Improvised_orange : FaceCover_Improvised
    {
        scope = 2;
        color = "orange";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\masks\data\FaceCover_Improvised_orange_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_orange_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_orange_co.paa"
        };
    };
    class FaceCover_Improvised_blue : FaceCover_Improvised
    {
        scope = 2;
        color = "blue";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\masks\data\FaceCover_Improvised_blue_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_blue_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_blue_co.paa"
        };
    };
    class FaceCover_Improvised_Red : FaceCover_Improvised
    {
        scope = 2;
        color = "Red";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\masks\data\FaceCover_Improvised_red_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_red_co.paa",
          "iat_retextures\masks\data\FaceCover_Improvised_red_co.paa"
        };
    };

    class NioshFaceMask_WaldoRescue : NioshFaceMask
    {
        scope = 2;
        color = "WaldoRescue";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\masks\data\NioshFaceMask_Rescue_co.paa",
            "iat_retextures\masks\data\NioshFaceMask_Rescue_co.paa",
            "iat_retextures\masks\data\NioshFaceMask_Rescue_co.paa"
        };
    };

};