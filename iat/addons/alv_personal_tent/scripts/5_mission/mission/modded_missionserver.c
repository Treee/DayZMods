modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().IAT_SetTentManager(GetDayZGame().IAT_GetTentManager());
	}
};