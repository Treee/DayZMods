class CfgPatches
{
	class IAT_DZ_ALV_Gear_ConfigOverrides_Gear_Food
	{
		requiredAddons[] = { "SRP_ALV_Gear_Food" };
	};
};
class CfgVehicles
{
	class ALV_Carcass_Base;

	//==================================================== VANILLA OVERRIDE
	class ALV_Carcass_Deer : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
	class ALV_Carcass_Pig : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
	class ALV_Carcass_Sheep : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
	class ALV_Carcass_Goat : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
	class ALV_Carcass_Wolf : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
	class ALV_Carcass_Cow : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
	class ALV_Carcass_Bear : ALV_Carcass_Base
	{
		itemBehaviour = 0;
		itemSize[] = { 12, 12 };
	};
};