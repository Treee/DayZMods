class IAT_ActionManageCodelock extends ActionInteractBase
{
	ref NoiseParams m_NoisePar;

	void IAT_ActionManageCodelock()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;

		m_Text = "Manage Codelock";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINotPresent();
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
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
		IAT_Codelock_Colorbase targetCodelock;
		// is the target a codelock?
		if (Class.CastTo(targetCodelock, target.GetObject()))
		{
			if (targetCodelock.HasAccess(player.GetIdentity()))
			{
				// if the player performing the action has access
				if (targetCodelock.IsOwner(player.GetIdentity().GetPlainId()))
				{
					// return true
					return true;
				}
			}
		}
		EntityAI targetEntity;
		// is the target something that has the codelock attached but not a visible proxy
		if (Class.CastTo(targetEntity, target.GetObject()))
		{
			// does it have an inventory
			if (targetEntity.GetInventory())
			{
				IAT_Codelock_Colorbase iat_codelock;
				// is our codelock attached?
				if (Class.CastTo(iat_codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
				{
					// if the player performing the action has access
					if (iat_codelock.HasAccess(player.GetIdentity()))
					{
						// if the player performing the action has access
						if (iat_codelock.IsOwner(player.GetIdentity().GetPlainId()))
						{
							// return true
							return true;
						}
					}
				}
			}
		}
		return false;
	};

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);
        // sanity check player
		PlayerBase player;
        if (Class.CastTo(player, action_data.m_Player))
        {
			// sanity check direct codelock target
        	IAT_Codelock_Colorbase codelock;
			if (!Class.CastTo(codelock, action_data.m_Target.GetObject()))
			{
				// sanity check indirect codelock target
				EntityAI targetEntity;
				if (Class.CastTo(targetEntity, action_data.m_Target.GetObject()))
				{
					if (targetEntity.GetInventory())
					{
						if (!Class.CastTo(codelock, targetEntity.GetInventory().FindAttachmentByName("Att_CombinationLock")))
						{
							// if we still don't have a codelock, return
							return;
						}
					}
				}
			}
			if (codelock)
			{
				// do client side dance
				codelock.OpenCodelockManagerMenu();
			}
        }
	}

	override void OnEndServer( ActionData action_data )
	{
		super.OnEndServer(action_data);

		m_NoisePar = new NoiseParams();
		m_NoisePar.LoadFromPath("CfgVehicles SurvivorBase NoiseActionDefault");
		NoiseSystem noise = GetGame().GetNoiseSystem();
		if ( noise )
		{
			if ( action_data.m_Player )
				noise.AddNoisePos(action_data.m_Player, action_data.m_Target.GetObject().GetPosition(), m_NoisePar, NoiseAIEvaluate.GetNoiseReduction(GetGame().GetWeather()));
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " managing code lock " + action_data.m_Target.GetObject().GetDisplayName();
	}
};