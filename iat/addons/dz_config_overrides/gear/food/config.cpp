class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Food
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Food"
		};
	};
};
class CfgVehicles
{
	class Edible_Base;

	//==================================================== VANILLA OVERRIDE
	class BoxCerealCrunchin : Edible_Base
	{
		canBeSplit = 1;
		weight = 2;
		itemSize[] = { 2,2 };
	};
	class SmallGuts : Edible_Base
	{
		weight = 8;
	};
	class Guts : Edible_Base
	{
		weight = 7;
		canBeSplit = 1;
		itemSize[] = { 2,1 };
	};
};