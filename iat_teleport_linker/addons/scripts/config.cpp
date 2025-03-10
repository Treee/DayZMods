class CfgPatches
{
	class IAT_Teleport_Linker_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Teleport_Linker
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Teleport Linker";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_teleport_linker/scripts/4_world" };
			};
		};
	};
};