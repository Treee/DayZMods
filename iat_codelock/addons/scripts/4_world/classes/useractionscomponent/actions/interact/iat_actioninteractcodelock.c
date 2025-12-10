class IAT_ActionInteractCodelock extends ActionInteractBase
{
	ref NoiseParams m_NoisePar;

	void IAT_ActionInteractCodelock()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;

		m_Text = "Interact with Codelock";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone();
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
	}

	override bool HasProneException()
	{
		return true;
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// this action path goes from most specific to most generic (reverse funnel)
		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					return CanPlayerInteractWithCodelockedObject(iat_codelock, player);
				}
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, target.GetParent()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					return CanPlayerInteractWithCodelockedObject(iat_codelock, player);
				}
			}
		}
		return false;
	};

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		IAT_Codelock_Colorbase iat_codelock;
		// check the target objects inventory to see if there is a codelock present
		EntityAI targetEntity;
		if (Class.CastTo(targetEntity, action_data.m_Target.GetObject()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					iat_codelock.OpenPasscodeEntryMenu();
					return; // short circuit
				}
			}
		}
		// check the target objects parent to see if it has a codelock
		if (Class.CastTo(targetEntity, action_data.m_Target.GetParent()))
		{
			if (targetEntity.GetInventory())
			{
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					iat_codelock.OpenPasscodeEntryMenu();
					return; // short circuit
				}
			}
		}
	}

	override void OnEndServer( ActionData action_data )
	{
		super.OnEndServer(action_data);

		m_NoisePar = new NoiseParams();
		m_NoisePar.LoadFromPath("CfgVehicles SurvivorBase NoiseActionDefault");
		NoiseSystem noise = g_Game.GetNoiseSystem();
		if ( noise )
		{
			if ( action_data.m_Player )
				noise.AddNoisePos(action_data.m_Player, action_data.m_Player.GetPosition(), m_NoisePar, NoiseAIEvaluate.GetNoiseReduction(g_Game.GetWeather()));
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " interact with code lock ";
	}

	bool CanPlayerInteractWithCodelockedObject(IAT_Codelock_Colorbase iat_codelock, PlayerBase player)
	{
		// does the player NOT have access to the codelock?
		if (iat_codelock && !iat_codelock.HasAccess(player.GetIdentity()))
		{
			// if the codelock has no owner, do not allow interacting
			if (!iat_codelock.HasOwner())
			{
				return false;
			}
			// have they already tried to access it too many times?
			if (player.HasFailedPasscodeEntryTooManyTimes())
			{
				// if so, return false
				return false;
			}
			return true;
		}
		return false;
	}
};