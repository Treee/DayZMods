class CfgPatches
{
	class IAT_Compass_UI
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Compass_UI
	{
		type = "mod";
		author = "ItsATreee";
		name = "Compass UI";
		inputs = "iat/compass_ui/inputs.xml";
		dependencies[] = { "Mission" };
		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = { "iat/compass_ui/scripts/5_mission" };
			};
		};
	};
};