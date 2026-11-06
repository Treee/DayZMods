class CfgPatches
{
	class IAT_StaminaOverhaul
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_StaminaOverhaul
	{
		type = "mod";
		author = "ItsATreee";
		name = "Stamina Overhaul";
		dependencies[] = { "Game","World" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "IAT/stamina_overhaul/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "IAT/stamina_overhaul/scripts/4_world" };
			};
		};
	};
};