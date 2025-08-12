class IAT_MiningSegmentConfig
{
	protected bool m_IsEntrance; // tracks if this is the entrance to a mine
	protected bool m_IsExit; // tracks if this is the exit from a mine

	protected string m_ID; // persistent id between restarts

	protected vector m_SegmentPosition;
	protected vector m_SegmentTeleportDestination;

	protected ref TFloatArray m_MineableComponentOreChances; // the probabilities of getting ore on hit in this segment for all the walls

	protected int m_MaxYieldQuantity = 3; // max yield for ore when a complete mining animation is finished

	void IAT_MiningSegmentConfig(string id, bool isEntrance, bool isExit, vector segPos, vector segTelePos)
	{
		m_ID = id;
		m_IsEntrance = isEntrance;
		m_IsExit = isExit;
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
};