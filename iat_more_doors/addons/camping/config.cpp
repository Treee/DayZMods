class CfgPatches
{
	class IAT_MoreDoors_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Camping" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;

	/*====================== LAND DOORS ===========================================
	* These doors are for map baked requirements. They have the correct prefix and other
	* properties that allow them to be baked into terrains.
	*=============================================================================*/
	class IAT_LandDoor_Colorbase : HouseNoDestruct
	{
		scope = 0;
		displayName = "Base Door";
		descriptionShort = "Base Door";
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_right_wooden.p3d";
		carveNavmesh = 1;
		weight = 1500;
		itemSize[] = { 15,10 };	// too big for cargo ever!
		itemsCargoSize[] = { 0,0 }; // no storage at all
		physLayer = "item_large"; // give it collission
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "false";
		lootCategory = "Crafted";
		hiddenSelections[] = { "zbytek", "metal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa"
		};
	};

	class IAT_LandDoor_Single_Colorbase : IAT_LandDoor_Colorbase
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class Melee
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
			};
			class DamageZones
			{
				class Door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door1" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
			};
		};
	};
	class IAT_LandDoor_Double_Colorbase : IAT_LandDoor_Colorbase
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class Melee
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
			};
			class DamageZones
			{
				class Door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door1" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door2
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door2" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
			};
		};
	};

	class land_iat_singledoor_left_wooden : IAT_LandDoor_Single_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_left_wooden.p3d";
		attachments[] = { "Att_CombinationLock" };
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class land_iat_singledoor_left_metal : IAT_LandDoor_Single_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_left_metal.p3d";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class land_iat_singledoor_left_iron : IAT_LandDoor_Single_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_left_iron.p3d";
		attachments[] = { "Att_CombinationLock" };
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalContainerOpen";
				soundClose = "doorMetalContainerClose";
				soundLocked = "doorMetalContainerRattle";
				soundOpenABit = "doorMetalContainerOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};

	class land_iat_singledoor_right_wooden : IAT_LandDoor_Single_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_right_wooden.p3d";
		attachments[] = { "Att_CombinationLock" };
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class land_iat_singledoor_right_metal : IAT_LandDoor_Single_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_right_metal.p3d";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class land_iat_singledoor_right_iron : IAT_LandDoor_Single_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_singledoor_right_iron.p3d";
		attachments[] = { "Att_CombinationLock" };
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalContainerOpen";
				soundClose = "doorMetalContainerClose";
				soundLocked = "doorMetalContainerRattle";
				soundOpenABit = "doorMetalContainerOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};

	class land_iat_doubledoor_wooden : IAT_LandDoor_Double_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_doubledoor_wooden.p3d";
		attachments[] = { "Att_CombinationLock" };
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Door2
			{
				displayName = "Door 2";
				component = "Door2";
				soundPos = "door2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class land_iat_doubledoor_metal : IAT_LandDoor_Double_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_doubledoor_metal.p3d";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
			class Door2
			{
				displayName = "Door 2";
				component = "Door2";
				soundPos = "door2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class land_iat_doubledoor_iron : IAT_LandDoor_Double_Colorbase
	{
		scope = 1;
		model = "iat_more_doors\camping\land\smallshed\iat_doubledoor_iron.p3d";
		attachments[] = { "Att_CombinationLock" };
		class Doors
		{
			class Door1
			{
				displayName = "Door 1";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalContainerOpen";
				soundClose = "doorMetalContainerClose";
				soundLocked = "doorMetalContainerRattle";
				soundOpenABit = "doorMetalContainerOpenABit";
			};
			class Door2
			{
				displayName = "Door 2";
				component = "Door2";
				soundPos = "door2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalContainerOpen";
				soundClose = "doorMetalContainerClose";
				soundLocked = "doorMetalContainerRattle";
				soundOpenABit = "doorMetalContainerOpenABit";
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};

	/*====================== CONSTRUCTION DOORS ==================================
	* These doors are for player construction. Their animations are always "closed" by default.
	*=============================================================================*/
	class IAT_MoreDoor_Kit : Inventory_Base
	{
		scope = 2;
		displayName = "Door Kit";
		descriptionShort = "A kit that has several options for placing a door.";
		model = "\DZ\gear\camping\fence_kit.p3d";
		rotationFlags = 17;
		itemSize[] = { 1, 5 };
		weight = 280;
		itemBehaviour = 1;
		debug_ItemCategory = 10;
		soundImpactType = "wood";
		iat_KitOptionDisplayNames[] =
		{
			"Single - Left - Wood - Small",
			"Single - Left - Metal - Small",
			"Single - Left - Iron - Small",
			"Single - LeftHatch - Wood - Large",
			"Single - Right - Wood - Small",
			"Single - Right - Metal - Small",
			"Single - Right - Iron - Small",
			"Single - RightHatch - Wood - Large",
			"Double - Wood - Small",
			"Double - Metal - Small",
			"Double - Iron - Small",
			"Double - Wood - Medium Shed",
			"Double - Metal - Medium Shed",
			"Double - Iron - Medium Shed",
			"Double - Wood - Hatch",
		};
		iat_KitOptionClassNames[] =
		{
			"IAT_ConstructionDoor_Single_Left_Wooden",
			"IAT_ConstructionDoor_Single_Left_Metal",
			"IAT_ConstructionDoor_Single_Left_Iron",
			"IAT_ConstructionDoor_Single_Left_WoodenLargeHatch",
			"IAT_ConstructionDoor_Single_Right_Wooden",
			"IAT_ConstructionDoor_Single_Right_Metal",
			"IAT_ConstructionDoor_Single_Right_Iron",
			"IAT_ConstructionDoor_Single_Right_WoodenLargeHatch",
			"IAT_ConstructionDoor_Double_Wooden",
			"IAT_ConstructionDoor_Double_Metal",
			"IAT_ConstructionDoor_Double_Iron",
			"IAT_ConstructionDoor_Double_WoodenMedium",
			"IAT_ConstructionDoor_Double_MetalMedium",
			"IAT_ConstructionDoor_Double_IronMedium",
			"IAT_ConstructionDoor_Double_WoodenHatch",
		};
		class AnimationSources
		{
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = { {1, {}}, {0.7, {}}, {0.5, {}}, {0.3, {}}, {0, {}} };
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};

	class IAT_ConstructionDoor_Colorbase : Inventory_Base
	{
		scope = 0;
		displayName = "Door";
		descriptionShort = "A sturdy door";
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_left_wooden_c.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "false";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		physLayer = "item_large"; // give it collission
		debug_ItemCategory = 10;
		weight = 100000;
		itemSize[] = { 50, 50 };
		itemsCargoSize[] = { 0 , 0 };
		hiddenSelections[] = { "zbytek", "metal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa"
		};
	};
	class IAT_ConstructionDoor_Single_Colorbase : IAT_ConstructionDoor_Colorbase
	{
		class AnimationSources
		{
			class DoorRotate1
			{
				source = "user";
				animPeriod = 2.0;
				initPhase = 0;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class Melee
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
			};
			class DamageZones
			{
				class Door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door1" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
			};
		};
	};
	class IAT_ConstructionDoor_Double_Colorbase : IAT_ConstructionDoor_Colorbase
	{
		class AnimationSources
		{
			class DoorRotate1
			{
				source = "user";
				animPeriod = 2.0;
				initPhase = 0;
			};
			class DoorRotate2
			{
				source = "user";
				animPeriod = 2.0;
				initPhase = 0;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
				class Melee
				{
					class Health { damage = 0; };
					class Blood { damage = 0; };
					class Shock { damage = 0; };
				};
			};
			class DamageZones
			{
				class Door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door1" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
				class Door2
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = { "door2" };
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health { damage = 2; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
						class Melee
						{
							class Health { damage = 2.5; };
							class Blood { damage = 0; };
							class Shock { damage = 0; };
						};
					};
				};
			};
		};
	};

	class IAT_ConstructionDoor_Single_Left_Wooden : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_left_wooden_c.p3d";
		iat_RecipeDisplayName = "Single - Left Door - Wood - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Single_Left_Metal : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_left_metal_c.p3d";
		iat_RecipeDisplayName = "Single - Left Door - Metal - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Single_Left_Iron : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_left_iron_c.p3d";
		iat_RecipeDisplayName = "Single - Left Door - Iron - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Single_Left_WoodenLargeHatch : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		displayName = "Hatch";
		model = "iat_more_doors\camping\construction\largehatch\iat_lhatchdoor_wooden_c.p3d";
		iat_RecipeDisplayName = "Single - Left Hatch Door - Wooden - Large";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};

	class IAT_ConstructionDoor_Single_Right_Wooden : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_right_wooden_c.p3d";
		iat_RecipeDisplayName = "Single - Right Door - Wood - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Single_Right_Metal : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_right_metal_c.p3d";
		iat_RecipeDisplayName = "Single - Right Door - Metal - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Single_Right_Iron : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_singledoor_right_iron_c.p3d";
		iat_RecipeDisplayName = "Single - Right Door - Iron - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Single_Right_WoodenLargeHatch : IAT_ConstructionDoor_Single_Colorbase
	{
		scope = 2;
		displayName = "Hatch";
		model = "iat_more_doors\camping\construction\largehatch\iat_rhatchdoor_wooden_c.p3d";
		iat_RecipeDisplayName = "Single - Right Hatch Door - Wooden - Large";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};

	class IAT_ConstructionDoor_Double_Wooden : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_doubledoor_wooden_c.p3d";
		iat_RecipeDisplayName = "Double Doors - Wood - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Double_Metal : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_doubledoor_metal_c.p3d";
		iat_RecipeDisplayName = "Double Doors - Metal - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Double_Iron : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\smallshed\iat_doubledoor_iron_c.p3d";
		iat_RecipeDisplayName = "Double Doors - Iron - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Double_WoodenHatch : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		displayName = "Hatch";
		model = "iat_more_doors\camping\construction\largehatch\iat_dhatchdoor_wooden_c.p3d";
		iat_RecipeDisplayName = "Hatch Doors - Wood - Small Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};


	class IAT_ConstructionDoor_Double_WoodenMedium : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\mediumshed\iat_doubledoor_mshed_wooden_c.p3d";
		iat_RecipeDisplayName = "Double Doors - Wood - Medium Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Double_MetalMedium : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\mediumshed\iat_doubledoor_mshed_metal_c.p3d";
		iat_RecipeDisplayName = "Double Doors - Metal - Medium Shed";
		attachments[] = { "Att_CombinationLock" };
		hiddenSelections[] = { "zbytek", "metal", "sheetmetal" };
		hiddenSelectionsTextures[] =
		{
			"DZ\gear\consumables\data\pile_of_planks_co.paa",
			"DZ\structures\industrial\pipes\data\pipes_co.paa",
			"DZ\gear\consumables\data\metalsheets_co.paa",
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};
	class IAT_ConstructionDoor_Double_IronMedium : IAT_ConstructionDoor_Double_Colorbase
	{
		scope = 2;
		model = "iat_more_doors\camping\construction\mediumshed\iat_doubledoor_mshed_iron_c.p3d";
		iat_RecipeDisplayName = "Double Doors - Iron - Medium Shed";
		attachments[] = { "Att_CombinationLock" };
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = { "Att_CombinationLock" };
				icon = "set:dayz_inventory image:cat_bb_attachments";
			};
		};
	};


};