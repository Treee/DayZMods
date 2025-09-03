class CfgPatches
{
	class IAT_Universal_Dye_ALV_Gear_Overrides_Tops
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"ACO_Upper_Tops"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	class ALV_Top_Base;
	class ALV_Outfit_Base;
	//------------------------------------- BASE GAME OVERRIDE
	class ALV_CottonTop_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_CottonTop";
		colorVariants[] =
		{
			"Grey",
			"Tan",
			"Olive",
			"Brown",
			"Black",
			"BlackWhite",
		};
	};
	class ALV_RaglanTshirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_RaglanTshirt";
		colorVariants[] =
		{
			"BlackWhite",
			"WhiteBlack",
			"Teal",
			"Tan",
			"Red",
			"Pink",
			"Blue",
		};
	};
	class ALV_TacticalHoodie_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_TacticalHoodie";
		colorVariants[] =
		{
			"Grey",
			"Tan",
			"Red",
			"Olive",
			"MC",
			"EMR",
			"Black",
		};
	};
	class ALV_FlannelShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_FlannelShirt";
		colorVariants[] =
		{
			"White",
			"Yellow",
			"Red2",
			"Red",
			"Blue",
		};
	};
	class ALV_SheriffShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_SheriffShirt";
		colorVariants[] =
		{
			"Plain",
			"Tan",
		};
	};
	class ALV_Tshirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_Tshirt";
		colorVariants[] =
		{
			"Beige",
			"Grey",
			"White",
			"Green",
			"Blue",
			"Black",
		};
	};
	class ALV_FleeceTop_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_FleeceTop";
		colorVariants[] =
		{
			"Blue",
			"Khaki",
			"CreBlue",
			"Cream",
			"BlaGrn",
			"OrgBlu",
			"Black",
		};
	};
	class ALV_PulloverHoodie_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_PulloverHoodie";
		colorVariants[] =
		{
			"Grey",
			"Black",
			"BlackWhite",
			"Tan",
			"Yellow",
			"Blue",
			"Green",
		};
	};
	class ALV_DressShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_DressShirt";
		colorVariants[] =
		{
			"White",
			"Blue",
			"Grey",
			"Red",
			"Brown",
		};
	};
	class ALV_LongSleeve_Tshirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_LongSleeve_Tshirt";
		colorVariants[] =
		{
			"Grey",
			"Black",
			"Shanka",
		};
	};
	class ALV_Sweater_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_Sweater";
		colorVariants[] =
		{
			"Tan",
			"Grey",
		};
	};
	class ALV_ScavangerTop_Colorbase : Clothing
	{
		rootClassName = "ALV_ScavangerTop";
		colorVariants[] =
		{
			"MC",
			"MCBLK",
			"ESPN",
			"ESPNGry",
			"Snow",
			"SnowGry",
			"Tan",
			"TanGry",
		};
	};
	class ALV_WorkersShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_WorkersShirt";
		colorVariants[] =
		{
			"Tan",
			"Olive",
			"Black",
			"Denim",
			"Blue",
		};
	};
	class ALV_OpenShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_OpenShirt";
		colorVariants[] =
		{
			"Red",
			"Black",
			"Green",
			"Pink",
		};
	};
	class ALV_PoliceShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_PoliceShirt";
		colorVariants[] =
		{
			"Blue",
			"Tan",
			"Green",
			"Brown",
			"Black",
		};
	};
	class ALV_TurtleNeck_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_TurtleNeck";
		colorVariants[] =
		{
			"Black",
			"Camel",
			"Brown",
			"Orange",
		};
	};
	class ALV_HawaiianShirt_Colorbase : ALV_Top_Base
	{
		rootClassName = "ALV_HawaiianShirt";
		colorVariants[] =
		{
			"DarkBlue",
			"BrightBlue",
			"Red",
		};
	};
	class ALV_HazMat_Colorbase : ALV_Outfit_Base
	{
		rootClassName = "ALV_HazMat";
		colorVariants[] =
		{
			"Yellow",
			"OD",
			"CB",
			"Black",
		};
	};
	class ALV_Frag_Colorbase : ALV_Outfit_Base
	{
		rootClassName = "ALV_Frag";
		colorVariants[] =
		{
			"Blue",
			"Black",
		};
	};
	class ALV_Monkrobes_Colorbase : ALV_Outfit_Base
	{
		rootClassName = "ALV_Monkrobes";
		colorVariants[] =
		{
			"Brown",
			"Black",
			"Abbot",
		};
	};
	class ALV_NBCShirt_Colorbase : Clothing
	{
		rootClassName = "ALV_NBCShirt";
		colorVariants[] =
		{
			"Green",
			"Yellow",
			"MC",
			"White",
		};
	};
};