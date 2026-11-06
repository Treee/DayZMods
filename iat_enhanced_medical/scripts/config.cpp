class CfgPatches
{
	class IAT_Enhanced_Medical_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Characters", "DZ_Gear_Medical", "DZ_Gear_Tools", "WZ_Melee_Mod", "WesternZClothingMisc" };
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
				files[] = { "iat_enhanced_medical/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_enhanced_medical/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_enhanced_medical/scripts/5_mission" };
			};
		};
	};
};

