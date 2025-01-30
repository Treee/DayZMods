class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TentBase;

	//==================================================== VANILLA OVERRIDE
	class ShelterBase : TentBase
	{
		itemsCargoSize[] = { 10, 3 };
	};

	class Fabric : Inventory_Base
	{
		varStackMax = 4;
		varQuantityMax = 200;
	};
};