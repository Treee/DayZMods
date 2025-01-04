class CfgPatches
{
	class IAT_NotesEnhanced_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_NotesEnhanced
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Notes Enhanced";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_notes_enhanced/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_notes_enhanced/scripts/5_mission" };
			};
		};
	};
};