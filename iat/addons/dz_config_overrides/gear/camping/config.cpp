class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class TentBase;
	class BaseBuildingBase;

	//==================================================== VANILLA OVERRIDE
	class ShelterBase : TentBase
	{
		itemsCargoSize[] = { 10, 3 };
	};

	class Fabric : Inventory_Base
	{
		varStackMax = 4;
		varQuantityMax = 200;
	};

	// remove camonets
	class Fence : BaseBuildingBase
	{
		attachments[] = { "Wall_Barbedwire_1", "Wall_Barbedwire_2", "Att_CombinationLock", "Material_Nails", "Material_WoodenPlanks", "Material_MetalSheets", "Material_WoodenLogs", "Material_MetalWire" };
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = { "Material_WoodenLogs" };
				icon = "set:dayz_inventory image:cat_bb_base";
				selection = "wall";
			};
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Wall_Barbedwire_1", "Wall_Barbedwire_2", "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
				selection = "wall";
			};
			class Material
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Materials";
				description = "";
				attachmentSlots[] = { "Material_Nails", "Material_WoodenPlanks", "Material_MetalSheets", "Material_MetalWire" };
				icon = "set:dayz_inventory image:cat_bb_material";
				selection = "wall";
			};
		};
	};
	// remove camonets from level 1
	class Watchtower : BaseBuildingBase
	{
		attachments[] = { "Level_1_Wall_1_Barbedwire_1", "Level_1_Wall_1_Barbedwire_2", "Level_1_Wall_2_Barbedwire_1", "Level_1_Wall_2_Barbedwire_2", "Level_1_Wall_3_Barbedwire_1", "Level_1_Wall_3_Barbedwire_2", "Level_2_Wall_1_Camonet", "Level_2_Wall_2_Camonet", "Level_2_Wall_3_Camonet", "Level_3_Wall_1_Camonet", "Level_3_Wall_2_Camonet", "Level_3_Wall_3_Camonet", "Material_L1_WoodenLogs", "Material_L2_WoodenLogs", "Material_L3_WoodenLogs", "Material_L1_Nails", "Material_L1W1_Nails", "Material_L1W2_Nails", "Material_L1W3_Nails", "Material_L2_Nails", "Material_L2W1_Nails", "Material_L2W2_Nails", "Material_L2W3_Nails", "Material_L3_Nails", "Material_L3W1_Nails", "Material_L3W2_Nails", "Material_L3W3_Nails", "Material_L1_WoodenPlanks", "Material_L1W1_WoodenPlanks", "Material_L1W2_WoodenPlanks", "Material_L1W3_WoodenPlanks", "Material_L2_WoodenPlanks", "Material_L2W1_WoodenPlanks", "Material_L2W2_WoodenPlanks", "Material_L2W3_WoodenPlanks", "Material_L3_WoodenPlanks", "Material_L3W1_WoodenPlanks", "Material_L3W2_WoodenPlanks", "Material_L3W3_WoodenPlanks", "Material_L3_MetalSheets", "Material_L1W1_MetalSheets", "Material_L1W2_MetalSheets", "Material_L1W3_MetalSheets", "Material_L2W1_MetalSheets", "Material_L2W2_MetalSheets", "Material_L2W3_MetalSheets", "Material_L3W1_MetalSheets", "Material_L3W2_MetalSheets", "Material_L3W3_MetalSheets" };
		class GUIInventoryAttachmentsProps
		{
			class Level_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Base";
				description = "";
				attachmentSlots[] = { "Material_L1_WoodenLogs", "Material_L1_Nails", "Material_L1_WoodenPlanks" };
				icon = "set:dayz_inventory image:cat_bb_watchtower";
				selection = "level_1";
			};
			class Level_1_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_1";
				description = "";
				attachmentSlots[] = { "Material_L1W1_Nails", "Material_L1W1_WoodenPlanks", "Material_L1W1_MetalSheets", "Level_1_Wall_1_Barbedwire_1", "Level_1_Wall_1_Barbedwire_2" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_1";
				selection = "level_1_wall_1";
			};
			class Level_1_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_2";
				description = "";
				attachmentSlots[] = { "Material_L1W2_Nails", "Material_L1W2_WoodenPlanks", "Material_L1W2_MetalSheets", "Level_1_Wall_2_Barbedwire_1", "Level_1_Wall_2_Barbedwire_2" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_2";
				selection = "level_1_wall_2";
			};
			class Level_1_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_3";
				description = "";
				attachmentSlots[] = { "Material_L1W3_Nails", "Material_L1W3_WoodenPlanks", "Material_L1W3_MetalSheets", "Level_1_Wall_3_Barbedwire_1", "Level_1_Wall_3_Barbedwire_2" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_3";
				selection = "level_1_wall_3";
			};
			class Level_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Base";
				description = "";
				attachmentSlots[] = { "Material_L2_WoodenLogs", "Material_L2_Nails", "Material_L2_WoodenPlanks" };
				icon = "set:dayz_inventory image:cat_bb_watchtower";
				selection = "level_2";
			};
			class Level_2_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_1";
				description = "";
				attachmentSlots[] = { "Material_L2W1_Nails", "Material_L2W1_WoodenPlanks", "Material_L2W1_MetalSheets", "Level_2_Wall_1_Camonet" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_1";
				selection = "level_2_wall_1";
			};
			class Level_2_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_2";
				description = "";
				attachmentSlots[] = { "Material_L2W2_Nails", "Material_L2W2_WoodenPlanks", "Material_L2W2_MetalSheets", "Level_2_Wall_2_Camonet" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_2";
				selection = "level_2_wall_2";
			};
			class Level_2_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_3";
				description = "";
				attachmentSlots[] = { "Material_L2W3_Nails", "Material_L2W3_WoodenPlanks", "Material_L2W3_MetalSheets", "Level_2_Wall_3_Camonet" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_3";
				selection = "level_2_wall_3";
			};
			class Level_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Base";
				description = "";
				attachmentSlots[] = { "Material_L3_WoodenLogs", "Material_L3_Nails", "Material_L3_WoodenPlanks", "Material_L3_MetalSheets" };
				icon = "set:dayz_inventory image:cat_bb_watchtower";
				selection = "level_3";
			};
			class Level_3_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_1";
				description = "";
				attachmentSlots[] = { "Material_L3W1_Nails", "Material_L3W1_WoodenPlanks", "Material_L3W1_MetalSheets", "Level_3_Wall_1_Camonet" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_1";
				selection = "level_3_wall_1";
			};
			class Level_3_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_2";
				description = "";
				attachmentSlots[] = { "Material_L3W2_Nails", "Material_L3W2_WoodenPlanks", "Material_L3W2_MetalSheets", "Level_3_Wall_2_Camonet" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_2";
				selection = "level_3_wall_2";
			};
			class Level_3_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_3";
				description = "";
				attachmentSlots[] = { "Material_L3W3_Nails", "Material_L3W3_WoodenPlanks", "Material_L3W3_MetalSheets", "Level_3_Wall_3_Camonet" };
				icon = "set:dayz_inventory image:cat_bb_watchtower_wall_3";
				selection = "level_3_wall_3";
			};
		};
	};
};