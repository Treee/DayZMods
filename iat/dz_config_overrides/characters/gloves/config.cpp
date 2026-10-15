class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Characters_Gloves
	{
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Gloves"
		};
	};
};
class CfgVehicles
{
	class Clothing;
	//------------------------------------- BASE GAME OVERRIDE
	class WorkingGloves_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class TacticalGloves_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
	class SkiGloves_ColorBase : Clothing
	{
		itemSize[] = { 2,2 };
	};
};