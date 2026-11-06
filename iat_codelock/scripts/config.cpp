class CfgPatches
{
	class IAT_Codelock_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Codelock
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Codelock";
		dependencies[] = { "Game","World","Mission" };
		storageVersion = 1;
		class defs
		{
			class gameScriptModule
			{
				files[] =
				{
					"iat_codelock/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				files[] =
				{
					"JM/COT/Scripts/Common",
					"VPPAdminTools/Definitions",
					"iat_codelock/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				files[] =
				{
					"iat_codelock/scripts/5_mission"
				};
			};
		};
	};
};