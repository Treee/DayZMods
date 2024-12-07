modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        SpawnEverything();
    };

    void SpawnEverything()
    {
        IAT_OneOfEverythingHelper helper = new IAT_OneOfEverythingHelper();
        helper.GetOneOfEverythingConfig();
        helper.LoadAllP3ds();
    }
};