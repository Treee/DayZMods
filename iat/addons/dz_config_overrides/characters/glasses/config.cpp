class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Glasses
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Glasses"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class SportGlasses_ColorBase : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
	class AviatorGlasses : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
	class DesignerGlasses : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
	class ThickFramesGlasses : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
	class ThinFramesGlasses : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
	class TacticalGoggles : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
	class EyePatch_Improvised : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 2,3 };
		repairCosts[] = { 30,30 };
	};
	class EyeMask_ColorBase : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 2,3 };
		repairCosts[] = { 30,30 };
	};
	class SkiGoggles_ColorBase : Clothing
	{
		inventorySlot[] += {"Extra"};
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
	};
};