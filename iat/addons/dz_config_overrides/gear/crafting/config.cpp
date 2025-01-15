class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Crafting
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Crafting" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================== VANILLA OVERRIDE
	class MetalWire : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 1;
		varStackMax = 1;
	};
};