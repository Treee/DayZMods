class CfgPatches
{
	class IAT_Enhanced_Medical_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Enhanced_Medical
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Enhanced Medical";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_enhanced_medical/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_enhanced_medical/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_enhanced_medical/scripts/5_mission" };
			};
		};
	};
};