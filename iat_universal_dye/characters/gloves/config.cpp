class CfgPatches
{
	class IAT_Universal_Dye_Characters_Gloves
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Gloves"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class WorkingGloves_ColorBase : Clothing
	{
		rootClassName = "WorkingGloves";
		colorVariants[] =
		{
		  "Black",
		  "Beige",
		  "Brown",
		  "Yellow",
		  "White",
		  "Red"
		};
	};
	class HandsCover_Improvised : Clothing
	{
		rootClassName = "HandsCover_Improvised";
		colorVariants[] =
		{
			"Green",
			"Black",
			"Orange",
			"Blue",
			"Red",
		};
	};
	class TacticalGloves_ColorBase : Clothing
	{
		rootClassName = "TacticalGloves";
		colorVariants[] =
		{
		  "Black",
		  "Beige",
		  "Green",
		  "MTP",
		  "ATAC",
		  "ATACSFG",
		  "USNAOR1",
		  "USNAOR2",
		  "SURPAT",
		  "MARPATWinter",
		  "EMP6",
		};
	};
	class NBCGloves_ColorBase : Clothing
	{
		rootClassName = "NBCGloves";
		colorVariants[] =
		{
		  "Blue",
		  "Gray",
		  "Yellow",
		  "White",
		};
	};
	class SurgicalGloves_ColorBase : Clothing
	{
		rootClassName = "SurgicalGloves";
		colorVariants[] =
		{
		  "Blue",
		  "LightBlue",
		  "Green",
		  "White",
		  "SkyBlue",
		  "Coal",
		  "Lime",
		  "LightGreen",
		  "Orange",
		  "Pink",
		  "Purple",
		  "Red",
		  "Yellow"
		};
	};
	class LeatherGloves_ColorBase : Clothing
	{
		rootClassName = "LeatherGloves";
		colorVariants[] =
		{
		  "Natural",
		  "Beige",
		  "Black",
		  "Brown",
		  "Choco",
		  "Lime",
		  "Orange",
		  "Pink",
		  "Purple",
		  "Storm",
		  "Yellow",
		};
	};
	class OMNOGloves_ColorBase : Clothing
	{
		rootClassName = "OMNOGloves";
		colorVariants[] =
		{
		  "Gray",
		  "Brown",
		  "Green",
		  "Black"
		};
	};
	class WoolGloves_ColorBase : Clothing
	{
		rootClassName = "WoolGloves";
		colorVariants[] =
		{
		  "Black",
		  "Green",
		  "Tan",
		  "White",
		  "ChristmasBlue",
		  "ChristmasRed",
		};
	};
	class WoolGlovesFingerless_ColorBase : Clothing
	{
		rootClassName = "WoolGlovesFingerless";
		colorVariants[] =
		{
		  "Black",
		  "Green",
		  "Tan",
		  "White",
		  "ChristmasBlue",
		  "ChristmasRed",
		};
	};
	class PaddedGloves_ColorBase : Clothing
	{
		rootClassName = "PaddedGloves";
		colorVariants[] =
		{
		  "Brown",
		  "Beige",
		  "Threat"
		};
	};
	class SkiGloves_ColorBase : Clothing
	{
		rootClassName = "SkiGloves";
		colorVariants[] =
		{
		  "Blue",
		  "Red",
		  "90s"
		};
	};
};