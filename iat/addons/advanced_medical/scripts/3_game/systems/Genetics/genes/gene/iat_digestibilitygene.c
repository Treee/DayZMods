class IAT_DigestibilityGene extends IAT_GeneBase
{
	void IAT_DigestibilityGene()
	{
		m_GeneType = IAT_GeneTypes.DIGESTIBILITY;
		m_GeneMin = 0; // 0% growth
		m_GeneMax = 100; // 100% growth
		m_CurrentValue = 0; // no change to vanilla growth (at 0)
		m_NumBytes = 1; // 1 byte since max value is 100
		m_GeneBinary = "00000000";

		InitializeGene();
	}

};