class CfgPatches
{
	class IAT_BoilToSanitize
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_BoilToSanitize
	{
		type = "mod";
		author = "ItsATreee";
		name = "Boil To Sanitize";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/boil_to_sanitize/scripts/4_world" };
			};
		};
	};
};