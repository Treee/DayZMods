class CfgPatches
{
	class IAT_Universal_Repair_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class BarbedWireLocked : Inventory_Base
	{
		CanBeUnrestrainedBy[] += { "IAT_UniversalRepair_MultiTool", 20 };
		CanBeUnrestrainedByDMG[] += { 20 };
	};
};