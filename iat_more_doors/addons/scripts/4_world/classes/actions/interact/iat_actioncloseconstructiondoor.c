class IAT_ActionCloseConstructionDoor extends ActionInteractBase
{
	ref NoiseParams m_NoisePar;

	const string SELECTION_INTERACT_DOOR1 = "door1";
	const string SELECTION_INTERACT_DOOR2 = "door2";

	void IAT_ActionCloseConstructionDoor()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_Text = "#close";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// sanity check null for target object
		Object targetObject;
		if (Class.CastTo(targetObject, target.GetObject()))
		{
			// attempt to cast to our door type
			IAT_ConstructionDoor_Colorbase iat_door;
			if (Class.CastTo(iat_door, targetObject))
			{
				// get the component name of the thing we are looking at
				string componentName = iat_door.GetActionComponentName(target.GetComponentIndex());
				// lowecase it
				componentName.ToLower();
				// if the player can close the door
				if (iat_door.CanCloseDoor(componentName))
				{
					// if we are looking at a door1/door2
					if (componentName == SELECTION_INTERACT_DOOR1)
					{
						return true; // we can open the door
					}
					if (componentName == SELECTION_INTERACT_DOOR2)
					{
						return true; // we can open the door
					}
				}
			}
		}
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer(action_data);

		IAT_ConstructionDoor_Colorbase iat_door;
		if (Class.CastTo(iat_door, action_data.m_Target.GetObject()))
		{
			string componentName = iat_door.GetActionComponentName(action_data.m_Target.GetComponentIndex());
			// lowercase it
			componentName.ToLower();
			// close the door server side
			iat_door.CloseDoor(componentName);
		}
	}

	// override void OnEndServer( ActionData action_data )
	// {
	// 	super.OnEndServer(action_data);
	// 	// paly sounds
	// 	m_NoisePar = new NoiseParams();
	// 	m_NoisePar.LoadFromPath("CfgVehicles SurvivorBase NoiseActionDefault");
	// 	NoiseSystem noise = GetGame().GetNoiseSystem();
	// 	if ( noise )
	// 	{
	// 		if ( action_data.m_Player )
	// 			noise.AddNoisePos(action_data.m_Player, action_data.m_Target.GetObject().GetPosition(), m_NoisePar, NoiseAIEvaluate.GetNoiseReduction(GetGame().GetWeather()));
	// 	}
	// }
}