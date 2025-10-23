class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Radio
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Radio"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================== VANILLA OVERRIDE
	class Megaphone
	{
		range = 100; // settlement size
		gain = 1; // default
		class EnergyManager
		{
			energyUsagePerSecond = 0.01;
		};
	};
};