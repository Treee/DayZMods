class CfgPatches
{
	class IAT_NotesEnhanced_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class Paper : Inventory_Base
	{
		hiddenSelections[] = { "zbytek" };
		inventorySlot[] += { "IAT_NoteLabel" };
		hiddenSelectionsTextures[] = { "DZ\gear\consumables\data\loot_paper_co.paa" };
	};
};
class CfgSlots
{
	class Slot_IAT_NoteLabel
	{
		name = "IAT_NoteLabel";
		displayName = "Note Label";
		ghostIcon = "set:dayz_inventory image:paper";
	};
};