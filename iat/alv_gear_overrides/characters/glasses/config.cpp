class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Glasses
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Headgear_Glasses"
		};
	};
};
class CfgVehicles
{
	class ALV_GoggleBase;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_SkiGoggles_Colorbase : ALV_GoggleBase
	{
		rootClassName = "ALV_SkiGoggles";
		colorVariants[] =
		{
			"Black",
			"Blue",
			"Purple",
			"White",
		};
	};
};