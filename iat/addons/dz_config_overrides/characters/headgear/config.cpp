class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Headgear
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Headgear"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class PumpkinHelmet : Clothing
	{
		scope = 0;
	};
};