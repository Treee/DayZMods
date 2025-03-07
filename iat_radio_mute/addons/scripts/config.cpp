class CfgPatches
{
	class IAT_Radio_Mute_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Radio_Mute
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Radio Mute";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_radio_mute/scripts/4_world" };
			};
		};
	};
};