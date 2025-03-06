class CfgPatches
{
	class IAT_Universal_Repair_Tools
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Tools" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class IAT_UniversalRepair_Epoxy : Inventory_Base
	{
		scope = 2;
		debug_ItemCategory = 2;
		displayName = "Universal Repair Tool";
		descriptionShort = "A special tool that repairs anything.";
		model = "\dz\gear\tools\epoxy_putty.p3d";
		animClass = "Knife";
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		weight = 20;
		weightPerQuantityUnit = 2;
		itemSize[] = { 1,2 };
		repairKitType[] = { 1,2,3,4,5,6,7,8 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
					{
						{1,{"DZ\gear\tools\data\epoxy_putty.rvmat"}},
						{0.69999999,{"DZ\gear\tools\data\epoxy_putty.rvmat"}},
						{0.5,{"DZ\gear\tools\data\epoxy_putty_damage.rvmat"}},
						{0.30000001,{"DZ\gear\tools\data\epoxy_putty_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\epoxy_putty_destruct.rvmat"}}
					};
				};
			};
		};
		soundImpactType = "plastic";
		class AnimEvents
		{
			class SoundWeapon
			{
				class Stitch
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
				class pickup
				{
					soundSet = "sewingkit_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "sewingkit_drop_SoundSet";
					id = 898;
				};
			};
		};
	};

	class IAT_UniversalRepair_MultiTool : Inventory_Base
	{
		scope = 2;
		debug_ItemCategory = 2;
		displayName = "Multi Tool";
		descriptionShort = "A special tool that has just about anything you need for repairs or building.";
		model = "\dz\gear\tools\epoxy_putty.p3d";
		animClass = "Knife";
		rotationFlags = 17;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 1250;
		varQuantityMin = 0;
		varQuantityMax = 1250;
		weight = 20;
		weightPerQuantityUnit = 2;
		itemSize[] = { 1,2 };
		repairKitType[] = { 2,3,6 }; // sewing/ leather/tire repair kit
		openItemSpillRange[] = { 0, 0 }; // can opener
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
					{
						{1,{"DZ\gear\tools\data\epoxy_putty.rvmat"}},
						{0.69999999,{"DZ\gear\tools\data\epoxy_putty.rvmat"}},
						{0.5,{"DZ\gear\tools\data\epoxy_putty_damage.rvmat"}},
						{0.30000001,{"DZ\gear\tools\data\epoxy_putty_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\epoxy_putty_destruct.rvmat"}}
					};
				};
			};
		};
		soundImpactType = "plastic";
		class AnimEvents
		{
			class SoundWeapon
			{
				class Stitch
				{
					soundSet = "StitchUpSelf_SoundSet";
					id = 201;
				};
				class pickup
				{
					soundSet = "sewingkit_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "sewingkit_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};