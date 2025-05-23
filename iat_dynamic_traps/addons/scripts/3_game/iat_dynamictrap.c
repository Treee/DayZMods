class IAT_DynamicTrap
{
	protected int m_TrapCooldown; // this determines if the trap will be triggered again before restart.
	protected string m_TrapTarget; // this is the name of the building/thing to be trapped
	protected ref array<ref IAT_DynamicTrapResult> m_TrapResults; // this is the roll tables for a trap

	void IAT_DynamicTrap(string trapTarget, int trapCooldown = -1)
	{
		m_TrapTarget = trapTarget;
		m_TrapCooldown = trapCooldown;
	}

	// ==================================================================================
	// Helpers
	// ==================================================================================
	void AddDynamicTrapResult(IAT_DynamicTrapResult result)
	{
		if (!m_TrapResults)
		{
			m_TrapResults = new array<ref IAT_DynamicTrapResult>;
		}
		m_TrapResults.Insert(result);
	}

	bool IsObjectTrapped(string objectName)
	{
		return m_TrapTarget == objectName;
	}
	bool IsObjectTrapped(typename objectType)
	{
		return objectType == m_TrapTarget.ToType();
	}

	IAT_DynamicTrapResult GetResultByChance(int chance)
	{
		foreach(IAT_DynamicTrapResult trapResult : m_TrapResults)
		{
			if (trapResult.IsChanceWithinRange(chance))
			{
				return trapResult;
			}
		}
		return null;
	}
	bool HasTrapCooldown()
	{
		return m_TrapCooldown > 0;
	}
	// ==================================================================================
	// Getters & Setters
	// ==================================================================================
	int GetTrapCooldown()
	{
		return m_TrapCooldown;
	}
	void SetTrapCooldown(int newState)
	{
		m_TrapCooldown = newState;
	}

	string GetTrapTarget()
	{
		return m_TrapTarget;
	}
	void SetTrapTarget(string newState)
	{
		m_TrapTarget = newState;
	}

	array<ref IAT_DynamicTrapResult> GetTrapResults()
	{
		return m_TrapResults;
	}
};