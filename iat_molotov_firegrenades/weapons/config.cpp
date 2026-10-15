class CfgPatches
{
	class IAT_Molotov_Grenades_Weapons
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};

class CfgVehicles
{
	class EffectArea;

	class IAT_IncendiaryArea_Static : EffectArea
	{
		scope = 2;
	};
	class IAT_IncendiaryArea_Dynamic : EffectArea
	{
		scope = 2;
	};
	class IAT_IncendiaryArea_Local : EffectArea
	{
		scope = 2;
	};
};