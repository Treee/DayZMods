class IAT_InvasibilityGene extends IAT_GeneBase
{
	void IAT_InvasibilityGene()
	{
		m_GeneType = IAT_GeneTypes.INVASIBILITY;
		m_GeneMin = -100; // -100% growth
		m_GeneMax = 100; // 100% growth
		m_CurrentValue = 0; // no change to vanilla growth (at 0)
		m_NumBytes = 1; // 1 byte since max value is 100
		m_GeneBinary = "00000000";

		InitializeGene();
	}

};