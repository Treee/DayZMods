class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Masks
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Headgear_Masks"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_SkullMask_Colorbase : Clothing
	{
		rootClassName = "ALV_SkullMask";
		colorVariants[] =
		{
			"Black",
			"Brown",
		};
	};
};