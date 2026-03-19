modded class MissionServer
{
	void MissionServer()
	{
		IAT_DayZCodexConfig m_Codex = GetDayZGame().GetIATDayZCodexConfig();

		GetDayZGame().SetIATDayZCodexConfig(m_Codex);

		m_Codex.IAT_Codex_ParseCfgItems(CFG_VEHICLESPATH);
		m_Codex.IAT_Codex_ParseCfgItems(CFG_WEAPONSPATH);
		m_Codex.IAT_Codex_ParseCfgItems(CFG_MAGAZINESPATH);
		m_Codex.PrettyPrint();
	}

};