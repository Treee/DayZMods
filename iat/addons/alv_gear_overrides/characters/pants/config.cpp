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
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_Jeans_ColorBase : Clothing
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
	class ALV_Sheriffpants_ColorBase : Clothing
	{
		rootClassName = "ALV_Sheriffpants";
		colorVariants[] =
		{
			"Brown",
			"Olive",
		};
	};
	class ALV_Cargopants_ColorBase : Clothing
	{
		rootClassName = "ALV_Cargopants";
		colorVariants[] =
		{
			"Beige",
			"Black",
		};
	};
	class ALV_FirefighterPants_ColorBase : Clothing
	{
		rootClassName = "ALV_FirefighterPants";
		colorVariants[] =
		{
			"Beige",
			"Black",
		};
	};
	class ALV_PatrolPants_ColorBase : Clothing
	{
		rootClassName = "ALV_PatrolPants";
		colorVariants[] =
		{
			"Snow",
			"Green",
			"STG_Red",
		};
	};
	class ALV_G3Pants_ColorBase : Clothing
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
	class ALV_HunterPants_ColorBase : Clothing
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
	class ALV_CargoShorts_ColorBase : Clothing
	{
		rootClassName = "ALV_CargoShorts";
		colorVariants[] =
		{
			"Tan",
			"Olive",
		};
	};
	class ALV_SmartPants_ColorBase : Clothing
	{
		rootClassName = "ALV_SmartPants";
		colorVariants[] =
		{
			"Grey",
			"Brown",
		};
	};
	class ALV_HunterPants_Kneepads_ColorBase : Clothing
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
	class ALV_PolicePants_ColorBase : Clothing
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
	class ALV_NBCPants_ColorBase : Clothing
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