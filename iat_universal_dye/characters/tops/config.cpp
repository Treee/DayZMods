class CfgPatches
{
	class IAT_Universal_Dye_Characters_Tops
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Tops"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class DownJacket_ColorBase : Clothing
	{
		rootClassName = "DownJacket";
		colorVariants[] =
		{
		  "Blue",
		  "Red",
		  "Orange",
		  "Green",
		};
	};
	class Armband_ColorBase : Clothing
	{
		rootClassName = "Armband";
		colorVariants[] =
		{
			"White",
			"Yellow",
			"Orange",
			"Red",
			"Green",
			"Pink",
			"Blue",
			"Black",
			"Chernarus",
			"Chedaki",
			"NAPA",
			"CDF",
			"Livonia",
			"Altis",
			"SSahrani",
			"NSahrani",
			"DayZ",
			"LivoniaArmy",
			"Bohemia",
			"APA",
			"UEC",
			"Pirates",
			"Cannibals",
			"Bear",
			"Wolf",
			"BabyDeer",
			"Rooster",
			"LivoniaPolice",
			"CMC",
			"TEC",
			"CHEL",
			"Zenit",
			"HunterZ",
			"BrainZ",
			"Refuge",
			"RSTA",
			"Snake",
			"Crook",
			"Rex",
			"Zagorky",
		};
	};
	class NBCJacketBase : Clothing
	{
		rootClassName = "NBCJacketBase";
		colorVariants[] =
		{
		  "Gray",
		  "Yellow",
		  "Orange",
		  "White",
		};
	};
	class Sweater_ColorBase : Clothing
	{
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
	class Sweater_ChristmasColorbase : Clothing
	{
		rootClassName = "Sweater";
		colorVariants[] =
		{
		  "ChristmasBlue",
		  "ChristmasGreen",
		  "ChristmasRed",
		};
	};
	class Shirt_ColorBase : Clothing
	{
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
		rootClassName = "TShirt";
		colorVariants[] =
		{
		  "Beige",
		  "Black",
		  "Blue",
		  "Dyed",
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
		rootClassName = "GorkaEJacket";
		colorVariants[] =
		{
		  "Summer",
		  "Flat",
		  "Autumn",
		  "PautRev",
		  "Winter",
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
		rootClassName = "PoliceJacket";
		colorVariants[] =
		{
		  "Sheriff",
		  "Sheriff1",
		};
	};
	class PoliceJacketOrel : Clothing
	{
		rootClassName = "PoliceJacketOrel";
		colorVariants[] =
		{
		  "WinterCamo",
		  "Swat",
		};
	};
	class BushlatPoliceJacket_ColorBase : Clothing
	{
		rootClassName = "BushlatPoliceJacket";
		colorVariants[] =
		{
		  "Blue",
		};
	};
	class ParamedicJacket_ColorBase : Clothing
	{
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
		rootClassName = "FirefighterJacket";
		colorVariants[] =
		{
		  "Beige",
		  "Black",
		};
	};
	class PrisonUniformJacket : Clothing
	{
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
		rootClassName = "TTsKOJacket";
		colorVariants[] =
		{
		  "Camo",
		  "Tan",
		};
	};
	class MedicalScrubsShirt_ColorBase : Clothing
	{
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
		rootClassName = "USMCJacket";
		colorVariants[] =
		{
		  "Desert",
		  "Woodland",
		};
	};
	class OMKJacket_ColorBase : Clothing
	{
		rootClassName = "OMKJacket";
		colorVariants[] =
		{
		  "Navy",
		};
	};
	class Blouse_ColorBase : Clothing
	{
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
};