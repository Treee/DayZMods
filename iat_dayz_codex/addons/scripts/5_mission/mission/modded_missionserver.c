modded class MissionServer
{
	void MissionServer()
	{
		IAT_DayZCodexConfig m_Codex = GetDayZGame().GetIATDayZCodexConfig();

		GetDayZGame().SetIATDayZCodexConfig(m_Codex);

		Print("================================================================= FILL ITEM SCHEMA");
		m_Codex.IAT_Codex_ParseCfgItems(CFG_VEHICLESPATH);
		m_Codex.IAT_Codex_ParseCfgItems(CFG_WEAPONSPATH);
		m_Codex.IAT_Codex_ParseCfgItems(CFG_MAGAZINESPATH);
		m_Codex.PrettyPrint();
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		auto configParams = new Param1<IAT_DayZCodexConfig>(GetDayZGame().GetIATDayZCodexConfig());
		PrintFormat("Sending IAT_DayZCodex Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_DayZCodex.CHECK_CONFIG);
		g_Game.RPCSingleParam(player, IAT_RPC_DayZCodex.CHECK_CONFIG, configParams, true, identity);
	}
};