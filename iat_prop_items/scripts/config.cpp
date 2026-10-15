class CfgPatches
{
	class IAT_Prop_Items_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Prop_Items_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Prop Items";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_prop_items/scripts/4_world" };
			};
		};
	};
};