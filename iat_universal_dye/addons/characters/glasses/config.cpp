class CfgPatches
{
	class IAT_Universal_Dye_Characters_Glasses
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Glasses"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class SportGlasses_ColorBase : Clothing
	{
		rootClassName = "SportGlasses";
		colorVariants[] =
		{
			"Black",
			"Blue",
			"Green",
			"Orange",
		};
	};
	class EyeMask_ColorBase : Clothing
	{
		rootClassName = "EyeMask";
		colorVariants[] =
		{
			"Valentines",
			"NewYears",
			"Christmas",
			"Dead",
			"Black",
			"Blue",
			"Red",
			"Yellow",
		};
	};
	class SkiGoggles_ColorBase : Clothing
	{
		rootClassName = "SkiGoggles";
		colorVariants[] =
		{
			"WhiteClear",
			"WhiteDark",
			"WhiteBlackYellow",
		};
	};
};