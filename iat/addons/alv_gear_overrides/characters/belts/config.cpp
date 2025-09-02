class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Belts
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Lower_Belts"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_BisonBelt_Colorbase : Clothing
	{
		rootClassName = "ALV_BisonBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_UtilityBelt_Colorbase : Clothing
	{
		rootClassName = "ALV_UtilityBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_LeatherBelt_Colorbase : Clothing
	{
		rootClassName = "ALV_LeatherBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_MolleBelt_Colorbase : Clothing
	{
		rootClassName = "ALV_MolleBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_Smersh_Colorbase : Clothing
	{
		rootClassName = "ALV_Smersh";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_FannyPack_Colorbase : Clothing
	{
		rootClassName = "ALV_FannyPack";
		colorVariants[] =
		{
			"Green",
			"Pink",
			"Brown",
			"Blue",
			"Black",
		};
	};
};