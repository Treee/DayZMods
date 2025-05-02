modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATCraftingPlusConfig(GetDayZGame().GetIATCraftingPlusConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		Param1<IAT_CraftingPlusConfig> configParams = new Param1<IAT_CraftingPlusConfig>(GetDayZGame().GetIATCraftingPlusConfig());
		PrintFormat("[IAT_CraftingPlusConfig] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_CRAFTINGPLUS_RPC.CHECK_CRAFTINGPLUS_CONFIG);
		GetGame().RPCSingleParam(player, IAT_CRAFTINGPLUS_RPC.CHECK_CRAFTINGPLUS_CONFIG, configParams, true, identity);
	}
};