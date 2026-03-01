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

	//------------------------------------- RETEXTURES
    class ALV_6B25Vest_nekomaid_chan : ALV_6B25Vest_Colorbase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat\alv_gear_overrides\characters\vests\data\StagVest_nekomain_chan_CO.paa" };
    };
    class ALV_6B25Vest_grimstif : ALV_6B25Vest_Colorbase
    {
        scope = 2;
        hiddenSelectionsTextures[] = { "iat\alv_gear_overrides\characters\vests\data\StagVest_grimstif_CO.paa" };
    };
};