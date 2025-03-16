modded class MissionServer
{
	override void OnInit()
    {
        super.OnInit();
		GetDayZGame().SetIATTeleportLinkConfig(GetDayZGame().GetIATTeleportLinkConfig());
		Print("[IAT_Teleport_Linker] Config Initialized");
    }

	override void OnMissionStart()
	{
		super.OnMissionStart();
		Print("[IAT_Teleport_Linker] Setup Teleports");

		IAT_TeleportLinkConfig teleportLinks = GetDayZGame().GetIATTeleportLinkConfig();
	}

	override void OnMissionFinish()
	{
		GetDayZGame().GetIATTeleportLinkConfig().SaveConfig();
		super.OnMissionFinish();
	}
};