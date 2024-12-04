class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Medical
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Medical"
		};
	};
};
class CfgVehicles
{
	class Edible_Base;

	// ------------------------------------------ VANILLA OVERRIDE
	class VitaminBottle : Edible_Base
	{
		canBeSplit = 1;
		weight = 2;
	};

};