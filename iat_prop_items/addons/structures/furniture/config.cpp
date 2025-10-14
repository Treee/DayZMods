class CfgPatches
{
    class IAT_Prop_Items_Structures_Furniture
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Structures_Furniture" };
    };
};
class CfgVehicles
{
    class HouseNoDestruct;

    class IAT_OccultTable_Colorbase : HouseNoDestruct
    {
        scope = 1;
        displayName = "Occult Table";
        model = "iat_prop_items\structures\furniture\iat_occulttable.p3d";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\structures\furniture\data\iat_occulttable_co.paa" };
        attachments[] = { "IAT_OccultCard1", "IAT_OccultCard2", "IAT_OccultCard3", "IAT_OccultCard4", "IAT_OccultCard5", "IAT_OccultCard6", "IAT_OccultCard7", "IAT_OccultCard8" };
    };
    class IAT_OccultTable_basic : IAT_OccultTable_Colorbase
    {
        scope = 1;
    };
    class IAT_OccultTable_essesentiendum : IAT_OccultTable_Colorbase
    {
        scope = 1;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\structures\furniture\data\iat_occulttable_essesentiendum_co.paa" };
    };

    class IAT_NeonSign_TheStash : HouseNoDestruct
    {
        scope = 1;
        model = "iat_prop_items\structures\furniture\iat_neonsign_thestash.p3d";
    };
};

class CfgSlots
{
    class Slot_IAT_OccultCard1
    {
        name = "IAT_OccultCard1";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard2
    {
        name = "IAT_OccultCard2";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard3
    {
        name = "IAT_OccultCard3";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard4
    {
        name = "IAT_OccultCard4";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard5
    {
        name = "IAT_OccultCard5";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard6
    {
        name = "IAT_OccultCard6";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard7
    {
        name = "IAT_OccultCard7";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
    class Slot_IAT_OccultCard8
    {
        name = "IAT_OccultCard8";
        displayName = "Tarot Card";
        ghostIcon = "set:dayz_inventory image:paper";
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyiat_occulttable_card1 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard1" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card1.p3d";
    };
    class Proxyiat_occulttable_card2 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard2" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card2.p3d";
    };
    class Proxyiat_occulttable_card3 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard3" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card3.p3d";
    };
    class Proxyiat_occulttable_card4 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard4" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card4.p3d";
    };
    class Proxyiat_occulttable_card5 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard5" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card5.p3d";
    };
    class Proxyiat_occulttable_card6 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard6" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card6.p3d";
    };
    class Proxyiat_occulttable_card7 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard7" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card7.p3d";
    };
    class Proxyiat_occulttable_card8 : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_OccultCard8" };
        model = "iat_prop_items\structures\furniture\proxy\iat_occulttable_card8.p3d";
    };
};