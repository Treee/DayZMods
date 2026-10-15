class CfgPatches
{
	class IAT_Seed_Yield_Change_Gear_Cultivation
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Cultivation" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================== VANILLA OVERRIDE
	class TomatoSeedsPack : Inventory_Base
	{
		class Horticulture
		{
			ContainsSeedsType = "TomatoSeeds";
			ContainsSeedsQuantity = 5;
		};
	};
	class PepperSeedsPack : Inventory_Base
	{
		class Horticulture
		{
			ContainsSeedsType = "PepperSeeds";
			ContainsSeedsQuantity = 5;
		};
	};
	class PumpkinSeedsPack : Inventory_Base
	{
		class Horticulture
		{
			ContainsSeedsType = "PumpkinSeeds";
			ContainsSeedsQuantity = 5;
		};
	};
	class ZucchiniSeedsPack : Inventory_Base
	{
		class Horticulture
		{
			ContainsSeedsType = "ZucchiniSeeds";
			ContainsSeedsQuantity = 5;
		};
	};
	class CannabisSeedsPack : Inventory_Base
	{
		class Horticulture
		{
			ContainsSeedsType = "CannabisSeeds";
			ContainsSeedsQuantity = 5;
		};
	};
};