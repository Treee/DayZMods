modded class MissionServer
{
	void MissionServer()
    {
		GetDayZGame().SetIATSmeltingConfig(GetDayZGame().GetIATSmeltingConfig());
    }

	override void OnMissionFinish()
	{
		GetDayZGame().GetIATSmeltingConfig().SaveConfig();
		super.OnMissionFinish();
	}
};