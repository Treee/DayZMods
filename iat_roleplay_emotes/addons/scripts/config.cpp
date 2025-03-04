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
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_roleplay_emotes/scripts/4_world" };
			};
		};
	};
};