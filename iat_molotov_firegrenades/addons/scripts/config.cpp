class CfgPatches
{
	class IAT_Molotov_Grenades_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Molotov_Grenades
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Molotov and Incendiary Grenades";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_molotov_firegrenades/scripts/4_world" };
			};
		};
	};
};