class CfgPatches
{
	class IAT_Admin_Helper
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Admin_Helper
	{
		type = "mod";
		author = "ItsATreee";
		name = "Admin Helper";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/admin_helper/scripts/4_world" };
			};
		};
	};
};