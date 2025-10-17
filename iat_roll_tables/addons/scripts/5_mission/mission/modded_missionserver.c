modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATRollTableConfig(GetDayZGame().GetIATRollTableConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		auto configParams = new Param1<IAT_RollTableConfig>(GetDayZGame().GetIATRollTableConfig());
		PrintFormat("Sending IAT_RollTable Mod Config to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_RollTables.CHECK_ROLLTABLE_CONFIG);
		GetGame().RPCSingleParam(player, IAT_RPC_RollTables.CHECK_ROLLTABLE_CONFIG, configParams, true, identity);
	}
};