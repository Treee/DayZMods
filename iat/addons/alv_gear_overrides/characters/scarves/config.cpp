class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Scarves
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Headgear_Scarves"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_ShemaghScarf_Colorbase : Clothing
	{
		rootClassName = "ALV_ShemaghScarf";
		colorVariants[] =
		{
			"White",
			"Yellow",
			"Red",
			"Purple",
			"Black",
			"Classic",
		};
	};
	class ALV_TatteredPoncho_Colorbase : Clothing
	{
		rootClassName = "ALV_TatteredPoncho";
		colorVariants[] =
		{
			"Black",
			"Brown",
		};
	};
	class ALV_TatteredPoncho_Hooddown_Colorbase : Clothing
	{
		rootClassName = "ALV_TatteredPoncho_Hooddown";
		colorVariants[] =
		{
			"Black",
			"Brown",
		};
	};

	class ALV_Balaclava_Open_Colorbase : Clothing
	{
		rootClassName = "ALV_Balaclava_Open";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Snow",
		};
	};
	class ALV_Balaclava_Colorbase : Clothing
	{
		rootClassName = "ALV_Balaclava";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Snow",
		};
	};
	class ALV_Balaclava_FaceCover_Colorbase : Clothing
	{
		rootClassName = "ALV_Balaclava_FaceCover";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Snow",
		};
	};
	class ALV_Scarf01_Colorbase : Clothing
	{
		rootClassName = "ALV_Scarf01";
		colorVariants[] =
		{
			"Red",
			"Yellow",
			"Black",
			"Cream",
		};
	};
	class ALV_Scarf02_Colorbase : Clothing
	{
		rootClassName = "ALV_Scarf02";
		colorVariants[] =
		{
			"Red",
			"Yellow",
			"Black",
			"Cream",
		};
	};
	class ALV_Scarf03_Colorbase : Clothing
	{
		rootClassName = "ALV_Scarf03";
		colorVariants[] =
		{
			"Red",
			"Yellow",
			"Black",
			"Cream",
		};
	};
	class ALV_HoodedShawl_Colorbase : Clothing
	{
		rootClassName = "ALV_HoodedShawl";
		colorVariants[] =
		{
			"Red",
			"Black",
			"Green",
			"Red",
		};
	};
};