class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Pants
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Pants"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class GorkaPants_ColorBase : Clothing
	{
		heatIsolation = 0.80000001;
	};
	class NBCPantsBase : Clothing
	{
		class Protection
		{
			biological = 1;
		};
	};
};