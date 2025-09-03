class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Jackets
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Upper_Jackets"
		};
	};
};
class CfgVehicles
{
	class ALV_Coat_Base;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_Parka_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_Parka";
		colorVariants[] =
		{
			"Brown",
			"Olive",
			"Blue",
			"Black",
			"Beige",
		};
	};
	class ALV_WinterJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_WinterJacket";
		colorVariants[] =
		{
			"Grey",
			"Blue",
			"Black",
			"Brown",
			"Green",
			"Purple",
		};
	};
	class ALV_NauticJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_NauticJacket";
		colorVariants[] =
		{
			"Green",
			"YellowBlue",
			"Yellow",
			"Orange",
			"Black",
			"BlueWhite",
		};
	};
	class ALV_PlaidJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_PlaidJacket";
		colorVariants[] =
		{
			"Red",
			"Beige",
			"Brown",
		};
	};
	class ALV_MilitaryJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_MilitaryJacket";
		colorVariants[] =
		{
			"Black",
			"Tan",
			"Olive",
			"Blue",
		};
	};
	class ALV_DenimJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_DenimJacket";
		colorVariants[] =
		{
			"Blue",
			"Blue_Wool",
			"Black_Wool",
		};
	};
	class ALV_PCUL5Coat_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_PCUL5Coat";
		colorVariants[] =
		{
			"Grey",
			"Brown",
			"Tan",
			"Black",
			"Snow",
		};
	};
	class ALV_PatrolJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_PatrolJacket";
		colorVariants[] =
		{
			"Green",
			"Snow",
		};
	};
	class ALV_HuntingCoat_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_HuntingCoat";
		colorVariants[] =
		{
			"Brown",
			"Camo",
			"Camo2",
			"WinterCamo",
		};
	};
	class ALV_TweedJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_TweedJacket";
		colorVariants[] =
		{
			"Grey",
			"Brown",
		};
	};
	class ALV_HikingJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_HikingJacket";
		colorVariants[] =
		{
			"Yellow",
			"Orange",
			"Red",
			"Blue",
			"Black",
		};
	};
	class ALV_LightweightJacket_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_LightweightJacket";
		colorVariants[] =
		{
			"Tan",
			"Black",
			"Camo",
			"WinterCamo",
		};
	};
	class ALV_Duster_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_Duster";
		colorVariants[] =
		{
			"Black",
			"Brown",
			"Red",
		};
	};
	class ALV_Overcoat_Colorbase : ALV_Coat_Base
	{
		rootClassName = "ALV_Overcoat";
		colorVariants[] =
		{
			"Black",
			"Camel",
			"Brown",
		};
	};
};