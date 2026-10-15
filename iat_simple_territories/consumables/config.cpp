class CfgPatches
{
	class IAT_Simple_Territories_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class Stone : Inventory_Base
	{
		inventorySlot[] += {"IAT_FlagRaiseTax"};
	};
};