class CfgPatches
{
	class IAT_Seed_Yield_Change_Gear_Food
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Food" };
	};
};
class CfgVehicles
{
	class Edible_Base;

	//==================================================== VANILLA OVERRIDE
	class Tomato : Edible_Base
	{
		ContainsSeedsQuantity = "0";
	};
	class GreenBellPepper : Edible_Base
	{
		ContainsSeedsQuantity = "0";
	};
	class Zucchini : Edible_Base
	{
		ContainsSeedsQuantity = "0";
	};
	class Pumpkin : Edible_Base
	{
		ContainsSeedsQuantity = "0";
	};
};