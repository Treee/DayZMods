class CfgPatches
{
    class IAT_Enhanced_Medical_Tests
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = { "IAT_Enhanced_Medical_Scripts" };
    };
};
class CfgMods
{
    class IAT_Enhanced_Medical_Tests
    {
        type = "mod";
        dependencies[] = { "World" };
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = { "iat_enhanced_medical/tests/scripts/4_world" };
            };
        };
    };
};

// Config fixtures are private to the diagnostic test addon.
class CfgAmmo
{
    class Bullet_556x45;
    class Bullet_12GaugeRubberSlug;
    class Bullet_40mm_Base;
    class Bolt_Base;
    class Bullet_Flare;
    class Bullet_12GaugeBeanbag;
    class IAT_EM_RenamedRound : Bullet_556x45 {};
    class IAT_EM_DeepRoundLevel1 : IAT_EM_RenamedRound {};
    class IAT_EM_DeepRoundLevel2 : IAT_EM_DeepRoundLevel1 {};
    class IAT_EM_DeepRoundLevel3 : IAT_EM_DeepRoundLevel2 {};
    class IAT_EM_RenamedRubber : Bullet_12GaugeRubberSlug {};
    class IAT_EM_RenamedGrenade : Bullet_40mm_Base {};
    class IAT_EM_RenamedBolt : Bolt_Base {};
    class IAT_EM_RenamedFlare : Bullet_Flare {};
    class IAT_EM_RenamedBeanbag : Bullet_12GaugeBeanbag {};
};
class CfgVehicles
{
    class Pliers;
    class BandageDressing;
    class IAT_EM_IncompatibleDressing : BandageDressing
    {
        scope = 1;
        inventorySlot[] = {"WZBandageLArm"};
    };
    class IAT_EM_TestNegativeTool : Pliers { scope = 1; };
    class IAT_EM_TestZeroTool : Pliers { scope = 1; };
};
