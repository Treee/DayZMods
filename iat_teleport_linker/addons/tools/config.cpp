class CfgPatches
{
	class IAT_Teleport_Linker_Tools
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Tools", };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class IAT_TeleportLinker_Basic : Inventory_Base
	{
		scope = 2;
		displayName = "Teleport Link Hammer";
		descriptionShort = "Hold the hammer in your hands and link two or more objects together.";
		model = "\dz\gear\tools\Hammer.p3d";
		debug_ItemCategory = 2;
		rotationFlags = 17;
		weight = 940;
		itemSize[] = { 2, 3 };
		soundImpactType = "metal";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1, {"DZ\gear\tools\data\Hammer.rvmat"}}, {0.7, {"DZ\gear\tools\data\Hammer.rvmat"}}, {0.5, {"DZ\gear\tools\data\Hammer_damage.rvmat"}}, {0.3, {"DZ\gear\tools\data\Hammer_damage.rvmat"}}, {0, {"DZ\gear\tools\data\Hammer_destruct.rvmat"}} };
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBluntLight_2";
				range = 1.1;
			};
			class Heavy
			{
				ammo = "MeleeBluntHeavy_2";
				range = 1.1;
			};
			class Sprint
			{
				ammo = "MeleeBluntHeavy_2";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class MinningBuilding
				{
					soundLookupTable = "MinningBuilding_LookupTable";
					id = 11161;
				};
			};
		};
	};
};