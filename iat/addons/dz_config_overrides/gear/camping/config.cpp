class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================== VANILLA OVERRIDE
	class Fabric : Inventory_Base
	{
		varStackMax = 4;
		varQuantityMax = 200;
	};
};