class CfgPatches
{
	class IAT_Mining_Tools
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Tools" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	//==================================================================== ORE
	class IAT_AdminPickaxe : Inventory_Base
	{
		scope = 2;
		displayName = "Admin Pickaxe";
		descriptionShort = "A strong pickaxe owned by Paul Bunyon";
		model = "\dz\weapons\melee\blade\Pickaxe.p3d";
		debug_ItemCategory = 2;
		inventorySlot[] = { "Shoulder", "Melee" };
		rotationFlags = 12;
		repairableWithKits[] = { 4 };
		repairCosts[] = { 25 };
		build_action_type = 36;
		dismantle_action_type = 46;
		itemInfo[] = { "Pickaxe" };
		RestrainUnlockType = 1;
		itemSize[] = { 3, 6 };
		weight = 2500;
		itemBehaviour = 2;
		lootTag[] = { "Work" };
		lootCategory = "Tools";
		openItemSpillRange[] = { 40, 70 };
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "dz\weapons\melee\blade\data\Pickaxe_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = { {1, {"DZ\weapons\melee\blade\data\Pickaxe.rvmat"}}, {0.7, {"DZ\weapons\melee\blade\data\Pickaxe.rvmat"}}, {0.5, {"DZ\weapons\melee\blade\data\Pickaxe_damage.rvmat"}}, {0.3, {"DZ\weapons\melee\blade\data\Pickaxe_damage.rvmat"}}, {0, {"DZ\weapons\melee\blade\data\Pickaxe_destruct.rvmat"}} };
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "fireaxe";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSharpLight_4";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeSharpHeavy_4";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeSharpHeavy_4";
				range = 3.7;
			};
		};
		class Horticulture
		{
			ToolAnim = "CHOPPINGWOOD";
			DiggingTimeToComplete = 4.5;
		};
		soundImpactType = "metal";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "pickUpShovelLight_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "pickUpShovel_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
			class Sound
			{
				class SurfaceDig
				{
					class DigPrimary
					{
						default = 15;
						sakhal_snow = 903;
						sakhal_snow_forest = 903;
						sakhal_grass_brown = 903;
						sakhal_ice_sea = 904;
						sakhal_ice_lake = 904;
					};
				};
			};
		};
	};
};