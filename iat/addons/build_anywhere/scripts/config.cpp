class CfgPatches
{
	class IAT_BuildAnywhre
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_BuildAnywhre
	{
		type = "mod";
		author = "ItsATreee";
		name = "Build Anywhere";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/build_anywhere/scripts/4_world" };
			};
		};
	};
};