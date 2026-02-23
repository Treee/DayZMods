/*
*
* This class encapsulates a single rolls results. It includes a min and max roll range (inclusive)
* and a list of results. These results can be items in game or other roll tables. For convenience,
* a spawnPosition AND memory point helper property is being added to allow for dynamic placement
* of results. default will always be player position
*
*/
class IAT_RollTableResult
{
	protected int m_MinRollRange;
	protected int m_MaxRollRange;
	protected ref TStringArray m_Results; // this can be items or even other roll tables

	void IAT_RollTableResult(int minRoll, int maxRoll, TStringArray results)
	{
		m_MinRollRange = minRoll;
		m_MaxRollRange = maxRoll;
		m_Results = results;
	}

	TStringArray GetProbabilityResults()
	{
		return m_Results;
	}
	bool IsRollWithinRange(int chance)
	{
		PrintFormat("IsRollWithinRange-- chance: %1 min: %2 max: %3", chance, m_MinRollRange, m_MaxRollRange);
		if (chance >= m_MinRollRange && chance <= m_MaxRollRange)
		{
			return true;
		}
		return false;
	}
	string ToPrettyString()
	{
		string s = string.Format("------[Roll] -- Min: %1 -- Max: %2", m_MinRollRange, m_MaxRollRange);
		foreach(string result : m_Results)
		{
			s = string.Format("%1\n------%2", s, result);
		}
		return s;
	}
	void PrettyPrint()
	{
		PrintFormat("------[Roll] -- Min: %1 -- Max: %2", m_MinRollRange, m_MaxRollRange);
		foreach(string result : m_Results)
		{
			PrintFormat("------%1", result);
		}
	}
};