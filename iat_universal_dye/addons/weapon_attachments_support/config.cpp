class CfgPatches
{
	class IAT_Universal_Dye_Weapon_Attachments_Support
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Weapons_Supports"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;

	// ----------------------  BASE GAME OVERRIDES
	class GhillieAtt_ColorBase : Inventory_Base
	{
		rootClassName = "GhillieAtt";
		colorVariants[] =
		{
		  "Tan",
		  "Woodland",
		  "Mossy",
		  "Winter",
		  "White",
		  "Black",
		};
	};
};