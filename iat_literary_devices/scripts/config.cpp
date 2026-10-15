class CfgPatches
{
    class IAT_LiteraryDevices_Scripts
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};
class CfgMods
{
    class IAT_LiteraryDevices
    {
        type = "mod";
        author = "ItsATreee";
        name = "ItsATreee Literary Devices";
        dir = "IAT_LiteraryDevices";
        dependencies[] = { "World","Mission" };
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = { "iat_literary_devices\scripts\4_world" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "iat_literary_devices\scripts\5_mission" };
            };
        };
    };
};