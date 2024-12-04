class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Pants
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Pants"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class Jeans_ColorBase : Clothing
	{
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
		rootClassName = "TTSKOPants";
		colorVariants[] =
		{
		  "Green",
		  "Tan",
		};
	};
	class HunterPants_ColorBase : Clothing
	{
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
		rootClassName = "PolicePants";
		colorVariants[] =
		{
		  "Sheriff1",
		  "Sheriff2",
		};
	};
	class PolicePantsOrel : Clothing
	{
		rootClassName = "PolicePantsOrel";
		colorVariants[] =
		{
		  "SWAT",
		  "WinterCamo",
		};
	};
	class ParamedicPants_ColorBase : Clothing
	{
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
		rootClassName = "FirefightersPants";
		colorVariants[] =
		{
		  "Beige",
		  "Black",
		};
	};
	class PrisonUniformPants : Clothing
	{
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
		rootClassName = "USMCPants";
		colorVariants[] =
		{
		  "Desert",
		  "Woodland",
		};
	};
	class SlacksPants_ColorBase : Clothing
	{
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
		rootClassName = "BDUPants";
		colorVariants[] =
		{
		  "CCE",
		};
	};

};