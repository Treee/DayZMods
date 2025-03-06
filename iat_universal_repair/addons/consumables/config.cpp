class CfgPatches
{
	class IAT_Universal_Repair_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class DuctTapeLocked : Inventory_Base
	{
		CanBeUnrestrainedBy[] += { "IAT_UniversalRepair_MultiTool", 1.5 };
		CanBeUnrestrainedByDMG[] += { 5 };
	};
};