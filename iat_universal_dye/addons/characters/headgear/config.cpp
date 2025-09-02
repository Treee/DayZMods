class CfgPatches
{
	class IAT_Universal_Dye_Characters_Headgear
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Headgear"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	class Switchable_Base;
	//------------------------------------- BASE GAME OVERRIDE
	class BallisticHelmet_ColorBase : Clothing
	{
		rootClassName = "BallisticHelmet";
		colorVariants[] =
		{
		  "Green",
		  "Black",
		  "UN",
		  "BDU",
		  "Desert",
		  "Woodland",
		  "Winter",
		  "Navy",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		  "Rain"
		};
	};
	class HeadCover_Improvised : Clothing
	{
		rootClassName = "HeadCover_Improvised";
		colorVariants[] =
		{
		  "Green",
		  "Black",
		  "Orange",
		  "Blue",
		  "Red",
		};
	};
	class BaseballCap_ColorBase : Clothing
	{
		rootClassName = "BaseballCap";
		colorVariants[] =
		{
		  "Blue",
		  "Beige",
		  "Black",
		  "Olive",
		  "Pink",
		  "Red",
		  "Camo",
		  "CMMG_Black",
		  "CMMG_Pink",
		  "Lisiy",
		  "PoliceCap",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		  "Marshals",
		  "OregonPolice",
		  "BlackRanger",
		  "WaldoRescueGreen",
		  "WaldoRescueOrange",
		};
	};
	class ZSh3PilotHelmet : Clothing
	{
		rootClassName = "ZSh3PilotHelmet";
		colorVariants[] =
		{
		  "Green",
		  "Black",
		};
	};
	class ConstructionHelmet_ColorBase : Clothing
	{
		rootClassName = "ConstructionHelmet";
		colorVariants[] =
		{
		  "Blue",
		  "Lime",
		  "Orange",
		  "Red",
		  "White",
		  "Yellow"
		};
	};
	class BurlapSackCover : Clothing
	{
		rootClassName = "BurlapSackCover";
		colorVariants[] =
		{
		  "Black",
		  "Skull",
		  "White",
		};
	};
	class BeanieHat_ColorBase : Clothing
	{
		rootClassName = "BeanieHat";
		colorVariants[] =
		{
		  "Beige",
		  "Black",
		  "Blue",
		  "Brown",
		  "Green",
		  "Grey",
		  "Pink",
		  "Red",
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
	class Ushanka_ColorBase : Clothing
	{
		rootClassName = "Ushanka";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Green",
		  "Denim",
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
	class MotoHelmet_ColorBase : Clothing
	{
		rootClassName = "MotoHelmet";
		colorVariants[] =
		{
		  "Black",
		  "Grey",
		  "Green",
		  "Lime",
		  "Blue",
		  "Red",
		  "White",
		  "Yellow"
		};
	};
	class DarkMotoHelmet_ColorBase : Clothing
	{
		rootClassName = "DarkMotoHelmet";
		colorVariants[] =
		{
		  "Black",
		  "Grey",
		  "Green",
		  "Lime",
		  "Blue",
		  "Red",
		  "White",
		  "Yellow",
		  "YellowScarred"
		};
	};
	class Headtorch_ColorBase : Switchable_Base
	{
		rootClassName = "Headtorch";
		colorVariants[] =
		{
		  "Black",
		  "Grey"
		};
	};
	class Bandana_ColorBase : Clothing
	{
		rootClassName = "Bandana";
		colorVariants[] =
		{
		  "RedPattern",
		  "BlackPattern",
		  "PolkaPattern",
		  "GreenPattern",
		  "CamoPattern",
		  "Blue",
		  "Pink",
		  "Yellow",
		  "65Black",
		  "65Desert",
		  "65Tan",
		  "CheckBlue",
		  "CheckBlueBright",
		  "CheckGreen",
		  "Checkred",
		  "CheckWhite",
		  "Denim",
		  "Kamysh",
		  "USMC_D",
		  "USMC_W",
		};
	};
	class Shemag_ColorBase : Clothing
	{
		rootClassName = "Shemag";
		colorVariants[] =
		{
			"Brown",
			"Green",
			"Red",
			"White",
		};
	};
	class RadarCap_ColorBase : Clothing
	{
		rootClassName = "RadarCap";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Brown",
		  "Green",
		  "Red",
		};
	};
	class MilitaryBeret_ColorBase : Clothing
	{
		rootClassName = "MilitaryBeret";
		colorVariants[] =
		{
		  "Red",
		  "UN",
		  "NZ",
		  "ChDKZ",
		  "CDF"
		};
	};
	class FlatCap_ColorBase : Clothing
	{
		rootClassName = "FlatCap";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Red",
		  "Brown",
		  "Grey",
		  "BrownCheck",
		  "GreyCheck",
		  "BlackCheck",
		  "ERDL",
		  "Snow",
		  "Multicam",
		  "MulticamTropic",
		  "MulticamBlack"
		};
	};
	class ZmijovkaCap_ColorBase : Clothing
	{
		rootClassName = "ZmijovkaCap";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Brown",
		  "Green",
		  "Red",
		};
	};
	class CowboyHat_ColorBase : Clothing
	{
		rootClassName = "CowboyHat";
		colorVariants[] =
		{
		  "Brown",
		  "Black",
		  "DarkBrown",
		  "Green"
		};
	};
	class BoonieHat_ColorBase : Clothing
	{
		rootClassName = "BoonieHat";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "DPM",
		  "Dubok",
		  "Flecktran",
		  "NavyBlue",
		  "Olive",
		  "Orange",
		  "Red",
		  "Tan",
		  "Winter",
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
		  "Camo"
		};
	};
	class GorkaHelmet : Clothing
	{
		rootClassName = "GorkaHelmet";
		colorVariants[] =
		{
		  "Black",
		  "Green",
		};
	};
	class FirefightersHelmet_ColorBase : Clothing
	{
		rootClassName = "FirefightersHelmet";
		colorVariants[] =
		{
		  "Red",
		  "White",
		  "Yellow",
		};
	};
	class SkateHelmet_ColorBase : Clothing
	{
		rootClassName = "SkateHelmet";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Gray",
		  "Green",
		  "Red",
		};
	};
	class PrisonerCap : Clothing
	{
		rootClassName = "PrisonerCap";
		colorVariants[] =
		{
		  "Brown"
		};
	};
	class GhillieHood_ColorBase : Clothing
	{
		rootClassName = "GhillieHood";
		colorVariants[] =
		{
		  "Tan",
		  "Woodland",
		  "Mossy",
		  "Winter",
		};
	};
	class LeatherHat_ColorBase : Clothing
	{
		rootClassName = "LeatherHat";
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
	class MedicalScrubsHat_ColorBase : Clothing
	{
		rootClassName = "MedicalScrubsHat";
		colorVariants[] =
		{
		  "Blue",
		  "White",
		  "Green",
		};
	};
	class DirtBikeHelmet_ColorBase : Clothing
	{
		rootClassName = "DirtBikeHelmet";
		colorVariants[] =
		{
		  "Green",
		  "Chernarus",
		  "Khaki",
		  "Police",
		  "Red",
		  "Black",
		  "Blue",
		};
	};
	class NBCHoodBase : Clothing
	{
		rootClassName = "NBCHoodBase";
		colorVariants[] =
		{
		  "Gray",
		  "Yellow",
		  "Orange",
		  "White",
		};
	};
	class HockeyHelmet_ColorBase : Clothing
	{
		rootClassName = "HockeyHelmet";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Red",
		  "White",
		};
	};
	class SantasHat : Clothing
	{
		rootClassName = "SantasHat";
		colorVariants[] =
		{
		  "Elf",
		};
	};
	class WitchHood_ColorBase : Clothing
	{
		rootClassName = "WitchHood";
		colorVariants[] =
		{
		  "Black",
		  "Brown",
		  "Red",
		};
	};
	class WitchHoodCoif_ColorBase : Clothing
	{
		rootClassName = "WitchHoodCoif";
		colorVariants[] =
		{
		  "Black",
		  "Brown",
		  "Red",
		};
	};
	class WitchHat : Clothing
	{
		rootClassName = "WitchHat";
		colorVariants[] =
		{
		  "Blue",
		  "BlueKitty",
		  "Pink",
		  "RedKitty",
		};
	};
	class Mich2001Helmet : Clothing
	{
		rootClassName = "Mich2001Helmet";
		colorVariants[] =
		{
		  "EMP6",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		};
	};
	class WinterCoif_ColorBase : Clothing
	{
		rootClassName = "WinterCoif";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "Green",
		  "Skull",
		};
	};
	class OKZKCap_ColorBase : Clothing
	{
		rootClassName = "OKZKCap";
		colorVariants[] =
		{
		  "Beige",
		  "Green",
		};
	};
	class PetushokHat_ColorBase : Clothing
	{
		rootClassName = "PetushokHat";
		colorVariants[] =
		{
		  "Black",
		  "Yellow",
		  "Green",
		};
	};
	class ChristmasHeadband_ColorBase : Clothing
	{
		rootClassName = "ChristmasHeadband";
		colorVariants[] =
		{
		  "Anlters",
		  "Gingerbread",
		  "Trees",
		};
	};
	class SnowstormUshanka_ColorBase : Clothing
	{
		rootClassName = "SnowstormUshanka";
		colorVariants[] =
		{
		  "Brown",
		  "Navy",
		  "Olive",
		  "White",
		};
	};
	class BudenovkaHat_ColorBase : Clothing
	{
		rootClassName = "BudenovkaHat";
		colorVariants[] =
		{
		  "Gray",
		};
	};
	class SherpaHat_ColorBase : Clothing
	{
		rootClassName = "SherpaHat";
		colorVariants[] =
		{
		  "Red",
		  "Black",
		  "Blue",
		};
	};
	class LeafCrown_Colorbase : Clothing
	{
		rootClassName = "LeafCrown";
		colorVariants[] =
		{
		  "Spring",
		  "Summer",
		  "Autumn",
		  "Winter",
		};
	};
};