class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Vests
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Vests"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class PlateCarrierVest : Clothing
	{
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 75.0,60.0,50.0,50.0 };
	};
	class PlateCarrierHolster : Clothing
	{
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 35.0,30.0,25.0,25.0 };
	};
	class PressVest_ColorBase : Clothing
	{
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 45.0,45.0,45.0,45.0 };
	};
	class UKAssVest_ColorBase : Clothing
	{
		itemsCargoSize[] = { 6,5 };
	};
	class HighCapacityVest_ColorBase : Clothing
	{
		repairableWithKits[] = { 3,5,7,8 };
		repairCosts[] = { 60.0,50.0,40.0,40.0 };
	};
};