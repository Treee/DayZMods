class CfgPatches
{
	class IAT_BoilToSanitize_Medical
	{
		requiredAddons[] = { "DZ_Gear_Medical" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BandageDressing : Inventory_Base
	{
		varTemperatureMin = 0;
		varTemperatureMax = 100;
		varTemperatureOverheatTime = 5;
	};
};