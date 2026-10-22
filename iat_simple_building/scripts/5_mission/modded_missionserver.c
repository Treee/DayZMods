modded class MissionServer
{
	void MissionServer()
	{
		// init the config on the server. client doesnt need to know anything here
		GetDayZGame().SetIATSimpleBuildingConfig(GetDayZGame().GetIATSimpleBuildingConfig());
	}
};