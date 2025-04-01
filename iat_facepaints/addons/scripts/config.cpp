class CfgMods
{
	class IAT_FacePaints_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "IAT FacePaints";
		dir = "iat_facepaints";
		dependencies[] = { "Game", "World", "Mission" };
		storageVersion = 1;
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_facepaints/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_facepaints/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_facepaints/scripts/5_mission" };
			};
		};
	};
};
// comment for publisher
class CfgPatches
{
	class IAT_FacePaints_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};