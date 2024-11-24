class CfgPatches
{
    class SRP_Core_Characters_Pants
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Characters_Pants",
        };
    };
};
class CfgVehicles
{
    class Clothing;

    //-------------------------------------BASE GAME OVERRIDE
    class Jeans_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "Jeans";
        colorVariants[] =
        {
          "Black",
          "Blue",
          "Blue1",
          "Brown",
          "Green",
          "Grey",
          "BlueDark",
          "Orange",
          "Lime",
          "Moss",
          "Pink",
          "Purple",
          "Red",
          "Rose",
          "Teal",
          "Yellow",
          "CadPat_Green",
          "CadPat_Blue",
        };
    };
    class CargoPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,4 };
        rootClassName = "CargoPants";
        colorVariants[] =
        {
          "Beige",
          "Black",
          "Blue",
          "Green",
          "Grey",
          "Janek",
          "Rain",
          "Bandit",
          "Bandit1",
          "Bandit2",
          "Bandit3",
          "Denim",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "Sumrak",
          "MarpatWinter",
          "EMP6",
          "Snow",
          "Tan",
          "Olive",
          "Brown1",
          "Blue2",
          "ERDL",
          "ChocChip",
          "CADPAT",
          "M05",
          "MARPAT",
          "MulticamBlack",
          "TigerStripe",
        };
    };
    class TTSKOPants : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "TTSKOPants";
        colorVariants[] =
        {
          "Green",
          "Tan",
        };
    };
    class HunterPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 8,6 };
        rootClassName = "HunterPants";
        colorVariants[] =
        {
          "Autumn",
          "Brown",
          "Spring",
          "Summer",
          "Winter",
          "Black",
          "Grey",
          "MTP",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
          "TigerCamo",
          "OldCamo",
          "SpringRanger",
          "WaldoRescue",
          "NinjaBrown",
          "NinjaLemon",
          "NinjaPink",
          "NinjaPurple",
          "NinjaSky",
          "OdinBlue",
          "OdinGreen",
          "OdinWine",
          "OdinYellow",
        };
    };
    class CanvasPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "CanvasPants";
        colorVariants[] =
        {
          "Beige",
          "Blue",
          "Grey",
          "Red",
          "Violet",
          "Leather",
          "BlueJeans",
          "DarkBlueJeans",
          "Forest",
          "Pink",
        };
    };
    class CanvasPantsMidi_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "CanvasPantsMidi";
        colorVariants[] =
        {
          "Beige",
          "Blue",
          "Grey",
          "Red",
          "Violet",
          "Leather",
          "BlueJeans",
          "DarkBlueJeans",
          "Forest",
          "Pink",
        };
    };
    class TrackSuitPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "TrackSuitPants";
        colorVariants[] =
        {
          "Black",
          "Blue",
          "Green",
          "Red",
          "LightBlue",
          "Montana",
          "MTP",
          "ATAC",
        };
    };
    class GorkaPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 8,6 };
        heatIsolation = 0.80000001;
        rootClassName = "GorkaPants";
        colorVariants[] =
        {
          "Summer",
          "Autumn",
          "Flat",
          "PautRev",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "Marpat",
          "MARPATWinter",
          "EMP6",
          "ERDL",
          "Snow",
          "Multicam",
          "MulticamTropic",
          "MulticamBlack",
          "CAD",
          "ChocChip",
          "M05",
          "TigerStripe",
        };
    };
    class PolicePants : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "PolicePants";
        colorVariants[] =
        {
          "Sheriff1",
          "Sheriff2",
        };
    };
    class PolicePantsOrel : Clothing
    {
        itemsCargoSize[] = { 6,4 };
        rootClassName = "PolicePantsOrel";
        colorVariants[] =
        {
          "SWAT",
          "WinterCamo",
        };
    };
    class ParamedicPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,4 };
        rootClassName = "ParamedicPants";
        colorVariants[] =
        {
          "Blue",
          "Crimson",
          "Green",
          "Black",
        };
    };
    class FirefightersPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,4 };
        rootClassName = "FirefightersPants";
        colorVariants[] =
        {
          "Beige",
          "Black",
        };
    };
    class PrisonUniformPants : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "PrisonUniformPants";
        colorVariants[] =
        {
          "Black",
          "Blue",
          "Leather",
        };
    };
    class LeatherPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,4 };
        rootClassName = "LeatherPants";
        colorVariants[] =
        {
          "Natural",
          "Beige",
          "Brown",
          "Black",
          "Choco",
          "Lime",
          "Orange",
          "Pink",
          "Purple",
          "Storm",
          "Yellow",
        };
    };
    class MedicalScrubsPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "MedicalScrubsPants";
        colorVariants[] =
        {
          "Blue",
          "Green",
          "White"
        };
    };
    class USMCPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "USMCPants";
        colorVariants[] =
        {
          "Desert",
          "Woodland",
        };
    };
    class SlacksPants_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "SlacksPants";
        colorVariants[] =
        {
          "Beige",
          "Black",
          "Blue",
          "Brown",
          "DarkGrey",
          "Khaki",
          "LightGrey",
          "White",
          "TweedBlack",
          "TweedGrey",
          "TweedNavy",
          "TweedSalmon",
        };
    };
    class NBCPantsBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "NBCPantsBase";
        colorVariants[] =
        {
          "Orange",
          "Gray",
          "Yellow",
          "White",
        };
        class Protection
        {
            biological = 1;
        };
    };
    class Breeches_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "Breeches";
        colorVariants[] =
        {
          "Beige",
          "Beetcheck",
          "Black",
          "Black1",
          "Blackcheck",
          "Blue",
          "Blue1",
          "Browncheck",
          "Green",
          "White",
          "Red",
          "Pink",
        };
    };
    class ShortJeans_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "ShortJeans";
        colorVariants[] =
        {
          "Black",
          "Black1",
          "Blue",
          "Brown",
          "DarkBlue",
          "Green",
          "Red",
          "Grape",
          "Snow",
          "Leather"
        };
    };
    class Skirt_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "Skirt";
        colorVariants[] =
        {
          "Blue",
          "Red",
          "White",
          "Yellow",
        };
    };
    class JumpsuitPants_ColorBase : Clothing
    {
        rootClassName = "JumpsuitPants";
        colorVariants[] =
        {
          "Blue",
          "Green",
          "Grey",
          "Red",
        };
    };
    class LegsCover_Improvised : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "LegsCover_Improvised";
        colorVariants[] =
        {
          "Green",
          "Black",
          "Orange",
          "Blue",
          "Red",
        };
    };
    class BDUPants : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "BDUPants";
        colorVariants[] =
        {
          "CCE",
        };
    };
    class Chainmail_Leggings : Clothing
    {
        itemsCargoSize[] = { 4,4 };
    };

};