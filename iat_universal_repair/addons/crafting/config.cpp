class CfgPatches
{
	class IAT_Universal_Repair_Crafting
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Crafting" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class RopeLocked : Inventory_Base
	{
		CanBeUnrestrainedBy[] += { "IAT_UniversalRepair_MultiTool", 2 };
		CanBeUnrestrainedByDMG[] += { 5 };
	};

	class MetalWireLocked : Inventory_Base
	{
		CanBeUnrestrainedBy[] += { "IAT_UniversalRepair_MultiTool", 20 };
		CanBeUnrestrainedByDMG[] += { 20 };
	};
};