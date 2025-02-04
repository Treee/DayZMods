class CfgPatches
{
	class IAT_Armbands_And_Flags
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Armbands_And_Flags
	{
		type = "mod";
		author = "ItsATreee";
		name = "Armbands And Flags";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/armbands_and_flags/scripts/4_world" };
			};
		};
	};
};