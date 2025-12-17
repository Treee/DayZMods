class CfgPatches
{
	class IAT_EnhancedMining_Overrides
	{
		requiredAddons[] = { "IAT_Mining_Consumables" };
	};
};

class CfgVehicles
{
	class IAT_MiningOre_ColorBase;

	// These are accelerants for the smelter/furnace
	class IAT_MiningOre_Charcoal : IAT_MiningOre_ColorBase
	{
		IAT_Accelerant = 1;
		IAT_MinTemp = 1300;
		IAT_MaxTemp = 1500;
		inventorySlot[] += { "IAT_Accelerant" };
	};
	class IAT_MiningOre_Coal : IAT_MiningOre_ColorBase
	{
		IAT_Accelerant = 1;
		IAT_MinTemp = 1400;
		IAT_MaxTemp = 1700;
		inventorySlot[] += { "IAT_Accelerant" };
	};
	class IAT_MiningOre_Coke : IAT_MiningOre_ColorBase
	{
		IAT_Accelerant = 1;
		IAT_MinTemp = 1800;
		IAT_MaxTemp = 2000;
		inventorySlot[] += { "IAT_Accelerant", "IAT_RawOre1", "IAT_RawOre2" };
	};

	// These are ores that can attach to the smelter
	class IAT_MiningOre_Iron : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Copper : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Aluminium : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Lead : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Zinc : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Tin : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Silver : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Gold : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_SaltPeter : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Sulfur : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningOre_Clay : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
	class IAT_MiningGem_Quartz : IAT_MiningOre_ColorBase
	{
		inventorySlot[] += { "IAT_RawOre1", "IAT_RawOre2" };
	};
};