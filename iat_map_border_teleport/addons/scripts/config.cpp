class CfgPatches
{
	class IAT_Map_Border_Teleport_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Map_Border_Teleport
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Map Border Teleport";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_map_border_teleport/scripts/4_world" };
			};
		};

	};
};