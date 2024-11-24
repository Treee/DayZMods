class CfgPatches
{
    class SRP_Core_Characters_Tops
    {
        units[] = {	};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Characters_Tops",
        };
    };
};
class CfgVehicles
{
    class Clothing;
    //----------------------------------- BASE GAME OVERRIDE
    class Armband_ColorBase : Clothing
    {
        inventorySlot[] +=
        {
            "Armband",
                "SRP_DisplayHook_SingleArmband",
        };
    };
    class NBCJacketBase : Clothing
    {
        heatIsolation = 0.80000001;
        absorbency = 0;
        rootClassName = "NBCJacketBase";
        colorVariants[] =
        {
          "Gray",
          "Yellow",
          "Orange",
          "White",
        };
        class Protection
        {
            biological = 1;
        };
    };
    class Sweater_ColorBase : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "Sweater";
        colorVariants[] =
        {
          "Gray",
          "Blue",
          "Green",
          "Red",
          "SantaRL",
          "SantaBlueRL",
          "SantaRedGreenRL",
          "SantaRedBlueRL",
        };
    };
    class Shirt_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "Shirt";
        colorVariants[] =
        {
          "BlueCheck",
          "BlueCheckBright",
          "GreenCheck",
          "PlainGreen",
          "RedCheck",
          "WhiteCheck",
          "PlaneBlack",
          "PlainDenim",
          "PlainGrey",
          "PlainBurgandy",
          "CatBlue",
          "CatLime",
          "CatPink",
          "PlainGrape",
          "PlainCat",
        };
    };
    class TShirt_ColorBase : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "TShirt";
        colorVariants[] =
        {
          "Beige",
          "Black",
          "Blue",
          "Green",
          "OrangeWhiteStripes",
          "Red",
          "RedBlackStripes",
          "White",
          "Grey",
          "PocketPals",
          "Mendel",
          "WhiteRabbit",
          "WhiteNY",
          "WhiteUnicorn",
          "WhiteDreams",
          "WhitePunk",
          "GotMilk",
          "RedSun",
          "Nirvana",
          "IronMaiden",
          "BlackRabbit",
          "BlackNY",
          "BlackUnicorn",
          "BlackDreams",
          "BlackCars",
          "BlackPunk",
          "Music",
          "Scream",
          "Rock",
          "Misfits",
          "Smiley",
          "Kids",
          "Piggy",
          "Catdog",
          "BlackCatdog",
          "BFFs",
          "Hipster",
          "Maori",
        };
    };
    class Hoodie_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "Hoodie";
        colorVariants[] =
        {
          "Blue",
          "Blue1",
          "Black",
          "Brown",
          "Brown1",
          "Green",
          "Grey",
          "Grey1",
          "Red",
          "Red1",
          "Purple",
          "Pink",
        };
    };
    class TacticalShirt_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,5 };
        rootClassName = "TacticalShirt";
        colorVariants[] =
        {
          "Grey",
          "Black",
          "Olive",
          "Tan",
          "Lime",
          "Green",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
          "ERDL",
          "Snow",
          "Multicam",
          "MulticamTropic",
          "MulticamBlack",
          "Flecktarn",
          "WaldoRescue"
        };
    };
    class HikingJacket_ColorBase : Clothing
    {
        rootClassName = "HikingJacket";
        colorVariants[] =
        {
          "Black",
          "Blue",
          "Red",
          "Green",
          "ChocChip",
          "CAD",
          "ERDL",
          "M05",
          "MARPAT",
          "MulticamBlack",
          "TigerStripe",
        };
    };
    class Raincoat_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "Raincoat";
        colorVariants[] =
        {
          "Orange",
          "Green",
          "Yellow",
          "Pink",
          "Red",
          "Blue",
          "Black",
          "Leather",
        };
    };
    class M65Jacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 8,6 };
        rootClassName = "M65Jacket";
        colorVariants[] =
        {
          "Black",
          "Khaki",
          "Tan",
          "Olive",
          "ATFBlack",
          "CIABlack",
          "FBIBlack",
          "MedicalBlack",
          "MedicalDpmDesert",
          "MedicalKhaki",
          "MedicalOlive",
          "MedicalTan",
          "Brown",
          "Grey",
          "RedPatches",
          "RedFaded",
          "Leather",
          "Leather1",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
        };
    };
    class GorkaEJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 8,5 };
        heatIsolation = 0.80000001;
        rootClassName = "GorkaEJacket";
        colorVariants[] =
        {
          "Summer",
          "Flat",
          "Autumn",
          "PautRev",
          "Blue",
          "Tan",
          "Brown",
          "Olive",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
          "ERDL",
          "ERDL2",
          "Snow",
          "Multicam",
          "MulticamTropic",
          "MulticamBlack",
          "MulticamBlack2",
          "CAD",
          "ChocChip",
          "M05",
          "MARPAT",
          "TigerStripe",
        };
    };
    class RidersJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "RidersJacket";
        colorVariants[] =
        {
          "Black",
          "Brown",
          "White",
          "Skull",
          "Heart",
          "Yoda",
          "RedSun",
          "Rabbit",
          "NY",
          "Nirvana",
          "IronMaiden",
          "Unicorn",
          "Dreams",
          "Punk",
          "UpInSmoke",
          "CheechNChong",
          "Exploited",
          "FlashGordon",
          "FuckYou",
          "Smiley1",
          "Heart1",
          "Schrodinger",
          "Rainbow",
          "SmileBeatles",
        };
    };
    class WoolCoat_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "WoolCoat";
        colorVariants[] =
        {
          "Black",
          "Red",
          "Blue",
          "Green",
          "Beige",
          "RedCheck",
          "BlackCheck",
          "BlueCheck",
          "GreyCheck",
          "BrownCheck",
          "Leather",
        };
    };
    class TrackSuitJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "TrackSuitJacket";
        colorVariants[] =
        {
          "Black",
          "Blue",
          "Green",
          "LightBlue",
          "Red",
          "Montana",
          "MTP",
          "ATAC",
        };
    };
    class PoliceJacket : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "PoliceJacket";
        colorVariants[] =
        {
          "Sheriff",
          "Sheriff1",
        };
    };
    class PoliceJacketOrel : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "PoliceJacketOrel";
        colorVariants[] =
        {
          "WinterCamo",
          "Swat",
        };
    };
    class ParamedicJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "ParamedicJacket";
        colorVariants[] =
        {
          "Blue",
          "Crimson",
          "Green",
          "BlackMedic",
          "WaldoRescue"
        };
    };
    class FirefighterJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "FirefighterJacket";
        colorVariants[] =
        {
          "Beige",
          "Black",
        };
    };
    class PrisonUniformJacket : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "PrisonUniformJacket";
        colorVariants[] =
        {
          "Beige",
          "Black",
          "HawaiianMultiLeaf",
          "HawaiianPalmLeaf",
          "HawaiianFlowers",
          "Leather"
        };
    };
    class MiniDress_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        rootClassName = "MiniDress";
        colorVariants[] =
        {
          "Pink",
          "PinkChecker",
          "RedChecker",
          "WhiteChecker",
          "GreenChecker",
          "BrownChecker",
          "BlueChecker",
          "BlueWithDots",
          "Leather",
        };
    };
    class QuiltedJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "QuiltedJacket";
        colorVariants[] =
        {
          "Black",
          "Green",
          "Blue",
          "Red",
          "Grey",
          "Orange",
          "Yellow",
          "Violet",
          "Puffy",
          "Brown",
          "Denim",
          "White",
          "Blarg",
          "BlueStripe",
          "PinkPaw",
          "SnowFancy",
          "HeartBlue",
          "HeartPink",
          "HeartPurple",
          "DarkBlueStripe",
          "DarkPurpleStripe",
          "GreyStripe",
          "PinkPinkStripe",
          "Rose",
          "SnowPink",
          "SnowWhite",
          "TealYellowStripe",
        };
    };
    class BomberJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "BomberJacket";
        colorVariants[] =
        {
          "Black",
          "Black2",
          "Black3",
          "Brown",
          "Grey",
          "Maroon",
          "Olive",
          "SkyBlue",
          "Devil",
          "Leather",
        };
    };
    class LeatherJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "LeatherJacket";
        colorVariants[] =
        {
          "Natural",
          "Beige",
          "Brown",
          "Black",
        };
    };
    class HuntingJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "HuntingJacket";
        colorVariants[] =
        {
          "Autumn",
          "Brown",
          "Spring",
          "Summer",
          "Winter",
          "Black",
          "Black1",
          "RainJacket",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
          "Gold",
          "Grape",
          "Navy",
          "Red",
          "Leather",
          "GreenCamo",
          "BrownCamo",
          "PurpleCamo",
          "DarkGreenCamo",
          "RedCamo",
          "WhiteSkull",
          "TanSkull",
          "PurpleSkull",
          "BlueSkull",
          "BlackSkull",
          "SpringRanger",
          "NinjaPurple",
          "NinjaRed",
          "NinjaLemon",
          "NinjaLime",
          "NinjaPink",
          "NinjaSky",
        };
    };
    class LeatherShirt_ColorBase : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "LeatherShirt";
        colorVariants[] =
        {
          "Natural",
          "Choco",
          "Lime",
          "Orange",
          "Pink",
          "Purple",
          "Storm",
          "Yellow",
        };
    };
    class TTsKOJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "TTsKOJacket";
        colorVariants[] =
        {
          "Camo",
          "Tan",
        };
    };
    class MedicalScrubsShirt_ColorBase : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "MedicalScrubsShirt";
        colorVariants[] =
        {
          "Blue",
          "Green",
          "White",
        };
    };
    class NurseDress_ColorBase : Clothing
    {
        itemsCargoSize[] = { 5,4 };
        heatIsolation = 0.80000001;
        rootClassName = "NurseDress";
        colorVariants[] =
        {
          "White",
          "Blue",
          "BlackGrape",
          "BlackGreen",
          "BlackMint",
          "BlackOcean",
          "BlackPink",
          "BlackRed",
          "BlackSnow",
          "BlackStorm",
          "BlackSunny",
          "BlackWhite",
          "BlueYellow",
          "GreenBlack",
          "GreenBlackBow",
          "PinkWhite",
          "WhiteBowBlue",
          "WhiteBowGreen",
          "WhiteBowPink",
        };
    };
    class USMCJacket_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "USMCJacket";
        colorVariants[] =
        {
          "Desert",
          "Woodland",
        };
    };
    class Blouse_ColorBase : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "Blouse";
        colorVariants[] =
        {
          "Blue",
          "White",
          "Green",
          "Violet",
          "Leather",
        };
    };
    class DenimJacket : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "DenimJacket";
        colorVariants[] =
        {
          "Black",
          "Leather",
        };
    };
    class JumpsuitJacket_ColorBase : Clothing
    {
        rootClassName = "JumpsuitJacket";
        colorVariants[] =
        {
          "Blue",
          "Gray",
          "Green",
          "Red",
          "ATFBlue",
          "CIABlue",
          "FBIBlue",
        };
    };
    class ManSuit_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "ManSuit";
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
    class WomanSuit_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "WomanSuit";
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
        };
    };
    class TorsoCover_Improvised : Clothing
    {
        itemsCargoSize[] = { 4,3 };
        rootClassName = "TorsoCover_Improvised";
        colorVariants[] =
        {
          "Green",
          "Black",
          "Orange",
          "Blue",
          "Red",
        };
    };
    class BDUJacket : Clothing
    {
        itemsCargoSize[] = { 7,6 };
        rootClassName = "BDUPants";
        colorVariants[] =
        {
          "CCE",
        };
    };
    class LabCoat : Clothing
    {
        rootClassName = "LabCoat";
        colorVariants[] =
        {
          "BlackSpace",
          "Bloody",
        };
    };
    class Chainmail : Clothing
    {
        itemsCargoSize[] = { 4,4 };
    };

};