class IAT_DynamicTrapResult
{
	protected int m_RollRangeMin; // min range for roll
	protected int m_RollRangeMax; // max range for roll
	protected int m_NumResults; // number of items to spawn per roll

	protected bool m_DynamicPersistency;
	protected bool m_InitAI;
	protected bool m_PlaceOnSurface;
	protected bool m_KeepHeight;

	protected ref TStringArray m_RollResults; // list of results a successful roll could yield
	protected ref TStringArray m_MemoryPointLocations; // list of potential memory point spawn locations for the results

	void IAT_DynamicTrapResult(int rollMin, int rollMax, int numResults = 1, bool persistency = true, bool initAI = false, bool placeOnSurface = false, bool keepHeight = false)
	{
		m_RollRangeMin = rollMin;
		m_RollRangeMax = rollMax;
		m_NumResults = numResults;

		m_DynamicPersistency = persistency;
		m_InitAI = initAI;
		m_PlaceOnSurface = placeOnSurface;
		m_KeepHeight = keepHeight;
	}
	// ==================================================================================
	// Helpers
	// ==================================================================================
	void AddResult(string result)
	{
		if (!m_RollResults)
		{
			m_RollResults = new TStringArray;
		}
		m_RollResults.Insert(result);
	}
	void AddMemoryPointSpawnLocation(string memoryPoint)
	{
		if (!m_MemoryPointLocations)
		{
			m_MemoryPointLocations = new TStringArray;
		}
		m_MemoryPointLocations.Insert(memoryPoint);
	}
	bool IsChanceWithinRange(int chance)
	{
		if (chance >= m_RollRangeMin && chance <= m_RollRangeMax)
		{
			return true;
		}
		return false;
	}
	bool HasCustomSpawnLocations()
	{
		if (!m_MemoryPointLocations)
			return false;
		if (m_MemoryPointLocations.Count() == 0)
			return false;
		return true;
	}
	string GetRandomMemoryPoint()
	{
		return m_MemoryPointLocations.GetRandomElement();
	}
	string GetRandomResult()
	{
		return m_RollResults.GetRandomElement();
	}
	int GetResultSpawnFlag()
	{
		int flags = 0;
		if (m_DynamicPersistency)
			flags |= ECE_DYNAMIC_PERSISTENCY|ECE_NOLIFETIME|ECE_SETUP;
		if (m_InitAI)
			flags |= ECE_INITAI;
		if (m_PlaceOnSurface)
			flags |= ECE_PLACE_ON_SURFACE;
		if (m_KeepHeight)
			flags |= ECE_KEEPHEIGHT;

		return flags;
	}
	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	int GetRollRangeMin()
	{
		return m_RollRangeMin;
	}
	void SetRollRangeMin(int newState)
	{
		m_RollRangeMin = newState;
	}

	int GetRollRangeMax()
	{
		return m_RollRangeMax;
	}
	void SetRollRangeMax(int newState)
	{
		m_RollRangeMax = newState;
	}

	int GetNumResults()
	{
		return m_NumResults;
	}
	void SetNumResults(int newState)
	{
		m_NumResults = newState;
	}

	TStringArray GetRollResults()
	{
		return m_RollResults;
	}
};