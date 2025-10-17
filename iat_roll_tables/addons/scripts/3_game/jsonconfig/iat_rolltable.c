/*
*
* This class encapsulates an entire roll table. that includes a max roll (inclusive)
* and a list of results. These results can potentially be other roll tables allowing
* for complex chaining of probability.
*
*/
class IAT_RollTable
{
	protected string m_TableName;
	protected int m_MaxRoll; // this number is inclusive. ex a value of 100 would success if the dice rolled 100 as well
	protected ref array<ref IAT_RollTableProbability> m_ListOfProbabilities;

	void IAT_RollTable(string tableName, int maxRoll)
	{
		m_TableName = tableName;
		m_MaxRoll = maxRoll;
	}
	// ================================================================================== HELPERS
	// i split this out in case someone wants to add "crit" rolls or w/e
	int GetRandomRoll()
	{
		int chance = Math.RandomIntInclusive(1, m_MaxRoll);
		return chance;
	}
	TStringArray GetResults()
	{
		int chance = GetRandomRoll();

		foreach(IAT_RollTableProbability prob : m_ListOfProbabilities)
		{
			if (prob.IsRollWithinRange(chance))
			{
				return prob.GetProbabilityResults();
			}
		}
		return {};
	}

	void RegisterProbability(IAT_RollTableProbability probability)
	{
		if (!m_ListOfProbabilities)
		{
			m_ListOfProbabilities = new array<ref IAT_RollTableProbability>();
		}
		m_ListOfProbabilities.Insert(probability);
	}

	bool NameMatches(string other)
	{
		return m_TableName == other;
	}
	string GetTableName()
	{
		return m_TableName;
	}

	void PrettyPrint()
	{
		PrintFormat("----[IAT_RollTable]: %1 -- MaxRoll: %2", m_TableName, m_MaxRoll);
		foreach(IAT_RollTableProbability rollProb : m_ListOfProbabilities)
		{
			rollProb.PrettyPrint();
		}
	}
};