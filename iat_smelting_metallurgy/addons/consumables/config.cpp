class CfgPatches
{
	class IAT_Smelting_Metallurgy_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};

class CfgSlots
{
	class Slot_IAT_Accelerant
	{
		name = "IAT_Accelerant";
		displayName = "Accelerant Fuel";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 1;
	};
	class Slot_IAT_RawOre1
	{
		name = "IAT_RawOre1";
		displayName = "Raw Ore";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 20;
	};
	class Slot_IAT_RawOre2
	{
		name = "IAT_RawOre2";
		displayName = "Raw Ore";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 20;
	};
};