class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Masks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
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
	class GasMask : Clothing
	{
		soundVoiceType = "none";
		soundVoicePriority = 3;
		itemSize[] = { 2,2 };
	};
	class BalaclavaMask_ColorBase : Clothing
	{
		itemSize[] = { 1,2 };
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
		itemSize[] = { 1,2 };
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
	class GP5GasMask : Clothing
	{
		soundVoiceType = "none";
		soundVoicePriority = 3;
		itemSize[] = { 2,2 };
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
		inventorySlot[] +=
		{
			"Mask"
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