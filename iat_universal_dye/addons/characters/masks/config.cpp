class CfgPatches
{
	class IAT_Universal_Dye_Characters_Masks
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Masks"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class BalaclavaMask_ColorBase : Clothing
	{
		rootClassName = "BalaclavaMask";
		colorVariants[] =
		{
		  "Black",
		  "BlackSkull",
		  "Beige",
		  "Blue",
		  "Green",
		  "Pink",
		  "White",
		  "Pig",
		  "Chain",
		  "BDU",
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
	class Balaclava3Holes_ColorBase : Clothing
	{
		rootClassName = "Balaclava3Holes";
		colorVariants[] =
		{
		  "Black",
		  "BlackSkull",
		  "Beige",
		  "Blue",
		  "Green",
		  "Pink",
		  "White",
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
	class PaydayMask_ColorBase : Clothing
	{
		rootClassName = "SurgicalMask";
		colorVariants[] =
		{
			"Dallas",
			"Hoxton",
			"Wolf",
			"Chains",
		};
	};
	class SurgicalMask : Clothing
	{
		rootClassName = "SurgicalMask";
		colorVariants[] =
		{
		  "Black"
		};
	};
	class HockeyMask : Clothing
	{
		rootClassName = "HockeyMask";
		colorVariants[] =
		{
		  "Steel"
		};
	};
	class MimeMask_Male : Clothing
	{
		rootClassName = "MimeMask_Male";
		colorVariants[] =
		{
		};
	};
	class MimeMask_Female : MimeMask_Male
	{
		rootClassName = "MimeMask_Female";
		colorVariants[] =
		{
		};
	};
	class FaceCover_Improvised : Clothing
	{
		rootClassName = "FaceCover_Improvised";
		colorVariants[] =
		{
		  "Green",
		  "Black",
		  "Orange",
		  "Blue",
		  "Red",
		};
	};
	class NioshFaceMask : Clothing
	{
		rootClassName = "NioshFaceMask";
		colorVariants[] =
		{
		  "WaldoRescue",
		};
	};
};