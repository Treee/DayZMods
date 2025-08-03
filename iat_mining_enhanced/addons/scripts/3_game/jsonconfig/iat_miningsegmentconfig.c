class IAT_MiningSegmentConfig
{
	protected bool m_IsEntrance; // tracks if this is the entrance to a mine
	protected bool m_IsExit; // tracks if this is the exit from a mine

	protected string m_ID; // persistent id between restarts

	protected vector m_SegmentPosition;
	protected vector m_SegmentTeleportDestination;

	protected ref TStringArray m_MineableComponentNames; // names of the selections for each "wall" that can be mined
	protected ref TIntArray m_MineableComponentHitCounters; // the number of times that specific wall has been hit
	protected ref TFloatArray m_MineableComponentOreChances; // the probabilities of getting ore on hit in this segment for all the walls

	protected int m_MaxYieldQuantity = 3; // max yield for ore when a complete mining animation is finished
	protected int m_MaxHitLimit = 5; // max times a wall can be hit

	void IAT_MiningSegmentConfig(string id, bool isEntrance, bool isExit, int maxHits, vector segPos, vector segTelePos)
	{
		m_ID = id;
		m_IsEntrance = isEntrance;
		m_IsExit = isExit;
		m_MaxHitLimit = maxHits;
		m_SegmentPosition = segPos;
		m_SegmentTeleportDestination = segTelePos;
	}
	//========================================================= HELPERS

	bool IsIDMatch(string id)
	{
		if (m_ID == id)
			return true;
		return false;
	}
	bool IsSegmentExit(string id)
	{

	}
	bool CanMineSegmentComponent(string componentName)
	{
		// enforce lowercase
		componentName.ToLower();

		// loop over all segments to see if we are looking at a mineable one
		foreach (int index, string component : m_MineableComponentNames)
		{
			// if the target component is a match
			if (component == componentName)
			{
				// if this wall can be hit more
				if (m_MineableComponentHitCounters[index] < m_MaxHitLimit)
				{
					return true;
				}
				// the wall should be animated down at this point so we should never actually get here
			}
		}
		// if none of the components can be mined. return false
		return false;
	}
	void IncrementSegmentComponentHitCounter(string componentName)
	{
		// enforce lowercase
		componentName.ToLower();
		// find the component in the list
		int index = m_MineableComponentNames.Find(componentName);
		// if we did find one
		if (index > -1)
		{
			// increment the hit counter
			m_MineableComponentHitCounters[index] = m_MineableComponentHitCounters[index] + 1;
			PrintFormat("component hit: %1 numTimes: %2", componentName, m_MineableComponentHitCounters[index]);
		}
	}

	//========================================================= GETTERS & SETTERS
	string GetID()
	{
		return m_ID;
	}
	void SetID(string id)
	{
		m_ID = id;
	}
	bool IsEntrance()
	{
		return m_IsEntrance;
	}
	void SetIsEntrance(bool isEntrance)
	{
		m_IsEntrance = isEntrance;
	}
	bool IsExit()
	{
		return m_IsExit;
	}
	void SetIsExit(bool isExit)
	{
		m_IsExit = isExit;
	}
	vector GetSegmentPosition()
	{
		return m_SegmentPosition;
	}
	void SetSegmentPosition(vector pos)
	{
		m_SegmentPosition = pos;
	}
	vector GetSegmentTeleportDestination()
	{
		return m_SegmentTeleportDestination;
	}
	void SetSegmentTeleportDestination(vector dest)
	{
		m_SegmentTeleportDestination = dest;
	}
	TStringArray GetMineableComponentNames()
	{
		return m_MineableComponentNames;
	}
	void SetMineableComponentNames(TStringArray componentNames)
	{
		m_MineableComponentNames = componentNames;
	}
	TIntArray GetMineableComponentHitCounters()
	{
		return m_MineableComponentHitCounters;
	}
	void SetMineableComponentHitCounters(TIntArray componentNames)
	{
		m_MineableComponentHitCounters = componentNames;
	}
	TFloatArray GetMineableComponentOreChances()
	{
		return m_MineableComponentOreChances;
	}
	void SetMineableComponentOreChances(TFloatArray componentChances)
	{
		m_MineableComponentOreChances = componentChances;
	}
	int GetSegmentMaxOreYield()
	{
		return m_MaxYieldQuantity;
	}
	void SetSegmentMaxOreYield(int newValue)
	{
		m_MaxYieldQuantity = newValue;
	}
	int GetWallMaxHitLimit()
	{
		return m_MaxHitLimit;
	}
	void SetWallMaxHitLimit(int newValue)
	{
		m_MaxHitLimit = newValue;
	}
};