class CfgPatches
{
	class IAT_Radio_Volume_Control_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Radio_Volume_Control
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Radio Volume Control";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_radio_volume_control/scripts/4_world" };
			};
		};
	};
};