class CfgPatches
{
    class IAT_Crafting_Plus_Crafting
    {
        requiredAddons[] = { "DZ_Data" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    class IAT_CraftingPlus_CraftingBench_Test : Inventory_Base
    {
        scope = 2;
        displayName = "Test Workbench Plus";
        descriptionShort = "A test workbench used to showcase advanced crafting.";
        model = "DZ\structures\Furniture\Tables\kitchen_table_a\kitchen_table_a.p3d";
        overrideDrawArea = 8;
        useEntityHierarchy = "true";
        attachments[] =
        {
            "Material_WoodenLogs",
            "Material_L1_WoodenPlanks",
            "Material_MetalSheets",
            "MetalWire",
            "Material_Shelter_Fabric",
            "Rags",
            "Chemlight",
            "WalkieTalkie"
        };
        destroyOnEmpty = 0;
        carveNavmesh = 0;
        canBeDigged = 0;
        heavyItem = 1;
        weight = 500;
        itemSize[] = { 10,4 };
        itemsCargoSize[] = { 0,0 };
        itemBehaviour = 0;
        physLayer = "item_large";
        allowOwnedCargoManipulation = 1;
        class GUIInventoryAttachmentsProps
        {
            class Wood
            {
                name = "Wood Ingredients";
                description = "Logs, planks, sticks, and other wooden components.";
                attachmentSlots[] =
                {
                    "Material_WoodenLogs",
                    "Material_L1_WoodenPlanks",
                };
                icon = "set:dayz_inventory image:woodenlog";
            };
            class Metal
            {
                name = "Metal Ingredients";
                description = "Metal sheets, wire, ingots and other metal components.";
                attachmentSlots[] =
                {
                    "Material_MetalSheets",
                    "MetalWire",
                };
                icon = "set:dayz_inventory image:plates";
            };
            class Fabric
            {
                name = "Fabric Ingredients";
                description = "Fabric, burlap strips, rags and other fabrics.";
                attachmentSlots[] =
                {
                    "Material_Shelter_Fabric",
                    "Rags"
                };
                icon = "set:dayz_inventory image:tarp";
            };
            class Chemical
            {
                name = "Chemical Ingredients";
                description = "Glowsticks, radios, etc.";
                attachmentSlots[] =
                {
                    "Chemlight",
                    "WalkieTalkie"
                };
                icon = "set:dayz_inventory image:chemlight";
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5000;
                    healthLevels[] =
                    {

                        {
                            1.01,
                            {}
                        },

                        {
                            0.69999999,
                            {}
                        },

                        {
                            0.5,
                            {}
                        },

                        {
                            0.30000001,
                            {}
                        },

                        {
                            0.0099999998,
                            {}
                        }
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem_Light
                {
                    soundSet = "pickUpBarrelLight_SoundSet";
                    id = 796;
                };
                class pickUpItem
                {
                    soundSet = "pickUpBarrel_SoundSet";
                    id = 797;
                };
            };
        };
    };
};