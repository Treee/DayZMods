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
	class BakedBeansCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class BakedBeansCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class PeachesCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class PeachesCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class TacticalBaconCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class TacticalBaconCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class SpaghettiCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class SpaghettiCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
};