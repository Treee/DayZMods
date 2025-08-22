class IAT_ActionFortifyJunction extends ActionSingleUseBase
{
	// down, up, east, west, north, south
	protected ref TStringArray m_WallSupportMemoryPoints = {"door13", "door14", "door15", "door16", "door17", "door18"};
	// temporary fix for holding onto which wall support is closest without recalculating distances
	protected string m_WallToSupport = "";

	void IAT_ActionFortifyJunction()
	{
		m_Text = "Fortify Mining Segment";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTCursor();
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		// if no target, return false
		if (!target)
			return false;

		// if not log in hand, return false
		if (!item.CanFortifyMiningJunction())
			return false;

		IAT_MiningSegment_Colorbase iat_Junction;
		// check our custom walls
		if (Class.CastTo(iat_Junction, target.GetObject()))
		{
			if (iat_Junction.IsMineable())
			{
				// default to no index
				int supportIndex = -1;
				// keep track of the last shortest distance
				float lastSmallestDistance = 99999;
				// keep track of the shortest memory point
				string memoryPointName = "";

				// foreach support memory point
				foreach (int index, string memoryPoint : m_WallSupportMemoryPoints)
				{
					// if the memory point exists
					if (iat_Junction.MemoryPointExists(memoryPoint))
					{
						// translate the model position to world space
						vector selection_pos = iat_Junction.ModelToWorld( iat_Junction.GetMemoryPointPos( memoryPoint ) );
						float mpDistance = vector.Distance(selection_pos, target.GetCursorHitPos());
						// if the cursor target is less than 2m from the memory point
						if (mpDistance < 1.5)
						{
							//this is a valid memory point, check to see if there are any closer so we get best fit
							if (mpDistance < lastSmallestDistance)
							{
								// mpdistance IS smaller than the last distance
								lastSmallestDistance = mpDistance;
								// set best fit memory point
								memoryPointName = memoryPoint;
								// set best fit memory point array index
								supportIndex = index;
								m_WallToSupport = memoryPoint;
							}
						}
					}
				}
				if (supportIndex > -1)
				{
					// append num of doors prior to supports
					supportIndex = supportIndex + 12;
					return iat_Junction.CanDoorBeOpened(supportIndex, true);
				}
			}
		}
		return false;
	}

	override void OnEndServer( ActionData action_data )
	{
		super.OnEndServer(action_data);
		// cast our targeted object to a junction
		IAT_MiningSegment_Colorbase iat_Junction;
		if (Class.CastTo(iat_Junction, action_data.m_Target.GetObject()))
		{
			iat_Junction.IncrementSupportCounter(m_WallToSupport);
			// delete the log in hand
			action_data.m_MainItem.AddQuantity(-1);
		}
	}
};