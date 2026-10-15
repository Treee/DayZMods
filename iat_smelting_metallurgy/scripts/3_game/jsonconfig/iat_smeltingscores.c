class IAT_SmeltingScore
{
	protected string m_PlayerName;
	protected string m_PlayerID;
	protected int m_Wins;
	protected int m_Loss;
	protected int m_CurrentStreak;
	protected int m_LongestStreak;

	void IAT_SmeltingScore(string playerName, string playerId, int win = 0, int loss = 0, int streak = 0)
	{
		m_PlayerName = playerName;
		m_PlayerID = playerId;
		m_Wins = win;
		m_Loss = loss;
		m_CurrentStreak = streak;
		m_LongestStreak = streak;
	}

	void IncrementWins(int win, int streak)
	{
		m_Wins = win;
		m_CurrentStreak = streak;
		// replace longest streak with an EVEN LONGER ONE!!
		if (streak > m_LongestStreak)
		{
			m_LongestStreak = streak;
		}
	}
	void IncrementLoss(int loss)
	{
		m_Loss = loss;
		m_CurrentStreak = 0;
	}
	void TryUpdateName(string name)
	{
		if (m_PlayerName != name)
		{
			m_PlayerName = name;
		}
	}

	bool IsPlayerScore(string id)
	{
		return m_PlayerID == id;
	}

	// Getters
	int GetWins()
	{
		return m_Wins;
	}
	int GetLoss()
	{
		return m_Loss;
	}
	int GetCurrentStreak()
	{
		return m_CurrentStreak;
	}
	string PrettyPrint()
	{
		return string.Format("PlayerId: %1 PlayerName: %2 || Wins: %3 Loss: %4 || Streak: %5 Longest: %6", m_PlayerID, m_PlayerName, m_Wins, m_Loss, m_CurrentStreak, m_LongestStreak);
	}
};