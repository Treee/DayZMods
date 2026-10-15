class IAT_GrowthPotencyGene extends IAT_GeneBase
{
	void IAT_GrowthPotencyGene()
	{
		m_GeneType = IAT_GeneTypes.GROWTH_POTENCY;
		m_GeneMin = 0; // no potency modification
		m_GeneMax = 5; // maximum potency modification (EStatLevels.GREAT + 4 = CRITICAL)
		m_CurrentValue = 0; // no change to vanilla growth (at 0)
		m_NumBytes = 1; // 1 byte since max value is 100
		m_GeneBinary = "00000000";

		InitializeGene();
	}

};