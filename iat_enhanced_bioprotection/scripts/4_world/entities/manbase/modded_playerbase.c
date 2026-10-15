modded class PlayerBase
{
	protected int m_ChemicalProtectionTotal = 0;
	protected int m_BiologicalProtectionTotal = 0;

	override protected void OnContaminatedAreaEnterServer()
	{
		// short circuit if there is enough bioprotection
		if (HasEnoughChemicalProtection())
			return;

		// if we dont have enough protection, do whatever normally happens
		super.OnContaminatedAreaEnterServer();
	}

	void ModifyChemicalProtection(int amount)
	{
		// += allows for negative numbers to exist
		m_ChemicalProtectionTotal += amount;
	}
	// default 5 pieces of gear. head, top, gloves, pants, shoes
	bool HasEnoughChemicalProtection(int requiredLevel = 5)
	{
		return m_ChemicalProtectionTotal >= requiredLevel;
	}

	void ModifyBiologicalProtection(int amount)
	{
		// += allows for negative numbers to exist
		m_BiologicalProtectionTotal += amount;
	}
	// default mask with filter (but a special clothing item could suffice)
	bool HasEnoughBiologicalProtection(int requiredLevel = 1)
	{
		return m_BiologicalProtectionTotal >= requiredLevel;
	}
};