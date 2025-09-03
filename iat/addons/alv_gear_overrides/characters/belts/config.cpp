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
	class ALV_BeltBase;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_BisonBelt_Colorbase : ALV_BeltBase
	{
		rootClassName = "ALV_BisonBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_UtilityBelt_Colorbase : ALV_BeltBase
	{
		rootClassName = "ALV_UtilityBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_LeatherBelt_Colorbase : ALV_BeltBase
	{
		rootClassName = "ALV_LeatherBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_MolleBelt_Colorbase : ALV_BeltBase
	{
		rootClassName = "ALV_MolleBelt";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_Smersh_Colorbase : ALV_BeltBase
	{
		rootClassName = "ALV_Smersh";
		colorVariants[] =
		{
			"Black",
			"Tan",
		};
	};
	class ALV_FannyPack_Colorbase : ALV_BeltBase
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