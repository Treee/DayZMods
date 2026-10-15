class CfgPatches
{
	class IAT_Admin_Helper_Proxy
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Consumables", "DZ_Gear_Tools", "DZ_Gear_Crafting" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class WoodenLog : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_WoodenLogs" };
	};
	class WoodenPlank : Inventory_Base
	{
		inventorySlot[] += {"IAT_Construction_WoodenPlanks"};
	};
	class MetalPlate : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_MetalPlate" };
	};
	class Nail : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_Nails" };
	};
	class EpoxyPutty : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_Epoxy" };
	};
	class MetalWire : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_MetalWire" };
	};
	class Pipe : Inventory_Base
	{
		inventorySlot[] += {"IAT_Construction_Pipe"};
	};
	class Stone : Inventory_Base
	{
		inventorySlot[] += {"IAT_Construction_Stone"};
	};
	class Fabric : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_Fabric" };
	};
	class Rope : Inventory_Base
	{
		inventorySlot[] += { "IAT_Construction_Rope" };
	};
};
class CfgSlots
{
	class Slot_IAT_Construction_WoodenLogs
	{
		name = "IAT_Construction_WoodenLogs";
		displayName = "Wooden Logs";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 400; // max stack logs is 50
	};
	class Slot_IAT_Construction_WoodenPlanks
	{
		name = "IAT_Construction_WoodenPlanks";
		displayName = "Wooden Planks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 400; // max stack planks is 20
	};
	class Slot_IAT_Construction_MetalPlate
	{
		name = "IAT_Construction_MetalPlate";
		displayName = "Metal Plate";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 800; // max stack metal plate is 40
	};
	class Slot_IAT_Construction_Nails
	{
		name = "IAT_Construction_Nails";
		displayName = "Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 990; // max stack nails is 99
	};
	class Slot_IAT_Construction_Epoxy
	{
		name = "IAT_Construction_Epoxy";
		displayName = "Epoxy";
		ghostIcon = "set:dayz_inventory image:missing";
		stackMax = 5000; // max stack epoxy is 100
	};
	class Slot_IAT_Construction_MetalWire
	{
		name = "IAT_Construction_MetalWire";
		displayName = "Metal Wire";
		ghostIcon = "set:dayz_inventory image:metalwire";
		stackMax = 100; // max stack wire is 1
	};
	class Slot_IAT_Construction_Pipe
	{
		name = "IAT_Construction_Pipe";
		displayName = "Pipe";
		ghostIcon = "set:dayz_inventory image:shoulderright";
		stackMax = 50; // max stack pipe is 1
	};
	class Slot_IAT_Construction_Stone
	{
		name = "IAT_Construction_Stone";
		displayName = "Stone";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 400; // max stack pipe is 1
	};
	class Slot_IAT_Construction_Fabric
	{
		name = "IAT_Construction_Fabric";
		displayName = "Fabric";
		ghostIcon = "set:dayz_inventory image:tarp";
		stackMax = 200; // max stack fabric is 4
	};
	class Slot_IAT_Construction_Rope
	{
		name = "IAT_Construction_Rope";
		displayName = "Rope";
		ghostIcon = "set:dayz_inventory image:rope";
		stackMax = 100; // max stack rope is 1
	};
};