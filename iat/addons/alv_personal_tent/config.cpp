class CfgPatches
{
	class IAT_ALV_PersonalTent
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_ALV_PersonalTent_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "ALV Personal Tent";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat/alv_personal_tent/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/alv_personal_tent/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat/alv_personal_tent/scripts/5_mission" };
			};
		};
	};
};