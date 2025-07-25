class CfgPatches
{
	class IAT_Mining_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================================== ORE
	class IAT_MiningOre_ColorBase : Inventory_Base
	{
		scope = 0;
		displayName = "Raw Ore";
		descriptionShort = "Raw ore mined from the ground.";
		model = "\dz\gear\consumables\SmallStone.p3d";
		animClass = "NoFireClass";
		weight = 500;
		itemSize[] = { 1, 1 };
		rotationFlags = 17;
		canBeSplit = 1;
		varQuantityDestroyOnMin = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varStackMax = 20;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_iron_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{
						{1, {"DZ\gear\consumables\data\stone.rvmat"}},
						{0.7, {"DZ\gear\consumables\data\stone.rvmat"}},
						{0.5, {"DZ\gear\consumables\data\stone_damage.rvmat"}},
						{0.3, {"DZ\gear\consumables\data\stone_damage.rvmat"}},
						{0, {"DZ\gear\consumables\data\stone_destruct.rvmat"}}
					};
				};
			};
		};
	};

	class IAT_MiningOre_Iron : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Iron Ore";
		color = "iron";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_iron_co.paa" };
	};
	class IAT_MiningOre_Copper : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Copper Ore";
		color = "copper";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_copper_co.paa" };
	};
	class IAT_MiningOre_Aluminium : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Aluminium Ore";
		color = "Aluminium";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_aluminium_co.paa" };
	};
	class IAT_MiningOre_Lead : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Lead Ore";
		color = "Lead";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_lead_co.paa" };
	};
	class IAT_MiningOre_Zinc : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Zinc Ore";
		color = "Zinc";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_zinc_co.paa" };
	};
	class IAT_MiningOre_Tin : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Tin Ore";
		color = "Tin";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_tin_co.paa" };
	};

	//==================================================================== PRECIOUS METALS
	class IAT_MiningOre_Silver : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Silve Ore";
		color = "Silver";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_silver_co.paa" };
	};
	class IAT_MiningOre_Gold : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Gold Ore";
		color = "Gold";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_gold_co.paa" };
	};

	//==================================================================== EARTH MINERALS
	class IAT_MiningOre_Coal : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Coal Chunk";
		descriptionShort = "Raw material mined from the ground.";
		color = "Coal";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_coal_co.paa" };
	};
	class IAT_MiningOre_SaltPeter : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Salt Peter";
		descriptionShort = "Raw material mined from the ground.";
		color = "SaltPeter";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_saltpeter_co.paa" };
	};
	class IAT_MiningOre_Sulfur : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Sulfur";
		descriptionShort = "Raw material mined from the ground.";
		color = "Sulfur";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_sulfur_co.paa" };
	};
	class IAT_MiningOre_SaltCrystals : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Salt Crystals";
		descriptionShort = "Raw material mined from the ground.";
		color = "SaltCrystals";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_saltcrystals_co.paa" };
	};
	class IAT_MiningOre_Clay : IAT_MiningOre_ColorBase
	{
		scope = 2;
		displayName = "Clay";
		descriptionShort = "Raw material mined from the ground.";
		color = "Clay";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_clay_co.paa" };
	};

	//==================================================================== GEMSTONES
	class IAT_MiningGem_ColorBase : Inventory_Base
	{
		scope = 0;
		displayName = "Raw Gem";
		descriptionShort = "Raw gemstone mined from the ground.";
		model = "\dz\gear\consumables\SmallStone.p3d";
		animClass = "NoFireClass";
		weight = 500;
		itemSize[] = { 1, 1 };
		rotationFlags = 17;
		canBeSplit = 1;
		varQuantityDestroyOnMin = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 50;
		varStackMax = 10;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_quartz_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1, {"DZ\gear\consumables\data\stone.rvmat"}}, {0.7, {"DZ\gear\consumables\data\stone.rvmat"}}, {0.5, {"DZ\gear\consumables\data\stone_damage.rvmat"}}, {0.3, {"DZ\gear\consumables\data\stone_damage.rvmat"}}, {0, {"DZ\gear\consumables\data\stone_destruct.rvmat"}} };
				};
			};
		};
	};
	class IAT_MiningGem_Quartz : IAT_MiningGem_ColorBase
	{
		scope = 2;
		displayName = "Quartz";
		color = "Quartz";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_quartz_co.paa" };
	};
	class IAT_MiningGem_Amethyst : IAT_MiningGem_ColorBase
	{
		scope = 2;
		displayName = "Amethyst";
		color = "Amethyst";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_amethyst_co.paa" };
	};
	class IAT_MiningGem_Topaz : IAT_MiningGem_ColorBase
	{
		scope = 2;
		displayName = "Topaz";
		color = "Topaz";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_topaz_co.paa" };
	};
	class IAT_MiningGem_Ruby : IAT_MiningGem_ColorBase
	{
		scope = 2;
		displayName = "Ruby";
		color = "Ruby";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_ruby_co.paa" };
	};
	class IAT_MiningGem_Sapphire : IAT_MiningGem_ColorBase
	{
		scope = 2;
		displayName = "Sapphire";
		color = "Sapphire";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_sapphire_co.paa" };
	};
	class IAT_MiningGem_Diamond : IAT_MiningGem_ColorBase
	{
		scope = 2;
		displayName = "Diamond";
		color = "Diamond";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_mining_enhanced\consumables\data\iat_stone_diamond_co.paa" };
	};

};