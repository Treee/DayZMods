modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATDynamicRadioConfig(GetDayZGame().GetIATDynamicRadioConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		Param1<IAT_DynamicRadioConfig> configParams = new Param1<IAT_DynamicRadioConfig>(GetDayZGame().GetIATDynamicRadioConfig());
		PrintFormat("[IAT_DynamicRadioConfig] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_DYNAMICRADIO_RPC.CHECK_DYNAMICRADIO_CONFIG);
		GetGame().RPCSingleParam(player, IAT_DYNAMICRADIO_RPC.CHECK_DYNAMICRADIO_CONFIG, configParams, true, identity);
	}
};