class IAT_ActionDescendIntoMine extends ActionInteractBase
{
	ref NoiseParams m_NoisePar;

	void IAT_ActionDescendIntoMine()
	{
		m_CommandUID 	= DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text 			= "Enter Mineshaft";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINone();
		m_ConditionTarget 	= new CCTCursor();
	}

	protected bool CreatesNoise()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target)
			return false;

		land_iat_miningsegment_entrance mineEntrance;
		if (Class.CastTo(mineEntrance, target.GetObject()))
		{
			if (mineEntrance.CanEnterMine())
			{
				return true;
			}
		}
		return false;
	}

	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		land_iat_miningsegment_entrance mineEntrance;
		if (Class.CastTo(mineEntrance, action_data.m_Target.GetObject()))
		{
			if (mineEntrance.CanEnterMine())
			{
				if (MiscGameplayFunctions.TeleportPlayerToSafeLocation3D(action_data.m_Player, mineEntrance.GetTeleportDestination()))
				{
					// teleported
					// Print("teleported");
				}
			}
		}
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		m_NoisePar = new NoiseParams();
		m_NoisePar.LoadFromPath("CfgVehicles SurvivorBase NoiseActionDefault");
		NoiseSystem noise = GetGame().GetNoiseSystem();
		if (noise && CreatesNoise())
		{
			if (action_data.m_Player)
				noise.AddNoisePos(action_data.m_Player, action_data.m_Target.GetObject().GetPosition(), m_NoisePar, NoiseAIEvaluate.GetNoiseReduction(GetGame().GetWeather()));
		}
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		land_iat_miningsegment_entrance mineEntrance;
		if (Class.CastTo(mineEntrance, action_data.m_Target.GetObject()))
		{
			return " teleported using a mine entrance from: %1 to: %2 " + action_data.m_Target.GetObject().GetPosition();
		}
		return "";
	}

	override bool IsLockTargetOnUse()
	{
		return false;
	}
};