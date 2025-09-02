class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Headgear
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Headgear_Headgear"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_Comtacs_Colorbase : Clothing
	{
		rootClassName = "ALV_Comtacs";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"MC",
			"Snow",
		};
	};

	class ALV_Beret_Colorbase : Clothing
	{
		rootClassName = "ALV_Beret";
		colorVariants[] =
		{
			"Green",
			"Blue",
		};
	};

	class ALV_Boonie_Colorbase : Clothing
	{
		rootClassName = "ALV_Boonie";
		colorVariants[] =
		{
			"Tan",
			"Black",
			"Green",
			"MC",
		};
	};
	class ALV_Beanie_Colorbase : Clothing
	{
		rootClassName = "ALV_Beanie";
		colorVariants[] =
		{
			"Black",
			"Grey",
			"Pink",
			"Red",
			"WinterCamo",
			"Orange",
			"Green",
			"Camo",
		};
	};
	class ALV_TacCap_Colorbase : Clothing
	{
		rootClassName = "ALV_TacCap";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Snow",
		};
	};
	class ALV_BaseballCap_Forwards_Colorbase : Clothing
	{
		rootClassName = "ALV_BaseballCap_Forwards";
		colorVariants[] =
		{
			"Beige",
			"Green",
			"Brown",
		};
	};

	class ALV_BaseballCap_Backwards_Colorbase : Clothing
	{
		rootClassName = "ALV_BaseballCap_Backwards";
		colorVariants[] =
		{
			"Beige",
			"Green",
			"Brown",
		};
	};
};