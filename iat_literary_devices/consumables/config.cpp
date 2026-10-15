class CfgPatches
{
	class IAT_LiteraryDevices_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class Paper : Inventory_Base
	{
		inventorySlot[] +=
		{
			"IAT_Paper_1",
				"IAT_Paper_2",
				"IAT_Paper_3",
				"IAT_Paper_4",
				"IAT_Paper_5",
		};
	};
};