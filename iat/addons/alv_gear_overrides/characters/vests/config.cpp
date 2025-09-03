class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Vests
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Upper_Vests"
		};
	};
};
class CfgVehicles
{
	class ALV_Vest_Base;
	class ALV_Large_Vest_Base;
	class ALV_UAVest_Base;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_ModularVest_Colorbase : ALV_Vest_Base
	{
		rootClassName = "ALV_ModularVest";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Snow",
		};
	};
	class ALV_JPCVest_Colorbase : ALV_Vest_Base
	{
		rootClassName = "ALV_JPCVest";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Snow",
		};
	};
	class ALV_6B25Vest_Colorbase : ALV_Large_Vest_Base
	{
		rootClassName = "ALV_6B25Vest";
		colorVariants[] =
		{
			"Black",
			"Green",
			"Snow",
		};
	};
	class ALV_BikerVest_Colorbase : ALV_UAVest_Base
	{
		rootClassName = "ALV_BikerVest";
		colorVariants[] =
		{
			"Brown",
			"Black_Angel",
		};
	};
	class ALV_AssaultVest_Colorbase : ALV_Vest_Base
	{
		rootClassName = "ALV_AssaultVest";
		colorVariants[] =
		{
			"Tan",
			"Black",
		};
	};
	class ALV_ChestRig_Colorbase : ALV_Vest_Base
	{
		rootClassName = "ALV_ChestRig";
		colorVariants[] =
		{
			"Olive",
			"Brown",
		};
	};
};