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
	class BaseBuildingBase;

	class IAT_Codelock_Colorbase : Inventory_Base
	{
		scope = 0;
		displayName = "Codelock";
		descriptionShort = "A lock that normally attaches to a fence gate, tent, and sometimes a cargo container. Default password is 1234. Make sure you change it after attaching to an object. Unlock to detach from object. Use the attach action, do not click and drag it onto the slot.";
		model = "iat_codelock\camping\iat_codelock.p3d";
		inventorySlot[] = { "Att_CombinationLock" };
		rotationFlags = 16;
		itemSize[] = { 3, 3 };
		weight = 350;
		soundImpactType = "metal";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "iat_codelock\camping\data\iat_codelock_co.paa" };
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
	class IAT_Codelock_CombinationLock3 : IAT_Codelock_Colorbase
	{
		scope = 2;
        displayName="$STR_CfgVehicles_CombinationLock0";
        descriptionShort="$STR_CfgVehicles_CombinationLock1";
        model="\DZ\gear\camping\combination_lock3.p3d";
		inventorySlot[]={"Att_CombinationLock"};
        rotationFlags=34;
        itemSize[]={3, 3};
        weight=350;
        soundImpactType="metal";
        class AnimationSources
        {
            class AnimSourceHidden
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
			class AnimSourceShown
            {
                source="user";
                animPeriod=0.01;
                initPhase=0;
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
            class Combination_Lock_Attached : AnimSourceShown
            {
            };
            class Lock_Attached_1 : AnimSourceShown
            {
            };
            class Lock_Attached_2 : AnimSourceShown
            {
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=1500;
                    healthLevels[]={{1, {"DZ\gear\camping\data\combilock3_metal.rvmat", "DZ\gear\camping\data\combination_lock_chain.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}}, {0.7, {"DZ\gear\camping\data\combilock3_metal.rvmat", "DZ\gear\camping\data\combination_lock_chain.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}}, {0.5, {"DZ\gear\camping\data\combilock3_metal_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\combilock3_metal_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}}, {0, {"DZ\gear\camping\data\combilock3_metal_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_destruct.rvmat"}}};
                };
            };
            class GlobalArmor
            {
                class Projectile
                {
                    class Health
                    {
                        damage=0;
                    };
                    class Blood
                    {
                        damage=0;
                    };
                    class Shock
                    {
                        damage=0;
                    };
                };
                class FragGrenade
                {
                    class Health
                    {
                        damage=0;
                    };
                    class Blood
                    {
                        damage=0;
                    };
                    class Shock
                    {
                        damage=0;
                    };
                };
            };
        };
	};
	class IAT_Codelock_CombinationLock4 : IAT_Codelock_Colorbase
	{
		scope = 2;
        displayName="$STR_CfgVehicles_4digitcombinationlock0";
        descriptionShort="$STR_CfgVehicles_4digitcombinationlock1";
        model="\DZ\gear\camping\combination_lock4.p3d";
		inventorySlot[]={"Att_CombinationLock"};
        rotationFlags=34;
        itemSize[]={3, 3};
        weight=350;
        soundImpactType="metal";
        class AnimationSources
        {
            class AnimSourceHidden
            {
                source="user";
                animPeriod=0.01;
                initPhase=1;
            };
			class AnimSourceShown
            {
                source="user";
                animPeriod=0.01;
                initPhase=0;
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
            class Combination_Lock_Attached : AnimSourceShown
            {
            };
            class Lock_Attached_1 : AnimSourceShown
            {
            };
            class Lock_Attached_2 : AnimSourceShown
            {
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=1500;
                    healthLevels[]={{1, {"DZ\gear\camping\data\combilock4_metal.rvmat", "DZ\gear\camping\data\combination_lock_chain.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}}, {0.7, {"DZ\gear\camping\data\combilock4_metal.rvmat", "DZ\gear\camping\data\combination_lock_chain.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}}, {0.5, {"DZ\gear\camping\data\combilock4_metal_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\combilock4_metal_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}}, {0, {"DZ\gear\camping\data\combilock4_metal_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber_destruct.rvmat", "DZ\gear\camping\data\combination_lock_chain_rubber1_destruct.rvmat"}}};
                };
            };
            class GlobalArmor
            {
                class Projectile
                {
                    class Health
                    {
                        damage=0;
                    };
                    class Blood
                    {
                        damage=0;
                    };
                    class Shock
                    {
                        damage=0;
                    };
                };
                class FragGrenade
                {
                    class Health
                    {
                        damage=0;
                    };
                    class Blood
                    {
                        damage=0;
                    };
                    class Shock
                    {
                        damage=0;
                    };
                };
            };
        };
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
		scope = 0; // making sure this is removed from servers before i delete it completely
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

	// class ShelterBase;
	// class ShelterFabric : ShelterBase
	// {
	// 	attachments[] += { "Att_CombinationLock" };
	// };
	// class ShelterLeather : ShelterBase
	// {
	// 	attachments[] += { "Att_CombinationLock" };
	// };
	// class ShelterStick : ShelterBase
	// {
	// 	attachments[] += { "Att_CombinationLock" };
	// };

};

class CfgNonAIVehicles
{
	class ProxyCombinationLock;
	class Proxyiat_codelock : ProxyCombinationLock
	{
		model = "iat_codelock\camping\iat_codelock.p3d";
	};
};