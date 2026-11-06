class CfgPatches
{
	class IAT_Codelock_Tests
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = { "IAT_Codelock_Scripts", "IAT_Codelock_Camping", "DZ_Structures_Nasdara_Residential" };
	};
};
class CfgMods
{
	class IAT_Codelock_Tests
	{
		type = "mod";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				files[] = { "iat_codelock/tests/scripts/4_world" };
			};
		};
	};
};
class CfgVehicles
{
	class IAT_Codelock_Basic;
	class IAT_TestCodelock_Authorized : IAT_Codelock_Basic
	{
		scope = 2;
	};
};
