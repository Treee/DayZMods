modded class CAContinuousMineRock
{
	override bool GetMiningData(ActionData action_data )
	{
		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, action_data.m_Target.GetObject()))
		{
			iat_Junction.SpawnMaterialAndQuantityYield();

			m_DamageToMiningItemEachDrop = iat_Junction.GetDamageToMiningItemEachYield(action_data.m_MainItem);
			m_AdjustedDamageToMiningItemEachDrop = m_DamageToMiningItemEachDrop;
			return true;
		}
		else
			return super.GetMiningData(action_data);
	}
};

modded class ActionMineRock
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// if we can mine
		if (super.ActionCondition(player, target, item))
		{
			IAT_MiningSegment_Colorbase iat_Junction;
			// check our custom walls
			if (Class.CastTo(iat_Junction, target.GetObject()))
			{
				if (iat_Junction.IsMineable())
				{
					int doorIndex = iat_Junction.GetDoorIndex(target.GetComponentIndex());
					// PrintFormat("door index: %1", doorIndex);
					if (doorIndex != -1)
					{
						// Print("has door, check is in reach");
						if (!IsInReach(player, target, UAMaxDistances.REPAIR))
							return false;

						return iat_Junction.CanDoorBeOpened(doorIndex, true);
					}
				}
				// our custom conditions failed, action failed
				return false;
			}
			// pass through vanilla true
			return true;
		}
		// pass through vanilla false
		return false;
	}

	override string GetYieldName(PlayerBase player, ActionTarget target, ItemBase item)
	{
		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, target.GetObject()))
		{
			if (iat_Junction.IsMineable())
			{
				return iat_Junction.GetMiningYield(item);
			}
		}
		return super.GetYieldName(player, target, item);
	}

	// happens approximately eight seconds
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, action_data.m_Target.GetObject()))
		{
			// get the index of the door we are looking at
			int doorIndex = iat_Junction.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			// if we are looking at a door
			if (doorIndex != -1)
			{
				int modifiedDoorIndex = doorIndex + 1;
				string componentName = string.Format("door%1", modifiedDoorIndex);
				// damage the walls so that they will open eventually
				iat_Junction.DecreaseHealth(componentName, "Health", iat_Junction.GetDamageToMineWallEachYield(action_data.m_MainItem));
				// if the door hp is less than 0
				if (iat_Junction.GetHealth(componentName, "Health") <= 0)
				{
					// Print("open door");
					// open the door
					iat_Junction.OpenDoor(doorIndex);

					iat_Junction.SetPlaySmokeParticles(true);
					iat_Junction.SetSynchDirty();
				}
			}
		}
	}
};