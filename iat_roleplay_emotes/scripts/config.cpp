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
				files[] = { "iat_roleplay_emotes/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_roleplay_emotes/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_roleplay_emotes/scripts/5_mission" };
			};
		};
	};
};