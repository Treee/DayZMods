class CfgPatches
{
    class IAT_InfinityGauntlet_Proxy
    {
        requiredAddons[] = { "DZ_Scripts" };
    };
};
class CfgSlots
{
    class Slot_IAT_InfinityStone_Mind
    {
        name = "IAT_InfinityStone_Mind";
        displayName = "Mind Stone";
        ghostIcon = "set:dayz_inventory image:stones";
        stackMax = 1;
    };
    class Slot_IAT_InfinityStone_Power
    {
        name = "IAT_InfinityStone_Power";
        displayName = "Power Stone";
        ghostIcon = "set:dayz_inventory image:stones";
        stackMax = 1;
    };
    class Slot_IAT_InfinityStone_Reality
    {
        name = "IAT_InfinityStone_Reality";
        displayName = "Reality Stone";
        ghostIcon = "set:dayz_inventory image:stones";
        stackMax = 1;
    };
    class Slot_IAT_InfinityStone_Soul
    {
        name = "IAT_InfinityStone_Soul";
        displayName = "Soul Stone";
        ghostIcon = "set:dayz_inventory image:stones";
        stackMax = 1;
    };
    class Slot_IAT_InfinityStone_Space
    {
        name = "IAT_InfinityStone_Space";
        displayName = "Space Stone";
        ghostIcon = "set:dayz_inventory image:stones";
        stackMax = 1;
    };
    class Slot_IAT_InfinityStone_Time
    {
        name = "IAT_InfinityStone_Time";
        displayName = "Time Stone";
        ghostIcon = "set:dayz_inventory image:stones";
        stackMax = 1;
    };
};

class CfgNonAIVehicles
{
    class ProxyAttachment;
    class Proxyiat_infinitystone_mind : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_InfinityStone_Mind" };
        model = "iat_infinity_gauntlet\proxy\data\iat_infinitystone_mind.p3d";
    };
    class Proxyiat_infinitystone_power : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_InfinityStone_Power" };
        model = "iat_infinity_gauntlet\proxy\data\iat_infinitystone_power.p3d";
    };
    class Proxyiat_infinitystone_reality : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_InfinityStone_Reality" };
        model = "iat_infinity_gauntlet\proxy\data\iat_infinitystone_reality.p3d";
    };
    class Proxyiat_infinitystone_soul : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_InfinityStone_Soul" };
        model = "iat_infinity_gauntlet\proxy\data\iat_infinitystone_soul.p3d";
    };
    class Proxyiat_infinitystone_space : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_InfinityStone_Space" };
        model = "iat_infinity_gauntlet\proxy\data\iat_infinitystone_space.p3d";
    };
    class Proxyiat_infinitystone_time : ProxyAttachment
    {
        scope = 2;
        inventorySlot[] = { "IAT_InfinityStone_Time" };
        model = "iat_infinity_gauntlet\proxy\data\iat_infinitystone_time.p3d";
    };
};