class CfgPatches
{
	class IAT_Smelting_Metallurgy_Crafting
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Crafting" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class FireplaceBase;

	class IAT_FurnaceKit_ColorBase : Inventory_Base
	{
		scope = 0;
		displayName = "Furnace Kit";
		descriptionShort = "A kit for constructing a smelting forge or furnace.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		rotationFlags = 2;
		itemBehaviour = 0;
		itemSize[] = { 5, 4 };
		weight = 3000;
		soundImpactType = "wood";
		hiddenSelections[] = { "camoGround" };
		hiddenSelectionsTextures[] = { "\dz\gear\camping\data\wooden_case_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = { {1, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.7, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.5, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0, {"DZ\gear\camping\data\wooden_case_destruct.rvmat"}} };
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class IAT_FurnaceKit_BasicStone : IAT_FurnaceKit_ColorBase
	{
		scope = 2;
		displayName = "Basic Stone Furnace Kit";
		descriptionShort = "A kit for constructing a smelting forge or furnace.";
		projectionTypename = "IAT_SmeltingFurnace_BasicStone";
	};
	class IAT_FurnaceKit_BasicBrick : IAT_FurnaceKit_ColorBase
	{
		scope = 2;
		displayName = "Basic Brick Furnace Kit";
		descriptionShort = "A kit for constructing a smelting forge or furnace.";
		projectionTypename = "IAT_SmeltingFurnace_BasicBrick";
	};
	class IAT_FurnaceKit_Advancedstone : IAT_FurnaceKit_ColorBase
	{
		scope = 2;
		displayName = "Advanced Stone Furnace Kit";
		descriptionShort = "A kit for constructing a smelting forge or furnace.";
		projectionTypename = "IAT_SmeltingFurnace_AdvancedStone";
	};
	class IAT_FurnaceKit_Industrial : IAT_FurnaceKit_ColorBase
	{
		scope = 2;
		displayName = "Industrial Furnace Kit";
		descriptionShort = "A kit for constructing a smelting forge or furnace.";
		projectionTypename = "IAT_SmeltingFurnace_Industrial";
	};

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