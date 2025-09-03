class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Cultivation
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Cultivation" };
	};
};
class CfgVehicles
{
	class PlantBase;

	//==================================================== VANILLA OVERRIDE
	class Plant_Tomato : PlantBase
	{
		class Horticulture
		{
			CropsCount = 3; // default 7
		};
	};
	class Plant_Pepper : PlantBase
	{
		class Horticulture
		{
			CropsCount = 2; // default 3
		};
	};
	class Plant_Potato : PlantBase
	{
		class Horticulture
		{
			CropsCount = 2; // default 3
		};
	};
	class Plant_Pumpkin : PlantBase
	{
		class Horticulture
		{
			CropsCount = 2; // default is 2
		};
	};
	class Plant_Zucchini : PlantBase
	{
		class Horticulture
		{
			CropsCount = 2; // default is 2
		};
	};
	class Plant_Cannabis : PlantBase
	{
		class Horticulture
		{
			CropsCount = 2; // default is 4
		};
	};
};