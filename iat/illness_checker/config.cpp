class CfgPatches
{
	class IAT_Illness_Checker
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Illness_Checker
	{
		type = "mod";
		author = "ItsATreee";
		name = "Illness Checker";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/illness_checker/scripts/4_world" };
			};
		};
	};
};