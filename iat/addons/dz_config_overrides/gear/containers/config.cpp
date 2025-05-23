class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Containers
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Containers"
		};
	};
};
class CfgVehicles
{
	class Container_Base;

	// ----------------------  BASE GAME OVERRIDES
	class PlateCarrierPouches : Container_Base
	{
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 45.0,35.0,35.0,35.0 };
		rootClassName = "PlateCarrierPouches";
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
};