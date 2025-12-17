class CfgPatches
{
	class IAT_Smelting_Metallurgy_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};

class CfgVehicles
{
	class Inventory_Base;

	//================================================ METAL BARS
	class IAT_SmeltingIngot_ColorBase : Inventory_Base
	{
		scope = 0;
		displayName = "Ingot";
		descriptionShort = "A smelted ingot.";
		model = "iat_smelting_metallurgy\consumables\iat_ingot.p3d";
		animClass = "NoFireClass";
		weight = 500;
		itemSize[] = { 1, 2 };
		rotationFlags = 16;
		canBeSplit = 1;
		varQuantityDestroyOnMin = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varStackMax = 20;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{
						{1, {"iat_smelting_metallurgy\consumables\data\iat_ingot.rvmat"}},
						{0.7, {"iat_smelting_metallurgy\consumables\data\iat_ingot.rvmat"}},
						{0.5, {"iat_smelting_metallurgy\consumables\data\iat_ingot_damage.rvmat"}},
						{0.3, {"iat_smelting_metallurgy\consumables\data\iat_ingot_damage.rvmat"}},
						{0, {"iat_smelting_metallurgy\consumables\data\iat_ingot_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class IAT_SmeltingIngot_Steel : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Steel Ingot";
		color = "steel";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_co.paa" };
	};
	class IAT_SmeltingIngot_PigIron : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Pig Iron Ingot";
		color = "pigiron";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_pigiron_co.paa" };
	};
	class IAT_SmeltingIngot_ElectrumIron : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Electrum Iron Ingot";
		color = "electrumiron";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_electrumiron_co.paa" };
	};
	class IAT_SmeltingIngot_Copper : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Copper Ingot";
		color = "copper";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_copper_co.paa" };
	};
	class IAT_SmeltingIngot_Bronze : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Bronze Ingot";
		color = "bronze";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_bronze_co.paa" };
	};
	class IAT_SmeltingIngot_Brass : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Brass Ingot";
		color = "brass";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_brass_co.paa" };
	};
	class IAT_SmeltingIngot_Nickel : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Nickel Ingot";
		color = "nickel";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_nickel_co.paa" };
	};
	class IAT_SmeltingIngot_AluminiumBronze : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Aluminium Bronze Ingot";
		color = "aluminiumbronze";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_aluminiumbronze_co.paa" };
	};
	class IAT_SmeltingIngot_AluminiumTin : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Aluminium Tin Ingot";
		color = "aluminiumtin";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_aluminiumtin_co.paa" };
	};
	class IAT_SmeltingIngot_AluminiumZinc : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Aluminium Zinc Ingot";
		color = "aluminiumzinc";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_aluminiumzinc_co.paa" };
	};
	class IAT_SmeltingIngot_Lead : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Lead Ingot";
		color = "lead";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_lead_co.paa" };
	};
	class IAT_SmeltingIngot_Solder : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Solder Ingot";
		color = "solder";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_solder_co.paa" };
	};
	class IAT_SmeltingIngot_ElectrumNatural : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Electrum Natural Ingot";
		color = "electrumnatural";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_electrumnatural_co.paa" };
	};
	class IAT_SmeltingIngot_Silver : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Silver Ingot";
		color = "silver";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_silver_co.paa" };
	};
	class IAT_SmeltingIngot_SilverSterling : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Silver Sterling Ingot";
		color = "silversterling";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_silver_co.paa" };
	};
	class IAT_SmeltingIngot_Gold : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Gold Ingot";
		color = "gold";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_gold_co.paa" };
	};
	class IAT_SmeltingIngot_BlackPowder : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Black Powder Ingot";
		color = "blackpowder";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_blackpowder_co.paa" };
	};
	class IAT_SmeltingIngot_Glass : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Glass Ingot";
		color = "glass";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_glass_co.paa" };
	};
	class IAT_SmeltingIngot_Scrap : IAT_SmeltingIngot_ColorBase
	{
		scope = 2;
		displayName = "Scrap Ingot";
		color = "scrap";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\consumables\data\iat_ingot_scrap_co.paa" };
	};
};

class CfgSlots
{
	class Slot_IAT_Accelerant
	{
		name = "IAT_Accelerant";
		displayName = "Accelerant Fuel";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 1;
	};
	class Slot_IAT_RawOre1
	{
		name = "IAT_RawOre1";
		displayName = "Raw Ore";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 20;
	};
	class Slot_IAT_RawOre2
	{
		name = "IAT_RawOre2";
		displayName = "Raw Ore";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 20;
	};
};