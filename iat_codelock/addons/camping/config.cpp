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
		displayName = "Codelock";
		descriptionShort = "A lock that normally attaches to a fence gate, tent, and sometimes a cargo container. Default password is 1234. Make sure you change it after attaching to an object. Unlock to detach from object.";
		model = "iat_codelock\camping\iat_codelock.p3d";
		inventorySlot[] = { "Att_CombinationLock" };
		rotationFlags = 34;
		itemSize[] = { 3, 3 };
		weight = 350;
		soundImpactType = "metal";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_codelock\camping\data\iat_codelock_co.paa" };
		class InventorySlotsOffsets
		{
			class Att_CombinationLock
			{
				position[] = { -0.04, 0, -0.085 };
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
					healthLevels[] = { {1, {"iat_codelock\camping\data\iat_codelock.rvmat"}}, {0.7, {"iat_codelock\camping\data\iat_codelock.rvmat"}}, {0.5, {"iat_codelock\camping\data\iat_codelock_damage.rvmat"}}, {0.3, {"iat_codelock\camping\data\iat_codelock_damage.rvmat"}}, {0, {"iat_codelock\camping\data\iat_codelock_destruct.rvmat"}} };
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
	class IAT_Codelock_Painted : IAT_Codelock_Colorbase
	{
		scope = 2;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_codelock\camping\data\iat_codelock_painted_co.paa" };
	};
	// this codelock is meant to be hard overridden in the scripts to provide
	// a codelock in solo testing that is not owned by me and has a default password
	class IAT_Codelock_DebugNoOwner : IAT_Codelock_Colorbase
	{
		scope = 2;
		displayName = "Debug Codelock - No Owner";
		descriptionShort = "This codelock is not meant to be used on a live server since it has no real owner and its password is 1234.";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_codelock\camping\data\iat_codelock_painted_co.paa" };
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