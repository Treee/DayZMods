class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Tools
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Tools"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================== VANILLA OVERRIDE
	class LeatherSewingKit : Inventory_Base
	{
		canBeSplit = 1;
		itemSize[] = { 2,2 };
		weight = 12;
	};
	class SewingKit : Inventory_Base
	{
		canBeSplit = 1;
		weight = 2.1;
	};
	class EpoxyPutty : Inventory_Base
	{
		canBeSplit = 1;
		weight = 0.2;
		varStackMax = 100;
		varQuantityMax = 5000;
	};
	class WeaponCleaningKit : Inventory_Base
	{
		canBeSplit = 1;
		weight = 8;
		itemSize[] = { 2,2 };
	};
	class Heatpack : Inventory_Base
	{
		itemSize[] = { 1,2 };
	};
	class Pipe : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 1;
		varStackMax = 1;
	};
	class Rope : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 1;
		varStackMax = 1;
	};
	class Mace : Inventory_Base
	{
		inventorySlot[] += { "Backpack_1" };
	};
	class ElectronicRepairKit : Inventory_Base
	{
		canBeSplit = 1;
		weight = 10;
	};
};