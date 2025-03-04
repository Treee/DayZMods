class CfgPatches
{
	class IAT_Roleplay_Emotes_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Roleplay_Emotes
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Roleplay Emotes";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_roleplay_emotes/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_roleplay_emotes/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_roleplay_emotes/scripts/5_mission" };
			};
		};
	};
};