class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Tops
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Tops"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	class Sweater_ChristmasColorbase;
	//------------------------------------- BASE GAME OVERRIDE
	class NBCJacketBase : Clothing
	{
		class Protection
		{
			biological = 1;
		};
	};
	class Sweater_ChristmasBlue : Sweater_ChristmasColorbase { scope = 0; };
	class Sweater_ChristmasGreen : Sweater_ChristmasColorbase { scope = 0; };
	class Sweater_ChristmasRed : Sweater_ChristmasColorbase { scope = 0; };
};