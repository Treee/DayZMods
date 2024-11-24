class CfgMods
{
    class SRP_Core
    {
        type = "mod";
        author = "ItsATreee | Sir Locksley | Turko | Orin | Alevaric | Mar";
        name = "Survivalists Core";
        dir = "TheSurvivalists";
        // inputs = "TheSurvivalists/inputs.xml";
        dependencies[] = { "Game","World","Mission" };
        class defs
        {
            // class imageSets
            // {
            //     files[] =
            //     {
            //       "Survivalists_Scripts/gui/images/srp_sleep_iconset.imageset"
            //     };
            // };
            class gameScriptModule
            {
                value = "";
                files[] = { "TheSurvivalists/Core/scripts/3_game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "TheSurvivalists/Core/scripts/4_world" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "TheSurvivalists/Core/scripts/5_mission" };
            };
        };
    };
};

class CfgPatches
{
    class SRP_Core
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Data",
            "DZ_Scripts",
            // "DZM_VPPAdminToolsScripts", // VPP logging enhancement
            // "deerisle", // for the map (security door)
            // "Deerisle_Security_System", // overriding air craft carrier loot
            // "DeerIsle_Weapons",
            // "JMC_Mjolnir",
            // "CodeLock",
            // "VanillaPlusPlus", // hiding map when restrained
            // "DressupBox_Weapons", // for magazine slots
            // "Survivalists_Narcotics",
            // "Survivalists_Drink",
            // "Survivalists_Food",
            // "Survivalists_RadioElectronics",
            // "Alv_Tac_Gear"
        };
    };
};