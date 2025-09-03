class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Pants
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Lower_Pants"
		};
	};
};
class CfgVehicles
{
	class ALV_Pants_Base;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_Jeans_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_Jeans";
		colorVariants[] =
		{
			"Black",
			"Blue",
			"Grey",
			"Brown",
		};
	};
	class ALV_Sheriffpants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_Sheriffpants";
		colorVariants[] =
		{
			"Brown",
			"Olive",
		};
	};
	class ALV_Cargopants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_Cargopants";
		colorVariants[] =
		{
			"Beige",
			"Black",
		};
	};
	class ALV_FirefighterPants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_FirefighterPants";
		colorVariants[] =
		{
			"Beige",
			"Black",
		};
	};
	class ALV_PatrolPants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_PatrolPants";
		colorVariants[] =
		{
			"Snow",
			"Green",
			"STG_Red",
		};
	};
	class ALV_G3Pants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_G3Pants";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"MC",
			"Snow",
		};
	};
	class ALV_HunterPants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_HunterPants";
		colorVariants[] =
		{
			"Tan",
			"Black",
			"Camo",
			"WinterCamo",
		};
	};
	class ALV_CargoShorts_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_CargoShorts";
		colorVariants[] =
		{
			"Tan",
			"Olive",
		};
	};
	class ALV_SmartPants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_SmartPants";
		colorVariants[] =
		{
			"Grey",
			"Brown",
		};
	};
	class ALV_HunterPants_Kneepads_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_HunterPants_Kneepads";
		colorVariants[] =
		{
			"Tan",
			"Black",
			"Camo",
			"WinterCamo",
		};
	};
	class ALV_PolicePants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_PolicePants";
		colorVariants[] =
		{
			"Grey",
			"Blue",
			"Brown",
			"Tan",
			"Black",
		};
	};
	class ALV_NBCPants_ColorBase : ALV_Pants_Base
	{
		rootClassName = "ALV_NBCPants";
		colorVariants[] =
		{
			"Green",
			"Yellow",
			"MC",
			"White",
		};
	};
};