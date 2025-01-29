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
		hiddenSelectionsTextures[] = { "DZ\gear\consumables\data\loot_paper_co.paa" };
	};
};