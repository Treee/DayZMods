class CfgPatches
{
	class IAT_Universal_Dye_Gear_Containers
	{
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
		rootClassName = "PlateCarrierPouches";
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
};