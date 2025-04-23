modded class MissionServer
{
	void MissionServer()
	{
		GetDayZGame().SetIATPoweredRadioTowerConfig(GetDayZGame().GetIATPoweredRadioTowerConfig());
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		Param1<IAT_PoweredRadioTowerConfig> configParams = new Param1<IAT_PoweredRadioTowerConfig>(GetDayZGame().GetIATPoweredRadioTowerConfig());
		PrintFormat("[IAT_PoweredRadioTowerConfig] Sending Config to Player: %1 RPC: %2", identity.GetName(), IAT_POWEREDRADIOTOWER_RPC.CHECK_POWEREDRADIOTOWER_CONFIG);
		GetGame().RPCSingleParam(player, IAT_POWEREDRADIOTOWER_RPC.CHECK_POWEREDRADIOTOWER_CONFIG, configParams, true, identity);
	}
};