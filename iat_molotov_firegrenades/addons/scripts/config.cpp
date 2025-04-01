class CfgPatches
{
	class IAT_Molotov_Grenades_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "IAT_Molotov_Grenades_Graphics" };
	};
};
class CfgMods
{
	class IAT_Molotov_Grenades
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Molotov and Incendiary Grenades";
		dependencies[] = { "Game", "World" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_molotov_firegrenades/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_molotov_firegrenades/scripts/4_world" };
			};
		};
	};
};