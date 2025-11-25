modded class MissionServer
{
	override void OnInit()
    {
        super.OnInit();
		GetDayZGame().SetIATSmeltingConfig(GetDayZGame().GetIATSmeltingConfig());
		Print("[IAT_Smelting] Config Initialized");
    }

	override void OnMissionStart()
	{
		super.OnMissionStart();
		Print("[IAT_Smelting] Setup SMelting Info");
	}

	override void OnMissionFinish()
	{
		GetDayZGame().GetIATSmeltingConfig().SaveConfig();
		super.OnMissionFinish();
	}

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player)
	{
		super.OnClientReadyEvent(identity, player);

		IAT_SmeltingConfig smeltingConfig;
		if (Class.CastTo(smeltingConfig, GetDayZGame().GetIATSmeltingConfig()))
		{
			IAT_SmeltingScore playerScore;
			if (Class.CastTo(playerScore, smeltingConfig.IAT_GetSmeltingScore(identity.GetName(), identity.GetPlainId())))
			{
				Param1<IAT_SmeltingScore> configParams = new Param1<IAT_SmeltingScore>(playerScore);
				PrintFormat("[IAT_Smelting] Sending Score to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_SMELTING.SERVER_SEND_CONFIG);
				GetGame().RPCSingleParam(player, IAT_RPC_SMELTING.SERVER_SEND_CONFIG, configParams, true, identity);
				player.IAT_SetSmeltingDataFromStore(playerScore.GetWins(), playerScore.GetLoss(), playerScore.GetCurrentStreak());
			}
		}
	}
};