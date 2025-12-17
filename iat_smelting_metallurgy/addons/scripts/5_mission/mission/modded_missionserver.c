modded class MissionServer
{
	override void OnInit()
    {
        super.OnInit();
		GetDayZGame().SetIATSmeltingConfig(GetDayZGame().GetIATSmeltingConfig());
		Print("[IAT_Smelting] Config Initialized");
    }

	override void OnMissionStart()
	{
		super.OnMissionStart();
		Print("[IAT_Smelting] Setup Smelting Info");
	}

	override void OnMissionFinish()
	{
		GetDayZGame().GetIATSmeltingConfig().SaveConfig();
		super.OnMissionFinish();
	}
};