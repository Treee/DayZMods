class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Backpacks
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Other_Backpacks"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_HipsterBag_Colorbase : Clothing
	{
		rootClassName = "ALV_HipsterBag";
		colorVariants[] =
		{
			"Blue",
			"Black",
			"Green",
		};
	};
	class ALV_MilitaryBag_Colorbase : Clothing
	{
		rootClassName = "ALV_MilitaryBag";
		colorVariants[] =
		{
			"Tan",
			"Black",
		};
	};
	class ALV_LargeTrailBag_Colorbase : Clothing
	{
		rootClassName = "ALV_LargeTrailBag";
		colorVariants[] =
		{
			"Blue",
			"Black",
			"Orange",
		};
	};
	class ALV_SmallBackpack_Colorbase : Clothing
	{
		rootClassName = "ALV_SmallBackpack";
		colorVariants[] =
		{
			"Blue",
			"Red",
			"Pink",
		};
	};
	class ALV_CanvasBag_Colorbase : Clothing
	{
		rootClassName = "ALV_CanvasBag";
		colorVariants[] =
		{
			"Green",
			"Black",
			"Yellow",
		};
	};
};