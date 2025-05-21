class CfgPatches
{
	class IAT_DZ_ALV_Gear_ConfigOverrides_Characters_Jackets
	{
		requiredAddons[] = { "ACO_Upper_Jackets" };
	};
};
class CfgVehicles
{
	class ALV_WW2Coat_Colorbase;

	//==================================================== VANILLA OVERRIDE
	class ALV_WW2Coat_Classic : ALV_WW2Coat_Colorbase
	{
		scope = 0;
	};
};