class CfgPatches
{
    class IAT_Retextures_Headgear
    {
        requiredAddons[] = { "DZ_Characters", "DZ_Characters_Headgear" };
    };
};
class CfgVehicles
{
    class WitchHat;
    class BallisticHelmet_ColorBase;
    class BaseballCap_ColorBase;
    class SantasHat;
    class NBCHoodBase;
    class BurlapSackCover;
    class Bandana_ColorBase;
    class Ushanka_ColorBase;
    class PrisonerCap;
    class BeanieHat_ColorBase;
    class Mich2001Helmet;
    class BoonieHat_ColorBase;
    class FlatCap_ColorBase;
    class LeatherHat_ColorBase;
    class OfficerHat;
    class PoliceCap;
    class HeadCover_Improvised;
    class CowboyHat_ColorBase;
    class GhillieHood_ColorBase;

    //=============================================== Vanilla Override
    class BallisticHelmet_MTP : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich01_co.paa",
            "iat_retextures\headgear\data\helmetmich01_co.paa",
            "iat_retextures\headgear\data\helmetmich01_co.paa"
        };
    };
    class BallisticHelmet_ATAC : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich04_co.paa",
            "iat_retextures\headgear\data\helmetmich04_co.paa",
            "iat_retextures\headgear\data\helmetmich04_co.paa"
        };
    };
    class BallisticHelmet_ATACSFG : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich38_co.paa",
            "iat_retextures\headgear\data\helmetmich38_co.paa",
            "iat_retextures\headgear\data\helmetmich38_co.paa"
        };
    };
    class BallisticHelmet_USNAOR2 : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich09_co.paa",
            "iat_retextures\headgear\data\helmetmich09_co.paa",
            "iat_retextures\headgear\data\helmetmich09_co.paa"
        };
    };
    class BallisticHelmet_USNAOR1 : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich10_co.paa",
            "iat_retextures\headgear\data\helmetmich10_co.paa",
            "iat_retextures\headgear\data\helmetmich10_co.paa"
        };
    };
    class BallisticHelmet_SURPAT : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich12_co.paa",
            "iat_retextures\headgear\data\helmetmich12_co.paa",
            "iat_retextures\headgear\data\helmetmich12_co.paa"
        };
    };
    class BallisticHelmet_MARPATWinter : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich19_co.paa",
            "iat_retextures\headgear\data\helmetmich19_co.paa",
            "iat_retextures\headgear\data\helmetmich19_co.paa"
        };
    };
    class BallisticHelmet_EMP6 : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\helmetmich57_co.paa",
            "iat_retextures\headgear\data\helmetmich57_co.paa",
            "iat_retextures\headgear\data\helmetmich57_co.paa"
        };
    };
    class BallisticHelmet_Rain : BallisticHelmet_ColorBase
    {
        scope = 2;
        color = "Rain";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BPRainhelm_co.paa",
            "iat_retextures\headgear\data\BPRainhelm_co.paa",
            "iat_retextures\headgear\data\BPRainhelm_co.paa"
        };
    };

    class BaseballCap_Lisiy : BaseballCap_ColorBase
    {
        scope = 2;
        color = "Lisiy";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcap_lisiy_co.paa",
            "iat_retextures\headgear\data\baseballcap_lisiy_co.paa",
            "iat_retextures\headgear\data\baseballcap_lisiy_co.paa"
        };
    };
    class BaseballCap_PoliceCap : BaseballCap_ColorBase
    {
        scope = 2;
        color = "PoliceCap";
        heatIsolation = 0.80000001;
        displayName = "Sheriff Cap";
        descriptionShort = "Hackcock Sheriffs Department Cap";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\iat_policecap_co.paa",
            "iat_retextures\headgear\data\iat_policecap_co.paa",
            "iat_retextures\headgear\data\iat_policecap_co.paa"
        };
    };
    class BaseballCap_MTP : BaseballCap_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball01_co.paa",
            "iat_retextures\headgear\data\baseball01_co.paa",
            "iat_retextures\headgear\data\baseball01_co.paa"
        };
    };
    class BaseballCap_ATAC : BaseballCap_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball04_co.paa",
            "iat_retextures\headgear\data\baseball04_co.paa",
            "iat_retextures\headgear\data\baseball04_co.paa"
        };
    };
    class BaseballCap_ATACSFG : BaseballCap_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball38_co.paa",
            "iat_retextures\headgear\data\baseball38_co.paa",
            "iat_retextures\headgear\data\baseball38_co.paa"
        };
    };
    class BaseballCap_USNAOR2 : BaseballCap_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball09_co.paa",
            "iat_retextures\headgear\data\baseball09_co.paa",
            "iat_retextures\headgear\data\baseball09_co.paa"
        };
    };
    class BaseballCap_USNAOR1 : BaseballCap_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball10_co.paa",
            "iat_retextures\headgear\data\baseball10_co.paa",
            "iat_retextures\headgear\data\baseball10_co.paa"
        };
    };
    class BaseballCap_SURPAT : BaseballCap_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball12_co.paa",
            "iat_retextures\headgear\data\baseball12_co.paa",
            "iat_retextures\headgear\data\baseball12_co.paa"
        };
    };
    class BaseballCap_MARPATWinter : BaseballCap_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball19_co.paa",
            "iat_retextures\headgear\data\baseball19_co.paa",
            "iat_retextures\headgear\data\baseball19_co.paa"
        };
    };
    class BaseballCap_EMP6 : BaseballCap_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseball57_co.paa",
            "iat_retextures\headgear\data\baseball57_co.paa",
            "iat_retextures\headgear\data\baseball57_co.paa"
        };
    };
    class BaseballCap_Black : BaseballCap_ColorBase
    {
        scope = 2;
        color = "Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcapii_black_co.paa",
            "iat_retextures\headgear\data\baseballcapii_black_co.paa",
            "iat_retextures\headgear\data\baseballcapii_black_co.paa"
        };
    };
    class BaseballCap_TTDBlack : BaseballCap_ColorBase
    {
        scope = 2;
        color = "TTDBlack";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcap_TTDBlack_co.paa",
            "iat_retextures\headgear\data\baseballcap_TTDBlack_co.paa",
            "iat_retextures\headgear\data\baseballcap_TTDBlack_co.paa"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 25;
                    healthLevels[] =
                    {
                        {1,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0.69999999,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0.5,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0.30000001,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}}
                    };
                };
            };
        };
    };
    class BaseballCap_TTDWhite : BaseballCap_ColorBase
    {
        scope = 2;
        color = "TTDWhite";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcap_TTDWhite_co.paa",
            "iat_retextures\headgear\data\baseballcap_TTDWhite_co.paa",
            "iat_retextures\headgear\data\baseballcap_TTDWhite_co.paa"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 25;
                    healthLevels[] =
                    {
                        {1,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0.69999999,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0.5,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0.30000001,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}},
                        {0,	{	"iat_retextures\headgear\data\baseballcap_TTD.rvmat"}}
                    };
                };
            };
        };
    };
    class BaseballCap_Marshals : BaseballCap_ColorBase
    {
        scope = 2;
        color = "Marshals";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcapii_black_marshals_co.paa",
            "iat_retextures\headgear\data\baseballcapii_black_marshals_co.paa",
            "iat_retextures\headgear\data\baseballcapii_black_marshals_co.paa"
        };
    };
    class BaseballCap_OregonPolice : BaseballCap_ColorBase
    {
        scope = 2;
        color = "OregonPolice";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcapii_navy_oregonpolice_co.paa",
            "iat_retextures\headgear\data\baseballcapii_navy_oregonpolice_co.paa",
            "iat_retextures\headgear\data\baseballcapii_navy_oregonpolice_co.paa"
        };
    };
    class BaseballCap_BlackRanger : BaseballCap_ColorBase
    {
        scope = 2;
        color = "BlackRanger";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcapii_black_ranger_co.paa",
            "iat_retextures\headgear\data\baseballcapii_black_ranger_co.paa",
            "iat_retextures\headgear\data\baseballcapii_black_ranger_co.paa"
        };
    };
    class BaseballCap_WaldoRescueGreen : BaseballCap_ColorBase
    {
        scope = 2;
        color = "WaldoRescueGreen";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcapii_RescueGreen_co.paa",
            "iat_retextures\headgear\data\baseballcapii_RescueGreen_co.paa",
            "iat_retextures\headgear\data\baseballcapii_RescueGreen_co.paa"
        };
    };
    class BaseballCap_WaldoRescueOrange : BaseballCap_ColorBase
    {
        scope = 2;
        color = "WaldoRescueOrange";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\baseballcapii_RescueOrange_co.paa",
            "iat_retextures\headgear\data\baseballcapii_RescueOrange_co.paa",
            "iat_retextures\headgear\data\baseballcapii_RescueOrange_co.paa"
        };
    };

    class BeanieHat_MTP : BeanieHat_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat03_co.paa",
            "iat_retextures\headgear\data\BeanieHat03_co.paa",
            "iat_retextures\headgear\data\BeanieHat03_co.paa"
        };
    };
    class BeanieHat_ATAC : BeanieHat_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat05_co.paa",
            "iat_retextures\headgear\data\BeanieHat05_co.paa",
            "iat_retextures\headgear\data\BeanieHat05_co.paa"
        };
    };
    class BeanieHat_ATACSFG : BeanieHat_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat39_co.paa",
            "iat_retextures\headgear\data\BeanieHat39_co.paa",
            "iat_retextures\headgear\data\BeanieHat39_co.paa"
        };
    };
    class BeanieHat_USNAOR2 : BeanieHat_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat10_co.paa",
            "iat_retextures\headgear\data\BeanieHat10_co.paa",
            "iat_retextures\headgear\data\BeanieHat10_co.paa"
        };
    };
    class BeanieHat_USNAOR1 : BeanieHat_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat11_co.paa",
            "iat_retextures\headgear\data\BeanieHat11_co.paa",
            "iat_retextures\headgear\data\BeanieHat11_co.paa"
        };
    };
    class BeanieHat_SURPAT : BeanieHat_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat13_co.paa",
            "iat_retextures\headgear\data\BeanieHat13_co.paa",
            "iat_retextures\headgear\data\BeanieHat13_co.paa"
        };
    };
    class BeanieHat_MARPATWinter : BeanieHat_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat20_co.paa",
            "iat_retextures\headgear\data\BeanieHat20_co.paa",
            "iat_retextures\headgear\data\BeanieHat20_co.paa"
        };
    };
    class BeanieHat_EMP6 : BeanieHat_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BeanieHat58_co.paa",
            "iat_retextures\headgear\data\BeanieHat58_co.paa",
            "iat_retextures\headgear\data\BeanieHat58_co.paa"
        };
    };

    class BurlapSackCover_Black : BurlapSackCover
    {
        scope = 2;
        color = "black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\head_sack_black_co.paa",
            "iat_retextures\headgear\data\head_sack_black_co.paa",
            "iat_retextures\headgear\data\head_sack_black_co.paa"
        };
    };
    class BurlapSackCover_Skull : BurlapSackCover
    {
        scope = 2;
        color = "skull";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\head_sack_black_skull_co.paa",
            "iat_retextures\headgear\data\head_sack_black_skull_co.paa",
            "iat_retextures\headgear\data\head_sack_black_skull_co.paa"
        };
    };
    class BurlapSackCover_White : BurlapSackCover
    {
        scope = 2;
        color = "white";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\head_sack_white_co.paa",
            "iat_retextures\headgear\data\head_sack_white_co.paa",
            "iat_retextures\headgear\data\head_sack_white_co.paa"
        };
    };

    class Ushanka_Denim : Ushanka_ColorBase
    {
        scope = 2;
        color = "Denim";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\ushanka_denim_co.paa",
            "iat_retextures\headgear\data\ushanka_denim_co.paa",
            "iat_retextures\headgear\data\ushanka_denim_co.paa"
        };
    };
    class Ushanka_MTP : Ushanka_ColorBase
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka01_co.paa",
            "iat_retextures\headgear\data\Ushanka01_co.paa",
            "iat_retextures\headgear\data\Ushanka01_co.paa"
        };
    };
    class Ushanka_ATAC : Ushanka_ColorBase
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka04_co.paa",
            "iat_retextures\headgear\data\Ushanka04_co.paa",
            "iat_retextures\headgear\data\Ushanka04_co.paa"
        };
    };
    class Ushanka_ATACSFG : Ushanka_ColorBase
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka38_co.paa",
            "iat_retextures\headgear\data\Ushanka38_co.paa",
            "iat_retextures\headgear\data\Ushanka38_co.paa"
        };
    };
    class Ushanka_USNAOR2 : Ushanka_ColorBase
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka09_co.paa",
            "iat_retextures\headgear\data\Ushanka09_co.paa",
            "iat_retextures\headgear\data\Ushanka09_co.paa"
        };
    };
    class Ushanka_USNAOR1 : Ushanka_ColorBase
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka10_co.paa",
            "iat_retextures\headgear\data\Ushanka10_co.paa",
            "iat_retextures\headgear\data\Ushanka10_co.paa"
        };
    };
    class Ushanka_SURPAT : Ushanka_ColorBase
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka12_co.paa",
            "iat_retextures\headgear\data\Ushanka12_co.paa",
            "iat_retextures\headgear\data\Ushanka12_co.paa"
        };
    };
    class Ushanka_MARPATWinter : Ushanka_ColorBase
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka19_co.paa",
            "iat_retextures\headgear\data\Ushanka19_co.paa",
            "iat_retextures\headgear\data\Ushanka19_co.paa"
        };
    };
    class Ushanka_EMP6 : Ushanka_ColorBase
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka57_co.paa",
            "iat_retextures\headgear\data\Ushanka57_co.paa",
            "iat_retextures\headgear\data\Ushanka57_co.paa"
        };
    };
    class Ushanka_STAG : Ushanka_ColorBase
    {
        scope = 2;
        color = "STAG";
        visibilityModifier = 0.89999998;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\Ushanka_STAG_co.paa",
            "iat_retextures\headgear\data\Ushanka_STAG_co.paa",
            "iat_retextures\headgear\data\Ushanka_STAG_co.paa"
        };
    };

    class OfficerHat_Officer : OfficerHat
    {
        scope = 2;
        color = "Officer";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\officerHat_dillard_co.paa",
            "iat_retextures\headgear\data\officerHat_dillard_co.paa",
            "iat_retextures\headgear\data\officerHat_dillard_co.paa"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 35;
                    healthLevels[] =
                    {
                        {1,	{	"iat_retextures\headgear\data\officerHat_dillard.rvmat"}},
                        {0.69999999,	{	"iat_retextures\headgear\data\officerHat_dillard.rvmat"}},
                        {0.5,	{	"iat_retextures\headgear\data\officerHat_dillard.rvmat"}},
                        {0.30000001,	{	"iat_retextures\headgear\data\officerHat_dillard.rvmat"}},
                        {0,	{	"iat_retextures\headgear\data\officerHat_dillard.rvmat"}}
                    };
                };
            };
        };
    };
    class PoliceCap_Holiday : PoliceCap
    {
        scope = 2;
        color = "Holiday";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\policecap_dillard_co.paa",
            "iat_retextures\headgear\data\policecap_dillard_co.paa",
            "iat_retextures\headgear\data\policecap_dillard_co.paa"
        };
    };

    class Bandana_65Black : Bandana_ColorBase
    {
        scope = 2;
        color = "65Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_65b_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65b_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65b_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65b_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65b_co.paa"
        };
    };
    class Bandana_65Desert : Bandana_ColorBase
    {
        scope = 2;
        color = "65Desert";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_65d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65d_co.paa"
        };
    };
    class Bandana_65Tan : Bandana_ColorBase
    {
        scope = 2;
        color = "65Tan";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_65t_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65t_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65t_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65t_co.paa",
            "iat_retextures\headgear\data\bandanafhg_65t_co.paa"
        };
    };
    class Bandana_CheckBlue : Bandana_ColorBase
    {
        scope = 2;
        color = "CheckBlue";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_cb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cb_co.paa"
        };
    };
    class Bandana_CheckBlueBright : Bandana_ColorBase
    {
        scope = 2;
        color = "CheckBlueBright";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_cbb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cbb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cbb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cbb_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cbb_co.paa"
        };
    };
    class Bandana_CheckGreen : Bandana_ColorBase
    {
        scope = 2;
        color = "CheckGreen";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_cg_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cg_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cg_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cg_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cg_co.paa"
        };
    };
    class Bandana_CheckRed : Bandana_ColorBase
    {
        scope = 2;
        color = "CheckRed";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_cr_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cr_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cr_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cr_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cr_co.paa"
        };
    };
    class Bandana_CheckWhite : Bandana_ColorBase
    {
        scope = 2;
        color = "CheckWhite";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_cw_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cw_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cw_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cw_co.paa",
            "iat_retextures\headgear\data\bandanafhg_cw_co.paa"
        };
    };
    class Bandana_Denim : Bandana_ColorBase
    {
        scope = 2;
        color = "Denim";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_denim_co.paa",
            "iat_retextures\headgear\data\bandanafhg_denim_co.paa",
            "iat_retextures\headgear\data\bandanafhg_denim_co.paa",
            "iat_retextures\headgear\data\bandanafhg_denim_co.paa",
            "iat_retextures\headgear\data\bandanafhg_denim_co.paa"
        };
    };
    class Bandana_Kamysh : Bandana_ColorBase
    {
        scope = 2;
        color = "Kamysh";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_kamysh_co.paa",
            "iat_retextures\headgear\data\bandanafhg_kamysh_co.paa",
            "iat_retextures\headgear\data\bandanafhg_kamysh_co.paa",
            "iat_retextures\headgear\data\bandanafhg_kamysh_co.paa",
            "iat_retextures\headgear\data\bandanafhg_kamysh_co.paa"
        };
    };
    class Bandana_USMC_D : Bandana_ColorBase
    {
        scope = 2;
        color = "USMC_D";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_usmc_d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_d_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_d_co.paa"
        };
    };
    class Bandana_USMC_W : Bandana_ColorBase
    {
        scope = 2;
        color = "USMC_W";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\bandanafhg_usmc_w_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_w_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_w_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_w_co.paa",
            "iat_retextures\headgear\data\bandanafhg_usmc_w_co.paa"
        };
    };

    class FlatCap_ERDL : FlatCap_ColorBase
    {
        scope = 2;
        color = "ERDL";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\FlatCap_erdl_co.paa",
            "iat_retextures\headgear\data\FlatCap_erdl_co.paa",
            "iat_retextures\headgear\data\FlatCap_erdl_co.paa"
        };
    };
    class FlatCap_Snow : FlatCap_ColorBase
    {
        scope = 2;
        color = "Snow";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\FlatCap_Snow_co.paa",
            "iat_retextures\headgear\data\FlatCap_Snow_co.paa",
            "iat_retextures\headgear\data\FlatCap_Snow_co.paa"
        };
    };
    class FlatCap_Multicam : FlatCap_ColorBase
    {
        scope = 2;
        color = "Multicam";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\FlatCap_MC_co.paa",
            "iat_retextures\headgear\data\FlatCap_MC_co.paa",
            "iat_retextures\headgear\data\FlatCap_MC_co.paa"
        };
    };
    class FlatCap_MulticamTropic : FlatCap_ColorBase
    {
        scope = 2;
        color = "MulticamTropic";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\FlatCap_MC_Tropic_co.paa",
            "iat_retextures\headgear\data\FlatCap_MC_Tropic_co.paa",
            "iat_retextures\headgear\data\FlatCap_MC_Tropic_co.paa"
        };
    };
    class FlatCap_MulticamBlack : FlatCap_ColorBase
    {
        scope = 2;
        color = "MulticamBlack";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\FlatCap_MC_Black_co.paa",
            "iat_retextures\headgear\data\FlatCap_MC_Black_co.paa",
            "iat_retextures\headgear\data\FlatCap_MC_Black_co.paa"
        };
    };

    class BoonieHat_MTP : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat01_co.paa",
            "iat_retextures\headgear\data\booniehat01_co.paa",
            "iat_retextures\headgear\data\booniehat01_co.paa"
        };
    };
    class BoonieHat_ATAC : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat05_co.paa",
            "iat_retextures\headgear\data\booniehat05_co.paa",
            "iat_retextures\headgear\data\booniehat05_co.paa"
        };
    };
    class BoonieHat_ATACSFG : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat39_co.paa",
            "iat_retextures\headgear\data\booniehat39_co.paa",
            "iat_retextures\headgear\data\booniehat39_co.paa"
        };
    };
    class BoonieHat_USNAOR2 : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat10_co.paa",
            "iat_retextures\headgear\data\booniehat10_co.paa",
            "iat_retextures\headgear\data\booniehat10_co.paa"
        };
    };
    class BoonieHat_USNAOR1 : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat11_co.paa",
            "iat_retextures\headgear\data\booniehat11_co.paa",
            "iat_retextures\headgear\data\booniehat11_co.paa"
        };
    };
    class BoonieHat_SURPAT : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat13_co.paa",
            "iat_retextures\headgear\data\booniehat13_co.paa",
            "iat_retextures\headgear\data\booniehat13_co.paa"
        };
    };
    class BoonieHat_MARPATWinter : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat20_co.paa",
            "iat_retextures\headgear\data\booniehat20_co.paa",
            "iat_retextures\headgear\data\booniehat20_co.paa"
        };
    };
    class BoonieHat_EMP6 : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat58_co.paa",
            "iat_retextures\headgear\data\booniehat58_co.paa",
            "iat_retextures\headgear\data\booniehat58_co.paa"
        };
    };
    class BoonieHat_ERDL : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BoonieHat_erdl_co.paa",
            "iat_retextures\headgear\data\BoonieHat_erdl_co.paa",
            "iat_retextures\headgear\data\BoonieHat_erdl_co.paa"
        };
    };
    class BoonieHat_Snow : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BoonieHat_Snow_co.paa",
            "iat_retextures\headgear\data\BoonieHat_Snow_co.paa",
            "iat_retextures\headgear\data\BoonieHat_Snow_co.paa"
        };
    };
    class BoonieHat_Multicam : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BoonieHat_MC_co.paa",
            "iat_retextures\headgear\data\BoonieHat_MC_co.paa",
            "iat_retextures\headgear\data\BoonieHat_MC_co.paa"
        };
    };
    class BoonieHat_MulticamTropic : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BoonieHat_MC_Tropic_co.paa",
            "iat_retextures\headgear\data\BoonieHat_MC_Tropic_co.paa",
            "iat_retextures\headgear\data\BoonieHat_MC_Tropic_co.paa"
        };
    };
    class BoonieHat_MulticamBlack : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\BoonieHat_MC_Black_co.paa",
            "iat_retextures\headgear\data\BoonieHat_MC_Black_co.paa",
            "iat_retextures\headgear\data\BoonieHat_MC_Black_co.paa"
        };
    };
    class BoonieHat_Camo : BoonieHat_ColorBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\booniehat_camo_co.paa",
            "iat_retextures\headgear\data\booniehat_camo_co.paa",
            "iat_retextures\headgear\data\booniehat_camo_co.paa"
        };
    };

    class PrisonerCap_Brown : PrisonerCap
    {
        scope = 2;
        displayName = "Handmade Flat Cap";
        descriptionShort = "A hand sewn flat cap.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\prisonerscap_co.paa",
            "iat_retextures\headgear\data\prisonerscap_co.paa",
            "iat_retextures\headgear\data\prisonerscap_co.paa"
        };
    };

    class NBCHoodBase_Orange : NBCHoodBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\nbc_hood_orange_co.paa",
            "iat_retextures\headgear\data\nbc_hood_orange_co.paa",
            "iat_retextures\headgear\data\nbc_hood_orange_co.paa"
        };
    };
    class NBCHoodBase_Gray : NBCHoodBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\headgear\data\NBC_Hood_grey_co.paa",
            "\dz\characters\headgear\data\NBC_Hood_grey_co.paa",
            "\dz\characters\headgear\data\NBC_Hood_grey_co.paa"
        };
    };
    class NBCHoodBase_Yellow : NBCHoodBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "\dz\characters\headgear\data\NBC_Hood_yellow_co.paa",
            "\dz\characters\headgear\data\NBC_Hood_yellow_co.paa",
            "\dz\characters\headgear\data\NBC_Hood_yellow_co.paa"
        };
    };
    class NBCHoodBase_White : NBCHoodBase
    {
        scope = 2;
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\nbc_hood_white_co.paa",
            "iat_retextures\headgear\data\nbc_hood_white_co.paa",
            "iat_retextures\headgear\data\nbc_hood_white_co.paa",
        };
    };

    class Mich2001Helmet_EMP6 : Mich2001Helmet
    {
        scope = 2;
        color = "EMP6";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_57_co.paa",
            "iat_retextures\headgear\data\mich2001_57_co.paa",
            "iat_retextures\headgear\data\mich2001_57_co.paa"
        };
    };
    class Mich2001Helmet_MTP : Mich2001Helmet
    {
        scope = 2;
        color = "MTP";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_01_co.paa",
            "iat_retextures\headgear\data\mich2001_01_co.paa",
            "iat_retextures\headgear\data\mich2001_01_co.paa"
        };
    };
    class Mich2001Helmet_ATAC : Mich2001Helmet
    {
        scope = 2;
        color = "ATAC";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_04_co.paa",
            "iat_retextures\headgear\data\mich2001_04_co.paa",
            "iat_retextures\headgear\data\mich2001_04_co.paa"
        };
    };
    class Mich2001Helmet_ATACSFG : Mich2001Helmet
    {
        scope = 2;
        color = "ATACSFG";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_38_co.paa",
            "iat_retextures\headgear\data\mich2001_38_co.paa",
            "iat_retextures\headgear\data\mich2001_38_co.paa"
        };
    };
    class Mich2001Helmet_USNAOR2 : Mich2001Helmet
    {
        scope = 2;
        color = "USNAOR2";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_09_co.paa",
            "iat_retextures\headgear\data\mich2001_09_co.paa",
            "iat_retextures\headgear\data\mich2001_09_co.paa"
        };
    };
    class Mich2001Helmet_USNAOR1 : Mich2001Helmet
    {
        scope = 2;
        color = "USNAOR1";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_10_co.paa",
            "iat_retextures\headgear\data\mich2001_10_co.paa",
            "iat_retextures\headgear\data\mich2001_10_co.paa"
        };
    };
    class Mich2001Helmet_SURPAT : Mich2001Helmet
    {
        scope = 2;
        color = "SURPAT";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_12_co.paa",
            "iat_retextures\headgear\data\mich2001_12_co.paa",
            "iat_retextures\headgear\data\mich2001_12_co.paa"
        };
    };
    class Mich2001Helmet_MARPATWinter : Mich2001Helmet
    {
        scope = 2;
        color = "MARPATWinter";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\mich2001_19_co.paa",
            "iat_retextures\headgear\data\mich2001_19_co.paa",
            "iat_retextures\headgear\data\mich2001_19_co.paa"
        };
    };

    class LeatherHat_Choco : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Choco";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_choco_co.paa"
        };
    };
    class LeatherHat_Lime : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Lime";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_Lime_co.paa"
        };
    };
    class LeatherHat_Orange : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Orange";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_Orange_co.paa"
        };
    };
    class LeatherHat_Pink : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Pink";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_Pink_co.paa"
        };
    };
    class LeatherHat_Purple : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Purple";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_Purple_co.paa"
        };
    };
    class LeatherHat_Storm : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Storm";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_Storm_co.paa"
        };
    };
    class LeatherHat_Yellow : LeatherHat_ColorBase
    {
        scope = 2;
        color = "Yellow";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\hat_leather_Yellow_co.paa"
        };
    };

    class HeadCover_Improvised_green : HeadCover_Improvised
    {
        scope = 2;
        color = "green";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\headgear\data\headCover_improvised_green_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_green_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_green_CO.paa"
        };
    };
    class HeadCover_Improvised_black : HeadCover_Improvised
    {
        scope = 2;
        color = "black";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\headgear\data\headCover_improvised_black_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_black_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_black_CO.paa"
        };
    };
    class HeadCover_Improvised_orange : HeadCover_Improvised
    {
        scope = 2;
        color = "orange";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\headgear\data\headCover_improvised_orange_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_orange_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_orange_CO.paa"
        };
    };
    class HeadCover_Improvised_blue : HeadCover_Improvised
    {
        scope = 2;
        color = "blue";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\headgear\data\headCover_improvised_blue_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_blue_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_blue_CO.paa"
        };
    };
    class HeadCover_Improvised_Red : HeadCover_Improvised
    {
        scope = 2;
        color = "Red";
        hiddenSelectionsTextures[] =
        {
          "iat_retextures\headgear\data\headCover_improvised_red_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_red_CO.paa",
          "iat_retextures\headgear\data\headCover_improvised_red_CO.paa"
        };
    };

    class WitchHat_Blue : WitchHat
    {
        scope = 2;
        color = "Blue";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\headgear\data\witchhat_blue_co.paa" };
    };
    class WitchHat_BlueKitty : WitchHat
    {
        scope = 2;
        color = "BlueKitty";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\headgear\data\witchhat_BlueKitty_co.paa" };
    };
    class WitchHat_Pink : WitchHat
    {
        scope = 2;
        color = "Pink";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\headgear\data\witchhat_Pink_co.paa" };
    };
    class WitchHat_RedKitty : WitchHat
    {
        scope = 2;
        color = "RedKitty";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_retextures\headgear\data\witchhat_RedKitty_co.paa" };
    };

    class SantasHat_Elf : SantasHat
    {
        scope = 2;
        color = "Elf";
        hiddenSelections[] =
        {
            "camoGround",
            "camoMale",
            "camoFemale"
        };
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\headgear\data\santashatelf_co.paa",
            "iat_retextures\headgear\data\santashatelf_co.paa",
            "iat_retextures\headgear\data\santashatelf_co.paa"
        };
    };

    class CowboyHat_Mawboss : CowboyHat_ColorBase
    {
        scope = 2;
        visibilityModifier = 0.85;
        hiddenSelections[] = { "camoGround", "camoMale", "camoFemale" };
        hiddenSelectionsTextures[] = { "iat_retextures\headgear\data\iat_CowboyHat_mawboss_co.paa", "iat_retextures\headgear\data\iat_CowboyHat_mawboss_co.paa", "iat_retextures\headgear\data\iat_CowboyHat_mawboss_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_retextures\headgear\data\iat_cowboyhat.rvmat", "iat_retextures\headgear\data\iat_cowboyhat.rvmat", "iat_retextures\headgear\data\iat_cowboyhat.rvmat" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] = { {1, {"iat_retextures\headgear\data\iat_cowboyhat.rvmat"}}, {0.7, {"iat_retextures\headgear\data\iat_cowboyhat.rvmat"}}, {0.5, {"iat_retextures\headgear\data\iat_cowboyhat_damage.rvmat"}}, {0.3, {"iat_retextures\headgear\data\iat_cowboyhat_damage.rvmat"}}, {0, {"iat_retextures\headgear\data\iat_cowboyhat_destruct.rvmat"}} };
                };
            };
        };
    };

    class GhillieHood_Black : GhillieHood_ColorBase
    {
        scope = 2;
        color = "Black";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa",
            "iat_retextures\backpacks\data\ghillie_black_co.paa"
        };
    };
    class GhillieHood_White : GhillieHood_ColorBase
    {
        scope = 2;
        color = "White";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa",
            "iat_retextures\backpacks\data\ghillie_winter_co.paa"
        };
    };
};