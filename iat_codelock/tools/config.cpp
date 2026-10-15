class CfgPatches
{
	class IAT_Codelock_Tools
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Tools" };
	};
};
class CfgVehicles
{
	class Inventory_Base;

	class IAT_RaidHacksaw_Colorbase : Inventory_Base
	{
		scope = 0;
		displayName = "Raiding Hacksaw";
		descriptionShort = "Specially modified hacksaw to destroy codelocks.";
		model = "\dz\gear\tools\hacksaw.p3d";
		debug_ItemCategory = 2;
		action = "GestureMeleeBayonetStab";
		repairableWithKits[] = { 4 };
		repairCosts[] = { 15 };
		inventorySlot[] = { "Backpack_1" };
		itemInfo[] = { "Knife" };
		rotationFlags = 17;
		RestrainUnlockType = 1;
		weight = 800;
		itemSize[] = { 4, 2 };
		fragility = 0.08;
		dismantle_action_type = 64;
		openItemSpillRange[] = { 10, 40 };
		soundImpactType = "metal";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSharpLight_1";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeSharpHeavy_1";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeSharpHeavy_1";
				range = 3.3;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = { {1, {"DZ\gear\tools\data\hacksaw.rvmat"}}, {0.7, {"DZ\gear\tools\data\hacksaw.rvmat"}}, {0.5, {"DZ\gear\tools\data\hacksaw_damage.rvmat"}}, {0.3, {"DZ\gear\tools\data\hacksaw_damage.rvmat"}}, {0, {"DZ\gear\tools\data\hacksaw_destruct.rvmat"}} };
				};
			};
		};
		class InventorySlotsOffsets
		{
			class Backpack_1
			{
				position[] = { 0.04, 0.35, 0 };
				orientation[] = { 180, -180, 90 };
			};
		};
	};

	class IAT_RaidHacksaw_Admin : IAT_RaidHacksaw_Colorbase
	{
		scope = 2;
		displayName = "Admin Raiding Hacksaw";
		descriptionShort = "Specially modified hacksaw to destroy codelocks VERY FAST and without tool damage.";
	};
	class IAT_RaidHacksaw_Basic : IAT_RaidHacksaw_Colorbase
	{
		scope = 2;
	};
};