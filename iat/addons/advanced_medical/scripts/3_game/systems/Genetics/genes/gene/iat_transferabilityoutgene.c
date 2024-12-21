class IAT_TransferabilityOutGene extends IAT_GeneBase
{
	void IAT_TransferabilityOutGene()
	{
		m_GeneType = IAT_GeneTypes.TRANSFERIBILITY_OUT;
		m_GeneMin = 0; // 0% chance
		m_GeneMax = 100; // 100% chance
		m_CurrentValue = 0; // no change to vanilla chance (at 0)
		m_NumBytes = 1; // 1 byte since max value is 100
		m_GeneBinary = "00000000";

		InitializeGene();
	}

};