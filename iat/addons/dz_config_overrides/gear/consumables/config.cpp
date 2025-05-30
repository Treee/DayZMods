class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Box_Base;

	//==================================================== VANILLA OVERRIDE
	class DuctTape : Inventory_Base
	{
		canBeSplit = 1;
		itemSize[] = { 1,2 };
		weight = 5;
	};
	class GardenLime : Inventory_Base
	{
		canBeSplit = 1;
		itemSize[] = { 2,3 };
		weight = 1;
	};
	class NailBox : Box_Base
	{
		weight = 1414;
	};
	class Nail : Inventory_Base
	{
		varStackMax = 99;
		varQuantityMax = 990;
		weight = 20.20;
	};
	class Stone : Inventory_Base
	{
		varQuantityMax = 400;
		weight = 1000;
	};
	class WoodenLog : Inventory_Base
	{
		varQuantityMax = 400;
	};
	class WoodenPlank : Inventory_Base
	{
		varStackMax = 20;
		varQuantityMax = 400;
	};
	class MetalPlate : Inventory_Base
	{
		varQuantityMax = 800;
	};
	class Rag : Inventory_Base
	{
		itemSize[] = { 2,1 };
	};
	class GasMask_Filter : Inventory_Base
	{
		itemSize[] = { 2,1 };
	};
	class Chemlight_ColorBase : Inventory_Base
	{
		inventorySlot[] += { "VestGrenadeA", "VestGrenadeB", "VestGrenadeC", "VestGrenadeD" };
	};
	class Roadflare : Inventory_Base
	{
		inventorySlot[] += { "VestGrenadeA", "VestGrenadeB", "VestGrenadeC", "VestGrenadeD" };
	};
};