class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Vests
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
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
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 75.0,60.0,50.0,50.0 };
		rootClassName = "PlateCarrierVest";
		colorVariants[] =
		{
		  "Trader",
		  "Black",
		  "Green",
		  "Camo",
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
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 35.0,30.0,25.0,25.0 };
		rootClassName = "PlateCarrierHolster";
		colorVariants[] =
		{
		  "White",
		  "Pseudo",
		  "Tan",
		  "Green",
		  "Camo",
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
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 45.0,45.0,45.0,45.0 };
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
		itemsCargoSize[] = { 6,5 };
		rootClassName = "UKAssVest";
		colorVariants[] =
		{
		  "Black",
		  "Camo",
		  "Khaki",
		  "Olive",
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
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 60.0,50.0,40.0,40.0 };
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
		};
	};
};