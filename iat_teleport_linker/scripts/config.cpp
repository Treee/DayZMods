class CfgPatches
{
	class IAT_Teleport_Linker_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Teleport_Linker
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Teleport Linker";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_teleport_linker/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_teleport_linker/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_teleport_linker/scripts/5_mission" };
			};
		};
	};
};