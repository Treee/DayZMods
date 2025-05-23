class CfgPatches
{
	class IAT_DZ_Bitterroot_ConfigOverrides_Gear_Food
	{
		requiredAddons[] = { "DZ_Data", "MF_MountainLion", "MF_Moose" };
	};
};
class CfgVehicles
{
	class CowSteakMeat;

	class MF_Moose_Meat : CowSteakMeat
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
	};
	class MountainLion_Meat : CowSteakMeat
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
	};
};