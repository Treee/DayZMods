class CfgPatches
{
	class IAT_MapAnnotations_Tests
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "IAT_MapAnnotations_Scripts" };
	};
};
class CfgMods
{
	class IAT_MapAnnotations_Tests
	{
		type = "mod";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				files[] = { "iat_map_annotations/tests/scripts/4_world" };
			};
		};
	};
};
