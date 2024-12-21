class IAT_AntibioticEfficacyGene extends IAT_GeneBase
{
	void IAT_AntibioticEfficacyGene()
	{
		m_GeneType = IAT_GeneTypes.ANTIBIOTIC_EFFICACY;
		m_GeneMin = 10; // 10% efficacy
		m_GeneMax = 200; // 200% efficacy
		m_CurrentValue = 0; // no change to vanilla growth (at 0)
		m_NumBytes = 1; // 1 byte since max value is 100
		m_GeneBinary = "00000000";

		InitializeGene();
	}

};