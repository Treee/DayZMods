class CfgPatches
{
	class IAT_Smelting_Metallurgy_Crafting
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Crafting" };
	};
};
class CfgVehicles
{
	class FireplaceBase;

	class IAT_SmeltingFurnace_ColorBase : FireplaceBase
	{
		scope = 0;
		displayName = "Smelting Furnace";
		descriptionShort = "A large structure meant for melting raw ores into ingots.";
		model = "iat_smelting_metallurgy\crafting\iat_stonefurnace.p3d";
		overrideDrawArea = "8.0";
		openable = 0;
		varTemperatureMax = 3000;
		varWetMax = 0;
		lootCategory = "Crafted";
		itemSize[] = { 13, 13 };
		itemsCargoSize[] = { 1, 1 };
		physLayer = "item_large";
		useEntityHierarchy = "true";
		attachments[] = { "Firewood", "WoodenStick", "Rags", "MedicalBandage", "Paper", "Bark", "IAT_Accelerant", "IAT_RawOre1", "IAT_RawOre2" };
		hiddenSelections[] = { "coal", "metal", "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\crafting\data\iat_furnacecoal_co.paa", "iat_smelting_metallurgy\crafting\data\iat_furnacemetal_co.paa", "iat_smelting_metallurgy\crafting\data\iat_furnace_co.paa" };
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name = "$STR_attachment_Fuel0";
				description = "";
				attachmentSlots[] = { "Firewood", "WoodenStick" };
				icon = "set:dayz_inventory image:cat_fp_fuel";
			};
			class Kindling
			{
				name = "$STR_attachment_Kindling0";
				description = "";
				attachmentSlots[] = { "Rags", "MedicalBandage", "Paper", "Bark" };
				icon = "set:dayz_inventory image:cat_fp_kindling";
			};
			class Smelting
			{
				name = "Smelting";
				description = "";
				attachmentSlots[] =
				{
					"IAT_Accelerant",
					"IAT_RawOre1",
					"IAT_RawOre2"
				};
				icon = "set:dayz_inventory image:stones";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10000;
				};
			};
		};
		soundImpactType = "default";
	};

	class IAT_SmeltingFurnace_BasicStone : IAT_SmeltingFurnace_ColorBase
	{
		scope = 2;
		class AnimationSources
		{
			class pour
			{
				source = "user";
				initPhase = 0;
				animPeriod = 5;
			};
			class pourlever
			{
				source = "user";
				initPhase = 0;
				animPeriod = 5;
			};
		};
	};
	class IAT_SmeltingFurnace_BasicBrick : IAT_SmeltingFurnace_ColorBase
	{
		scope = 2;
		model = "iat_smelting_metallurgy\crafting\iat_stoneforge.p3d";
		hiddenSelections[] = { "coal", "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\crafting\data\iat_stoneforge_co.paa", "iat_smelting_metallurgy\crafting\data\iat_stoneforge_co.paa" };
	};
	class IAT_SmeltingFurnace_AdvancedStone : IAT_SmeltingFurnace_ColorBase
	{
		scope = 2;
		model = "iat_smelting_metallurgy\crafting\iat_advancedstonefurnace.p3d";
		hiddenSelections[] = { "coal", "zbytek" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\crafting\data\iat_forgeNbellows_co.paa", "iat_smelting_metallurgy\crafting\data\iat_forgeNbellows_co.paa" };
	};
	class IAT_SmeltingFurnace_Industrial : IAT_SmeltingFurnace_ColorBase
	{
		scope = 2;
		model = "iat_smelting_metallurgy\crafting\iat_industrialfurnace.p3d";
		hiddenSelections[] = { "coal", "zbytek", "table" };
		hiddenSelectionsTextures[] = { "iat_smelting_metallurgy\crafting\data\iat_advancedfurnace_co.paa", "iat_smelting_metallurgy\crafting\data\iat_advancedfurnace_co.paa", "iat_smelting_metallurgy\crafting\data\iat_advancedfurnacetable_co.paa" };
	};
};