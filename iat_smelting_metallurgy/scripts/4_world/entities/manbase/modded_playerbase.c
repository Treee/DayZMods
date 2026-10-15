modded class PlayerBase
{
	// This way we can track score between UI opens
	protected int m_IAT_SmeltingMiniGameWins = 0;
	protected int m_IAT_SmeltingMiniGameLoss = 0;
	protected int m_IAT_SmeltingMiniGameStreak = 0;

	protected bool m_IAT_SmeltingMiniGameLastGameWin = false;
	protected bool m_IAT_SyncedSmeltingScore = false;

	override void SetActions(out TInputActionMap InputActionMap)
    {
        super.SetActions(InputActionMap);
        AddAction(IAT_ActionOpenSmeltingMenu, InputActionMap);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == IAT_RPC_SMELTING.SERVER_SEND_CONFIG)
		{
			Param1<IAT_SmeltingScore> configParams;
			// read the params, short circuit if there is an error
			if(!ctx.Read(configParams))
				return;

			// sync local score with server score
			IAT_SmeltingScore playerScore;
			if (Class.CastTo(playerScore, configParams.param1))
			{
				IAT_SetSmeltingDataFromStore(playerScore.GetWins(), playerScore.GetLoss(), playerScore.GetCurrentStreak());
			}
		}
	}

	//=============================================== PUBLIC METHODS
	void IAT_SetSmeltingDataFromStore(int wins, int loss, int currentStreak)
	{
		m_IAT_SmeltingMiniGameWins = wins;
		m_IAT_SmeltingMiniGameLoss = loss;
		m_IAT_SmeltingMiniGameStreak = currentStreak;
	}
	void IAT_IncrementSmeltingWins(PlayerIdentity identity)
	{
		// increment wins
		m_IAT_SmeltingMiniGameWins += 1;
		// increment streak
		IAT_IncrementSmeltingStreak();
		// set we've won
		m_IAT_SmeltingMiniGameLastGameWin = true;

		// server side update of score
		if (g_Game.IsDedicatedServer())
		{
			IAT_SmeltingConfig smeltingConfig;
			if (GetDayZGame() && Class.CastTo(smeltingConfig, GetDayZGame().GetIATSmeltingConfig()))
			{
				smeltingConfig.IncrementPlayerWins(identity.GetPlainId(), m_IAT_SmeltingMiniGameWins, m_IAT_SmeltingMiniGameStreak);
			}
		}
	}
	void IAT_IncrementSmeltingLoss(PlayerIdentity identity)
	{
		m_IAT_SmeltingMiniGameLoss += 1;
		m_IAT_SmeltingMiniGameLastGameWin = false;
		IAT_ResetStreak();

		// server side update of score
		if (g_Game.IsDedicatedServer())
		{
			IAT_SmeltingConfig smeltingConfig;
			if (GetDayZGame() && Class.CastTo(smeltingConfig, GetDayZGame().GetIATSmeltingConfig()))
			{
				smeltingConfig.IncrementPlayerLoss(identity.GetPlainId(), m_IAT_SmeltingMiniGameLoss);
			}
		}
	}
	void IAT_IncrementSmeltingStreak()
	{
		m_IAT_SmeltingMiniGameStreak += 1;
	}
	void IAT_ResetStreak()
	{
		m_IAT_SmeltingMiniGameStreak = 0;
	}
	// Quick hack to move score checking into the action of opening the client side menu.
	// Prior all players that logged in were being added to the json. This attempts to clamp
	// that behavior to only those who interact with the smelters resulting in MUCH smaller lists.
	bool IAT_TrySyncedSmeltingScore(PlayerIdentity identity)
	{
		if (g_Game.IsDedicatedServer())
		{
			if (!m_IAT_SyncedSmeltingScore)
			{
				PlayerBase player;
				if (Class.CastTo(player, identity.GetPlayer()))
				{
					m_IAT_SyncedSmeltingScore = true;
					IAT_SmeltingConfig smeltingConfig;
					if (Class.CastTo(smeltingConfig, GetDayZGame().GetIATSmeltingConfig()))
					{
						IAT_SmeltingScore playerScore;
						if (Class.CastTo(playerScore, smeltingConfig.IAT_GetSmeltingScore(identity.GetName(), identity.GetPlainId())))
						{
							Param1<IAT_SmeltingScore> configParams = new Param1<IAT_SmeltingScore>(playerScore);
							PrintFormat("[IAT_Smelting] Sending Score to Player: %1 RPC: %2", identity.GetName(), IAT_RPC_SMELTING.SERVER_SEND_CONFIG);
							g_Game.RPCSingleParam(player, IAT_RPC_SMELTING.SERVER_SEND_CONFIG, configParams, true, identity);
							player.IAT_SetSmeltingDataFromStore(playerScore.GetWins(), playerScore.GetLoss(), playerScore.GetCurrentStreak());

							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool IAT_IsOnStreak()
	{
		return m_IAT_SmeltingMiniGameLastGameWin;
	}
	int IAT_GetSmeltingWins()
	{
		return m_IAT_SmeltingMiniGameWins;
	}
	int IAT_GetSmeltingLoss()
	{
		return m_IAT_SmeltingMiniGameLoss;
	}
	int IAT_GetSmeltingStreak()
	{
		return m_IAT_SmeltingMiniGameStreak;
	}
};