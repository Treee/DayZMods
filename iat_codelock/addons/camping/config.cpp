class CfgPatches
{
	class IAT_Codelock_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TentBase;
	class SeaChest;

	class IAT_Codelock_Colorbase : Inventory_Base
	{
		scope = 0;
		displayName = "IAT Codelock";
		descriptionShort = "My super awesome codelock!";
		model = "\dz\gear\camping\spotlight.p3d";
		inventorySlot[] = { "Att_CombinationLock" };
		rotationFlags = 34;
		itemSize[] = { 3, 3 };
		weight = 350;
		soundImpactType = "metal";
		class AnimationSources
		{
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Combination_Lock_Item : AnimSourceHidden
			{
			};
			class Lock_Item_1 : AnimSourceHidden
			{
			};
			class Lock_Item_2 : AnimSourceHidden
			{
			};
			class Combination_Lock_Attached : AnimSourceHidden
			{
			};
			class Lock_Attached_1 : AnimSourceHidden
			{
			};
			class Lock_Attached_2 : AnimSourceHidden
			{
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
					healthLevels[] = { {1, {"DZ\gear\camping\data\combilock3_metal.rvmat", "DZ\gear\camping\data\combination_lock_chain.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}}, {0.7, {"DZ\gear\camping\data\combilock3_metal.rvmat", "DZ\gear\camping\data\combination_lock_chain.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}}, {0.5, {"DZ\gear\camping\data\combilock3_metal_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\combilock3_metal_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}}, {0, {"DZ\gear\camping\data\combilock3_metal_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_destruct.rvmat"}} };
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};

	class IAT_Codelock_Basic : IAT_Codelock_Colorbase
	{
		scope = 2;
	};
	// this codelock is meant to be hard overridden in the scripts to provide
	// a codelock in solo testing that is not owned by me and has a default password
	class IAT_Codelock_DebugNoOwner : IAT_Codelock_Colorbase
	{
		scope = 2;
		displayName = "Debug Codelock - No Owner";
		descriptionShort = "This codelock is not meant to be used on a live server since it has no real owner and its password is 1234.";
	};

	class MediumTent : TentBase
	{
		attachments[] += { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = { "CamoNet", "Lights", "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 1;
			};
		};
	};
	class LargeTent : TentBase
	{
		attachments[] += { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = { "CamoNet", "Lights", "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 1;
			};
		};
	};

	class CarTent : TentBase
	{
		attachments[] += { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = { "CamoNet", "Lights", "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 1;
			};
		};
	};

	class PartyTent : TentBase
	{
		attachments[] += { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = { "CamoNet", "Lights", "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 1;
			};
		};
	};

	// out of scope for this iteration of the mod
	class IAT_LockableSeaChest : SeaChest
	{
		scope = 2;
		attachments[] += { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_fp_tents";
				view_index = 1;
			};
		};
	};

};