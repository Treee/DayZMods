class CfgPatches
{
	class IAT_BoilToSanitize_Consumables
	{
		requiredAddons[] = { "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Rag : Inventory_Base
	{
		varTemperatureMin = 0;
		varTemperatureMax = 50;
		varTemperatureOverheatTime = 5;
	};
};