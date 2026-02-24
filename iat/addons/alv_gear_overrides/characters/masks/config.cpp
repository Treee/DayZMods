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
	class ALV_Mask_Base;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_SkullMask_Colorbase : ALV_Mask_Base
	{
		rootClassName = "ALV_SkullMask";
		colorVariants[] =
		{
			"Black",
			"Brown",
		};
	};

	//------------------------------------- RETEXTURES
    class ALV_SkullMask_Kalli : ALV_SkullMask_Colorbase
    {
        scope = 2;
        // color = "Kalli";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat\alv_gear_overrides\characters\masks\data\skullMask_kalli_CO.paa" };
    };
};