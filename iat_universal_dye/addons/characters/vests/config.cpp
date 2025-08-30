class CfgPatches
{
	class IAT_Universal_Dye_Characters_Vests
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Vests"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class PlateCarrierVest : Clothing
	{
		rootClassName = "PlateCarrierVest";
		colorVariants[] =
		{
		  "Trader",
		  "Black",
		  "Green",
		  "Camo",
		  "Winter",
		  "White",
		  "Pseudo",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR2",
		  "USNAOR1",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		  "Lavender",
		  "Petal",
		  "Stone",
		  "Storm",
		  "Sunny",
		};
	};
	class PlateCarrierHolster : Clothing
	{
		rootClassName = "PlateCarrierHolster";
		colorVariants[] =
		{
		  "White",
		  "Pseudo",
		  "Tan",
		  "Green",
		  "Camo",
		  "Winter",
		  "Black",
		  "Lavender",
		  "Petal",
		  "Stone",
		  "Storm",
		  "Sunny",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR2",
		  "USNAOR1",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		};
	};
	class SmershVest : Clothing
	{
		rootClassName = "SmershVest";
		colorVariants[] =
		{
		  "White",
		  "Black",
		  "Green",
		  "Tan",
		  "Red",
		  "Purple",
		  "Blue",
		  "Pink",
		  "Olive",
		  "Storm",
		};
	};
	class PressVest_ColorBase : Clothing
	{
		rootClassName = "PressVest";
		colorVariants[] =
		{
		  "Black",
		  "Blue",
		  "LightBlue",
		  "ATFBlue",
		  "CIABlue",
		  "FBIBlue",
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
	class UKAssVest_ColorBase : Clothing
	{
		rootClassName = "UKAssVest"; // lol ass
		colorVariants[] =
		{
		  "Black",
		  "Camo",
		  "Khaki",
		  "Olive",
		  "Winter",
		  "White",
		};
	};
	class PoliceVest : Clothing
	{
		rootClassName = "PoliceVest";
		colorVariants[] =
		{
		  "Sheriff",
		  "ATF",
		  "CIA",
		  "FBI",
		  "NoLetters",
		};
	};
	class ChestHolster : Clothing
	{
		rootClassName = "ChestHolster";
		colorVariants[] =
		{
		  "Black",
		  "White",
		};
	};
	class HighCapacityVest_ColorBase : Clothing
	{
		rootClassName = "HighCapacityVest";
		colorVariants[] =
		{
		  "Black",
		  "Olive",
		  "Rain",
		  "ATFBlack",
		  "ATFOlive",
		  "CIABlack",
		  "CIAOlive",
		  "FBIBlack",
		  "FBIOlive",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR2",
		  "USNAOR1",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		};
	};
	class LeatherStorageVest_ColorBase : Clothing
	{
		rootClassName = "LeatherStorageVest";
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
	class HuntingVest : Clothing
	{
		rootClassName = "HuntingVest";
		colorVariants[] =
		{
		  "Leather",
		  "Winter",
		};
	};
};