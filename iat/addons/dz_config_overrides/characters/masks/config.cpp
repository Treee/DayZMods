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
	};
	class Balaclava3Holes_ColorBase : Clothing
	{
		itemSize[] = { 1,2 };
	};
	class GP5GasMask : Clothing
	{
		soundVoiceType = "none";
		soundVoicePriority = 3;
		itemSize[] = { 2,2 };
	};
	class MimeMask_Female : MimeMask_Male
	{
		inventorySlot[] +=
		{
			"Mask"
		};
	};
};